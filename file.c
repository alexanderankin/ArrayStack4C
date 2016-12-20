#include <stdio.h>
#include <assert.h>

#include "another.h"

int main(int argc, char const *argv[])
{
  char stat[] = "example";

  array_stack *mystream = another_new();

  assert( another_getchar( mystream ) == EOF );

  another_queue_string( mystream, stat, sizeof(stat) );

  assert( another_getchar( mystream ) == 'e' );
  assert( another_getchar( mystream ) == 'x' );
  assert( another_getchar( mystream ) == 'a' );

  another_putchar( mystream, 1 );
  assert( another_getchar( mystream ) == 1 );

  assert( another_getchar( mystream ) == 'm' );
  assert( another_getchar( mystream ) == 'p' );
  assert( another_getchar( mystream ) == 'l' );
  assert( another_getchar( mystream ) == 'e' );
  assert( another_getchar( mystream ) == EOF );
  assert( another_getchar( mystream ) == EOF );
  assert( another_getchar( mystream ) == EOF );

  another_free( mystream );

  return 0;
}
