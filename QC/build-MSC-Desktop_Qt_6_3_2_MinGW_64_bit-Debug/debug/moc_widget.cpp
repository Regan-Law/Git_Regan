/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MSC/widget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    uint offsetsAndSizes[40];
    char stringdata0[7];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[28];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[15];
    char stringdata8[12];
    char stringdata9[14];
    char stringdata10[15];
    char stringdata11[6];
    char stringdata12[9];
    char stringdata13[22];
    char stringdata14[9];
    char stringdata15[20];
    char stringdata16[18];
    char stringdata17[16];
    char stringdata18[22];
    char stringdata19[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Widget_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 10),  // "changedate"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 4),  // "date"
        QT_MOC_LITERAL(24, 27),  // "on_ckShowLunar_stateChanged"
        QT_MOC_LITERAL(52, 4),  // "arg1"
        QT_MOC_LITERAL(57, 9),  // "showtoday"
        QT_MOC_LITERAL(67, 14),  // "getclickeddate"
        QT_MOC_LITERAL(82, 11),  // "clickeddate"
        QT_MOC_LITERAL(94, 13),  // "replyFinished"
        QT_MOC_LITERAL(108, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(123, 5),  // "reply"
        QT_MOC_LITERAL(129, 8),  // "showcase"
        QT_MOC_LITERAL(138, 21),  // "on_deletecase_clicked"
        QT_MOC_LITERAL(160, 8),  // "sendjump"
        QT_MOC_LITERAL(169, 19),  // "on_editcase_clicked"
        QT_MOC_LITERAL(189, 17),  // "on_search_clicked"
        QT_MOC_LITERAL(207, 15),  // "on_next_clicked"
        QT_MOC_LITERAL(223, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(245, 23)   // "on_pushButton_2_clicked"
    },
    "Widget",
    "changedate",
    "",
    "date",
    "on_ckShowLunar_stateChanged",
    "arg1",
    "showtoday",
    "getclickeddate",
    "clickeddate",
    "replyFinished",
    "QNetworkReply*",
    "reply",
    "showcase",
    "on_deletecase_clicked",
    "sendjump",
    "on_editcase_clicked",
    "on_search_clicked",
    "on_next_clicked",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   95,    2, 0x0a,    3 /* Public */,
       6,    0,   98,    2, 0x0a,    5 /* Public */,
       7,    1,   99,    2, 0x0a,    6 /* Public */,
       9,    1,  102,    2, 0x0a,    8 /* Public */,
      12,    1,  105,    2, 0x0a,   10 /* Public */,
      13,    0,  108,    2, 0x0a,   12 /* Public */,
      14,    1,  109,    2, 0x0a,   13 /* Public */,
      15,    0,  112,    2, 0x08,   15 /* Private */,
      16,    0,  113,    2, 0x08,   16 /* Private */,
      17,    0,  114,    2, 0x08,   17 /* Private */,
      18,    0,  115,    2, 0x08,   18 /* Private */,
      19,    0,  116,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changedate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 1: _t->on_ckShowLunar_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->showtoday(); break;
        case 3: _t->getclickeddate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 4: _t->replyFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 5: _t->showcase((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 6: _t->on_deletecase_clicked(); break;
        case 7: _t->sendjump((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 8: _t->on_editcase_clicked(); break;
        case 9: _t->on_search_clicked(); break;
        case 10: _t->on_next_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QDate );
            if (_t _q_method = &Widget::changedate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.offsetsAndSizes,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Widget_t
, QtPrivate::TypeAndForceComplete<Widget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Widget::changedate(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
