#include "Player.h"

void Player::DescribePath() 
{
	cout << "\n\t" << location->GetName() << "\n\n\t";
	GetLocation()->Look();
	cout << "\n\n\tYou can go to: \n";
	Show(GetLocation()->content, EntityType::EXIT);
	cout << "\tItems here: \n";
	if (Show(GetLocation()->content, EntityType::ITEM) == 0)
	{
		cout << "\tNo items.";
	}
	cout << "\tEnemies in the room: \n";
	if (Show(GetLocation()->content, EntityType::ENEMY) == 0)
	{
		cout << "\tNo enemy here. \n";
	}
}

void Player::Inventory() 
{
	cout << "\n\tInventory: \n";
	if( Show(content, EntityType::ITEM) == 0) 
	{ 
		cout << "\tYou  dont have anything"; 
	}
}

Item* Player::GetHoldingItem() const 
{
	return holdingItem;
}

void Player::SetHoldingItem(Item* item) 
{
	holdingItem = item;
}

void Player::Look(const string& str) 
{

	bool looked = false;

	if ("me" == str) 
	{
		Entity::Look();
		looked = true;
	}

	if ("room" == str) 
	{
		DescribePath();
		looked = true;
	}

	if (!looked) 
	{
		string currentRoomName = Txt_to_low(location->GetName());
		if (currentRoomName == str) 
		{
			location->Look();
			looked = true;
		}
	}


	if (!looked) 
	{
		string entityName;

		for (Entity *e : location->content) 
		{		
			switch (e->GetType()) {
			case EntityType::EXIT:
			case EntityType::ITEM:
				entityName = Txt_to_low(e->GetName());
				if (entityName == str) 
				{
					e->Look();
					looked = true;
				}
				break;
			default:
				break;
			}

		}
	}


	if (!looked) 
	{
		Item* item = GetEntityName<Item>(str, content, EntityType::ITEM);

		if (item != nullptr) 
		{
			item->Look();
			looked = true;
		}
	}


	if (!looked) 
	{
		Exit* exit = ExitPath(str);

		if (exit != nullptr)
		{
			exit->Look();
			looked = true;
		}
	}

	if (!looked) 
	{
		cerr << "\tYou see nothing " << str << ".";
	}

}

void Player::Go(const string& str)
{

	bool moved = false;

	Exit* exit = ExitPath(str);
	if (exit != nullptr) 
	{
		if (exit->IsLocked()) 
		{
			cout << str << " is locked.";
		}
		else 
		{
			system("cls");
			cout << "\tMoving to " << str << " path.\n";
			location = exit->GetDestination();
			DescribePath();
			moved = true;
		}
	}

	if (!moved)
	{
		cout << "\tYou can't move to " << str << ".";
	}

}

void Player::Take(const string& str) 
{

	Item* item = GetEntityName<Item>(str, location->content, EntityType::ITEM);

	if (item == nullptr) 
	{
		cout << "\tYou can't take " << str << ".";
	}
	else 
	{
		content.push_back(item);
		location->content.remove(item);
		cout << "\tYou take " << str << ".";
	}
		
}

void Player::Drop(const string& str) 
{

	Item* item = GetEntityName<Item>(str, content, EntityType::ITEM);

	if (item == nullptr) 
	{
		cout << "\n\tYou can't drop " << str << ".";
	}
	else 
	{

		if (GetHoldingItem() == item) 
		{
			Unequip(str);
		}

		Entity* parent = item->GetParent();
		if (parent != nullptr) 
		{
			parent->Remove(item);
			item->SetParent(nullptr);
		}

		for (Entity* child : item->content) 
		{
			content.remove(child);
			location->content.push_back(child);
			cout << "\tYou dropped " << child->GetName() << ".";
		}

		item->content.clear();
		content.remove(item);
		location->content.push_back(item);
		cout << "\tYou dropped " << str << ".";
	}

}

void Player::Equip(const string& str) 
{

	Item* item = GetEntityName<Item>(str, content, EntityType::ITEM);

	if (item == nullptr) {
		cout << "\tYou can't equip " << str << ".";
	}
	else {
		if (GetHoldingItem() != nullptr)
			cout << "\tChanged " << GetHoldingItem()->GetName() << " for " << item->GetName() << ".";
		SetHoldingItem(item);
		cout << "\tEquipped " << item->GetName() << ".";
	}

}

void Player::Unequip(const string& str) 
{

	Item* item = GetEntityName<Item>(str, content, EntityType::ITEM);

	if (item == nullptr) 
	{
		cout << "\tYou can't unequip " << str << ".";
	}
	else
	{
		if (GetHoldingItem() == item) 
		{
			cout << "\tUnequipped a " << item->GetName() << ".";
			SetHoldingItem(nullptr);
		}
		else 
		{
			cout << "\tYou not holding " << item->GetName() << ".";
		}
	}

}

void Player::Attack(const string& str) 
{

	Enemy* enemy = GetEnemyFromCurrentRoom();

	if (enemy == nullptr) 
	{
		cout << "\n\tNobody is in this room.";
	}
	else
		{
			Item* weapon = GetTypeItem(ItemType::WEAPON);

			if (weapon == nullptr)
			{
				cout << "\n\tYou don't have a weapon to attack.";
			}
			else 
			{
				if (weapon == GetHoldingItem()) 
				{
					if (enemy->IsDead()) 
					{
							cout << "\n\tThe " << enemy->GetName() <<"is dead.";
					}
					else
					{
						enemy->Attack();
					}
				}
					else
					{
						cout << "\n\tYou need to equip a weapon to attack.";
					}	
				}
			}
}

void Player::Unlock(const string& str) 
{

	if (IsPath(str)) 
	{

		Path* direction = SetPath(str);
		Exit* exit = ExitPath(str);

		if (exit == nullptr) 
		{
			cout << "\n\tThere is no exit in " << str << ".";
		}
		else 
		{
			if (exit->IsLocked()) 
			{
				Item* key = GetTypeItem(ItemType::KEY);

				if (key == nullptr) 
				{
					cout << "\n\tYou don't have a key to unlock this path.";
				}
				else 
				{
	
					if (key == GetHoldingItem() && key == exit->ExitKey())
					{
						cout << str << " unlocked.";
						exit->SetExit(false);
					}
					else
					{
						cout << "\n\tYou are missing something important to open the path.";
					}
				}
			}
			else
			{
				cout << str << " is already unlocked!";
			}
		}

	}
	else 
	{
		cout << "\n\tCommand must be a path.";
	}
}


Exit* Player::ExitPath(const Path& dir) const 
{
	Exit* exit = nullptr;

	for (Entity* e : location->content) 
	{

		if (e != nullptr && e->GetType() == EntityType::EXIT)
		{
			if (dir == ((Exit*)e)->GetPath()) 
			{
				exit = (Exit*)e;
				break;
			}
		}
	}
	return exit;
}

Exit* Player::ExitPath(const string& str) const 
{
	return IsPath(str) ? ExitPath(*SetPath(str)) : nullptr;
}

template <class T>
T* Player::GetEntityName(const string& name, const list<Entity*>& entities, const EntityType type) const
{
	T* entity = nullptr;



	for (Entity* e : entities) {
		
		if (e!=nullptr && e->GetType() == type) {

			string entityName = Txt_to_low(e->GetName());
			if (entityName == name) {
				entity = (T*)e;
				break;
			}
		}
	}

	return entity;
}

Item* Player::GetTypeItem(ItemType type) const
{
	Item* item = nullptr;

	for (Entity* e : content)
	{

		if (e!=nullptr && e->GetType() == EntityType::ITEM && ((Item*)e)->GetItemType() == type) 
		{
			item = (Item*)e;
			break;
		}
	}
	return item;
}

Enemy* Player::GetEnemyFromCurrentRoom() const 
{
	Enemy* enemy = nullptr;


	for (Entity* e : location->content) 
	{

		if (e != nullptr && e->GetType() == EntityType::ENEMY) {
			enemy = (Enemy*)e;
			break;
		}
	}
	return enemy;
}
