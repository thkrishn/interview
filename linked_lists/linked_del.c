// delete a key  in LL 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
	int data;
	struct node* next;
};

struct node* append(struct node* head, int num);
struct node* addatthebeg(struct node* head, int num);
void printlist(struct node* q);

struct node* deleteKey(struct node *head, int key)
{
    struct node* temp_del = NULL;
    struct node* temp = head;

    while(temp->next != NULL){
        //printf("%d --",temp->data);
        if (temp->next->data == key ){
            temp_del = temp->next;
            temp->next = temp->next->next;
            free(temp_del);
        }
        else temp = temp->next;
    }

    if (head->data == key){
        temp_del = head;
        head = head->next;
        free(temp_del);
    }
    
    return head;
}


int main()
{
    struct node* head = NULL;
    
    printf("\nThis the elements in the linked list\n");
    head = append(head,1);
    head = append(head,2);
    head = append(head,3);
    head = append(head,4);
    head = append(head,5);
    head = append(head,10);
    head = append(head,10);
    head = append(head,10);
    head = append(head,10);

    //printlist(head);

    printf("\nThis is adding the 3 elements  list\n");
	
    head = addatthebeg(head,8);
    head = addatthebeg(head,9);
    head = addatthebeg(head,10);
    head = addatthebeg(head,11);
    head = addatthebeg(head,12);
    head = addatthebeg(head,13);
    head = addatthebeg(head,10);

    printlist(head);

    head = deleteKey(head,10);
    printf("\n After the key has been deleted \n");

    printlist(head);

}

void printlist(struct node* head)
{
	struct node* temp = head;
	if (head == 0){
		printf("The provided address is NULL  \n" );
		return;
	}

	while(temp != NULL){
    	printf("The element is %4d  \n" ,temp->data);
    	//printf ("%4d -> ",temp->data);
    	temp = temp->next;
	}

	printf("\n");
}


struct node* append(struct node* head , int num)
{
	struct node *temp1,*temp2;

	temp1 = head;

	if (head == NULL){ // If the node is the first element
    	temp1 = (struct node*) malloc(sizeof(struct node));
    	temp1->data = num ;
    	temp1->next = NULL;
    	return temp1;
	}
	
	else{
    	
        while (temp1->next != NULL)// go to the last node
        	temp1 = temp1->next;

        temp2 = (struct node*) malloc(sizeof(struct node));
        temp2->data = num ;
        temp2->next = NULL;
        temp1->next = temp2;
	}
	return head;
}

struct node* addatthebeg(struct node* head, int num)
{
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num;
    temp->next = head;
    return temp;
}
