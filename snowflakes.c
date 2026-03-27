#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>

#define WIDTH 40
#define HEIGHT 15

void secret_snow_animation() {
    int snow[WIDTH];
    for (int i = 0; i < WIDTH; i++) snow[i] = rand() % HEIGHT;

    printf("\n[!!!] STACK OVERFLOW: REDIRECTING TO SECRET_FUNCTION [!!!]\n");
    sleep(1);

    while (1) {
        printf("\033[H");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (snow[j] == i) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        for (int i = 0; i < WIDTH; i++) {
            if (rand() % 10 == 0) snow[i] = (snow[i] + 1) % HEIGHT;
        }
        usleep(100000);
    }
}

void vulnerable_input() {
    char buffer[16]; // A very small buffer
    printf("--- Safety Monitoring System ---\n");
    printf("Enter your password (use more than 24 characters for the attack): ");

    // VULNERABILITY: `scanf` does not check the buffer size
    // To exploit this vulnerability, you need to overwrite 16 bytes of the buffer + 8 bytes (RBP) + the function address
    scanf("%s", buffer);

    printf("Access is restricted to: %s\n", buffer);
}

int main() {

    vulnerable_input();
    printf("The program has been completed as scheduled.\n");
    return 0;
}
