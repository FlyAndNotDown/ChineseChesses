#pragma comment(lib,"winmm.lib")  //����PlaySound����������ļ�
#pragma  comment(lib,"Msimg32.lib")  //���ʹ��TransparentBlt��������Ŀ��ļ�

#include<fstream>
using namespace std;
#include<windows.h>
#include<tchar.h>
#include"define.h"
#include "Board.h"
//����l������������¼ʱ��
DWORD TimePre=0,TimeNow=0;  //TimePre��¼��һ�λ�ͼ��ʱ�䣬TimeNow��¼�˴�׼����ͼ��ʱ��

//GDI��ͼDC˵��
HDC hdc=NULL;  //ȫ���豸�����������(GDI)
HDC Bithdc[17];

//��ɫ
COLORREF Red=RGB(255,0,0);
COLORREF White=RGB(255,255,255);

//���ʡ���ˢ��λͼ�����塢��ͼ����DC
HPEN RedMiniLine=CreatePen(PS_SOLID,1,Red);
HPEN RedLine=CreatePen(PS_SOLID,2,Red);
HPEN RedRoughLine=CreatePen(PS_SOLID,4,Red);
HFONT ChuHan=CreateFont
	(
	BLOCKBOARD-2*CHUHANJIE,HALFBLOCKBOARD,0,0,0,0,0,0,
	GB2312_CHARSET,0,0,0,0,TEXT("����")
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

//��������
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
BOOL Game_Init(HWND);  //��Ϸ��Դ��ʼ������
VOID Game_Paint(HWND);  //��ͼ����
BOOL Game_Clean(HWND);  //��Ϸ��Դ������

//������
Board GameBoard,temp;

//�浵��������Ҫ���ļ�
fstream Info,Save;

//�������
int Retract=0;

//WinMain()����
int WINAPI WinMain
	(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow
	)
{
	/*����*/
	HWND hWnd;  //���ھ��
	MSG msg={0};  //��Ϣ

	/*�������*/
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
	wndClass.lpszClassName=_T("˫���й����壬���ߣ�161520311  ������");

	/*����ע��*/
	RegisterClassEx(&wndClass);

	/*���ڴ���*/
	hWnd=CreateWindowEx
		(
			WS_EX_CLIENTEDGE,
			_T("˫���й����壬���ߣ�161520311  ������"),
			_T("˫���й����壬���ߣ�161520311  ������"),
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

	/*���ڵ�ˢ��*/
	/*1�ı䴰�ڵ�λ�úʹ�С*/
	MoveWindow(hWnd,200,50,WINDOW_WIDTH,WINDOW_HIGHT,true);
	/*2��ʾ����*/
	ShowWindow(hWnd,nCmdShow);
	/*3ˢ�´���*/
	UpdateWindow(hWnd);

	/*��Ϸ��Դ��ʼ��*/
	if(!Game_Init(hWnd))
	{
		MessageBox(hWnd,_T("��Դ��ʼ������"),_T("Warning!"),0);
		return FALSE;
	}
	//ѭ�����ű������� 
	PlaySound(_T("��֮ʫ.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);

	MessageBox(NULL,WRITEFORWARD,_T("д��ǰ��"),MB_OK);

	/*��Ϣѭ��*/
	while(msg.message!=WM_QUIT)		//ʹ��whileѭ���������Ϣ����WM_QUIT��Ϣ���ͼ���ѭ��
	{
		if( PeekMessage(&msg,0,0,0,PM_REMOVE))   //�鿴Ӧ�ó�����Ϣ���У�����Ϣʱ�������е���Ϣ�ɷ���ȥ��
		{
			TranslateMessage(&msg);		//���������Ϣת��Ϊ�ַ���Ϣ
			DispatchMessage(&msg);			//�ַ�һ����Ϣ�����ڳ���
		}
		else
		{
			TimeNow = GetTickCount();   //��ȡ��ǰϵͳʱ��
			if(TimeNow-TimePre>=200)        //�ػ�
			{
				InvalidateRect(hWnd, NULL, true);  //�����ػ�
				Game_Paint(hWnd);
			}
		}

		if(GameBoard.Victory()==WINRED)
		{
			MessageBox(NULL,_T("�췽ʤ��!"),_T("����"),MB_OK);
			break;
		}
		if(GameBoard.Victory()==WINBLACK)
		{
			MessageBox(NULL,_T("�ڷ�ʤ��!"),_T("����"),MB_OK);
			break;
		}
	}

	/*�������ע��*/
	UnregisterClass(_T("˫���й����壬���ߣ�161520311  ������"),wndClass.hInstance);

	return 0;
}


/*
	���ڹ��̺���
						*/
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	int count;

	/*����*/
	PAINTSTRUCT paintStruct;  //��¼��ͼ��Ϣ�Ľṹ��

	/*��Ϣ����*/
	switch(message)
	{
	case WM_PAINT:
		hdc=BeginPaint(hwnd,&paintStruct);  //��¼��ͼ��Ϣ��׼����ͼ
		InvalidateRect(hwnd, NULL, true);
		Game_Paint(hwnd);  //��ʼ��ͼ
		EndPaint(hwnd,&paintStruct);  //������ͼ
		ValidateRect(hwnd,NULL);  //���¿ͻ�����ʾ
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

		case VK_RETURN:  //�س�
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

		case VK_SPACE:  //�ո�
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
			MessageBox(NULL,HELP,_T("����"),MB_OK);
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
			MessageBox(NULL,ABOUTME,_T("����"),MB_OK);
			break;
		}
		break;

	case WM_DESTROY:
		Game_Clean(hwnd);  //������Ϸ��Դ
		PostQuitMessage(0);  //��ϵͳ������ֹ����
		break;

	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}


//��Ϸ��Դ��ʼ������
BOOL Game_Init(HWND hwnd)
{
	int i;

	//�����ļ���ʼ��
	Info.open("Info.dat",ios::binary|ios::out|ios::trunc);
	Info.close();
	Info.open("Info.dat",ios::binary|ios::out|ios::app);
	Info.write((char *)&GameBoard,sizeof(GameBoard));
	Info.close();

	//��ȡ�豸����
	hdc=GetDC(hwnd);

	//��������DC
	for(i=0;i<=16;i++)
		Bithdc[i]=CreateCompatibleDC(hdc);

	Game_Paint(hwnd);  //���л�ͼ
	return TRUE;
}


//��Ϸ��ͼ����
VOID Game_Paint(HWND hwnd)
{
	//��ʱ����
	int i,k;

	//�������ݱ���
	BOARD_CHESS boa=GameBoard.OutBOARD();
	BOARD_CHESS che=GameBoard.OutCHESS();

	//��߿�
	SelectObject(hdc,RedRoughLine);

	MoveToEx(hdc,KONG,KONG,NULL);
	LineTo(hdc,KONG,KONG+2*KUANG+9*BLOCKBOARD);

	MoveToEx(hdc,KONG,KONG,NULL);
	LineTo(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG);

	MoveToEx(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG+2*KUANG+9*BLOCKBOARD,NULL);
	LineTo(hdc,KONG,KONG+2*KUANG+9*BLOCKBOARD);

	MoveToEx(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG+2*KUANG+9*BLOCKBOARD,NULL);
	LineTo(hdc,KONG+2*KUANG+8*BLOCKBOARD,KONG);


	//����
	SelectObject(hdc,RedLine);

	for(i=0;i<=9;i++)     //����
	{
		MoveToEx(hdc,KONG+KUANG,KONG+KUANG+i*BLOCKBOARD,NULL);
		LineTo(hdc,KONG+KUANG+8*BLOCKBOARD,KONG+KUANG+i*BLOCKBOARD);
	}

	for(i=0;i<=8;i++)     //����
	{
		MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG,NULL);
		LineTo(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+4*BLOCKBOARD);

		MoveToEx(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+5*BLOCKBOARD,NULL);
		LineTo(hdc,KONG+KUANG+i*BLOCKBOARD,KONG+KUANG+9*BLOCKBOARD);
	}

	//������
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

	//���ӡ�����
	SelectObject(hdc,ChuHan);
	SetTextColor(hdc,Red);
	SetBkMode(hdc,TRANSPARENT);
	TextOut(hdc,KONG+KUANG+BLOCKBOARD,
		KONG+KUANG+4*BLOCKBOARD+CHUHANJIE,_T("����"),4);
	TextOut(hdc,KONG+KUANG+5*BLOCKBOARD,
		KONG+KUANG+4*BLOCKBOARD+CHUHANJIE,_T("����"),4);

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

	//���ƹ��
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


//��Ϸ��Դ������
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
