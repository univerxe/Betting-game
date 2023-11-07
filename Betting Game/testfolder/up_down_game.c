#include <stdio.h>  // For printf(), scanf()
#include <stdlib.h> // For srand(), rand()
#include <time.h>   // For time()

void UpDownGame(int* currentMoney) {
    int secretNumber, userGuess, bet;
    int chances = 2; // Number of chances given to the user

    srand((unsigned int)time(NULL)); // Initialize random number generator
    secretNumber = rand() % 10 + 1; // Generate a random number between 1 and 10

    printf("\n[Up and Down Game]\n");
    printf("\nHOW TO PLAY?\n");
    printf("Guess a number between 1 and 10. You have two chances.\n\n");

    // Enter the betting amount
    do {
        printf("Enter your bet (current balance: %d won)\n", *currentMoney);
        scanf("%d", &bet);
        if (bet < 1) {
            printf("The betting amount must be at least 1 won.\n");
        }
        else if (bet > *currentMoney) {
            printf("You cannot bet more than your current balance. Current balance: %d won\n", *currentMoney);
        }
    } while (bet < 1 || bet > *currentMoney);

    // Give the user two chances to guess the number
    while (chances > 0) {
        do {
            printf("Enter a number (1 to 10): ");
            scanf("%d", &userGuess);
            if (userGuess < 1 || userGuess > 10) {
                printf("Invalid input. Please enter a number between 1 and 10.\n");
            }
        } while (userGuess < 1 || userGuess > 10);

        chances--; // Decrease the number of chances by 1

        if (userGuess == secretNumber) {
            printf("Congratulations! You guessed the number.\n");
            *currentMoney += bet * 2;
            return;
        }
        else if (userGuess < secretNumber) {
            printf("Up! (Higher number needed.)\n");
        }
        else {
            printf("Down! (Lower number needed.)\n");
        }

        if (chances == 0) {
            printf("You've used up all your chances. The correct answer was %d.\n", secretNumber);
            *currentMoney -= bet; // Lose the betting amount
        }
    }

    printf("Current balance: %d won\n", *currentMoney);
}
