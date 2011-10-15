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
    QHBoxLayout *layout= new QHBoxLayout;
    layout->addWidget(labelCourse);
    layout->addWidget(editCourse);
    layout->addWidget(labelHours);
    layout->addWidget(comboHours);
    layout->addWidget(buttonEnter);
    setLayout(layout);
    listHours<<"5"<<"4"<<"3"<<"2"<<"1"<<"0";
}

void CourseListWidget::update(){
    //fill it in
    QMessageBox::information(this,QString("Result"),QString("Course:"+editCourse->text()+" Hours:"+comboHours->itemText(comboHours->currentIndex())));
    
}
