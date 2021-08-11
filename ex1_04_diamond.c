#include <stdio.h>


int diamondTopHalf(int num, int level) {
    if (num < 1) {
        return 0;
    }
    diamondTopHalf(num-2,level+1);
    for (int i = 0; i < level; i++) {
        printf(" ");
    }

    for (int i = 0; i < num; i++) {
        printf("*");
    }

    printf("\n");
}

int diamondBottomHalf(int num, int level) {
    if (num < 1) {
        return 0;
    }
    for (int i = 0; i < level; i++) {
        printf(" ");
    }

    for (int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
    diamondBottomHalf(num-2,level+1);
    }

int diamond(int num) {
    if (num % 2 == 0) {
        return -1;
    }
    
    return diamondTopHalf(num,0) + diamondBottomHalf(num-2,1);
}


int main() {
    int num = -1;
    diamond(num);
    return 0;
}