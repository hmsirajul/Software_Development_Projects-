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

    while (f.read((char*)&i, sizeof(i)))
    {
        cout << i.retitemno() << "\t\t" << i.retiname() << "\t\t" << i.retprice() << endl;
    }
    f.close();
}

