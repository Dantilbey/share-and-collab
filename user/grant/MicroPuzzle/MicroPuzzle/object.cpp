#include "main.h"
#include "object.h"

object::object()
{
}

object::object(std::string Name, std::string Description):
	description(Description),
	name(Name)
{
}


std::string object::getName()
{
	return name;
}

std::string object::getDecription()
{
	return description;
}
