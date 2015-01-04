#ifndef QHOOKWHEELEVENT_H
#define QHOOKWHEELEVENT_H

#include <QDebug>
#include <QPoint>

class QHookWheelEvent
{
public:
    enum Direction{ Up = 0, Down = 1 };

    QHookWheelEvent(Direction direction, int delta, QPoint pos);

    int direction();
    int delta();
    QPoint pos();

private:
    int p_Delta;
    Direction p_Dir;
    QPoint p_Pos;
};

#endif // QHOOKWHEELEVENT_H
