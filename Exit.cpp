#include "Exit.h"

Path Exit::GetPath() const 
{
	return direction;
}

Room* Exit::GetHome() const 
{
	return home;
}

Room* Exit::GetDestination() const 
{
	return destination;
}

Item* Exit::ExitKey()
{
	return key;
}
void Exit::SetExit(bool status) 
{
	locked = status;
}

bool Exit::IsLocked() const 
{
	return locked;
}
