#include"Common_Function.h"

// Function to fixed screen
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Function to set Width and Height of Console Screen
void SetWindowSize(SHORT width, SHORT height) {
    RECT rect;
    HWND console = GetConsoleWindow();
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, width, height, TRUE);
}

// Function to set screen console in the upper left corner of laptop screen
void SreenConsole_Top_Left() {
    HWND console = GetConsoleWindow();
    SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

// Function to hidden the scrollbar
void HiddenScrollBar() {
    HANDLE handleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
    GetConsoleScreenBufferInfo(handleOut, &screenBuffer);

    COORD newSize;
    newSize.X = screenBuffer.srWindow.Right - screenBuffer.srWindow.Left + 1;
    newSize.Y = screenBuffer.srWindow.Bottom - screenBuffer.srWindow.Top + 1;

    SetConsoleScreenBufferSize(handleOut, newSize);
}

// Function that moving cursor pointer to xy-coordinate
void gotoXY(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to show or hidden Cursor pointer
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}

// Function to set color for character
void textcolor(int x) {
    HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}