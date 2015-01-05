#include "qhookmouseevent.h"

QHookMouseEvent::QHookMouseEvent(EventType type, int button, QPoint pos, int flags) :
    p_Type(type), p_Button(button), p_Pos(pos), p_Flags(flags)
{
}


int QHookMouseEvent::button(){ return p_Button; }
QHookMouseEvent::EventType QHookMouseEvent::eventType(){ return p_Type; }
int QHookMouseEvent::flags(){ return p_Flags; }
bool QHookMouseEvent::isInjected(){ return (flags() & QHookMouseEvent::Injected) ? true : false; }
QPoint QHookMouseEvent::pos(){ return p_Pos; }
