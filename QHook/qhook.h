#ifndef QHOOK_H
#define QHOOK_H


#include <QObject>
#include "qhookkeyevent.h"
#include "qhookmouseevent.h"

#ifdef Q_OS_WIN32
#include "keyboardhook.h"
#else
class KeyboardHook{};
#endif


class QHook : public QObject
{
    Q_OBJECT
public:
    QHook();

    virtual bool keyPressEvent(QHookKeyEvent *event);
    virtual bool keyReleaseEvent(QHookKeyEvent *event);

    virtual bool mouseMoveEvent(QHookMouseEvent *event);
    virtual bool mousePressEvent(QHookMouseEvent *event);
    virtual bool mouseReleaseEvent(QHookMouseEvent *event);


private:
    KeyboardHook *p_KeyboardHook;
};

#endif // QHOOK_H
