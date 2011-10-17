/* 
 * File:   Student.h
 * Author: davidbethke
 *
 * Created on October 15, 2011, 4:42 PM
 */

#ifndef STUDENT_H
#define	STUDENT_H
#include <QString>

class Student {
public:
    Student();
    Student(QString,int,double);
    Student(const Student& orig);
    virtual ~Student();
    QString getName();
    int getHours();
    double getGpa();
    void setName(QString);
    void setHours(int);
    void setGpa(double);
    void addCourse(int, QString);
    
private:
    
    QString name;
    int hoursAttempted;
    double gpa;
    void addHours(int);
    double gradeToDouble(QString);
    void calcGpa(int,double);
    
    
};

#endif	/* STUDENT_H */

