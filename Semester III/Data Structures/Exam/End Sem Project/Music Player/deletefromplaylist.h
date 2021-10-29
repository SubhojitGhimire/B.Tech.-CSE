int Delete_from_Playlist (int playlist_no, int list_num)
{
    if (list_num == 1)
    {
        begin_list [playlist_no] -> next = begin_list [playlist_no];
    }
    else
    {
        struct PLAYLIST *point = begin_list [playlist_no];

        for (int i=2; i<list_num; ++i)
        {
            point = point -> next;
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

    printf ("\nRequested song Deleted from the playlist...\n");
    return0;
}