/* 
 * File:   StudentWidget.h
 * Author: davidbethke
 *
 * Created on October 14, 2011, 11:51 PM
 */


#ifndef STUDENTWIDGET_H
#define	STUDENTWIDGET_H
#include <QWidget>
#include <QtGui>
#include "Student.h"
#include "MainWindow.h"
#include "AddStudentWidget.h"
class StudentWidget:public QWidget{
    Q_OBJECT
public:
    StudentWidget(QStandardItemModel*m, QWidget *parent=0);
    StudentWidget(Student*,QStandardItemModel*,QWidget *parent=0);
    StudentWidget(Student *,QStandardItemModel*,QStandardItemModel*,QWidget *parent=0);
    StudentWidget(Student *,QStandardItemModel*,QStandardItemModel*,QStandardItemModel*,QWidget *parent=0);


    //StudentWidget(QWidget *parent=0);
    StudentWidget(const StudentWidget& orig);
    virtual ~StudentWidget();
    void setModel(QStandardItemModel*);
private:
    QLabel *labelCourse;
    QLabel *labelGrade;
    QComboBox *comboCourse;
    QComboBox *comboGrade;
    QPushButton *buttonEnter;
    QStringListModel *modelGrade;
    QStandardItemModel *modelCourse;
    QStandardItemModel *modelGpa;
    QStandardItemModel *modelTreeCourse;
    QTableView *courseList;
    QStandardItemModel *modelStudent;
    Student* student;
    AddStudentWidget *p;
    void init();
    
    public slots:
        void update();

};

#endif	/* STUDENTWIDGET_H */

