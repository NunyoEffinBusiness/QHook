#ifndef QHOOKWHEELEVENT_H
#define QHOOKWHEELEVENT_H

#include <QPoint>

class QHookWheelEvent
{
public:
    enum Direction{ Down = 0, Up = 1 };
    enum Flags{ Injected = 0x1 };

    QHookWheelEvent(Direction direction, int delta, QPoint pos, int flags);

    int direction();
    int delta();
    int flags();
    bool isInjected();
    QPoint pos();

private:
    int p_Delta;
    Direction p_Dir;
    int p_Flags;
    QPoint p_Pos;
};

#endif // QHOOKWHEELEVENT_H
