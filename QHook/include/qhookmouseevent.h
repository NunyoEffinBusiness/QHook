#ifndef QHOOKMOUSEEVENT_H
#define QHOOKMOUSEEVENT_H

#include <QDebug>
#include <QPoint>

class QHookMouseEvent
{
public:
    enum EventType{ Move = 0, Button = 1, Wheel = 2 };
    enum MouseButton{ LeftButton = 0x1, RightButton = 0x2, MiddleButton = 0x4 };

    QHookMouseEvent(EventType type, MouseButton button, QPoint pos);

    int button();
    EventType eventType();
    QPoint pos();

private:
    const EventType p_Type;
    const int p_Button;
    const QPoint p_Pos;
};

#endif // QHOOKMOUSEEVENT_H
