# [Brackets (BRACKETS)](https://www.codechef.com/problems/BRACKETS)
- **Difficulty Rating**: 1207
- **Solved in**: 2 attempt(s)

## Problem Summary

Mike is given a parentheses sequence `A`. He wants to construct a new parentheses sequence `B` that satisfies three conditions:
1.  `F(B) = F(A)`: The maximal balance over all prefixes of `B` must be equal to the maximal balance over all prefixes of `A`.
2.  `B` has minimal length.
3.  `B` is lexicographically smallest among all sequences satisfying conditions 1 and 2.

The balance of a parentheses sequence is calculated by assigning `+1` for an opening parenthesis `(` and `-1` for a closing parenthesis `)`. `F(S)` is defined as the maximum balance encountered when scanning `S` from left to right, starting with an initial balance of 0.

## Intuition & Mathematical Observation

Let's denote `K = F(A)`. Our goal is to construct a sequence `B` such that `F(B) = K`, `B` has minimal length, and `B` is lexicographically smallest.

1.  **Calculating `F(A)`**: This is straightforward. We iterate through the input string `A`, maintaining a `current_balance`. If we see `(`, we increment `current_balance`; if we see `)`, we decrement it. We also maintain a `max_balance_seen` variable, updating it with `max_balance_seen = std::max(max_balance_seen, current_balance)` at each step. The final `max_balance_seen` will be `F(A)`.

2.  **Minimal Length for `F(B) = K`**:
    To achieve a maximal balance of `K`, `B` must contain at least `K` opening parentheses. If `B` only consisted of `K` opening parentheses (e.g., `((...(` K times), its `F(B)` would be `K`, and its length would be `K`. However, the problem examples (like `F(A)=3` resulting in `((()))`) suggest that the resulting sequence `B` should typically be a "well-formed" or "balanced" sequence, where the final balance is 0. If the final balance must be 0, and the maximum balance reached is `K`, then `B` must contain exactly `K` opening parentheses and `K` closing parentheses. In this case, the minimal length would be `2K`.

3.  **Lexicographically Smallest for `F(B) = K` and Minimal Length**:
    Assuming `B` must have a final balance of 0 and thus a length of `2K`:
    *   To be lexicographically smallest, we want to place `(` characters as early as possible.
    *   To achieve `F(B) = K`, the balance must reach `K` at some point. The most direct way to do this while keeping `(` characters early is to have `K` opening parentheses consecutively at the beginning. This brings the balance to `K`.
    *   After reaching a balance of `K`, to bring the balance back to 0 (for a total of `K` opening and `K` closing parentheses) and maintain the lexicographical smallest property, we should then place `K` closing parentheses.
    *   Consider the sequence formed by `K` opening parentheses followed by `K` closing parentheses: `((...()))` (K times `(` and K times `)`).
        *   Its prefixes are `(`, `((`, ..., `((...(` (K times). The balances are `1, 2, ..., K`. So, `F(B) = K`.
        *   Its length is `2K`.
        *   Any other sequence of length `2K` with `F(B)=K` would either:
            *   Have a `)` earlier than the `K`-th character, making it lexicographically larger (e.g., `()((()))` for `K=3` is not length `2K`, and `F` is 2).
            *   Not achieve `F(B)=K`.
    *   Therefore, the sequence consisting of `K` opening parentheses followed by `K` closing parentheses is the unique solution that satisfies all three conditions.

The overall strategy is:
1.  Compute `K = F(A)`.
2.  Print `K` opening parentheses.
3.  Print `K` closing parentheses.

## Complexity Analysis

Let $N$ be the maximum length of the input string `A`.

-   **Time Complexity**:
    -   Reading the number of test cases `t`: $O(1)$.
    -   For each test case:
        -   Reading the string `A`: $O(N)$.
        -   Calculating `max_balance` (which is `F(A)`): This involves a single pass through the string `A`, performing constant time operations for each character. So, $O(N)$.
        -   Printing the resulting string `B`: The length of `B` is `2 * max_balance`. Since `max_balance` can be at most $N$, printing `B` takes $O(N)$ time.
    -   Total time complexity per test case is $O(N)$.
    -   With $T$ test cases, the total time complexity is $O(T \cdot N)$. Given $T \le 10$ and $N \le 10^5$, $T \cdot N \le 10 \cdot 10^5 = 10^6$, which is efficient enough for the typical time limit of 1-2 seconds.

-   **Space Complexity**:
    -   Storing the input string `A`: A `char` array of size `100001` is used, which is $O(N)$ where $N$ is the maximum possible length of `A`.
    -   Other variables (`t`, `balance`, `max_balance`, loop counters): These use a constant amount of memory, $O(1)$.
    -   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <cstdio>    // For scanf, printf
#include <algorithm> // For std::max

// Max length of A is 100000. Need 100001 for the null terminator.
// Declaring it globally avoids potential stack overflow for large arrays
// if declared inside main, and ensures zero-initialization.
char A[100001];

int main() {
    // When using scanf/printf, there's no need for ios_base::sync_with_stdio(false)
    // or cin.tie(NULL), as these are specific to C++ iostreams.

    int t;
    scanf("%d", &t); // Read the number of testcases

    while (t--) { // Loop through each testcase
        scanf("%s", A); // Read Mike's current parentheses sequence A into the char array

        int balance = 0;
        int max_balance = 0;

        // Calculate F(A), which is the maximal balance over all prefixes of A.
        // Iterate through the C-style string until the null terminator is found.
        for (int i = 0; A[i] != '\0'; ++i) {
            if (A[i] == '(') {
                balance++;
            } else { // A[i] == ')'
                balance--;
            }
            max_balance = std::max(max_balance, balance); // Update max_balance
        }

        // Construct the new parentheses sequence B.
        // B must have F(B) == max_balance, minimal length, and be lexicographically smallest.
        // This is achieved by a string of 'max_balance' opening parentheses
        // followed by 'max_balance' closing parentheses.
        // Example: if max_balance is 3, B will be "((()))"
        for (int i = 0; i < max_balance; ++i) {
            printf("("); // Print an opening parenthesis
        }
        for (int i = 0; i < max_balance; ++i) {
            printf(")"); // Print a closing parenthesis
        }
        printf("\n"); // Print a newline after each testcase output
    }

    return 0;
}
```