#pragma once
#include "chess.h"
#include "define.h"

class chess_pao :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_pao(int,int,int,bool);
	chess_pao(void);
	chess_pao(chess_pao &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

