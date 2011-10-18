/* 
 * File:   MainWindow.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 5:23 PM
 */

#include "MainWindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent):QWidget(parent) {
    init();
}

MainWindow::MainWindow(const MainWindow& orig) {
}

MainWindow::~MainWindow() {
}
void MainWindow::init(){
    
   // modelCourses = new QStandardItemModel;
   // modelStudent = new QStandardItemModel;
    //treeCourses = new QTreeView;
    //tableStudent = new QTableView;
    addStudent = new AddStudentWidget();
    courseList = new CourseListWidget;
    
    QStringList header;
    header.append(QString("Name"));
    header.append(QString("Credit Hours"));
    header.append(QString("GPAA"));
   // modelStudent->setHorizontalHeaderLabels(header);
    //tableStudent->setModel(modelStudent);
    //tableStudent->setMinimumWidth(300);
    //treeCourses->setModel(modelCourses);
    // layout
    //QVBoxLayout *vLayout = new QVBoxLayout;
    QVBoxLayout *vLayout2 = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    //vLayout->addWidget(treeCourses);
    //vLayout->addWidget(tableStudent);
    vLayout2->addWidget(addStudent);
    vLayout2->addWidget(courseList);
    //hLayout->addLayout(vLayout);
    hLayout->addLayout(vLayout2);
    setLayout(hLayout);
    /*
    addStudent->show();
    courseList->show();
    tableStudent->show();
    treeCourses->show();
     */
    
    
}
void MainWindow::createStudentWidget(QString n,QString h,QString g){
    Student *someStudent= new Student;
    someStudent->setName(n);
    someStudent->setHours(h.toInt());
    someStudent->setGpa(g.toDouble());
    //QMessageBox::information(this,QString("Result"),QString("name:"+someStudent->getName()));
   // StudentWidget *studentWidget = new StudentWidget(someStudent,courseList->getModel());
    //studentWidget->show();
}
void MainWindow::updateGpa(Student*s){
    // this method should update the modelStudent w/ the new GPA and total hoursAttempted, it will be displayed
    // in a table view on the MainWindow(not really a mainWindow of the definition of Qt)
   // get index, setItem index.row,col1 (hours, index.row, col2(GPA), hopefully
   // create an QStandardItem from the Student name, hours, gpa to be searched and inserted
    QString hoursInt, gpaDouble;
    QString dave = "Dave";
    QStandardItem *name = new QStandardItem(s->getName());
    QStandardItem *daveName = new QStandardItem(dave);
    QStandardItem *hours = new QStandardItem(hoursInt.setNum(s->getHours()));
    QStandardItem *gpa = new QStandardItem(gpaDouble.setNum(s->getGpa()));
    //QMessageBox::information(this,QString("Result"),QString("Gpa:"+modelStudent->takeItem(0,1)->text()+" Hours:"+modelStudent->takeItem(0,2)->text()));

    //modelStudent->clear();
    //QModelIndex index = modelStudent->indexFromItem(daveName);
    /*
    modelStudent->setItem(0,1,daveName);
    modelStudent->setItem(0,2,daveName);
    */
    // Fucking fuck up mother fucker take all god damn fucking day
    //shit shit shit shit shit fuck
    /*
    QString  qFuck1,qFuck2, qFuck3;
    
    qFuck1="Fuck1";qFuck2="Fuck2";qFuck3="Fuck3";
    QStandardItem *fuck1 = new QStandardItem(qFuck1);
    QStandardItem *fuck2 = new QStandardItem(qFuck2);
    QStandardItem *fuck3 = new QStandardItem(qFuck3);
    QList<QStandardItem *> list;
    list << fuck1<<fuck2<<fuck3;
    addStudent->getModel()->appendRow(list);
    */
    // is that it?
}
/*
QStandardItemModel* MainWindow::getStudentModel(){
    return modelStudent;
}
 */
CourseListWidget* MainWindow::getCourseList(){
    return courseList;
}