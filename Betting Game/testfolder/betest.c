#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include "odd_even_game.h"
#include "up_down_game.h"
#include "rock_paper_scissors.h"

#define _(string) gettext(string)

int main() {
    setlocale(LC_ALL, "");  // Set the program's locale to the user's default
    bindtextdomain("your_game", "./locale");  // Set the path to your message catalogs
    textdomain("your_game");

    int currentMoney = 10000;
    int gameChoice;
    char languageChoice[2];

    printf(_("Choose a language:\n"));
    printf("en: English\n");
    printf("kr: Korean\n");
    scanf("%s", languageChoice);
    system("cls");  // On Windows, use system("cls");

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
        case 1:
            OddEvenGame(&currentMoney);
            break;
        case 2:
            UpDownGame(&currentMoney);
            break;
        case 3:
            RockPaperScissors(&currentMoney);
            break;
        case 0:
            printf(_("Exiting the game.\n"));
            return 0;
        default:
            printf(_("Invalid choice. Please choose again.\n"));
            break;
        }

        if (currentMoney <= 0) {
            printf(_("You have lost all your money! Game over!\n"));
            break;
        }
    }

    return 0;
}
