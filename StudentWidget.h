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
class StudentWidget:public QWidget{
    Q_OBJECT
public:
    StudentWidget(QStandardItemModel*m, QWidget *parent=0);
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
    QTableView *courseList;
    QStandardItemModel *modelStudent;
    void init();
    
    public slots:
        void update();

};

#endif	/* STUDENTWIDGET_H */

