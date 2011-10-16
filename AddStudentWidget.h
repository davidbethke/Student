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
    //AddStudentWidget(QStandardItemModel*,QWidget *parent=0);
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
    QWidget *p;
    void init();
    Student getStudent(QString,QString,QString);
public slots:
    void update();

};

#endif	/* ADDSTUDENTWIDGET_H */

