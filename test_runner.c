#include <stdio.h>
#include <assert.h>

#include "stack_array.h"

int main(int argc, char const *argv[])
{
  char stat[] = "example";

  array_stack *mystream = array_stack_new();

  assert( array_stack_getchar( mystream ) == EOF );

  array_stack_queue_string( mystream, stat, sizeof(stat) );

  assert( array_stack_getchar( mystream ) == 'e' );
  assert( array_stack_getchar( mystream ) == 'x' );
  assert( array_stack_getchar( mystream ) == 'a' );

  array_stack_putchar( mystream, 1 );
  assert( array_stack_getchar( mystream ) == 1 );

  assert( array_stack_getchar( mystream ) == 'm' );
  assert( array_stack_getchar( mystream ) == 'p' );
  assert( array_stack_getchar( mystream ) == 'l' );
  assert( array_stack_getchar( mystream ) == 'e' );
  assert( array_stack_getchar( mystream ) == EOF );
  assert( array_stack_getchar( mystream ) == EOF );
  assert( array_stack_getchar( mystream ) == EOF );

  array_stack_free( mystream );

  return 0;
}
