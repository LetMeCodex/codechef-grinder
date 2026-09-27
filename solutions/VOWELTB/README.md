# [Is it a VOWEL or CONSONANT (VOWELTB)](https://www.codechef.com/problems/VOWELTB)
- **Difficulty Rating**: 840
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine whether a given uppercase English alphabet character is a Vowel or a Consonant. We need to print "Vowel" if it's a vowel, and "Consonant" otherwise. The input is guaranteed to be a single uppercase English alphabet character.

## Intuition & Mathematical Observation

The core of this problem lies in the definition of vowels and consonants in the English alphabet. The uppercase vowels are 'A', 'E', 'I', 'O', 'U'. Any other uppercase English alphabet character is a consonant.

Our approach will be straightforward:
1. Read the input character.
2. Check if this character is equal to 'A', 'E', 'I', 'O', or 'U'.
3. If it matches any of these, it's a vowel, so we print "Vowel".
4. Otherwise, by elimination (since the input is guaranteed to be an uppercase English alphabet character), it must be a consonant, so we print "Consonant".

This is a direct conditional check and doesn't require any complex algorithms, data structures, or mathematical observations beyond the basic definition of vowels and consonants.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading a single character, performing a constant number of comparisons (at most 5 `OR` operations), and printing a fixed-length string. All these operations take constant time, regardless of the input character.

-   **Space Complexity**: $O(1)$
    The solution uses a single character variable to store the input. No additional data structures are allocated, and the memory usage remains constant irrespective of the input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    // While not strictly necessary for a problem with such small input, it's good practice for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c; // Declare a character variable to store the input
    cin >> c; // Read the single uppercase character from input

    // Check if the character is one of the five uppercase vowels
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Vowel\n"; // If it's a vowel, print "Vowel" followed by a newline
    } else {
        // If it's not a vowel (and we know it's an uppercase English alphabet),
        // then it must be a consonant.
        cout << "Consonant\n"; // Print "Consonant" followed by a newline
    }

    return 0; // Indicate successful execution
}
```