//Circular Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

//Display the list........
void cirdisplay(struct node *last) 
{
    struct node *p;
    if(last==NULL)
    {
        printf("\nList is empty");
        return;
    }
        p=last->next;
    do
        {
            printf("%d->",p->data);
            p=p->next;
        }
        while(p!=last->next);
        printf("\n");
}
//Insertion at beginning
struct node *ciraddbeg(struct node *last,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    if(last==NULL)
    {
        temp->data=num;
        last=temp;
        temp->next=last;
        return last;
    }
    else
    {
        temp->data=num;
        temp->next=last->next;
        last->next=temp;
        return last;
    }
}
//Function for insertion at the end
struct node *ciraddend(struct node *last,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}

//intermediate 

void ClLinsertNodeAtAny(int data, int pos)
{
    struct node *newnode, *curNode;
    struct node *last;
    int i,num;

    if(last == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else if(pos == 1)
    {
        last=ciraddbeg(last,num);
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        curNode = last;
        for(i=2; i<=pos-1; i++)
        {
            curNode = curNode->next;
        }
        newnode->next = curNode->next;
        curNode->next = newnode;
    }
} 

//Function to delete a number
struct node *cirdel(struct node *last,int num)
{
    printf("\nEnter the number to be deleted->");
    scanf("%d",&num);
    struct node *p,*temp;
    if(last==NULL)
    {
        printf("\nList is empty");
        return 0;
    }
    p=last;
    while(p->next->data!=num)
        p=p->next;
    temp=p->next;
    p->next=temp->next;
    if(temp==last)
    {
        last=p;
    }
    free(temp);
    return last;
}

void main()
{
    struct node *last=NULL;
    int choice,num,num2,insPlc,posi;
    while(1)
    {
        printf("\n**********Circular List*********");
        printf("\n1.Display");
        printf("\n2.Insert at begining");
        printf("\n3.Insert at end");
        printf("\n4.Insert intermediate");
        printf("\n5.Delete from list");
        printf("\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                cirdisplay(last);
                break;
            }
        case 2:
            {
                last=ciraddbeg(last,num);
                break;
            }
        case 3:
            {
                last=ciraddend(last,num);
                break;
            }
        case 4:
            {	
		    printf(" Input the position to insert a new node : ");
		    scanf("%d", &insPlc);
		    printf(" Input data for the position %d : ", insPlc);
		    scanf("%d", &posi);
		    ClLinsertNodeAtAny(posi,insPlc);  	
                break;
            }
        case 5:
            {
                last=cirdel(last,num);
                break;
            }
        case 6:
            {
                printf("Thank You!\n");
exit(1);
break;

            }
        default:
            printf("\nInvalid Choice");
break;
        }
    }
}
