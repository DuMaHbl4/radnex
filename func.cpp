#include "main.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

int reg(vector<user> &users)	//функция регистрации
  {
  string tmp;
  string n, m, p;
  unsigned int v, i, d, a, b, r;
  getline(cin, tmp);
  cout << "\n-----Регистрация------\n\n";
  cout << "Введите имя и фамилию через пробел: ";
  getline(cin, n);
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
  circle c(a, b, r);
  users.push_back(user(n, m, p, d, v, i, c));
  /*users[0].show();
  cout << endl;
  users[0].showad();*/
  cout << users[0];
  }

ostream &operator<<(ostream &stream, admin adm) //перегрузка оператора << класса admin
  {
  stream << adm.password << ' ' << adm.mail << ' ' << adm.name ;
  return stream;
  }

istream &operator>>(istream &stream, admin &adm) //перегрузка оператора >> класса admin
  {
  stream >> adm.password >> adm.mail >> adm.name;
  return stream;
  }
  
ostream &operator<<(ostream &stream, user usr)	//перегрузка оператора << класса user
  {
  stream << usr.id << ' ' << usr.idVk << ' ' << usr.idInst << ' ' << usr.circ << ' ' << usr.password << ' ' << usr.mail << ' ' << usr.name << endl;
  return stream;
  } 
 
istream &operator>>(istream &stream, user &usr) //перегрузка оператора >> класса user
  {
  stream >> usr.id >> usr.idVk >> usr.idInst >> usr.circ >> usr.password >> usr.mail >> usr.name;
  return stream;
  } 
  
ostream &operator<<(ostream &stream, circle cir) //перегрузка оператора << класса circle 
  {
  stream << cir.x << ' ' << cir.y << ' ' << cir.rad;
  return stream;
  }
  
istream &operator>>(istream &stream, circle &cir) //перегрузка оператора >> класса circle
  {
  stream >> cir.x >> cir.y >> cir.rad;
  return stream;
  }
int load(char* data, vector<user> &users, admin &adm)	//загрузка данных из файла
  {
  int d=0;
  int i;
  ifstream fi;
  ofstream fo;
  fi.open(data);
  fi >> d;
  if(fi==NULL && d==0)
    {
    fi.close();
    fo.open(data);
    fo << "0" << endl << adm;
    fo.close();
    }
  /*if(!fi)	
    {
    cout << "Ошибка открытия файла\n";
    return 4;
    }*/
  else
    {
    fi >> adm;
    i=0;
  /*if(fi.eof())
    {
    fi.close();
    return 1;
    }*/
    while(!fi.eof())
      { 
      fi>>users[i];
      cout << users[i];
      i++;
      }
    }
  fi.close();
  return 1;
  }
  
int save(char* data, vector<user> &users, admin &adm)
  {
  int i;
  unsigned int d;
  ifstream fi;
  ofstream fo;
  fi.open(data);
  fi >> d;
  fi.close();
  fo.open(data);
  fo << d << endl;
  fo << adm << endl;
  for(i=0; i<users.size(); i++)
    fo << users[i];
  fo.close();
  } 