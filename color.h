#include <windows.h>
#include <iostream>


VOID WINAPI SetConsoleColors(WORD attribs);


int color() {
	SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    return 10;
}


VOID WINAPI SetConsoleColors(WORD attribs) {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFOEX cbi;
    cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hOutput, &cbi);
    cbi.wAttributes = attribs;
    SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}
