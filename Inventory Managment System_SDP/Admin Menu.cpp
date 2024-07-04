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

