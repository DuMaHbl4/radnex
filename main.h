#include "person.h"

int menu(char* data);
user* reg(unsigned int &id, user *beg, char* data);
user* load(char* data, admin &adm);
int save(char* data, user *beg, admin &adm);
unsigned int avt(user *beg, const admin& adm);
void showr(user *beg, user *pU);
user* setting(int &c, user *beg, user *pU);
void poisk(user *beg);
void pokas(user *beg);
user* delet(user *beg);
void repass(admin &adm);
void hello(user *beg, user *pU);
/**@function vect
Функция показа информации о векторе в удобном для пользователя виде. Выводит на экран расстояние между точками и направление от первой точки ко второй, если расстояние между точками меньше чем радиус, в котором пользователь желает видеть людей. Имеет пять входных параметров.
@param x1 - параметр, отвечающий за координату Х точки начала вектора
@param y1 - параметр, отвечающий за координату У точки начала вектора
@param x2 - параметр, отвечающий за координату Х точки конца вектора
@param y2 - параметр, отвечающий за координату У точки конца вектора
@param rad - параметр, отвечающий за радиус, в котром пользователь хочет видеть дюдей*/
bool vect(const unsigned int& x1, const unsigned int& y1, const unsigned int& x2, const unsigned int& y2, const unsigned int& rad);
