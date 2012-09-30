/****************************************************************************
** Meta object code from reading C++ file 'lavacao.h'
**
** Created: Sun Sep 30 18:04:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lavacao.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lavacao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Lavacao[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x0a,
      42,    9,    8,    8, 0x0a,
      64,    8,    8,    8, 0x0a,
      83,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Lavacao[] = {
    "Lavacao\0\0carro\0insereCarrosNaFila(Carro*)\0"
    "despachaCarro(Carro*)\0encerraSimulacao()\0"
    "criaAnimacaoEntrada()\0"
};

void Lavacao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Lavacao *_t = static_cast<Lavacao *>(_o);
        switch (_id) {
        case 0: _t->insereCarrosNaFila((*reinterpret_cast< Carro*(*)>(_a[1]))); break;
        case 1: _t->despachaCarro((*reinterpret_cast< Carro*(*)>(_a[1]))); break;
        case 2: _t->encerraSimulacao(); break;
        case 3: _t->criaAnimacaoEntrada(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Lavacao::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Lavacao::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Lavacao,
      qt_meta_data_Lavacao, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Lavacao::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Lavacao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Lavacao::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Lavacao))
        return static_cast<void*>(const_cast< Lavacao*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Lavacao*>(this));
    return QObject::qt_metacast(_clname);
}

int Lavacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
