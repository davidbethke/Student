/* 
 * File:   AddStudentWidget.h
 * Author: davidbethke
 *
 * Created on October 15, 2011, 5:29 PM
 */

#ifndef ADDSTUDENTWIDGET_H
#define	ADDSTUDENTWIDGET_H
#include <QWidget>
#include <QtGui>
#include "Student.h"



class AddStudentWidget:public QWidget {
    Q_OBJECT
public:
    AddStudentWidget(QStandardItemModel*,QWidget *parent=0);
    AddStudentWidget(QWidget *parent=0);
    AddStudentWidget(const AddStudentWidget& orig);
    virtual ~AddStudentWidget();
private:
    QLabel *labelName;
    QLabel *labelHours;
    QLabel *labelGpa;
    QLineEdit *editName;
    QLineEdit *editHours;
    QLineEdit *editGpa;
    QPushButton *buttonEnter;
    QStandardItemModel *modelStudent;
    QStandardItemModel *modelCourse;
    QTableView *tableStudent;
    QTreeView *treeCourse;
    bool COURSE_SET;
    void init();
    Student getStudent(QString,QString,QString);
public slots:
    void update();
    QStandardItemModel* getModel();
    void updateGpa(QStandardItemModel*,Student*);
    void updateCourse(QStandardItemModel*,QStandardItemModel*,Student*,QStandardItem*);

};

#endif	/* ADDSTUDENTWIDGET_H */

