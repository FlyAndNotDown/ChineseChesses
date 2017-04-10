#include "chess.h"

chess::chess(int X,int Y,int PLAYER,bool ALIVE)
{
	x=X;
	y=Y;
	player=PLAYER;
	alive=ALIVE;
}

chess::chess(void)
{
	x=-1;
	y=-1;
	player=PLAYERNONE;
	alive=false;
}

chess::chess(chess &obj)
{
	x=obj.x;
	y=obj.y;
	player=obj.player;
	alive=obj.alive;
}

void chess::InPlayer(int PLAYER)
{
	player=PLAYER;
}

int chess::OutPlayer()
{
	return player;
}

void chess::InXY(int X,int Y)
{
	x=X;
	y=Y;
}

int chess::OutX()
{
	return x;
}

int chess::OutY()
{
	return y;
}

void chess::InAlive(bool ALIVE)
{
	alive=ALIVE;
}

bool chess::OutAlive()
{
	return alive;
}