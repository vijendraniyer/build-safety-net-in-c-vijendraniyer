#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, BasicName) {
    char soundex[5];
    generateSoundex("Vijendran", soundex);
    ASSERT_STREQ(soundex, "V253");
}

TEST(SoundexTestsuite, MixedCaseName) {
    char soundex[5];
    generateSoundex("vIjeNDran", soundex);
    ASSERT_STREQ(soundex, "V253");
}

TEST(SoundexTestsuite, EmptyString) {
    char soundex[5];
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "0000");
}

TEST(SoundexTestsuite, SingleCharacter) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, SingleNonAlphabeticCharacter) {
    char soundex[5];
    generateSoundex("1", soundex);
    ASSERT_STREQ(soundex, "1000");
}

TEST(SoundexTestsuite, SingleLowercaseCharacter) {
    char soundex[5];
    generateSoundex("a", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, RepeatedConsonants) {
    char soundex[5];
    generateSoundex("AABB", soundex);
    ASSERT_STREQ(soundex, "A100");
}

TEST(SoundexTestsuite, ConsecutiveIdenticalConsonants) {
    char soundex[5];
    generateSoundex("AABBB", soundex);
    ASSERT_STREQ(soundex, "A100");
}

TEST(SoundexTestsuite, NonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("A1B2C", soundex);
    ASSERT_STREQ(soundex, "A120");
}

TEST(SoundexTestsuite, SpecialCharacters) {
    char soundex[5];
    generateSoundex("A-B_C", soundex);
    ASSERT_STREQ(soundex, "A120");
}

TEST(SoundexTestsuite, NameWithVowels) {
    char soundex[5];
    generateSoundex("AeIou", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, ShortName) {
    char soundex[5];
    generateSoundex("Jo", soundex);
    ASSERT_STREQ(soundex, "J000");
}

TEST(SoundexTestsuite, LongName) {
    char soundex[5];
    generateSoundex("Alexander", soundex);
    ASSERT_STREQ(soundex, "A452");
}

TEST(SoundexTestsuite, LongSequenceOfSameConsonants) {
    char soundex[5];
    generateSoundex("BBBBBBBB", soundex);
    ASSERT_STREQ(soundex, "B111");
}

TEST(SoundexTestsuite, UpperBoundOfLength) {
    char soundex[5];
    generateSoundex("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, NullInputSoundexArray) {
    generateSoundex("Alexander", NULL);
    // No direct assertion here; ensures no crash occurs
}

TEST(SoundexTestsuite, NullInputName) {
    char soundex[5];
    generateSoundex(NULL, soundex);
    ASSERT_STREQ(soundex, "0000");
}
