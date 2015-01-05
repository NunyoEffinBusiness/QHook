#ifndef MOUSEHOOK_H
#define MOUSEHOOK_H

#include <QObject>
#include <QPoint>
#include <Windows.h>

#include "qhookmouseevent.h"
#include "qhookwheelevent.h"

class MouseHook
{
public:
    MouseHook();

    bool isHooked();

    void hook();
    void unhook();


private:
    HHOOK p_Hook;
};

#endif // MOUSEHOOK_H
