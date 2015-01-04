#include "qhookmouseevent.h"

QHookMouseEvent::QHookMouseEvent(EventType type, MouseButton button, QPoint pos) :
    p_Type(type), p_Button(button), p_Pos(pos)
{
}


int QHookMouseEvent::button(){ return p_Button; }
QHookMouseEvent::EventType QHookMouseEvent::eventType(){ return p_Type; }
QPoint QHookMouseEvent::pos(){ return p_Pos; }
