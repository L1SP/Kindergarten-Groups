#include <iostream>
#include "Child.h"
#include "Group.h"
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    Child *A = new Child("Серов", Child::Gender::MALE, 2002);
    Child *B = new Child("Акулов", Child::Gender::MALE, 2003);
    Group* G = new Group(1, "Авсеева");
    G->insertChild(*A);
    G->insertChild(*B);
    cout << *G;
}
