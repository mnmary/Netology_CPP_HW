/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QT HW8/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[28];
    char stringdata5[7];
    char stringdata6[25];
    char stringdata7[10];
    char stringdata8[4];
    char stringdata9[17];
    char stringdata10[20];
    char stringdata11[7];
    char stringdata12[25];
    char stringdata13[25];
    char stringdata14[22];
    char stringdata15[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "sig_RequestToDb"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 7),  // "request"
        QT_MOC_LITERAL(36, 27),  // "ReceiveStatusConnectionToDB"
        QT_MOC_LITERAL(64, 6),  // "status"
        QT_MOC_LITERAL(71, 24),  // "ReceiveStatusRequestToDB"
        QT_MOC_LITERAL(96, 9),  // "QSqlError"
        QT_MOC_LITERAL(106, 3),  // "err"
        QT_MOC_LITERAL(110, 16),  // "ScreenDataFromDB"
        QT_MOC_LITERAL(127, 19),  // "const QTableWidget*"
        QT_MOC_LITERAL(147, 6),  // "widget"
        QT_MOC_LITERAL(154, 24),  // "on_act_addData_triggered"
        QT_MOC_LITERAL(179, 24),  // "on_act_connect_triggered"
        QT_MOC_LITERAL(204, 21),  // "on_pb_request_clicked"
        QT_MOC_LITERAL(226, 19)   // "on_pb_clear_clicked"
    },
    "MainWindow",
    "sig_RequestToDb",
    "",
    "request",
    "ReceiveStatusConnectionToDB",
    "status",
    "ReceiveStatusRequestToDB",
    "QSqlError",
    "err",
    "ScreenDataFromDB",
    "const QTableWidget*",
    "widget",
    "on_act_addData_triggered",
    "on_act_connect_triggered",
    "on_pb_request_clicked",
    "on_pb_clear_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   68,    2, 0x0a,    5 /* Public */,
       9,    1,   71,    2, 0x0a,    7 /* Public */,
      12,    0,   74,    2, 0x08,    9 /* Private */,
      13,    0,   75,    2, 0x08,   10 /* Private */,
      14,    0,   76,    2, 0x08,   11 /* Private */,
      15,    0,   77,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'sig_RequestToDb'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ReceiveStatusConnectionToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ReceiveStatusRequestToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>,
        // method 'ScreenDataFromDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTableWidget *, std::false_type>,
        // method 'on_act_addData_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_act_connect_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_request_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_RequestToDb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->ReceiveStatusConnectionToDB((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->ReceiveStatusRequestToDB((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1]))); break;
        case 3: _t->ScreenDataFromDB((*reinterpret_cast< std::add_pointer_t<const QTableWidget*>>(_a[1]))); break;
        case 4: _t->on_act_addData_triggered(); break;
        case 5: _t->on_act_connect_triggered(); break;
        case 6: _t->on_pb_request_clicked(); break;
        case 7: _t->on_pb_clear_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::sig_RequestToDb; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_RequestToDb(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
