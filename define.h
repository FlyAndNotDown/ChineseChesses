#pragma once
//结构体
struct BOARD_CHESS
{
	int a[10][9];
};
struct BOARD_HIND
{
	bool a[10][9];
};

//写在前面的话
#define WRITEFORWARD _T("--------------双人中国象棋--------------\n\n作者：南航161520311  黄文麒\n\n需要帮助请按F1\n\nHave Fun!\n\n----------------------------------------------")

//F1帮助信息辅助宏
#define HELP _T("/*************************************************************\n玩法解析：\n双人中国象棋，两个人都使用键盘操作\nP1：光标移动-WSAD 选取键-SPACE键\nP2：光标移动-方向键 选取键-ENTER键\n帮助键：F1\n悔棋：F2\n存档：F3\n读档：F4\n关于：F5\n\n\n\n操作的时候先移动光标到你想选取的棋子的位置按下选取\n键，然后再移动光标到你想移动到的地方，再次按下选取\n键，即可移动棋子到指定位置（不按照规则移动是无法移\n动的），存档的时候，改谁走的，读档完成后还是谁走哦\n*************************************************************/\n")

//F10关于辅助宏
#define ABOUTME _T("/********************************\n\n	  双人中国象棋\n\n********************************/\n\n/********************************\n\n	 作者：黄文麒\n\n        学号：161520311\n\n       电话：15651705969\n\n     邮箱： 461425614@qq.com\n\n********************************/\n\n")

//窗口宽度宏
#define WINDOW_WIDTH 500
//窗口高度宏
#define WINDOW_HIGHT 570

//行列辅助宏
#define HANG 10
#define LIE 9

//棋子名字辅助宏
#define NAMENONE 0
#define NAMEJIANG 1
#define NAMESHI 2
#define NAMEXIANG 3
#define NAMEPAO 4
#define NAMEMA 5
#define NAMEJU 6
#define NAMEBING 7

//玩家信息辅助宏
#define PLAYERNONE 0
#define PLAYERRED 1
#define PLAYERBLACK 2

//回合辅助宏
#define TURNRED 0
#define TURNBLACK 1

//方向辅助宏
#define DIRECTIONUP 0
#define DIRECTIONDOWN 1
#define DIRECTIONLEFT 2
#define DIRECTIONRIGHT 3

//胜利辅助宏
#define WINRED 0
#define WINBLACK 1

//作图辅助宏
//外空部分
#define KONG 30
//边框间隔
#define KUANG 5
//棋盘方块
#define BLOCKBOARD 50
//棋盘方块的一半
#define HALFBLOCKBOARD 25
//棋子方块
#define BLOCKCHESS 40
//棋子方块的一半
#define HALFBLOCKCHESS 20
//棋子与棋盘方块的差值
#define DIF 5
//辅助线--炮、兵空
#define PAOBINGKONG 5
//辅助线--炮、兵长度
#define PAOBINGLONG 8
//楚河汉界文字与边缘差
#define CHUHANJIE 8

//光标尺寸
#define BLOCKMOUSE 30
#define HALFBLOCKMOUSE 15