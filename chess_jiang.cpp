#include "chess_jiang.h"

chess_jiang::chess_jiang(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEJIANG;
}

chess_jiang::chess_jiang(void):chess(-1,-1,PLAYERNONE,false)
{
	name=NAMEJIANG;
}

chess_jiang::chess_jiang(chess_jiang &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_jiang::OutChessName()
{
	return name;
}

BOARD_HIND chess_jiang::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//临时变量
	int i,k;
	int can=1;

	//对面将的位置
	int temp_x;
	int temp_y;

	for(i=0;i<=9;i++)
			for(k=0;k<=8;k++)
				p->a[i][k]=false;

	if(player==PLAYERRED)
	{
		switch(x)
		{
		case 7:
			switch(y)
			{
			case 3:
				if(BOARD.a[7][4]!=PLAYERRED) p->a[7][4]=true;
				if(BOARD.a[8][3]!=PLAYERRED) p->a[8][3]=true;
				break;
			case 4:
				if(BOARD.a[7][3]!=PLAYERRED) p->a[7][3]=true;
				if(BOARD.a[7][5]!=PLAYERRED) p->a[7][5]=true;
				if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
				break;
			case 5:
				if(BOARD.a[7][4]!=PLAYERRED) p->a[7][4]=true;
				if(BOARD.a[8][5]!=PLAYERRED) p->a[8][5]=true;
				break;
			}
			break;
		case 8:
			switch(y)
			{
			case 3:
				if(BOARD.a[7][3]!=PLAYERRED) p->a[7][3]=true;
				if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
				if(BOARD.a[9][3]!=PLAYERRED) p->a[9][3]=true;
				break;
			case 4:
				if(BOARD.a[7][4]!=PLAYERRED) p->a[7][4]=true;
				if(BOARD.a[8][3]!=PLAYERRED) p->a[8][3]=true;
				if(BOARD.a[8][5]!=PLAYERRED) p->a[8][5]=true;
				if(BOARD.a[9][4]!=PLAYERRED) p->a[9][4]=true;
				break;
			case 5:
				if(BOARD.a[7][5]!=PLAYERRED) p->a[7][5]=true;
				if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
				if(BOARD.a[9][5]!=PLAYERRED) p->a[9][5]=true;
				break;
			}
			break;
		case 9:
			switch(y)
			{
			case 3:
				if(BOARD.a[8][3]!=PLAYERRED) p->a[8][3]=true;
				if(BOARD.a[9][4]!=PLAYERRED) p->a[9][4]=true;
				break;
			case 4:
				if(BOARD.a[8][4]!=PLAYERRED) p->a[8][4]=true;
				if(BOARD.a[9][3]!=PLAYERRED) p->a[9][3]=true;
				if(BOARD.a[9][5]!=PLAYERRED) p->a[9][5]=true;
				break;
			case 5:
				if(BOARD.a[8][5]!=PLAYERRED) p->a[8][5]=true;
				if(BOARD.a[9][4]!=PLAYERRED) p->a[9][4]=true;
				break;
			}
			break;
		}

		//寻找对手将的位置
		for(i=0;i<=2;i++)
			for(k=3;k<=5;k++)
				if(CHESS.a[i][k]==NAMEJIANG && BOARD.a[i][k]==PLAYERBLACK)
				{
					temp_x=i;
					temp_y=k;
				}

		if(y==temp_y)
			for(i=temp_x+1;i<=x-1;i++)
				if(CHESS.a[i][y]!=NAMENONE)
					can=0;
		if(can==1) p->a[temp_x][temp_y]=true;
	}

	can=1;

	if(player==PLAYERBLACK)
	{
		switch(x)
		{
		case 0:
			switch(y)
			{
			case 3:
				if(BOARD.a[0][4]!=PLAYERBLACK) p->a[0][4]=true;
				if(BOARD.a[1][3]!=PLAYERBLACK) p->a[1][3]=true;
				break;
			case 4:
				if(BOARD.a[0][3]!=PLAYERBLACK) p->a[0][3]=true;
				if(BOARD.a[0][5]!=PLAYERBLACK) p->a[0][5]=true;
				if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
				break;
			case 5:
				if(BOARD.a[0][4]!=PLAYERBLACK) p->a[0][4]=true;
				if(BOARD.a[1][5]!=PLAYERBLACK) p->a[1][5]=true;
				break;
			}
			break;
		case 1:
			switch(y)
			{
			case 3:
				if(BOARD.a[0][3]!=PLAYERBLACK) p->a[0][3]=true;
				if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
				if(BOARD.a[2][3]!=PLAYERBLACK) p->a[2][3]=true;
				break;
			case 4:
				if(BOARD.a[0][4]!=PLAYERBLACK) p->a[0][4]=true;
				if(BOARD.a[1][3]!=PLAYERBLACK) p->a[1][3]=true;
				if(BOARD.a[1][5]!=PLAYERBLACK) p->a[1][5]=true;
				if(BOARD.a[2][4]!=PLAYERBLACK) p->a[2][4]=true;
				break;
			case 5:
				if(BOARD.a[0][5]!=PLAYERBLACK) p->a[0][5]=true;
				if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
				if(BOARD.a[2][5]!=PLAYERBLACK) p->a[2][5]=true;
				break;
			}
			break;
		case 2:
			switch(y)
			{
			case 3:
				if(BOARD.a[1][3]!=PLAYERBLACK) p->a[1][3]=true;
				if(BOARD.a[2][4]!=PLAYERBLACK) p->a[2][4]=true;
				break;
			case 4:
				if(BOARD.a[1][4]!=PLAYERBLACK) p->a[1][4]=true;
				if(BOARD.a[2][3]!=PLAYERBLACK) p->a[2][3]=true;
				if(BOARD.a[2][5]!=PLAYERBLACK) p->a[2][5]=true;
				break;
			case 5:
				if(BOARD.a[1][5]!=PLAYERBLACK) p->a[1][5]=true;
				if(BOARD.a[2][4]!=PLAYERBLACK) p->a[2][4]=true;
				break;
			}
			break;
		}

		//寻找对手将的位置
		for(i=7;i<=9;i++)
			for(k=3;k<=5;k++)
				if(CHESS.a[i][k]==NAMEJIANG && BOARD.a[i][k]==PLAYERRED)
				{
					temp_x=i;
					temp_y=k;
				}

		if(y==temp_y)
			for(i=x+1;i<=temp_x-1;i++)
				if(CHESS.a[i][y]!=NAMENONE)
					can=0;

		if(can==1) p->a[temp_x][temp_y]=true;
	}

	return *p;
}
