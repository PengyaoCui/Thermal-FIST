/****************************************************************************
** Meta object code from reading C++ file 'eventgeneratortab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eventgeneratortab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventgeneratortab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventGeneratorWorker_t {
    QByteArrayData data[3];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventGeneratorWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventGeneratorWorker_t qt_meta_stringdata_EventGeneratorWorker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "EventGeneratorWorker"
QT_MOC_LITERAL(1, 21, 10), // "calculated"
QT_MOC_LITERAL(2, 32, 0) // ""

    },
    "EventGeneratorWorker\0calculated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventGeneratorWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void EventGeneratorWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventGeneratorWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calculated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EventGeneratorWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventGeneratorWorker::calculated)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EventGeneratorWorker::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_EventGeneratorWorker.data,
    qt_meta_data_EventGeneratorWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventGeneratorWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventGeneratorWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventGeneratorWorker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int EventGeneratorWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void EventGeneratorWorker::calculated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_EventGeneratorTab_t {
    QByteArrayData data[34];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventGeneratorTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventGeneratorTab_t qt_meta_stringdata_EventGeneratorTab = {
    {
QT_MOC_LITERAL(0, 0, 17), // "EventGeneratorTab"
QT_MOC_LITERAL(1, 18, 10), // "changedRow"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "calculate"
QT_MOC_LITERAL(4, 40, 6), // "replot"
QT_MOC_LITERAL(5, 47, 15), // "QVector<double>"
QT_MOC_LITERAL(6, 63, 2), // "x1"
QT_MOC_LITERAL(7, 66, 2), // "y1"
QT_MOC_LITERAL(8, 69, 5), // "y1err"
QT_MOC_LITERAL(9, 75, 2), // "x2"
QT_MOC_LITERAL(10, 78, 2), // "y2"
QT_MOC_LITERAL(11, 81, 5), // "index"
QT_MOC_LITERAL(12, 87, 10), // "rightlimit"
QT_MOC_LITERAL(13, 98, 8), // "replot2D"
QT_MOC_LITERAL(14, 107, 2), // "xv"
QT_MOC_LITERAL(15, 110, 2), // "yv"
QT_MOC_LITERAL(16, 113, 2), // "zv"
QT_MOC_LITERAL(17, 116, 19), // "quantityDoubleClick"
QT_MOC_LITERAL(18, 136, 11), // "QModelIndex"
QT_MOC_LITERAL(19, 148, 8), // "setModel"
QT_MOC_LITERAL(20, 157, 30), // "thermalfist::ThermalModelBase*"
QT_MOC_LITERAL(21, 188, 5), // "model"
QT_MOC_LITERAL(22, 194, 14), // "updateProgress"
QT_MOC_LITERAL(23, 209, 8), // "finalize"
QT_MOC_LITERAL(24, 218, 10), // "changePlot"
QT_MOC_LITERAL(25, 229, 12), // "modelChanged"
QT_MOC_LITERAL(26, 242, 8), // "resetTPS"
QT_MOC_LITERAL(27, 251, 14), // "loadAcceptance"
QT_MOC_LITERAL(28, 266, 16), // "chooseOutputFile"
QT_MOC_LITERAL(29, 283, 15), // "changeVolumeRSC"
QT_MOC_LITERAL(30, 299, 10), // "changeTkin"
QT_MOC_LITERAL(31, 310, 14), // "generateEvents"
QT_MOC_LITERAL(32, 325, 18), // "ThermalModelConfig"
QT_MOC_LITERAL(33, 344, 6) // "config"

    },
    "EventGeneratorTab\0changedRow\0\0calculate\0"
    "replot\0QVector<double>\0x1\0y1\0y1err\0"
    "x2\0y2\0index\0rightlimit\0replot2D\0xv\0"
    "yv\0zv\0quantityDoubleClick\0QModelIndex\0"
    "setModel\0thermalfist::ThermalModelBase*\0"
    "model\0updateProgress\0finalize\0changePlot\0"
    "modelChanged\0resetTPS\0loadAcceptance\0"
    "chooseOutputFile\0changeVolumeRSC\0"
    "changeTkin\0generateEvents\0ThermalModelConfig\0"
    "config"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventGeneratorTab[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       4,    7,  112,    2, 0x0a /* Public */,
       4,    6,  127,    2, 0x2a /* Public | MethodCloned */,
      13,    5,  140,    2, 0x0a /* Public */,
      13,    4,  151,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  160,    2, 0x0a /* Public */,
      19,    1,  163,    2, 0x0a /* Public */,
      22,    0,  166,    2, 0x0a /* Public */,
      23,    0,  167,    2, 0x0a /* Public */,
      24,    0,  168,    2, 0x0a /* Public */,
      25,    0,  169,    2, 0x0a /* Public */,
      26,    0,  170,    2, 0x0a /* Public */,
      27,    0,  171,    2, 0x0a /* Public */,
      28,    0,  172,    2, 0x0a /* Public */,
      29,    1,  173,    2, 0x0a /* Public */,
      30,    1,  176,    2, 0x0a /* Public */,
      31,    1,  179,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, QMetaType::Double,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int,    6,    7,    8,    9,   10,   11,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, QMetaType::Double,   14,   15,   16,   11,   12,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int,   14,   15,   16,   11,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 32,   33,

       0        // eod
};

void EventGeneratorTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventGeneratorTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changedRow(); break;
        case 1: _t->calculate(); break;
        case 2: _t->replot(); break;
        case 3: _t->replot((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< const QVector<double>(*)>(_a[4])),(*reinterpret_cast< const QVector<double>(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        case 4: _t->replot((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< const QVector<double>(*)>(_a[4])),(*reinterpret_cast< const QVector<double>(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 5: _t->replot2D((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 6: _t->replot2D((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->quantityDoubleClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->setModel((*reinterpret_cast< thermalfist::ThermalModelBase*(*)>(_a[1]))); break;
        case 9: _t->updateProgress(); break;
        case 10: _t->finalize(); break;
        case 11: _t->changePlot(); break;
        case 12: _t->modelChanged(); break;
        case 13: _t->resetTPS(); break;
        case 14: _t->loadAcceptance(); break;
        case 15: _t->chooseOutputFile(); break;
        case 16: _t->changeVolumeRSC((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->changeTkin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->generateEvents((*reinterpret_cast< const ThermalModelConfig(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EventGeneratorTab::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_EventGeneratorTab.data,
    qt_meta_data_EventGeneratorTab,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventGeneratorTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventGeneratorTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventGeneratorTab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EventGeneratorTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
