#include "main.h"
#include "rooms.h"
#include "items.h"
#include "word.h"

//MAGIC NUMBERS
int const NUMOFROOMS = 19;
int const NUMOFITEMS = 15;
int const NUMOFVERBS = 12;

void gameStart();

void loadData();
//loads in all of data for the rooms from file
void loadRooms(int roomArrayNum);

//load in items from file
void loadItems(int itemArrayNum);

//finding the room array number from the id
int roomLookup(std::string roomId);

//finding the item array number from the name
int itemLookup(std::string itemName);

//list<room> rooms;
//rooms
room rooms[NUMOFROOMS];

//items
item items[NUMOFITEMS];

//verbs
word verbs[NUMOFVERBS];

//test if the first word is a verb
bool testForVerb(std::string choice);

//validate the input
bool validateInput(std::string choice);

//deal with input if the first word was a verb
std::string verb(int currentRoom);

//functions for actions
std::string take(int currentRoom);
std::string eat(int currentRoom);
std::string examine(int currentRoom);

//strings for seperating words
std::string word1 = "";
std::string word2 = "";
	
std::ifstream file;


//inventory
void inventory();

//starting room
std::string startingRoom = "001";

int main()
{
	loadData();
	gameStart();
	//for(int i = 0; i < NUMOFROOMS; i++)
	//{
	//	rooms[i].printRoom();
	//}

	char f;
	std::cin >> f;
	return 0;
}


void loadData()
{
	//ROOM ID'S START AT 001, AND ITEM ID'S START AT 101
	//n, e, s, w ROOMS
		
	
	//LOAD ROOMS FROM FILE
	file.open("rooms.txt");
	for(int i = 0; i<NUMOFROOMS; i++)
	{
		if(!file.eof())
		{
			loadRooms(i);
		}
		else
		{
			break;
		}
	}
	file.close();


	//LOAD VERBS
	word verb1("TAKE");
	verbs[0] = verb1;

	word verb2("EAT");
	verbs[1] = verb2;

	word verb3("EXAMINE");
	verbs[2] = verb3;

	//LOAD ITEMS
	file.open("items.txt");
	std::string tmpId;
	for(int i = 0; i<NUMOFITEMS; i++)
	{
		if(!file.eof())
		{
			loadItems(i);

			//put the item into the correct room
			rooms[roomLookup(items[i].getRoomId())].addItem(items[i].getName());

		}
		else
		{
			break;
		}
	}
	file.close();
	
}

void loadItems(int itemArrayNum)
{
	//create strings to hold data temporarily
	std::string data[2];
	
	//load data from file
	for(int i = 0; i<2;i++)
	{
		data[i] == "NULL";
		getline(file, data[i]);
		if(data[i] == ".")
		{
			data[i] = "NULL";
			break;
		}
	}
	//create temporary room to hold data
	item tmpItem(data[0], data[1]);
	items[itemArrayNum] = tmpItem;

	std::string ignore;
	getline(file, ignore);
}

void loadRooms(int roomArrayNum)
{
	//create strings to hold data temporarily
	std::string data[9];
	
	//load data from file
	for(int i = 0; i<9;i++)
	{
		data[i] = "NULL";
		getline(file, data[i]);
		if(data[i] == ".")
		{
			for(int x = i; x < 9;x++)
			{
				data[x] = "NULL";
			}
			break;
		}
	}
	//create temporary room to hold data
	room tmpRoom(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
	rooms[roomArrayNum] = tmpRoom;

	std::string ignore;
	getline(file, ignore);
}

void gameStart()
{

	//store id of current room
	std::string currentRoomId;
	//store the array number of the current room
	int currentRoom;
	//set the starting room
	currentRoomId = startingRoom;

	//setup variables to hold both words
	std::string choice;


	//used to hold the id of the new room so that it can be evaluated
	std::string newRoom;

	//defualt message
	std::string defualt = "YOU AWAKEN..";

	while(true)
	{
		//clear the screen
		system("CLS");

		//retrieve the id of the current room
		currentRoom = roomLookup(currentRoomId);
		
		//print room
		rooms[currentRoom].printRoom(defualt);

		

		std::cout << "WHAT WILL YOU DO NOW \n?";
		//resets the string
		choice = "";

		//gets a line of input
		std::getline(std::cin, choice);

		if(choice != "")
		{
			//validate input
			if(!validateInput(choice))
			{
				defualt = "YOU DO NOT MAKE SENSE";
			}
			else
			{
				//test for room move
				if(choice == "N" || choice == "E" || choice == "S" || choice == "W")
				{
					//retrieves the neighboring room id, if the id is "NULL" then there is no neighbor avalialbe
					newRoom = rooms[currentRoom].getNeighbor(choice);
					if(newRoom != "NULL")
					{
						currentRoomId = newRoom;
						defualt = "OK";
					}
					else
					{
						defualt = "YOU CANNOT GO THAT WAY";
					}
				}
				else
				{
					//check for inventory
					if(choice == "I")
					{
						inventory();
					}
					else
					{
						//test for verbs and actions
						if(testForVerb(choice))
						{
							defualt = verb(currentRoom);
						}
						else
						{
							defualt = "YOU DO NOT MAKE SENSE";
						}
					}
				}
			}
		}
		else
		{
			defualt = "YOU CANNOT GO THAT WAY";
		}
		//std::cin.clear();
		//char f;
		//scin >> f;
	}
}

bool validateInput(std::string choice)
{
	//sets the valid characters
	std::string validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

	//loops through each character and returns false is any are not valid
	for(int i = 0;i<choice.length(); i++)
	{
		bool valid = false;
		for(int x = 0; x<validChars.length() ;x++)
		{
			if(choice[i] == validChars[x])
			{
				valid = true;
				break;
			}
		}
		if(!valid)
		{
			return false;
		}
	}
	return true;
}

bool testForVerb(std::string choice)
{
	word1 = "";
	word2 = "";
	//devide the string into two words
	for(int i = 0; i<choice.length(); i++)
	{
		if(choice[i] != ' ')
		{
			word1 += choice[i];
		}
		else
		{
			for(int x = i+1;x<choice.length();x++)
			{
				word2 += choice[x];
			}
			break;
		}
	}

	//test for a verb
	for(int i = 0; i < NUMOFVERBS; i++)
	{
		if(word1 == verbs[i].getName())
		{
			return true;
		}
	}
	return false;
}

std::string verb(int currentRoom)
{
	//test for the word take and call the appropriate function
	if(word1 == "TAKE")
	{
		if (word2 != "")
		{
			return take(currentRoom);
		}
		else
		{
			return "IT IS NOT HERE";
		}
	}
	else if(word1 == "EAT")
	{
		if(word2 != "")
		{
			return eat(currentRoom);
		}
		else
		{
			return "I NEED TWO WORDS";
		}
	}
	else if(word1 == "EXAMINE")
	{
		if(word2 != "")
		{
			return examine(currentRoom);
		}
		else
		{
			return "NOTHING OF INTEREST";
		}
	}
	else 
	{
		return "YOU DO NOT MAKE SENSE";
	}
}

std::string examine(int currentRoom)
{
	if(rooms[currentRoom].object1.getName() == word2)
	{
		return rooms[currentRoom].object1.getDecription();
	}
	else
	{
		return "NOTHING OF INTEREST";
	}
}

std::string take(int currentRoom)
{
	int arrayNum;
	//if there is an item in the room and the second word that the user entered the name of the item, then take it
	if(rooms[currentRoom].item1.getOwned() == true && rooms[currentRoom].item1.getName() == word2)
	{
		//remove the item from the room
		rooms[currentRoom].removeItem();

		//give the item to the player
		arrayNum = itemLookup(rooms[currentRoom].item1.getName());
		items[arrayNum].setOwned(true);

		//set the defualt message
		return "YOU HAVE THE "+items[arrayNum].getName();
	}
	else
	{
		return "IT IS NOT HERE";
	}
}

std::string eat(int currentRoom)
{
	//if the player has the item and they typed the name
	for(int i = 0; i< NUMOFITEMS; i++)
	{
		if("CHEESE" == items[i].getName() && word2 == "CHEESE" && items[i].getOwned() == true)
		{
			items[i].consume();
			return "MUNCH CHOMP";
		}
	}
	return "YOU DO NOT HAVE " + word2 + " ";
}

void inventory()
{
	//print the inventory
	std::cout << "YOU ARE CARRYING:" << std::endl;
	for(int i = 0;i<NUMOFITEMS;i++)
	{
		items[i].printIfOwned();
	}
	std::cout << std::endl;
	std::cout << "PRESS RETURN TO CONTINUE" <<std:: endl;
	std::cout << "?";

	std::string f;
	std::getline(std::cin, f);
}

//look up a room array number
int roomLookup(std::string roomId)
{
	for(int i = 0; i< NUMOFROOMS; i++)
	{
		if(roomId == rooms[i].getID())
		{
			return i;
		}
	}
	return 99;
}

int itemLookup(std::string itemName)
{
	// if the id is null then the item does not exist and does not need to be look up
	if (itemName == "NULL")
	{
		return 99;
	}

	//look up the item using the id and returning the array number that it is stored under
	for(int i = 0; i< NUMOFITEMS; i++)
	{
		if(itemName == items[i].getName())
		{
			return i;
		}
	}
	return 99;
}
