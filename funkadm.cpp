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
  
user* delet(user* beg)
  {
  int c;
  bool kont=true;
  string tmp;
  unsigned int id;
  user *pU;
  user *pUs;
  cout << "Введите id человека, которого вы хотите удалить: ";
  while(1)
    {
    cin >> id;
    if(cin.fail())
      {
      cout << "\nВведите число больше 0!\n";
      cin.clear();
      getline(cin, tmp);
      }
    else break;
    }
  pU=beg;
  while(pU!=NULL)
    {
    if(pU->getId()==id)
      {
      pU->showad();
      cout << "Это тот человек которого нужно удалить?\n1. Да\n2. Нет\n";
      while(1)
        {
        cin >> c;
        if(cin.fail() || c<1 || c>2)
          {
          cout << "\nВведите 1 или 2!\n";
          cin.clear();
          getline(cin, tmp);
          }
        else break;
        }
      if(c==1) break;
      else return beg;
      }
    pU=pU->next;
    }
  if(pU==beg)
    {
    if(pU->next==NULL)
      {
      delete beg;
      beg=NULL;
      }
    else
      {
      beg=beg->next;
      delete pU;
      }
    }
  else
    {
   /* if(pU->next==NULL)
      delete pU;
    else
      {*/
      pUs=beg;
      while(pUs->next!=pU) pUs=pUs->next;
      pUs->next=pU->next;
      delete pU;
     // }
    }
  cout << "Аккаунт удален\n";
  return beg;
  }
  
void repass(admin &adm)
  {
  int c;
  string tmp;
  string p;
  string newP;
  while(1)
    {
    cout << "Введите старый пароль: ";
    cin >> p;
    if(adm.pass(p))
      {
      cout << "Введите новый пароль: ";
      cin >> newP;
      adm.rePass(newP);
      break;
      }
    else
      {
      cout << "Неверный пароль!\n1. Ввести еще раз\n2. Выйти в меню\n";
      while(1)
        {
        cin >> c;
        if(cin.fail() || c<1 || c>2)
          {
          cout << "\nВведите 1 или 2!\n";
          cin.clear();
          getline(cin, tmp); 
          }
        else break;  
        }
      if(c==2) break;
      }
    }
  }