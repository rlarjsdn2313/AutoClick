#include <stdio.h>

// Packages for windows
#include <windows.h>
#include <winuser.h>

void printing(int time);
int click(int time);


int main() {
    int time = 0;
    int check = 1;

    while (check != 0 && !GetAsyncKeyState(VK_F3)) {
        if (check == 1) {
            printing(time);
            check = -1;
        } 

        if (GetAsyncKeyState(VK_F5)) {
            printf("Input Time(1000 = 1s) : ");
            scanf("%d", &time);
            check = 1;
        }


        if (GetAsyncKeyState(VK_F1)) {
            check = click(time);
        }
    }


    printf("\nAutoClicker1.0 Shutting Down...\n");

    return 1;
}

int click(int time) {
    POINT pt;
    while (1) {
        if (GetAsyncKeyState(VK_F3)) {
            return 0;
        } else if (GetAsyncKeyState(VK_F4)) {
            return 1;
        } else {
            GetCursorPos(&pt);
            mouse_event(MOUSEEVENTF_LEFTDOWN, pt.x, pt.y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, pt.x, pt.y, 0, 0);
            Sleep(time);
        }
    }
}

void printing(int time) {
    system("cls");
    printf("AutoClicker1.0\n");
    printf("===Description===\n");
    printf("1. F1 : Start Clicking(%dms)\n", time);
    printf("2. F4 : Stop Clicking\n");
    printf("3. F5 : Set time\n");
    printf("4. F3 : Exit AutoClicker1.0\n");

}

