#include "qhookkeyevent.h"

QHookKeyEvent::QHookKeyEvent(int keyCode, int scanCode, int flags) :
    p_KeyCode(keyCode), p_ScanCode(scanCode), p_Flags(flags)
{
}


int QHookKeyEvent::flags(){ return p_Flags; }
int QHookKeyEvent::keyCode(){ return p_KeyCode; }
int QHookKeyEvent::scanCode(){ return p_ScanCode; }
