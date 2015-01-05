#include "mousehook.h"
#include "qhook.h"

HHOOK mouseHook;

LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if(nCode >= 0)
    {

        MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT*) lParam;
        bool result = true;

        int flags;
        flags |= (p->flags & LLMHF_INJECTED) ? QHookMouseEvent::Injected: 0;

        if(wParam == WM_LBUTTONDOWN)
            result = QHook::instance()->mousePressEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::LeftButton, QPoint(p->pt.x, p->pt.y), flags));
        else if(wParam == WM_LBUTTONUP)
            result = QHook::instance()->mouseReleaseEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::LeftButton, QPoint(p->pt.x, p->pt.y), flags));

        if(wParam == WM_RBUTTONDOWN)
            result = QHook::instance()->mousePressEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::RightButton, QPoint(p->pt.x, p->pt.y), flags));
        else if(wParam == WM_RBUTTONUP)
            result = QHook::instance()->mouseReleaseEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::RightButton, QPoint(p->pt.x, p->pt.y), flags));

        if(wParam == WM_MBUTTONDOWN)
            result = QHook::instance()->mousePressEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::MiddleButton, QPoint(p->pt.x, p->pt.y), flags));
        else if(wParam == WM_MBUTTONUP)
            result = QHook::instance()->mouseReleaseEvent(new QHookMouseEvent(QHookMouseEvent::Button, QHookMouseEvent::MiddleButton, QPoint(p->pt.x, p->pt.y), flags));

        if(wParam == WM_MOUSEMOVE)
            result = QHook::instance()->mouseMoveEvent(new QHookMouseEvent(QHookMouseEvent::Move, QHookMouseEvent::RightButton, QPoint(p->pt.x, p->pt.y), flags));

        if(wParam == WM_MOUSEWHEEL)
            result = QHook::instance()->mouseWheelEvent(new QHookWheelEvent((HIWORD(p->mouseData) > 0) ? QHookWheelEvent::Up : QHookWheelEvent::Down,
                                                                           HIWORD(p->mouseData), QPoint(p->pt.x, p->pt.y), flags));

        if(!result)
            return 1;
    }

    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

MouseHook::MouseHook()
{
    p_Hook = NULL;
    mouseHook = p_Hook;
}

bool MouseHook::isHooked(){ return (p_Hook == NULL) ? false : true; }

void MouseHook::hook()
{
    if(p_Hook == NULL)
        p_Hook = SetWindowsHookEx(WH_MOUSE_LL, mouseHookProc, NULL, 0);

    mouseHook = p_Hook;
}


void MouseHook::unhook()
{
    if(p_Hook != NULL)
        UnhookWindowsHookEx(p_Hook);

    p_Hook = NULL;
    mouseHook = p_Hook;
}


