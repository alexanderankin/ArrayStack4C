#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "another.h"

struct _array_stack
{
  int size;
  int pointer;
  int *array;
};

array_stack *
array_stack_new(void)
{
  array_stack *stack = malloc( sizeof(*stack) );

  stack->size           = 1;
  stack->pointer        = 0;
  stack->array    = malloc( sizeof(*stack->array) );
  *stack->array   = EOF;

  return stack;
}

void
array_stack_free(array_stack *stack)
{
  if (stack->array)
  {
    free(stack->array);
    stack->array = NULL;
  }
  if (stack)
  {
    free(stack);
    stack = NULL;
  }
}

int
array_stack_getchar(array_stack *stack)
{
  if (stack->pointer < 1)
    return EOF;

  else
    return stack->array[stack->pointer--];
}

int array_stack_putchar(array_stack *stack, int c)
{
  int * temp = realloc(stack->array, stack->size + sizeof(*temp) * sizeof(c));
  if (temp == NULL)
    ; // failed
  else
  {
    stack->array = temp;
    stack->size += 1;
  }

  stack->array[++stack->pointer] = c;
}

static void fix_and_move(array_stack *, int);

static
void
fix_and_move (array_stack *stack, int length)
{
  int *temp = realloc(
    stack->array,
    stack->size + ( sizeof(int) * length ) + sizeof(int) * 1);

  if (temp == NULL)
    printf("Could not reallocate things.\n");

  else
    stack->array = temp;

  memmove( stack->array + length,
    stack->array,
    stack->size );

  stack->size += length;
}

static void string_rev(char *);

static
void
string_rev(char *str)
{
  char *end = str + strlen(str);
  while (str < end)
    {
      do { *str ^= *end; *end ^= *str; *str ^= *end; } while (0);
      str++;
      end--;
    }
}

void
array_stack_queue_string( array_stack *stack,
  char *string, int length )
{
  string_rev( string );

  if (stack->size < stack->pointer + length + 1)
  {
    fix_and_move( stack, length );
  }

  else
  {
    int **s_arr = &stack->array;
    memmove( *s_arr + length, *s_arr, stack->size );
  }


  for (int i = 0; i < length; ++i)
  {
    stack->array[i] = string[i];
  }

  stack->pointer += length - 1;
}
