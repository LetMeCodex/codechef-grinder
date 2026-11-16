# [Piece of cake (LCH15JAB)](https://www.codechef.com/problems/LCH15JAB)
- **Difficulty Rating**: 1144
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if, for a given string `S` consisting of lowercase Latin letters, there exists at least one character such that its total count in the string is equal to the sum of the counts of all other characters in the string. We need to output "YES" or "NO" for each test case.

## Intuition & Mathematical Observation

Let's denote the count of a specific character `x` in the string `S` as `C_x`.
Let `S_others` be the sum of the counts of all characters *other than* `x`.

The problem condition states that we need to find if there exists any character `x` such that:
`C_x = S_others`

We also know that the total length of the string `S`, let's call it `L`, is the sum of the counts of *all* characters in the string. This can be expressed as:
`L = C_x + S_others`

Now, we can substitute the problem condition (`C_x = S_others`) into the total length equation:
`L = C_x + C_x`
`L = 2 * C_x`

This equation `L = 2 * C_x` is the key insight. It tells us two critical things:

1.  **The total length `L` of the string must be an even number.** If `L` were odd, then `2 * C_x` would also be odd (since `C_x` is an integer count), which is a contradiction. Therefore, if the string length `L` is odd, it's impossible for the condition to be met, and we can immediately say "NO".

2.  **If `L` is an even number, then for the condition to hold, the count of the character `x` (`C_x`) must be exactly half of the total length.** That is, `C_x = L / 2`.

So, the strategy to solve the problem simplifies to:
1.  Calculate the frequency of each lowercase Latin character in the input string `S`.
2.  Determine the total length `L` of the string `S`.
3.  If `L` is odd, print "NO".
4.  If `L` is even, calculate the `target_count = L / 2`.
5.  Iterate through the frequencies of all 26 possible characters. If any character's frequency is exactly equal to `target_count`, then we have found such a character, and we can print "YES".
6.  If, after checking all character frequencies, none match `target_count`, then no such character exists, and we print "NO".

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the input string `S` takes $O(|S|)$ time, where $|S|$ is the length of the string.
    *   Calculating character frequencies involves iterating through the string once. This takes $O(|S|)$ time, as each character access and frequency update is $O(1)$.
    *   Determining the string length and performing basic arithmetic operations (like modulo and division) are all $O(1)$.
    *   Iterating through the `freq` vector (which has a fixed size of 26 for lowercase English letters) to check for `target_count` takes $O(26)$, which simplifies to $O(1)$ as 26 is a constant.
    *   Therefore, for each test case, the dominant operation is reading the string and calculating frequencies, resulting in a time complexity of $O(|S|)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot |S|_{max})$, where $|S|_{max}$ is the maximum possible length of the string.

*   **Space Complexity**:
    *   Storing the input string `S` requires $O(|S|)$ space.
    *   The `freq` vector stores the counts for 26 characters. This is a fixed amount of space, $O(26)$, which simplifies to $O(1)$ (constant space) because the alphabet size is independent of the input string length.
    *   Thus, the total space complexity is dominated by storing the input string, which is $O(|S|)$. If we consider auxiliary space (space used beyond input storage), it's $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions
using namespace std; // Uses the standard namespace, as per problem instructions

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the input string S

    // A vector to store frequencies of lowercase Latin letters.
    // 'a' maps to index 0, 'b' to 1, ..., 'z' to 25.
    // Initialized with all zeros.
    vector<int> freq(26, 0); 

    // Iterate through the string to calculate character frequencies
    for (char c : s) {
        freq[c - 'a']++; // Increment count for the corresponding character
    }

    int total_length = s.length(); // Get the total length of the string

    // The condition "count of one character equals sum of counts of others"
    // implies that total_length = count_of_that_char + count_of_that_char
    // i.e., total_length = 2 * count_of_that_char.
    // This means total_length must be an even number.
    // If total_length is odd, no such character can exist.
    if (total_length % 2 != 0) {
        cout << "NO\n"; // Output "NO" and return for this test case
        return;
    }

    // If total_length is even, the target count for a character
    // to satisfy the condition is exactly half of the total length.
    int target_count = total_length / 2;

    // Check if any character's frequency matches the target_count
    bool found = false;
    for (int count : freq) { // Iterate through all 26 possible character counts
        if (count == target_count) {
            found = true; // Found a character that satisfies the condition
            break;        // No need to check further, we found one
        }
    }

    // Output "YES" or "NO" based on whether such a character was found
    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```