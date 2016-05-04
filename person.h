class circle
  {
  private:
    unsigned int x;		//координаты
    unsigned int y;
    unsigned int rad;		//радиус окружности
  public:
    point() {x=0; y=0; rad=0;}
    point(unsigned int h, unsigned int i, unsigned int r) {x=h; y=i; rad=r;}
    unsigned int getX() const {return x;}	//возврат координат
    unsigned int getY() const {return y;}
    unsigned int getRad() const {return rad;}	//возврат радиуса
    void reRad(unsigned int r) {rad=r}		//изменение радиуса
    void reCoord(unsigned int h, unsigned int i) {x=h; y=i;}	//изменение координат
  };
  
class person
  {
  private:		
    string name;		//имя
    string password;  		//пароль
    string mail;		//почта 
  public:
    void rePass(string p; string newP);	//изменение пароля
    void login(string n, string p);	//вход
  };
  
class user : public person
  {
  private:
    unsigned int id;		//айди
    unsigned int idVk;		//айди вконтакте
    unsigned int idInst;	//айди инстаграмма
    circle circ;		//окружность с центром в местоположении пользователя, с радиусом ,в котором он желает видеть людей
  public:
    user() {name="0"; password="0"; id=0; idVk=0; idInst=0; idTwit=0;}
    user(string n, string p, unsigned int d, unsigned int v, unsigned int i, unsigned int t) {name=n; password=p; id=d; idVk=v; idInst=i; idTwit=t;}
    string getName() const {return name;}	//возврат имени	
    void hello() const;		//функция привет
    void vk() const;		//написать сообщение вк
    void inst() const;		//просмотр инстаграм пользователя
    void twit() const;		//просмотр твиттера пользователя
  }; 
  
class admin : public person
  {
  public:
    admin() {name="admin"; password="password"; mail="adm@radnex.com";}    
  };
