/* 
 * File:   StudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 14, 2011, 11:51 PM
 */

#include "StudentWidget.h"

StudentWidget::StudentWidget(QStandardItemModel *m,QWidget *parent):modelCourse(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
   
}
StudentWidget::StudentWidget(Student *s,QStandardItemModel *m,QWidget *parent):student(s),modelCourse(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
   
}
StudentWidget::StudentWidget(Student *s,QStandardItemModel *mG,QStandardItemModel *m,QWidget *parent):student(s),modelGpa(mG),modelCourse(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
   
}

StudentWidget::StudentWidget(const StudentWidget& orig) {
}

StudentWidget::~StudentWidget() {
}
void StudentWidget::init(){
    labelCourse = new QLabel("Course:");
    labelGrade = new QLabel("Grade:");
    comboCourse= new QComboBox;
    comboGrade = new QComboBox;
    buttonEnter = new QPushButton("Enter Course");
    QLabel *labelCourses = new QLabel("ALL Student Courses");
    //otherButton = new QPushButton("Other");
    modelGrade = new QStringListModel;
    modelStudent= new QStandardItemModel;
    //modelCourse = new QStandardItemModel;
    QStringList header;
    header.append(QString("Title"));
    header.append(QString("Credit Hours"));
    header.append(QString("Grade"));
    modelStudent->setHorizontalHeaderLabels(header);
    courseList = new QTableView;
    QStringList gradeList;
    gradeList<<"A"<<"B"<<"C"<<"D"<<"E";
    modelGrade->setStringList(gradeList);
    comboGrade->setModel(modelGrade);
    comboCourse->setModel(modelCourse);
    //comboCourse->setModelColumn(1);
    courseList->setModel(modelStudent);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(labelCourse);
    layout->addWidget(comboCourse);
    layout->addWidget(labelGrade);
    layout->addWidget(comboGrade);
    layout->addWidget(buttonEnter);
    //layout->addWidget(otherButton);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(layout);
    vLayout->addWidget(labelCourses);
    vLayout->addWidget(courseList);
    setLayout(vLayout);
    setWindowTitle("Student Course List: "+student->getName());
    //setWindowTitle("some student");
} 

void StudentWidget::update(){
    // do something
   //QMessageBox::information(this,QString("Result"),QString("Course:"+comboCourse->itemText(comboCourse->currentIndex())+" Grade:"+comboGrade->itemText(comboGrade->currentIndex())));

    QStandardItem *title= new QStandardItem(comboCourse->itemText(comboCourse->currentIndex()));
    //QModelIndex index = modelCourse->index(0,1);
   // QStandardItem *hours= modelCourse->itemFromIndex(index);
        QStandardItem *hours= modelCourse->item(comboCourse->currentIndex(),1)->clone();

    
        //QStandardItem *hours= modelCourse->takeItem(0,1);

    QStandardItem *grade = new QStandardItem(comboGrade->itemText(comboGrade->currentIndex()));
    QList<QStandardItem *> list;
    list << title<<hours<< grade;
    modelStudent->appendRow(list);
    //student = new Student()
    //  modelStudent->setItem(0,1,new QStandardItem(comboCourse->itemText(comboCourse->currentIndex())));
    // calc new gpa and add hours to hours completed, then update model from parent
    //double gradeConv=student->gradeToDouble(comboGrade->itemText(comboGrade->currentIndex()));
    student->addCourse(hours->text().toInt(),comboGrade->itemText(comboGrade->currentIndex()));
    //student->addHours(hours->text().toInt());
    //update model with getGpa and getHours
    // fucking fuck up mother fucker
    QString  qFuck1,qFuck2, qFuck3;
    
    qFuck1="Fuck1";qFuck2="Fuck2";qFuck3="Fuck3";
    QStandardItem *fuck1 = new QStandardItem(qFuck1);
    QStandardItem *fuck2 = new QStandardItem(qFuck2);
    QStandardItem *fuck3 = new QStandardItem(qFuck3);
    QList<QStandardItem *> list2;
    list2 << fuck1<<fuck2<<fuck3;
    static_cast<MainWindow *>(parentWidget())->getStudentModel()->appendRow(list2);
    //addStudent->getModel()->appendRow(list);
    static_cast<MainWindow *>(parentWidget())->updateGpa(student);

}
void StudentWidget::setModel(QStandardItemModel *m){
    modelCourse=m;
}
