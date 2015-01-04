#include "qhook.h"

#ifndef Q_OS_WIN32

QHook::QHook(){}

#else

KeyboardHook* p_keyboardHook;

QHook::QHook()
{

}

#endif


/*!
 * These functions may be overridden to determin the event
 * and wheather or not it should go through or not
 *
 * Returning `true` on an event will allow the event to go through
 * while returning `false` will block the event
 */


bool QHook::keyPressEvent(QHookKeyEvent *event){ Q_UNUSED(event) return true; }
bool QHook::keyReleaseEvent(QHookKeyEvent *event){ Q_UNUSED(event) return true; }


bool QHook::mouseMoveEvent(QHookMouseEvent *event){ Q_UNUSED(event) return true; }
bool QHook::mousePressEvent(QHookMouseEvent *event){ Q_UNUSED(event) return true; }
bool QHook::mouseReleaseEvent(QHookMouseEvent *event){ Q_UNUSED(event) return true; }
