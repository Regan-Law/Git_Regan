/****************************************************************************
** Meta object code from reading C++ file 'newcase.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MSC/newcase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_newcase_t {
    uint offsetsAndSizes[16];
    char stringdata0[8];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[15];
    char stringdata5[12];
    char stringdata6[19];
    char stringdata7[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_newcase_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_newcase_t qt_meta_stringdata_newcase = {
    {
        QT_MOC_LITERAL(0, 7),  // "newcase"
        QT_MOC_LITERAL(8, 17),  // "on_cancel_clicked"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "gettime"
        QT_MOC_LITERAL(35, 14),  // "getclickeddate"
        QT_MOC_LITERAL(50, 11),  // "clickeddate"
        QT_MOC_LITERAL(62, 18),  // "on_confirm_clicked"
        QT_MOC_LITERAL(81, 19)   // "on_addmedia_clicked"
    },
    "newcase",
    "on_cancel_clicked",
    "",
    "gettime",
    "getclickeddate",
    "clickeddate",
    "on_confirm_clicked",
    "on_addmedia_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newcase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    1,   46,    2, 0x0a,    3 /* Public */,
       6,    0,   49,    2, 0x0a,    5 /* Public */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void newcase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<newcase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_cancel_clicked(); break;
        case 1: _t->gettime(); break;
        case 2: _t->getclickeddate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: _t->on_confirm_clicked(); break;
        case 4: _t->on_addmedia_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject newcase::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_newcase.offsetsAndSizes,
    qt_meta_data_newcase,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_newcase_t
, QtPrivate::TypeAndForceComplete<newcase, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *newcase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newcase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_newcase.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int newcase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
