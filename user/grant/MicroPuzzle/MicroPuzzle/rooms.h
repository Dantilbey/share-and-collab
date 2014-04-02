#include "object.h"
#include "items.h"
class room
{
private:
	std::string id;
	std::string description;


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
	//defualt constructor
	room(std::string Id = "NULL");
	
	//constructor
	room(std::string Id, std::string description = "-NO DESCRIPTION-", std::string nn = "NULL", std::string en = "NULL", std::string sn = "NULL", std::string wn = "NULL", std::string objectName = "NULL", std::string objectDescription = "NULL");
	
	//print the room and item if it contains one
	void printRoom(std::string defualtMessage = "-NO MESSAGE-", std::string itemName = "NULL"); // print description and any items in the room
	
	 // print the avaliable directions
	void findDirections();
	
	//get the neighbor of the room based on which direction the user has chosen
	std::string getNeighbor(std::string direction, std::string word2 = "NULL");
	
	//return the unique id of the room
	std::string getID();

	//add an item to the room
	void addItem(std::string itemName);
	
	//remove the current item from the room
	void removeItem();
};