#include "qhookwheelevent.h"

QHookWheelEvent::QHookWheelEvent(Direction direction, int delta, QPoint pos) :
    p_Dir(direction), p_Delta(delta), p_Pos(pos)
{
}


int QHookWheelEvent::delta(){ return p_Delta; }
int QHookWheelEvent::direction(){ return p_Dir; }
QPoint QHookWheelEvent::pos(){ return p_Pos; }
