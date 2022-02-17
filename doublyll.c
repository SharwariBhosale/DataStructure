#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insert node at the front
void insertFront(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  newNode->next = (*head);

  newNode->prev = NULL;

  if ((*head) != NULL)
    (*head)->prev = newNode;

  (*head) = newNode;
}


// delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* del_node) {

  if (*head == NULL || del_node == NULL)
    return;

  if (*head == del_node)
    *head = del_node->next;

  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  free(del_node);
}


// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}


void main ()  
{  
int n,choice =0;  
struct Node* head = NULL;
    while(choice !=4)  
    {  
        printf("\nChoose the operation\n");    
        printf("\n1.Insert in begining\n2.Delete\n3.Display\n4.Quit\n");  
        printf("\nEnter your choice:\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
	    printf("Enter the number that you want to insert:-\n");
	    scanf("%d",&n);
            insertFront(&head, n);
            break;  

            case 2:  
            deleteNode(&head,head);
            break;  

            case 3:  
            displayList(head);
            break; 

            case 4:  
            printf("\nThank You!\n");
            break;    
            default:  
            printf("Please enter valid choice!!!");  
        }  
    }  
}  

