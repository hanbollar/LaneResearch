/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[31];
    char stringdata0[585];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 13), // "sig_addVertex"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 37, 17), // "sig_vertexChanged"
QT_MOC_LITERAL(5, 55, 12), // "sig_addPoint"
QT_MOC_LITERAL(6, 68, 19), // "sig_clearVertexList"
QT_MOC_LITERAL(7, 88, 18), // "sig_clearPointList"
QT_MOC_LITERAL(8, 107, 22), // "sig_invalidTxtFileLine"
QT_MOC_LITERAL(9, 130, 24), // "sig_addSelectedVertPoint"
QT_MOC_LITERAL(10, 155, 27), // "sig_removeSelectedVertPoint"
QT_MOC_LITERAL(11, 183, 15), // "sig_DisplayPosX"
QT_MOC_LITERAL(12, 199, 15), // "sig_DisplayPosY"
QT_MOC_LITERAL(13, 215, 15), // "sig_DisplayPosZ"
QT_MOC_LITERAL(14, 231, 21), // "sig_preExistingVertex"
QT_MOC_LITERAL(15, 253, 11), // "timerUpdate"
QT_MOC_LITERAL(16, 265, 22), // "slot_vertexItemClicked"
QT_MOC_LITERAL(17, 288, 29), // "slot_interestPointItemClicked"
QT_MOC_LITERAL(18, 318, 17), // "slot_loadFileData"
QT_MOC_LITERAL(19, 336, 22), // "slot_loadPointsFromTxt"
QT_MOC_LITERAL(20, 359, 20), // "slot_savePointsToTxt"
QT_MOC_LITERAL(21, 380, 13), // "slot_recenter"
QT_MOC_LITERAL(22, 394, 25), // "slot_removedInterestPoint"
QT_MOC_LITERAL(23, 420, 17), // "slot_removedPoint"
QT_MOC_LITERAL(24, 438, 23), // "slot_addPointFromVertex"
QT_MOC_LITERAL(25, 462, 24), // "slot_highlightVertexById"
QT_MOC_LITERAL(26, 487, 23), // "slot_highlightPointById"
QT_MOC_LITERAL(27, 511, 18), // "slot_viewPointsSet"
QT_MOC_LITERAL(28, 530, 20), // "slot_viewObjVertices"
QT_MOC_LITERAL(29, 551, 13), // "slot_viewMesh"
QT_MOC_LITERAL(30, 565, 19) // "slot_creatingPoints"

    },
    "MyGL\0sig_addVertex\0\0QListWidgetItem*\0"
    "sig_vertexChanged\0sig_addPoint\0"
    "sig_clearVertexList\0sig_clearPointList\0"
    "sig_invalidTxtFileLine\0sig_addSelectedVertPoint\0"
    "sig_removeSelectedVertPoint\0sig_DisplayPosX\0"
    "sig_DisplayPosY\0sig_DisplayPosZ\0"
    "sig_preExistingVertex\0timerUpdate\0"
    "slot_vertexItemClicked\0"
    "slot_interestPointItemClicked\0"
    "slot_loadFileData\0slot_loadPointsFromTxt\0"
    "slot_savePointsToTxt\0slot_recenter\0"
    "slot_removedInterestPoint\0slot_removedPoint\0"
    "slot_addPointFromVertex\0"
    "slot_highlightVertexById\0"
    "slot_highlightPointById\0slot_viewPointsSet\0"
    "slot_viewObjVertices\0slot_viewMesh\0"
    "slot_creatingPoints"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       4,    1,  157,    2, 0x06 /* Public */,
       5,    1,  160,    2, 0x06 /* Public */,
       6,    0,  163,    2, 0x06 /* Public */,
       7,    0,  164,    2, 0x06 /* Public */,
       8,    1,  165,    2, 0x06 /* Public */,
       9,    1,  168,    2, 0x06 /* Public */,
      10,    1,  171,    2, 0x06 /* Public */,
      11,    1,  174,    2, 0x06 /* Public */,
      12,    1,  177,    2, 0x06 /* Public */,
      13,    1,  180,    2, 0x06 /* Public */,
      14,    1,  183,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  186,    2, 0x08 /* Private */,
      16,    1,  187,    2, 0x0a /* Public */,
      17,    1,  190,    2, 0x0a /* Public */,
      18,    1,  193,    2, 0x0a /* Public */,
      19,    1,  196,    2, 0x0a /* Public */,
      20,    1,  199,    2, 0x0a /* Public */,
      21,    0,  202,    2, 0x0a /* Public */,
      22,    0,  203,    2, 0x0a /* Public */,
      23,    1,  204,    2, 0x0a /* Public */,
      24,    0,  207,    2, 0x0a /* Public */,
      25,    1,  208,    2, 0x0a /* Public */,
      26,    1,  211,    2, 0x0a /* Public */,
      27,    1,  214,    2, 0x0a /* Public */,
      28,    1,  217,    2, 0x0a /* Public */,
      29,    1,  220,    2, 0x0a /* Public */,
      30,    1,  223,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_addVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->sig_vertexChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->sig_addPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->sig_clearVertexList(); break;
        case 4: _t->sig_clearPointList(); break;
        case 5: _t->sig_invalidTxtFileLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sig_addSelectedVertPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->sig_removeSelectedVertPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->sig_DisplayPosX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->sig_DisplayPosY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->sig_DisplayPosZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->sig_preExistingVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->timerUpdate(); break;
        case 13: _t->slot_vertexItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->slot_interestPointItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->slot_loadFileData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->slot_loadPointsFromTxt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->slot_savePointsToTxt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slot_recenter(); break;
        case 19: _t->slot_removedInterestPoint(); break;
        case 20: _t->slot_removedPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->slot_addPointFromVertex(); break;
        case 22: _t->slot_highlightVertexById((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->slot_highlightPointById((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->slot_viewPointsSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->slot_viewObjVertices((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->slot_viewMesh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->slot_creatingPoints((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_addVertex)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_vertexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_addPoint)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_clearVertexList)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_clearPointList)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_invalidTxtFileLine)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_addSelectedVertPoint)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_removeSelectedVertPoint)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_DisplayPosX)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_DisplayPosY)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_DisplayPosZ)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_preExistingVertex)) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata0))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MyGL::sig_addVertex(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::sig_vertexChanged(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::sig_addPoint(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::sig_clearVertexList()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MyGL::sig_clearPointList()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MyGL::sig_invalidTxtFileLine(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGL::sig_addSelectedVertPoint(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGL::sig_removeSelectedVertPoint(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGL::sig_DisplayPosX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyGL::sig_DisplayPosY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyGL::sig_DisplayPosZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MyGL::sig_preExistingVertex(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
