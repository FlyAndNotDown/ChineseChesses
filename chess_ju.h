#pragma once
#include "chess.h"
#include "define.h"

class chess_ju :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_ju(int,int,int,bool);
	chess_ju(void);
	chess_ju(chess_ju &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

