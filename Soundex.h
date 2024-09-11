#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', // A
        '1', // B
        '2', // C
        '3', // D
        '0', // E
        '1', // F
        '2', // G
        '0', // H
        '0', // I
        '1', // J
        '2', // K
        '0', // L
        '5', // M
        '0', // N
        '0', // O
        '1', // P
        '0', // Q
        '2', // R
        '0', // S
        '3', // T
        '0', // U
        '1', // V
        '0', // W
        '2', // X
        '0', // Y
        '2'  // Z
    };

    c = toupper(c); // Convert character to uppercase
    return (c >= 'A' && c <= 'Z') ? soundexTable[c - 'A'] : '0';
}

// Initialization function
void initializeSoundex(char *soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
    memset(soundex + 1, '0', 3); // Set the rest of the soundex string to '0'
    soundex[4] = '\0';
}

// Processing function
void processName(const char *name, char *soundex) {
    int sIndex = 1;

    for (int i = 1; name[i] && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
}

void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) return; // Handle NULL inputs
    
    initializeSoundex(soundex, name[0]);
    processName(name, soundex);
}

#endif // SOUNDEX_H
