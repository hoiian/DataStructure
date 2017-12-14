#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(x,y)  ( x>y?x:y )

struct node
{
    int key;
    struct node *left, *right;
};

int height=1;

int minDepth(struct node *root)
{
    // Corner case. Should never be hit unless the code is 
    // called on root = NULL
    if (root == NULL)
        return 0;
 
    // Base case : Leaf Node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
       return 1;
 
    // If left subtree is NULL, recur for right subtree
    if (root->left != NULL)
       return minDepth(root->right) + 1;
 
    // If right subtree is NULL, recur for right subtree
    if (root->right != NULL)
       return minDepth(root->left) + 1;
 
    return max(minDepth(root->left), minDepth(root->right)) + 1;
}

int maxDepth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void printkey(struct node *root){
    if(root != NULL){
        printf("%-3d", root->key);
    }else printf("*  ");
}

void printchild(struct node *root)
{
    struct node *temleft;
    struct node *temright;
    int i;
    // printf("%d ", root->key);
    // printf("\n");
    // print(root->left);
    // print(root->right);
    
    // temleft = root->left;
    // temright = root->right;
    // print(temleft);
    
    // while(root != NULL){
        
        if(root == NULL ){
            printf("*  *  ");
        }else {
            temleft = root->left;
            temright = root->right;
            printkey(temleft);
            printkey(temright);
            printf("\n");
            printkey(temleft->left);
            printkey(temleft->right);
            printkey(temright->left);
            printkey(temright->right); 
            printf("\n");
            // if((temleft != NULL || temright != NULL)){
            // printchild(temleft);
            // printchild(temright);
            // printf("\n");
            // }
        }

        
    // }
    // printf("\n");
        // print(temleft);

}

void print(struct node *root)
{
    struct node *temleft;
    struct node *temright;
    temleft = root->left;
    temright = root->right;
    int i;

    // if(temleft != NULL || temright != NULL){
        // printkey(root);
        // printf("\n");
        // printchild(root);
        // printf("\n");
        printchild(temleft);
        // printf("/");
        printchild(temright);
        printf("\n");
        // printf("\n");
        printchild(temleft->left);
        printchild(temleft->right);
        printchild(temright->left);
        printchild(temright->right);
        // if(temleft != NULL && root != NULL){
        //     print(temleft);
        //     printf("\n");
        // }
        // if(temright != NULL && root != NULL){
        //     print(temright);
        //     printf("\n");
        // }
        
    // } else
    

}

void printtree(struct node **head_node)
{
    struct node *head;
    head = *head_node;
    if(head == NULL)
    {
        printf("* \n");
        return;
    }
    else
    {
        printkey(head);
        printchild(head);
        printchild(head->left);
        printchild(head->right);
        printtree(&(head->left));
        // printtree(&(head->right));
    }
}

// void PrintTree(struct node *root, int leftAlignment, int level)
// {
//      if (root==NULL)
//      {
//          return;
//      }

//      printf("%d,%d", level, leftAlignment * 4);
//      printf("%d",root->key);

//      PrintTree(root->left, leftAlignment - 1, level + 1);
//      PrintTree(root->right, leftAlignment + 1, level + 1);
// }



struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    // temp->left->key = temp->right->key = -1;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


int main() {

    struct node *root = NULL;
    // root = insert(root, 16);
    // root = insert(root, 5);
    // root = insert(root, 31);
    // root = insert(root, 2);
    // root = insert(root, 7);
    // root = insert(root, 49);
    // root = insert(root, 6);
    // root = insert(root, 44);
    // root = insert(root, 82);
    // root = insert(root, 30);

    int ch;
    // do{
    //     ch = getchar();
    //     printf("%c", ch);
    // }while(ch!=','|| ch!='\n');
    
    // 16,5,31,2,7,49,6,44,82
    // char str[256];
    char str[]="16,5,31,2,7,49,6,44,82";
    // scanf("%s",str);
    char *pt;
    pt = strtok (str,",");
    while (pt != NULL) {
        int a = atoi(pt);
        // printf("%d\n", a);
        root = insert(root, a);
        pt = strtok (NULL, ",");
    }

    printf("depth:%d\n",maxDepth(root));
// 
    // preorder(root);
    // printtree(&root);
    // print(root);
    printchild(root);
    // PrintTree(root,0,0);
    return 0;
}
