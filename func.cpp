#include "main.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

user* reg(unsigned int &d, user *beg, char* data)	//функция регистрации
  { 
  bool kont;
  int l; 	
  user *end;
  user *pUs;
  user *pU;
  string tmp;
  string n, s, m, p;
  unsigned int v, i, a, b, r;
  ifstream fi;
  fi.open(data);
  fi >> d;
  fi.close();
  d++;
  cout << "\n-----Регистрация------\n\n";
  cout << "Введите имя: ";
  cin >> n;
  cout << "Фамилия: ";
  cin >> s;
  while(1)
    {
    cout << "\nEmail: ";
    kont=false;
    cin >> m;
    pUs=beg;
    while(pUs!=NULL)	//проверка на оригинальность введенного email 
      {
      if(pUs->getMail()==m) 
        {
        kont=true;
        cout << "\nEmail уже используется!\n\n1. Ввести еще раз\n2. Отменить регистрацию\n";
        cin >> l;
        if(l==2) 
          {
          d=0;
          return (beg);
          }
        }
      pUs=pUs->next;
      }
    if(kont==false) break;
    }
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
  pU=new user(n, s, p, m, d, v, i, c);
  pU->showad();
  end=beg;
  if(beg!=NULL)
    while(end->next!=NULL) end=end->next;	//поиск конца списка
  pUs=beg;
  while(pUs!=NULL)
    pUs=pUs->next;
  if(beg==NULL) beg=pU;
  else end->next=pU;
  end=pU;
  end->next=NULL;
  //pUs->next=NULL;
  //if(beg==NULL) beg=pU;
  //beg->showad();
  pU=beg;
  while(pU!=NULL)
    {
    pU=pU->next;
    }
  return (beg);
  }

unsigned int avt(user *beg, const admin& adm)
  {
  int kont=0;	//переменная контроля
  unsigned int u=0;
  string m, p; //мэил и пароль
  user *pU;
  cout << "-----Авторизация-----\n";
  cout << "Введите Email: ";
  getline(cin, m);
  cout << "\nВведите пароль: ";
  cin >> p;
  if(adm.avto(m, p)) return 1;
  pU=beg;
  while(pU!=NULL)
    {
    if(pU->avto(m, p)) 
      {
      kont=1;
      cout << endl << pU->getName();
      cout << ", добро пожаловать!\n";
      u=pU->getId();
      break;
      }
    pU=pU->next;
    }
  if(kont==0) cout << "\nEmail или пароль введены неверно!\n\n";
  return u;
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
  int i;
  stream << usr.id << ' ' << usr.idVk << ' ' << usr.idInst << ' ' << usr.circ;
  for(i=0; i < usr.hi.size(); i++)
    {
    stream << ' ' << usr.hi[i];
    }
    stream << " 0 " << usr.password << ' ' << usr.mail << ' ' << usr.name << ' ' << usr.sername;
  return stream;
  } 
 
istream &operator>>(istream &stream, user &usr) //перегрузка оператора >> класса user
  {
  unsigned int i;
  stream >> usr.id >> usr.idVk >> usr.idInst >> usr.circ;
  while(1)
    {
    stream >> i;
    if(i!=0)
      usr.hi.push_back(i);
    else break;
    }
    stream  >> usr.password >> usr.mail >> usr.name >> usr.sername;
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
  if(d==0)
    {
    fi.close();
    fo.open(data);
    fo << "1" << endl << adm;
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
  unsigned int d=0;
  ofstream fo;
  if(beg==NULL)
    {
    fo.open(data);
    fo << 0 << endl;
    fo << adm;
    fo.close();
    }
  else
    {
    pU=beg;
    while(pU!=NULL)
      {
      if(d<pU->getId()) d=pU->getId();
      pU=pU->next;
      }
    fo.open(data);
    fo << d << endl;
    fo << adm;
    pU=beg;
    while(pU!=NULL)
      {
      fo<<endl<<(*pU);
      pU=pU->next;
      }
    fo.close();
    }
  } 

void showr(user *beg, user *pU)
  {
  bool kont=false;
  string tmp;
  unsigned int id;
  double rn;
  int i;
  double co; //косинус
  double rc; //угол
  bool c = false;
  unsigned int x1, x2, y1, y2;
  int dx, dy; 	//расстяние между х и у
  unsigned int dist=0;	//расстояние между точками
  user *pUs;		//указатель на юзера для перемещения по списку
  pUs=beg;
  while(pUs!=NULL)
    {
    x1=pU->circ.getX(); //считывание х и у двух точек
    x2=pUs->circ.getX();
    y1=pU->circ.getY();
    y2=pUs->circ.getY();
    if(x1<x2) dx=x2-x1;  //поиск коордиат вектора 
    else dx=x1-x2;
    if(y1<y2) dy=y2-y1;
    else dy=y1-y2;
    dist=sqrt(pow(dx,2)+pow(dy,2)); //расстояние мужду точками
    if(dist<=pU->circ.getRad() && pU->getId()!=pUs->getId()) //если радиус пользователя больше чем расстояние до человека то выводим на экран
      {
      c=true;
      break;
      }
    pUs=pUs->next;
    }
  if(c)
    {  
    pUs=beg;
    cout << "Список людей в вашем радиусе:\n";
    while(pUs!=NULL)
      {
      x1=pU->circ.getX();
      x2=pUs->circ.getX();
      y1=pU->circ.getY();
      y2=pUs->circ.getY();
      dx=x2-x1;
      dy=y2-y1;
      dist=sqrt(pow(dx,2)+pow(dy,2));
      co=(dx)/(sqrt(pow(dx,2)+pow(dy,2))); 
      rn=180*acos(co)/3.14;
      rc=rn;
      if(dy<0)
      rc=360-rn;
      rc=rc+22.5;
      for(i=0; i<8; i++)
        {
        if(rc>=i*45 && rc<=(i+1)*45) break;
        }
      if(dist<=pU->circ.getRad() && pU->getId()!=pUs->getId()) 
        {
        cout << "На расстоянии " << dist << " метров: ";
        pUs->show();
        cout << " Id: " << pUs->getId();
        switch(i)
          {
          case 0: 
            cout << " На востоке";
            break;
          case 1:
            cout << " На северо-востоке";
            break;
          case 2:
            cout << " На севере";
            break;
          case 3:
            cout << " На северо-западе";
            break;
          case 4:
            cout << " На запде";
            break;
          case 5:
            cout << " На юго-западе";
            break;
          case 6:
            cout << " На юге";
            break;
          case 7:
            cout << " На юго-востоке";
            break;
          }
        cout << endl;
        }
      pUs=pUs->next;
      }
    cout << "\nВведите id человека, которому хотите передать привет, введите 0 чтобы выйти в меню\n";
    while(1)
      {
      cin >> id;
      if(cin.fail())
        {
        cout << "\nВведите число больше нуля!\n";
        cin.clear();
        getline(cin, tmp);
        }
      else break;
      }
    if(id==0) ;
    else
      {
      if(id==pU->getId())
        {
        cout << "Можете сказать себе: " << "привет\n";
        }
      pUs=beg;
      while(pUs!=NULL)
        {
        if(id==pUs->getId()) 
          {
          pUs->hello(pU->getId());
          cout << pU->getId();
          kont=true;
          cout << "Привет отправлен\n";
          break;
          }
        pUs=pUs->next;
        }
      if(!kont) cout << "Человека с таким Id еще нет\n";
      }
    }
  else cout << "Людей в вашем радиусе нет\n";
  }
  
  
user* setting(int &c, user *beg, user *pU)
  {
  user *pUs;
  string pass;
  string tmp;
  int i;
  int l;
  cout << "\n-----Настройки-----\n\n";
  cout << "1. Изменить пароль\n2. Удалить аккаунт\n3. Выйти в меню\n";
  while(1)
    {
    cin >> i;
    if(cin.fail())
      {
      cout << "\nВведите число от 1 до 3!\n";
      getline(cin, tmp);
      cin.clear();
      }
    else break;
    }
  while(1)
  {switch(i)
    {
    case 1:
      cout << "Введите старый пароль: ";
      cin >> pass;
      if(pU->pass(pass))
        {
        cout << "Введите новый пароль: ";
        cin >> pass;
        pU->rePass(pass);
        return beg;
        }
      else
        {
        cout << "Пароль введен неверно!\n1. Ввести еще раз\n2. Выйти в меню\n";
        while(1)
          {
          cin >> l;
          if(cin.fail() || l<1 || l>2)
            {
            cout << "\nВведите 1 или 2!\n";
            getline(cin, tmp);
            cin.clear();
            }
          else break;
          }
        if(l==1)
          {
          break;
          }
        else 
          {
          i=3;
          break;
          }
        }
    case 2:
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
        pUs=beg;
        while(pUs->next!=pU)
          {
          pUs=pUs->next;
          }
        pUs->next=pUs->next->next;
        delete pU;
        }
      c=1;
      return beg;
    case 3:
      return beg;
    }
    }
  }
  
void hello(user *beg, user *pU)
  {
  unsigned int l;
  user *pUs;
  if(pU->hi.size()>0)
    {
    cout << "Вам передают привет: ";
    for(l=0; l<pU->hi.size(); l++)
      {
      pUs=beg;
      while(pUs!=NULL)
        {
        if(pUs->getId()==pU->hi[l])
          {
          if(l>0) cout << ", ";
          pUs->show();
          }
        pUs=pUs->next;
        }
      }
    cout << "\n\n";
    }                                                                                                                                                                                                                                                                              
  }