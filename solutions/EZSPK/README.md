Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem EZSPK:

# [Easy Speaking (EZSPK)](https://www.codechef.com/problems/EZSPK)
- **Difficulty Rating**: 708
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given word is "hard to pronounce". A word is considered hard to pronounce if it contains at least 4 consecutive consonants. We are given a series of test cases, and for each test case, we need to read the length of the word `N` and the word itself (a string `S` consisting of lowercase English letters). For each word, we should output "Yes" if it's hard to pronounce, and "No" otherwise. Vowels are defined as 'a', 'e', 'i', 'o', 'u'; all other letters are consonants.

## Intuition & Mathematical Observation

The core idea is to iterate through the word character by character and maintain a count of consecutive consonants.

1.  **Initialize a counter**: We start with a counter, say `consecutive_consonants_count`, set to 0. This counter will keep track of the current sequence of consonants.
2.  **Iterate through the word**: For each character in the input string `S`:
    *   **Check if it's a vowel**: We need a helper function or a simple `if` condition to determine if the current character is 'a', 'e', 'i', 'o', or 'u'.
    *   **If it's a vowel**: The sequence of consonants is broken. We reset `consecutive_consonants_count` back to 0.
    *   **If it's a consonant**: We increment `consecutive_consonants_count` by 1.
3.  **Check the condition**: After updating `consecutive_consonants_count` (either by resetting or incrementing), we immediately check if its value is greater than or equal to 4.
    *   If `consecutive_consonants_count >= 4`, it means we have found at least 4 consecutive consonants. In this case, the word is hard to pronounce. We can set a flag (e.g., `hard_to_pronounce = true`) and immediately break out of the loop, as further checking is unnecessary.
4.  **Final Output**: After the loop finishes (either by completing the word or by breaking early), we check the `hard_to_pronounce` flag. If it's `true`, we print "Yes"; otherwise, we print "No".

This approach ensures that we correctly identify any sequence of 4 or more consonants, regardless of where it appears in the word.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   The solution iterates through the input string `S` exactly once. In the worst case, it processes all `N` characters.
    *   The `is_vowel` function performs a constant number of comparisons, so it takes $O(1)$ time.
    *   All other operations inside the loop (incrementing, resetting, checking) also take $O(1)$ time.
    *   Given `T` test cases, the total time complexity will be $O(T \cdot N)$.
-   **Space Complexity**: $O(N)$ per test case.
    *   The primary space usage comes from storing the input string `S`, which requires $O(N)$ space.
    *   A few integer variables (`n`, `consecutive_consonants_count`, `t`) and a boolean flag (`hard_to_pronounce`) are used, which consume $O(1)$ additional space.
    *   Therefore, the overall space complexity is dominated by the input string, making it $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as requested

// Using namespace std; as requested
using namespace std;

// Function to check if a character is a vowel
// Returns true if 'c' is 'a', 'e', 'i', 'o', or 'u', false otherwise.
bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the word
    string s;
    cin >> s; // Read the word itself

    int consecutive_consonants_count = 0; // Counter for consecutive consonants
    bool hard_to_pronounce = false;       // Flag to indicate if the word is hard to pronounce

    // Iterate through each character of the string
    for (char c : s) {
        if (is_vowel(c)) {
            // If a vowel is encountered, the sequence of consonants is broken.
            // Reset the counter.
            consecutive_consonants_count = 0;
        } else {
            // If a consonant is encountered, increment the counter.
            consecutive_consonants_count++;
        }

        // After updating the count, check if we have found at least 4 consecutive consonants.
        if (consecutive_consonants_count >= 4) {
            hard_to_pronounce = true; // Set the flag
            break;                   // No need to check further characters, we found the condition
        }
    }

    // Output the result for the current test case
    if (hard_to_pronounce) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O setup as requested for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```