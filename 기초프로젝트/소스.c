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
void How_To_Use();
void Select_Color();
void Blue_Select();
void Green_Select();
void Grey_Select();
void Red_Select();
void Yello_Select();
void Purple_Select();
void Ok_Select();
void White_Select();

int xy[2] = { 0 };
int x = 320, y = 355; //455-355=100
int color = 0;

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
					if (color == 34)
						Blue_Select();
					else if (color == 32)
						Green_Select();
					else if (color == 36)
						Ok_Select();
					else if (color == 31)
						Red_Select();
					else if (color == 35)
						Purple_Select();
					else if (color == 33)
						Yello_Select();
					else if (color == 37)
						White_Select();
					else if (color == 0)
						Grey_Select();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					Select_Color();

					gotoxy(xy[0], xy[1] + 1);

					printf("\x1b[%dm""■", color);

					if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
						xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
						xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
						xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
						xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
						xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
						xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
						xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
						xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
						xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
						)
					{
						system("cls");
						do
						{
							How_To_Use();
							key = getch();
						} while (key != 13);
						system("cls");
					}
					if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
						xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
						xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
						xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
						xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
						xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
						xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
						xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
						xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
						)
					{
						return 0;
					}
					if (kbhit() == 50 || 51 || 52 || 53 || 32)
						break;
				}
				break;
			}
			case 50:
			{
				while (1) {

					Print_Board_Up();
					if (color == 34)
						Blue_Select();
					else if (color == 32)
						Green_Select();
					else if (color == 36)
						Ok_Select();
					else if (color == 31)
						Red_Select();
					else if (color == 35)
						Purple_Select();
					else if (color == 33)
						Yello_Select();
					else if (color == 37)
						White_Select();
					else if (color == 0)
						Grey_Select();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					Select_Color();
					gotoxy(xy[0], xy[1] + 1);
					printf("\x1b[%dm""▲", color);
					if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
						xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
						xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
						xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
						xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
						xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
						xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
						xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
						xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
						xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
						)
					{
						system("cls");
						do
						{
							How_To_Use();
							key = getch();
						} while (key != 13);
						system("cls");
					}
					if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
						xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
						xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
						xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
						xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
						xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
						xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
						xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
						xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
						)
					{
						return 0;
					}
					if (kbhit() == 49 || 51 || 52 || 53 || 32)
						break;

				}
				break;
			}
			case 51:
			{
				while (1) {

					Print_Board_Up();
					if (color == 34)
						Blue_Select();
					else if (color == 32)
						Green_Select();
					else if (color == 36)
						Ok_Select();
					else if (color == 31)
						Red_Select();
					else if (color == 35)
						Purple_Select();
					else if (color == 33)
						Yello_Select();
					else if (color == 37)
						White_Select();
					else if (color == 0)
						Grey_Select();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					Select_Color();
					gotoxy(xy[0], xy[1] + 1);
					printf("\x1b[%dm""●", color);
					if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
						xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
						xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
						xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
						xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
						xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
						xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
						xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
						xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
						xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
						)
					{
						system("cls");
						do
						{
							How_To_Use();
							key = getch();
						} while (key != 13);
						system("cls");
					}
					if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
						xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
						xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
						xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
						xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
						xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
						xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
						xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
						xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
						)
					{
						return 0;
					}
					if (kbhit() == 49 || 50 || 52 || 53 || 32)
						break;
				}
				break;
			}
			case 52:
			{
				while (1) {

					Print_Board_Up();
					if (color == 34)
						Blue_Select();
					else if (color == 32)
						Green_Select();
					else if (color == 36)
						Ok_Select();
					else if (color == 31)
						Red_Select();
					else if (color == 35)
						Purple_Select();
					else if (color == 33)
						Yello_Select();
					else if (color == 37)
						White_Select();
					else if (color == 0)
						Grey_Select();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					Select_Color();
					gotoxy(xy[0], xy[1] + 1);
					printf("\x1b[%dm""★", color);
					if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
						xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
						xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
						xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
						xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
						xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
						xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
						xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
						xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
						xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
						)
					{
						system("cls");
						do
						{
							How_To_Use();
							key = getch();
						} while (key != 13);
						system("cls");
					}
					if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
						xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
						xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
						xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
						xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
						xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
						xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
						xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
						xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
						)
					{
						return 0;
					}
					if (kbhit() == 50 || 51 || 49 || 53 || 32)
						break;
				}
				break;
			}
			case 53:
			{
				while (1) {

					Print_Board_Up();
					if (color == 34)
						Blue_Select();
					else if (color == 32)
						Green_Select();
					else if (color == 36)
						Ok_Select();
					else if (color == 31)
						Red_Select();
					else if (color == 35)
						Purple_Select();
					else if (color == 33)
						Yello_Select();
					else if (color == 37)
						White_Select();
					else if (color == 0)
						Grey_Select();
					Print_Board_Down();
					Print_Board_Left();
					Print_Board_Right();

					showClickPositionInConsole();
					Select_Color();
					gotoxy(xy[0], xy[1] + 1);
					printf("\x1b[%dm""◆", color);
					if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
						xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
						xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
						xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
						xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
						xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
						xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
						xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
						xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
						xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
						)
					{
						system("cls");
						do
						{
							How_To_Use();
							key = getch();
						} while (key != 13);
						system("cls");
					}
					if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
						xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
						xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
						xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
						xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
						xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
						xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
						xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
						xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
						)
					{
						return 0;
					}
					if (kbhit() == 50 || 51 || 52 || 49 || 32)
						break;
				}
				break;
			}
			case 32:
			{
				showClickPositionInConsole();
				gotoxy(xy[0], xy[1] + 1);
				printf(" ");
				if (xy[0] == 82 && xy[1] == 1 || xy[0] == 82 && xy[1] == 2 || xy[0] == 82 && xy[1] == 3 ||
					xy[0] == 83 && xy[1] == 1 || xy[0] == 83 && xy[1] == 2 || xy[0] == 83 && xy[1] == 3 ||
					xy[0] == 84 && xy[1] == 1 || xy[0] == 84 && xy[1] == 2 || xy[0] == 84 && xy[1] == 3 ||
					xy[0] == 85 && xy[1] == 1 || xy[0] == 85 && xy[1] == 2 || xy[0] == 85 && xy[1] == 3 ||
					xy[0] == 86 && xy[1] == 1 || xy[0] == 86 && xy[1] == 2 || xy[0] == 86 && xy[1] == 3 ||
					xy[0] == 87 && xy[1] == 1 || xy[0] == 87 && xy[1] == 2 || xy[0] == 87 && xy[1] == 3 ||
					xy[0] == 88 && xy[1] == 1 || xy[0] == 88 && xy[1] == 2 || xy[0] == 88 && xy[1] == 3 ||
					xy[0] == 89 && xy[1] == 1 || xy[0] == 89 && xy[1] == 2 || xy[0] == 89 && xy[1] == 3 ||
					xy[0] == 90 && xy[1] == 1 || xy[0] == 90 && xy[1] == 2 || xy[0] == 90 && xy[1] == 3 ||
					xy[0] == 91 && xy[1] == 1 || xy[0] == 91 && xy[1] == 2 || xy[0] == 91 && xy[1] == 3
					)
				{
					system("cls");
					do
					{
						How_To_Use();
						key = getch();
					} while (key != 13);
					system("cls");
				}
				if (xy[0] == 92 && xy[1] == 1 || xy[0] == 92 && xy[1] == 2 || xy[0] == 92 && xy[1] == 3 ||
					xy[0] == 93 && xy[1] == 1 || xy[0] == 93 && xy[1] == 2 || xy[0] == 93 && xy[1] == 3 ||
					xy[0] == 94 && xy[1] == 1 || xy[0] == 94 && xy[1] == 2 || xy[0] == 94 && xy[1] == 3 ||
					xy[0] == 95 && xy[1] == 1 || xy[0] == 95 && xy[1] == 2 || xy[0] == 95 && xy[1] == 3 ||
					xy[0] == 96 && xy[1] == 1 || xy[0] == 96 && xy[1] == 2 || xy[0] == 96 && xy[1] == 3 ||
					xy[0] == 97 && xy[1] == 1 || xy[0] == 97 && xy[1] == 2 || xy[0] == 97 && xy[1] == 3 ||
					xy[0] == 98 && xy[1] == 1 || xy[0] == 98 && xy[1] == 2 || xy[0] == 98 && xy[1] == 3 ||
					xy[0] == 99 && xy[1] == 1 || xy[0] == 99 && xy[1] == 2 || xy[0] == 99 && xy[1] == 3 ||
					xy[0] == 100 && xy[1] == 1 || xy[0] == 100 && xy[1] == 2 || xy[0] == 100 && xy[1] == 3
					)
				{
					return 0;
				}

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

void How_To_Use()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("How_To_Use.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Select_Color()
{
	if (xy[0] == 41 && xy[1] == 1 || xy[0] == 41 && xy[1] == 2 ||
		xy[0] == 42 && xy[1] == 1 || xy[0] == 42 && xy[1] == 2 ||
		xy[0] == 43 && xy[1] == 1 || xy[0] == 43 && xy[1] == 2 ||
		xy[0] == 44 && xy[1] == 1 || xy[0] == 44 && xy[1] == 2)
		color = 34;
	if (xy[0] == 46 && xy[1] == 1 || xy[0] == 46 && xy[1] == 2 ||
		xy[0] == 47 && xy[1] == 1 || xy[0] == 47 && xy[1] == 2 ||
		xy[0] == 48 && xy[1] == 1 || xy[0] == 48 && xy[1] == 2 ||
		xy[0] == 49 && xy[1] == 1 || xy[0] == 49 && xy[1] == 2)
		color = 32;
	if (xy[0] == 51 && xy[1] == 1 || xy[0] == 51 && xy[1] == 2 ||
		xy[0] == 52 && xy[1] == 1 || xy[0] == 52 && xy[1] == 2 ||
		xy[0] == 53 && xy[1] == 1 || xy[0] == 53 && xy[1] == 2 ||
		xy[0] == 54 && xy[1] == 1 || xy[0] == 54 && xy[1] == 2)
		color = 36;
	if (xy[0] == 56 && xy[1] == 1 || xy[0] == 56 && xy[1] == 2 ||
		xy[0] == 57 && xy[1] == 1 || xy[0] == 57 && xy[1] == 2 ||
		xy[0] == 58 && xy[1] == 1 || xy[0] == 58 && xy[1] == 2 ||
		xy[0] == 59 && xy[1] == 1 || xy[0] == 59 && xy[1] == 2)
		color = 31;
	if (xy[0] == 61 && xy[1] == 1 || xy[0] == 61 && xy[1] == 2 ||
		xy[0] == 62 && xy[1] == 1 || xy[0] == 62 && xy[1] == 2 ||
		xy[0] == 63 && xy[1] == 1 || xy[0] == 63 && xy[1] == 2 ||
		xy[0] == 64 && xy[1] == 1 || xy[0] == 64 && xy[1] == 2)
		color = 35;
	if (xy[0] == 66 && xy[1] == 1 || xy[0] == 66 && xy[1] == 2 ||
		xy[0] == 67 && xy[1] == 1 || xy[0] == 67 && xy[1] == 2 ||
		xy[0] == 68 && xy[1] == 1 || xy[0] == 68 && xy[1] == 2 ||
		xy[0] == 69 && xy[1] == 1 || xy[0] == 69 && xy[1] == 2)
		color = 33;
	if (xy[0] == 71 && xy[1] == 1 || xy[0] == 71 && xy[1] == 2 ||
		xy[0] == 72 && xy[1] == 1 || xy[0] == 72 && xy[1] == 2 ||
		xy[0] == 73 && xy[1] == 1 || xy[0] == 73 && xy[1] == 2 ||
		xy[0] == 74 && xy[1] == 1 || xy[0] == 74 && xy[1] == 2)
		color = 37;
	if (xy[0] == 76 && xy[1] == 1 || xy[0] == 76 && xy[1] == 2 ||
		xy[0] == 77 && xy[1] == 1 || xy[0] == 77 && xy[1] == 2 ||
		xy[0] == 78 && xy[1] == 1 || xy[0] == 78 && xy[1] == 2 ||
		xy[0] == 79 && xy[1] == 1 || xy[0] == 79 && xy[1] == 2)
		color = 0;
}

void Blue_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("blue.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 330, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Green_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Green.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 370, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Ok_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Ok.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 405, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
void Red_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Red.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 445, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
void Purple_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Purple.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 485, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
void Yello_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Yello.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 520, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void White_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("White.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 560, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void Grey_Select()
{
	int num = 0;
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);
	// 이미지 로드

	hImage = (HBITMAP)LoadImage(NULL, TEXT("Grey.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//    이미지 출력 부분
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 600, 50, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY); //40단위

	//각종 메모리 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}