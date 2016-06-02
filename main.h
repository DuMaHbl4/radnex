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
bool vect(const unsigned int& x1, const unsigned int& y1, const unsigned int& x2, const unsigned int& y2, const unsigned int& rad);
void frend(user* beg, user* pU);