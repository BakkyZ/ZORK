#include "Achievements.h"
Path Achievement::GetPath() const
{
	return path;
}
void Achievement::SetShow(bool status)
{
	show = status;
}
bool Achievement::IsShowed() const
{
	return show;
}