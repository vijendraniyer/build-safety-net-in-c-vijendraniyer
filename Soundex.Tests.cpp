#include <gtest/gtest.h>
#include "Soundex.h"

// Test case for generating Soundex code from a basic name
TEST(SoundexTestsuite, GeneratesSoundexForBasicName) {
    char soundex[5];
    generateSoundex("Vijendran", soundex);
    ASSERT_STREQ(soundex, "V253");
}

// Test case for generating Soundex code from a name with mixed case
TEST(SoundexTestsuite, HandlesMixedCaseName) {
    char soundex[5];
    generateSoundex("vIjeNDran", soundex);
    ASSERT_STREQ(soundex, "V253");
}

// Test case for generating Soundex code from an empty string
TEST(SoundexTestsuite, HandlesEmptyString) {
    char soundex[5];
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "0000");
}

// Test case for generating Soundex code from a single character
TEST(SoundexTestsuite, HandlesSingleCharacterName) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for generating Soundex code from a single non-alphabetic character
TEST(SoundexTestsuite, HandlesSingleNonAlphabeticCharacter) {
    char soundex[5];
    generateSoundex("1", soundex);
    ASSERT_STREQ(soundex, "1000");
}

// Test case for generating Soundex code from a single lowercase character
TEST(SoundexTestsuite, HandlesSingleLowercaseCharacter) {
    char soundex[5];
    generateSoundex("a", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for generating Soundex code from a name with repeated consonants
TEST(SoundexTestsuite, HandlesRepeatedConsonants) {
    char soundex[5];
    generateSoundex("AABB", soundex);
    ASSERT_STREQ(soundex, "A100");
}

// Test case for generating Soundex code from a name with consecutive identical consonants
TEST(SoundexTestsuite, HandlesConsecutiveIdenticalConsonants) {
    char soundex[5];
    generateSoundex("AABBB", soundex);
    ASSERT_STREQ(soundex, "A100");
}

// Test case for generating Soundex code from a name with non-alphabetic characters
TEST(SoundexTestsuite, HandlesNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("A1B2C", soundex);
    ASSERT_STREQ(soundex, "A120");
}

// Test case for generating Soundex code from a name with special characters
TEST(SoundexTestsuite, HandlesSpecialCharacters) {
    char soundex[5];
    generateSoundex("A-B_C", soundex);
    ASSERT_STREQ(soundex, "A120");
}

// Test case for generating Soundex code from a name with only vowels
TEST(SoundexTestsuite, HandlesNameWithOnlyVowels) {
    char soundex[5];
    generateSoundex("AeIou", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for generating Soundex code from a short name
TEST(SoundexTestsuite, HandlesShortName) {
    char soundex[5];
    generateSoundex("Jo", soundex);
    ASSERT_STREQ(soundex, "J000");
}

// Test case for generating Soundex code from a long name
TEST(SoundexTestsuite, HandlesLongName) {
    char soundex[5];
    generateSoundex("Alexander", soundex);
    ASSERT_STREQ(soundex, "A452");
}

// Test case for generating Soundex code from a long sequence of the same consonants
TEST(SoundexTestsuite, HandlesLongSequenceOfSameConsonants) {
    char soundex[5];
    generateSoundex("BBBBBBBB", soundex);
    ASSERT_STREQ(soundex, "B111");
}

// Test case for generating Soundex code from a name at the upper bound of length
TEST(SoundexTestsuite, HandlesUpperBoundOfNameLength) {
    char soundex[5];
    generateSoundex("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Test case for handling NULL input for Soundex array
TEST(SoundexTestsuite, HandlesNullInputForSoundexArray) {
    generateSoundex("Alexander", NULL);
    // No direct assertion here; ensures no crash occurs
}

// Test case for handling NULL input for name
TEST(SoundexTestsuite, HandlesNullInputForName) {
    char soundex[5];
    generateSoundex(NULL, soundex);
    ASSERT_STREQ(soundex, "0000");
}
