int play_next (struct PLAYLIST *point)
{
    point = point -> next;
    if (point == NULL)
    {
        printf ("\nPlaylist ended... Returnning to main menu... \n");
        Main_Menu ();
    }
    else
    {
        printf ("\nPlaying: %s by %s", point -> Song, point -> Song);
        ask_user (point);
    }
    return 0;
}