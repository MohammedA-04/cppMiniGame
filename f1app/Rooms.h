#ifndef ROOMS_H
#define ROOMS_H


class Rooms
{
	public:
		Rooms();
	
		int getRoomsLeft() const;
		int decrementRoom();
		void setRooms(int roomsArg);

	private:
		int rooms;
};


#endif 