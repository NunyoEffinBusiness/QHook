#ifndef MOUSEHOOK_H
#define MOUSEHOOK_H

#include <QObject>
#include <QPoint>
#include <Windows.h>
#include <QDebug>

#include "qhookmouseevent.h"
#include "qhookwheelevent.h"

class MouseHook
{
public:
    MouseHook();

    void hook();
    void unhook();

private:
    HHOOK p_Hook;
};

#endif // MOUSEHOOK_H
