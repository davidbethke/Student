/* 
 * File:   AddStudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 5:29 PM
 */

#include "AddStudentWidget.h"
#include "MainWindow.h"

AddStudentWidget::AddStudentWidget(QWidget* parent):QWidget(parent){
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));

}

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
    modelStudent = new QStandardItemModel;
    tableStudent = new QTableView;
    labelName= new QLabel("Student Name:");
    labelHours= new QLabel("Credit Hours:");
    labelGpa= new QLabel("Current GPA:");
    editName = new QLineEdit;
    editHours = new QLineEdit;
    editGpa= new QLineEdit;
    buttonEnter= new QPushButton("Add Student");
    // modelStudent setup
    QStringList header;
    header.append(QString("Name"));
    header.append(QString("Credit Hours"));
    header.append(QString("GPAA"));
    modelStudent->setHorizontalHeaderLabels(header);
    tableStudent->setModel(modelStudent);
    tableStudent->setMinimumWidth(300);
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *layout= new QHBoxLayout;
    layout->addWidget(labelName);
    layout->addWidget(editName);
    layout->addWidget(labelHours);
    layout->addWidget(editHours);
    layout->addWidget(labelGpa);
    layout->addWidget(editGpa);
    layout->addWidget(buttonEnter);
    vLayout->addLayout(layout);
    vLayout->addWidget(tableStudent);
    
    setLayout(vLayout);
    //resize(400,60);
    
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
    //Student someStudent;
    //someStudent(editName->text(),editHours->text().toInt(),editGpa->text().toDouble());
    //someStudent.setName(editName->text());
    //someStudent.setHours(editHours->text().toInt());
    //someStudent.setGpa(editGpa->text().toDouble());
    //QMessageBox::information(this,QString("addstudentwidget"),QString("name:"+someStudent.getName()+"Hours:"+QString::number(someStudent.getHours())));
   
    //StudentWidget *studentWidget = new StudentWidget(student,modelStudent);
    //studentWidget->show();
    // following works try having addstudentwidget launch StudentWidget
    //static_cast<MainWindow *>(parentWidget())->createStudentWidget(editName->text(),editHours->text(),editGpa->text());
    // copied directly
    Student *someStudent= new Student;
    someStudent->setName(editName->text());
    someStudent->setHours(editHours->text().toInt());
    someStudent->setGpa(editGpa->text().toDouble());
    //QMessageBox::information(this,QString("Result"),QString("name:"+someStudent->getName()));
    StudentWidget *studentWidget = new StudentWidget(someStudent,modelStudent,static_cast<MainWindow *>(parentWidget())->getCourseList()->getModel());
    studentWidget->show();
}
Student AddStudentWidget::getStudent(QString n, QString h, QString g){
    return Student(n,h.toInt(),g.toDouble());
}
QStandardItemModel* AddStudentWidget::getModel(){
    return modelStudent;
}
void AddStudentWidget::updateGpa(Student *s){
    // take from main
    QString hoursInt, gpaDouble;
    //QString dave = "Dave";
    QStandardItem *name = new QStandardItem(s->getName());
    //QStandardItem *daveName = new QStandardItem(dave);
    QStandardItem *hours = new QStandardItem(hoursInt.setNum(s->getHours()));
    QStandardItem *gpa = new QStandardItem(gpaDouble.setNum(s->getGpa()));
    QModelIndex index = getModel()->indexFromItem(name);
   // modelStudent->setItem(index.row(),1,hours);
   // modelStudent->setItem(index.row(),2,gpa);
}
