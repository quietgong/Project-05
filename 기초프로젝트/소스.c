#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)

void gotoxy(int x, int y); //gotoxy함수
void Print_Menu(); //메뉴 출력 함수
void Menu_Cursor(); //메뉴 커서 움직이는 함수
int Move_Cursor_Key(); //메뉴 커서의 y값을 변경하는 함수
void showClickPositionInConsole(); //마우스 입력시 해당 좌표를 전역변수 xy에 저장하는 함수
void Print_Board_Up();
void Print_Board_Down();
void Print_Board_Left();
void Print_Board_Right();
void Input_Data();

int xy[2] = { 0 };
int x = 320, y = 355; //455-355=100

int main()
{
	int select;
	char key;
	system("mode con cols=100 lines=38"); //815*612
	Print_Menu();
	select = Move_Cursor_Key();
	switch (select)
	{
	case 355:
		system("cls");
		//Print_Board();
		while (1)
		{
			Print_Board_Up();
			Print_Board_Down();
			Print_Board_Left();
			Print_Board_Right();

			key = getch();
			switch (key)
			{
			case 49:
			{
				while (1) {
					
					Print_Board_Up();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					gotoxy(xy[0], xy[1] + 1);
					Input_Data();
					printf("□");
					if (kbhit())
					{
						key = getch();
						if (key == 32)
							break;
					}
				}
				break;
			}
			case 50:
			{
				while (1) {

					Print_Board_Up();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					gotoxy(xy[0], xy[1] + 1);
					Input_Data();
					printf("△");
					if (_kbhit())
					{	
						key = getch();
						if (key == 32)
							break;
					}
				}
				break;
			}
			case 51:
			{
				while (1) {

					Print_Board_Up();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					gotoxy(xy[0], xy[1] + 1);
					Input_Data();
					printf("○");
					if (!_kbhit())
					{
						key = getch();
						if (key == 32)
							break;
					}
				}
				break;
			}
			case 52:
			{
				while (1) {

					Print_Board_Up();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					gotoxy(xy[0], xy[1] + 1);
					Input_Data();
					printf("☆");
					if (!_kbhit())
					{
						key = getch();
						if (key == 32)
							break;
					}
				}
				break;
			}
			case 53:
			{
				while (1) {

					Print_Board_Up();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					gotoxy(xy[0], xy[1] + 1);
					Input_Data();
					printf("◇");
					if (!_kbhit())
					{
						key = getch();
						if (key == 32)
							break;
					}
				}
				break;
			}
			case 32:
			{
				showClickPositionInConsole();
				gotoxy(xy[0], xy[1] + 1);
				printf(" ");
				break;
			}
			case 13:
				return 0;
			}
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
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Start_Menu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

//메뉴에서 커서를 움직이는 함수
void Menu_Cursor()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("selection.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, x, y, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
//Menu_Cursor의 x,y좌표를 변경하는 함수
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

void Print_Board_Down()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("board_down.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 153, 545, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
void Print_Board_Up()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("board_up.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 153, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Print_Board_Left()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("board_left.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Print_Board_Right()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("board_right.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 737, 93, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}


void Input_Data()
{
	int i;
	FILE* fp = fopen("result.txt", "a");
	
	for (i = 0; i < xy[1]-6; i++)
		fputs("\n", fp);
	for (i = 0; i < xy[0]-22; i++)
		fputs(" ", fp);

	fputs("□", fp);
}