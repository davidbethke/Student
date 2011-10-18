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
    
    addStudent = new AddStudentWidget();
    courseList = new CourseListWidget;
    
    QStringList header;
    header.append(QString("Name"));
    header.append(QString("Credit Hours"));
    header.append(QString("GPAA"));
   
    QVBoxLayout *vLayout2 = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    
    vLayout2->addWidget(addStudent);
    vLayout2->addWidget(courseList);
    
    hLayout->addLayout(vLayout2);
    setLayout(hLayout);
    
    
}
void MainWindow::createStudentWidget(QString n,QString h,QString g){
    Student *someStudent= new Student;
    someStudent->setName(n);
    someStudent->setHours(h.toInt());
    someStudent->setGpa(g.toDouble());
    
}

CourseListWidget* MainWindow::getCourseList(){
    return courseList;
}