#pragma once
#include "chess.h"
#include "define.h"

class chess_jiang :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_jiang(int,int,int,bool);
	chess_jiang(void);
	chess_jiang(chess_jiang &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

