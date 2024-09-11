#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[256] = {
        ['A'] = '0', ['B'] = '1', ['C'] = '2', ['D'] = '3', ['E'] = '0', ['F'] = '1',
        ['G'] = '2', ['H'] = '0', ['I'] = '0', ['J'] = '1', ['K'] = '2', ['L'] = '4',
        ['M'] = '5', ['N'] = '5', ['O'] = '0', ['P'] = '1', ['Q'] = '1', ['R'] = '2',
        ['S'] = '2', ['T'] = '3', ['U'] = '0', ['V'] = '1', ['W'] = '0', ['X'] = '2',
        ['Y'] = '0', ['Z'] = '2'
    };

    // Convert character to uppercase if it is a lowercase letter
    c = toupper(c);
    
    // Return the corresponding soundex code or '0' for non-alphabetic characters
    return (c >= 'A' && c <= 'Z') ? soundexTable[(unsigned char)c] : '0';
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
