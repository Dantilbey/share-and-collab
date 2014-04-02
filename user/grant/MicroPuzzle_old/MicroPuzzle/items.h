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
	item();
	item(std::string Id, std::string Name = "NULL", bool consumeable = false);
	std::string getRoomId();
	std::string getName();
	void setOwned(bool Owned);
	bool getOwned();
	void printIfOwned();
	void consume();

};