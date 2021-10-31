#include"CGAME.h"
#include<thread>

CGAME cg;
char MOVING;
bool isSound;
bool isMusic;

void runGame() {
    while (cg.isRunning()) {

        if (!cg.getPeople().isDead()) {
            cg.updatePosPeople(MOVING);
        }
        MOVING = ' ';

        cg.updatePosAnimal();
        cg.updatePosVehicle();
        cg.drawObjects(MOVING);

        Sleep(2);
    }
}

int main()
{

    CONSOLE::SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    CONSOLE::FixConsoleWindow();
    CONSOLE::SreenConsole_Top_Left();
    CONSOLE::HiddenScrollBar();
    CONSOLE::ShowCur(false);
    CONSOLE::SetConsoleOutput(437);
    CONSOLE::SetTitleCosole("CROSS THE STREET");

    CDRAW cd;
    //cd.drawLogo(COORD{ 47, 5 }, 15, 1500);
    cd.drawTitle(COORD{ 10, 4 }, 151);
    cg.runApp();
    //cd.drawGameOverScreen(COORD{ 17, 4 }, 151);

    
    /*cg.drawGame();
    cg.drawGuide();*/

   /* CHORSE h;
    h.set(5, 16, 112, 3, LEFT);
    CRABBIT r;
    r.set(5, 11, 114, 2, RIGHT);
    CCAR car;
    car.set(5, 1, 113, 1, 2, RIGHT);
    CTRUCK truck;
    truck.set(5, 6, 113, 4, 2, RIGHT);

    while (1) {
        car.move();
        car.draw();
        r.move();
        r.draw();
        h.move();
        h.draw();
        truck.move();
        truck.draw();
        Sleep(5);
    }*/

    cg.resetGame(4);
    char key;

    thread run(runGame);
    while (1) 
    {
        key = toupper(_getch());
        // Người còn sống
        if (!cg.getPeople().isDead()) {
            if (key == 27) {
                //xử lý exit
            }
            //.....
            else {
                if (cg.isRunning())
                    MOVING = key;
            }

        }
        // Người đã chết
        else {

        }
    }

    _getch();
}