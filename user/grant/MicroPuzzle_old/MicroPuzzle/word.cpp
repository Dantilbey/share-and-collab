#include "main.h"
#include "word.h"

//word::word()
//{
//}

word::word(std::string Name):
	name(Name)
{
}

std::string word::getName()
{
	return name;
}