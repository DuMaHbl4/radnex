#include <cstring>
#include <iostream>
#include "main.h"
//#include "person.h"
using namespace std;

/**меню
@param data - имя файла со всей информацией о пользователях*/
int menu(char* data)
  {
  unsigned int id;
  int c=1;
  admin adm;
  user *pUs;	//дополнительный указатель на класс юзера
  user *pU;	//указатель на авторизовавшегося юзера
  user *beg;	//указатель на начало списка
  beg=load(data, adm);	//функция загрузки из файла 
  int i;
  unsigned int u=0;
  string tmp;
  if(beg==NULL)
    {
    cout<<"Добро пожаловать. Мы рады приветствовать Вас в RADNEX. Вы наш первый пользователь.\n";
    beg=reg(id, beg, data);	//функция регистрации
    beg->showad();
    pU=beg;
    while(pU->next!=NULL)
      if(id==pU->getId()) break;
    c=2;
    }
    cout<<"\n-----Добро пожаловать-----\n\n";
    while(1)
      {
      switch(c)
        {	
        case 1:
          while(1)
            {
            if(beg==NULL)
              {
              beg=load(data, adm);
              }
            cout<<"1. Зарегистрироваться\n2. Авторизоваться\n3. Выйти из программы\n";
            while(1)
              {
              cin>>i;
              if(cin.fail())
                {
                cin.clear();
                getline(cin, tmp);
                cout << "\nВведите одну из цифр от 0 до 2!\n";
                }
              else break;
              }
              cin.clear();
              while(cin.get()!='\n');
            switch(i)
              {
              case 1:
                beg=reg(u, beg, data);	//функция регистрации
                break;
              case 2:
                u=avt(beg, adm); 	//функция авторизации
                break;
              case 3:
                c=4;
                break;
              default:
                cout<<"\n\nВведите одну из цифр от 0 до 2!\n";
              }
            if(c==4) break;
            if(u!=0)
              {
              if(u==1)	//если авторизовался админ, то переходим в меню админа
                {
                c=3;
                break;
                }
              else
                {
                pU=beg;
                while(pU!=NULL)	//выбор указателя на авторизовавшегося пользователя
                  {
                  if(u==pU->getId()) break;
                  pU=pU->next;
                  }
                c=2;
                break;
                }
              } 
            } 
            break;
        case 2:
          while(1)
            {
            cout<<"\n-----Главное меню-----\n\n";
            hello(beg, pU);	//показ людей, отправивших привет
            pU->clearHi();
            cout << "1. Изменить местоположение\n2. Изменить радиус\n3. Показать списсок людей рядом\n4. Найстройки аккаунта\n5. Выйти из аккаунта\n6. Выйти из программы\n";
            while(1)
              {
              cin>>i;
              if(cin.fail())
                {
                cin.clear();
                getline(cin, tmp);
                cout << "\nВведите одну из цифр от 1 до 6!\n";
                }
              else break;
              }
            switch(i)
              {
              case 1:	//изменение координат
                {
                int a, b;
                cout << "Введите новые координаты\nx=";
                while(1)
                  {
                  cin >> a;
                  if(cin.fail())
                    {
                    cin.clear();
                    getline(cin, tmp);
                    cout << "\nВведите целое число!\n";
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
                    cout << "\nВведите целое число!\n";
                    }
                  else break;
                  }
                cout << endl;
                pU->circ.reCoord(a,b);
                break;
                } 
              case 2:	//изменение радиуса
                {
                int r; 
                cout << "Введите новый радиус\n";
                while(1)
                  {
                  cin >> r;
                  if(cin.fail())
                    {
                    cin.clear();
                    getline(cin, tmp);
                    cout << "Введите целое число!\n";
                    }
                  else break;
                  } 
                pU->circ.reRad(r);
                break;
                }
              case 3:
                showr(beg, pU);	//функция показа списка людей рядом
                break;
              case 4:
                beg=setting(c, beg, pU);	//функция настройки аккаунта
                break;	
              case 5:
                save(data, beg, adm);
                pU=beg;
                while(pU!=NULL)
                  {
                  pUs=pU;
                  delete pU;
                  pU=pUs->next;
                  }
                beg=NULL;
                u=0;
                c=1;
                break;
              case 6:
                c=4;
                break;
              default: cout<<"\nВведите одну из цифр от 1 до 6!\n";	
              }
            if(c!=2) break;
            }
          break; 
        case 3:
          while (1)
            {
            cout<<"\n-----Меню админа-----\n\n";
            cout<<"1. Поиск пользователя по id\n2. Удаление пользователя по id\n3. Просмотр всех пользователей\n4. Изменить пароль\n5. Выйти из аккаунта админа\n6. Выйти из прогаммы"<<endl;
            while(1)
              {
              cin>>i;
              if(cin.fail())
                {
                cin.clear();
                getline(cin, tmp);
                cout << "\nВведите одну из цифр от 1 до 6!\n";
                }
              else break;
              }
            switch (i)
              {
              case 1:
                poisk(beg);
                break;
              case 2:
                beg=delet(beg);
                break;
              case 3:
                pokas(beg);
                break;
              case 4:
                repass(adm);
                break;
              case 5:
                save(data, beg, adm);
                pU=beg;
                while(pU!=NULL)
                  {
                  pUs=pU;
                  delete pU;
                  pU=pUs->next;
                  }
                beg=NULL;
                u=0;
                c=1;
                break;
              case 6:
                c=4;
                break;
              default: cout<<"\nВведите одну из цифр от 1 до 5!\n";	
              }
            if(c!=3) break;
          }
          break;
        case 4:
          save(data, beg, adm);
          return 0;
        }
    }
  }

