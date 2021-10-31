#include"CONSOLE.h"
#include"CGAME.h"
#include"CPEOPLE.h"
#include"CVEHICLE.h"
#include"CCAR.h"
#include"CTRUCK.h"

int main()
{
    CONSOLE::SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    CONSOLE::FixConsoleWindow();
    CONSOLE::SreenConsole_Top_Left();
    CONSOLE::HiddenScrollBar();
    CONSOLE::ShowCur(false);
    CONSOLE::SetConsoleOutput(437);
    CONSOLE::SetTitleCosole("CROSS THE STREET");
    //system("color 7a");

    CGAME cg;
    CDRAW cd;

    cd.drawLogo(COORD{ 47, 5 }, 15, 1500);
    cd.drawTitle(COORD{ 10, 4 }, 151);
    //cd.drawGameOverScreen(COORD{ 17, 4 }, 151);

    cg.runApp();
    //cg.drawGame();
    //cg.drawGuide();

    /*CPEOPLE cn;
    cn.draw(LEFT);*/

    CTRUCK a;

    //a.set(-18, 1, ColorGame::black, 30, 1, RIGHT);    //hàm input: tọa độ X, tọa độ Y, màu, tốc độ
    //a.move();                    

    //a.set(sRIGHT, 1, ColorGame::black, 30);
    //a.move();

    /*CTRUCK b;

    b.set(-18, 1, ColorGame::black, 30);
    b.moveTruck(1, RIGHT);

    b.set(sRIGHT, 1, ColorGame::black, 30);
    b.moveTruck(1, LEFT);*/

    /*CPEOPLE *cp = new CPEOPLE;
    cp->draw(Key::LEFT);*/

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
