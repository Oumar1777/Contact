/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBase_t {
    QByteArrayData data[23];
    char stringdata0[477];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBase_t qt_meta_stringdata_DataBase = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataBase"
QT_MOC_LITERAL(1, 9, 13), // "errorDataBase"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "infoDataBase"
QT_MOC_LITERAL(4, 37, 9), // "refreshed"
QT_MOC_LITERAL(5, 47, 18), // "refreshingContacts"
QT_MOC_LITERAL(6, 66, 15), // "GestionContact&"
QT_MOC_LITERAL(7, 82, 22), // "refreshingInteractions"
QT_MOC_LITERAL(8, 105, 15), // "refreshingTodos"
QT_MOC_LITERAL(9, 121, 10), // "refreshing"
QT_MOC_LITERAL(10, 132, 21), // "searchingContactbyNom"
QT_MOC_LITERAL(11, 154, 19), // "std::list<Contact>&"
QT_MOC_LITERAL(12, 174, 24), // "searchingContactByPrenom"
QT_MOC_LITERAL(13, 199, 28), // "searchingContactByEntreprise"
QT_MOC_LITERAL(14, 228, 27), // "searchingContactByNomPrenom"
QT_MOC_LITERAL(15, 256, 31), // "searchingContactByNomEntreprise"
QT_MOC_LITERAL(16, 288, 34), // "searchingContactByPrenomEntre..."
QT_MOC_LITERAL(17, 323, 37), // "searchingContactByNomPrenomEn..."
QT_MOC_LITERAL(18, 361, 25), // "searchingContactByAllInfo"
QT_MOC_LITERAL(19, 387, 27), // "searchingContactInteraction"
QT_MOC_LITERAL(20, 415, 23), // "std::list<Interaction>&"
QT_MOC_LITERAL(21, 439, 20), // "searchingContactTodo"
QT_MOC_LITERAL(22, 460, 16) // "std::list<Todo>&"

    },
    "DataBase\0errorDataBase\0\0infoDataBase\0"
    "refreshed\0refreshingContacts\0"
    "GestionContact&\0refreshingInteractions\0"
    "refreshingTodos\0refreshing\0"
    "searchingContactbyNom\0std::list<Contact>&\0"
    "searchingContactByPrenom\0"
    "searchingContactByEntreprise\0"
    "searchingContactByNomPrenom\0"
    "searchingContactByNomEntreprise\0"
    "searchingContactByPrenomEntreprise\0"
    "searchingContactByNomPrenomEntreprise\0"
    "searchingContactByAllInfo\0"
    "searchingContactInteraction\0"
    "std::list<Interaction>&\0searchingContactTodo\0"
    "std::list<Todo>&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       3,    1,  102,    2, 0x06 /* Public */,
       4,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  106,    2, 0x0a /* Public */,
       7,    1,  109,    2, 0x0a /* Public */,
       8,    1,  112,    2, 0x0a /* Public */,
       9,    1,  115,    2, 0x0a /* Public */,
      10,    4,  118,    2, 0x0a /* Public */,
      12,    4,  127,    2, 0x0a /* Public */,
      13,    4,  136,    2, 0x0a /* Public */,
      14,    4,  145,    2, 0x0a /* Public */,
      15,    4,  154,    2, 0x0a /* Public */,
      16,    4,  163,    2, 0x0a /* Public */,
      17,    4,  172,    2, 0x0a /* Public */,
      18,    4,  181,    2, 0x0a /* Public */,
      19,    5,  190,    2, 0x0a /* Public */,
      21,    5,  201,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 20, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,

       0        // eod
};

void DataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorDataBase((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->infoDataBase((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->refreshed(); break;
        case 3: _t->refreshingContacts((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 4: _t->refreshingInteractions((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 5: _t->refreshingTodos((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 6: _t->refreshing((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 7: _t->searchingContactbyNom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 8: _t->searchingContactByPrenom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 9: _t->searchingContactByEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 10: _t->searchingContactByNomPrenom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 11: _t->searchingContactByNomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 12: _t->searchingContactByPrenomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 13: _t->searchingContactByNomPrenomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 14: _t->searchingContactByAllInfo((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 15: _t->searchingContactInteraction((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< std::list<Interaction>(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 16: _t->searchingContactTodo((*reinterpret_cast< std::list<Interaction>(*)>(_a[1])),(*reinterpret_cast< std::list<Todo>(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataBase::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBase::errorDataBase)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBase::infoDataBase)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBase::refreshed)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataBase.data,
    qt_meta_data_DataBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DataBase::errorDataBase(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataBase::infoDataBase(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBase::refreshed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
