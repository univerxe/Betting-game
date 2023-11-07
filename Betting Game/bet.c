#include <stdio.h>               // For printf(), scanf()
#include <stdlib.h>              // For system()
#include "odd_even_game.h"       // For OddEvenGame()
#include "up_down_game.h"        // For UpDownGame()
#include "rock_paper_scissors.h" // For RockPaperScissors()

int main() {
    int currentMoney = 10000; // Starting balance
    int gameChoice;

    // Display the menu and play the game until the user runs out of money
    while (currentMoney > 0) {
        printf("Current balance: ");
        printf("%d won\n", currentMoney);
        printf("Choose a game:\n");
        printf("1: Odd or Even\n");
        printf("2: Up and Down\n");
        printf("3: Rock, Paper, Scissors\n");
        printf("0: Quit the game\n");
        scanf("%d", &gameChoice); 
        system("cls"); // On Windows, use system("cls");

        // Play the game (3 games to choose from)
        switch (gameChoice) {
        case 1: // play Odd or Even game
            OddEvenGame(&currentMoney);
            break;
        case 2: // play Up and Down game
            UpDownGame(&currentMoney);
            break;
        case 3: // play Rock Paper Scissors game
            RockPaperScissors(&currentMoney);
            break;
        case 0: // Quit the game
            printf("Exiting the game.\n");
            return 0;
        default:
            printf("Invalid choice. Please choose again.\n");
            break;
        }

        // Check the balance after the game
        if (currentMoney <= 0) {
            printf("You have lost all your money! Game over!\n");
            break;
        }
    }

    return 0;
}
