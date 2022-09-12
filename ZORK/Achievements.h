#pragma once
#include "Global.h"
#include "Entity.h"
#include "Room.h"


class Achievement : public Entity
{

public:
	 Achievement(string in_name, string in_description, bool in_show = false)
		 : Entity(EntityType::ACHIEVEMENT, in_name, in_description)
	{
		show = in_show;
	}

	void SetShow(bool status);
	bool IsShowed() const;

private:
	bool show;
};

