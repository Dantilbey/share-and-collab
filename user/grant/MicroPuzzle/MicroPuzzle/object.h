#pragma once
class object
{
private:
	std::string name;
	std::string description; //reads when the user types examine

public:
	//defualt constructor
	object();
	//constructor
	object(std::string name, std::string description);
	//return the name of the object
	std::string getName();
	//return the description of the object
	std::string getDecription();
};