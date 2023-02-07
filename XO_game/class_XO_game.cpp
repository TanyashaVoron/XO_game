#include "class_XO_game.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int XO_game::Convert(char x, int& y) 
{
	y--;
	if (x == 'A') return 0;
	if (x == 'B') return 1;
	if (x == 'C') return 2;
}

void XO_game::PrintTable()
{
	cout << "  A B C" << endl;
	for (int i = 0; i < 3; i++)
		cout << i+1 << " " << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
}

void XO_game::PlaceSymbol(Step step,char s)
{
     arr[step.x][step.y] = s;
}

bool XO_game::CheckStep(Step step) 
{
	return (arr[step.x][step.y] == '*');
}

bool XO_game::CheckWin() 
{
	for (int i = 0; i < 3; i++) 
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] != '*') return 1;
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != '*') return 1;
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2]!='*') return 1;
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[0][2]!='*') return 1;
	return 0;
}

bool XO_game::CheckDraw()
{
	bool flag = 1;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++) 
		{
			Step step;
			step.x = i;
			step.y = j;
			if (CheckStep(step) == 1) flag = 0;
		}
	return flag;
}

void XO_game::Player()
{
	Step step;
	PrintTable();
	char x;
	char y;
	cout << "сделайте ход" << endl << "введите координаты поля(буква(заглавная англ),цифра): ";
	cin >> x >> y;
	int b = y-48;
	step.y = Convert(x, b);
	step.x = b;

	while ((step.y < 0 || step.y>2) || (x != 'A' && x != 'B' && x != 'C') || !CheckStep(step) || (y!='1' && y != '2' && y != '2'))
	{
		cout << "введены некорректные данные" << endl;
		cout << "введите координаты поля (буква(заглавная англ),цифра) через пробел: ";
		cin >> x >> y;

		int b = y-48;
		step.y = Convert(x, b);
		step.x = y;
	}
	PlaceSymbol(step, player);
}

void XO_game::Computer() 
{
	Step step2;
	do{
		step2.x = rand() % 3;
		step2.y = rand() % 3;
	} while (!CheckStep(step2));
	PlaceSymbol(step2, computer);
}

void XO_game::Play()
{
	cout << "За какую фигуру вы хотите играть? (Х или О) введите ее с заглавной буквы на англ: ";
	cin >> player;
	while (player != 'X' && player != 'O') 
	{
		cout << "введены некорректные данные" << endl << "введите(Х или О) с заглавной буквы на англ : ";
		cin >> player;
	}
	if (player == 'X') computer = 'O';
	if (player == 'O') computer = 'X';
	
	int flag = 1; //первый ходит игрок
	if (rand() % 2 == 0) flag *= -1; //первый ходит комп
	do{
		if (flag == 1) Player();
		if (flag == -1) Computer();
		flag *= -1;
	} while (CheckWin()==0 && CheckDraw()==0);

	PrintTable();
	if (CheckDraw() == 1) cout << "Ничья!" << endl;
	else {
		if (flag == -1) cout << "Поздравляю! Вы победили!" << endl;
		else cout << "Вы проиграли" << endl;
	}
}