/* 
 * File:   Student.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 4:42 PM
 */

#include "Student.h"
#include "CourseListWidget.h"

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
double Student::gradeToDouble(){
    // todo
    return 0.0;
}
void Student::calcGpa(int h,double g){
    gpa = ((gpa * hoursAttempted)+(g*h))/(hoursAttempted+h);
    
}