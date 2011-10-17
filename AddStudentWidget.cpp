/* 
 * File:   AddStudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 5:29 PM
 */

#include "AddStudentWidget.h"
#include "MainWindow.h"

AddStudentWidget::AddStudentWidget(QStandardItemModel *m,QWidget *parent):modelStudent(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
    //p=parent;
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
    layout->addWidget(editHours);
    layout->addWidget(labelGpa);
    layout->addWidget(editGpa);
    layout->addWidget(buttonEnter);
    
    setLayout(layout);
    resize(400,60);
    
}
void AddStudentWidget::update(){
    // do nothing yet
    QStandardItem *name = new QStandardItem(editName->text());
    QStandardItem *hours = new QStandardItem(editHours->text());
    QStandardItem *gpa = new QStandardItem(editGpa->text());
    QList<QStandardItem *> list;
    list << name<<hours<<gpa;
    modelStudent->appendRow(list);
    //call student
    Student someStudent;
    //someStudent(editName->text(),editHours->text().toInt(),editGpa->text().toDouble());
    someStudent.setName(editName->text());
    someStudent.setHours(editHours->text().toInt());
    someStudent.setGpa(editGpa->text().toDouble());
    //QMessageBox::information(this,QString("addstudentwidget"),QString("name:"+someStudent.getName()+"Hours:"+QString::number(someStudent.getHours())));
   
    //StudentWidget *studentWidget = new StudentWidget(student,modelStudent);
    //studentWidget->show();
    static_cast<MainWindow *>(parentWidget())->createStudentWidget(editName->text(),editHours->text(),editGpa->text());
    
}
Student AddStudentWidget::getStudent(QString n, QString h, QString g){
    return Student(n,h.toInt(),g.toDouble());
}
QStandardItemModel* AddStudentWidget::getModel(){
    return modelStudent;
}
