/* 
 * File:   CourseListWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 14, 2011, 10:30 PM
 */

#include "CourseListWidget.h"

CourseListWidget::CourseListWidget(QWidget *parent):QWidget(parent) {
    
    init();
    QStringListModel *modelHours = new QStringListModel;
    modelHours->setStringList(listHours);
    comboHours->setModel(modelHours);
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
    
}

CourseListWidget::CourseListWidget(const CourseListWidget& orig) {
}

CourseListWidget::~CourseListWidget() {
}


void CourseListWidget::init(){
    labelCourse=new QLabel("Course Title:");
    labelHours = new QLabel("Credit Hours:");
    editCourse= new QLineEdit("Enter Course Title");
    comboHours= new QComboBox;
    buttonEnter= new QPushButton("Enter New Course");
    courseList=new QStandardItemModel();
    QStringList header;
    header.append(QString("Title"));
    header.append(QString("Credit Hours"));
    courseList->setHorizontalHeaderLabels(header);
    tableCourse = new QTableView;
    tableCourse->setModel(courseList);
    QHBoxLayout *layout= new QHBoxLayout;
    QVBoxLayout *vLayout= new QVBoxLayout;
    layout->addWidget(labelCourse);
    layout->addWidget(editCourse);
    layout->addWidget(labelHours);
    layout->addWidget(comboHours);
    layout->addWidget(buttonEnter);
    vLayout->addLayout(layout);
    vLayout->addWidget(tableCourse);
    setLayout(vLayout);
    listHours<<"5"<<"4"<<"3"<<"2"<<"1"<<"0";
}

void CourseListWidget::update(){
    //fill it in
    //QMessageBox::information(this,QString("Result"),QString("Course:"+editCourse->text()+" Hours:"+comboHours->itemText(comboHours->currentIndex())));
    QStandardItem *title= new QStandardItem(editCourse->text());
    QStandardItem *hours = new QStandardItem(comboHours->itemText(comboHours->currentIndex()));
    QList<QStandardItem *> list;
    list << title<< hours;
    //courseList->setItem(0,0,title);
    //courseList->setItem(0,1,hours);
    courseList->appendRow(list);
    
}
QStandardItemModel* CourseListWidget::getModel(){
    return courseList;
}
