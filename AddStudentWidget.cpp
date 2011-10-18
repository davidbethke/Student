/* 
 * File:   AddStudentWidget.cpp
 * Author: davidbethke
 * 
 * Created on October 15, 2011, 5:29 PM
 */

#include "AddStudentWidget.h"
#include "MainWindow.h"

AddStudentWidget::AddStudentWidget(QWidget* parent):QWidget(parent){
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));

}

AddStudentWidget::AddStudentWidget(QStandardItemModel *m,QWidget *parent):modelStudent(m),QWidget(parent) {
    init();
    connect(buttonEnter,SIGNAL(clicked()),this,SLOT(update()));
    //p=parent;
}

AddStudentWidget::AddStudentWidget(const AddStudentWidget& orig) {
}

AddStudentWidget::~AddStudentWidget() {
}
void AddStudentWidget::init(){
    modelStudent = new QStandardItemModel;
    tableStudent = new QTableView;
    labelName= new QLabel("Student Name:");
    labelHours= new QLabel("Credit Hours:");
    labelGpa= new QLabel("Current GPA:");
    editName = new QLineEdit;
    editHours = new QLineEdit;
    editGpa= new QLineEdit;
    buttonEnter= new QPushButton("Add Student");
    // course tree
    treeCourse = new QTreeView;
    modelCourse = new QStandardItemModel;
    treeCourse->setModel(modelCourse);
    //treeCourse->setRootIsDecorated(true);
    // modelStudent setup
    QStringList header;
    header.append(QString("Name"));
    header.append(QString("Credit Hours"));
    header.append(QString("GPAA"));
    modelStudent->setHorizontalHeaderLabels(header);
    tableStudent->setModel(modelStudent);
    tableStudent->setMinimumWidth(300);
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *layout= new QHBoxLayout;
    layout->addWidget(labelName);
    layout->addWidget(editName);
    layout->addWidget(labelHours);
    layout->addWidget(editHours);
    layout->addWidget(labelGpa);
    layout->addWidget(editGpa);
    layout->addWidget(buttonEnter);
    vLayout->addLayout(layout);
    vLayout->addWidget(tableStudent);
    vLayout->addWidget(treeCourse);
    
    setLayout(vLayout);
    //resize(400,60);
    
}
void AddStudentWidget::update(){
    // do nothing yet
    QStandardItem *name = new QStandardItem(editName->text());
    QStandardItem *hours = new QStandardItem(editHours->text());
    QStandardItem *gpa = new QStandardItem(editGpa->text());
    QList<QStandardItem *> list;
    list << name<<hours<<gpa;
    modelStudent->appendRow(list);
    //call student
    //Student someStudent;
    //someStudent(editName->text(),editHours->text().toInt(),editGpa->text().toDouble());
    //someStudent.setName(editName->text());
    //someStudent.setHours(editHours->text().toInt());
    //someStudent.setGpa(editGpa->text().toDouble());
    //QMessageBox::information(this,QString("addstudentwidget"),QString("name:"+someStudent.getName()+"Hours:"+QString::number(someStudent.getHours())));
   
    //StudentWidget *studentWidget = new StudentWidget(student,modelStudent);
    //studentWidget->show();
    // following works try having addstudentwidget launch StudentWidget
    //static_cast<MainWindow *>(parentWidget())->createStudentWidget(editName->text(),editHours->text(),editGpa->text());
    // copied directly
    Student *someStudent= new Student;
    someStudent->setName(editName->text());
    someStudent->setHours(editHours->text().toInt());
    someStudent->setGpa(editGpa->text().toDouble());
    //QMessageBox::information(this,QString("Result"),QString("name:"+someStudent->getName()));
    StudentWidget *studentWidget = new StudentWidget(someStudent,modelCourse,modelStudent,static_cast<MainWindow *>(parentWidget())->getCourseList()->getModel());
    //StudentWidget *studentWidget = new StudentWidget(someStudent,static_cast<MainWindow *>(parentWidget())->getCourseList()->getModel());

    studentWidget->show();
}
Student AddStudentWidget::getStudent(QString n, QString h, QString g){
    return Student(n,h.toInt(),g.toDouble());
}
QStandardItemModel* AddStudentWidget::getModel(){
    return modelStudent;
}
void AddStudentWidget::updateGpa(QStandardItemModel *modelStudent,Student *s){
    
    // take from main
    QString hoursInt, gpaDouble;
    QString dave = "Fucker";
    //QModelIndex index = modelGpa->pare
    QStandardItem *name = new QStandardItem(s->getName());
    //QStandardItem *daveName = new QStandardItem(dave);
    QStandardItem *hoursG = new QStandardItem(hoursInt.setNum(s->getHours()));
    QStandardItem *gpaG = new QStandardItem(gpaDouble.setNum(s->getGpa()));
    //modelGpa->findItems()
    // loop on fucking model?
    int studentRow=0;
    for (int i=0; i< modelStudent->rowCount();i++)
    {
        if(modelStudent->item(i,0)->text() == s->getName())
            studentRow=i;
        }
    //QModelIndex index = modelGpa->indexFromItem(name);
    modelStudent->setItem(studentRow,1,hoursG);
    modelStudent->setItem(studentRow,2,gpaG);
}
void AddStudentWidget::updateCourse(QStandardItemModel* modelTreeCourse,QStandardItemModel* modelCourseAll, Student *s,QStandardItem* title){
    bool appended=false;
    QStandardItem *name = new QStandardItem(s->getName());
    QString nKitty="Kitty";
    QStandardItem *kitty = new QStandardItem(nKitty);
    // kluge way of doing it
    // iterate over tree then total
    for (int j=0; j< modelTreeCourse->rowCount();j++)
    {
        if(modelTreeCourse->item(j,0)->text() ==  title->text())
        {
            modelTreeCourse->item(j,0)->setChild(modelTreeCourse->item(j,0)->rowCount(),name);
            appended=true;
        }
    }
    
    // set up everything
    /*
    for(int j=0; j < modelCourseAll->rowCount();j++)
    {
        modelTreeCourse->setItem(j,0,modelCourseAll->item(j,0)->clone());
        modelTreeCourse->item(j,0)->setChild(0,name->clone());
        modelTreeCourse->item(j,0)->setChild(modelTreeCourse->item(j,0)->rowCount(),kitty->clone());

    }
     */
    //modelCourse->
    if (!appended)
    {
        int row=0;
        for (int i=0; i < modelCourseAll->rowCount();i++)
        {
            qDebug()<<"looping";
            if(modelCourseAll->item(i,0)->text() ==  title->text())
            {

                qDebug() <<"got here"+ i;
                modelTreeCourse->setItem(modelTreeCourse->rowCount(),0,modelCourseAll->item(i,0)->clone());
                modelTreeCourse->item(modelTreeCourse->rowCount()-1,0)->setChild(0,name->clone());
                row=i;
            }
        }
    }
    //modelTreeCourse->setItem(row,0,title);
    //modelTreeCourse->item(row,0)->setChild(0,name);
    
}
