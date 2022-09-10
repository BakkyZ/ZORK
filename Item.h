#pragma once
#include "Entity.h"

enum ItemType { DEF, KEY, WEAPON, ACHIVEMENT };

class Item : public Entity 
{

public:
	Item(string name, string description, ItemType itemType = ItemType::DEF) 
		: Entity(EntityType::ITEM, name, description)
	{
		this->itemType = itemType;
	}

	ItemType GetItemType() const;

private:
	ItemType itemType;
};
