int ask_user (struct PLAYLIST *point)
{
    char next_prev;
    printf ("\n This song had ended... Play Next (N)/ Previous (P)\n> ");
    scanf ("%c", next_prev);
    if (next_prev == 'N' || next_prev == 'n')
    {
        play_next (point, i);
    }
    else if (next_prev == 'P' || next_prev == 'p')
    {
        play_previous (point, i);
    }
    else
    {
        Main_Menu ();
    }
    
    return 0;
}