#include "chess_ju.h"

chess_ju::chess_ju(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEJU;
}

chess_ju::chess_ju(void):chess(-1,-1,PLAYERNONE,false)
{
	name=NAMEJU;
}

chess_ju::chess_ju(chess_ju &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_ju::OutChessName()
{
	return name;
}

BOARD_HIND chess_ju::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
{
	BOARD_HIND *p=new BOARD_HIND;

	//临时变量
	int i,k;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
			p->a[i][k]=false;

	//某一方向上的第一个棋子坐标
	int x1=-1;
	int y1=-1;

	
	//左
	for(k=y-1;k>=0;k--)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x1=x;
			y1=k;
			break;
		}
	if(x1==-1 && y1==-1)
		for(k=y-1;k>=0;k--)
			p->a[x][k]=true;
	if(x1!=-1 && y1!=-1)
	{
		for(k=y-1;k>=y1+1;k--)
			p->a[x][k]=true;
		if(BOARD.a[x1][y1]!=player)
			p->a[x1][y1]=true;
	}

	x1=y1=-1;

	//右
	for(k=y+1;k<=8;k++)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x1=x;
			y1=k;
			break;
		}
	if(x1==-1 && y1==-1)
		for(k=y+1;k<=8;k++)
			p->a[x][k]=true;
	if(x1!=-1 && y1!=-1)
	{
		for(k=y+1;k<=y1-1;k++)
			p->a[x][k]=true;
		if(BOARD.a[x1][y1]!=player)
			p->a[x1][y1]=true;
	}

	x1=y1=-1;

	//上
	for(i=x-1;i>=0;i--)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x1=i;
			y1=y;
			break;
		}
	if(x1==-1 && y1==-1)
		for(i=x-1;i>=0;i--)
			p->a[i][y]=true;
	if(x1!=-1 && y1!=-1)
	{
		for(i=x-1;i>=x1+1;i--)
			p->a[i][y]=true;
		if(BOARD.a[x1][y1]!=player)
			p->a[x1][y1]=true;
	}

	x1=y1=-1;

	//下
	for(i=x+1;i<=9;i++)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x1=i;
			y1=y;
			break;
		}
	if(x1==-1 && y1==-1)
		for(i=x+1;i<=9;i++)
			p->a[i][y]=true;
	if(x1!=-1 && y1!=-1)
	{
		for(i=x+1;i<=x1-1;i++)
			p->a[i][y]=true;
		if(BOARD.a[x1][y1]!=player)
			p->a[x1][y1]=true;
	}

	return *p;
}
