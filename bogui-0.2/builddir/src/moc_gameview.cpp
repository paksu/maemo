/****************************************************************************
** Meta object code from reading C++ file 'gameview.h'
**
** Created: Thu Feb 25 18:37:35 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gameview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      24,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      67,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameView[] = {
    "GameView\0\0gameStopped()\0noticeGameOver(int)\0"
    "startGame()\0stopGame()\0gameEnded(int)\0"
};

const QMetaObject GameView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GameView,
      qt_meta_data_GameView, 0 }
};

const QMetaObject *GameView::metaObject() const
{
    return &staticMetaObject;
}

void *GameView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameView))
        return static_cast<void*>(const_cast< GameView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gameStopped(); break;
        case 1: noticeGameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: startGame(); break;
        case 3: stopGame(); break;
        case 4: gameEnded((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GameView::gameStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameView::noticeGameOver(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
