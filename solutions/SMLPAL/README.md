# [Small Palindrome (SMLPAL)](https://www.codechef.com/problems/SMLPAL)
- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct the lexicographically smallest palindrome using a given number of '1's ($X$) and '2's ($Y$). We are guaranteed that both $X$ and $Y$ will always be even integers.

## Intuition & Mathematical Observation

1.  **Lexicographically Smallest**: To make a string lexicographically smallest, we want to place smaller characters ('1's) as far to the left as possible.
2.  **Palindrome Property**: A string is a palindrome if it reads the same forwards and backwards. This implies that the first half of the string completely determines the second half (the second half is the reverse of the first half).
3.  **Even Counts ($X, Y$)**: The problem states that $X$ and $Y$ are always even. This is a crucial observation.
    *   If $X$ is even and $Y$ is even, then the total number of characters $X+Y$ is also even.
    *   This means the palindrome will always have an even length, and there will be no single "middle" character that doesn't have a pair.
    *   The length of the first half of the palindrome will be $(X+Y)/2$.
    *   This first half must contain exactly $X/2$ ones and $Y/2$ twos.
4.  **Constructing the Smallest Palindrome**:
    *   To make the *entire* palindrome lexicographically smallest, we must make its *first half* lexicographically smallest.
    *   To make a string of length $(X+Y)/2$ with $X/2$ ones and $Y/2$ twos lexicographically smallest, we should place all the '1's before all the '2's.
    *   So, the first half of our palindrome will be: `(X/2 ones) followed by (Y/2 twos)`.
5.  **Completing the Palindrome**:
    *   Once the first half is determined, the second half is simply the reverse of the first half.
    *   If the first half is `(X/2 ones) + (Y/2 twos)`, then its reverse is `(Y/2 twos) + (X/2 ones)`.
    *   Combining these, the full palindrome will be:
        ` (X/2 ones) + (Y/2 twos) + (Y/2 twos) + (X/2 ones) `

This construction uses a total of $X/2 + X/2 = X$ ones and $Y/2 + Y/2 = Y$ twos, satisfying the problem constraints, and ensures the '1's are as far left as possible, resulting in the lexicographically smallest palindrome.

**Example**: $X=2, Y=2$
*   Total length: $2+2=4$.
*   First half length: $4/2=2$.
*   First half needs $X/2=1$ one and $Y/2=1$ two.
*   Smallest first half: `12`
*   Reverse of first half: `21`
*   Resulting palindrome: `1221`

## Complexity Analysis

Let $N = X+Y$ be the total length of the palindrome.

*   **Time Complexity**: $O(N)$
    *   Reading inputs $X$ and $Y$ takes $O(1)$.
    *   The `string::reserve` call is $O(1)$ on average.
    *   The four `for` loops iterate a total of $X/2 + Y/2 + Y/2 + X/2 = X+Y = N$ times. Each `string::operator+=` (appending a single character) takes amortized $O(1)$ time.
    *   Printing the final string of length $N$ takes $O(N)$ time.
    *   Therefore, for a single test case, the total time complexity is $O(N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$. With $X, Y \le 100$, $N \le 200$. $T \le 1000$. The maximum operations would be around $1000 \times 200 = 2 \times 10^5$, which is well within typical time limits.

*   **Space Complexity**: $O(N)$
    *   The `string result` stores the final palindrome, which has a length of $N = X+Y$. This requires $O(N)$ space.
    *   All other variables (`X`, `Y`, `T`, loop counters) use $O(1)$ space.
    *   Thus, the dominant space usage is for the result string, leading to $O(N)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the number of ones (X) and twos (Y)
    cin >> X >> Y;

    // A string to build the palindrome
    string result = "";
    // Reserve space to avoid reallocations. For max length 200, this is a minor optimization.
    result.reserve(X + Y); 

    // The strategy to form the smallest palindrome is to place '1's first
    // in the left half, followed by '2's.
    // Since X and Y are even, the total length (X+Y) is also even.
    // The palindrome will be formed by a left half and its reverse.
    // If the left half uses X/2 ones and Y/2 twos, the total will be X ones and Y twos.

    // 1. Append X/2 ones to form the initial part of the left half
    for (int i = 0; i < X / 2; ++i) {
        result += '1';
    }

    // 2. Append Y/2 twos to complete the left half
    for (int i = 0; i < Y / 2; ++i) {
        result += '2';
    }

    // Now, append the reverse of the left half.
    // The reverse of (X/2 ones followed by Y/2 twos) is (Y/2 twos followed by X/2 ones).

    // 3. Append Y/2 twos for the first part of the right half (mirroring the '2's from left half)
    for (int i = 0; i < Y / 2; ++i) {
        result += '2';
    }

    // 4. Append X/2 ones for the second part of the right half (mirroring the '1's from left half)
    for (int i = 0; i < X / 2; ++i) {
        result += '1';
    }

    // Output the constructed palindrome followed by a newline
    cout << result << "\n";
}

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}
```