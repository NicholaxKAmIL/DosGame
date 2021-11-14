#include <windows.h>
#include <iostream>


void color2(int cntFlashes, int flashInterval_ms, COLORREF color){

    {

        CONSOLE_SCREEN_BUFFER_INFOEX sbInfoEx;
        sbInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

        HANDLE consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfoEx(consoleOut, &sbInfoEx);

        COLORREF storedBG = sbInfoEx.ColorTable[0];

        for (int i = 0; i < cntFlashes; ++i)
        {
            //-- set BG color
            Sleep(flashInterval_ms);
            sbInfoEx.ColorTable[0] = color;
            SetConsoleScreenBufferInfoEx(consoleOut, &sbInfoEx);

            //-- restore previous color
            Sleep(flashInterval_ms);
            sbInfoEx.ColorTable[0] = storedBG;
            SetConsoleScreenBufferInfoEx(consoleOut, &sbInfoEx);
        }
    }

    int color3(){
        printf("Flashing console BG: RED");
        FlashConsoleBackgroundColor(20, 50, RGB(255, 0, 0));

        printf("\rFlashing console BG: ORANGE\n");
        FlashConsoleBackgroundColor(10, 100, RGB(255, 105, 0));

        return 0;
    }
}
