#include "chess_xiang.h"

chess_xiang::chess_xiang(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEXIANG;
}

chess_xiang::chess_xiang(void):chess(-1,-1,NAMENONE,false)
{
	name=NAMEXIANG;
}

chess_xiang::chess_xiang(chess_xiang &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_xiang::OutChessName()
{
	return name;
}

BOARD_HIND chess_xiang::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//¡Ÿ ±±‰¡ø
	int i,k;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
			p->a[i][k]=false;
	
	if(player==PLAYERRED)
	{
		switch(x)
		{
		case 5:
			switch(y)
			{
			case 2:
				if(BOARD.a[7][0]!=PLAYERRED && BOARD.a[6][1]==PLAYERNONE) p->a[7][0]=true;
				if(BOARD.a[7][4]!=PLAYERRED && BOARD.a[6][3]==PLAYERNONE) p->a[7][4]=true;
				break;
			case 6:
				if(BOARD.a[7][4]!=PLAYERRED && BOARD.a[6][5]==PLAYERNONE) p->a[7][4]=true;
				if(BOARD.a[7][8]!=PLAYERRED && BOARD.a[6][7]==PLAYERNONE) p->a[7][8]=true;
				break;
			}
			break;
		case 7:
			switch(y)
			{
			case 0:
				if(BOARD.a[5][2]!=PLAYERRED && BOARD.a[6][1]==PLAYERNONE) p->a[5][2]=true;
				if(BOARD.a[9][2]!=PLAYERRED && BOARD.a[8][1]==PLAYERNONE) p->a[9][2]=true;
				break;
			case 4:
				if(BOARD.a[5][2]!=PLAYERRED && BOARD.a[6][3]==PLAYERNONE) p->a[5][2]=true;
				if(BOARD.a[5][6]!=PLAYERRED && BOARD.a[6][5]==PLAYERNONE) p->a[5][6]=true;
				if(BOARD.a[9][2]!=PLAYERRED && BOARD.a[8][3]==PLAYERNONE) p->a[9][2]=true;
				if(BOARD.a[9][6]!=PLAYERRED && BOARD.a[8][5]==PLAYERNONE) p->a[9][6]=true;
				break;
			case 8:
				if(BOARD.a[5][6]!=PLAYERRED && BOARD.a[6][7]==PLAYERNONE) p->a[5][6]=true;
				if(BOARD.a[9][6]!=PLAYERRED && BOARD.a[8][7]==PLAYERNONE) p->a[9][6]=true;
				break;
			}
			break;
		case 9:
			switch(y)
			{
			case 2:
				if(BOARD.a[7][0]!=PLAYERRED && BOARD.a[8][1]==PLAYERNONE) p->a[7][0]=true;
				if(BOARD.a[7][4]!=PLAYERRED && BOARD.a[8][3]==PLAYERNONE) p->a[7][4]=true;
				break;
			case 6:
				if(BOARD.a[7][4]!=PLAYERRED && BOARD.a[8][5]==PLAYERNONE) p->a[7][4]=true;
				if(BOARD.a[7][8]!=PLAYERRED && BOARD.a[8][7]==PLAYERNONE) p->a[7][8]=true;
				break;
			}
			break;
		}
	}

	if(player==PLAYERBLACK)
	{
		switch(x)
		{
		case 0:
			switch(y)
			{
			case 2:
				if(BOARD.a[2][0]!=PLAYERBLACK && BOARD.a[1][1]==PLAYERNONE) p->a[2][0]=true;
				if(BOARD.a[2][4]!=PLAYERBLACK && BOARD.a[1][3]==PLAYERNONE) p->a[2][4]=true;
				break;
			case 6:
				if(BOARD.a[2][4]!=PLAYERBLACK && BOARD.a[1][5]==PLAYERNONE) p->a[2][4]=true;
				if(BOARD.a[2][8]!=PLAYERBLACK && BOARD.a[1][7]==PLAYERNONE) p->a[2][8]=true;
				break;
			}
			break;
		case 2:
			switch(y)
			{
			case 0:
				if(BOARD.a[0][2]!=PLAYERBLACK && BOARD.a[1][1]==PLAYERNONE) p->a[0][2]=true;
				if(BOARD.a[4][2]!=PLAYERBLACK && BOARD.a[1][3]==PLAYERNONE) p->a[4][2]=true;
				break;
			case 4:
				if(BOARD.a[0][2]!=PLAYERBLACK && BOARD.a[1][3]==PLAYERNONE) p->a[0][2]=true;
				if(BOARD.a[0][6]!=PLAYERBLACK && BOARD.a[1][5]==PLAYERNONE) p->a[0][6]=true;
				if(BOARD.a[4][2]!=PLAYERBLACK && BOARD.a[3][3]==PLAYERNONE) p->a[4][2]=true;
				if(BOARD.a[4][6]!=PLAYERBLACK && BOARD.a[3][5]==PLAYERNONE) p->a[4][6]=true;
				break;
			case 8:
				if(BOARD.a[0][6]!=PLAYERBLACK && BOARD.a[1][7]==PLAYERNONE) p->a[0][6]=true;
				if(BOARD.a[4][6]!=PLAYERBLACK && BOARD.a[3][7]==PLAYERNONE) p->a[4][6]=true;
				break;
			}
			break;
		case 4:
			switch(y)
			{
			case 2:
				if(BOARD.a[2][0]!=PLAYERBLACK && BOARD.a[3][1]==PLAYERNONE) p->a[2][0]=true;
				if(BOARD.a[2][4]!=PLAYERBLACK && BOARD.a[3][3]==PLAYERNONE) p->a[2][4]=true;
				break;
			case 6:
				if(BOARD.a[2][4]!=PLAYERBLACK && BOARD.a[3][5]==PLAYERNONE) p->a[2][4]=true;
				if(BOARD.a[2][8]!=PLAYERBLACK && BOARD.a[3][7]==PLAYERNONE) p->a[2][8]=true;
				break;
			}
			break;
		}
	}

	return *p;
}
