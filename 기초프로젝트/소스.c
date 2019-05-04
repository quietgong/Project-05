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
	while (1)
	{
		showClickPositionInConsole();
		gotoxy(xy[0], xy[1]+1);
		printf("��");
		Input_Data();
	}
	/*
	int menu;
	system("mode con cols=120 lines=40"); //�ܼ�â ũ�⸦ �����ϴ� ��ɾ� (cols=����, lines=����)
	Print_Menu();
	menu=Menu_Cursor();
	return 0;
	*/
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Print_Menu()
{
	gotoxy(60, 20); printf("�� �� ��");
	gotoxy(60, 21); printf("�簢 �׸���");
	gotoxy(60, 22); printf("�ٵ��� �׸���");
	gotoxy(60, 23); printf("���� �׸���");
	gotoxy(60, 24); printf("����");
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
void Print_Board_Menu()
{

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

}