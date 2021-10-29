int music_player()
{
    system ("cls");
    printf ("\n####################################\n");
    printf ("########### MUSiC PLAYER ###########\n");
    printf ("####################################\n");
    printf ("\nContinue? Y/N...\n> ");
    char option ['!'];
    scanf ("%s", &option);
    if (strcmpi(option, "y"))
    {
        system ("cls");
        main_menu ();
    }
    return 0;    
}