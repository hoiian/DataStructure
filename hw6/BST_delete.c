#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


#define max(x,y)  ( x>y?x:y )

struct node
{
    int key;
    int index;
    struct node *left, *right;
};

int myPow(int x,int n)
{
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}

int height;
int node_num;
int tree[100] = {0};

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

void printkey(struct node *root){
    if(root != NULL){
        printf("%d", root->key);
    }else printf("*  ");
}

void setindex(struct node *root)
{
    struct node *temleft;
    struct node *temright;
    // int i;
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
            int k = root->index;
            tree[root->index] = root->key;
            // printf("k=%d ",k);
            temleft = root->left;
            temright = root->right;

            if(temleft != NULL){
                temleft->index = k*2;
                printkey(temleft);
                printf("-(%d)  ", temleft->index);
                tree[temleft->index] = temleft->key;
            }else{
                printf("*  ");
            }
            
            if(temright != NULL){
                temright->index = k*2 +1;
                printkey(temright);
                printf("-(%d)  ", temright->index);
                tree[temright->index] = temright->key;
            }else{
                printf("*  ");
            }

            // printf("\n");
            // printkey(temleft->left);
            // printkey(temleft->right);
            // printkey(temright->left);
            // printkey(temright->right); 
            // printf("\n");
            // if((temleft != NULL || temright != NULL)){
            // setindex(temleft);
            // setindex(temright);
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
    if((root->left != NULL || root->right != NULL) && root != NULL){
    temleft = root->left;
    temright = root->right;
    // int i;

    // if(temleft != NULL || temright != NULL){
        // printkey(root);
        // printf("\n");
        setindex(root);
        if(temleft != NULL)
            print(temleft);
        if(temright != NULL)
            print(temright);
        // printf("\n");
        // setindex(temleft);
        // printf("/");
        // setindex(temright);
        // printf("\n");
        // printf("\n");
        // setindex(temleft->left);
        // setindex(temleft->right);
        // setindex(temright->left);
        // setindex(temright->right);

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

}

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    // temp->left->key = temp->right->key = -1;
    temp->index = -1;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key){
        node->left  = insert(node->left, key);

        // tree[node->index * 2] = node->left->key;
    }
    else{
        node->right = insert(node->right, key);
        // tree[node->index * 2 +1] = node->right->key;
    }
        
 
    /* return the (unchanged) node pointer */
    return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void finalprint(){
    int lev=1;
    int i;
    for(i=1; i<node_num-1;i++){
        if(tree[i]==0){
            printf("*  ");
        } else {
            printf("%-3d", tree[i]);
        }
    
        if(i==lev){
            lev = lev * 2 +1;
            printf("\n");
        }
    }
}

int havekey(key){
    int i;
    for(i=1; i<node_num-1; i++){
        if(tree[i]==key){
            return 1;
        }
    }
    return 0;
}

void cleankey(){
    int i;
    for(i=1; i<node_num-1;i++){
        if(tree[i]==0){
            // printf("*  ");
        } else {
            // printf("%-3d", tree[i]);
            tree[i] = 0;
            
        }

    }
}

int main() {

    struct node *root = NULL;
    char yesno;
    int element;

    // 16,5,31,2,7,49,6,44,82
    // char str[256];
    char str[]="16,5,31,2,1,7,49,6,44,82,30";
    // scanf("%s",str);
    char *pt;
    pt = strtok (str,",");
    while (pt != NULL) {
        int a = atoi(pt);
        // printf("%d\n", a);
        root = insert(root, a);
        pt = strtok (NULL, ",");
    }

    height = maxDepth(root);
    printf("height:%d\n",height);

    node_num = myPow(2,height)+1;
    printf("node num:%d\n", node_num);
    // tree[node_num];

    // tree[1] = root->key;
    root->index = 1;

    print(root);
    printf("\n");
    finalprint();

    while(1){
        printf("Delete element?(Y/N):");
        scanf("%c",&yesno);
        if(yesno=='Y'){
            printf("Choose element:");
            scanf("%d",&element);
            if(havekey(element)){
                deleteNode(root,element);
                cleankey();
                print(root);
                printf("\n");
                finalprint();
            }else{
                printf("%d is not in the tree.\n",element);
            }
            
            // tree[1] = root->key;
        }
        if(yesno=='N'){
            return 0;
        }
    }

    return 0;
}
