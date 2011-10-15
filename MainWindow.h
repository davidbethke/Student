/* 
 * File:   MainWindow.h
 * Author: davidbethke
 *
 * Created on October 15, 2011, 5:23 PM
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H
#include <QWidget>
#include "AddStudentWidget.h"
#include "CourseListWidget.h"
class MainWindow:public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);
    MainWindow(const MainWindow& orig);
    virtual ~MainWindow();
   
private:
    QStandardItemModel *modelCourses;
    QTreeView *treeCourses;
    QStandardItemModel *modelStudent;
    QTableView *tableStudent;
    AddStudentWidget *addStudent;
    CourseListWidget *courseList;
    void init();
};

#endif	/* MAINWINDOW_H */

