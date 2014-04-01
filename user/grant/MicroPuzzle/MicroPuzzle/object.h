#pragma once
class object
{
private:
	std::string name;
	std::string description; //reads when the user types examine

public:
	object();
	object(std::string name, std::string description);
	std::string getName();
	std::string getDecription();
};