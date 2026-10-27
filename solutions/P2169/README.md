# [Opposite Attract (P2169)](https://www.codechef.com/problems/P2169)
- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to take a binary string `S` of length `N` and generate a new binary string `T` of the same length. For each character `S[i]` in the input string, the corresponding character `T[i]` in the output string should be its "opposite". Specifically:
- If `S[i]` is '0', then `T[i]` should be '1'.
- If `S[i]` is '1', then `T[i]` should be '0'.

We need to do this for multiple test cases.

## Intuition & Mathematical Observation

The problem is a straightforward character-by-character transformation. There's no complex algorithm, data structure, or deep mathematical insight required. The "opposite" of a binary digit is simply its complement.

For each character `s[i]` in the input string `S`:
- If `s[i]` is '0', its complement is '1'.
- If `s[i]` is '1', its complement is '0'.

Therefore, the solution involves iterating through the input string `S` from left to right, and for each character, printing its complement directly to the output.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading the integer `N` takes $O(1)$ time.
    -   Reading the binary string `S` of length `N` takes $O(N)$ time.
    -   The core logic involves a single loop that iterates `N` times (from `i = 0` to `N-1`). Inside the loop, we perform a constant number of operations (character comparison and printing). Thus, this loop takes $O(N)$ time.
    -   Printing the final newline takes $O(1)$ time.
    -   Combining these, the total time complexity for a single test case is $O(N)$.
    -   For `T` test cases, the total time complexity would be $O(\sum N)$, where $\sum N$ is the sum of lengths of strings across all test cases.

-   **Space Complexity**: $O(N)$
    -   We need $O(1)$ space to store the integer `N`.
    -   We need $O(N)$ space to store the input binary string `S`.
    -   The output string `T` is generated and printed character by character, so we don't need to store the entire `T` in memory.
    -   Therefore, the dominant factor for space complexity is storing the input string `S`, resulting in $O(N)$ space complexity per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

void solve() {
    int n;
    cin >> n; // Read the length of the binary string S
    string s;
    cin >> s; // Read the binary string S

    // Iterate through each character of S
    for (int i = 0; i < n; ++i) {
        // If the character is '0', its opposite is '1'
        if (s[i] == '0') {
            cout << '1';
        } 
        // If the character is '1', its opposite is '0'
        else { // Since S is a binary string, s[i] must be '1' if not '0'
            cout << '0';
        }
    }
    cout << "\n"; // Print a newline after generating T for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}
```