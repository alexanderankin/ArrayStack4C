#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "another.h"

struct _another
{
  int size;
  int pointer;
  // char *stack_array;
  int *stack_array;
};

another_stream *another_new(void)
{
  another_stream *stream = malloc(sizeof(*stream));
  stream->size = 1;
  // stream->pointer = 1;
  stream->pointer = 0;
  stream->stack_array = malloc(sizeof(*stream->stack_array));
  *stream->stack_array = EOF;
  return stream;
}

void another_free(another_stream *stream)
{
  if (stream->stack_array)
  {
    free(stream->stack_array);
    stream->stack_array = NULL;
  }
  if (stream)
  {
    free(stream);
    stream = NULL;
  }
}

int another_getchar(another_stream *stream)
{
  if (stream->pointer < 1)
  {
    return EOF;
  }
  else
  {
    return stream->stack_array[stream->pointer--];
  }
}

/*int another_getchar(another_stream *stream)
{
  if (stream->pointer > stream->size)
  {
    return EOF;
  }
  else
  {
    return stream->stack_array[stream->pointer++];
  }
}*/

int another_putchar(another_stream *stream, int c)
{
  int * temp = realloc(stream->stack_array, stream->size + sizeof(*temp) * sizeof(c));
  if (temp == NULL)
    ; // failed
  else
  {
    stream->stack_array = temp;
    stream->size += 1;
  }

  stream->stack_array[++stream->pointer] = c;
}

/*void *memmove(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n)
{
  int *temp = malloc(n * sizeof(*temp));
  for (int i = 0; i < n; ++i)
  {
    ((int *)temp)[i] = ((int *)src)[i];
  }
  // printf("memmove destination is %d / %p .\n", dest, dest);
  for (int i = 0; i < n; ++i)
  {
    ((int *)dest)[i] = ((int *)temp)[i];
  }
  free(temp);
}*/

static void fix_and_move(another_stream *, int);
static
void
fix_and_move (another_stream *stream, int length)
{
  int *temp = realloc(
    stream->stack_array,
    stream->size + (sizeof(int) * length) + sizeof(int) * 1);

  if (temp == NULL)
    printf("Could not reallocate things.\n");

  else
    stream->stack_array = temp;

  memmove(stream->stack_array + length,
    stream->stack_array,
    stream->size);

  stream->size += length;
}

void strrev(char *);
void strrev(char *str)
{
  char *end = str + strlen(str);
  while (str < end)
    {
      do { *str ^= *end; *end ^= *str; *str ^= *end; } while (0);
      str++;
      end--;
    }
}

void another_queue_string(another_stream *stream,
  char *string, int length)
{
  strrev(string);

  if (stream->size < stream->pointer + length + 1)
  {
    // printf("correct\n");
    fix_and_move(stream, length);
  }
    
  else
  {
    int **s_arr = &stream->stack_array;
    memmove(*s_arr + length, *s_arr, stream->size);
  }


  for (int i = 0; i < length; ++i)
  {
    stream->stack_array[i] = string[i];
  }

  stream->pointer += length - 1;
}

// void another_flush(another_stream *);
