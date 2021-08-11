#include <stdio.h>

int mystrlen(const char* start) {
   const char* end = start;
   for ( ; *end != '\0'; ++end);
   return end - start;
}

int main() {
    char str[] = "hello world!";
    printf("the length of the string is %d", mystrlen(str));
    return 0;
}