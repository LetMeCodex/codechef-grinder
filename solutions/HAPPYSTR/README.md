# [Chef and Happy String  (HAPPYSTR)](https://www.codechef.com/problems/HAPPYSTR)
- **Difficulty Rating**: 956
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given string `S` is "Happy" or "Sad". A string is considered "Happy" if it contains at least three consecutive vowels. Otherwise, it is "Sad". The vowels are defined as 'a', 'e', 'i', 'o', 'u'.

We need to process multiple test cases. For each test case, we read a string `S` and print "Happy" or "Sad" accordingly.

## Intuition & Mathematical Observation

The core idea is to iterate through the string and keep track of the count of consecutive vowels encountered so far.

1.  **Initialization**: We start with a counter for consecutive vowels, initialized to 0. We also need a boolean flag, say `happy_found`, initialized to `false`.
2.  **Iteration**: We traverse the string character by character from left to right.
    *   If the current character is a vowel ('a', 'e', 'i', 'o', 'u'), we increment our `consecutive_vowels` counter.
    *   If the current character is a consonant, it breaks any sequence of consecutive vowels, so we reset `consecutive_vowels` back to 0.
3.  **Check for Happiness**: After updating `consecutive_vowels` for each character, we check if its value has become greater than 2 (i.e., 3 or more). If it is, it means we have found at least three consecutive vowels. In this case, the string is "Happy", so we set `happy_found` to `true` and can immediately stop processing the rest of the string for this test case, as the condition is already met.
4.  **Final Output**: After iterating through the entire string (or stopping early if `happy_found` becomes `true`), we check the `happy_found` flag. If it's `true`, we print "Happy". Otherwise, if we finished the string without finding three consecutive vowels, we print "Sad".

This approach directly implements the problem definition by maintaining a running count of consecutive vowels and checking if it ever reaches the threshold of 3.

## Complexity Analysis

*   **Time Complexity**: $O(\sum |S|)$
    *   For each test case, we iterate through the input string `S` exactly once.
    *   Inside the loop, checking if a character is a vowel (`is_vowel` function) involves a few character comparisons, which is a constant time operation, $O(1)$.
    *   Updating the `consecutive_vowels` counter and checking the `happy_found` flag are also $O(1)$ operations.
    *   Thus, for a string of length $|S|$, the time taken is proportional to $|S|$.
    *   Given that there are $T$ test cases and the sum of $|S|$ over all test cases does not exceed $2 \cdot 10^5$, the total time complexity will be $O(\sum |S|)$, which is efficient enough for the given constraints.

*   **Space Complexity**: $O(\max |S|)$
    *   The primary space usage comes from storing the input string `S` itself, which requires $O(|S|)$ space.
    *   Apart from the input string, we use a few integer variables (`t`, `consecutive_vowels`) and a boolean variable (`happy`), which take up a constant amount of space, $O(1)$.
    *   Therefore, the auxiliary space complexity (excluding input storage) is $O(1)$. The overall space complexity is dominated by the input string, $O(\max |S|)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for using the string class
#include <vector>   // Not strictly needed for this problem, but often included
#include <unordered_set> // Not strictly needed for this problem, but often included

using namespace std;

// Helper function to check if a character is a vowel
bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        string s; // Variable to store the input string for the current test case
        cin >> s; // Read the string

        int consecutive_vowels = 0; // Counter for consecutive vowels
        bool happy = false;         // Flag to indicate if the string is "Happy"

        // Iterate through each character of the string
        for (char c : s) {
            if (is_vowel(c)) {
                // If the character is a vowel, increment the counter
                consecutive_vowels++;
                // If we have found more than 2 consecutive vowels (i.e., 3 or more)
                if (consecutive_vowels > 2) {
                    happy = true; // Set the flag to true
                    break;        // No need to check further, string is "Happy"
                }
            } else {
                // If the character is a consonant, reset the counter
                consecutive_vowels = 0;
            }
        }

        // Output "Happy" or "Sad" based on the flag
        if (happy) {
            cout << "Happy\n";
        } else {
            cout << "Sad\n";
        }
    }

    return 0; // Indicate successful execution
}

```