#include "person.h"

int menu(char* data);
user* reg(unsigned int &id, user *beg, char* data);
user* load(char* data, admin &adm);
int save(char* data, user *beg, admin &adm);