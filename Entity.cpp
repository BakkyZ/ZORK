#include "Entity.h"

Entity::Entity(EntityType type, string name, string description)
{
	this->type = type;
	this->name = name;
	this->description = description;
	this->parent = nullptr;
}

Entity::~Entity() 
{
	if (parent != nullptr)
	{
		delete parent;
	}
	for (Entity* x : content) 
	{
		if (x != nullptr)
		{
			delete x;
			x = nullptr;
		}
			
	}
	content.clear();
}

string Entity::GetName() const 
{
	return name;
}

string Entity::GetDescription() const 
{
	return description;
}

EntityType Entity::GetType() const 
{
	return type;
}

Entity* Entity::GetParent() const 
{
	return parent;
}

void Entity::SetParent(Entity* parent) 
{
	this->parent = parent;
}

void Entity::Look() 
{
	cout << description;
}

void Entity::Insert(Entity* entity) 
{
	content.push_back(entity);
}

void Entity::Remove(Entity* entity) 
{
	content.remove(entity);
}

int Entity::Show(list<Entity*>& entities, EntityType type) 
{
	int count = 0;

	for (Entity* x : entities)
	{
		if (x != nullptr && type == x->GetType())
		{
			string itemName = Txt_to_low(x->GetName());
			cout << "\t- " << itemName << endl;
			count++;
		}
	}

	return count;
}