#pragma once
#include "chess.h"
#include "define.h"

class chess_bing :
	public chess
{
private:
	int name;
	friend class Board;  //������Ԫ�࣬�������̺���������в���
public:
	//���캯��
	chess_bing(int,int,int,bool);
	chess_bing(void);
	chess_bing(chess_bing &);

	//���Ǹ����еĴ��麯��
	int OutChessName();
	BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS);
};

