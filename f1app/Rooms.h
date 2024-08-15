#ifndef ROOMS_H
#define ROOMS_H


class Rooms
{
	public:
		Rooms();
	
		int getRoomsLeft() const;
		void decrementRoom();
		void setRandomRooms();
		int genRandomHp();
		void enterRoomGame();

	private:
		int rooms;
};


#endif 