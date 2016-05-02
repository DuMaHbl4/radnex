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
    unsigned int idTwit;	//айди твиттера
    unsigned int rad;		//радиус
    unsigned int x, y;		//координаты
  public:
    user() {name="0"; password="0"; id=0; idVk=0; idInst=0; idTwit=0; rad=0; x=0; y=0;}
    user(string n, string p, unsigned int d, unsigned int v, unsigned int i, unsigned int t, unsigned int r, unsigned int a, unsigned int b) {name=n; password=p; id=d; idVk=v; idInst=i; idTwit=t; rad=r; x=a; y=b}
    void reRad(unsigned int r) {rad=r;}	//изменение радиуса
    void reCoord(unsigned int a, unsigned int b) {x=a; y=b;}	//изменение координат
    string getName() {return name;}	//возврат имени
    unsigned int getRad() {return rad;}	//возврат радиуса
    unsigned int getX() {return x;}	//возврат координат
    unsigned int getY() {return y;}	
    void hello();		//функция привет
    void vk();			//написать сообщение вк
    void inst();		//просмотр инстаграм пользователя
    void twit();		//просмотр твиттера пользователя
  }; 
  
class admin : public person
  {
  public:
    admin() {name="admin"; password="password"; mail="adm@radnex.com";}    
  };