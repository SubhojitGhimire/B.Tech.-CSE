int main_menu ()
{
    printf ("\n");
    Display_Album ();
    printf ("\nMenu(M)\tOpen Playlist(O)\tBack(B)\n> ");
    char option ['!'];
    int menu_opt, song_num;

    scanf ("%s", &option);
    option [0] = toupper (option [0]);

    switch (option)
    {
        case "M":   printf ("\n1. Add Song");
                    printf ("\n2. Delete Song");
                    printf ("\n3. Back\n> ");
                    scanf ("%d", &menu_opt);
                    switch (menu_opt)
                    {
                        case 1: system ("cls");
                                Store_Song ();
                                main_menu ();
                                break;
                        case 2: printf ("\nDelete Song Number> ");
                                scanf ("%d", &song_num);
                                Delete_Song (song_num);
                                main_menu ();
                                break;
                        default: main_menu ();
                                break;
                    }
                    break;
        case 'O':   system ("cls");
                    Open_Playlist_menu (playlist_name);
                    break;
        case 'B':   music_player ();
                    break;
        default :   main_menu ();
                    break;
     }
    return 0;
}