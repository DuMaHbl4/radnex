#include <cstring>
#include <vector>
#include <iostream>
#include "main.h"
#include "person.h"
using namespace std;

int menu(char* data)
  {
  vector<user> users;
  //load(char* data, users);	//функция загрузки вектора из файла 
  int i;
  int u=0;
  int c=1;
  string tmp;
  if(users.size()==0)
    {
    cout<<"Добро пожаловать. Мы рады приветствовать Вас в RADNEX. Вы наш первый пользователь.\n";
    reg(users);	//функция регистрации
    }
    cout<<"\n-----Добро пожаловать-----\n\n";
    while(1)
      {
      switch(c)
        {	
        case 1:
          while(1)
            {
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
            switch(i)
              {
              case 1:
                //u=reg(users);	//функция регистрации
                if(u>=0) c=2;	//в случае уданой регистрации возвращается номер элемнта вектора, который >=0
                break;
              case 2:
                //u=avt(users); 	//функция авторизации
                if(u>=0) c=2;	//анологично с регистрацией
                break;
              case 3:
                c=4;
                break;
              default:
                cout<<"\n\nВведите одну из цифр от 0 до 2!\n";
              }
            if(c!=1) break; 
            } 
            break;
        case 2:
          while(1)
            {
            cout<<"\n-----Главное меню-----\n\n1. Изменить местоположение\n2. Изменить радиус\n3. Показать списсок людей рядом\n4. Найстройки аккаунта\n5. Выйти из аккаунта\n6. Выйти из программы\n";
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
                //users[u].circle.reCoord(a,b);
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
                //users[u].circle.reRad(r);
                break;
                }
              /*case 3:
                showr(u, users);	//функция показа списка людей рядом
                break;
              case 4:
                setting(u, users);	//функция настройки аккаунта
                break;	
              case 5:
                c=1;
                break;*/
              case 6:
                c=4;
                break;
              default: cout<<"\nВведите одну из цифр от 1 до 6!\n";	
              }
            if(c!=2) break;
            }
          break;  
        case 4:
          return 0;
        }
      }
  }
