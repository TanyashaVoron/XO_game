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

	int Convert(char x, int& y); //��� ����� �������������� �-0, �-1 � ��
	void PrintTable();
	void PlaceSymbol(Step step, char s); //������ �� ����
	bool CheckStep(Step step); //���������, �������� �� ����
	bool CheckWin(); //�������� �� ������
	bool CheckDraw(); //�������� �� �����
	void Player(); //��� ������
	void Computer(); //��� ����������

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