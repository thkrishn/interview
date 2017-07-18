/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    Node* first = head;
    Node* second = head;
    
    while (positionFromTail != 0){
        first = first->next;
        positionFromTail--;
    }
    first = first -> next;
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    
    if (second != NULL)
        return second->data;
    
    return -1;
}

