typedef struct _another another_stream;

another_stream *another_new(void);
void another_free(another_stream *);

int another_getchar(another_stream *);
int another_putchar(another_stream *, int c);

void another_queue_string(another_stream *, char *, int);
// void another_queue_char(another_stream *, int);

void another_flush(another_stream *);

