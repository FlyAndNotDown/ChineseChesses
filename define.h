#pragma once
//�ṹ��
struct BOARD_CHESS
{
	int a[10][9];
};
struct BOARD_HIND
{
	bool a[10][9];
};

//д��ǰ��Ļ�
#define WRITEFORWARD _T("--------------˫���й�����--------------\n\n���ߣ��Ϻ�161520311  ������\n\n��Ҫ�����밴F1\n\nHave Fun!\n\n----------------------------------------------")

//F1������Ϣ������
#define HELP _T("/*************************************************************\n�淨������\n˫���й����壬�����˶�ʹ�ü��̲���\nP1������ƶ�-WSAD ѡȡ��-SPACE��\nP2������ƶ�-����� ѡȡ��-ENTER��\n��������F1\n���壺F2\n�浵��F3\n������F4\n���ڣ�F5\n\n\n\n������ʱ�����ƶ���굽����ѡȡ�����ӵ�λ�ð���ѡȡ\n����Ȼ�����ƶ���굽�����ƶ����ĵط����ٴΰ���ѡȡ\n���������ƶ����ӵ�ָ��λ�ã������չ����ƶ����޷���\n���ģ����浵��ʱ�򣬸�˭�ߵģ�������ɺ���˭��Ŷ\n*************************************************************/\n")

//F10���ڸ�����
#define ABOUTME _T("/********************************\n\n	  ˫���й�����\n\n********************************/\n\n/********************************\n\n	 ���ߣ�������\n\n        ѧ�ţ�161520311\n\n       �绰��15651705969\n\n     ���䣺 461425614@qq.com\n\n********************************/\n\n")

//���ڿ�Ⱥ�
#define WINDOW_WIDTH 500
//���ڸ߶Ⱥ�
#define WINDOW_HIGHT 570

//���и�����
#define HANG 10
#define LIE 9

//�������ָ�����
#define NAMENONE 0
#define NAMEJIANG 1
#define NAMESHI 2
#define NAMEXIANG 3
#define NAMEPAO 4
#define NAMEMA 5
#define NAMEJU 6
#define NAMEBING 7

//�����Ϣ������
#define PLAYERNONE 0
#define PLAYERRED 1
#define PLAYERBLACK 2

//�غϸ�����
#define TURNRED 0
#define TURNBLACK 1

//��������
#define DIRECTIONUP 0
#define DIRECTIONDOWN 1
#define DIRECTIONLEFT 2
#define DIRECTIONRIGHT 3

//ʤ��������
#define WINRED 0
#define WINBLACK 1

//��ͼ������
//��ղ���
#define KONG 30
//�߿���
#define KUANG 5
//���̷���
#define BLOCKBOARD 50
//���̷����һ��
#define HALFBLOCKBOARD 25
//���ӷ���
#define BLOCKCHESS 40
//���ӷ����һ��
#define HALFBLOCKCHESS 20
//���������̷���Ĳ�ֵ
#define DIF 5
//������--�ڡ�����
#define PAOBINGKONG 5
//������--�ڡ�������
#define PAOBINGLONG 8
//���Ӻ����������Ե��
#define CHUHANJIE 8

//���ߴ�
#define BLOCKMOUSE 30
#define HALFBLOCKMOUSE 15