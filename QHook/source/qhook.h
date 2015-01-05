#ifndef QHOOK_H
#define QHOOK_H

#include <QObject>

#include "keyboardhook.h"

#include "qhookkeyevent.h"
#include "qhookmouseevent.h"
#include "qhookwheelevent.h"

#include "keyboardhook.h"
#include "mousehook.h"
#include <QDebug>


class QHook : public QObject
{
    Q_OBJECT
public:
    QHook();
    ~QHook();

    static QHook* instance();

    bool isKeyboardHooked();
    bool isMouseHooked();

    virtual bool keyPressEvent(QHookKeyEvent *event);
    virtual bool keyReleaseEvent(QHookKeyEvent *event);

    virtual bool mouseMoveEvent(QHookMouseEvent *event);
    virtual bool mousePressEvent(QHookMouseEvent *event);
    virtual bool mouseReleaseEvent(QHookMouseEvent *event);
    virtual bool mouseWheelEvent(QHookWheelEvent *event);


private:
    KeyboardHook *p_KeyboardHook;
    MouseHook *p_MouseHook;


public slots:
    void hookKeyboard();
    void hookMouse();
    void unhookKeyboard();
    void unhookMouse();

};

#endif // QHOOK_H
