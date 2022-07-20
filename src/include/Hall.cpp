#include "include/Hall.hpp"

const float Hall::MIN_WIDTH(416);  //32*13
const float Hall::MIN_HEIGHT(320); //32*10

Hall::Hall()
{
}

Hall::~Hall()
{
}

float Hall::getMIN_WIDTH()
{
	return MIN_WIDTH;
}

float Hall::getMIN_HEIGHT()
{
	return MIN_HEIGHT;
}
