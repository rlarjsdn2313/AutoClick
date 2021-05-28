#include <stdio.h>

// Packages for windows
#include <windows.h>
#include <winuser.h>

int main() {
    printf("Click!\n");
    POINT pt;
    while (1) {
        if (GetAsyncKeyState(VK_F1)) {
            GetCursorPos(&pt);
            mouse_event(MOUSEEVENTF_LEFTDOWN, pt.x, pt.y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, pt.x, pt.y, 0, 0);
            break;
        }
    }



    return 1;
}