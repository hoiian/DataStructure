#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

typedef struct node {
   int  data;
   struct node  *np;
}  node;


void traverse( node *start ) {
    node *prev, *cur;
    cur = prev = start;

    while ( cur ) {
        printf( "%d, ", cur->data );
        if ( cur->np == cur )
            // done
            break;
        if ( cur == prev )
            cur = cur->np;   // start of list
        else {
            node *save = cur;
            cur = (node*)((uintptr_t)prev ^ (uintptr_t)cur->np);
            prev = save;
         }
      }
      printf("\n");
}

node* newnode( node *prev, node *cur, int data ) {
    node *next;

    next = (node*)malloc(sizeof( node ));
    next->data = data;
    next->np = cur;  // end node points to previous one

    if ( cur == NULL )
        ; // very first node - we'll just return it
    else if ( prev == NULL ) {
        // this is the second node (they point at each other)
        cur->np = next;
        next->np = cur;
    }
    else {
        cur->np = (node*)((uintptr_t)prev ^ (uintptr_t)next);
    }

    return next;
}

int main( int argc, char* argv[] )
{
    node *head, *tail;
    int data = 1;
    int i;

    // the first two nodes point at each other.
    head = tail = newnode( NULL, NULL, data++ );
    tail = newnode( NULL, tail, data++ );

    for(i=0;i<18;i++){
        tail = newnode( tail->np, tail, data++ );
    }

    printf( "Forwards: from left to right\n" );
    traverse( head );
    printf( "Backwards: from right to left\n" );
    traverse( tail );
}