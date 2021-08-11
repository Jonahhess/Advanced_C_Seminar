#include <stdio.h>

int getCurrentDigit(int id, int i) {
    int idPrefix = id;
    for (int j = 0; j < i; j++) {
        idPrefix /= 10;
    }
    return idPrefix % 10;
}

int checkDigit(int incompleteID) {
    int currentDigit;
    int result = 0;

    for (int i = 1; i < 8; i = i + 2) {
        currentDigit = getCurrentDigit(incompleteID,i);
        result += currentDigit;
    }

    for (int i = 0; i < 8; i = i + 2) {
        currentDigit = getCurrentDigit(incompleteID,i) * 2;

        if (currentDigit > 9) {
            currentDigit -= 9;
        }
        result += currentDigit;
    }
    return result;    
}

int validateIncompleteID(int incompleteID) {
    if (incompleteID < 10000000 || incompleteID > 99999999) {
        return -1;
    }
    return (10 - checkDigit(incompleteID) % 10) % 10;
}
int main() {

    int incompleteID = 12345678;
    int checkDigit = validateIncompleteID(incompleteID);
    if (checkDigit < 0) {
        return -1;
    }
    printf("%d is the check digit!\n", checkDigit);
    return 0;
}