#include"Common_Function.h"
#include"CGAME.h"

int main()
{
    CONSOLE::SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    CONSOLE::FixConsoleWindow();
    CONSOLE::SreenConsole_Top_Left();
    CONSOLE::HiddenScrollBar();
    CONSOLE::ShowCur(false);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    //SetConsoleTitleA("Game CROSS THE STREET");
    system("color 7a");
    
    CGAME cg;
    CDRAW cd;
    cg.runApp();
    //cg.drawGame();
    //cg.drawGuide();

   /* int cl = TEXT_BOX_GAME_COLOR;
    cd.backroundBox(4, 5, 4, 5, cl);*/

    /*for (int i = 0; i < 256; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << "color " << i << "   ";
        if (i % 10 == 0)cout << endl;
    }*/
    /*for (int i = 100; i < 256; i++) {
        wcout << i << ": " << char(i) << "\t";
        if (i % 10 == 0) cout << endl;
    }*/

    //cd.printString("duy khuong", 0, 20, 5, 144);

    _getch();
}
