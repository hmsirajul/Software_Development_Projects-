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
        while (f.read((char*)&i, sizeof(i)))
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

    cout << "\n*******************************************************************************************";
    cout << "\n\n\t\t\t\t\t\t\tTOTAL = " << total;
    getch();
}

