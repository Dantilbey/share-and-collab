#include "object.h"
#include "items.h"
class room
{
private:
	std::string id;
	std::string description;
	std::string itemId;


	//neighbor room ids
	std::string northNeighbor;
	std::string eastNeighbor;
	std::string southNeighbor;
	std::string westNeighbor;

public:
	//object in room
	object object1;

	//item in room
	item item1;

	//methods
	room(std::string Id = "NULL");
	room(std::string Id, std::string description = "-NO DESCRIPTION-", std::string nn = "NULL", std::string en = "NULL", std::string sn = "NULL", std::string wn = "NULL", std::string itemID = "NULL", std::string objectName = "NULL", std::string objectDescription = "NULL");
	void printRoom(std::string defualtMessage = "-NO MESSAGE-", std::string itemName = "NULL"); // print description and any items in the room
	void findDirections(); // print the avaliable directions
	std::string getNeighbor(std::string direction);
	std::string getID();
	std::string getItemId();
	void addItem(std::string itemName);
	void removeItem();
};