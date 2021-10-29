#include <stdio.h> 
#include <stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* thead,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL)
    {           
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=thead;
    while(curr!=NULL && curr->expo>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==thead)
    {            
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL)
    {  
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return thead;
}

struct node* append(struct node* thead,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL)
    {
        newnode->next=NULL;
        return newnode;
    }
    struct node* trav=thead;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return thead;
}

struct node* polyaddition(struct node* p1thead,struct node* p2thead)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1thead;
    t2=p2thead;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL)
    {   
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL)
    { 
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* thead)
{
    printf ("\nThe final added polynomial is: ");
    struct node* temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            if(temp->coef == 0);
            else if(temp->coef == 1 && temp->expo == 1)
                printf("X+");
            else if(temp->coef == 1 && temp->expo != 0 && temp->expo != 1)
                printf("X^%d+",temp->expo);
            else if( temp->expo == 1)
                printf("%dX+",temp->coef);
            else
            printf("%dX^%d+",temp->coef,temp->expo);
            temp=temp->next;
        }
        if(temp->coef == 0);
        else if(temp->coef == 1 && temp->expo == 1)
            printf("X");
        else if(temp->coef == 1 && temp->expo != 0 && temp->expo != 1)
            printf("X^%d",temp->expo);
        else if( temp->expo == 0)
            printf("%d",temp->coef);
        else if( temp->expo == 1)
            printf("%dX",temp->coef);
        else
        printf("%dX^%d",temp->coef,temp->expo);
    }
}

int main() {
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    printf ("Enter Number of Terms in First Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf ("Coefficient ");
        scanf("%d",&a);
        printf ("Exponent ");
        scanf("%d",&b);
        p1head=insertpoly(p1head,a,b);
    }

    printf ("Enter Number of Terms in Second Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf ("Coefficient ");
        scanf("%d",&a);
        printf ("Exponent ");
        scanf("%d",&b);
        p2head=insertpoly(p2head,a,b);
    }
    
    p3head=polyaddition(p1head,p2head);

    display(p3head);
    
    return 0;
}