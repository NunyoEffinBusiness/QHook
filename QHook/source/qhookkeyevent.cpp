#include "qhookkeyevent.h"

QHookKeyEvent::QHookKeyEvent(int keyCode, int scanCode, int flags) :
    p_KeyCode(keyCode), p_ScanCode(scanCode), p_Flags(flags)
{
}

bool QHookKeyEvent::isAlt()
{
    return (flags() & QHookKeyEvent::Alt) ? true : false;
}

bool QHookKeyEvent::isExtended()
{
    return (flags() & QHookKeyEvent::Extended) ? true : false;
}

bool QHookKeyEvent::isInjected()
{
    return (flags() & QHookKeyEvent::Injected) ? true : false;
}

int QHookKeyEvent::flags(){ return p_Flags; }
int QHookKeyEvent::keyCode(){ return p_KeyCode; }
int QHookKeyEvent::scanCode(){ return p_ScanCode; }
