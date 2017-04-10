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
	//������
	chess_jiang JiangRed,JiangBlack;
	chess_shi ShiRed1,ShiRed2,ShiBlack1,ShiBlack2;
	chess_xiang XiangRed1,XiangRed2,XiangBlack1,XiangBlack2;
	chess_pao PaoRed1,PaoRed2,PaoBlack1,PaoBlack2;
	chess_ma MaRed1,MaRed2,MaBlack1,MaBlack2;
	chess_ju JuRed1,JuRed2,JuBlack1,JuBlack2;
	chess_bing BingRed1,BingRed2,BingRed3,BingRed4,BingRed5,
		BingBlack1,BingBlack2,BingBlack3,BingBlack4,BingBlack5;

	//������ָ��
	chess *che[32];

	//�����
	mouse MouseRed,MouseBlack;

	//��Ϣ����
	BOARD_CHESS BOARD;  //�������
	BOARD_CHESS CHESS;  //��������
	BOARD_HIND HIND;

	//�Ƿ���ѡȡ״̬
	bool choice;
	int turn;

	//ѡȡ�е�������Ϣ
	int ChX;
	int ChY;
	int record;

	//ʤ��
	int winner;

public:
	//���캯��
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
	
	//�������캯��
	Board(Board &);

	//���ܺ���
	void MouseMove(int,int);
	void Choose(int);
	void Unchoose();
	bool ChessMove(int);
	void Flash();
	int Victory();

	//�������
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

