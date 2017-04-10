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
	//构造函数
	mouse(int,int,int);
	mouse(void);
	mouse(mouse &);

	//输入函数
	void InXY(int,int);
	void InPlayer(int);

	//输出函数
	int OutX();
	int OutY();
	int OutPlayer();
};

