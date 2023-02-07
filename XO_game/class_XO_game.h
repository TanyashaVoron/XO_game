#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Step {
	int x, y;
	char s;
};

class XO_game
{
private:
	char arr[3][3];
	char computer;
	char player;

	int Convert(char x, int& y); //при вводе преобразование А-0, В-1 и тд
	void PrintTable();
	void PlaceSymbol(Step step, char s); //символ на поле
	bool CheckStep(Step step); //проверяем, свободно ли поле
	bool CheckWin(); //проверка на победу
	bool CheckDraw(); //проверка на ничью
	void Player(); //ход игрока
	void Computer(); //ход компьютера

public:
	XO_game() 
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[i][j] = '*';
		computer = 'O';
		player = 'X';
	}

	void Play(); 
};