#pragma comment(lib,"winmm.lib")  //调用PlaySound函数所需库文件
#pragma  comment(lib,"Msimg32.lib")  //添加使用TransparentBlt函数所需的库文件

#include<fstream>
using namespace std;
#include<windows.h>
#include<tchar.h>
#include"define.h"
#include "Board.h"
//声明l两个变量来记录时间
DWORD TimePre=0,TimeNow=0;  //TimePre记录上一次绘图的时间，TimeNow记录此次准备绘图的时间

//GDI绘图DC说明
HDC hdc=NULL;  //全局设备环境句柄声明(GDI)
HDC Bithdc[17];

//颜色
COLORREF Red=RGB(255,0,0);
COLORREF White=RGB(255,255,255);

//画笔、画刷、位图、字体、贴图兼容DC
HPEN RedMiniLine=CreatePen(PS_SOLID,1,Red);
HPEN RedLine=CreatePen(PS_SOLID,2,Red);
HPEN RedRoughLine=CreatePen(PS_SOLID,4,Red);
HFONT ChuHan=CreateFont
	(
	BLOCKBOARD-2*CHUHANJIE,HALFBLOCKBOARD,0,0,0,0,0,0,
	GB2312_CHARSET,0,0,0,0,TEXT("楷体")
	);
HBITMAP JiangRed=(HBITMAP)LoadImage
	(
	NULL,_T("JiangRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP ShiRed=(HBITMAP)LoadImage
	(
	NULL,_T("ShiRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP XiangRed=(HBITMAP)LoadImage
	(
	NULL,_T("XiangRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP PaoRed=(HBITMAP)LoadImage
	(
	NULL,_T("PaoRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP MaRed=(HBITMAP)LoadImage
	(
	NULL,_T("MaRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP JuRed=(HBITMAP)LoadImage
	(
	NULL,_T("JuRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP BingRed=(HBITMAP)LoadImage
	(
	NULL,_T("BingRed.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP JiangBlack=(HBITMAP)LoadImage
	(
	NULL,_T("JiangBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP ShiBlack=(HBITMAP)LoadImage
	(
	NULL,_T("ShiBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP XiangBlack=(HBITMAP)LoadImage
	(
	NULL,_T("XiangBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP PaoBlack=(HBITMAP)LoadImage
	(
	NULL,_T("PaoBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP MaBlack=(HBITMAP)LoadImage
	(
	NULL,_T("MaBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP JuBlack=(HBITMAP)LoadImage
	(
	NULL,_T("JuBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP BingBlack=(HBITMAP)LoadImage
	(
	NULL,_T("BingBlack.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);
HBITMAP MouseRed=(HBITMAP)LoadImage
	(
	NULL,_T("MouseRed.bmp"),IMAGE_BITMAP,
	BLOCKMOUSE,BLOCKMOUSE,LR_LOADFROMFILE
	);
HBITMAP MouseBlack=(HBITMAP)LoadImage
	(
	NULL,_T("MouseBlack.bmp"),IMAGE_BITMAP,
	BLOCKMOUSE,BLOCKMOUSE,LR_LOADFROMFILE
	);
HBITMAP XuanQu=(HBITMAP)LoadImage
	(
	NULL,_T("XuanQu.bmp"),IMAGE_BITMAP,
	BLOCKCHESS,BLOCKCHESS,LR_LOADFROMFILE
	);

//函数声明
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
BOOL Game_Init(HWND);  //游戏资源初始化函数
VOID Game_Paint(HWND);  //绘图函数
BOOL Game_Clean(HWND);  //游戏资源清理函数

//定义类
Board GameBoard,temp;

//存档功能所需要的文件
fstream Info,Save;

//悔棋变量
int Retract=0;

//WinMain()函数
int WINAPI WinMain
	(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow
	)
{
	/*定义*/
	HWND hWnd;  //窗口句柄
	MSG msg={0};  //消息

	/*窗口设计*/
	WNDCLASSEX wndClass={0};
	wndClass.cbSize=sizeof(WNDCLASSEX);
	wndClass.style=CS_HREDRAW|CS_VREDRAW;
	wndClass.lpfnWndProc=WndProc;
	wndClass.cbClsExtra=0;
	wndClass.cbWndExtra=0;
	wndClass.hInstance=hInstance;
	wndClass.hIcon=(HICON)::LoadImage
		(NULL,_T("ICON.ico"),IMAGE_ICON,0,0,LR_DEFAULTSIZE|LR_LOADFROMFILE);
	wndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName=NULL;
	wndClass.lpszClassName=_T("双人中国象棋，作者：161520311  黄文麒");

	/*窗口注册*/
	RegisterClassEx(&wndClass);

	/*窗口创建*/
	hWnd=CreateWindowEx
		(
			WS_EX_CLIENTEDGE,
			_T("双人中国象棋，作者：161520311  黄文麒"),
			_T("双人中国象棋，作者：161520311  黄文麒"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			WINDOW_WIDTH,
			WINDOW_HIGHT,
			NULL,
			NULL,
			hInstance,
			NULL
		);

	/*窗口的刷新*/
	/*1改变窗口的位置和大小*/
	MoveWindow(hWnd,200,50,WINDOW_WIDTH,WINDOW_HIGHT,true);
	/*2显示窗口*/
	ShowWindow(hWnd,nCmdShow);
	/*3刷新窗口*/
	UpdateWindow(hWnd);

	/*游戏资源初始化*/
	if(!Game_Init(hWnd))
	{
		MessageBox(hWnd,_T("资源初始化出错！"),_T("Warning!"),0);
		return FALSE;
	}
	//循环播放背景音乐 
	PlaySound(_T("鸟之诗.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);

	MessageBox(NULL,WRITEFORWARD,_T("写在前面"),MB_OK);

	/*消息循环*/
	while(msg.message!=WM_QUIT)		//使用while循环，如果消息不是WM_QUIT消息，就继续循环
	{
		if( PeekMessage(&msg,0,0,0,PM_REMOVE))   //查看应用程序消息队列，有消息时将队列中的消息派发出去。
		{
			TranslateMessage(&msg);		//将虚拟键消息转换为字符消息
			DispatchMessage(&msg);			//分发一个消息给窗口程序。
		}
		else
		{
			TimeNow = GetTickCount();   //获取当前系统时间
			if(TimeNow-TimePre>=200)        //重绘
			{
				InvalidateRect(hWnd, NULL, true);  //背景重绘
				Game_Paint(hWnd);
			}
		}

		if(GameBoard.Victory()==WINRED)
		{
			MessageBox(NULL,_T("红方胜利!"),_T("结束"),MB_OK);
			break;
		}
		if(GameBoard.Victory()==WINBLACK)
		{
			MessageBox(NULL,_T("黑方胜利!"),_T("结束"),MB_OK);
			break;
		}
	}

	/*窗口类的注销*/
	UnregisterClass(_T("双人中国象棋，作者：161520311  黄文麒"),wndClass.hInstance);

	return 0;
}


/*
	窗口过程函数
						*/
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	int count;

	/*定义*/
	PAINTSTRUCT paintStruct;  //记录绘图信息的结构体

	/*消息处理*/
	switch(message)
	{
	case WM_PAINT:
		hdc=BeginPaint(hwnd,&paintStruct);  //记录绘图信息，准备绘图
		InvalidateRect(hwnd, NULL, true);
		Game_Paint(hwnd);  //开始绘图
		EndPaint(hwnd,&paintStruct);  //结束绘图
		ValidateRect(hwnd,NULL);  //更新客户区显示
		break;

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_UP:
			GameBoard.MouseMove(PLAYERRED,DIRECTIONUP);
			break;

		case VK_DOWN:
			GameBoard.MouseMove(PLAYERRED,DIRECTIONDOWN);
			break;

		case VK_LEFT:
			GameBoard.MouseMove(PLAYERRED,DIRECTIONLEFT);
			break;

		case VK_RIGHT:
			GameBoard.MouseMove(PLAYERRED,DIRECTIONRIGHT);
			break;

		case 87:  //W
			GameBoard.MouseMove(PLAYERBLACK,DIRECTIONUP);
			break;

		case 83:  //S
			GameBoard.MouseMove(PLAYERBLACK,DIRECTIONDOWN);
			break;

		case 65:  //A
			GameBoard.MouseMove(PLAYERBLACK,DIRECTIONLEFT);
			break;

		case 68:  //D
			GameBoard.MouseMove(PLAYERBLACK,DIRECTIONRIGHT);
			break;

		case VK_RETURN:  //回车
			if(GameBoard.OutChoice()==false)
				GameBoard.Choose(PLAYERRED);
			else
				{
					if(GameBoard.ChessMove(PLAYERRED))
					{
						Retract++;
						Info.open("Info.dat",ios::binary|ios::out|ios::app);
						Info.write((char *)&GameBoard,sizeof(GameBoard));
						Info.close();
					}
				}
			break;

		case VK_SPACE:  //空格
			if(GameBoard.OutChoice()==false)
				GameBoard.Choose(PLAYERBLACK);
			else
				if(GameBoard.ChessMove(PLAYERBLACK))
					{
						Retract++;
						Info.open("Info.dat",ios::binary|ios::out|ios::app);
						Info.write((char *)&GameBoard,sizeof(GameBoard));
						Info.close();
					}
			break;

		case VK_F1:
			MessageBox(NULL,HELP,_T("帮助"),MB_OK);
			break;

		case VK_F2:
			Info.open("Info.dat",ios::binary|ios::in);
			count=0;
			while(!Info.eof())
			{
				if(count==Retract-2)
				{
					Info.read((char *)&GameBoard,sizeof(GameBoard));
					Retract-=2;
					break;
				}
				else
					Info.read((char *)&temp,sizeof(temp));
				count++;
			}
			Info.close();
			break;

		case VK_F3:
			Save.open("Save.dat",ios::binary|ios::out|ios::trunc);
			Save.write((char *)&GameBoard,sizeof(GameBoard));
			Save.close();
			break;

		case VK_F4:
			Save.open("Save.dat",ios::binary|ios::in);
			Save.read((char *)&GameBoard,sizeof(GameBoard));
			Save.close();
			Retract=0;
			Info.open("Info.dat",ios::binary|ios::out|ios::trunc);
			Info.close();
			Info.open("Info.dat",ios::binary|ios::out|ios::app);
			Info.write((char *)&GameBoard,sizeof(GameBoard));
			Info.close();
			break;

		case VK_F5:
			MessageBox(NULL,ABOUTME,_T("关于"),MB_OK);
			break;
		}
		break;

	case WM_DESTROY:
		Game_Clean(hwnd);  //清理游戏资源
		PostQuitMessage(0);  //向系统发出终止请求
		break;

	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}


//游戏资源初始化函数
BOOL Game_Init(HWND hwnd)
{
	int i;

	//悔棋文件初始化
	Info.open("Info.dat",ios::binary|ios::out|ios::trunc);
	Info.close();
	Info.open("Info.dat",ios::binary|ios::out|ios::app);
	Info.write((char *)&GameBoard,sizeof(GameBoard));
	Info.close();

	//获取设备环境
	hdc=GetDC(hwnd);

	//建立兼容DC
	for(i=0;i<=16;i++)
		Bithdc[i]=CreateCompatibleDC(hdc);

	Game_Paint(hwnd);  //进行绘图
	return TRUE;
}


//游戏绘图函数
VOID Game_Paint(HWND hwnd)
{
	//临时变量
	int i,k;

	//棋盘数据变量
	BOARD_CHESS boa=GameBoard.OutBOARD();
	BOARD_CHESS che=GameBoard.OutCHESS();

	//外边框
	SelectObject(hdc,RedRoughLine);

	MoveToEx(hdc,KONG,KONG,NULL);
	LineTo(hdc,KONG,KONG+2*KUANG+9*BLOCKBOARD);

	MoveToEx(hdc,KONG,KONG,NULL);
	LineTo(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG);

	MoveToEx(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG+2*KUANG+9*BLOCKBOARD,NULL);
	LineTo(hdc,KONG,KONG+2*KUANG+9*BLOCKBOARD);

	MoveToEx(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG+2*KUANG+9*BLOCKBOARD,NULL);
	LineTo(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG);


	//棋盘
	SelectObject(hdc,RedLine);

	for(i=0;i<=9;i++)     //横线
	{
		MoveToEx(hdc,KONG+KUANG,KONG+KUANG+i*BLOCKBOARD,NULL);
		LineTo(hdc,KONG+KUANG+8*BLOCKBOARD,KONG+KUANG+i*BLOCKBOARD);
	}

	for(i=0;i<=8;i++)     //竖线
	{
		MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG,NULL);
		LineTo(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+4*BLOCKBOARD);

		MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+5*BLOCKBOARD,NULL);
		LineTo(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+9*BLOCKBOARD);
	}

	//辅助线
	for(i=0;i<=8;i++)
		for(k=0;k<=9;k++)
		{
			if( (i==1 && k==2) || (i==7 && k==2) ||
				(i==2 && k==3) || (i==4 && k==3) || (i==6 && k==3) ||
				(i==1 && k==7) || (i==7 && k==7) ||
				(i==2 && k==6) || (i==4 && k==6) || (i==6 && k==6) )
			{
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG);

				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG);

				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG);

				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG);
			}

			if( (i==0 && k==3) || (i==0 && k==6) )
			{
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG);

				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD+PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG);
			}

			if( (i==8 && k==3) || (i==8 && k==6) )
			{
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG);

				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG-PAOBINGLONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG);
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG,NULL);
				LineTo(hdc,KONG+KUANG+i*BLOCKBOARD-PAOBINGKONG,
					KONG+KUANG+k*BLOCKBOARD+PAOBINGKONG+PAOBINGLONG);
			}

			if( (i==3 && k==0) || (i==3 && k==7) )
			{
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,
					KONG+KUANG+k*BLOCKBOARD,NULL);
				LineTo(hdc,KONG+KUANG+(i+2)*BLOCKBOARD,
					KONG+KUANG+(k+2)*BLOCKBOARD);
			}

			if( (i==5 && k==0) || (i==5 && k==7) )
			{
				MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,
					KONG+KUANG+k*BLOCKBOARD,NULL);
				LineTo(hdc,KONG+KUANG+(i-2)*BLOCKBOARD,
					KONG+KUANG+(k+2)*BLOCKBOARD);
			}
		}

	//楚河、汉界
	SelectObject(hdc,ChuHan);
	SetTextColor(hdc,Red);
	SetBkMode(hdc,TRANSPARENT);
	TextOut(hdc,KONG+KUANG+BLOCKBOARD,
		KONG+KUANG+4*BLOCKBOARD+CHUHANJIE,_T("楚河"),4);
	TextOut(hdc,KONG+KUANG+5*BLOCKBOARD,
		KONG+KUANG+4*BLOCKBOARD+CHUHANJIE,_T("汉界"),4);

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEJIANG)
		{
			SelectObject(Bithdc[0],JiangRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[0],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMESHI)
		{
			SelectObject(Bithdc[1],ShiRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[1],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEXIANG)
		{
			SelectObject(Bithdc[2],XiangRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[2],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEPAO)
		{
			SelectObject(Bithdc[3],PaoRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[3],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEMA)
		{
			SelectObject(Bithdc[4],MaRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[4],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEJU)
		{
			SelectObject(Bithdc[5],JuRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[5],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERRED && che.a[i][k]==NAMEBING)
		{
			SelectObject(Bithdc[6],BingRed);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[6],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEJIANG)
		{
			SelectObject(Bithdc[7],JiangBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[7],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMESHI)
		{
			SelectObject(Bithdc[8],ShiBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[8],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEXIANG)
		{
			SelectObject(Bithdc[9],XiangBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[9],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEPAO)
		{
			SelectObject(Bithdc[10],PaoBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[10],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}
	
	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEMA)
		{
			SelectObject(Bithdc[11],MaBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[11],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEJU)
		{
			SelectObject(Bithdc[12],JuBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[12],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	for(i=0;i<=9;i++)
		for(k=0;k<=8;k++)
		if(boa.a[i][k]==PLAYERBLACK && che.a[i][k]==NAMEBING)
		{
			SelectObject(Bithdc[13],BingBlack);
			TransparentBlt(hdc,KONG+KUANG+k*BLOCKBOARD-HALFBLOCKCHESS,
				KONG+KUANG+i*BLOCKBOARD-HALFBLOCKCHESS,BLOCKCHESS,
				BLOCKCHESS,Bithdc[13],0,0,BLOCKCHESS,BLOCKCHESS,White);
		}

	//绘制光标
	SelectObject(Bithdc[14],MouseRed);
	TransparentBlt(hdc,KONG+KUANG+GameBoard.OutMouseRedY()*BLOCKBOARD,
		KONG+KUANG+GameBoard.OutMouseRedX()*BLOCKBOARD,BLOCKMOUSE,
		BLOCKMOUSE,Bithdc[14],0,0,BLOCKMOUSE,BLOCKMOUSE,White);

	SelectObject(Bithdc[15],MouseBlack);
	TransparentBlt(hdc,KONG+KUANG+GameBoard.OutMouseBlackY()*BLOCKBOARD,
		KONG+KUANG+GameBoard.OutMouseBlackX()*BLOCKBOARD,BLOCKMOUSE,
		BLOCKMOUSE,Bithdc[15],0,0,BLOCKMOUSE,BLOCKMOUSE,White);

	if(GameBoard.OutChoice()==TRUE)
	{
		SelectObject(Bithdc[16],XuanQu);
		TransparentBlt(hdc,KONG+KUANG+GameBoard.OutChY()*BLOCKBOARD-HALFBLOCKBOARD,
			KONG+KUANG+GameBoard.OutChX()*BLOCKBOARD-HALFBLOCKBOARD,BLOCKBOARD,
			BLOCKBOARD,Bithdc[16],0,0,BLOCKCHESS,BLOCKCHESS,White);
	}

	TimePre=GetTickCount();
}


//游戏资源清理函数
BOOL Game_Clean(HWND hwnd)
{
	int i;

	DeleteObject(RedMiniLine);
	DeleteObject(RedLine);
	DeleteObject(RedRoughLine);
	DeleteObject(ChuHan);
	DeleteObject(JiangRed);
	DeleteObject(ShiRed);
	DeleteObject(XiangRed);
	DeleteObject(PaoRed);
	DeleteObject(MaRed);
	DeleteObject(JuRed);
	DeleteObject(BingRed);
	DeleteObject(JiangBlack);
	DeleteObject(ShiBlack);
	DeleteObject(XiangBlack);
	DeleteObject(PaoBlack);
	DeleteObject(MaBlack);
	DeleteObject(JuBlack);
	DeleteObject(BingBlack);
	DeleteObject(MouseRed);
	DeleteObject(MouseBlack);
	DeleteObject(XuanQu);

	for(i=0;i<=16;i++)
		DeleteDC(Bithdc[i]);

	ReleaseDC(hwnd,hdc);

	return true;
}
