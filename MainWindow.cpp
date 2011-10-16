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
    
    modelCourses = new QStandardItemModel;
    modelStudent = new QStandardItemModel;
    treeCourses = new QTreeView;
    tableStudent = new QTableView;
    addStudent = new AddStudentWidget(modelStudent,this);
    courseList = new CourseListWidget;
    
    QStringList header;
    header.append(QString("Name"));
    header.append(QString("Credit Hours"));
    header.append(QString("GPAA"));
    modelStudent->setHorizontalHeaderLabels(header);
    tableStudent->setModel(modelStudent);
    tableStudent->setMinimumWidth(300);
    treeCourses->setModel(modelCourses);
    // layout
    QVBoxLayout *vLayout = new QVBoxLayout;
    QVBoxLayout *vLayout2 = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    vLayout->addWidget(treeCourses);
    vLayout->addWidget(tableStudent);
    vLayout2->addWidget(addStudent);
    vLayout2->addWidget(courseList);
    hLayout->addLayout(vLayout);
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
    QMessageBox::information(this,QString("Result"),QString("name:"+someStudent->getName()));
    StudentWidget *studentWidget = new StudentWidget(someStudent,courseList->getModel());
    

    studentWidget->show();
}

