#pragma once
class item
{
private:
//tring roomId;
	std::string name;
	bool owned;
	bool consumable;
	std::string roomId;

public:
	//defualt constructor
	item();
	
	//constructor
	item(std::string Id, std::string Name = "NULL", bool consumeable = false);
	
	//return the unique roomId that this item belongs
	std::string getRoomId();
	
	//return the name of the item
	std::string getName();
	
	//set if the item is currently owned
	void setOwned(bool Owned);
	
	//return whether or not the item is owned, if this is being called from a method within room
	//then it is testing if the item is currently in the room
	bool getOwned();
	
	//print the item if it is owned (used for the inventory)
	void printIfOwned();
	
	//consume the item
	void consume();

};