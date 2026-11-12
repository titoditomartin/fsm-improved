
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "mylib/mylib.h"

// Clear the terminal screen
void clearScreen(void) {
    printf("\033[2J");
    printf("\033[1;1H");
}

// Clear invalid input from stdin
void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

// Read a valid binary input (0 or 1), or -1 to exit
int getInput(const char *prompt) {
    int value;

    while (true) {
        printf("%s", prompt);
        fflush(stdout);

        if (scanf("%d", &value) != 1) {
            if (feof(stdin)) {
                return -1;
            }

            clearInputBuffer();
            printf("Invalid input. Please enter 0, 1, or -1 to exit.\n");
            continue;
        }

        clearInputBuffer();

        if (value == -1 || value == 0 || value == 1) {
            return value;
        }

        printf("Invalid input. Please enter 0, 1, or -1 to exit.\n");
    }
}

// Microwave: door closed
void closed(void) {
    printf(" _____________________ \n");
    printf("|                     |\n");
    printf("|  _____________      |\n");
    printf("| |             | 0 0 |\n");
    printf("| |          |  | 0 0 |\n");
    printf("| |          |  |     |\n");
    printf("| |_____________|  3  |\n");
    printf("|_____________________|\n");
    printf("  Door is closed\n");
}

// Microwave: door open
void opened(void) {
    printf(" _____________________ \n");
    printf("|                     |\n");
    printf("|   ____________      |\n");
    printf("| ||            | 0 0 |\n");
    printf("| ||            | 0 0 |\n");
    printf("| ||            |     |\n");
    printf("| ||____________|  3  |\n");
    printf("|_____________________|\n");
    printf("  Door is opened\n");
}

// Microwave: cooking countdown
void cooking(int seconds) {
    printf(" _____________________ \n");
    printf("|                     |\n");
    printf("|   ____________      |\n");
    printf("| ||            | 0 0 |\n");
    printf("| ||            | 0 0 |\n");
    printf("| ||            |     |\n");
    printf("| ||____________|  %d  |\n", seconds);
    printf("|_____________________|\n");
    printf("  Cooking\n");
}

// Run the cooking simulation
void runCooking(void) {
    for (int i = 3; i > 0; i--) {
        clearScreen();
        cooking(i);
        fflush(stdout);
        sleep(1);
    }

    clearScreen();
    printf("Cooking complete!\n");
    sleep(1);
}

int main(void) {
    int s0 = 0;
    int s1 = 0;
    int D, T;
    int M = 0;

    printf("Microwave Finite State Machine Simulation\n");
    printf("Enter -1 at any input prompt to exit.\n\n");

    while (true) {
        clearScreen();

        // Display current FSM state
        if (s0 == 0 && s1 == 0) {
            opened();
        }
        else if (s0 == 0 && s1 == 1) {
            closed();
        }
        else if (s0 == 1 && s1 == 0) {
            runCooking();

            // Return to door-closed state after cooking
            s0 = 0;
            s1 = 1;
            M = 0;

            clearScreen();
            closed();
        }
        else {
            printf("Unexpected FSM state. Resetting...\n");
            s0 = 0;
            s1 = 0;
            M = 0;
            continue;
        }

        // Get door input
        D = getInput(
            "Enter input (0 to open the door // 1 to close the door): "
        );

        if (D == -1) {
            break;
        }

        // Get timer input
        T = getInput(
            "Enter button input (0 to stop the timer // 1 to start the timer): "
        );

        if (T == -1) {
            break;
        }

        // Update FSM state using mylib.c
        states(s0, s1, D, T, &s0, &s1, &M);
    }

    printf("\nMicrowave simulation terminated.\n");
    return 0;
}
