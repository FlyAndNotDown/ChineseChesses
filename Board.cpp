#include "Board.h"

Board::Board
	(
		chess_jiang JIANGRED,chess_jiang JIANGBLACK,
		chess_shi SHIRED1,chess_shi SHIRED2,
		chess_shi SHIBLACK1,chess_shi SHIBLACK2,
		chess_xiang XIANGRED1,chess_xiang XIANGRED2,
		chess_xiang XIANGBLACK1,chess_xiang XIANGBLACK2,
		chess_pao PAORED1,chess_pao PAORED2,
		chess_pao PAOBLACK1,chess_pao PAOBLACK2,
		chess_ma MARED1,chess_ma MARED2,
		chess_ma MABLACK1,chess_ma MABLACK2,
		chess_ju JURED1,chess_ju JURED2,
		chess_ju JUBLACK1,chess_ju JUBLACK2,
		chess_bing BINGRED1,chess_bing BINGRED2,
		chess_bing BINGRED3,chess_bing BINGRED4,chess_bing BINGRED5,
		chess_bing BINGBLACK1,chess_bing BINGBLACK2,
		chess_bing BINGBLACK3,chess_bing BINGBLACK4,chess_bing BINGBLACK5,
		int TURN
	)
	:JiangRed(JIANGRED),JiangBlack(JIANGBLACK),
	ShiRed1(SHIRED1),ShiRed2(SHIRED2),
	ShiBlack1(SHIBLACK1),ShiBlack2(SHIBLACK2),
	XiangRed1(XIANGRED1),XiangRed2(XIANGRED2),
	XiangBlack1(XIANGBLACK1),XiangBlack2(XIANGBLACK2),
	PaoRed1(PAORED1),PaoRed2(PAORED2),
	PaoBlack1(PAOBLACK1),PaoBlack2(PAOBLACK2),
	MaRed1(MARED1),MaRed2(MARED2),
	MaBlack1(MABLACK1),MaBlack2(MABLACK2),
	JuRed1(JURED1),JuRed2(JURED2),
	JuBlack1(JUBLACK1),JuBlack2(JUBLACK2),
	BingRed1(BINGRED1),BingRed2(BINGRED2),BingRed3(BINGRED3),
	BingRed4(BINGRED4),BingRed5(BINGRED5),
	BingBlack1(BINGBLACK1),BingBlack2(BINGBLACK2),BingBlack3(BINGBLACK3),
	BingBlack4(BINGBLACK4),BingBlack5(BINGBLACK5),
	MouseRed(9,8,PLAYERRED),MouseBlack(0,0,PLAYERBLACK)
{
	choice=false;
	turn=TURN;

	ChX=-1;
	ChY=-1;
	record=-1;

	winner=-1;

	che[0]=&JiangRed;
	che[1]=&JiangBlack;
	che[2]=&ShiRed1;
	che[3]=&ShiRed2;
	che[4]=&ShiBlack1;
	che[5]=&ShiBlack2;
	che[6]=&XiangRed1;
	che[7]=&XiangRed2;
	che[8]=&XiangBlack1;
	che[9]=&XiangBlack2;
	che[10]=&PaoRed1;
	che[11]=&PaoRed2;
	che[12]=&PaoBlack1;
	che[13]=&PaoBlack2;
	che[14]=&MaRed1;
	che[15]=&MaRed2;
	che[16]=&MaBlack1;
	che[17]=&MaBlack2;
	che[18]=&JuRed1;
	che[19]=&JuRed2;
	che[20]=&JuBlack1;
	che[21]=&JuBlack2;
	che[22]=&BingRed1;
	che[23]=&BingRed2;
	che[24]=&BingRed3;
	che[25]=&BingRed4;
	che[26]=&BingRed5;
	che[27]=&BingBlack1;
	che[28]=&BingBlack2;
	che[29]=&BingBlack3;
	che[30]=&BingBlack4;
	che[31]=&BingBlack5;
	
	Flash();
}

Board::Board(void)
	:JiangRed(9,4,PLAYERRED,true),JiangBlack(0,4,PLAYERBLACK,true),
	ShiRed1(9,3,PLAYERRED,true),ShiRed2(9,5,PLAYERRED,true),
	ShiBlack1(0,3,PLAYERBLACK,true),ShiBlack2(0,5,PLAYERBLACK,true),
	XiangRed1(9,2,PLAYERRED,true),XiangRed2(9,6,PLAYERRED,true),
	XiangBlack1(0,2,PLAYERBLACK,true),XiangBlack2(0,6,PLAYERBLACK,true),
	PaoRed1(7,1,PLAYERRED,true),PaoRed2(7,7,PLAYERRED,true),
	PaoBlack1(2,1,PLAYERBLACK,true),PaoBlack2(2,7,PLAYERBLACK,true),
	MaRed1(9,1,PLAYERRED,true),MaRed2(9,7,PLAYERRED,true),
	MaBlack1(0,1,PLAYERBLACK,true),MaBlack2(0,7,PLAYERBLACK,true),
	JuRed1(9,0,PLAYERRED,true),JuRed2(9,8,PLAYERRED,true),
	JuBlack1(0,0,PLAYERBLACK,true),JuBlack2(0,8,PLAYERBLACK,true),
	BingRed1(6,0,PLAYERRED,true),BingRed2(6,2,PLAYERRED,true),BingRed3(6,4,PLAYERRED,true),
	BingRed4(6,6,PLAYERRED,true),BingRed5(6,8,PLAYERRED,true),
	BingBlack1(3,0,PLAYERBLACK,true),BingBlack2(3,2,PLAYERBLACK,true),BingBlack3(3,4,PLAYERBLACK,true),
	BingBlack4(3,6,PLAYERBLACK,true),BingBlack5(3,8,PLAYERBLACK,true),
	MouseRed(9,8,PLAYERRED),MouseBlack(0,0,PLAYERBLACK)
{
	choice=false;
	turn=TURNRED;

	ChX=-1;
	ChY=-1;
	record=-1;

	winner=-1;

	che[0]=&JiangRed;
	che[1]=&JiangBlack;
	che[2]=&ShiRed1;
	che[3]=&ShiRed2;
	che[4]=&ShiBlack1;
	che[5]=&ShiBlack2;
	che[6]=&XiangRed1;
	che[7]=&XiangRed2;
	che[8]=&XiangBlack1;
	che[9]=&XiangBlack2;
	che[10]=&PaoRed1;
	che[11]=&PaoRed2;
	che[12]=&PaoBlack1;
	che[13]=&PaoBlack2;
	che[14]=&MaRed1;
	che[15]=&MaRed2;
	che[16]=&MaBlack1;
	che[17]=&MaBlack2;
	che[18]=&JuRed1;
	che[19]=&JuRed2;
	che[20]=&JuBlack1;
	che[21]=&JuBlack2;
	che[22]=&BingRed1;
	che[23]=&BingRed2;
	che[24]=&BingRed3;
	che[25]=&BingRed4;
	che[26]=&BingRed5;
	che[27]=&BingBlack1;
	che[28]=&BingBlack2;
	che[29]=&BingBlack3;
	che[30]=&BingBlack4;
	che[31]=&BingBlack5;

	Flash();
}

Board::Board(Board &obj)
	:JiangRed(obj.JiangRed),JiangBlack(obj.JiangBlack),
	ShiRed1(obj.ShiRed1),ShiRed2(obj.ShiRed2),
	ShiBlack1(obj.ShiBlack1),ShiBlack2(obj.ShiBlack2),
	XiangRed1(obj.XiangRed2),XiangRed2(obj.XiangRed2),
	XiangBlack1(obj.XiangBlack1),XiangBlack2(obj.XiangBlack2),
	PaoRed1(obj.PaoRed1),PaoRed2(obj.PaoRed2),
	PaoBlack1(obj.PaoBlack1),PaoBlack2(obj.PaoBlack2),
	MaRed1(obj.MaRed1),MaRed2(obj.MaRed2),
	MaBlack1(obj.MaBlack1),MaBlack2(obj.MaBlack2),
	JuRed1(obj.JuRed1),JuRed2(obj.JuRed2),
	JuBlack1(obj.JuBlack1),JuBlack2(obj.JuBlack2),
	BingRed1(obj.BingRed1),BingRed2(obj.BingRed2),BingRed3(obj.BingRed3),
	BingRed4(obj.BingRed4),BingRed5(obj.BingRed5),
	BingBlack1(obj.BingBlack1),BingBlack2(obj.BingBlack2),BingBlack3(obj.BingBlack3),
	BingBlack4(obj.BingBlack4),BingBlack5(obj.BingBlack5),
	MouseRed(obj.MouseRed),MouseBlack(obj.MouseBlack)
{
	choice=false;
	turn=obj.turn;

	ChX=-1;
	ChY=-1;
	record=-1;

	winner=-1;

	che[0]=&JiangRed;
	che[1]=&JiangBlack;
	che[2]=&ShiRed1;
	che[3]=&ShiRed2;
	che[4]=&ShiBlack1;
	che[5]=&ShiBlack2;
	che[6]=&XiangRed1;
	che[7]=&XiangRed2;
	che[8]=&XiangBlack1;
	che[9]=&XiangBlack2;
	che[10]=&PaoRed1;
	che[11]=&PaoRed2;
	che[12]=&PaoBlack1;
	che[13]=&PaoBlack2;
	che[14]=&MaRed1;
	che[15]=&MaRed2;
	che[16]=&MaBlack1;
	che[17]=&MaBlack2;
	che[18]=&JuRed1;
	che[19]=&JuRed2;
	che[20]=&JuBlack1;
	che[21]=&JuBlack2;
	che[22]=&BingRed1;
	che[23]=&BingRed2;
	che[24]=&BingRed3;
	che[25]=&BingRed4;
	che[26]=&BingRed5;
	che[27]=&BingBlack1;
	che[28]=&BingBlack2;
	che[29]=&BingBlack3;
	che[30]=&BingBlack4;
	che[31]=&BingBlack5;
	
	Flash();
}

bool Board::OutChoice()
{
	return choice;
}

BOARD_CHESS Board::OutBOARD()
{
	return BOARD;
}

BOARD_CHESS Board::OutCHESS()
{
	return CHESS;
}

void Board::MouseMove(int PLAYER,int DIRECTION)
{
	switch(PLAYER)
	{
	case PLAYERRED:
		switch(DIRECTION)
		{
		case DIRECTIONUP:
			if(MouseRed.x-1>=0) MouseRed.x-=1;
			break;
		case DIRECTIONDOWN:
			if(MouseRed.x+1<=9) MouseRed.x+=1;
			break;
		case DIRECTIONLEFT:
			if(MouseRed.y-1>=0) MouseRed.y-=1;
			break;
		case DIRECTIONRIGHT:
			if(MouseRed.y+1<=8) MouseRed.y+=1;
			break;
		}
		break;
	case PLAYERBLACK:
		switch(DIRECTION)
		{
		case DIRECTIONUP:
			if(MouseBlack.x-1>=0) MouseBlack.x-=1;
			break;
		case DIRECTIONDOWN:
			if(MouseBlack.x+1<=9) MouseBlack.x+=1;
			break;
		case DIRECTIONLEFT:
			if(MouseBlack.y-1>=0) MouseBlack.y-=1;
			break;
		case DIRECTIONRIGHT:
			if(MouseBlack.y+1<=8) MouseBlack.y+=1;
			break;
		}
		break;
	}
}

void Board::Choose(int PLAYER)
{
	//临时变量
	int i,k;

	//临时棋盘
	BOARD_HIND *t=new BOARD_HIND;

	if(PLAYER==PLAYERRED)
	{
		if(turn==TURNRED)
		{
			for(i=0;i<=31;i++)
				if(MouseRed.x==che[i]->OutX() && MouseRed.y==che[i]->OutY() &&
					che[i]->OutPlayer()==PLAYERRED && che[i]->OutAlive()==true)
				{
					choice=true;
					ChX=MouseRed.x;
					ChY=MouseRed.y;
					record=i;
					break;
				}

			if(choice==true)
				*t=che[record]->hind(BOARD,CHESS);

			for(i=0;i<=9;i++)
				for(k=0;k<=8;k++)
					HIND.a[i][k]=t->a[i][k];
		}
	}

	if(PLAYER==PLAYERBLACK)
	{
		if(turn==TURNBLACK)
		{
			for(i=0;i<=31;i++)
				if(MouseBlack.x==che[i]->OutX() && MouseBlack.y==che[i]->OutY() &&
					che[i]->OutPlayer()==PLAYERBLACK && che[i]->OutAlive()==true)
				{
					choice=true;
					ChX=MouseBlack.x;
					ChY=MouseBlack.y;
					record=i;
					break;
				}

			if(choice==true)
				*t=che[record]->hind(BOARD,CHESS);

			for(i=0;i<=9;i++)
				for(k=0;k<=8;k++)
					HIND.a[i][k]=t->a[i][k];
		}
	}
}

bool Board::ChessMove(int PLAYER)
{
	//临时变量
	int i,k;
	int CORD=-1;
	bool MOVE=false;

	if(PLAYER==PLAYERRED)
	{
		if(turn==TURNRED)
		{
			if(MouseRed.x==ChX && MouseRed.y==ChY)
				Unchoose();
			if((MouseRed.x!=ChX || MouseRed.y!=ChY) &&
				HIND.a[MouseRed.x][MouseRed.y]==true)
			{
				MOVE=true;

				for(i=0;i<=31;i++)
					if(che[i]->OutX()==MouseRed.x && che[i]->OutY()==MouseRed.y &&
						che[i]->OutAlive()==true && che[i]->OutPlayer()==PLAYERBLACK)
					{
						CORD=i;
						break;
					}

				if(CORD!=-1) che[i]->InAlive(false);

				che[record]->InXY(MouseRed.x,MouseRed.y);
			}
			else Unchoose();
		}
	}

	if(PLAYER==PLAYERBLACK)
	{
		if(turn==TURNBLACK)
		{
			if(MouseBlack.x==ChX && MouseBlack.y==ChY)
				Unchoose();
			if((MouseBlack.x!=ChX || MouseBlack.y!=ChY) &&
				HIND.a[MouseBlack.x][MouseBlack.y]==true)
			{
				MOVE=true;

				for(i=0;i<=31;i++)
					if(che[i]->OutX()==MouseBlack.x && che[i]->OutY()==MouseBlack.y &&
						che[i]->OutAlive()==true && che[i]->OutPlayer()==PLAYERRED)
					{
						CORD=1;
						break;
					}

				if(CORD!=-1) che[i]->InAlive(false);

				che[record]->InXY(MouseBlack.x,MouseBlack.y);
			}
			else Unchoose();
		}
	}

	if(MOVE==true)
	{
		switch(turn)
		{
		case TURNRED:
			turn=TURNBLACK;
			break;
		case TURNBLACK:
			turn=TURNRED;
			break;
		}
		choice=false;
	}

	Flash();
	
	if(MOVE==true) return true;
	else return false;
}

void Board::Unchoose()
{
	choice=false;
	ChX=-1;
	ChY=-1;
	record=-1;

	Flash();
}

void Board::Flash()
{
	//临时变量
	int i,k;

	choice=false;
	ChX=-1;
	ChY=-1;
	record=-1;

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		{
			BOARD.a[i][k]=PLAYERNONE;
			CHESS.a[i][k]=NAMENONE;
		}

	for(i=0;i<=31;i++)
		if(che[i]->OutAlive()==true)
		{
			BOARD.a[che[i]->OutX()][che[i]->OutY()]=che[i]->OutPlayer();
			CHESS.a[che[i]->OutX()][che[i]->OutY()]=che[i]->OutChessName();
		}

	Victory();
}

int Board::Victory()
{
	//临时变量
	int i,k;

	if(che[0]->OutAlive()==false)
		winner=WINBLACK;

	if(che[1]->OutAlive()==false)
		winner=WINRED;

	return winner;
}

int Board::OutMouseRedX()
{
	return MouseRed.x;
}

int Board::OutMouseRedY()
{
	return MouseRed.y;
}

int Board::OutMouseBlackX()
{
	return MouseBlack.x;
}

int Board::OutMouseBlackY()
{
	return MouseBlack.y;
}

int Board::OutChX()
{
	return ChX;
}

int Board::OutChY()
{
	return ChY;
}