/* 
 * File:   StudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 14, 2011, 11:51 PM
 */

#include "StudentWidget.h"

StudentWidget::StudentWidget(QStandardItemModel *m,QWidget *parent):modelCourse(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
   
}

StudentWidget::StudentWidget(const StudentWidget& orig) {
}

StudentWidget::~StudentWidget() {
}
void StudentWidget::init(){
    labelCourse = new QLabel("Course:");
    labelGrade = new QLabel("Grade:");
    comboCourse= new QComboBox;
    comboGrade = new QComboBox;
    buttonEnter = new QPushButton("Enter Course");
    QLabel *labelCourses = new QLabel("ALL Student Courses");
    //otherButton = new QPushButton("Other");
    modelGrade = new QStringListModel;
    modelStudent= new QStandardItemModel;
    //modelCourse = new QStandardItemModel;
    QStringList header;
    header.append(QString("Title"));
    header.append(QString("Credit Hours"));
    header.append(QString("Grade"));
    modelStudent->setHorizontalHeaderLabels(header);
    courseList = new QTableView;
    QStringList gradeList;
    gradeList<<"A"<<"B"<<"C"<<"D"<<"E";
    modelGrade->setStringList(gradeList);
    comboGrade->setModel(modelGrade);
    comboCourse->setModel(modelCourse);
    //comboCourse->setModelColumn(1);
    courseList->setModel(modelStudent);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(labelCourse);
    layout->addWidget(comboCourse);
    layout->addWidget(labelGrade);
    layout->addWidget(comboGrade);
    layout->addWidget(buttonEnter);
    //layout->addWidget(otherButton);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(layout);
    vLayout->addWidget(labelCourses);
    vLayout->addWidget(courseList);
    setLayout(vLayout);
      
} 

void StudentWidget::update(){
    // do something
   //QMessageBox::information(this,QString("Result"),QString("Course:"+comboCourse->itemText(comboCourse->currentIndex())+" Grade:"+comboGrade->itemText(comboGrade->currentIndex())));

    QStandardItem *title= new QStandardItem(comboCourse->itemText(comboCourse->currentIndex()));
    //QModelIndex index = modelCourse->index(0,1);
   // QStandardItem *hours= modelCourse->itemFromIndex(index);
        QStandardItem *hours= modelCourse->item(comboCourse->currentIndex(),1)->clone();

    
        //QStandardItem *hours= modelCourse->takeItem(0,1);

    QStandardItem *grade = new QStandardItem(comboGrade->itemText(comboGrade->currentIndex()));
    QList<QStandardItem *> list;
    list << title<<hours<< grade;
    modelStudent->appendRow(list);
          //  modelStudent->setItem(0,1,new QStandardItem(comboCourse->itemText(comboCourse->currentIndex())));

}
void StudentWidget::setModel(QStandardItemModel *m){
    modelCourse=m;
}
