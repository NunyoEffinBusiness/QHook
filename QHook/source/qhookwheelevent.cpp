#include "qhookwheelevent.h"

QHookWheelEvent::QHookWheelEvent(Direction direction, int delta, QPoint pos, int flags) :
    p_Dir(direction), p_Delta(delta), p_Pos(pos), p_Flags(flags)
{
}


int QHookWheelEvent::delta(){ return p_Delta; }
int QHookWheelEvent::direction(){ return p_Dir; }
int QHookWheelEvent::flags(){ return p_Flags; }
bool QHookWheelEvent::isInjected(){ return (p_Flags & Injected) ? true : false; }
QPoint QHookWheelEvent::pos(){ return p_Pos; }
