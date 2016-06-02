#include <vector>
#include <iostream>
using namespace std;
///@class circle
class circle///класс содержит информацию об окружности и методы, позволяющие изменять ее параметры
  {
  private:
    ///координата центра окружности Х
    unsigned int x;
    ///координата центра окружности У		
    unsigned int y;
    ///радиус окружности
    unsigned int radi;		
    ///второй радиус окружности
    unsigned int rado;
  public:
    ///конструктор по умолчанию
    circle() {x=0; y=0; radi=0; rado=0;} 
    ///конструктор с параметрами
    ///@param вся информация об окружности
    circle(unsigned int h, unsigned int i, unsigned int ri, unsigned int ro) {x=h; y=i; radi=ri; rado=ro;} 
    ///@return х - координату по Х центра окружности
    unsigned int getX() const {return x;}	
    ///@return y - координату по у центра окружности
    unsigned int getY() const {return y;}
    ///@return radi - радиус
    unsigned int getRadi() const {return radi;}
    ///@return rado - второй радиус
    unsigned int getRado() const {return rado;}
    ///изменение радиуса
    ///@param radi - радиус	
    void reRadi(unsigned int r) {radi=r;}
    ///изменение второго радиуса
    ///@param rado - второй радиус
    void reRado(unsigned int r) {rado=r;}	
    ///изменение координат
    ///@param h - x
    ///@param i - y	
    void reCoord(unsigned int h, unsigned int i) {x=h; y=i;}
    ///вывод всей информации об окружности на экран	
    void showcir() const {cout << x << ' ' << y << ' ' << radi << ' ' << rado << ' ';} 
    ///перегруженый оператор <<
    friend ostream &operator<<(ostream &stream, circle cir);
    ///перегруженый оператор >>	
    friend istream &operator>>(istream &stream, circle &cir);	
  };
///@class person  
class person ///базовый класс, содержит в себе общую информацию классов наследников(админ и пользователь). Не используется в программе напрямую 
  {
  protected:
    ///имя 		
    string name;		
    ///фамилия
    string sername;		
    ///пароль
    string password;  		
    ///почта
    string mail;	
  public:
    ///конструктор по умолчанию
    person() {name="0"; sername="0"; password="0"; mail="0";}
    ///конструктор
    ///@param все параметры человека 
    person(string n, string s, string p, string m) {name=n; sername=s; password=p; mail=m;}
    ///изменение пароль
    ///@param новый пароль
    void rePass(string newP) {password=newP;}
    ///@return sername - фамилию
    string getSername() const {return sername;}
    ///@return name - имя 
    string getName() const {return name;}
    ///@return mail - почту
    string getMail() const {return mail;}
    ///вывод на экран имени и фамилии
    void shov() const {cout << name << ' ' << sername << ' ';}
    ///расширеный вывод информации  на экран
    void shovad() const {cout << "Имя: " << name << " Фамилия: " << sername << " Email: " << mail;}
    ///проверка на правильность введеных данных(имя, пароль)
    ///@param e - почта
    ///@param p - пароль
    ///@return true если данные совпадают, false если не совпадают
    bool avto(string e, string p) const {if(mail==e && password==p) return true; else return false;}
    ///проверка на правильность введеного пароля
    ///@param p - пароль
    ///@return true если пароль совпал, false если не совпал
    bool pass(string p) const {if(p==password) return true; else return false;}
    };
///@class user
class user : public person ///класс "Пользователь" содержит в себе всю необходимую информацию о пользователе
  {
  private:
    ///id в программе
    unsigned int id;
    ///id Вконтакте
    unsigned int idVk;
    ///id в инстаграмме
    unsigned int idInst;
    ///список людей, отправивших привет
    vector <unsigned int> hi;
    ///список друзей
    vector <unsigned int> frnd;
  public:
    circle circ;		///<окружность с центром в местоположении пользователя, с радиусом ,в котором он желает видеть людей
    ///указатель на следующего пользователя
    user *next;
    ///конструктор по умолчанию
    user() {id=0; idVk=0; idInst=0; next=NULL;}
    ///конструктор с параметрами
    ///@param все параметры пользователя
    user(string n, string s, string p, string m, unsigned int d, unsigned int v, unsigned int i, circle c):person(n, s, p, m) {id=d; idVk=v; idInst=i; circ=c; next=NULL;}
    /*void vk() const;		//написать сообщение вк
    void inst() const;		//просмотр инстаграм пользователя*/
    ///@return id - id пользователя 
    unsigned int getId() const {return id;}
    ///@return idVk - id в соцсети
    unsigned int getIdVk() const {return idVk;} 
    ///вывод самой важной информации о пользователе
    void show() const {shov(); cout << "id: " << id << " idVk: " << idVk;}
    ///расширеный вывод информации на экран
    void showad() const {shovad(); cout << " Id: " << id << " Id Вконтакте: " << idVk << " Instagram: " << idInst << endl;}
    ///перегруженый оператор <<  
    friend ostream &operator<<(ostream &stream, user usr);
    ///перегруженый оператор >>   
    friend istream &operator>>(istream &stream, user &usr);
    ///@return hi.size - число людей, отправиших привет
    int getSiHi() const {return hi.size();}
    ///возврат элемента вектора hi
    ///@param l - номер возвращаемого элемента
    ///@return hi[l] - lый элемент вектора hi
    unsigned int getHi(const unsigned int& l) const {return hi[l];}
    ///получение привета от пользователя. функция добавляет в вектор id пользователя, отправившего "привет"
    ///@param id - id пользователя, отправившего "привет"
    void hello (const unsigned int& id) {hi.push_back(id);}
    ///очиста вектора людей, отправивших привет
    void clearHi () {hi.clear();}
    ///@return frnd.size - число друзей
    int getSiFr() const {return frnd.size();}
    ///возврат элемента вектора frnd
    ///@param l - номер возвращаемого элемента
    ///@return frnd[l] - lый элемент вектора frnd
    unsigned int getFr(const unsigned int& l) const {return frnd[l];}
    ///добавление id друга в список 
    ///@param idVk - id друга Вк(т.к. информация о друзьях должна импортироваться из соцсетей)
    void addFrnd (const unsigned int& idVk) {frnd.push_back(idVk);}
    ///удаление друга из списка
    ///@param idVk - id удаляемого друга
    void deleteFrnd (const unsigned int& idVk);
  }; 

///@class admin
class admin : public person ///класс "админ", пользователь, вошедший от его имени, имеет возможность просматривать информацию и удалить аккаунт любого пользователя каждом пользовател  
  {
  public:
    ///конструктор по умолчанию
    admin(): person ("admin", "админ", "password", "adm@radnex.com"){};
    ///перегруженй оператор << 
    friend ostream &operator<<(ostream &stream, admin adm);
    ///перегруженый оператор >>
    friend istream &operator>>(istream &stream, admin &adm);   
  };
