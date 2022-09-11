#pragma once
#include "Global.h"
#include "Room.h"

class Exit : public Entity 
{

public:
	Exit(string in_name, string in_description, Path in_direction, Room* in_source, Room* in_destination, bool in_locked=false, Item* in_key = nullptr) 
		: Entity(EntityType::EXIT, in_name, in_description) 
	{
		direction = in_direction;
		home = in_source;
		destination = in_destination;
		key = in_key;
		locked = in_locked;
	}

	Path GetPath() const;
	Room* GetHome() const;
	Room* GetDestination() const;
	Item* ExitKey();
	void SetExit(bool status);
	bool IsLocked() const;

private:
	Path direction;
	Item* key;
	Room* home;
	Room* destination;
	bool locked;
};
