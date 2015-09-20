#include<stdio.h>
#include<string.h>
#define NUMPROGRAMS 2    //NUMBER OF PROGRAMS.

void greedy(void);
void ceasar(void);

int main(void){
    int i;

    char *programs[NUMPROGRAMS];  //ARRAY OF PROGRAM DESCRIPTIONS.
    programs[0] = "1.Greedy. An algorithm to find the least amount of coins to use in change.";
    programs[1] = "2.Ceasar. An algorithm to encrypt input using the Ceasar Cipher (Shifting of letters).";

    printf("Hello to Victor's Program! \n");
    printf("List of current programs: \n");

    for(i = 0; i < NUMPROGRAMS; i++){
        printf("%s \n", programs[i]); //LIST ALL PROGRAMS
    }

    int userChoice;

    do{
    printf("Enter number of program you want to run:");
    scanf("%d",&userChoice);
    } while (userChoice > NUMPROGRAMS || userChoice < 0); //ERROR CHECK.

    switch(userChoice){
        case 1:
            greedy();
            break;
        case 2:
            ceasar();
            break;
    }
}

void greedy(void){
    int i;
    int coins[4] = {0, 0, 0, 0};    //ARRAY CONTAINING AMOUNT OF COINS USED
    int coinValues[4] = {25, 10, 5, 1}; //ARRAY CONTAINING THE VALUE OF COINS
    int balance;
    float change;

    do{
        printf("Enter amount of change:");  //PROMPT USER FOR AMOUNT OF CHANGE
        scanf("%f.2", &change);
    } while (change < 0 || change );

    change *= 100;  //ROUND THE FLOAT TO A USABLE NUMBER
    balance = round(change);    //CAST (FLOAT) CHANGE INTO (INT) BALANCE

    for(i = 0; i < 5 ; i++){
        while(balance >= coinValues[i]){    //CHECKS IF BALANCE CAN FIT IN THE VALUE OF COIN
                coins[i]++; //INCREASES COIN COUNTER OF THAT VALUE
                balance -= coinValues[i];
        }
    }
        printf("%d quarters, %d dimes, %d nickel, and %d pennies", coins[0], coins[1], coins[2], coins[3]); //PRINT OUT COIN NUMBERS
}

void ceasar(void){
    int i = 0;

    int shift;
    char word[2048];

    printf("Enter phrase to convert:");
    scanf("%s", &word);

    do{
        printf("Enter shift:");
        scanf("%d", &shift);
    } while (shift < 0);

    while(word[i] != '\0'){
        if(word[i] >= 'a' && word[i] <= 'z'){   //CHECKS FOR LOWERCASE AND THEN MAKES IT UPPERCASE
            word[i] -= 32;
        }

        if((word[i] + shift) >= 'A' && (word[i] + shift) <= 'Z'){  //CHECKS IF THE SHIFT MAKES IT REMAIN A CAPITAL (BETWEEN A AND Z)
            word[i] += (shift); //APPLIES SHIFT
            } else {
                word[i] += shift - 26;  //FIXES LETTERS THAT GO OVER 'Z'
            }

        i++;
    }

    i = 0;

    while(word[i] != '\0'){
        printf("%c", word[i]);
        i++;
    }
}
