#include <stdio.h>  // For printf(), scanf()
#include <stdlib.h> // For srand(), rand()
#include <time.h>   // For time()

void RockPaperScissors(int* currentMoney) {
    int bet, userChoice, computerChoice;
    const char* choices[] = { "Rock", "Paper", "Scissors" };

    printf("\n[Rock, Paper, Scissors Game]\n");
    printf("\nHOW TO PLAY?\n");
    printf("Choose one of the following: Rock(1), Paper(2), or Scissors(3).\n\n");

    // Enter the betting amount
    do {
        printf("Enter your bet (current balance: %d won): ", *currentMoney);
        scanf("%d", &bet);
        if (bet < 1) {
            printf("The betting amount must be at least 1 won.\n");
        }
        else if (bet > *currentMoney) {
            printf("You cannot bet more than your current balance. Current balance: %d won\n", *currentMoney);
        }
    } while (bet < 1 || bet > *currentMoney);

    // Enter your choice
    do {
        printf("Choose one: Rock(1), Paper(2), or Scissors(3): ");
        scanf("%d", &userChoice);
        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (userChoice < 1 || userChoice > 3);

    // Computer's choice (randomly generated number between 1 and 3)
    srand((unsigned int)time(NULL)); 
    computerChoice = rand() % 3 + 1;

    // Determine the result
    printf("Your choice: %s\n", choices[userChoice - 1]); // Display the user's choice
    printf("Computer's choice: %s\n", choices[computerChoice - 1]);

    if (userChoice == computerChoice) {
        printf("It's a draw! You get your bet back.\n");
    }
    
    else if ((userChoice == 1 && computerChoice == 3) ||
        (userChoice == 2 && computerChoice == 1) ||
        (userChoice == 3 && computerChoice == 2)) {
        printf("You win! You get double your bet.\n");
        *currentMoney += bet; // Win double the betting amount
    }
    else {
        printf("You lose! You lose your bet.\n");
        *currentMoney -= bet; // Lose the betting amount
    }

    printf("Current balance: %d won\n", *currentMoney);
}
