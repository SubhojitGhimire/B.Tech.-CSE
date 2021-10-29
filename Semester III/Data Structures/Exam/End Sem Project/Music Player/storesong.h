int Store_Song ()
{
    struct ALBUM *new_song = (struct ALBUM*) malloc (sizeof (struct ALBUM));
    
    char artist_name [30], song_name[50];
    printf ("\nArtist: ");
    scanf ("%[^\n]%*c", artist_name);
    printf ("Song: ");
    scanf ("%[^\n]%*c", song_name);

    strcpy (new_song -> Artist, artist_name);
    strcpy (new_song -> Song, song_name);

    new_song -> next = NULL;

    if (start == NULL)
    {
        start = new_song;
    }
    else
    {
        end -> next = new_song;
    }

    end = new_song;
    printf ("Song added to the Album\n");

    return 0;
}