#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to brew coffee given the number of cups
void brewCoffee(int cups) {
    printf("Brewing %d cup(s) of coffee on /dev/cf0...\n", cups);
    sleep(1);
    for (int i = 0; i < cups; i++) {
        for (int j = 0; j < 8; j++) {
            printf("#");
            fflush(stdout);  // Flush the output to ensure it appears immediately
            sleep(1);  // Pause for 1 second
        }
        printf(" ");  // Add a space after each cup
    }
    for (int k = 0; k < 3; k++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    sleep(1);
    printf("\nCoffee complete!\n");
    sleep(1);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        printf("Usage: %s -t type <number>\n", argv[0]);
        return 1;
    }

    // Check if the first argument is "-h"
    if (strcmp(argv[1], "-h") == 0) {
        if (argc < 4) {
            printf("Missing type and number after -h option.\n");
            return 1;
        }
        char* type = argv[3];
        printf("Brewing hot coffee. Cold is the default.\n");
        sleep(1);
        printf("Brewing %s coffee.\n", type);
        sleep(1); 
        // Extract the number from the fourth argument
        int number = atoi(argv[4]);

        brewCoffee(number);
    }
    // Check if the first argument is "-b"
    else if (strcmp(argv[1], "-b") == 0) {
        if (argc < 4) {
            printf("Missing type and number after -b option.\n");
            return 1;
        }
        char* type = argv[3];
        printf("Burning coffee. Especially useful when executing coffee on behalf of your boss.\n");
        sleep(1); 
        printf("Brewing %s coffee.\n", type);
        sleep(1); 
        // Extract the number from the fourth argument
        int number = atoi(argv[4]);

        brewCoffee(number);
    }
    // Check if the first argument is "-t"
    else if (strcmp(argv[1], "-t") == 0) {
       if (argc < 4) {
           printf("Missing type and number after -t option.\n");
           return 1;
       }
       char* type = argv[2];
    printf("Brewing %s coffee.\n", type);
    sleep(1); 
    // Extract the number from the third argument
    int number = atoi(argv[3]);

    brewCoffee(number);
}

    return 0;
}