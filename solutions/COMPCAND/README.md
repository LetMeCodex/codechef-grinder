# [Can You Eat It (COMPCAND)](https://www.codechef.com/problems/COMPCAND)
- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to eat an entire candy of length `N` by taking bites of exactly `K` units each. If it's possible, we should output the minimum number of bites required. If it's not possible to eat the entire candy this way, we should output `-1`.

The constraints state that `N` and `K` are positive integers ($1 \le N, K \le 10^9$), and there are `T` test cases ($1 \le T \le 1000$).

## Intuition & Mathematical Observation

The core of this problem lies in understanding divisibility.

1.  **Goal**: Eat the *entire* candy of length `N`.
2.  **Action**: Each bite consumes exactly `K` units of candy.
3.  **Condition**: If we take `X` bites, the total length of candy eaten will be `X * K`. For us to eat the *entire* candy, this total length must be exactly `N`.
    So, we need to find an integer `X` such that `X * K = N`.

This equation `X * K = N` implies that `N` must be a multiple of `K`. In other words, `N` must be perfectly divisible by `K`.

*   **Case 1: `N` is perfectly divisible by `K`**.
    If `N % K == 0`, it means `N` can be expressed as `X * K` for some integer `X`. The minimum number of bites `X` will simply be `N / K`.

*   **Case 2: `N` is not perfectly divisible by `K`**.
    If `N % K != 0`, it means that after taking as many `K`-unit bites as possible, there will always be a remaining piece of candy with length `N % K`. Since `N % K` will be positive but less than `K`, it's impossible to take another full `K`-unit bite to consume this remainder. Therefore, we cannot eat the *entire* candy using only `K`-unit bites. In this scenario, the answer is `-1`.

*   **Edge Case (from code, not strict constraints)**: The provided code also handles `N == 0`. Although the problem constraints specify $N \ge 1$, if `N` could be `0`, then `0` bites would be needed. The code correctly outputs `0` for `N=0`. However, given $N \ge 1$, this specific `if (N == 0)` check will never be true.

Combining these observations, the solution boils down to a simple check: if `N % K == 0`, output `N / K`; otherwise, output `-1`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a few constant-time operations: reading two integers, a modulo operation, a division operation, and printing an integer. Since each test case takes a constant amount of time, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `K`) regardless of the input values. These variables occupy a constant amount of memory. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers like iostream

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int N, K; // Declare variables for candy length N and bite size K
        cin >> N >> K; // Read N and K for the current testcase

        // The problem constraints state N >= 1, so N=0 case is not strictly needed.
        // However, if N could be 0, 0 bites would be needed.
        if (N == 0) {
            // If candy length is 0, no bites are needed.
            cout << 0 << "\n";
        } else if (N % K == 0) {
            // If N is perfectly divisible by K, we can eat the entire candy.
            // The number of bites will be N / K.
            cout << N / K << "\n";
        } else {
            // If N is not perfectly divisible by K, after taking as many K-unit bites
            // as possible, there will be a remaining piece of candy with length
            // N % K. This remaining piece will be positive but less than K,
            // making it impossible to take another K-unit bite.
            cout << -1 << "\n";
        }
    }

    return 0; // Indicate successful program execution
}
```