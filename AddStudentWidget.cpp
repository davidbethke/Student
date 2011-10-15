/* 
 * File:   AddStudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 5:29 PM
 */

#include "AddStudentWidget.h"

AddStudentWidget::AddStudentWidget(QStandardItemModel *m,QWidget *parent):modelStudent(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
}

AddStudentWidget::AddStudentWidget(const AddStudentWidget& orig) {
}

AddStudentWidget::~AddStudentWidget() {
}
void AddStudentWidget::init(){
    labelName= new QLabel("Student Name:");
    labelHours= new QLabel("Credit Hours:");
    labelGpa= new QLabel("Current GPA:");
    editName = new QLineEdit;
    editHours = new QLineEdit;
    editGpa= new QLineEdit;
    buttonEnter= new QPushButton("Add Student");
    QHBoxLayout *layout= new QHBoxLayout;
    layout->addWidget(labelName);
    layout->addWidget(editName);
    layout->addWidget(labelHours);
    layout->addWidget(labelGpa);
    layout->addWidget(editGpa);
    layout->addWidget(buttonEnter);
    
}
void AddStudentWidget::update(){
    // do nothing yet
    QStandardItem *name = new QStandardItem(editName->text());
    QStandardItem *hours = new QStandardItem(editHours->text());
    QStandardItem *gpa = new QStandardItem(editGpa->text());
    QList<QStandardItem *> list;
    list << name<<hours<<gpa;
    modelStudent->appendRow(list);
}
