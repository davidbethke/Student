/*
 * File:   main.cpp
 * Author: davidbethke
 *
 * Created on October 14, 2011, 10:24 PM
 */

#include <QtGui/QApplication>
#include "CourseListWidget.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    CourseListWidget courseList;
    courseList.setWindowTitle("Course List");
    courseList.show();

    // create and show your widgets here

    return app.exec();
}

