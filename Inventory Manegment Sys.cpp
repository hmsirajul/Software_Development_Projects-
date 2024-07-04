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

fstream f;
item i;

void write_to_file()
{
    f.open("store.dat", ios::out | ios::app);
    i.getdata();
    f.write((char *)&i, sizeof(i));
    f.close();
    cout << "\n\nThe Item Has Been Created ";
}

void disp_all()
{
    system("cls");
    cout << "\n\n\n\t\tDISPLAY ALL RECORDS\n\n";
    f.open("store.dat", ios::in);
    while (f.read((char *)&i, sizeof(i)))
    {
        i.showdata();
        cout << "\n\n";
    }
    f.close();
    getch();
}

void display_sp(int n)
{
    int flag = 0;
    f.open("store.dat", ios::in);
    while (f.read((char *)&i, sizeof(i)))
    {
        if (i.retitemno() == n)
        {
            system("cls");
            i.showdata();
            flag = 1;
        }
    }
    f.close();
    if (flag == 0)cout << "\n\nRecord does not exist";
    getch();

}

void modify()
{
    int no, found = 0;
    system("cls");
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Number of The Item ::->> ";
    cin >> no;
    f.open("store.dat", ios::in | ios::out);
    while (f.read((char *)&i, sizeof(i)) && found == 0)
    {
        if (i.retitemno() == no)
        {
            i.showdata();
            system("cls");
            cout << "\nPlease Enter The New Details of The Item ::->>" << endl;
            i.getdata();
            int pos = -1 * static_cast<int>(sizeof(i));
            f.seekp(pos, ios::cur);
            f.write((char *)&i, sizeof(i));
            cout << "\n\n\tRecord Updated";
            found = 1;
        }
    }
    f.close();
    if (found == 0)
        cout << "\n\nRecord Not Found";
}

void deleterec()
{
    int no;
    system("cls");
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The  Number of The Item You Want To Delete ::->> ";
    cin >> no;

    f.open("store.dat", ios::in | ios::out);
    fstream f2;
    f2.open("temp.dat", ios::out);
    f.seekg(0, ios::beg);
    while (f.read((char *)&i, sizeof(i)))
    {
        if (i.retitemno() != no)
        {
            f2.write((char *)&i, sizeof(i));
        }
    }
    f2.close();
    f.close();
    remove("store.dat");
    rename("temp.dat", "store.dat");
    cout << "\n\n\tRecord Deleted ....";
}

void menu()
{
    system("cls");
    f.open("store.dat", ios::in);
    if (!f)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout << "\n\n\n Program is closing...";
        exit(0);
    }

    cout << "\n\n\t\t ITEM MENU\n\n";
    cout << "=========================================================\n";
    cout << "ITEM. NO. \tNAME\t\tPRICE\n";
    cout << "=========================================================\n";

    while (f.read((char *)&i, sizeof(i)))
    {
        cout << i.retitemno() << "\t\t" << i.retiname() << "\t\t" << i.retprice() << endl;
    }
    f.close();
}

void place_order()
{
    system("cls");
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n=======================================================\n";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n=======================================================\n";

    do
    {
        cout << "\n\nEnter The Item Number Of The Item ::->> ";
        cin >> order_arr[c];
        cout << "\nQuantity in number ::->> ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Item? (Yes = y)/(No = n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\n\nThank You For Placing The Order";

    system("cls");
    cout << "\n\n**************************************INVOICE****************************************\n";
    cout << "Item No.\tName\tQuantity \tPrice \tAmount\tAmount after discount\n";
    cout << "*************************************************************************************";

    for (int x = 0; x < c; x++)
    {
        f.open("store.dat", ios::in);
        while (f.read((char *)&i, sizeof(i)))
        {
            if (i.retitemno() == order_arr[x])
            {
                amt = i.retprice() * quan[x];
                damt = amt - (amt * i.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t\t" << i.retiname() << "\t" << quan[x] << "\t\t" << i.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
        }
        f.close();
    }

    cout<<"\n*******************************************************************************************";
    cout << "\n\n\t\t\t\t\t\t\tTOTAL = " << total;
    getch();
}

void admin_menu()
{
    system("cls");
    char ch2;
    cout << "\n\n\tADMIN MENU";
    cout << "\n\t1.CREATE ITEM";
    cout << "\n\t2.DISPLAY ALL ITEMS";
    cout << "\n\t3.QUERY";
    cout << "\n\t4.MODIFY ITEM";
    cout << "\n\t5.DELETE ITEM";
    cout << "\n\t6.BACK";
    cout << "\n\t7.EXIT"; // Add the exit option
    cout << "\n\n\tPlease Enter Your Choice (1-7) ::->> ";
    cin >> ch2;
    switch (ch2)
    {
        case '1':
            system("cls");
            write_to_file();
            break;
        case '2':
            disp_all();
            break;
        case '3':
            int num;
            system("cls");
            cout << "\n\n\tPlease Enter The Item Number ::->>";
            cin >> num;
            display_sp(num);
            break;
        case '4':
            modify();
            break;
        case '5':
            deleterec();
            break;
        case '6':
            menu();
            break;
        case '7':
            exit(0); // Exit the program
            break;
        default:
            cout << "\a";
            admin_menu();
    }
}

int main()
{
    //cout << " wellcome In this online e comarcheas platform"<< endl;
    char ch;
    system("cls");
    cout << "************************************************************************************************************************";
    cout << "************************************************************************************************************************";
    cout << "************************************************************************************************************************";
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO THE E-COMARCHASE SHOPPING PLATFORM "; // Add welcome message
    //cout <<"\n\n\n\n\n************************************************************************************************************************";
    //cout << "************************************************************************************************************************";
    //cout << "************************************************************************************************************************";
    getch();

    cout << "\n\n\n\n\n\t\t\t\tLoading";

    for (int i = 0; i < 10; ++i)

        {
        Sleep(1000); // Sleep for 1 second
        cout << ".";

        }

    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. CUSTOMER";
        cout << "\n\n\t2. ADMINISTRATOR";
        cout << "\n\n\t3. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ::->> ";
        cin >> ch;
        switch (ch)
        {
            case '1':
                system("cls");
                place_order();
                break;
            case '2':
                admin_menu();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << "\a";
        }
    } while (ch != '3');
    return 0;
}


