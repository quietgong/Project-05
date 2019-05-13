#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(int x, int y); //gotoxy함수
void Print_Menu(); //메뉴 출력 함수
int Menu_Cursor(); //메뉴 커서 움직이는 함수
void Move_Cursor_Key(char key, int *x1, int *y1); //메뉴 커서의 y값을 변경하는 함수
void Print_Quad_Board(); //사각 그림판 출력 함수
void Print_Baduk_Board(); //바둑판 그림판 출력 함수
void Print_Circle_Board(); //원형 그림판 출력 함수
void Print_Board_Menu(); //그림판 메뉴 출력 함수
void showClickPositionInConsole(); //마우스 입력시 해당 좌표를 전역변수 xy에 저장하는 함수
void Input_Data(); //메모장에 데이터를 입력하는 함수
int Select_Menu(); //메뉴를 선택하는 함수

int xy[2];

int main()
{
	int menu;
	while (1)
	{
		Print_Menu();
		menu = Menu_Cursor();
	}
	return 0;	
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
int Menu_Cursor() 
{
	char key;
	int x = 57, y = 21;
	do {
		gotoxy(x, y);
		printf("▶");
		key = getch();
		printf("\b "); //한칸 뒤의 문자에 공백을 넣어줘서 지난 출력 제거
		Move_Cursor_Key(key, &x, &y); //커서의 y좌표값을 변경해주는 함수 출력
	} while (key != 13); //엔터가 입력되면 y값을 리턴해주고 종료
	return y;
}
//Menu_Cursor의 x,y좌표를 변경하는 함수
void Move_Cursor_Key(char key, int *x1, int *y1)
{
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 == 20) //↑방향키의 최대값을 넘어가면 맨 밑으로 이동
			*y1 = 24;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 == 25) //↓방향키의 최대값을 넘어가면 맨 위로 이동
			*y1 = 21;
		break;
	default:
		return;
	}
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
void Print_Quad_Board()
{

}
void Print_Baduk_Board()
{

}
void Print_Circle_Board()
{

}
void Print_Board_Menu() //그림판 메뉴 출력 함수
{
	for (int i = 0; i < 40; i++)
		printf("=");
	printf("※원하는 기능을 키보드로 입력해 주세요※");
	for (int i = 0; i < 40; i++)
		printf("=");
	gotoxy(41, 2);
	printf("1.□\t2.■\t3.△\t4.▲\t5.ㅡ\n");
	gotoxy(41, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); printf("6.빨강\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); printf("7.파랑\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); printf("8.흰\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); printf("9.검정\t");
	printf("0.종료\n");
	gotoxy(1, 4);
	for (int i = 0; i < 120;i++)
		printf("=");
}
void Print_HowToUse()
{

}
void Input_Data()
{
	FILE *fp = fopen("result.txt", "wt");
	fputc("□", fp);
}
int Select_Menu()
{
	char key;
	key = getchar();
	if (key == 80)
		printf("□");
}

