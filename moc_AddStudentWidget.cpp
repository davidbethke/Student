/****************************************************************************
** Meta object code from reading C++ file 'AddStudentWidget.h'
**
** Created: Mon Oct 17 19:50:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AddStudentWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddStudentWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddStudentWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      47,   17,   27,   17, 0x0a,
      60,   58,   17,   17, 0x0a,
     104,  100,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddStudentWidget[] = {
    "AddStudentWidget\0\0update()\0"
    "QStandardItemModel*\0getModel()\0,\0"
    "updateGpa(QStandardItemModel*,Student*)\0"
    ",,,\0"
    "updateCourse(QStandardItemModel*,QStandardItemModel*,Student*,QStandar"
    "dItem*)\0"
};

const QMetaObject AddStudentWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddStudentWidget,
      qt_meta_data_AddStudentWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddStudentWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddStudentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddStudentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddStudentWidget))
        return static_cast<void*>(const_cast< AddStudentWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddStudentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update(); break;
        case 1: { QStandardItemModel* _r = getModel();
            if (_a[0]) *reinterpret_cast< QStandardItemModel**>(_a[0]) = _r; }  break;
        case 2: updateGpa((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< Student*(*)>(_a[2]))); break;
        case 3: updateCourse((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< QStandardItemModel*(*)>(_a[2])),(*reinterpret_cast< Student*(*)>(_a[3])),(*reinterpret_cast< QStandardItem*(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
