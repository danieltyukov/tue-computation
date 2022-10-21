#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // Which is the correct way to malloc space for 10 integers?
  int *p = (int *)malloc(10 * sizeof(int));

}