#pragma once
#include "define.h"

class mouse
{
private:
	int x;
	int y;
	int player;
	friend  class Board;
public:
	//���캯��
	mouse(int,int,int);
	mouse(void);
	mouse(mouse &);

	//���뺯��
	void InXY(int,int);
	void InPlayer(int);

	//�������
	int OutX();
	int OutY();
	int OutPlayer();
};

