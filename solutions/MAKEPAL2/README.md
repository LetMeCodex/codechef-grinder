# [Make Palindrome 2 (MAKEPAL2)](https://www.codechef.com/problems/MAKEPAL2)
- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to take a binary string `S` of length `N`. We are allowed to delete at most `floor(N/2)` characters from `S`. Our goal is to make the resulting string a palindrome. We need to output *any* such palindrome.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the deletion constraint and finding a simple type of palindrome that can always be formed within this constraint.

1.  **What is a palindrome?** A string that reads the same forwards and backwards (e.g., "000", "11", "010", "1001").
2.  **Simplest Palindromes:** The simplest palindromes in a binary string context are those composed entirely of a single character, like "000..." or "111...". If we can form such a palindrome, it would satisfy the problem's requirement.

Let's count the occurrences of '0's and '1's in the original string `S`.
Let `count0` be the number of '0's and `count1` be the number of '1's.
We know that `count0 + count1 = N`.

Consider two strategies:

*   **Strategy A: Form a palindrome consisting only of '0's.**
    To achieve this, we must delete all `count1` occurrences of '1's from the string. The remaining `count0` '0's will form a palindrome (e.g., "000").
    For this strategy to be valid, the number of deletions (`count1`) must be less than or equal to `floor(N/2)`.
    Let's check when this condition holds:
    If `count0 >= count1`:
    Since `count0 + count1 = N` and `count0 >= count1`, we can substitute `count0` with `count1` (or a smaller value) in the sum:
    `count1 + count1 <= count0 + count1`
    `2 * count1 <= N`
    `count1 <= N/2`
    Since `count1` must be an integer, this implies `count1 <= floor(N/2)`.
    Therefore, if `count0 >= count1`, we can always delete all '1's (which is `count1` deletions) and form a palindrome of `count0` '0's. The number of deletions will always be within the allowed limit.

*   **Strategy B: Form a palindrome consisting only of '1's.**
    To achieve this, we must delete all `count0` occurrences of '0's from the string. The remaining `count1` '1's will form a palindrome (e.g., "111").
    For this strategy to be valid, the number of deletions (`count0`) must be less than or equal to `floor(N/2)`.
    Let's check when this condition holds:
    If `count1 > count0`:
    Since `count0 + count1 = N` and `count1 > count0`, we can substitute `count1` with `count0` (or a larger value) in the sum:
    `count0 + count0 < count0 + count1`
    `2 * count0 < N`
    `count0 < N/2`
    Since `count0` must be an integer, this implies `count0 <= floor(N/2)`.
    Therefore, if `count1 > count0`, we can always delete all '0's (which is `count0` deletions) and form a palindrome of `count1` '1's. The number of deletions will always be within the allowed limit.

**Conclusion:**
Combining these two strategies, we can always form a palindrome by keeping only the character that appears more frequently (or '0's if the counts are equal). The number of characters to delete (the count of the less frequent character) will always be less than or equal to `floor(N/2)`, thus satisfying the problem's constraint.

**Example:**
*   `N=5, S="01010"`
    `count0 = 3`, `count1 = 2`. `floor(N/2) = floor(5/2) = 2`.
    Since `count0 (3) >= count1 (2)`, we keep '0's. We delete `count1 = 2` '1's.
    `2 <= floor(N/2) (2)` is true. Output: "000".
*   `N=4, S="0110"`
    `count0 = 2`, `count1 = 2`. `floor(N/2) = floor(4/2) = 2`.
    Since `count0 (2) >= count1 (2)`, we keep '0's. We delete `count1 = 2` '1's.
    `2 <= floor(N/2) (2)` is true. Output: "00". (If we chose '1's, it would be "11", also valid).
*   `N=3, S="110"`
    `count0 = 1`, `count1 = 2`. `floor(N/2) = floor(3/2) = 1`.
    Since `count1 (2) > count0 (1)`, we keep '1's. We delete `count0 = 1` '0'.
    `1 <= floor(N/2) (1)` is true. Output: "11".

This simple greedy approach always yields a valid palindrome.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and the string `S` takes $O(N)$ time.
    *   Iterating through the string `S` once to count `count0` and `count1` takes $O(N)$ time.
    *   Printing the resulting palindrome (either `count0` '0's or `count1` '1's) takes $O(N)$ time in the worst case (when one character type dominates).
    *   For each test case, the total time complexity is $O(N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing the input string `S` requires $O(N)$ space.
    *   Variables like `n`, `count0`, `count1` use $O(1)$ space.
    *   Since the string `S` is read anew for each test case, the space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the binary string

    int count0 = 0; // Counter for '0's
    int count1 = 0; // Counter for '1's
    for (char c : s) { // Iterate through the string to count '0's and '1's
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // We want to form a palindrome consisting of only '0's or only '1's.
    // This is always possible within the given deletion constraints.
    // The strategy is to keep the character type that appears more frequently (or equally frequently).

    if (count0 >= count1) {
        // If there are more or an equal number of '0's than '1's,
        // we can form a palindrome consisting only of '0's.
        // We keep all `count0` '0's and delete all `count1` '1's.
        // The number of deletions is `count1`.
        // Constraint: `count1 <= floor(N/2)`.
        // Proof: Since `count0 >= count1` and `count0 + count1 = N`,
        // it implies `2 * count1 <= count0 + count1 = N`, so `count1 <= N/2`.
        // Thus, `count1 <= floor(N/2)` is always true, meaning this is a valid operation.
        for (int i = 0; i < count0; ++i) {
            cout << '0'; // Print `count0` '0's
        }
        cout << "\n"; // Newline after each test case output
    } else {
        // If there are more '1's than '0's,
        // we can form a palindrome consisting only of '1's.
        // We keep all `count1` '1's and delete all `count0` '0's.
        // The number of deletions is `count0`.
        // Constraint: `count0 <= floor(N/2)`.
        // Proof: Since `count1 > count0` and `count0 + count1 = N`,
        // it implies `2 * count0 < count0 + count1 = N`, so `count0 < N/2`.
        // Thus, `count0 <= floor(N/2)` is always true, meaning this is a valid operation.
        for (int i = 0; i < count1; ++i) {
            cout << '1'; // Print `count1` '1's
        }
        cout << "\n"; // Newline after each test case output
    }
}

int main() {
    // Fast I/O setup as per competitive programming best practices
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();
    }

    return 0;
}
```