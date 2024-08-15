#include "Rooms.h"
#include "player.h"
#include "monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// intialise constructor to ZERO
// constructor for rooms class 
Rooms::Rooms() : rooms(0) {
	// AI helped: using seed for std::rand so each time algo takes new seed based on time to give random num
	/// otherwise the std::rand will apparenlty produce the same pattern of random numbers
	std::srand(static_cast<unsigned>(std::time(0)));
}

int Rooms::getRoomsLeft() const{
	return rooms;
}

void Rooms::decrementRoom() {
	if (rooms > 0) {
		rooms--;
	}
}

void Rooms::setRandomRooms() {
	rooms = std::rand() % 5 + 1; // Gen num between 1 and 5
}

// reutrns val between 200-1
int Rooms::genRandomHp() {
	return std::rand() % 200 + 1; 
}

// Perform Game Ops
void Rooms::enterRoomGame() {

	// setup env variables
	setRandomRooms();

	// if rooms are 1 to 5
	if (rooms <= 5 && rooms > 0) {

		// loop until rooms is 0
		while (getRoomsLeft() > 0) {

			std::cout << "Entering Room " << getRoomsLeft() << "... \n";
			Player player1;
			Monster monster1(genRandomHp());

			while (monster1.isMonsterAlive()) {

				std::cout << "Press 'Enter' to attack the monster...\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				int damage = player1.attack();
				std::cout << "You attack the monster for " << damage << " damage." << '\n';

				monster1.takeDamage(damage);


				if (monster1.isMonsterAlive()) {
					std::cout << "Monster has " << monster1.getHp() << " HP remaining.\n\n";
				}
				else {
					std::cout << "Monster has died :(\n";
					std::cout << "You have defeated the monster!\n\n";
					decrementRoom();

					std::cout << "Remaining Rooms: " << getRoomsLeft() << '\n';
				}
			}
		}

		std::cout << "\033[32mYou have successfully defeated all rooms, well done!\033[0m" << std::endl;

	}
	else {
		// throw std::invalid_argument("rooms value must be between 1 and 5, it's currently: " + std::to_string(rooms));
	}
		
	
	
	
	


}
	