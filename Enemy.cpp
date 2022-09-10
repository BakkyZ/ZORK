#pragma once
#include "Enemy.h"

void Enemy::Attack() 
{
	if (GetName() != " ") 
	{
		life--;
		cout << "You hit the " << GetName() << "! " << "It has " << life << " lives left.";
	}
}

bool Enemy::IsDead() const 
{
	return life == 0;
}
