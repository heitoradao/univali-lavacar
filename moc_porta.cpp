/****************************************************************************
** Meta object code from reading C++ file 'porta.h'
**
** Created: Mon Sep 24 08:47:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "porta.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'porta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Porta[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Porta[] = {
    "Porta\0\0carro\0eventoEntraCarro(Carro*)\0"
    "geraCarro()\0"
};

void Porta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Porta *_t = static_cast<Porta *>(_o);
        switch (_id) {
        case 0: _t->eventoEntraCarro((*reinterpret_cast< Carro*(*)>(_a[1]))); break;
        case 1: _t->geraCarro(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Porta::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Porta::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Porta,
      qt_meta_data_Porta, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Porta::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Porta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Porta::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Porta))
        return static_cast<void*>(const_cast< Porta*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Porta*>(this));
    return QObject::qt_metacast(_clname);
}

int Porta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Porta::eventoEntraCarro(Carro * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
