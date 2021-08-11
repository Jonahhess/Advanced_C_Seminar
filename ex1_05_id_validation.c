#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int getCurrentDigit(int id, int i) {
    int idPrefix = id;
    for (int j = 0; j < i; j++) {
        idPrefix /= 10;
    }
    return idPrefix % 10;
}

int sumDigits(int id) {
    int currentDigit;
    int result = 0;

    for (int i = 0; i < 9; i = i + 2) {
        currentDigit = getCurrentDigit(id,i);
        result += currentDigit;
    }

    for (int i = 1; i < 9; i = i + 2) {
        currentDigit = getCurrentDigit(id,i) * 2;

        if (currentDigit > 9) {
            currentDigit -= 9;
        }
        result += currentDigit;
    }
    return result;
}

int validateID(int id) {
    if (id < 100000000 || id > 999999999) {
        return -1;
    }
    int sum = sumDigits(id);
    if (sum % 10 == 0) {
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));   // Initialization, should only be called once.
    int id;
    do {
        id = rand() % 1000000000;
    } while (validateID(id) != 0);
    printf("%d is a valid id!\n", id);
    return 0;
}