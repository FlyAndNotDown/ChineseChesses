#pragma once
#include "chess.h"
#include "define.h"

class chess_xiang :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_xiang(int,int,int,bool);
	chess_xiang(void);
	chess_xiang(chess_xiang &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

