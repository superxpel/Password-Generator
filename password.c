#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 33

const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

void generate_password(char* password) {
    int len = strlen(characters);
    int i;

    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int random_index = rand() % len;
        password[i] = characters[random_index];
    }
    password[PASSWORD_LENGTH] = '\0';
}

int main(void) {
    char password[PASSWORD_LENGTH + 1];
    char file_name[100];

    printf("Enter a title for the password file: ");
    scanf("%s", file_name);
    strcat(file_name, ".txt");

    generate_password(password);

    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Generated password: %s", password);

    printf("Password saved to %s\n", file_name);

    fclose(f);

    return 0;
}
