#include "main.h"
#include "rooms.h"

room::room(std::string Id, std::string Description, std::string Nn, std::string En, std::string Sn, std::string Wn, std::string ItemID,  std::string objectName, std::string objectDescription):
	id(Id),
	description(Description),
	itemId(ItemID),
	northNeighbor(Nn),
	eastNeighbor(En),
	southNeighbor(Sn),
	westNeighbor(Wn)
	{
		object tmpObject(objectName, objectDescription);
		object1 = tmpObject;
	}

room::room(std::string Id):
	id(Id)
{
	northNeighbor = "NULL";
	eastNeighbor = "NULL";
	southNeighbor = "NULL";
	westNeighbor = "NULL";
	itemId = "NULL";
}


void room::printRoom(std::string defualtMessage, std::string itemName)
{
	if (id != "NULL")
	{
		//print title and description
		std::cout << "MICRO PUZZLE" << std::endl;
		std::cout << "============" << std::endl;
		std::cout << description << std::endl;
		//print if there is something there HERE
		if(item1.getOwned())
		{
			std::cout << "THERE IS A " << item1.getName() << " HERE" << std::endl; 
		}
		else
		{
			std::cout << std::endl;
		}
		//print avaliable directions
		std::cout << "YOU CAN GO ";
		findDirections();
		std::cout << "------------------" << std::endl;
		std::cout << defualtMessage << std::endl;
	}
}

void room::findDirections()
{
	if(northNeighbor != "NULL")
	{
		std::cout << "N,";
	}
	if(eastNeighbor != "NULL")
	{
		std::cout << "E,";
	}
	if(southNeighbor != "NULL")
	{
		std::cout << "S,";
	}
	if(westNeighbor != "NULL")
	{
		std::cout << "W,";
	}
	std::cout << std::endl;
}

std::string room::getNeighbor(std::string direction)
{
	if(direction == "N")
	{
		return northNeighbor;
	}
	else
	{
		if(direction == "E")
		{
			return eastNeighbor;
		}
		else
		{
			if(direction == "S")
			{
				return southNeighbor;
			}
			else
			{
				if(direction == "W")
				{
					return westNeighbor;
				}
				else
				{
					return "NULL";
				}
			}
		}
	}
}

std::string room::getID()
{
	return id;
}

std::string room::getItemId()
{
	return itemId;
}

void room::addItem(std::string itemName)
{
	item tmpItem("NULL", itemName);
	item1 = tmpItem;
	item1.setOwned(true);
}
void room::removeItem()
{
	//itemId = "NULL";
	item1.setOwned(false);
}

