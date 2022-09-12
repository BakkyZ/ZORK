#pragma once
#include "Enemy.h"

void Enemy::Attack() 
{
	if (GetName() != " ") 
	{
		life--;
		cout << "\tYou hit the " << GetName() << "! " << "It has " << life << " lives left.";
	}
}

bool Enemy::IsDead() const 
{
	if (life <= 0) 
	{
		return true;
	}
	return false;
}
