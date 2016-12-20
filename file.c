#include "stdio.h"
#include "stdlib.h"
#include "another.h"

int main(int argc, char const *argv[])
{
  char *stat = "example";
  // printf("%d\n", sizeof(stat));  // 8

  another_stream *mystream = another_new();
  another_queue_string(mystream, stat, sizeof(stat));


  another_free(mystream);

  return 0;
}

