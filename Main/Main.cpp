#include"CGAME.h"
#include<thread>

CGAME cg;
char MOVING;
bool isSound;
bool isMusic;

void runGame() {
    while (cg.isRunning()) {

        // Update tọa độ people khi còn sống
        if (!cg.getPeople().isDead()) {
            cg.updatePosPeople(MOVING);
        }
        MOVING = ' ';

        // Update các đối tượng Vehicles, Animals
        cg.updatePosAnimal();
        cg.updatePosVehicle();
        // Draw các đối tượng ra screen
        cg.drawObjects(MOVING);

        // Xử lý va chạm
        if (cg.getPeople().isImpact(cg.getTruckLefts(), cg.getNumOfTructs()) ||
            cg.getPeople().isImpact(cg.getTruckRights(), cg.getNumOfTructs()) ||
            cg.getPeople().isImpact(cg.getCarLefts(), cg.getNumOfCars()) ||
            cg.getPeople().isImpact(cg.getCarRights(), cg.getNumOfCars()) ||
            cg.getPeople().isImpact(cg.getHorses(), cg.getNumOfHorses()) ||
            cg.getPeople().isImpact(cg.getRabbits(), cg.getNumOfRabbits()))
        {
            CONSOLE::gotoXY(sRIGHT - 10, 8);
            cout << "THUA";
        }

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
    //cd.drawTitle(COORD{ 10, 4 }, 151);
    //cg.runApp();
    //cd.drawGameOverScreen(COORD{ 17, 4 }, 151);

    cg.drawGame();
    cg.drawGuide();

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