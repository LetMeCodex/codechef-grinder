# [Schrodinger Smiley (SMILEY)](https://www.codechef.com/problems/SMILEY)
- **Difficulty Rating**: 1371
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "Schrodinger Smileys" within a given string `S`. A Schrodinger Smiley is defined by the pattern `':)'` where the `')'` part consists of one or more consecutive closing parentheses. Specifically, it's a substring that starts with a colon `':'`, followed by at least one closing parenthesis `')'`, and then ends with another colon `':'`. For example, `":):"` and `":)):"` are valid smileys. An opening parenthesis `'('` acts as a "reset" and breaks any ongoing potential smiley sequence.

## Intuition & Mathematical Observation

The problem requires us to identify a specific pattern `':', ')', ':'` with the middle `')'` being one or more characters. Since we need to count occurrences and the pattern has a sequential nature, a single pass (linear scan) through the string seems appropriate. We can maintain a few state variables to track our progress in forming a smiley:

1.  **`last_colon_pos`**: This variable will store the index of the most recently encountered colon `':'` that could potentially be the *start* of a smiley. If no such colon is active (e.g., after an opening parenthesis `'('`), we can set it to a special value like `-1`.
2.  **`current_right_parentheses_count`**: This variable will count the number of consecutive closing parentheses `')'` encountered *after* `last_colon_pos` and *before* the current character being processed.

We iterate through the string character by character and update these states:

*   **If `S[i] == '('`**:
    An opening parenthesis breaks any potential smiley sequence. We must reset our state:
    *   Set `last_colon_pos = -1`.
    *   Set `current_right_parentheses_count = 0`.

*   **If `S[i] == ')'`**:
    A closing parenthesis can be part of the middle section of a smiley.
    *   If `last_colon_pos != -1` (meaning there's an active starting colon), we increment `current_right_parentheses_count`.
    *   If `last_colon_pos == -1`, this `')'` is not preceded by a potential starting colon, so it doesn't contribute to any active smiley, and `current_right_parentheses_count` remains `0`.

*   **If `S[i] == ':'`**:
    A colon can be the *ending* colon of a smiley.
    *   We check if we have an active starting colon (`last_colon_pos != -1`) AND if we have accumulated at least one closing parenthesis in between (`current_right_parentheses_count > 0`).
    *   If both conditions are true, we have found a valid Schrodinger Smiley! Increment our `total_smileys` count.
    *   After checking, this current colon `S[i]` now becomes the *new potential starting colon* for subsequent smileys.
    *   Set `last_colon_pos = i`.
    *   Reset `current_right_parentheses_count = 0`, because any `')'` characters encountered *after* this new `last_colon_pos` would belong to a *new* potential smiley sequence.

By following this logic, we ensure that each valid smiley `':...:'` is counted exactly once. The `long long` type for `total_smileys` is used for safety, although for `N <= 10^5`, the maximum number of smileys would fit within an `int`.

## Complexity Analysis

*   **Time Complexity**: The solution involves a single pass through the input string `S`. For each character, we perform a constant number of operations (comparisons, assignments, increments). If `N` is the length of the string, the time complexity for processing one test case is $O(N)$. Given `T` test cases, the total time complexity is $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of `S`.

*   **Space Complexity**: The solution uses a few integer variables (`N`, `total_smileys`, `last_colon_pos`, `current_right_parentheses_count`) which take $O(1)$ auxiliary space. The input string `S` itself takes $O(N)$ space. Therefore, the overall space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    long long total_smileys = 0; // Use long long for safety, though int is sufficient for N <= 10^5
    int last_colon_pos = -1; // Stores the index of the last encountered colon.
                             // -1 indicates no active starting colon (e.g., after an '(').
    int current_right_parentheses_count = 0; // Counts consecutive ')' characters
                                             // immediately following 'last_colon_pos'.

    for (int i = 0; i < N; ++i) {
        if (S[i] == '(') {
            // An opening parenthesis breaks any potential smiley sequence.
            // Reset last_colon_pos to indicate no active starting colon.
            last_colon_pos = -1;
            current_right_parentheses_count = 0;
        } else if (S[i] == ')') {
            // A closing parenthesis can be part of a smiley.
            // Only count it if there's an active starting colon.
            if (last_colon_pos != -1) {
                current_right_parentheses_count++;
            }
            // If last_colon_pos is -1, this ')' is not preceded by a colon
            // that could start a smiley, so current_right_parentheses_count remains 0.
        } else if (S[i] == ':') {
            // A colon can be the end of a Schrödinger's Smiley.
            // Check if there's an active starting colon and a positive number of ')'s in between.
            if (last_colon_pos != -1 && current_right_parentheses_count > 0) {
                total_smileys++;
            }
            
            // This current colon now becomes the new potential starting colon.
            last_colon_pos = i;
            // Reset the count of ')' because any ')'s after this colon would start a new sequence.
            current_right_parentheses_count = 0;
        }
    }

    std::cout << total_smileys << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```