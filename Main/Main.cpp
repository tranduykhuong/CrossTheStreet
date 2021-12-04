#include"CGAME.h"

CGAME cg;
char MOVING;
bool isExit = false;

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
            cg.getPeople().isImpact(cg.getTrain(), cg.getNumOfTrains()) ||
            cg.getPeople().isImpact(cg.getHorses(), cg.getNumOfHorses()) ||
            cg.getPeople().isImpact(cg.getRabbits(), cg.getNumOfRabbits()))
        {
            cg.getPeople().setState(false);
            cg.pauseGame();
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

   if (cg.runApp() == false)
        return 0;
    system("cls");
    if (cg.getNumOfCars() == 0)
        cg.resetGame();
    cg.drawGame();
    cg.startMusic();

    char key;

    thread run(runGame);

    while (1) 
    {
        if (cg.isRunning())
            key = toupper(_getch());
        else key = ' ';

        // Người còn sống
        if (!cg.getPeople().isDead()) {
            
            // Press ESC
            if (key == 27) {
                cg.pauseGame(&run);
                cg.MusicStatus(false);
                Sleep(500);

                isExit = cg.ESC();
                if (!isExit) {
                    cg.MusicStatus(true);
                    Sleep(300);
                    system("cls");
                    cg.drawGame();
                    cg.resumeGame(runGame, &run);
                }
                else {
                    cg.Exit_game();
                    return 0;
                }
            }
            
            // exit
            else if (isExit) {
                cg.Exit_game();
                return 0;
            }
            
            // pause
            else if (key == 'P') {
                int choice;
                cg.MusicStatus(false);
                cg.pauseGame(&run);
                Sleep(500);

                CMENU pauseForm = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, cg.getSound());
                pauseForm.addItem("Resume");
                pauseForm.addItem("Quit");
                pauseForm.displayTableLine();
                choice = pauseForm.getSelectFromUser();

                if (choice == 0) {
                    cg.MusicStatus(true);
                    Sleep(300);
                    system("cls");
                    cg.drawGame();
                    cg.resumeGame(runGame, &run);
                }
                else {
                    cg.Exit_game();
                    return 0;
                }
            }

            // Settings
            else if (key == 'U') {
                cg.pauseGame(&run);
                cg.Settings();

                system("cls");
                Sleep(300);
                cg.drawGame();
                cg.resumeGame(runGame, &run);
            }
            
            // xử lý Save_game
            else if (key == 'L') {
                int choice;
                cg.MusicStatus(false);
                cg.pauseGame(&run);
                Sleep(500);
                cg.Save_game();
                CMENU saveFormComplete = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, cg.getSound());
                saveFormComplete.addItem("Save complete");
                saveFormComplete.displayTableNoneLine();
                Sleep(1500);

                saveFormComplete.removeItem(0);
                saveFormComplete.addItem("Continue");
                saveFormComplete.addItem("Back to menu");
                saveFormComplete.addItem("Quit");
                saveFormComplete.displayTableLine();

                choice = saveFormComplete.getSelectFromUser();

                if (choice == 0) {
                    cg.MusicStatus(true);
                    Sleep(300);
                    system("cls");
                    cg.drawGame();
                    cg.resumeGame(runGame, &run);
                }
                else if (choice == 1) {
                    system("cls");
                    cg.runApp(false);
                }
                else {
                    cg.Exit_game();
                    return 0;
                }
            }
            
            // xử lý Load_game
            else if (key == 'T') {

                cg.MusicStatus(false);
                cg.pauseGame(&run);
                Sleep(500);

                bool checkFile = true; string str;
                cg.Load_game(checkFile, str);

                while (!checkFile)
                {
                    CMENU loadForm = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, cg.getSound());
                    loadForm.addItem("Wrong filename!!!");
                    loadForm.addItem("\"Cancel\": to resume");
                    loadForm.displayTableLine();
                    cg.Load_game(checkFile, str);
                    if (str == "Cancel") break;
                }
                system("cls");
                Sleep(300);
                cg.MusicStatus(true);
                cg.drawGame();
                cg.resumeGame(runGame, &run);

            }

            // Di chuyển người
            else {
                if (cg.isRunning())
                    MOVING = key;
            }

        }

        // Khi người chết
        if (cg.getPeople().isDead() || !cg.isRunning()) {
            mciSendString(TEXT("close mp3"), NULL, 0, NULL);

            cg.pauseGame(&run);
            Sleep(500);
            isExit = cg.Game_over();

            if (!isExit) {
                cg.startMusic();
                system("cls");
                Sleep(300);
                cg.drawGame();
                cg.resumeGame(runGame, &run);
            }
        }

        // Khi người qua được đường
        else if (cg.getPeople().isWin()) {
            mciSendString(TEXT("close mp3"), NULL, 0, NULL);

            cg.pauseGame(&run);
            Sleep(200);
            isExit = cg.Win_nextLevel();

            if (!isExit) {
                cg.startMusic();
                system("cls");
                Sleep(300);
                cg.drawGame();
                cg.resumeGame(runGame, &run);
            }
        }
    }
}