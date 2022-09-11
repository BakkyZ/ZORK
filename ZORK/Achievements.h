#pragma once
#include "Global.h"
#include "Entity.h"


class Achievement : public Entity
{

public:
	 Achievement(string in_name, string in_description, Path in_path, bool in_show = false)
		 : Entity(EntityType::MENU, name, description)
	{
		path = in_path;
		show = in_show;
	}

	Path GetPath() const;
	void SetShow(bool status);
	bool IsShowed() const;

private:
	Path path;
	bool show;
};

