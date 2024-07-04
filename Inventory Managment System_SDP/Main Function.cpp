int main()
{
    char ch;
    system("cls");
    cout << "************************************************************************************************************************";
    cout << "************************************************************************************************************************";
    cout << "************************************************************************************************************************";
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO THE E-COMARCHASE SHOPPING PLATFORM "; // Add welcome message
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

