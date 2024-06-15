/****************************************************************************
** Meta object code from reading C++ file 'klientqthread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../klientqthread.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'klientqthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSklientQThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSklientQThreadENDCLASS = QtMocHelpers::stringData(
    "klientQThread",
    "listaWypozyczenGotowa",
    "",
    "daneWypozyczen",
    "listaDostepnychSamochodowGotowa",
    "samochody",
    "pobranyAdres",
    "email",
    "pobierzDostepneSamochody",
    "dataOd",
    "dataDo",
    "wybranyRodzaj",
    "wybranaMarka"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSklientQThreadENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[14];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[32];
    char stringdata5[10];
    char stringdata6[13];
    char stringdata7[6];
    char stringdata8[25];
    char stringdata9[7];
    char stringdata10[7];
    char stringdata11[14];
    char stringdata12[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSklientQThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSklientQThreadENDCLASS_t qt_meta_stringdata_CLASSklientQThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "klientQThread"
        QT_MOC_LITERAL(14, 21),  // "listaWypozyczenGotowa"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 14),  // "daneWypozyczen"
        QT_MOC_LITERAL(52, 31),  // "listaDostepnychSamochodowGotowa"
        QT_MOC_LITERAL(84, 9),  // "samochody"
        QT_MOC_LITERAL(94, 12),  // "pobranyAdres"
        QT_MOC_LITERAL(107, 5),  // "email"
        QT_MOC_LITERAL(113, 24),  // "pobierzDostepneSamochody"
        QT_MOC_LITERAL(138, 6),  // "dataOd"
        QT_MOC_LITERAL(145, 6),  // "dataDo"
        QT_MOC_LITERAL(152, 13),  // "wybranyRodzaj"
        QT_MOC_LITERAL(166, 12)   // "wybranaMarka"
    },
    "klientQThread",
    "listaWypozyczenGotowa",
    "",
    "daneWypozyczen",
    "listaDostepnychSamochodowGotowa",
    "samochody",
    "pobranyAdres",
    "email",
    "pobierzDostepneSamochody",
    "dataOd",
    "dataDo",
    "wybranyRodzaj",
    "wybranaMarka"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSklientQThreadENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   44,    2, 0x0a,    5 /* Public */,
       8,    4,   47,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QStringList,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject klientQThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSklientQThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSklientQThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSklientQThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<klientQThread, std::true_type>,
        // method 'listaWypozyczenGotowa'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QString>, std::false_type>,
        // method 'listaDostepnychSamochodowGotowa'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QString>, std::false_type>,
        // method 'pobranyAdres'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'pobierzDostepneSamochody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void klientQThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<klientQThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->listaWypozyczenGotowa((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 1: _t->listaDostepnychSamochodowGotowa((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 2: _t->pobranyAdres((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->pobierzDostepneSamochody((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (klientQThread::*)(const QList<QString> );
            if (_t _q_method = &klientQThread::listaWypozyczenGotowa; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (klientQThread::*)(const QList<QString> );
            if (_t _q_method = &klientQThread::listaDostepnychSamochodowGotowa; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *klientQThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *klientQThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSklientQThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int klientQThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void klientQThread::listaWypozyczenGotowa(const QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void klientQThread::listaDostepnychSamochodowGotowa(const QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
