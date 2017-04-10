#include "mouse.h"

mouse::mouse(int X,int Y,int PLAYER)
{
	x=X;
	y=Y;
	player=PLAYER;
}

mouse::mouse(void)
{
	x=-1;
	y=-1;
	player=PLAYERNONE;
}

mouse::mouse(mouse &obj)
{
	x=obj.x;
	y=obj.y;
	player=obj.player;
}

void mouse::InXY(int X,int Y)
{
	x=X;
	y=Y;
}

void mouse::InPlayer(int PLAYER)
{
	player=PLAYER;
}

int mouse::OutX()
{
	return x;
}

int mouse::OutY()
{
	return y;
}

int mouse::OutPlayer()
{
	return player;
}
