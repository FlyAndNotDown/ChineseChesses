#pragma once
#include "chess.h"
#include "define.h"

class chess_jiang :
	public chess
{
private:
	int name;
	friend class Board;  //声明友元类，方便棋盘函数对其进行操作
public:
	//构造函数
	chess_jiang(int,int,int,bool);
	chess_jiang(void);
	chess_jiang(chess_jiang &);

	//覆盖父类中的纯虚函数
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

