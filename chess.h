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
	//���캯��
	chess(int,int,int,bool);
	chess(void);
	chess(chess &);

	//���뺯��
	void InXY(int,int);
	void InPlayer(int);
	void InAlive(bool);

	//�������
	int OutX();
	int OutY();
	int OutPlayer();
	bool OutAlive();

	//�麯��(���ݲ�ͬ�����ӱ仯)(����ֵΪһ������)
	virtual int OutChessName()=0;
	virtual BOARD_HIND hind(BOARD_CHESS,BOARD_CHESS)=0;
};

