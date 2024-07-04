
fstream f; ///Global Variables
item i;///Global Variables


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
