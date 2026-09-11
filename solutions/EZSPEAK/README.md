# [Easy Pronunciation (EZSPEAK)](https://www.codechef.com/problems/EZSPEAK)
- **Difficulty Rating**: 1000
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given word (represented as a string `S`) is "hard to pronounce". A word is considered hard to pronounce if it contains 4 or more consecutive consonants. The vowels are defined as 'a', 'e', 'i', 'o', 'u'. All other lowercase English letters are considered consonants. We need to output "YES" if the word is easy to pronounce, and "NO" if it is hard to pronounce.

## Intuition & Mathematical Observation

The core idea is to iterate through the given string character by character and maintain a count of consecutive consonants.

1.  **Initialization**: We start with a counter for `consecutive_consonants` set to 0. We also use a boolean flag, say `hard_to_pronounce`, initialized to `false`.
2.  **Iteration**: For each character in the string:
    *   **Check if vowel**: If the current character is a vowel ('a', 'e', 'i', 'o', 'u'), it breaks any ongoing sequence of consonants. So, we reset `consecutive_consonants` to 0.
    *   **Check if consonant**: If the current character is a consonant, we increment `consecutive_consonants` by 1.
3.  **Condition Check**: After updating `consecutive_consonants` for the current character, we immediately check if its value is 4 or more.
    *   If `consecutive_consonants >= 4`, it means we have found a sequence of 4 or more consecutive consonants. In this case, the word is hard to pronounce. We set `hard_to_pronounce` to `true` and can stop processing the rest of the string, as the condition is already met.
4.  **Final Result**: After iterating through the entire string (or stopping early if the condition is met), we check the `hard_to_pronounce` flag.
    *   If `hard_to_pronounce` is `true`, output "NO".
    *   Otherwise (if the loop completed without finding 4 consecutive consonants), output "YES".

This approach is a direct simulation of the problem's definition, requiring no complex mathematical observations beyond identifying vowels and maintaining a simple counter.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   For each test case, we iterate through the input string `S` of length `N` exactly once.
    *   Inside the loop, the `is_vowel` function performs a constant number of comparisons, taking $O(1)$ time.
    *   All other operations within the loop (increment, assignment, comparison) also take $O(1)$ time.
    *   Therefore, the total time complexity for a single test case is directly proportional to the length of the string, $O(N)$.
    *   Given `T` test cases, the overall time complexity will be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of the string across all test cases.
*   **Space Complexity**: $O(N)$
    *   We store the input string `S`, which requires $O(N)$ space.
    *   We use a few auxiliary variables (`N`, `consecutive_consonants`, `i`, `hard_to_pronounce`) which take a constant amount of space, $O(1)$.
    *   Thus, the dominant factor for space complexity is storing the input string, making it $O(N)$. If we were to consider only auxiliary space (excluding input storage), it would be $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // Use standard namespace for convenience

// Function to check if a character is a vowel
// Vowels are 'a', 'e', 'i', 'o', 'u'
bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string

    int consecutive_consonants = 0; // Counter for consecutive consonants
    bool hard_to_pronounce = false; // Flag to indicate if the word is hard to pronounce

    // Iterate through each character of the string
    for (int i = 0; i < N; ++i) {
        if (is_vowel(S[i])) {
            // If it's a vowel, reset the consecutive consonant count
            consecutive_consonants = 0;
        } else {
            // If it's a consonant, increment the count
            consecutive_consonants++;
        }

        // Check if we have found 4 or more consecutive consonants
        if (consecutive_consonants >= 4) {
            hard_to_pronounce = true; // Mark as hard to pronounce
            break; // No need to check further, we found the condition
        }
    }

    // Output the result based on the flag
    if (hard_to_pronounce) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```