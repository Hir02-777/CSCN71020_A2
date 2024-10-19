#include <stdio.h>
#include <stdbool.h>
#include "main.h"

int main() {
    int length = 1;
    int width = 1;
    bool continueProgram = true;

    while (continueProgram) {
        printWelcomeMenu();
        printOptions();

        int menuInput = getIntInput("Enter menu option number:");

        switch (menuInput) {
        case 1:
            printf("\nThe Rectangle has a length of %i and a width of %i\n\n", length, width);
            break;

        case 2:
            setLength(getIntInput("Please enter the length of the rectangle (1-99):"), &length);
            break;

        case 3:
            setWidth(getIntInput("Please enter the width of the rectangle (1-99):"), &width);
            break;

        case 4:
            printf("\nThe Rectangle has a perimeter of %i\n\n", getPerimeter(&length, &width));
            break;

        case 5:
            printf("\nThe Rectangle has an area of %i\n\n", getArea(&length, &width));
            break;

        case 6:
            continueProgram = false;
            break;

        default:
            printf("\nInvalid option. Please select a valid option.\n\n");
            break;
        }
    }

    return 0;
}

int getIntInput(const char* message) {
    int input;
    int result;
    do {
        printf("\n%s", message);
        result = scanf_s("%d", &input);
        while (getchar() != '\n');
    } while (result != 1 || input < 1 || input > 99);

    return input;
}

void setLength(int input, int* length) {
    if (input >= 1 && input <= 99) {
        *length = input;
    }
    else {
        printf("Invalid length. Please enter a value between 1 and 99.\n");
    }
}

void setWidth(int input, int* width) {
    if (input >= 1 && input <= 99) {
        *width = input;
    }
    else {
        printf("Invalid width. Please enter a value between 1 and 99.\n");
    }
}

int getPerimeter(int* length, int* width) {
    return 2 * (*length + *width);
}

int getArea(int* length, int* width) {
    return *length * *width;
}

void printWelcomeMenu() {
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**    Assignment 02   **\n");
    printf(" **********************\n");
}

void printOptions() {
    printf("1. Get Rectangle Length & Width\n");
    printf("2. Change Rectangle Length\n");
    printf("3. Change Rectangle Width\n");
    printf("4. Get Rectangle Perimeter\n");
    printf("5. Get Rectangle Area\n");
    printf("6. Exit\n");
}
