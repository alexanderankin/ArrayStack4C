#ifndef another_h
#define another_h

typedef struct _array_stack array_stack;

/**
 * Malloc
 */
array_stack *another_new(void);

/**
 * Free
 */
void another_free(array_stack *);

/**
 * getchar()
 */
int another_getchar(array_stack *);

/**
 * putchar()
 */
int another_putchar(array_stack *, int c);

/**
 * Reverses a string and puts it on the stack.
 */
void another_queue_string(array_stack *, char *, int);

/** void another_flush(array_stack *); */

#endif
