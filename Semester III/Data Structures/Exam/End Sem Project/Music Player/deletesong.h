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
    return 0;
}
