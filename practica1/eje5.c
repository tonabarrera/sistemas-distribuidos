#include <stdio.h>

int main(int argc, char const *argv[]){
    int n = 2;
    n = n + (++n);
    printf("%d\n", n);
    return 0;
}