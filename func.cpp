#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int reg(vector<user> &users)
  {
  string tmp;
  string n, m, p;
  unsigned int v, i, a, b, r;
  cout << "\n-----Регистрация------\n\n";
  cout << "Введите имя и фамилию через пробел: ";
  cin >> n;
  cout << "\nВведите Email: ";
  cin >> m;
  cout << "\nВведите пароль: ";
  cin >> p;
  cout << "\nВведите ваш id Вконтакте: ";
  while(1)
    {
    cin >> v;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  cout << "\nВведите ваш id in100gram: ";
  while(1)
    {
    cin >> i;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  cout << "\nВведите координаты вашего местоположения\nx=";
  while(1)
    {
    cin >> a;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  cout << "\ny=";
  while(1)
    {
    cin >> b;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  cout << "\nВведите расстояние в радиусе которого вы хотите искать людей: ";
  while(1)
    {
    cin >> r;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  }