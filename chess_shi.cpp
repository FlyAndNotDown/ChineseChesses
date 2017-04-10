#include "chess_shi.h"

chess_shi::chess_shi(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMESHI;
}

chess_shi::chess_shi(void):chess(-1,-1,NAMENONE,false)
{
	name=NAMESHI;
}

chess_shi::chess_shi(chess_shi &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_shi::OutChessName()
{
	return name;
}

BOARD_HIND chess_shi::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//¡Ÿ ±±‰¡ø
	int i,k;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
			p->a[i][k]=false;

	if(player==PLAYERRED)
		switch(x)
		{
		case 7:
			if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
			break;
		case 8:
			if(BOARD.a[7][3]!=PLAYERRED) p->a[7][3]=true;
			if(BOARD.a[7][5]!=PLAYERRED) p->a[7][5]=true;
			if(BOARD.a[9][3]!=PLAYERRED) p->a[9][3]=true;
			if(BOARD.a[9][5]!=PLAYERRED) p->a[9][5]=true;
			break;
		case 9:
			if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
			break;
		}

	if(player==PLAYERBLACK)
		switch(x)
		{
		case 0:
			if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
			break;
		case 1:
			if(BOARD.a[0][3]!=PLAYERBLACK) p->a[0][3]=true;
			if(BOARD.a[0][5]!=PLAYERBLACK) p->a[0][5]=true;
			if(BOARD.a[2][3]!=PLAYERBLACK) p->a[2][3]=true;
			if(BOARD.a[2][5]!=PLAYERBLACK) p->a[2][5]=true;
			break;
		case 2:
			if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
			break;
		}

	return *p;
}
