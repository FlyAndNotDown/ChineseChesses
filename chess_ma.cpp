#include "chess_ma.h"

chess_ma::chess_ma(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEMA;
}

chess_ma::chess_ma(void):chess(-1,-1,PLAYERNONE,false)
{
	name=NAMEMA;
}

chess_ma::chess_ma(chess_ma &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_ma::OutChessName()
{
	return name;
}

BOARD_HIND chess_ma::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//¡Ÿ ±±‰¡ø
	int i,k;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
			p->a[i][k]=false;

	if(BOARD.a[x-2][y-1]!=player && (x-2>=0) && (y-1>=0) &&
		BOARD.a[x-1][y]==PLAYERNONE) p->a[x-2][y-1]=true;
	if(BOARD.a[x-2][y+1]!=player && (x-2>=0) && (y+1<=8) &&
		BOARD.a[x-1][y]==PLAYERNONE) p->a[x-2][y+1]=true;
	if(BOARD.a[x-1][y-2]!=player && (x-1>=0) && (y-2>=0) &&
		BOARD.a[x][y-1]==PLAYERNONE) p->a[x-1][y-2]=true;
	if(BOARD.a[x-1][y+2]!=player && (x-1>=0) && (y+2<=8) &&
		BOARD.a[x][y+1]==PLAYERNONE) p->a[x-1][y+2]=true;
	if(BOARD.a[x+1][y-2]!=player && (x+1<=9) && (y-2>=0) &&
		BOARD.a[x][y-1]==PLAYERNONE) p->a[x+1][y-2]=true;
	if(BOARD.a[x+1][y+2]!=player && (x+1<=9) && (y+2<=8) &&
		BOARD.a[x][y+1]==PLAYERNONE) p->a[x+1][y+2]=true;
	if(BOARD.a[x+2][y-1]!=player && (x+2<=9) && (y-1>=0) &&
		BOARD.a[x+1][y]==PLAYERNONE) p->a[x+2][y-1]=true;
	if(BOARD.a[x+2][y+1]!=player && (x+2<=9) && (y+1<=8) &&
		BOARD.a[x+1][y]==PLAYERNONE) p->a[x+2][y+1]=true;

	return *p;
}