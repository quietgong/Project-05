#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

void gotoxy(int x, int y); //gotoxy�Լ�
void Print_Menu(); //�޴� ��� �Լ�
void Menu_Cursor(); //�޴� Ŀ�� �����̴� �Լ�
int Move_Cursor_Key(); //�޴� Ŀ���� y���� �����ϴ� �Լ�
void Print_Board(); //�׸��� ��� �Լ�
void Print_Board_Menu(); //�׸��� �޴� ��� �Լ�
void showClickPositionInConsole(); //���콺 �Է½� �ش� ��ǥ�� �������� xy�� �����ϴ� �Լ�
int Select_Menu(); //�޴��� �����ϴ� �Լ�

int xy[2];
int x = 220, y = 355; //455-355=100
int main()
{
	int select;
	char key;
	system("mode con cols=102 lines=38"); //815*612
	Print_Menu();
	select = Move_Cursor_Key();
	switch (select)
	{
	case 355:
		system("cls");
		Print_Board();
		while (1)
		{
			showClickPositionInConsole();
		}
		break;
	case 455:
		return 0;
	}
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Print_Menu()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// �̹��� �ε�

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Start_Menu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    �̹��� ��� �κ�
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	//���� �޸� ����
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);

}

//�޴����� Ŀ���� �����̴� �Լ�
void Menu_Cursor()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// �̹��� �ε�

	hImage = (HBITMAP)LoadImage(NULL, TEXT("selection.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    �̹��� ��� �κ�
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, x, y, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//���� �޸� ����
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
//Menu_Cursor�� x,y��ǥ�� �����ϴ� �Լ�
int Move_Cursor_Key()
{
	char key;
	do {
		Menu_Cursor();
		key = getch();
		switch (key)
		{
		case 72:
			if (y == 355)
			{
				system("cls");
				Print_Menu();
				y == 355;
			}
			else
			{
				system("cls");
				Print_Menu();
				y -= 100;
			}
			break;
		case 80:
			if (y == 455)
			{
				system("cls");
				Print_Menu();
				y == 455;
			}
			else
			{
				system("cls");
				Print_Menu();
				y += 100;
			}
			break;
		}
	} while (key != 13);
	return y;
}
void showClickPositionInConsole()
{
	COORD coord;
	INPUT_RECORD input_record;
	DWORD input_count;
	HANDLE hIN = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hIN, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	while (1)
	{
		ReadConsoleInput(hIN, &input_record, 1, &input_count);

		if (input_record.EventType == MOUSE_EVENT)
		{
			if (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				coord.X = input_record.Event.MouseEvent.dwMousePosition.X;
				coord.Y = input_record.Event.MouseEvent.dwMousePosition.Y;
				xy[0] = coord.X;
				xy[1] = coord.Y;
				break;
			}
		}
	}
}
void Print_Board()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// �̹��� �ε�

	hImage = (HBITMAP)LoadImage(NULL, TEXT("board.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    �̹��� ��� �κ�
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//���� �޸� ����
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
void Print_Board_Menu()
{

}
void Print_HowToUse()
{

}
int Select_Menu()
{

}