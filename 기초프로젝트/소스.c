#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(int x, int y); //gotoxy�Լ�
void Print_Menu(); //�޴� ��� �Լ�
int Menu_Cursor(); //�޴� Ŀ�� �����̴� �Լ�
void Move_Cursor_Key(char key, int *x1, int *y1); //�޴� Ŀ���� y���� �����ϴ� �Լ�
void Print_Quad_Board(); //�簢 �׸��� ��� �Լ�
void Print_Baduk_Board(); //�ٵ��� �׸��� ��� �Լ�
void Print_Circle_Board(); //���� �׸��� ��� �Լ�
void Print_Board_Menu(); //�׸��� �޴� ��� �Լ�
void showClickPositionInConsole(); //���콺 �Է½� �ش� ��ǥ�� �������� xy�� �����ϴ� �Լ�
void Input_Data(); //�޸��忡 �����͸� �Է��ϴ� �Լ�
int Select_Menu(); //�޴��� �����ϴ� �Լ�

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
int Menu_Cursor() 
{
	char key;
	int x = 57, y = 21;
	do {
		gotoxy(x, y);
		printf("��");
		key = getch();
		printf("\b "); //��ĭ ���� ���ڿ� ������ �־��༭ ���� ��� ����
		Move_Cursor_Key(key, &x, &y); //Ŀ���� y��ǥ���� �������ִ� �Լ� ���
	} while (key != 13); //���Ͱ� �ԷµǸ� y���� �������ְ� ����
	return y;
}
//Menu_Cursor�� x,y��ǥ�� �����ϴ� �Լ�
void Move_Cursor_Key(char key, int *x1, int *y1)
{
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 == 20) //�����Ű�� �ִ밪�� �Ѿ�� �� ������ �̵�
			*y1 = 24;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 == 25) //�����Ű�� �ִ밪�� �Ѿ�� �� ���� �̵�
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
void Print_Board_Menu() //�׸��� �޴� ��� �Լ�
{
	for (int i = 0; i < 40; i++)
		printf("=");
	printf("�ؿ��ϴ� ����� Ű����� �Է��� �ּ����");
	for (int i = 0; i < 40; i++)
		printf("=");
	gotoxy(41, 2);
	printf("1.��\t2.��\t3.��\t4.��\t5.��\n");
	gotoxy(41, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); printf("6.����\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); printf("7.�Ķ�\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); printf("8.��\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); printf("9.����\t");
	printf("0.����\n");
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
	fputc("��", fp);
}
int Select_Menu()
{
	char key;
	key = getchar();
	if (key == 80)
		printf("��");
}

