#include "chess_bing.h"

chess_bing::chess_bing(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEBING;
}

chess_bing::chess_bing(void):chess(-1,-1,PLAYERNONE,false)
{
	name=NAMEBING;
}

chess_bing::chess_bing(chess_bing &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_bing::OutChessName()
{
	return name;
}

BOARD_HIND chess_bing::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//¡Ÿ ±±‰¡ø
	int i,k;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
			p->a[i][k]=false;

	if(player==PLAYERRED)
	{
		if(x>=5 && BOARD.a[x-1][y]!=PLAYERRED)
		{
			if(BOARD.a[x-1][y]!=PLAYERRED)
				p->a[x-1][y]=true;
		}
		else
		{
			if(BOARD.a[x][y-1]!=PLAYERRED && (y-1>=0)) p->a[x][y-1]=true;
			if(BOARD.a[x][y+1]!=PLAYERRED && (y+1<=8)) p->a[x][y+1]=true;
			if(BOARD.a[x-1][y]!=PLAYERRED && (x-1>=0)) p->a[x-1][y]=true;
		}
	}

	if(player==PLAYERBLACK)
	{
		if(x<=4)
		{
			if(BOARD.a[x-1][y]!=PLAYERBLACK)
				p->a[x+1][y]=true;
		}
		else
		{
			if(BOARD.a[x][y-1]!=PLAYERRED && (y-1>=0)) p->a[x][y-1]=true;
			if(BOARD.a[x][y+1]!=PLAYERBLACK && (y+1<=8)) p->a[x][y+1]=true;
			if(BOARD.a[x+1][y]!=PLAYERBLACK && (x+1<=9)) p->a[x+1][y]=true;
		}
	}

	return *p;
}
