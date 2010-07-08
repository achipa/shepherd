/****************************************************************************
** Meta object code from reading C++ file 'dummy.h'
**
** Created: Thu Jul 8 18:58:07 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dummy/dummy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dummy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DummyTriggerPlugin[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DummyTriggerPlugin[] = {
    "DummyTriggerPlugin\0\0aboutPlugin()\0"
};

const QMetaObject DummyTriggerPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DummyTriggerPlugin,
      qt_meta_data_DummyTriggerPlugin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DummyTriggerPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DummyTriggerPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DummyTriggerPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DummyTriggerPlugin))
        return static_cast<void*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "InfoInterface"))
        return static_cast< InfoInterface*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "InputInterface"))
        return static_cast< InputInterface*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "TriggerInterface"))
        return static_cast< TriggerInterface*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.InfoInterface/1.0"))
        return static_cast< InfoInterface*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.InputInterface/1.0"))
        return static_cast< InputInterface*>(const_cast< DummyTriggerPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.TriggerInterface/1.0"))
        return static_cast< TriggerInterface*>(const_cast< DummyTriggerPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int DummyTriggerPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: aboutPlugin(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
