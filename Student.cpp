/* 
 * File:   Student.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 4:42 PM
 */

#include "Student.h"
#include "CourseListWidget.h"
#include <QByteArray>

Student::Student() {
}
Student::Student(QString s, int h, double g):name(s),hoursAttempted(h),gpa(g){
    
}

Student::Student(const Student& orig) {
}

Student::~Student() {
}
QString Student::getName(){
    return name;
}
int Student::getHours(){
    return hoursAttempted;
}
double Student::getGpa(){
    return gpa;
}
void Student::addHours(int h){
    hoursAttempted +=h;
}
double Student::gradeToDouble(QString g){
    // todo
   
    if (g == "A")
        return 4.0;
    else if (g== "B")
        return 3.0;
    else if (g== "C")
        return 2.0;
    else if (g=="D")
        return 1.0;
    else
    return 0.0;
}
void Student::calcGpa(int h,double g){
    gpa = ((gpa * hoursAttempted)+(g*h))/(hoursAttempted+h);
    
}
void Student::setGpa(double g){
    gpa=g;
}
void Student::setHours(int h){
    hoursAttempted=h;
}
void Student::setName(QString n){
    name=n;
}
void Student::addCourse(int h, QString n){
    calcGpa(h,gradeToDouble(n));
    addHours(h);
}