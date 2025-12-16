#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIN_LENGTH 4
#define MAX_ATTEMPTS 2

void enterPIN(char *pin);
int verifyPIN(char *enteredPIN, char *storedPIN);
void selectTransaction(char *pin);
void withdrawCash();
void changePIN(char *pin);
// here is atm pin code 
int main() {
    char storedPIN[MAX_PIN_LENGTH + 1] = "1234"; 
    char enteredPIN[MAX_PIN_LENGTH + 1];
    int attempts = 0;
// here is pin attemption 
    while (attempts < MAX_ATTEMPTS) {
        enterPIN(enteredPIN);
        if (verifyPIN(enteredPIN, storedPIN)) {
            selectTransaction(storedPIN);
            break;
        } else {
            attempts++;
            printf("Invalid PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Too many failed attempts. Card blocked.\n");
    }

    return 0;
}
// here is enter your pin code
void enterPIN(char *pin) {
    printf("Enter your PIN: ");
    scanf("%s", pin);
}
// veryfing
int verifyPIN(char *enteredPIN, char *storedPIN) {
    return strcmp(enteredPIN, storedPIN) == 0;
}
// here is select your transaction
void selectTransaction(char *pin) {
    int choice;
    printf("Select transaction:\n");
    printf("1. Withdraw Cash\n");
    printf("2. Change PIN\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
// cash withdrawl processs
    switch (choice) {
        case 1:
            withdrawCash();
            break;
        case 2:
            changePIN(pin);
            break;
        default:
            printf("Invalid choice. Transaction cancelled.\n");
    }
}

void withdrawCash() {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    printf("Dispensing %.2f\n", amount);
}
// changing atm pin code written here
void changePIN(char *pin) {
    char newPIN[MAX_PIN_LENGTH + 1];
    printf("Enter new PIN: ");
    scanf("%s", newPIN);
    strcpy(pin, newPIN);
    printf("PIN changed successfully.\n");
}