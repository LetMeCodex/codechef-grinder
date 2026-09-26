# [Chef and Two Strings (CHEFSTLT)](https://www.codechef.com/problems/CHEFSTLT)
- **Difficulty Rating**: 1036
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider two strings, `S1` and `S2`, of equal length. These strings can contain lowercase Latin letters ('a'-'z') and question marks ('?'). We need to replace each '?' with any lowercase Latin letter such that:
1.  The number of positions `i` where `S1[i] != S2[i]` is minimized.
2.  The number of positions `i` where `S1[i] != S2[i]` is maximized.

For each test case, we must output these two values (minimum possible difference and maximum possible difference), separated by a space.

## Intuition & Mathematical Observation

The core idea is to iterate through both strings character by character, comparing `S1[i]` and `S2[i]` at each position `i`. We need to determine how each position contributes to the `min_diff` and `max_diff` based on the characters present.

Let's analyze the possible scenarios for `S1[i]` and `S2[i]`:

1.  **Both `S1[i]` and `S2[i]` are fixed lowercase letters (not '?')**:
    *   If `S1[i] == S2[i]`: This position contributes 0 to the difference. Since both characters are fixed and identical, they will always be equal. Thus, it adds 0 to both `min_diff` and `max_diff`.
    *   If `S1[i] != S2[i]`: This position contributes 1 to the difference. Since both characters are fixed and different, they will always be unequal. Thus, it adds 1 to both `min_diff` and `max_diff`.

2.  **At least one of `S1[i]` or `S2[i]` is a '?'**:
    This is where we have flexibility in choosing replacements for the question marks.

    *   **For `min_diff`**: To minimize the difference at this position, we should always try to make `S1[i]` and `S2[i]` equal.
        *   If `S1[i]` is 'a' and `S2[i]` is '?': Replace `S2[i]` with 'a'. Difference = 0.
        *   If `S1[i]` is '?' and `S2[i]` is 'b': Replace `S1[i]` with 'b'. Difference = 0.
        *   If `S1[i]` is '?' and `S2[i]` is '?': Replace both with 'a' (or any same letter). Difference = 0.
        In all these sub-cases, we can always make the characters at position `i` equal. Therefore, this position contributes **0** to `min_diff`.

    *   **For `max_diff`**: To maximize the difference at this position, we should always try to make `S1[i]` and `S2[i]` different.
        *   If `S1[i]` is 'a' and `S2[i]` is '?': Replace `S2[i]` with 'b` (any letter different from 'a'). Difference = 1.
        *   If `S1[i]` is '?' and `S2[i]` is 'b': Replace `S1[i]` with 'a' (any letter different from 'b'). Difference = 1.
        *   If `S1[i]` is '?' and `S2[i]` is '?': Replace `S1[i]` with 'a' and `S2[i]` with 'b'. Difference = 1.
        In all these sub-cases, we can always make the characters at position `i` different. Therefore, this position contributes **1** to `max_diff`.

**Summary of contributions per position `i`:**

| `S1[i]` | `S2[i]` | `min_diff` contribution | `max_diff` contribution |
| :------ | :------ | :---------------------- | :---------------------- |
| `char`  | `char`  | `(S1[i] != S2[i]) ? 1 : 0` | `(S1[i] != S2[i]) ? 1 : 0` |
| `?`     | `char`  | `0`                     | `1`                     |
| `char`  | `?`     | `0`                     | `1`                     |
| `?`     | `?`     | `0`                     | `1`                     |

The solution iterates through the strings, applying these rules to accumulate `min_diff` and `max_diff`.

## Complexity Analysis

Let `N` be the length of the strings `s1` and `s2`.
Let `T` be the number of test cases.

*   **Time Complexity**: $O(T \cdot N)$
    For each test case, we read two strings of length `N`, which takes $O(N)$ time. Then, we iterate through the strings once using a `for` loop that runs `N` times. Inside the loop, operations like character comparison and integer increments are constant time, $O(1)$. Therefore, processing a single test case takes $O(N)$ time. With `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    For each test case, we store the two input strings `s1` and `s2`, each of length `N`. This requires $O(N)$ space. A few integer variables (`t`, `min_diff`, `max_diff`, `n`, `i`) use $O(1)$ space. The space complexity is dominated by storing the input strings, resulting in $O(N)$ space per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // As requested

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        string s1, s2;
        cin >> s1 >> s2; // Read the two strings for the current test case

        int min_diff = 0; // Initialize minimal difference
        int max_diff = 0; // Initialize maximal difference
        int n = s1.length(); // Get the length of the strings (S1 and S2 have equal length)

        // Iterate through each character position in the strings
        for (int i = 0; i < n; ++i) {
            // Check if either character at the current position is a question mark
            if (s1[i] == '?' || s2[i] == '?') {
                // If at least one character is '?', we have flexibility:
                // For minimal difference: We can always replace '?' to make s1[i] and s2[i] equal.
                // For example, if s1[i] is 'a' and s2[i] is '?', replace s2[i] with 'a'.
                // If both are '?', replace both with 'a'. In these cases, the difference is 0.
                // So, min_diff does not increase.

                // For maximal difference: We can always replace '?' to make s1[i] and s2[i] different.
                // For example, if s1[i] is 'a' and s2[i] is '?', replace s2[i] with 'b'.
                // If both are '?', replace s1[i] with 'a' and s2[i] with 'b'. In these cases, the difference is 1.
                // So, max_diff increases by 1.
                max_diff++;
            } else {
                // Both characters are fixed lowercase Latin letters (not '?')
                // If the characters are different, this position contributes 1 to the difference.
                if (s1[i] != s2[i]) {
                    // Since they are fixed and different, they contribute 1 to both
                    // the minimal and maximal possible differences.
                    min_diff++;
                    max_diff++;
                }
                // If s1[i] == s2[i], they are fixed and equal. They contribute 0 to both
                // minimal and maximal differences. No change to min_diff or max_diff.
            }
        }
        // Output the calculated minimal and maximal differences, separated by a space,
        // followed by a newline for the next test case.
        cout << min_diff << " " << max_diff << "\n";
    }
    return 0; // Indicate successful execution
}
```