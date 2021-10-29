int play_prev (struct PLAYLIST *point, int i)
{
    point = point -> previous;
    if (point == NULL)
    {
        printf ("\nNo Previous Songs...\n");
        Main_Menu ();
    }
    else
    {
        printf ("\nPlaying: %s by %s", point -> Song, point -> Song);
        ask_user (point);
    }
    return 0;
}