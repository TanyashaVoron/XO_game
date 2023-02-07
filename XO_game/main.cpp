#include "class_XO_game.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    bool start = 1;
    while (start != 0)
    {
        string s;
        cout <<endl<< "хотите начать новую игру? Введите Yes|No: ";
        cin >> s;
        while (s != "Yes" && s != "No")
        {
            cout << "введены неворректные данные" << endl << "Введите Yes|No: ";
            cin >> s;
        }
        if (s == "No")
        {
            cout << "Возвращайся!";
            start = 0;
        }
        else if (s == "Yes")
        {
            XO_game NewGame;
            NewGame.Play();
        }
    }
}