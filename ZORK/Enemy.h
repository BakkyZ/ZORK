#pragma once
#include "Creature.h"

class Enemy : public Creature 
{

public:
	Enemy(string name, string description, Room* location) 
		: Creature(EntityType::ENEMY, name, description, location) 
	{
		this->life = 3;
	}

	void Attack();
	bool IsDead() const;

private:
	int life;
};
