#include <iostream>
#include <fstream>
#include <cstdlib>
#include<conio.h>
#include <windows.h> // For Sleep function
using namespace std;

class item
{
private:
    int itemno;
    char iname[50];
    float price, qnt, tax, dis;

public:
    void getdata()
    {
        system("cls");
        cout << "\nPlease Enter The Number of The Item ::>> ";
        cin >> itemno;
        cout << "\nPlease Enter The Name of The Item ::>> ";
        cin.ignore(); // Ignore newline character left in buffer
        cin.getline(iname, 50);
        cout << "\nPlease Enter The Price of The Item ::>> ";
        cin >> price;
        cout << "\nPlease Enter The Discount (%) ::>> ";
        cin >> dis;
    }

    void showdata()
    {
        system("cls");
        cout << "\n\tThe Item No. of The Item: " << itemno;
        cout << "\n\tThe Name of The Item: " << iname;
        cout << "\n\tThe Price of The Item: " << price;
        cout << "\n\tDiscount (%): " << dis;
    }

    int retitemno() { return itemno; }

    float retprice() { return price; }

    char *retiname() { return iname; }

    int retdis() { return dis; }
};
