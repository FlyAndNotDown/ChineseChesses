#pragma once
#include "chess.h"
#include "define.h"

class chess_shi :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_shi(int,int,int,bool);
	chess_shi(void);
	chess_shi(chess_shi &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

