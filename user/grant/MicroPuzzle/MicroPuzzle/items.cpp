#include "main.h"
#include "items.h"


item::item()
{
	owned = false;
	name = "NULL";
}

item::item(std::string RoomId, std::string Name, bool consumeable):
	roomId(RoomId),
	name(Name)
{
	owned = false;
}

std::string item::getRoomId()
{
	return roomId;
}

std::string item::getName()
{
	return name;
}

void item::setOwned(bool Owned)
{
	owned = Owned;
}

bool item::getOwned()
{
	return owned;
}

void item::printIfOwned()
{
	if(owned)
	{
		std::cout << name << ", ";
	}
}

void item::consume()
{
	owned = false;
}
