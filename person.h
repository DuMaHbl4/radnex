#include <iostream>
using namespace std;

class circle
  {
  private:
    unsigned int x;		//координаты
    unsigned int y;
    unsigned int rad;		//радиус окружности
  public:
    circle() {x=0; y=0; rad=0;}
    circle(unsigned int h, unsigned int i, unsigned int r) {x=h; y=i; rad=r;}
    unsigned int getX() const {return x;}	//возврат координат
    unsigned int getY() const {return y;}
    unsigned int getRad() const {return rad;}	//возврат радиуса
    void reRad(unsigned int r) {rad=r;}		//изменение радиуса
    void reCoord(unsigned int h, unsigned int i) {x=h; y=i;}	//изменение координат
  };
  
class person
  {
  private:		
    string name;		//имя
    string password;  		//пароль
    string mail;		//почта 
  public:
    person() {name="0"; password="0"; mail="0";}
    person(string n, string p, string m) {name=n; password=p; mail=m;}
    void rePass(string p, string newP);	//изменение пароля
    void login(string n, string p);	//вход
    string getName() const {return name;}
  };
  
class user : private person
  {
  private:
    unsigned int id;		//айди
    unsigned int idVk;		//айди вконтакте
    unsigned int idInst;	//айди инстаграмма
    circle circ;		//окружность с центром в местоположении пользователя, с радиусом ,в котором он желает видеть людей
  public:
    user() {id=0; idVk=0; idInst=0;}
    user(string n, string p, string m, unsigned int d, unsigned int v, unsigned int i, unsigned int t, circle c):person(n, p, m) {id=d; idVk=v; idInst=i; circ=c;}
    void hello() const;		//функция привет
    void vk() const;		//написать сообщение вк
    void inst() const;		//просмотр инстаграм пользователя
    void twit() const;		//просмотр твиттера пользователя
  }; 
  
class admin : public person
  {
  public:
    admin(): person ("admin", "password", "adm@radnex.com"){};    
  };
