#include "chess_pao.h"

chess_pao::chess_pao(int X,int Y,int PLAYER,bool ALIVE):chess(X,Y,PLAYER,ALIVE)
{
	name=NAMEPAO;
}

chess_pao::chess_pao(void):chess(-1,-1,NAMENONE,false)
{
	name=NAMEPAO;
}

chess_pao::chess_pao(chess_pao &obj)
{
	x=obj.x;
	y=obj.y;
	name=obj.name;
	player=obj.player;
	alive=obj.alive;
}

int chess_pao::OutChessName()
{
	return name;
}

BOARD_HIND chess_pao::hind(BOARD_CHESS BOARD,BOARD_CHESS CHESS)
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

	//某一方向上的第二个棋子坐标
	int x2=-1;
	int y2=-1;


	//左
	for(k=y-1;k>=0;k--)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x1=x;
			y1=k;
			break;
		}
	for(k=y1-1;k>=0;k--)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x2=x;
			y2=k;
			break;
		}
	if(x1==-1 && y1==-1)
		for(k=0;k<=y-1;k++)
			p->a[x][k]=true;

	if(x1!=-1 && y1!=-1)
	{
		for(k=y-1;k>=y1+1;k--)
			p->a[x][k]=true;
	
		if(x2!=-1 && y2!=-1 && player!=BOARD.a[x2][y2])
			p->a[x2][y2]=true;
	}

	x1=y1=x2=y2=-1;
	
	//右
	for(k=y+1;k<=8;k++)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x1=x;
			y1=k;
			break;
		}
	for(k=y1+1;k<=8;k++)
		if(BOARD.a[x][k]!=PLAYERNONE)
		{
			x2=x;
			y2=k;
			break;
		}
	if(x1==-1 && y1==-1)
		for(k=y+1;k<=8;k++)
			p->a[x][k]=true;

	if(x1!=-1 && y1!=-1)
	{
		for(k=y+1;k<=y1-1;k++)
			p->a[x][k]=true;

		if(x2!=-1 && y2!=-1 && player!=BOARD.a[x2][y2])
			p->a[x2][y2]=true;
	}

	x1=y1=x2=y2=-1;

	//上
	for(i=x-1;i>=0;i--)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x1=i;
			y1=y;
			break;
		}
	for(i=x1-1;i>=0;i--)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x2=i;
			y2=y;
			break;
		}
	
	if(x1==-1 && y1==-1)
		for(i=x-1;i>=0;i--)
			p->a[i][y]=true;

	if(x1!=-1 && y1!=-1)
	{
		for(i=x-1;i>=x1+1;i--)
			p->a[i][y]=true;

		if(x2!=-1 && y2!=-1 && player!=BOARD.a[x2][y2])
			p->a[x2][y2]=true;
	}

	x1=y1=x2=y2=-1;
	
	//下
	for(i=x+1;i<=9;i++)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x1=i;
			y1=y;
			break;
		}
	for(i=x1+1;i<=9;i++)
		if(BOARD.a[i][y]!=PLAYERNONE)
		{
			x2=i;
			y2=y;
			break;
		}

	if(x1==-1 && y1==-1)
		for(i=x+1;i<=9;i++)
			p->a[i][y]=true;

	if(x1!=-1 && y1!=-1)
	{
		for(i=x+1;i<=x1-1;i++)
			p->a[i][y]=true;

		if(x2!=-1 && y2!=-1 &&player!=BOARD.a[x2][y2])
			p->a[x2][y2]=true;
	}

	return *p;
}