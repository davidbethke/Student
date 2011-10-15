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
    Student(QString,int h=0,double g=0.0);
    Student(const Student& orig);
    virtual ~Student();
    QString getName();
    int getHours();
    double getGpa();
    
private:
    
    QString name;
    int hoursAttempted;
    double gpa;
    void addHours(int);
    double gradeToDouble();
    void calcGpa(int,double);
    
};

#endif	/* STUDENT_H */

