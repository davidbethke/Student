/*
 * File:   main.cpp
 * Author: davidbethke
 *
 * Created on October 14, 2011, 10:24 PM
 */

#include <QtGui/QApplication>
#include "CourseListWidget.h"
#include "StudentWidget.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("Student/Courses App");
    w.resize(800,600);
    w.show();
    
    //CourseListWidget courseList;
    //StudentWidget student(courseList.getModel());
      //  StudentWidget student;
      //  student.setModel(courseList.getModel());

    //courseList.setWindowTitle("Course List");
    //student.setWindowTitle("Student");
    //student.show();
    //courseList.show();
     

    // create and show your widgets here

    return app.exec();
}

