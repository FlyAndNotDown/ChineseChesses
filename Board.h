#pragma once
#include<windows.h>
#include "define.h"
#include "chess.h"
#include "chess_jiang.h"
#include "chess_shi.h"
#include "chess_xiang.h"
#include "chess_pao.h"
#include "chess_ma.h"
#include "chess_ju.h"
#include "chess_bing.h"
#include "mouse.h"

class Board
{
private:
	//棋子类
	chess_jiang JiangRed,JiangBlack;
	chess_shi ShiRed1,ShiRed2,ShiBlack1,ShiBlack2;
	chess_xiang XiangRed1,XiangRed2,XiangBlack1,XiangBlack2;
	chess_pao PaoRed1,PaoRed2,PaoBlack1,PaoBlack2;
	chess_ma MaRed1,MaRed2,MaBlack1,MaBlack2;
	chess_ju JuRed1,JuRed2,JuBlack1,JuBlack2;
	chess_bing BingRed1,BingRed2,BingRed3,BingRed4,BingRed5,
		BingBlack1,BingBlack2,BingBlack3,BingBlack4,BingBlack5;

	//棋子类指针
	chess *che[32];

	//光标类
	mouse MouseRed,MouseBlack;

	//信息棋盘
	BOARD_CHESS BOARD;  //红黑势力
	BOARD_CHESS CHESS;  //棋子名字
	BOARD_HIND HIND;

	//是否在选取状态
	bool choice;
	int turn;

	//选取中的棋子信息
	int ChX;
	int ChY;
	int record;

	//胜利
	int winner;

public:
	//构造函数
	Board
	(
		chess_jiang,chess_jiang,
		chess_shi,chess_shi,chess_shi,chess_shi,
		chess_xiang,chess_xiang,chess_xiang,chess_xiang,
		chess_pao,chess_pao,chess_pao,chess_pao,
		chess_ma,chess_ma,chess_ma,chess_ma,
		chess_ju,chess_ju,chess_ju,chess_ju,
		chess_bing,chess_bing,chess_bing,chess_bing,chess_bing,
		chess_bing,chess_bing,chess_bing,chess_bing,chess_bing,
		int
	);
	Board(void);
	
	//拷贝构造函数
	Board(Board &);

	//功能函数
	void MouseMove(int,int);
	void Choose(int);
	void Unchoose();
	bool ChessMove(int);
	void Flash();
	int Victory();

	//输出函数
	bool OutChoice();
	int OutMouseRedX();
	int OutMouseRedY();
	int OutMouseBlackX();
	int OutMouseBlackY();
	BOARD_CHESS OutBOARD();
	BOARD_CHESS OutCHESS();
	int OutChX();
	int OutChY();
};

