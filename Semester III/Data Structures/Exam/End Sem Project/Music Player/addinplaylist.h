int Add_in_Playlist (int playlist_no)
{
    int list_num;
    scanf ("%d", &list_num);
    struct ALBUM *point = start;
    for (int i=0; i<list_num; ++i)
    {
        point = point -> next;
    }

    struct PLAYLIST *add_song = (struct PLAYLIST*) malloc (sizeof (struct PLAYLIST));
    strcpy (add_song -> Artist, point -> Artist);
    strcpy (add_song -> Song, point -> Song);

    add_song -> next = NULL;

    if (begin_list [playlist_no] == NULL)
    {
        begin_list = add_song;
        begin_list -> previous = NULL;
    }
    else
    {
        end_list [playlist_no] -> next = new_song;
    }
    end_list [playlist_no] = new_song;
    
    return 0;
}