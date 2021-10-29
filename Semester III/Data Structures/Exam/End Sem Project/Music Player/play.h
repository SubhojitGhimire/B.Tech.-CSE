int Play (int playlist_no, int loop)
{
    if (begin_list [playlist_no] == NULL)
    {
        printf ("\ncannot find songs to play...\n");
    }
    else
    {
        struct PLAYLIST *point = begin_list [playlist_no];
        if (loop)
        {
            begin_list [playlist_no] -> previous = end_list [playlist_no];
            end_list [playlist_no] -> next = begin_list [playlist_no];
        }
        else
        {
            begin_list [playlist_no] -> previous = NULL;
            end_list [playlist_no] -> next = NULL;
        }
        printf ("\nPlaying: %s by %s\n", point -> Song, point -> Artist);
        ask_user (point);
    }
    return 0;
}

