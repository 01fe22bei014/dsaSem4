#include <stdio.h>
#include <conio.h>  // For getch() function

int main() {
    char password[20];
    int i = 0;
    char ch;

    printf("Enter password: ");

    while (1) {
        ch = getch();

        if (ch == 13) // Enter key
            break;

        if (ch == 8) { // Backspace
            if (i > 0) {
                printf("\b \b"); // Move the cursor back, erase the character, move the cursor back again
                i--;
            }
        } else {
            password[i] = ch;
            printf("*"); // Print asterisk to hide the character
            i++;
        }
    }

    password[i] = '\0'; // Null-terminate the password string
    printf("\nPassword entered: %s\n", password);

    return 0;
}

