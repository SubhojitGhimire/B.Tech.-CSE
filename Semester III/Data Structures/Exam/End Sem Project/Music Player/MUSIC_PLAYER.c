#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char playlist_name [10][20] = {"Create", "Create", "Create", "Create", "Create", "Create", "Create", "Create", "Create", "Create"};

struct PLAYLIST
{
    char Artist [30], Song [50];
    struct PLAYLIST *next, *previous;
} *begin_list [10], *end_list [10];

struct ALBUM
{
    char Artist [30], Song [50];
    struct ALBUM *next;
} *start = NULL, *end = NULL;

int music_player();
int main_menu ();
int Open_Playlist_Menu (char playlist_name [10][20]);
void Store_Song ();
int Delete_Song (int position);
void Display_Album ();
int create_playlist (int playlist_no, char playlist_name [10][20]);
int Add_in_Playlist (int playlist_no);
int Delete_from_Playlist (int playlist_no, int list_num);
int Display_Playlist (int playlist_no);
int play_next (struct PLAYLIST *point);
int play_prev (struct PLAYLIST *point);
int ask_user (struct PLAYLIST *point);
int Play (int playlist_no, int loop);

int main()
{
    system ("cls");
    music_player();
    return 0;
}

int music_player()
{
    system ("cls");
    printf ("\n####################################\n");
    printf ("########### MUSiC PLAYER ###########\n");
    printf ("####################################\n");
    printf ("\nContinue? Y/N...\n> ");
    char option ['!'];
    scanf ("%s", &option);
    if (option [0] == 'y' || option [0] == 'Y')
    {
        system ("cls");
        main_menu ();
    }
    return 0;    
}

int main_menu ()
{
    system ("cls");
    Display_Album ();
    printf ("\n\nMenu(M)\t\tOpen Playlist(O)\tBack(B)\n> ");
    char option_char ['!'];
    int option_int;
    int menu_opt, song_num;

    scanf ("%s", &option_char);
    option_char [0] = toupper (option_char [0]);
    option_int = (int) option_char[0];
    switch (option_int)
    {
        case 77:   printf ("\n1. Add Song");
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
        case 79:   system ("cls");
                    Open_Playlist_Menu (playlist_name);
                    break;
        case 66:   music_player ();
                    break;
        default :   main_menu ();
                    break;
     }
    return 0;
}

int Open_Playlist_Menu (char playlist_name [10][20])
{
    system ("cls");
    for (int i=0; i<10; ++i)
    {
        printf ("\n%d. %s", i+1, playlist_name [i]);
    }
    printf ("\n\nMenu(M)\t\tCreate Playlist(C)\tBack(B)\n> ");
    char option_char['!'];
    int option_int;
    scanf ("%s", &option_char);
    option_char [0] = toupper (option_char[0]);
    option_int = (int) option_char [0];
    int menu_opt, playlist_num, song_num;
    switch (option_int)
    {
        case 77:   printf ("\n1. Open Playlist");
                    printf ("\n2. Play Playlist");
                    printf ("\n3. Back\n> ");
                    scanf ("%d", &menu_opt);
                    switch (menu_opt)
                    {
                        case 1: printf ("\nSelect playlist by it's serial number to open it: ");
                                scanf ("%d", &playlist_num);
                            displayplaylist:
                                system ("cls");
                                Display_Playlist (playlist_num);
                                printf ("\n\nMenu(M)\t\tPlay(P)\t\tBack(B)\n> ");
                                scanf ("%s", &option_char);
                                option_char[0] = toupper (option_char [0]);
                                option_int = (int) option_char [0];
                                switch (option_int)
                                {
                                    case 77:   printf ("\n1. Add Song to this playlist");
                                                printf ("\n2. Delete Song from this playlist");
                                                printf ("\n3. Back to Playlist Menu\n> ");
                                                scanf ("%d", &menu_opt);
                                                switch (menu_opt)
                                                {
                                                    case 1: Add_in_Playlist (playlist_num);
                                                            goto displayplaylist;
                                                            break;
                                                    case 2: printf ("\nSelect song serial number to delete it: ");
                                                            scanf ("%d", &song_num);
                                                            Delete_from_Playlist (playlist_num, song_num);
                                                            goto displayplaylist;
                                                            break;
                                                    case 3: Open_Playlist_Menu (playlist_name);
                                                            break;
                                                    default:Open_Playlist_Menu (playlist_name);
                                                            break;
                                                }
                                                break;
                                    case 80:   printf ("\n1. Play in loop");
                                                printf ("\n2. Do not play on loop\n> ");
                                                scanf ("%d", &menu_opt);
                                                system ("cls");
                                                Play (playlist_num, menu_opt);
                                                goto displayplaylist;
                                                break;
                                    case 66:   Open_Playlist_Menu (playlist_name);
                                                break;
                                    default:    Open_Playlist_Menu (playlist_name);
                                                break;
                                }
                                break;
                        case 2: printf ("Play playlist serial number?\n> ");
                                scanf ("%d", &playlist_num);
                                printf ("\n\n1. Play in loop");
                                printf ("\n2. Do not play on loop\n> ");
                                scanf ("%d", &menu_opt);
                                system ("cls");
                                Play (playlist_num, menu_opt);
                                Open_Playlist_Menu (playlist_name);
                                break;
                        case 3: Open_Playlist_Menu (playlist_name);
                                break;
                        default: Open_Playlist_Menu (playlist_name);
                                break;
                    }
                    break;
        case 67:   printf("\nEnter playlist number to create: ");
                    scanf ("%d", &playlist_num);
                    create_playlist (playlist_num, playlist_name);
                    system ("cls");
                    Open_Playlist_Menu (playlist_name);
                    break;
        case 66:   main_menu ();
                    break;
        default:    Open_Playlist_Menu (playlist_name);
                    break;
    }
    return 0;
}

void Store_Song ()
{
    struct ALBUM *new_song = (struct ALBUM*) malloc (sizeof (struct ALBUM));
    
    char artist_name [30], song_name[50];
    printf ("\nArtist: ");
    scanf (" %[^\n]%*c", artist_name);
    printf ("Song: ");
    scanf (" %[^\n]%*c", song_name);
    printf ("\nSearching the song on the web...");
    sleep (1);
    printf ("\nSong Found... Downloading");
    for (int i=0; i < 3; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            printf (".");
            sleep (1);
        } 
        for (int j=0; j<3; ++j)
        {
            printf ("\b");
        } 
        for (int j=0; j<3; ++j)
        {
            char ch = 255;
            printf ("%c", ch);
        }
        for (int j=0; j<3; ++j)
        {
            printf ("\b");
        } 
    }

    strcpy (new_song -> Artist, artist_name);
    strcpy (new_song -> Song, song_name);

    printf ("\nDownload Complete...\n");

    new_song -> next = NULL;

    if (start == NULL)
    {
        start = new_song;
    }
    else
    {
        end -> next = new_song;
    }

    end = new_song;
    printf ("Song added to the Album\n");
    sleep (2);

    return;
}

int Delete_Song (int position)
{
    if (position == 1)
    {
        start = start -> next;
    }
    else
    {
        struct ALBUM *point = start;
        for (int i=2; i<position; ++i)
        {
            point = point-> next;
        }

        if (point -> next == end)
        {
            end = point;
        }
        else
        {
            point -> next = (point -> next) -> next;
        }
    }
    
    printf ("\nRequested Song Deleted from the Album\n");
    sleep (2);
    return 0;
}

void Display_Album ()
{
    int i = 1;
    system ("cls");
    if (start == NULL)
    {
        printf ("\nYour Music Player is Empty... Start Adding Songs...\n");
    }
    else
    {
        printf ("\nYour Music List:");
        if (start != end)
        {
            struct ALBUM *point = start;
            do
            {
                printf ("\n%d. %s by %s", i, point -> Song, point -> Artist);
                point = point -> next;
                ++i;
            }while (point != end);
        }
        printf ("\n%d. %s by %s\n", i, end -> Song, end -> Artist);
    }
    return;
}

int create_playlist (int playlist_no, char playlist_name [10][20])
{
    system ("cls");
    printf ("\nEnter Playlist Name: ");
    begin_list [playlist_no - 1] = end_list [playlist_no - 1] = NULL;
    scanf (" %[^\n]%*c", playlist_name [playlist_no - 1]);
    if (playlist_name [playlist_no - 1][0] == '\n')
    {
        char temp [11] = "PLAYLIST ";
        temp [9] = playlist_no - '0';
        temp [10] = '\n';
        strcpy (playlist_name [playlist_no - 1], temp);
    }
    return 0;
}

int Add_in_Playlist (int playlist_no)
{   
    system ("cls");
    Display_Album ();
    printf ("\nEnter Song serial number to add to the playlist:\n> ");
    int list_num;
    scanf ("%d", &list_num);
    struct ALBUM *point = start;
    for (int i=1; i<list_num; ++i)
    {
        point = point -> next;
    }

    struct PLAYLIST *add_song = (struct PLAYLIST*) malloc (sizeof (struct PLAYLIST));
    strcpy (add_song -> Artist, point -> Artist);
    strcpy (add_song -> Song, point -> Song);

    add_song -> next = NULL;

    if (begin_list [playlist_no - 1] == NULL)
    {
        begin_list [playlist_no - 1] = add_song;
        begin_list [playlist_no - 1] -> previous = NULL;
    }
    else
    {
        add_song -> previous = end_list [playlist_no - 1];
        end_list [playlist_no - 1] -> next = add_song;
    }
    end_list [playlist_no - 1] = add_song;
    return 0;
}

int Delete_from_Playlist (int playlist_no, int list_num)
{
    if (list_num == 1)
    {
        begin_list [playlist_no - 1] -> next = begin_list [playlist_no - 1];
    }
    else
    {
        struct PLAYLIST *point = begin_list [playlist_no - 1];

        for (int i=2; i<list_num; ++i)
        {
            point = point -> next;
        }
        if (point -> next == end_list [playlist_no - 1])
        {
            end_list [playlist_no - 1] = point;
        }
        else
        {
            point -> next = (point -> next) -> next;
        }
    }

    printf ("\nRequested song Deleted from the playlist... Returning back to playlist... Please Wait...\n");
    sleep (2);
    return 0;
}

int Display_Playlist (int playlist_no)
{
    if (begin_list [playlist_no - 1] == NULL)
    {
        printf ("\nIt's lonely in this Playlist... Add some tunes\n");
    }
    else
    {
        printf ("\nYour Music List:");
        struct PLAYLIST *point = begin_list [playlist_no - 1];
        int i = 1;
        if (begin_list [playlist_no - 1] != end_list [playlist_no - 1])
        {
            do
            {
                printf ("\n%d. %s by %s", i, point -> Song, point -> Artist);
                point = point -> next;
                ++i;
            }while (point != end_list [playlist_no - 1]);
        }   
        printf ("\n%d. %s by %s\n", i, point -> Song, point -> Artist);
    }
    
    return 0;
}

int play_next (struct PLAYLIST *point)
{
    point = point -> next;
    if (point == NULL)
    {
        printf ("\nPlaylist ended... Returning to Music Menu... \n");
        sleep (2);
        main_menu ();
    }
    else
    {
        srand (time (NULL));
        printf ("\nPlaying: %s by %s", point -> Song, point -> Artist);
        printf ("\n\n### Lyrics available to premium members only ###\n\n");
        int song_length = (rand () % 10) + 1;
        for (int i=0; i<song_length; ++i)
        {
            for (int j=0; j<30; ++j)
            {
                int equaliser = rand () % 2;
                if (equaliser)
                    printf (".");
                else
                    printf (":");
            }
            for (int j=0; j<30; ++j)
                printf ("\b");
            sleep (1);
        }
        ask_user (point);
    }
    return 0;
}

int play_prev (struct PLAYLIST *point)
{
    point = point -> previous;
    if (point == NULL)
    {
        printf ("\nNo Previous Songs... Returning to Music Menu...\n");
        sleep (2);
        main_menu ();
    }
    else
    {   
        srand (time (NULL));
        printf ("\nPlaying: %s by %s", point -> Song, point -> Artist);
        printf ("\n\n### Lyrics available to premium members only ###\n\n");
        int song_length = (rand () % 10) + 1;
        for (int i=0; i<song_length; ++i)
        {
            for (int j=0; j<30; ++j)
            {
                int equaliser = rand () % 2;
                if (equaliser)
                    printf (".");
                else
                    printf (":");
            }
            for (int j=0; j<30; ++j)
                printf ("\b");
            sleep (1);
        }
        ask_user (point);
    }
    return 0;
}

int ask_user (struct PLAYLIST *point)
{
    char next_prev ['!'];
    printf ("\nThis song had ended... Play Next (N)/ Previous (P)\n> ");
    scanf ("%s", &next_prev);
    system ("cls");
    if (next_prev[0] == 'N' || next_prev[0] == 'n')
    {
        play_next (point);
    }
    else if (next_prev[0] == 'P' || next_prev[0] == 'p')
    {
        play_prev (point);
    }
    else
    {
        printf ("Invalid Selection... Returning to Music Menu...");
        sleep (2);
        printf ("\nPlease hold...");
        sleep (1);
        main_menu ();
    }
    
    return 0;
}

int Play (int playlist_no, int loop)
{
    if (begin_list [playlist_no - 1] == NULL)
    {
        printf ("\ncannot find songs to play...\n");
    }
    else
    {
        srand (time (NULL));
        struct PLAYLIST *point = begin_list [playlist_no - 1];
        if (loop == 1)
        {
            begin_list [playlist_no - 1] -> previous = end_list [playlist_no - 1];
            end_list [playlist_no - 1] -> next = begin_list [playlist_no - 1];
        }
        else
        {
            begin_list [playlist_no - 1] -> previous = NULL;
            end_list [playlist_no - 1] -> next = NULL;
        }
        printf ("\nPlaying: %s by %s\n", point -> Song, point -> Artist);
        printf ("\n\n### Lyrics available to premium members only ###\n\n");
        int song_length = (rand () % 10) + 1;
        for (int i=0; i<song_length; ++i)
        {
            for (int j=0; j<30; ++j)
            {
                int equaliser = rand () % 2;
                if (equaliser)
                    printf (".");
                else
                    printf (":");
            }
            for (int j=0; j<30; ++j)
                printf ("\b");
            sleep (1);
        }
        ask_user (point);
    }
    return 0;
}