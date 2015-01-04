#ifndef KEYBOARDHOOK_H
#define KEYBOARDHOOK_H

#include <QObject>
#include <Windows.h>

#include "qhookkeyevent.h"

class KeyboardHook
{
public:
    KeyboardHook();

    void hook();
    void unhook();

    bool isHooked();

private:
    HHOOK p_Hook;
};

#endif // KEYBOARDHOOK_H
