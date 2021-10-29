struct PLAYLIST
{
    char Artist [30], Song [50];
    struct PLAYLIST *next, *previous;
} *begin_list [10], *end_list [10];

struct ALBUM
{
    char Artist [30], Song [50];
    struct ALBUM *next;
} *start = NULL, *end = NULL;