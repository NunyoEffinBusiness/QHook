#ifndef QHOOKMOUSEEVENT_H
#define QHOOKMOUSEEVENT_H

#include <QPoint>

class QHookMouseEvent
{
public:
    enum EventType{ Button = 0, Move = 1 };
    enum Flags{ Injected = 0x1 };
    enum MouseButton{ LeftButton = 0x1, MiddleButton = 0x2, RightButton = 0x4 };

    QHookMouseEvent(EventType type, int button, QPoint pos, int flags);

    int button();
    EventType eventType();
    int flags();
    bool isInjected();
    QPoint pos();

private:
    const EventType p_Type;
    const int p_Button;
    const int p_Flags;
    const QPoint p_Pos;
};

#endif // QHOOKMOUSEEVENT_H
