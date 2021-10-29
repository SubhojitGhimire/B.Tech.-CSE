int create_playlist (int playlist_no, char playlist_name [10][20])
{
    printf ("\nEnter Playlist Name: ");
    begin_list [playlist_no] = end_list [playlist_no] = NULL;
    scanf ("%[^\n]%*c", playlist_name [playlist_no]);
    if (playlist_name [playlist_no][0] == "\n")
    {
        char temp [11] = "PLAYLIST ";
        temp [9] = playlist_no - '0';
        temp [10] = '\n';
        strcpy (playlist_name [playlist_no], temp);
    }

    return 0;
}
