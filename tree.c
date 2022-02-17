#include<stdio.h>
#include<stdlib.h>

struct node{
    char info;
    struct node *lptr;
    struct node *rptr;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

int main()
{
    struct node *a,*b,*c,*d,*e,*f,*g,*t;

    a = (struct node *)malloc(sizeof(struct node));
    b = (struct node *)malloc(sizeof(struct node));
    c = (struct node *)malloc(sizeof(struct node));
    d = (struct node *)malloc(sizeof(struct node));
    e = (struct node *)malloc(sizeof(struct node));
    f = (struct node *)malloc(sizeof(struct node));
    g = (struct node *)malloc(sizeof(struct node));

    t = a;

    a->info = 'A';
    a->lptr = b;
    a->rptr = d;

    b->info = 'B';
    b->lptr = c;
    b->rptr = NULL;

    c->info = 'C';
    c->lptr = NULL;
    c->rptr = NULL;

    d->info = 'D';
    d->lptr = e;
    d->rptr = g;

    e->info = 'E';
    e->lptr = NULL;
    e->rptr = f;

    g->info = 'G';
    g->lptr = NULL;
    g->rptr = NULL;

    f->info = 'F';
    f->lptr = NULL;
    f->rptr = NULL;

    printf("Preorder:\n");
    preorder(t);

    printf("\nInorder:\n");
    inorder(t);

    printf("\nPostorder:\n");
    postorder(t);

    return 0;


}

void preorder(struct node *t)
{
    if(t==NULL)
        printf("Empty tree");
    else
    {
        printf("%c ",t->info);
        if(t->lptr != NULL)
        {
            preorder(t->lptr);
        }
        if(t->rptr != NULL)
        {
            preorder(t->rptr);
        }
    }    
}

void inorder(struct node *t)
{
    if(t == NULL)
        printf("Empty tree");
    else
    {
        if(t->lptr != NULL)
        {
            inorder(t->lptr);
        }
        printf("%c ",t->info);

        if(t->rptr != NULL)
        {
            inorder(t->rptr);
        }
    }    
}

void postorder(struct node *t)
{
    if(t == NULL)
        printf("Empty tree");
    else 
    {
        if(t->lptr != NULL)
        {
            postorder(t->lptr);
        }
        if(t->rptr != NULL)
        {
            postorder(t->rptr);
        }
        printf("%c ",t->info);
    }    
}

