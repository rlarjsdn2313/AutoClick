#include <stdio.h>

// Packages for windows
#include <windows.h>
#include <winuser.h>

void clicking(int time);
void printing();

int main() {
    int time = 0;

    while (!GetAsyncKeyState(VK_F3)) {
        printing();

        printf("Input Time(1000 = 1s) : ");
        scanf("%d", &time);
        printf("Listening...\n");

        if (GetAsyncKeyState(VK_F1)) {
            clicking(time);
        }
    }


    printf("\nAutoClicker1.0 Shutting Down...\n");

    return 1;
}

void printing() {
    system("cls");
    printf("AutoClicker1.0\n");
    printf("===Description===\n");
    printf("1. F1 : Start Clicking\n");
    printf("2. F2 : Stop Clicking\n");
    printf("3. F3 : Exit AutoClicker1.0");
}

// time = 1000 1초
void clicking(int time) {
    POINT pt;
    while (1) {
        if (GetAsyncKeyState(VK_F2)) {
            return;
        }
        GetCursorPos(&pt);
        mouse_event(MOUSEEVENTF_LEFTDOWN, pt.x, pt.y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, pt.x, pt.y, 0, 0);
        Sleep(time);
    }
    return;
}