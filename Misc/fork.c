#include <stdio.h>
#include <stdint.h>

int main (void) {
int pid = 0;
pid = fork();
if (pid) {
  printf("parent");
  sleep(5);
} else
  printf("child");
  //sleep(1);
return 0;
}
