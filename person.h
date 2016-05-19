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
    void showcir() const {cout << x << ' ' << y << ' ' << rad << ' ';}
    friend ostream &operator<<(ostream &stream, circle cir);
    friend istream &operator>>(istream &stream, circle &cir);
  };
  
class person
  {
  protected:		
    string name;		//имя
    string password;  		//пароль
    string mail;		//почта 
  public:
    person() {name="0"; password="0"; mail="0";}
    person(string n, string p, string m) {name=n; password=p; mail=m;}
    void rePass(string newP) {password=newP; cout <<"new password +";}	//изменение пароля
    void login(string n, string p);	//вход
    string getName() const {return name;}
    string getMail() const {return mail;}
    void shov() const {cout << name;}
    void shovad() const {cout << name << ' ' << password << ' ' << mail << ' ';}
    bool avto(string e, string p) const {if(mail==e && password==p) return true; else return false;}	//проверка при на имя и пароль
    bool pass(string p) const {if(p==password) return true; else return false;}	//проверка на правильность пароля
    };
  
class user : public person
  {
  private:
    vector <int> hi;		//список людей отправивших "привет"
    unsigned int id;		//айди
    unsigned int idVk;		//айди вконтакте
    unsigned int idInst;	//айди инстаграмма
  public:
    circle circ;		//окружность с центром в местоположении пользователя, с радиусом ,в котором он желает видеть людей
    user *next;
    user() {id=0; idVk=0; idInst=0; next=NULL;}
    user(string n, string p, string m, unsigned int d, unsigned int v, unsigned int i, circle c):person(n, p, m) {id=d; idVk=v; idInst=i; circ=c; next=NULL;}
    void hello() const;		//функция привет
    void vk() const;		//написать сообщение вк
    void inst() const;		//просмотр инстаграм пользователя
    void twit() const;		//просмотр твиттера пользователя 
    unsigned int getId() const {return id;}
    void show() const {shov();}
    void showad() const {shovad(); cout << id << ' ' << idVk << ' ' << idInst << ' '; circ.showcir();}  
    friend ostream &operator<<(ostream &stream, user usr);  
    friend istream &operator>>(istream &stream, user &usr);
    void hello (const unsigned int& id) {hi.push_back(id);}
    void clearHi () {hi.clear();}
  }; 
  
class admin : public person
  {
  public:
    admin(): person ("admin", "password", "adm@radnex.com"){}; 
    friend ostream &operator<<(ostream &stream, admin adm);
    friend istream &operator>>(istream &stream, admin &adm);   
  };
