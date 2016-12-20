#ifndef another_h
#define another_h

typedef struct _another another_stream;

/**
 * Malloc
 */
another_stream *another_new(void);

/**
 * Free
 */
void another_free(another_stream *);

/**
 * getchar()
 */
int another_getchar(another_stream *);

/**
 * putchar()
 */
int another_putchar(another_stream *, int c);

/**
 * Reverses a string and puts it on the stack.
 */
void another_queue_string(another_stream *, char *, int);

/** void another_flush(another_stream *); */

#endif
