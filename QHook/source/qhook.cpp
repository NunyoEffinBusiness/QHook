#include "qhook.h"

QHook *hook;

QHook* QHook::instance(){ return hook; }

QHook::QHook()
{
    hook = this;

    p_KeyboardHook = new KeyboardHook();
    p_MouseHook = new MouseHook();
}

QHook::~QHook()
{
    p_KeyboardHook->unhook();
}

void QHook::hookKeyboard()
{
    p_KeyboardHook->hook();
}

void QHook::hookMouse()
{
    p_MouseHook->hook();
}

void QHook::unhookKeyboard()
{
    p_KeyboardHook->unhook();
}

void QHook::unhookMouse()
{
    p_MouseHook->unhook();
}


bool QHook::isKeyboardHooked(){ return p_KeyboardHook->isHooked(); }
bool QHook::isMouseHooked(){ return p_MouseHook->isHooked(); }

/*!
 * The functions below may be overridden to determin the event
 * and wheather or not it should go through or not
 *
 * Returning `true` on an event will allow the event to go through
 * while returning `false` will block the event
 */


bool QHook::keyPressEvent(QHookKeyEvent *event){ return true; }
bool QHook::keyReleaseEvent(QHookKeyEvent *event){ return true; }


bool QHook::mouseMoveEvent(QHookMouseEvent *event){ return true; }
bool QHook::mousePressEvent(QHookMouseEvent *event){ return true; }
bool QHook::mouseReleaseEvent(QHookMouseEvent *event){ return true; }
bool QHook::mouseWheelEvent(QHookWheelEvent *event){ return true; }
