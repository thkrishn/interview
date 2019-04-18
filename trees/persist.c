/* program for boundary traversal of a binary tree */
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// A utility function to create a node
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

// A function to do boundary traversal of a given binary tree
void serialize (struct node* root, FILE* fd)
{
    if (root == NULL) {
      printf("%d ", -1);
      fprintf(fd, "%d ", -1);
      return;
    }

    printf("%d ", root->data);

    fprintf(fd, "%d ", root->data);
    //fwrite(root->data, sizeof(int), 1, fd);

    // Print the left boundary in top-down manner.
    serialize (root->left, fd);
    // Print all leaf nodes
    serialize(root->right, fd);

    // Print the right boundary in bottom-up manner
    //serialize(root->right);

}
void deserialize(struct node* root, FILE* fp) {
  int num;
  if ( fscanf(fp, "%d ", &num) == EOF)
    return;

  printf("%d ", num);
  // eerr = fscanf (&num);
   if(num == -1) {
       root = NULL;
       return;
   }

   //root = malloc(sizeof(node));
   root  = newNode(num);
   //root->data =  num;
   // root->left =  NULL;
   // root->right =  NULL;

   deserialize(root->left, fp);
   deserialize(root->right, fp);

}


// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    FILE* newFile;
    //char* ttt = "./someorder";
    newFile = fopen("./someorder.txt","w+");

    if (newFile == NULL){
        printf("FAILED \n");
        perror("fopen");
        exit(9);
    }


    printf("\nserialize \n");
    serialize(root, newFile);

    fclose(newFile);

    FILE* again = fopen("./someorder.txt","rb");

    if (again == NULL){
        printf("FAILED \n");
        perror("fopen");
        exit(9);
    }

    printf("\n------------");
    struct node* newstuff = NULL;

    printf("\n deserialize \n");
    deserialize(newstuff, again);

    fclose(again);

    return 0;
}
