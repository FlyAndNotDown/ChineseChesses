#pragma once
#include "define.h"

class chess
{
protected:
	int x;
	int y;
	bool alive;
	int player;
public:
	//构造函数
	chess(int,int,int,bool);
	chess(void);
	chess(chess &);

	//输入函数
	void InXY(int,int);
	void InPlayer(int);
	void InAlive(bool);

	//输出函数
	int OutX();
	int OutY();
	int OutPlayer();
	bool OutAlive();

	//虚函数(根据不同的棋子变化)(返回值为一张棋盘)
	virtual int OutChessName()=0;
	virtual BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS)=0;
};

