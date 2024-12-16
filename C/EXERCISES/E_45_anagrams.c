#include <stdio.h>

int anagram(const char *word1, const char *word2) {
    int count[256] = {0};  // Array to count ASCII characters

    // Calculate the length of both words
    int len1 = 0, len2 = 0;
    while (word1[len1] != '\0') len1++;
    while (word2[len2] != '\0') len2++;

    // Check if lengths are different
    if (len1 != len2) {
        return 0;  // Not anagrams if lengths differ
    }

    // Count the frequency of each character in word1
    for (int i = 0; i < len1; i++) {
        count[(unsigned char)word1[i]]++;
    }

    // Decrease the frequency based on characters in word2
    for (int i = 0; i < len2; i++) {
        count[(unsigned char)word2[i]]--;
    }

    // Verify if all counts are zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;  // Not anagrams if any count is not zero
        }
    }

    return 1;  // Words are anagrams
}

int main() {
    char word1[50], word2[50];

    // User input
    printf("Please enter 2 words (separated by a space): ");
    scanf("%s %s", word1, word2);

    // Check if the words are anagrams
    if (anagram(word1, word2)) {
        printf("%s and %s are anagrams.\n", word1, word2);
    } else {
        printf("%s and %s are not anagrams.\n", word1, word2);
    }

    return 0;
}