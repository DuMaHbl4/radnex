#include <iostream>
#include "main.h"
using namespace std;

int main(int argc, char* argv[])
  {
  if(argc!=2)
    {
    cout << "Необходимо ввести имя файла базы данный в командной строке\n";
    return 0;
    }
  menu(argv[1]);
  }