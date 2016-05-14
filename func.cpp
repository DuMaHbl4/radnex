#include "main.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

user* reg(unsigned int &id, user *beg, char* data)	//функция регистрации
  {
  user *pUs;
  user *pU;
  string tmp;
  string n, m, p;
  unsigned int v, i, d, a, b, r;
  ifstream fi;
  fi.open(data);
  fi >> d;
  fi.close();
  d++; 
  //getline(cin, tmp);
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
  pU=new user(n, m, p, d, v, i, c);
  cout<<(*pU);
  pUs=beg;
  while(pUs!=NULL)
    pUs=pUs->next;
  if(beg==NULL) beg=pU;
  else pUs=pU;
  //pUs->next=NULL;
  //if(beg==NULL) beg=pU;
  beg->showad();
  return (beg);
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
  stream << usr.id << ' ' << usr.idVk << ' ' << usr.idInst << ' ' << usr.circ << ' ' << usr.password << ' ' << usr.mail << ' ' << usr.name;
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
user* load(char* data, admin &adm)	//загрузка данных из файла
  {
  user *beg=NULL, *pU, *end=NULL;
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
  else
    {
    fi >> adm;
    i=0;
    while(fi)
      {
      pU=new user; 
      fi>>(*pU);
      if(pU->getId()==0) break;
      if(beg==NULL) beg=pU;
      else end->next=pU;
      end=pU;
      end->next=NULL;
      }
    }
  fi.close();
  return beg;
  }
  
int save(char* data, user *beg , admin &adm)
  {
  user u;
  user *pU;
  int i;
  unsigned int d;
  ifstream fi;
  ofstream fo;
  fi.open(data);
  fi >> d;
  fi.close();
  fo.open(data);
  fo << d << endl;
  fo << adm;
  //beg->showad();
  //(*beg).showad();
  pU=beg;
  while(pU!=NULL)
    {
    (*pU).showad();
    fo<<endl<<(*pU);
    pU=pU->next;
    }
  fo.close();
  } 
