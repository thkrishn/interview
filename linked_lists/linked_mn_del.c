// C Program to delete all occurrences of a given key in linked list
#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct node
{
    int data;
    struct node *next;
};
 
/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}


// This function prints contents of linked list starting from
// the given node
void printList(struct node *node)
{
    int n = 10;
    while (node != NULL)
    {
        printf(" %p  %d \n", node , node->data);
        //printf(" test\n");
        node = node->next;
        n--;
        if (n == 0) break;
    }
}

struct node* reverseBetweenH(struct node* head, struct node* tail) {
    
    if (head == tail) return head;
    
    struct node* prev = tail;
    struct node* curr = head;
    struct node* next = NULL;
    
    while (curr != tail){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    //printList(prev);
    //printf("\n ");

    return prev;
    
}

struct node* reverseBetween(struct node* head, int m, int n) {
    
    if (head == NULL)
        return NULL;
        
    struct node* t1 = head;
    struct node* t2 = head;
    
    while(m-->1) t1=t1->next;
    
    while(n-->0) t2=t2->next;
    
    printf(" Linked List: %d \n ",t1->data);
    printf(" Linked List: %d  \n",t2->data);
    
    t1->next = reverseBetweenH(t1->next,t2->next);
    
    return head;
}





/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    push(&head,7);
    /*push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,5);  */  

    printf("Created Linked List: \n");
    printList(head);
    //while(m-->1) h1 = h1->next;
    //while(n-->0) h2 = h2->next;

    head = reverseBetween(head, 1, 1);

    //printf(" Linked List: %d \n ",h1->data);
    //printf(" Linked List: %d  \n",h2->data);

    //printf("Delete  Linked List: ");

    printList(head);
        
    printf("\n ");
    return 0;

}

