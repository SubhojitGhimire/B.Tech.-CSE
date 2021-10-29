int Open_Playlist_Menu (char playlist_name [10][20])
{
    system ("cls");
    printf ("\n");
    for (int i=0; i<10; ++i)
    {
        printf ("\n%d. %s", i+1, playlist_name [i]);
    }
    printf ("\nMenu(M)\tCreate Playlist(C)\tBack(B)\n> ");
    char option['!'];
    scanf ("%s", &option);
    option [0] = toupper (option[0]);
    int menu_opt, playlist_num;
    switch (option)
    {
        case "M":   printf ("\n1. Open Playlist");
                    printf ("\n2. Play Playlist");
                    printf ("\n3. Back\n> ");
                    scanf ("%d", &menu_opt);
                    switch (menu_opt)
                    {
                        case 1: printf ("\nSelect playlist by it's serial number to open it: ");
                                scanf ("%d", &playlist_num);
                                system ("cls");
                                Display_Playlist (playlist_num);
                                printf ("\nMenu(M)\tPlay(P)\tBack(B)\n> ");
                                scanf ("%s", &option);
                                option[0] = toupper (option [0]);
                                switch (option)
                                {
                                    case "M":   printf ("\n1. Add Song to this playlist");
                                                printf ("\n2. Delete Song from this playlist");
                                                printf ("\n3. Back to Playlist Menu\n> ");
                                                scanf ("%d", &menu_opt);
                                                switch (menu_opt)
                                                {
                                                    case 1: Add_in_Playlist (playlist_num);
                                                            break;
                                                    case 2: Delete_from_Playlist (playlist_num);
                                                            break;
                                                    case 3: Open_Playlist_Menu (playlist_name);
                                                            break;
                                                    default:Open_Playlist_Menu (playlist_name);
                                                            break;
                                                }
                                    case "P":   printf ("\n1. Play in loop");
                                                printf ("\n2. Do not play on loop\n> ");
                                                scanf ("%d", &menu_opt);
                                                Play (playlist_num, menu_opt);
                                                break;
                                    case "B":   Open_Playlist_Menu (playlist_name);
                                                break;
                                    default:    Open_Playlist_Menu (playlist_name);
                                                break;
                                }
                                break;
                        case 2: printf ("\n1. Play in loop");
                                printf ("\n2. Do not play on loop\n> ");
                                scanf ("%d", &menu_opt);
                                system ("cls");
                                Play (playlist_num, menu_opt);
                                break;
                        case 3: main_menu ();
                                break;
                        default: Open_Playlist_Menu (playlist_name);
                                break;
                    }
        case "C":   printf("\nEnter playlist number to create: ");
                    scanf ("%d", &playlist_num);
                    system ("cls");
                    create_playlist (playlist_num);
                    break;
        case "B":   main_menu ();
                    break;
        default:    Open_Playlist_Menu (playlist_name);
                    break;
    }
    return 0;
}