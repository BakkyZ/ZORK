#pragma once
#include "Global.h"

enum EntityType { PLAYER, EXIT, ROOM, ITEM, ENEMY, MENU };

class Entity
{

public:
	explicit Entity(EntityType type, string name, string description);
	virtual ~Entity();

	string GetName() const;
	string GetDescription() const;
	EntityType GetType() const;
	Entity* GetParent() const;
	void SetParent(Entity* parent);

	virtual void Look();
	void Insert(Entity* entity);
	void Remove(Entity* entity);
	int Show(list<Entity*>& entities, EntityType type);

	list<Entity*> content;
	Entity* parent;

	bool operator == (const Entity& e) const
	{
		return type == e.type && name == e.name;
	}
	bool operator != (const Entity& e) const
	{
		return !operator==(e);
	}

protected:
	EntityType type;
	string name;
	string description;
};