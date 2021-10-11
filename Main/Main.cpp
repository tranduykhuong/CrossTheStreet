#include"Common_Function.h"
#include"CGAME.h"

#define SCREEN_WIDTH 1200 //pixel
#define SCREEN_HEIGHT 700 //pixel

int main()
{
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	FixConsoleWindow();
    SreenConsole_Top_Left();
    HiddenScrollBar();
    ShowCur(false);
    
    CGAME cg;
    CDRAW cd;
    cg.drawMenuGame();
    //cg.drawGame();
    
    //cd.printString("duy khuong", 0, 20, 5, 144);

    _getch();
}