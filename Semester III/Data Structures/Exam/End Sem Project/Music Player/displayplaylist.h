int Display_Playlist (int playlist_no)
{
    if (begin_list [playlist_no] == NULL)
    {
        printf ("\nIt's lonely in this Playlist... Add some tunes\n");
    }
    else
    {
        printf ("\nYour Music List:");
        struct PLAYLIST *point = begin_list [playlist_no];
        int i = 1;

        do
        {
            printf ("\n%d. %s by %s", i, point -> Song, point -> Artist);
            point = point -> next;
            ++i;
        }while (point != end);
        printf ("\n%d. %s by %s\n", i, end -> Song, end -> Artist);
    }
    
    return 0;
}