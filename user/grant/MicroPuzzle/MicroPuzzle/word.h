class word
{
private:
	std::string name;

public:
	//defualt constructor
	word(std::string Name = "NULL");
	
	//return the name of the word
	std::string getName();
};