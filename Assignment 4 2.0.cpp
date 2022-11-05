#include "TableChaining.h"
#include "TableDynamic.h"
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{


    Employee Mina("Mina", "30", "10000", "4");
    Employee Fawzy("Fawzy", "45", "5000", "8");
    Employee Yara("Yara", "19", "2000", "0");
    Employee Mariam("Mariam", "32", "8000", "2");
    Employee Ayman("Ayman", "33", "4000", "8");
    Employee Roshdy("Roshdy", "28", "9000", "3");
    Employee Aya("Aya", "26", "6000", "3");
    Employee Abdallah("Abdallah", "29", "7000", "4");
    Employee Fatma("Fatma", "21", "3000", "1");

    CHash hashLL;
    hashLL.insertItem(Mina);
    hashLL.insertItem(Fawzy);
    hashLL.insertItem(Yara);
    hashLL.insertItem(Mariam);
    hashLL.insertItem(Ayman);
    hashLL.insertItem(Roshdy);
    hashLL.insertItem(Aya);
    hashLL.insertItem(Abdallah);
    hashLL.insertItem(Fatma);
    hashLL.Cprint();
    cout << "Collision Rate: " << hashLL.collisionsRate() << endl;
    cout << "-----------------------------------------------------------\n";
    hashLL.removeItem(Yara);
    hashLL.Cprint();
    cout << "Collision Rate: " << hashLL.collisionsRate() << endl;
    cout << "-----------------------------------------------------------\n";

    dynamicHash HashDy;
    HashDy.insertItem(Mina);
    HashDy.insertItem(Fawzy);
    HashDy.insertItem(Yara);
    HashDy.insertItem(Mariam);
    HashDy.insertItem(Ayman);
    HashDy.insertItem(Roshdy);
    HashDy.insertItem(Aya);
    HashDy.insertItem(Abdallah);
    HashDy.insertItem(Fatma);
    HashDy.print();
    cout << "Collision Rate: " << HashDy.collisionsRate() << endl;
    cout << "-----------------------------------------------------------\n";
    HashDy.removeItem(Yara);
    HashDy.print();
    cout << "Collision Rate: " << HashDy.collisionsRate() << endl;
}