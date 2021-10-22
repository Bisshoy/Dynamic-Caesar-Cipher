// This is a program that allows the user to input a string of 
// most any length, depending on how much memory the user decides
// to allocate based on message length. The user will also choose 
// a shift value. The program will shift the letters of the user's
// original sentence by a number equal to the shift value. For 
// example, if the entered message is abcde and the shift value
// is 2, then the ciphered message is cdefg. 
// 
// As this program is designed for educational purposes, it contains
// many different c functions, such as dynamic memory allocation.
// 
// Please note that this function would be simpler if you just 
// used stack memory for the original string instead of heap
// memory. Honestly, the rationale was 20% for educational
// purposes and 80% the fact that "dynamic memory allocation" 
// sounds mega cool. I stand by my decision, future reader (probably
// just myself in the future).
//
// @version 10-21-2021
// @author Bisshoy Anwar 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

// Look Dad, my first PROTOTYPE! 
char CaesarCipher(char original[], int shift);

int main() {
    char sentenceSize; // To get general size of sentence 
    int length;
    int shift; 

    // s (10 bytes), m (100 bytes), or l (1000 bytes)
    printf("How long of a sentence? [s/m/l]: ");
    scanf("%c", &sentenceSize);
    getchar();

    // Modifies allocated memory based on sentence length
    switch (sentenceSize) {
        case ('s'): 
            length = 10;
            break;
        case ('m'):
            length = 100;
            break;
        case ('l'):
            length = 1000;
            break;
        default: 
            printf("ERROR: Size input not recognized.");
            break;
    }
    
    // Allocates memory for original sentence 
    // sizeof(char) is 1; this is just for style 
    char *original = (char*) malloc(length * sizeof(char)); 

    // In case of faulty memory allocation 
    if (original == NULL) {
        printf("ERROR: Memory not allocated.");
    }

    // Input original string 
    printf("Enter your original string here: "); 
    fgets(original, length * sizeof(original), stdin);
    original[strcspn(original, "\n")] = 0;
    
    // Decide the key shift number 
    printf("Enter the shift value here: ");
    scanf("%d", &shift); 

    // Print translated text 
    printf("\nYour cyphered text is:\n");
    printf("%c\n", CaesarCipher(original, shift));

    free(original);
    return 0;
}

// Caesar Cipher Function 
char CaesarCipher(char original[], int shift) {
    // Iterate through all elements of original[] 
    for (int i = 0; i < strlen(original); i++) {
        // For lowercase letters 
        if (islower(original[i])) {
            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <= 126) {
                original[i] = original[i];
            }

            else {
                original[i] = (((int) original[i] - 97 + shift) % 26) + 97;
            } 
        }

        // For uppercase letters 
        else {
            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <= 126) {
                original[i] = original[i];
            }

            // Replace each character with the shifted character
            else {
                original[i] = (((int) original[i] - 65 + shift) % 26) + 65;
            } 
        }

        printf("%c", original[i]); 

    }
}

// Note to self: decodeShift = 26 - (shift % 26) 

