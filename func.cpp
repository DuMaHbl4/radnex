#include "main.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

/**@function reg
функция регистрации
@param d - id зарегистрировавшегося пользователя
@param beg - указатель на начало списка
@param data - название файла
@return beg - указатель на начало списка*/
user* reg(unsigned int &d, user *beg, char* data)
  { 
  bool kont;
  int l; 	
  user *end;
  user *pUs;
  user *pU;
  string tmp;
  string n, s, m, p;
  unsigned int v, i, a, b, ri, ro;
  ifstream fi;
  fi.open(data);
  fi >> d;
  fi.close();
  d++;
  cout << "\n-----Регистрация------\n\n";
  cout << "Введите имя: ";
  cin >> n;
  cout << "\nФамилия: ";
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
    cin >> ri;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите число больше нуля!\n";
      }
    else break;
    }
  cout << "\nВведите расстояние в радиусе которго вы хотите быть видимыми дляя доугиз пользователей: ";
  while(1)
    {
    cin >> ro;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВвндите число больше нуля!\n";
      }
    else break;
    }
  circle c(a, b, ri, ro);
  pU=new user(n, s, p, m, d, v, i, c);
  //pU->showad();
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
  pU=beg;
  while(pU!=NULL)
    {
    pU=pU->next;
    }
  return (beg);
  }

/**функция авторизации. в зависимости от введеных почты и пароля программа может запросить ввести данные повторно, либо перейти в меню обычного пользователя, либо перейти в меню "адимина"
@param beg - указатель на начало списка
@param adm - объект класса "админ"
@return id, авторизовавшегося пользователя */
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
  stream << " 0";
  for(i=0; i < usr.frnd.size(); i++)
    {
    stream << ' ' << usr.frnd[i];
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
  while(1)
    {
    stream >> i;
    if(i!=0)
      usr.frnd.push_back(i);
    else break;
    }
  stream  >> usr.password >> usr.mail >> usr.name >> usr.sername;
  return stream;
  } 
  
ostream &operator<<(ostream &stream, circle cir) //перегрузка оператора << класса circle 
  {
  stream << cir.x << ' ' << cir.y << ' ' << cir.radi << ' ' << cir.rado;
  return stream;
  }
  
istream &operator>>(istream &stream, circle &cir) //перегрузка оператора >> класса circle
  {
  stream >> cir.x >> cir.y >> cir.radi >> cir.rado;
  return stream;
  }
  
/**функция загрузки списка пользователей из файла
@param data - название файла
@param adm - ссылка на объект класса "админ", нужна для чтения данных админа их файла
@return beg - указатель на начало списка*/
user* load(char* data, admin &adm)	//
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

/**функция сохранения списка пользователей и параметров адина в файл
@param data - название фйла
@param beg - указатель на начало списка
@param  adm - админ
*/  
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

/**@function
Функция показа информации о векторе в удобном для пользователя виде. Выводит на экран расстояние между точками и направление от первой точки ко второй, если расстояние между точками меньше чем радиус, в котором пользователь желает видеть людей. Имеет пять входных параметров.
@param x1 - параметр, отвечающий за координату Х точки начала вектора
@param y1 - параметр, отвечающий за координату У точки начала вектора
@param rad1 - параметр, отвечающий за радиус, в которм пользователь хочет видеть людей
@param x2 - параметр, отвечающий за координату Х точки конца вектора
@param y2 - параметр, отвечающий за координату У точки конца вектора
@param rad2 - параметр, отвечающий за радиус, в котром пользователь хочет быть видимым для других людей*/
bool vect(const unsigned int& x1, const unsigned int& y1, const unsigned int& radi, const unsigned int& x2, const unsigned int& y2, const unsigned int& rado, bool cot)
  {
  bool c=false;
  int dx, dy;
  unsigned int dist;
  double co, rn, rc;
  int i;
  dx=x2-x1; 
  dy=y2-y1; 
  dist=sqrt(pow(dx,2)+pow(dy,2));
  if(dist<=radi && dist<=rado)
    { 
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
    c=true;
    if(cot)
      {
      cout << "На расстоянии " << dist << " метров.";
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
          cout << " На запaде";
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
      }
    }
  return c;
  }

/**функция показа списка людей в радиусе пользователя, с информацией об их местеположении(расстояние и направление)
@param beg - указатель на начало списка
@param pU - указатель на пользователя, который ищет людей в своем радиусе*/      
void showr(user *beg, user *pU)
  {
  bool frend;
  bool nom;
  int i;
  bool kont=false;
  bool fr=false;
  string tmp;
  unsigned int id;
  user *pUs;		//указатель на юзера для перемещения по списку  
  pUs=beg;
  while(pUs!=NULL)
    {
    if(pUs!=pU)
      {
      if(vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), false))
        {
        kont = true;
        for(i=0; i<pU->getSiFr(); i++)
          {
          if(pU->getFr(i)==pUs->getIdVk())
            {
            fr=true;
            kont=false;
            break;
            }
          }
        }
      }
    pUs=pUs->next;
    }
  if(fr)
    {
    pUs=beg;
    cout << "Дпузья в вашем радиусе:\n";
    while(pUs!=NULL)
      {
      if(pUs!=pU)
        {
        if(vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), false))
          {
          for(i=0; i<pU->getSiFr(); i++)
            {
            if(pU->getFr(i)==pUs->getIdVk())
              {
              vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), true);
              cout << ' ';
              pUs->show();
              cout << endl;
              break;
              }
            }
          }
        }
      pUs=pUs->next;
      }
    }
  if(kont)
    {
    pUs=beg;
    cout << "\nПотенциальные знакомые:\n";
    while(pUs!=NULL)
      {
      if(pU!=pUs)
        {
        if(vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), false))
          {
          frend=false;
          for(i=0; i<pU->getSiFr(); i++)
            {
            if(pU->getFr(i)==pUs->getIdVk())
              {
              frend=true;
              break;
              }
            }
          if(!frend)
            {
            vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(),true);
            cout << ' ';
            pUs->show();
            cout << endl;
            }
          }
        }
      pUs=pUs->next;
      }
    }
  if(kont||fr)
    {
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
          kont=true;
          cout << "Привет отправлен\n";
          break;
          }
        pUs=pUs->next;
        }
      if(!kont) cout << "Человека с таким Id еще нет\n";
      }
    }
  else  cout << "В вашем радиусе никого нет\n";
  }
/**функция - меню настроек аккаунта пользователя(изменить пароль, удалить аккаунт)
@param c - ссылка на переменную, контролирующую дальнейший выбор пункта меню. если пользователь выбирает удаление аккаунта происходит переход в меню авторизации, в других случаях в меню пользователя 
@param bеg - указатель на начало списка
@param pU - указатель на пользователя, который тзменяет параметры своего аккаунта
@return beg - указатель на начало списка*/
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
        cout << "Пароль изменен\n";
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
/**функция "привет" выводит на экран пользователя список людей, отправивших ему привет
@param beg - указатель на начало списка
@param pU - указатель на пользователя, на экран которого выводится список людей, отправивших ему привет*/ 
void hello(user *beg, user *pU)
  {
  unsigned int l;
  user *pUs;
  if(pU->getSiHi()>0)
    {
    cout << "Вам передают привет:\n";
    for(l=0; l<pU->getSiHi(); l++)
      {
      pUs=beg;
      while(pUs!=NULL)
        {
        if(pUs->getId()==pU->getHi(l))
          {
          pUs->show();
          cout << ". ";
          vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), true);
          }
        pUs=pUs->next;
        }
      }
    cout << "\n\n";
    }                                                                                                                                                                                                                                                                              
  }
  
/**функция - меню связаное с взаимодействие пользователя со своими друзьями
@param beg - указатель на начало списка
@param pU - указатель на пользователя
@return beg - указатель на начало списка*/
void frend(user *beg, user* pU)
  {
  bool nal=false;
  user *pUs;
  pUs=beg;
  /*while(pUs!=NULL)
    {
    cout << (*pUs) << endl;
    pUs=pUs->next;
    }*/
  bool kont;
  unsigned int id;
  string tmp;
  int i;
  int l;
  cout << "-----Друзья-----\n\n";
  cout << "1. Посмотрель весь список друзей\n2. Добавить друга\n3. Удалить друга\n4. Выйти в меню\n";
  while(1)
    {
    cin >> i;
    if(cin.fail())
      {
      cout << "\nВведите одно из чисел от 1 до 4!\n";
      cin.clear();
      getline(cin, tmp);
      }
    else break;
    }
  switch(i)
    {
    case 1:
      kont=false;
      for(l=0; l<pU->getSiFr(); l++)
        {
        pUs=beg;
        while(pUs!=NULL)
          {
          if(pU->getFr(l)==pUs->getIdVk())
            {
            kont=true;
            pUs->show();
            cout << " Id Вк: " << pUs->getIdVk() << ' ' ;
            vect(pU->circ.getX(), pU->circ.getY(), pU->circ.getRadi(), pUs->circ.getX(), pUs->circ.getY(), pUs->circ.getRado(), true);
            cout << endl;
            break;
            }
          pUs=pUs->next;
          }
        }
      if(!kont) cout << "\nУ вас нет друзей\n";
      break;
    case 2:
      kont = false;
      cout << "Введите id Вконтакте вашего друга: ";
      while(1)
        {
        cin >> id;
        if(cin.fail())
          {
          cout << "\nВведите число > 0!\n";
          cin.clear();
          getline(cin, tmp);
          }
        else break; 
        }
      for(l=0; l<pU->getSiFr(); l++)
        {
        if(pU->getFr(l)==id)
          {
          nal=true;
          pUs->show();
          cout << " уже есть в списке ваших друзей\n";
          break;
          }
        }
      if(!nal)
        {
        pUs=beg;
        while(pUs!=NULL)
          {
          if(pUs->getIdVk()==id)
            {
            pU->addFrnd(pUs->getIdVk());
            pUs->show();
            cout << " теперь в вашем списке друзей";
            kont = true;
            break;
            }
          pUs=pUs->next;
          }
        if(!kont) cout << "Пользователя с таким id нет!\n";
        }
      break;
    case 3:
      cout << "Введите id удаляемого друга: ";
      while(1)
        {
        cin >> id;
        if(cin.fail())
          {
          cout << "\nВведите число > 0!\n";
          cin.clear();
          getline(cin, tmp);
          }
        else break; 
        }
      pU->deleteFrnd(id);
      break;
    case 4:
      break;
    default: cout << "\nВведите одно из чисел от 1 до 4!\n";
    }
  }

