#ifndef QHOOKKEYEVENT_H
#define QHOOKKEYEVENT_H

class QHookKeyEvent
{
public:
    enum Flags{ Alt = 0x1, Extended = 0x2, Injected = 0x4 };

    QHookKeyEvent(int keyCode, int scanCode, int flags);

    int flags();
    int keyCode();
    int scanCode();

    bool isAlt();
    bool isExtended();
    bool isInjected();


private:
    const int p_Flags;
    const int p_KeyCode;
    const int p_ScanCode;
};

#endif // QHOOKKEYEVENT_H
