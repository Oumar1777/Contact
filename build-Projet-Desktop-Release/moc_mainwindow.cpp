/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Projet/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[75];
    char stringdata0[1339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "refreshContacts"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "GestionContact&"
QT_MOC_LITERAL(4, 44, 19), // "refreshInteractions"
QT_MOC_LITERAL(5, 64, 12), // "refreshTodos"
QT_MOC_LITERAL(6, 77, 10), // "todoToSave"
QT_MOC_LITERAL(7, 88, 12), // "QStringList&"
QT_MOC_LITERAL(8, 101, 18), // "searchContactByNom"
QT_MOC_LITERAL(9, 120, 19), // "std::list<Contact>&"
QT_MOC_LITERAL(10, 140, 21), // "searchContactByPrenom"
QT_MOC_LITERAL(11, 162, 25), // "searchContactByEntreprise"
QT_MOC_LITERAL(12, 188, 24), // "searchContactByNomPrenom"
QT_MOC_LITERAL(13, 213, 28), // "searchContactByNomEntreprise"
QT_MOC_LITERAL(14, 242, 31), // "searchContactByPrenomEntreprise"
QT_MOC_LITERAL(15, 274, 34), // "searchContactByNomPrenomEntre..."
QT_MOC_LITERAL(16, 309, 22), // "searchContactByAllInfo"
QT_MOC_LITERAL(17, 332, 24), // "searchContactInteraction"
QT_MOC_LITERAL(18, 357, 23), // "std::list<Interaction>&"
QT_MOC_LITERAL(19, 381, 17), // "searchContactTodo"
QT_MOC_LITERAL(20, 399, 16), // "std::list<Todo>&"
QT_MOC_LITERAL(21, 416, 13), // "errorHappened"
QT_MOC_LITERAL(22, 430, 15), // "warningHappened"
QT_MOC_LITERAL(23, 446, 12), // "infoReceived"
QT_MOC_LITERAL(24, 459, 7), // "refresh"
QT_MOC_LITERAL(25, 467, 11), // "showContact"
QT_MOC_LITERAL(26, 479, 7), // "Quitter"
QT_MOC_LITERAL(27, 487, 16), // "createMainWidget"
QT_MOC_LITERAL(28, 504, 26), // "createContactForMainWidget"
QT_MOC_LITERAL(29, 531, 8), // "QWidget*"
QT_MOC_LITERAL(30, 540, 7), // "Contact"
QT_MOC_LITERAL(31, 548, 23), // "createTodoForMainWidget"
QT_MOC_LITERAL(32, 572, 4), // "Todo"
QT_MOC_LITERAL(33, 577, 23), // "createContactPageWidget"
QT_MOC_LITERAL(34, 601, 37), // "createInteractionWidgetForCon..."
QT_MOC_LITERAL(35, 639, 11), // "Interaction"
QT_MOC_LITERAL(36, 651, 30), // "createTodoWidgetForContactPage"
QT_MOC_LITERAL(37, 682, 16), // "insertContactPic"
QT_MOC_LITERAL(38, 699, 12), // "ajoutContact"
QT_MOC_LITERAL(39, 712, 8), // "verifier"
QT_MOC_LITERAL(40, 721, 12), // "resetContact"
QT_MOC_LITERAL(41, 734, 11), // "saveContact"
QT_MOC_LITERAL(42, 746, 13), // "deleteContact"
QT_MOC_LITERAL(43, 760, 19), // "modificationContact"
QT_MOC_LITERAL(44, 780, 39), // "createInteractionForModificat..."
QT_MOC_LITERAL(45, 820, 21), // "deleteThisInteraction"
QT_MOC_LITERAL(46, 842, 14), // "deleteThisTodo"
QT_MOC_LITERAL(47, 857, 19), // "todoContenuModified"
QT_MOC_LITERAL(48, 877, 16), // "todoDateModified"
QT_MOC_LITERAL(49, 894, 26), // "interactionContenuModified"
QT_MOC_LITERAL(50, 921, 23), // "interactionDateModified"
QT_MOC_LITERAL(51, 945, 17), // "contactIsModified"
QT_MOC_LITERAL(52, 963, 16), // "saveModification"
QT_MOC_LITERAL(53, 980, 14), // "seeAllContacts"
QT_MOC_LITERAL(54, 995, 26), // "createAllContactPageWidget"
QT_MOC_LITERAL(55, 1022, 30), // "createContactForAllContactPage"
QT_MOC_LITERAL(56, 1053, 34), // "createInteractionForAllContac..."
QT_MOC_LITERAL(57, 1088, 27), // "createTodoForAllContactPage"
QT_MOC_LITERAL(58, 1116, 8), // "toDelete"
QT_MOC_LITERAL(59, 1125, 9), // "fromDate_"
QT_MOC_LITERAL(60, 1135, 7), // "toDate_"
QT_MOC_LITERAL(61, 1143, 13), // "show_fromDate"
QT_MOC_LITERAL(62, 1157, 11), // "show_toDate"
QT_MOC_LITERAL(63, 1169, 16), // "ajoutInteraction"
QT_MOC_LITERAL(64, 1186, 14), // "boomNameChange"
QT_MOC_LITERAL(65, 1201, 14), // "addInteraction"
QT_MOC_LITERAL(66, 1216, 15), // "saveInteraction"
QT_MOC_LITERAL(67, 1232, 9), // "saveTodos"
QT_MOC_LITERAL(68, 1242, 9), // "searching"
QT_MOC_LITERAL(69, 1252, 16), // "searchingContact"
QT_MOC_LITERAL(70, 1269, 20), // "searchingInteraction"
QT_MOC_LITERAL(71, 1290, 13), // "searchingTodo"
QT_MOC_LITERAL(72, 1304, 8), // "selected"
QT_MOC_LITERAL(73, 1313, 13), // "selectedCombo"
QT_MOC_LITERAL(74, 1327, 11) // "exportJason"

    },
    "MainWindow\0refreshContacts\0\0GestionContact&\0"
    "refreshInteractions\0refreshTodos\0"
    "todoToSave\0QStringList&\0searchContactByNom\0"
    "std::list<Contact>&\0searchContactByPrenom\0"
    "searchContactByEntreprise\0"
    "searchContactByNomPrenom\0"
    "searchContactByNomEntreprise\0"
    "searchContactByPrenomEntreprise\0"
    "searchContactByNomPrenomEntreprise\0"
    "searchContactByAllInfo\0searchContactInteraction\0"
    "std::list<Interaction>&\0searchContactTodo\0"
    "std::list<Todo>&\0errorHappened\0"
    "warningHappened\0infoReceived\0refresh\0"
    "showContact\0Quitter\0createMainWidget\0"
    "createContactForMainWidget\0QWidget*\0"
    "Contact\0createTodoForMainWidget\0Todo\0"
    "createContactPageWidget\0"
    "createInteractionWidgetForContactPage\0"
    "Interaction\0createTodoWidgetForContactPage\0"
    "insertContactPic\0ajoutContact\0verifier\0"
    "resetContact\0saveContact\0deleteContact\0"
    "modificationContact\0"
    "createInteractionForModificationContact\0"
    "deleteThisInteraction\0deleteThisTodo\0"
    "todoContenuModified\0todoDateModified\0"
    "interactionContenuModified\0"
    "interactionDateModified\0contactIsModified\0"
    "saveModification\0seeAllContacts\0"
    "createAllContactPageWidget\0"
    "createContactForAllContactPage\0"
    "createInteractionForAllContactPage\0"
    "createTodoForAllContactPage\0toDelete\0"
    "fromDate_\0toDate_\0show_fromDate\0"
    "show_toDate\0ajoutInteraction\0"
    "boomNameChange\0addInteraction\0"
    "saveInteraction\0saveTodos\0searching\0"
    "searchingContact\0searchingInteraction\0"
    "searchingTodo\0selected\0selectedCombo\0"
    "exportJason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  334,    2, 0x06 /* Public */,
       4,    1,  337,    2, 0x06 /* Public */,
       5,    1,  340,    2, 0x06 /* Public */,
       6,    1,  343,    2, 0x06 /* Public */,
       8,    4,  346,    2, 0x06 /* Public */,
      10,    4,  355,    2, 0x06 /* Public */,
      11,    4,  364,    2, 0x06 /* Public */,
      12,    4,  373,    2, 0x06 /* Public */,
      13,    4,  382,    2, 0x06 /* Public */,
      14,    4,  391,    2, 0x06 /* Public */,
      15,    4,  400,    2, 0x06 /* Public */,
      16,    4,  409,    2, 0x06 /* Public */,
      17,    5,  418,    2, 0x06 /* Public */,
      19,    5,  429,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  440,    2, 0x0a /* Public */,
      22,    1,  443,    2, 0x0a /* Public */,
      23,    1,  446,    2, 0x0a /* Public */,
      24,    0,  449,    2, 0x0a /* Public */,
      25,    0,  450,    2, 0x0a /* Public */,
      26,    0,  451,    2, 0x0a /* Public */,
      27,    0,  452,    2, 0x0a /* Public */,
      28,    1,  453,    2, 0x0a /* Public */,
      31,    1,  456,    2, 0x0a /* Public */,
      33,    0,  459,    2, 0x0a /* Public */,
      34,    1,  460,    2, 0x0a /* Public */,
      36,    1,  463,    2, 0x0a /* Public */,
      37,    0,  466,    2, 0x0a /* Public */,
      38,    0,  467,    2, 0x0a /* Public */,
      39,    0,  468,    2, 0x0a /* Public */,
      40,    0,  469,    2, 0x0a /* Public */,
      41,    1,  470,    2, 0x0a /* Public */,
      42,    1,  473,    2, 0x0a /* Public */,
      43,    0,  476,    2, 0x0a /* Public */,
      44,    1,  477,    2, 0x0a /* Public */,
      45,    0,  480,    2, 0x0a /* Public */,
      46,    0,  481,    2, 0x0a /* Public */,
      47,    0,  482,    2, 0x0a /* Public */,
      48,    0,  483,    2, 0x0a /* Public */,
      49,    0,  484,    2, 0x0a /* Public */,
      50,    0,  485,    2, 0x0a /* Public */,
      51,    0,  486,    2, 0x0a /* Public */,
      52,    0,  487,    2, 0x0a /* Public */,
      53,    0,  488,    2, 0x0a /* Public */,
      54,    0,  489,    2, 0x0a /* Public */,
      55,    1,  490,    2, 0x0a /* Public */,
      56,    1,  493,    2, 0x0a /* Public */,
      57,    1,  496,    2, 0x0a /* Public */,
      58,    0,  499,    2, 0x0a /* Public */,
      59,    0,  500,    2, 0x0a /* Public */,
      60,    0,  501,    2, 0x0a /* Public */,
      61,    1,  502,    2, 0x0a /* Public */,
      62,    1,  505,    2, 0x0a /* Public */,
      63,    0,  508,    2, 0x0a /* Public */,
      64,    1,  509,    2, 0x0a /* Public */,
      65,    0,  512,    2, 0x0a /* Public */,
      66,    0,  513,    2, 0x0a /* Public */,
      67,    1,  514,    2, 0x0a /* Public */,
      68,    0,  517,    2, 0x0a /* Public */,
      69,    0,  518,    2, 0x0a /* Public */,
      70,    0,  519,    2, 0x0a /* Public */,
      71,    0,  520,    2, 0x0a /* Public */,
      72,    1,  521,    2, 0x0a /* Public */,
      73,    1,  524,    2, 0x0a /* Public */,
      74,    0,  527,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 18, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 29, 0x80000000 | 30,    2,
    0x80000000 | 29, 0x80000000 | 32,    2,
    QMetaType::Void,
    0x80000000 | 29, 0x80000000 | 35,    2,
    0x80000000 | 29, 0x80000000 | 32,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    0x80000000 | 29, 0x80000000 | 35,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 29, 0x80000000 | 30,    2,
    0x80000000 | 29, 0x80000000 | 35,    2,
    0x80000000 | 29, 0x80000000 | 32,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshContacts((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 1: _t->refreshInteractions((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 2: _t->refreshTodos((*reinterpret_cast< GestionContact(*)>(_a[1]))); break;
        case 3: _t->todoToSave((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->searchContactByNom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 5: _t->searchContactByPrenom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 6: _t->searchContactByEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 7: _t->searchContactByNomPrenom((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 8: _t->searchContactByNomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 9: _t->searchContactByPrenomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 10: _t->searchContactByNomPrenomEntreprise((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 11: _t->searchContactByAllInfo((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 12: _t->searchContactInteraction((*reinterpret_cast< std::list<Contact>(*)>(_a[1])),(*reinterpret_cast< std::list<Interaction>(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 13: _t->searchContactTodo((*reinterpret_cast< std::list<Interaction>(*)>(_a[1])),(*reinterpret_cast< std::list<Todo>(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 14: _t->errorHappened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->warningHappened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->infoReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->refresh(); break;
        case 18: _t->showContact(); break;
        case 19: _t->Quitter(); break;
        case 20: _t->createMainWidget(); break;
        case 21: { QWidget* _r = _t->createContactForMainWidget((*reinterpret_cast< const Contact(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 22: { QWidget* _r = _t->createTodoForMainWidget((*reinterpret_cast< const Todo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 23: _t->createContactPageWidget(); break;
        case 24: { QWidget* _r = _t->createInteractionWidgetForContactPage((*reinterpret_cast< const Interaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 25: { QWidget* _r = _t->createTodoWidgetForContactPage((*reinterpret_cast< const Todo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 26: _t->insertContactPic(); break;
        case 27: _t->ajoutContact(); break;
        case 28: _t->verifier(); break;
        case 29: _t->resetContact(); break;
        case 30: _t->saveContact((*reinterpret_cast< const Contact(*)>(_a[1]))); break;
        case 31: _t->deleteContact((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->modificationContact(); break;
        case 33: { QWidget* _r = _t->createInteractionForModificationContact((*reinterpret_cast< const Interaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 34: _t->deleteThisInteraction(); break;
        case 35: _t->deleteThisTodo(); break;
        case 36: _t->todoContenuModified(); break;
        case 37: _t->todoDateModified(); break;
        case 38: _t->interactionContenuModified(); break;
        case 39: _t->interactionDateModified(); break;
        case 40: _t->contactIsModified(); break;
        case 41: _t->saveModification(); break;
        case 42: _t->seeAllContacts(); break;
        case 43: _t->createAllContactPageWidget(); break;
        case 44: { QWidget* _r = _t->createContactForAllContactPage((*reinterpret_cast< const Contact(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 45: { QWidget* _r = _t->createInteractionForAllContactPage((*reinterpret_cast< const Interaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 46: { QWidget* _r = _t->createTodoForAllContactPage((*reinterpret_cast< const Todo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 47: _t->toDelete(); break;
        case 48: _t->fromDate_(); break;
        case 49: _t->toDate_(); break;
        case 50: _t->show_fromDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 51: _t->show_toDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 52: _t->ajoutInteraction(); break;
        case 53: _t->boomNameChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->addInteraction(); break;
        case 55: _t->saveInteraction(); break;
        case 56: _t->saveTodos((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 57: _t->searching(); break;
        case 58: _t->searchingContact(); break;
        case 59: _t->searchingInteraction(); break;
        case 60: _t->searchingTodo(); break;
        case 61: _t->selected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->selectedCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->exportJason(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(GestionContact & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::refreshContacts)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(GestionContact & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::refreshInteractions)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(GestionContact & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::refreshTodos)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::todoToSave)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByNom)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByPrenom)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByEntreprise)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByNomPrenom)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByNomEntreprise)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByPrenomEntreprise)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByNomPrenomEntreprise)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactByAllInfo)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Contact> & , std::list<Interaction> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactInteraction)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::list<Interaction> & , std::list<Todo> & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchContactTodo)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 64;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::refreshContacts(GestionContact & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::refreshInteractions(GestionContact & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::refreshTodos(GestionContact & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::todoToSave(QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::searchContactByNom(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::searchContactByPrenom(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::searchContactByEntreprise(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::searchContactByNomPrenom(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::searchContactByNomEntreprise(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::searchContactByPrenomEntreprise(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::searchContactByNomPrenomEntreprise(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::searchContactByAllInfo(std::list<Contact> & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::searchContactInteraction(std::list<Contact> & _t1, std::list<Interaction> & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::searchContactTodo(std::list<Interaction> & _t1, std::list<Todo> & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
