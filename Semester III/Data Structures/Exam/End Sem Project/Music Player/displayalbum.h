int Display_Album ()
{
    if (start == NULL)
    {
        printf ("\nYour Music Player is Empty... Start Adding Songs...\n");
    }
    else
    {
        printf ("\nYour Music List:");
        struct ALBUM *point = start;
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