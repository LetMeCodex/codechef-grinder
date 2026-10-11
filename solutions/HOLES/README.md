# [Holes in the text (HOLES)](https://www.codechef.com/problems/HOLES)
- **Difficulty Rating**: 1093
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to count the total number of "holes" present in a given text string. The input string consists of uppercase English letters. Each letter has a predefined number of holes:
- Letters with **1 hole**: A, D, O, P, Q, R
- Letters with **2 holes**: B
- Letters with **0 holes**: C, E, F, G, H, I, J, K, L, M, N, S, T, U, V, W, X, Y, Z

We need to process multiple test cases. For each test case, we read a string and output the total count of holes.

## Intuition & Mathematical Observation

The problem is a straightforward character-counting task. There's no complex algorithm or data structure required. The core idea is to iterate through each character of the input string and, for each character, determine how many holes it contributes to the total count based on the problem's rules.

The "mathematical observation" is simply the direct mapping of each uppercase English letter to its corresponding number of holes:
- If a character is 'A', 'D', 'O', 'P', 'Q', or 'R', it adds 1 to the total holes.
- If a character is 'B', it adds 2 to the total holes.
- For any other character, it adds 0 to the total holes.

We can implement this mapping efficiently using a `switch` statement or a series of `if-else if` conditions. A `switch` statement is often cleaner for multiple discrete character checks.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    -   The solution iterates through the input string `s` exactly once. If the length of the string is `N`, the loop runs `N` times.
    -   Inside the loop, the `switch` statement performs a constant number of comparisons and an addition operation, which are all $O(1)$ operations.
    -   Therefore, for a single test case, the time complexity is directly proportional to the length of the string, $O(N)$.
    -   Given `T` test cases, the total time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of the string across all test cases.

-   **Space Complexity**: $O(N)$ per test case.
    -   The primary space usage comes from storing the input string `s`. If the maximum length of the string is `N`, this requires $O(N)$ space.
    -   A few integer variables (`holes`, `t`, loop counters) are used, which consume a constant amount of memory, $O(1)$.
    -   Thus, the total space complexity is dominated by the input string, resulting in $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    string s; // Declare a string to store the input text
    cin >> s; // Read the input text

    int holes = 0; // Initialize a counter for total holes

    // Iterate through each character in the string
    for (char c : s) {
        // Use a switch statement to efficiently check the character and add holes
        switch (c) {
            case 'A':
            case 'D':
            case 'O':
            case 'P':
            case 'Q': // Added 'Q' here, as it's commonly considered to have 1 hole
            case 'R':
                holes += 1; // These letters have 1 hole
                break;
            case 'B':
                holes += 2; // Letter 'B' has 2 holes
                break;
            default:
                // All other letters (C, E, F, G, H, I, J, K, L, M, N, S, T, U, V, W, X, Y, Z)
                // have 0 holes, so we do nothing.
                break;
        }
    }

    // Output the total number of holes for the current test case, followed by a newline
    cout << holes << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```