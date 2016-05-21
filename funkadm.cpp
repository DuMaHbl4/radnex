#include "main.h"
#include <iostream>
using namespace std;
  
void poisk(user *beg) //поиск пользователя
  {
  bool kont=false;
  unsigned int n;
  string tmp;
  user *pU;
  cout<<"Введите уникальный id пользователя, которого Вы хотите найти: "<<endl;
  while(1)
    {
    cin >> n;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);    
      cout << "\nВведите число!\n";
      }
    else break;
    }
  pU=beg;
  while(pU!=NULL)
    {
    if(n==pU->getId())
      {
      pU->showad();
      kont=true;
      break;
      }
    pU=pU->next;
    }
  if(!kont) cout<<"Не найдено"<<endl;
  }

void pokas(user *beg) //вывод всего списка пользователей на экран
  {
  if(beg==NULL) cout << "\nСписок пуст!\n";
  else
    {
    user *pU;
    pU=beg;
    while(pU!=NULL)
      {
      pU->showad();
      pU=pU->next;
      }
    }
  }