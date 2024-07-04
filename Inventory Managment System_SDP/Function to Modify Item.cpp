
void modify()
{
    int no, found = 0;
    system("cls");
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Number of The Item ::->> ";
    cin >> no;
    f.open("store.dat", ios::in | ios::out);
    while (f.read((char*)&i, sizeof(i)) && found == 0)
    {
        if (i.retitemno() == no)
        {
            i.showdata();
            system("cls");
            cout << "\nPlease Enter The New Details of The Item ::->>" << endl;
            i.getdata();
            int pos = -1 * static_cast<int>(sizeof(i));
            f.seekp(pos, ios::cur);
            f.write((char*)&i, sizeof(i));
            cout << "\n\n\tRecord Updated";
            found = 1;
        }
    }
    f.close();
    if (found == 0) cout << "\n\nRecord Not Found";
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
    while (f.read((char*)&i, sizeof(i)))
    {
        if (i.retitemno() != no)
        {
            f2.write((char*)&i, sizeof(i));
        }
    }
    f2.close();
    f.close();
    remove("store.dat");
    rename("temp.dat", "store.dat");
    cout << "\n\n\tRecord Deleted ....";
}
