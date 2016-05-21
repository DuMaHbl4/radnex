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
void hello(user *beg, user *pU);