#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Helper function to get the Soundex digit for a character
char getSoundexCodeForCharacter(char c) {
    static const char soundexTable[26] = {
        '0', // A, E, I, O, U, H, W, Y
        '1', // B
        '2', // C, S
        '3', // D, T
        '0', // E (repeated as zero to avoid duplication)
        '1', // F, P
        '2', // G, J
        '0', // H (repeated as zero)
        '0', // I (repeated as zero)
        '1', // J (already mapped)
        '2', // K, G (already mapped)
        '0', // L (mapped as zero)
        '5', // M, N
        '0', // N (repeated as zero)
        '0', // O (repeated as zero)
        '1', // P (already mapped)
        '0', // Q (mapped as zero)
        '2', // R (already mapped)
        '0', // S (mapped as zero)
        '3', // T (already mapped)
        '0', // U (repeated as zero)
        '1', // V (already mapped)
        '0', // W (mapped as zero)
        '2', // X (mapped as zero)
        '0', // Y (repeated as zero)
        '2'  // Z (mapped as zero)
    };

    c = toupper(c); // Convert character to uppercase
    // Check if the character is between 'A' and 'Z' and return the corresponding Soundex digit
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    } else {
        return '0'; // Return '0' for non-alphabetic characters
    }
}

// Initializes the Soundex code with the first character of the name
void initializeSoundex(char *soundex, char firstChar) {
    if (soundex == NULL) return; // Ensure soundex is not NULL
    soundex[0] = toupper(firstChar); // Set the first character to uppercase
    memset(soundex + 1, '0', 3); // Set the remaining three characters to '0'
    soundex[4] = '\0'; // Null-terminate the string
}

// Processes the name to generate the Soundex code
void processName(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) return; // Handle NULL inputs

    int sIndex = 1; // Index for the soundex array
    for (int cIndex = 1; name[cIndex] && sIndex < 4; cIndex++) {
        char code = getSoundexCodeForCharacter(name[cIndex]); // Get the Soundex digit for the current character
        // Add the code to soundex if it's not '0' and different from the last added code
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code; // Add code and increment index
        }
    }
}

// Generates the Soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) {
        if (soundex != NULL) {
            strcpy(soundex, "0000"); // Set default value if name is NULL
        }
        return;
    }
    
    initializeSoundex(soundex, name[0]); // Initialize the Soundex with the first character
    processName(name, soundex); // Process the rest of the name to complete the Soundex code
}

#endif // SOUNDEX_H
