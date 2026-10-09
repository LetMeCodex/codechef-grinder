# [Alternate Additions (ALTERADD)](https://www.codechef.com/problems/ALTERADD)
- **Difficulty Rating**: 863
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has two numbers, `A` and `B`. He wants to make `A` equal to `B` by performing a sequence of operations. The operations must alternate:
1.  Add 1 to `A`.
2.  Add 2 to `A`.
3.  Add 1 to `A`.
4.  Add 2 to `A`.
... and so on.

Chef always starts with adding 1. The task is to determine if it's possible for Chef to make `A` equal to `B` using this alternating sequence of additions.

## Intuition & Mathematical Observation

Let's analyze the total amount added to `A` after a certain number of operations:

*   **After 1 operation**: Chef adds `+1`. Total added: `1`.
*   **After 2 operations**: Chef adds `+1`, then `+2`. Total added: `1 + 2 = 3`.
*   **After 3 operations**: Chef adds `+1`, `+2`, then `+1`. Total added: `1 + 2 + 1 = 4`.
*   **After 4 operations**: Chef adds `+1`, `+2`, `+1`, then `+2`. Total added: `1 + 2 + 1 + 2 = 6`.
*   **After 5 operations**: Chef adds `+1`, `+2`, `+1`, `+2`, then `+1`. Total added: `1 + 2 + 1 + 2 + 1 = 7`.

We are interested in the difference `diff = B - A`. Chef needs to add exactly `diff` to `A`. Let's observe the pattern of the total amount added modulo 3:

*   `1 % 3 = 1`
*   `3 % 3 = 0`
*   `4 % 3 = 1`
*   `6 % 3 = 0`
*   `7 % 3 = 1`

It appears that the total amount added can *never* be congruent to 2 modulo 3. Let's prove this more formally:

1.  **Consider an even number of operations (say, `2k` operations):**
    Each pair of operations consists of `+1` followed by `+2`, which adds a total of `3` to `A`.
    After `k` such pairs (i.e., `2k` operations), the total amount added to `A` will be `3k`.
    The value `3k` is always congruent to `0` modulo 3 (`3k % 3 == 0`).

2.  **Consider an odd number of operations (say, `2k+1` operations):**
    This consists of `k` pairs of operations (adding `3k`) plus one additional `+1` operation.
    So, the total amount added to `A` will be `3k + 1`.
    The value `3k + 1` is always congruent to `1` modulo 3 (`(3k + 1) % 3 == 1`).

From these observations, we can conclude that the total amount added to `A` will always be either `0` modulo 3 or `1` modulo 3. It will *never* be `2` modulo 3.

Therefore, if the required difference `(B - A)` is congruent to `2` modulo 3, it's impossible for Chef to make `A` equal to `B`. In all other cases (i.e., `(B - A) % 3 == 0` or `(B - A) % 3 == 1`), it is possible.

The solution simply calculates `diff = B - A` and checks `diff % 3`. If it's `2`, output "NO"; otherwise, output "YES".

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a few constant-time arithmetic operations (subtraction, modulo) and a comparison. This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: We only use a few integer variables (`T`, `A`, `B`, `diff`) to store input and intermediate calculations. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int A, B;
        cin >> A >> B; // Read the two numbers A and B

        int diff = B - A; // Calculate the difference B - A

        // Chef can make A equal to B if the difference (B-A)
        // is not congruent to 2 modulo 3.
        // This means (B-A) % 3 must be either 0 or 1.
        if (diff % 3 == 2) {
            cout << "NO\n"; // If diff % 3 is 2, it's impossible
        } else {
            cout << "YES\n"; // Otherwise (diff % 3 is 0 or 1), it's possible
        }
    }

    return 0; // Indicate successful execution
}
```