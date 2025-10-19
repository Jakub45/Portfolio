#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma warning(disable : 4996) // for Visual Studio

int main() {
    srand((unsigned int)(time(NULL) ^ clock()));

    // Random moves at the start
    for (int i = 0; i < 3; i++) {
        int random_number = rand() % 12;  // now covers 0–11

        switch (random_number) {
        case 0: printf("English move: Germany\n"); break;
        case 1: printf("English move: Italy\n"); break;
        case 2: printf("English move: Germany\n"); break;

        case 3: printf("Programming move: Germany\n"); break;
        case 4: printf("Programming move: Germany\n"); break;
        case 5: printf("Programming move: Italy\n"); break;

        case 6: printf("Microcontroller move: Italy\n"); break;
        case 7: printf("Microcontroller move: Germany\n"); break;
        case 8: {
            int rnd = rand() % 3;
            switch (rnd) {
            case 0: printf("Microcontroller move: Hungary\n"); break;
            case 1: printf("Microcontroller move: Romania\n"); break;
            case 2: printf("Microcontroller move: Bulgaria\n"); break;
            }
            break;
        }

        case 9:  printf("Mathematic move: Germany\n"); break;
        case 10: printf("Mathematic move: Germany\n"); break;
        case 11: {
            int rnd = rand() % 3;
            switch (rnd) {
            case 0: printf("Mathematic move: Hungary\n"); break;
            case 1: printf("Mathematic move: Romania\n"); break;
            case 2: printf("Mathematic move: Slovakia\n"); break;
            }
            break;
        }
        }
    }

    char input[100];

    printf("\nAnything else? Type one of: e (English), m (Microcontroller), p (Programming), a (Mathematic), or q to quit:\n");

    while (scanf("%s", input) == 1) {
        if (strcmp(input, "q") == 0) break;

        if (strcmp(input, "e") == 0) {
            printf("You chose English.\n");

            if (rand() % 2 == 0)
                printf("English move: Germany\n");
            else
                printf("English move: Italy\n");
        }
        else if (strcmp(input, "m") == 0) {
            printf("You chose Microcontroller.\n");

            int rnd = rand() % 3;
            switch (rnd) {
            case 0: printf("Microcontroller move: Italy\n"); break;
            case 1: {
                int rnd2 = rand() % 3;
                switch (rnd2) {
                case 0: printf("Microcontroller move: Hungary\n"); break;
                case 1: printf("Microcontroller move: Romania\n"); break;
                case 2: printf("Microcontroller move: Bulgaria\n"); break;
                }
                break;
            }
            case 2: printf("Microcontroller move: Germany\n"); break;
            }
        }
        else if (strcmp(input, "p") == 0) {
            printf("You chose Programming.\n");

            if (rand() % 2 == 0)
                printf("Programming move: Italy\n");
            else
                printf("Programming move: Germany\n");
        }
        else if (strcmp(input, "a") == 0) {
            printf("You chose Mathematic.\n");

            int rnd = rand() % 4;
            switch (rnd) {
            case 0: printf("Mathematic move: Germany\n"); break;
            case 1: printf("Mathematic move: Hungary\n"); break;
            case 2: printf("Mathematic move: Romania\n"); break;
            case 3: printf("Mathematic move: Slovakia\n"); break;
            }
        }
        else {
            printf("Unrecognized option: %s\n", input);
        }

        printf("\n\nAnything else? (e/m/p/a/q): ");
    }

    return 0;
}
