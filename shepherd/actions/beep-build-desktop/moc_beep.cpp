/****************************************************************************
** Meta object code from reading C++ file 'beep.h'
**
** Created: Thu Jul 8 18:58:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../beep/beep.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'beep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BeepActionPlugin[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   18,   17, 0x0a,
      33,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BeepActionPlugin[] = {
    "BeepActionPlugin\0\0bool\0execute()\0"
    "aboutPlugin()\0"
};

const QMetaObject BeepActionPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BeepActionPlugin,
      qt_meta_data_BeepActionPlugin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BeepActionPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BeepActionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BeepActionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BeepActionPlugin))
        return static_cast<void*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "InfoInterface"))
        return static_cast< InfoInterface*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "InputInterface"))
        return static_cast< InputInterface*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "ActionInterface"))
        return static_cast< ActionInterface*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.InfoInterface/1.0"))
        return static_cast< InfoInterface*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.InputInterface/1.0"))
        return static_cast< InputInterface*>(const_cast< BeepActionPlugin*>(this));
    if (!strcmp(_clname, "org.shepherd.ActionInterface/1.0"))
        return static_cast< ActionInterface*>(const_cast< BeepActionPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int BeepActionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = execute();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: aboutPlugin(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
