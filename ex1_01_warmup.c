#include <stdio.h>

int main() {
    char input;
    while (1) {
        scanf("%c", &input);
        if (input == 'Q' || input == 'q') {
            return 0;
        }
        printf("%c", input);
    }
}