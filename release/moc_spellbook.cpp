/****************************************************************************
** Meta object code from reading C++ file 'spellbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spellbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spellbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Spellbook_t {
    QByteArrayData data[24];
    char stringdata0[443];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spellbook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spellbook_t qt_meta_stringdata_Spellbook = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Spellbook"
QT_MOC_LITERAL(1, 10, 20), // "on_spellList_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 44, 5), // "index"
QT_MOC_LITERAL(5, 50, 31), // "on_sort1Box_currentIndexChanged"
QT_MOC_LITERAL(6, 82, 4), // "arg1"
QT_MOC_LITERAL(7, 87, 31), // "on_sort2Box_currentIndexChanged"
QT_MOC_LITERAL(8, 119, 26), // "on_spellList_cellActivated"
QT_MOC_LITERAL(9, 146, 3), // "row"
QT_MOC_LITERAL(10, 150, 6), // "column"
QT_MOC_LITERAL(11, 157, 24), // "on_spellList_cellEntered"
QT_MOC_LITERAL(12, 182, 32), // "on_filterBox_currentIndexChanged"
QT_MOC_LITERAL(13, 215, 20), // "on_spellList_entered"
QT_MOC_LITERAL(14, 236, 22), // "on_spellList_activated"
QT_MOC_LITERAL(15, 259, 31), // "on_spellList_currentCellChanged"
QT_MOC_LITERAL(16, 291, 10), // "currentRow"
QT_MOC_LITERAL(17, 302, 13), // "currentColumn"
QT_MOC_LITERAL(18, 316, 11), // "previousRow"
QT_MOC_LITERAL(19, 328, 14), // "previousColumn"
QT_MOC_LITERAL(20, 343, 26), // "on_favoritesButton_clicked"
QT_MOC_LITERAL(21, 370, 27), // "on_favoritesButton_released"
QT_MOC_LITERAL(22, 398, 20), // "on_favButton_clicked"
QT_MOC_LITERAL(23, 419, 23) // "on_searchBar_textEdited"

    },
    "Spellbook\0on_spellList_clicked\0\0"
    "QModelIndex\0index\0on_sort1Box_currentIndexChanged\0"
    "arg1\0on_sort2Box_currentIndexChanged\0"
    "on_spellList_cellActivated\0row\0column\0"
    "on_spellList_cellEntered\0"
    "on_filterBox_currentIndexChanged\0"
    "on_spellList_entered\0on_spellList_activated\0"
    "on_spellList_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_favoritesButton_clicked\0"
    "on_favoritesButton_released\0"
    "on_favButton_clicked\0on_searchBar_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spellbook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       8,    2,   88,    2, 0x08 /* Private */,
      11,    2,   93,    2, 0x08 /* Private */,
      12,    1,   98,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      15,    4,  107,    2, 0x08 /* Private */,
      20,    0,  116,    2, 0x08 /* Private */,
      21,    0,  117,    2, 0x08 /* Private */,
      22,    0,  118,    2, 0x08 /* Private */,
      23,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void Spellbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spellbook *_t = static_cast<Spellbook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_spellList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_sort1Box_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_sort2Box_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_spellList_cellActivated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_spellList_cellEntered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_filterBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spellList_entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_spellList_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_spellList_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 9: _t->on_favoritesButton_clicked(); break;
        case 10: _t->on_favoritesButton_released(); break;
        case 11: _t->on_favButton_clicked(); break;
        case 12: _t->on_searchBar_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Spellbook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Spellbook.data,
      qt_meta_data_Spellbook,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Spellbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spellbook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Spellbook.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Spellbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
