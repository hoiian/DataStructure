#include <stdio.h>
#include <stdint.h>  // gcc needs this for intptr_t.  

typedef struct xorll {
   int  value;
   struct xorll  *np;
}  xorll;


// traverse the list given either the head or the tail
void traverse( xorll *start )  // point to head or tail
{
   xorll *prev, *cur;

   cur = prev = start;
   while ( cur )
      {
      printf( "%d, ", cur->value );
      if ( cur->np == cur )
         // done
         break;
      if ( cur == prev )
         cur = cur->np;   // start of list
      else {
         xorll *save = cur;
         cur = (xorll*)((uintptr_t)prev ^ (uintptr_t)cur->np);
         prev = save;
         }
      }
      printf("\n");
}

// create a new node adding it to the given end and return it
xorll* newnode( xorll *prev, xorll *cur, int value )
{
   xorll *next;

   next = (xorll*)malloc( sizeof( xorll ));
   next->value = value;
   next->np = cur;  // end node points to previous one

   if ( cur == NULL )
      ; // very first node - we'll just return it
   else if ( prev == NULL ) {
      // this is the second node (they point at each other)
      cur->np = next;
      next->np = cur;
      }
   else {
      // do the xor magic
      cur->np = (xorll*)((uintptr_t)prev ^ (uintptr_t)next);
      }

   return next;
}



int main( int argc, char* argv[] )
{
   xorll *head, *tail;
   int   value = 1;
   int i;

   // the first two nodes point at each other.  Weird param calls to
   // get the list started
   head = tail = newnode( NULL, NULL, value++ );
   tail = newnode( NULL, tail, value++ );

    for(i=0;i<18;i++){
        tail = newnode( tail->np, tail, value++ );
    }
   // now add a couple to the end
   
  // tail = newnode( tail->np, tail, value++ );

   // this is cool - add a new head node
  // head = newnode( head->np, head, 99 );


   printf( "Forwards: from left to right\n" );
   traverse( head );
   printf( "Backwards: from right to left\n" );
   traverse( tail );


}