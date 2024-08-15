#include "Rooms.h"
#include <iostream>

// intialise constructor to ZERO
// constructor for rooms class 
Rooms::Rooms() : rooms(0) {}

int Rooms::getRoomsLeft() const{
	return rooms;
}

int Rooms::decrementRoom() {
	return rooms - 1 > 0 ? rooms - 1 : 0;
}

void Rooms::setRooms(int roomsArg) {
	rooms = roomsArg;
	// new line test
}
	