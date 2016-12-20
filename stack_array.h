#ifndef another_h
#define another_h

typedef struct _array_stack array_stack;

/**
 * Malloc
 */
array_stack *array_stack_new(void);

/**
 * Free
 */
void array_stack_free(array_stack *);

/**
 * getchar()
 */
int array_stack_getchar(array_stack *);

/**
 * putchar()
 */
int array_stack_putchar(array_stack *, int c);

/**
 * Reverses a string and puts it on the stack.
 */
void array_stack_queue_string(array_stack *, char *, int);

/** void another_flush(array_stack *); */

#endif
