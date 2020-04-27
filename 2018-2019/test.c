#include <stdio.h>
int main() {
    char c = 'A';
    void *p = &c;
    printf("%d",sizeof *(1?(int *)1:(long int *)2));
}

