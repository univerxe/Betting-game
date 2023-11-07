#include "odd_even_game.h" // For OddEvenGame()
#include <stdio.h>         // For printf(), scanf()
#include <stdlib.h>        // For srand(), rand()
#include <time.h>          // For time()

void OddEvenGame(int* currentMoney) { 
    int bet, guess, result;

    printf("\n[Odd or Even Game]\n");
    printf("\nHOW TO PLAY?\n");
    printf("Guess whether it's odd (1) or even (0). If you guess correctly, you win double your bet; otherwise, you lose your bet.\n\n");

    // Enter the betting amount
    do {
        printf("Enter your bet (current balance: %d won)\n", *currentMoney); // Display the current balance
        scanf("%d", &bet); // Enter the betting amount
        if (bet < 1) { 
            printf("You're too poor to play this game. \n"); 
        }
        else if (bet > *currentMoney) { 
            printf("Insufficient amount! Your Current balance: %d won\n", *currentMoney);
        }
    } while (bet < 1 || bet > *currentMoney); // Repeat until the betting amount is valid

    // Enter your guess
    do {
        printf("Enter 1 for odd or 0 for even: ");
        scanf("%d", &guess);
        if (guess != 0 && guess != 1) {
            printf("Invalid input. Please enter 1 for odd or 0 for even.\n");
        }
    } while (guess != 0 && guess != 1);

    // Generate a random number: 0 and 1
    srand((unsigned int)time(NULL)); 
    result = rand() % 2; 

    // Display the result
    if (guess == result) {
        printf("Congratulations! You guessed it right! You win double your bet.\n");
        *currentMoney += bet * 2; // Win double the betting amount
    }
    else {
        printf("Sorry, you guessed wrong. You lose your bet.\n");
        *currentMoney -= bet; // Lose the betting amount
    }

    printf("Result: %s\n", (result == 1) ? "Odd" : "Even"); // Display the result
    printf("Current balance: %d won\n", *currentMoney);
}
