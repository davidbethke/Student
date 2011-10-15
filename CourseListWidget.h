/* 
 * File:   CourseListWidget.h
 * Author: davidbethke
 *
 * Created on October 14, 2011, 10:30 PM
 */

#ifndef COURSELISTWIDGET_H
#define	COURSELISTWIDGET_H
#include <QWidget>
#include <QtGui>


class CourseListWidget: public QWidget {
    Q_OBJECT
public:
    explicit CourseListWidget(QWidget *parent=0);
    CourseListWidget(const CourseListWidget& orig);
    virtual ~CourseListWidget();
    QStandardItemModel* getModel();
    
private:
    // build the window
    QLabel *labelHours;
    QLabel *labelCourse;
    QComboBox *comboHours;
    QLineEdit *editCourse;
    QStringList listHours;
    QPushButton *buttonEnter;
    QStandardItemModel *courseList;
    QTableView* tableCourse;
    void init();
    
    public slots:
        void update();
};

#endif	/* COURSELISTWIDGET_H */

