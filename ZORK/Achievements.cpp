#include "Achievements.h"

void Achievement::SetShow(bool status)
{
	show = status;
}
bool Achievement::IsShowed() const
{
	return show;
}