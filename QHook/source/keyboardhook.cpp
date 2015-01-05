#include "keyboardhook.h"
#include "qhook.h"

HHOOK keyHook;

LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*) lParam;

    bool result = true;

    int flags;
    flags |= (p->flags & LLKHF_ALTDOWN) ? QHookKeyEvent::Alt : 0;
    flags |= (p->flags & LLKHF_EXTENDED) ? QHookKeyEvent::Extended : 0;
    flags |= (p->flags & LLKHF_INJECTED) ? QHookKeyEvent::Injected : 0;

    if(wParam == WM_KEYDOWN)
        result = QHook::instance()->keyPressEvent(new QHookKeyEvent((int)p->vkCode, (int)p->scanCode, flags));
    else
        result = QHook::instance()->keyReleaseEvent(new QHookKeyEvent((int)p->vkCode, (int)p->scanCode, flags));

    if(result)
        return CallNextHookEx(keyHook, nCode, wParam, lParam);
    else
        return 1;
}

KeyboardHook::KeyboardHook()
{
    p_Hook = NULL;
    keyHook = p_Hook;
}


bool KeyboardHook::isHooked(){ return (p_Hook == NULL) ? false : true; }


void KeyboardHook::hook()
{
    if(p_Hook == NULL)
        p_Hook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHookProc, NULL, 0);

    keyHook = p_Hook;
}


void KeyboardHook::unhook()
{
    if(p_Hook != NULL)
        UnhookWindowsHookEx(p_Hook);

    p_Hook = NULL;
    keyHook = p_Hook;
}


