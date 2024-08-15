#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "player.h"
#include "monster.h"
#include "Rooms.h"
#include <string>

void sysExit();

int main()
{
    char cquit;
    bool isExit = false;

    std::string name;
    std::cout << "============================================================\n";
    std::cout << "Hello World!\n";
    std::cout << "What is your name user?\n" << '\n';

    std::cin >> name;
    std::cout << "\nHi, " << name << '\n';

    // Enter your selected character 'f' or 'g'
    char optionEntered;
    std::cout << "Select your character [enter 'f' for fox and 'g' for goblin]\n";
    std::cin >> optionEntered;

    // Clear the newline character from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n============================================================";

    // Determine and print the chosen character
    std::cout << "\nYou have chosen "
        << ((optionEntered == 'f' || optionEntered == 'F') ? "fox " : "goblin ");


    // Game Code
    std::srand(std::time(0));
    Monster monstr(150);
    Player plyr;


    bool isGameStarted = false;
    
    std::cout << "and your monster has " << monstr.getHp() << " HP" << '\n';
    std::cout << "============================================================" << '\n';

    while (!isGameStarted) {

        // ignores anything until it encounters a '\n'
        std::cout << "Press 'Enter' to attack the monster...\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        // Attack Prompt
        int damage = plyr.attack();
        std::cout << "You attack the monster for " << damage << " damage." << '\n';

        // Monster takes damage
        monstr.takeDamage(damage);

        // Check if the monster is still alive
        if (monstr.isMonsterAlive()) {
            std::cout << "Monster has " << monstr.getHp() << " HP remaining.\n\n";
        }

        // when monster dies: [1. playagain, 2. enter rooms, 3. quit]
        else {
            std::cout << "Monster has died :(\n";
            std::cout << "You have defeated the monster!\n\n";

            std::cout << "Press 'p + Enter' to play again or Press 'c' to enter remaining rooms or 'Enter' to quit...\n";
            cquit = std::cin.get();

            if (cquit == 'p' || cquit == 'P') {
                monstr.setHp(150);
                std::cout << "A new monster appears with " << monstr.getHp() << " HP!\n\n";

            }
            else if (cquit == 'c' || cquit == 'C') {
                int roomAmount = std::rand() % 5 + 1; // num between 0 to 6
                std::cout << "Entering Rooms..." << '\n';
                std::cout << "There are " << roomAmount << " rooms!" << '\n';

                std::this_thread::sleep_for(std::chrono::seconds(2));
                // system("cls");

                Rooms rooms;
                std::cout << "Debug: About to enter room game" << std::endl;
                rooms.enterRoomGame();
                std::cout << "Debug: Finished room game" << std::endl;

                std::cout << "Press Enter to exit...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // isGameStarted = true;
            }
            else {
                std::cout << "Exiting application.\n";

                // Countdown loop from 5 to 1
                for (int i = 5; i > 0; --i) {
                    std::cout << i << " seconds remaining\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }


            }
        }
    }
   
    
   

  



    return 0; // Exit the program
}




