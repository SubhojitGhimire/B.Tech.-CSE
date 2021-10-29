//Defining the structure of the set
struct SET
{
    int data;
    struct SET *next, *previous;
} *begin = NULL, *end = NULL;

//Function that takes the input for a set
int build (int user_value)
{
    struct SET *NEW = (struct SET*) malloc (sizeof (struct SET));
    NEW -> data = user_value;
    NEW -> next = NULL;
    if (begin == NULL)
    {
        NEW -> previous = NULL;
        begin = NEW;
    }
    else
    {
        NEW -> previous = end;
        end -> next = NEW;
    }
    end = NEW;

    return 0;
}

//Function that removes the positional data of the set or the entire set itself
int remove (int user_position = 0)
{
    if (!user_position)
    {
        begin = end = NULL;
    }

    else
    {
        if(user_position < ( (size() + 1) / 2))
        {
            struct SET *point = begin;
            for (int i=0; i < user_position; ++i, point = point -> next);
            if (point == begin)
            {
                begin = end = NULL;
            }
            else
            {
                (point -> next) -> previous = point -> previous;
                (point -> previous ) -> next = point -> next;
            }
        }    
        else 
        {
            struct SET *point = end;
            for (int i = size(); i > user_position; --i, point = point -> previous);
            if (point == end)
            {
                (end -> previous) -> next = NULL;
                end = end -> previous; 
            }
            else
            {
                (point -> next) -> previous = point -> previous;
                (point -> previous ) -> next = point -> next;
            }        
        }
    }
    return 0;    
}

//Displaying the positional data of the set or the entire content of the set (232)
int 