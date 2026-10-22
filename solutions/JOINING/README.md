# [Joining Date (JOINING)](https://www.codechef.com/problems/JOINING)
- **Difficulty Rating**: 970
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a scenario with `N` candidates, numbered from 1 to `N`. They are scheduled to join a company in batches of 5. Specifically, candidate `i` is scheduled to join on day `ceil(i / 5)`.

Suddenly, candidate `K` (where `1 <= K <= N`) withdraws their offer. This withdrawal has a ripple effect: all candidates with numbers greater than `K` shift up by one position. That is, candidate `i` (where `i > K`) now effectively becomes candidate `i-1`. Candidates `i < K` are unaffected.

The task is to determine the total number of candidates (excluding candidate `K` themselves, as they no longer join) whose joining day changes due to candidate `K`'s withdrawal.

## Intuition & Mathematical Observation

Let's analyze the impact of candidate `K`'s withdrawal:

1.  **Candidates `i < K`**: These candidates are not affected. Their position remains `i`, and thus their joining day `ceil(i / 5)` remains unchanged.
2.  **Candidate `K`**: This candidate withdraws, so they no longer have a joining day. We don't count them in the "changed days" total.
3.  **Candidates `i > K`**: These are the only candidates whose joining day *might* change.
    *   **Original Position**: For a candidate `i` (where `K < i <= N`), their original position was `i`.
    *   **Original Joining Day**: `D_orig(i) = ceil(i / 5)`.
    *   **New Position**: After `K` withdraws, candidate `i` effectively moves to position `i - 1`.
    *   **New Joining Day**: `D_new(i) = ceil((i - 1) / 5)`.

We need to count how many candidates `i` (where `K < i <= N`) satisfy `D_orig(i) != D_new(i)`.
This means we are looking for `i` such that `ceil(i / 5) != ceil((i - 1) / 5)`.

Let's use the property of `ceil(x / M)` in integer arithmetic. For positive integers `x` and `M`, `ceil(x / M)` can be calculated as `(x - 1) / M + 1` using integer division.

Applying this to our joining days:
*   `D_orig(i) = (i - 1) / 5 + 1`
*   `D_new(i) = ((i - 1) - 1) / 5 + 1 = (i - 2) / 5 + 1`

So, a candidate's joining day changes if and only if:
`(i - 1) / 5 + 1 != (i - 2) / 5 + 1`
This simplifies to:
`(i - 1) / 5 != (i - 2) / 5`

Now, consider when `floor(A / B) != floor((A - 1) / B)` holds. This inequality is true if and only if `A` is a multiple of `B`.
In our case, `A = i - 1` and `B = 5`.
Therefore, the joining day changes if and only if `(i - 1)` is a multiple of 5.
This means `(i - 1) % 5 == 0`, which is equivalent to `i % 5 == 1`.

**Conclusion**: A candidate `i` (where `K < i <= N`) has their joining day changed if and only if `i % 5 == 1`.

Our problem now reduces to counting the number of integers `i` such that `K < i <= N` and `i % 5 == 1`.
This is equivalent to counting `i` in the range `[K + 1, N]` that satisfy `i % 5 == 1`.

To count numbers `x` in a range `[1, X]` such that `x % M == R_val`:
The numbers are `R_val, R_val + M, R_val + 2M, ..., R_val + m*M <= X`.
`m*M <= X - R_val`
`m <= (X - R_val) / M`
Since `m` starts from `0`, the number of such values is `floor((X - R_val) / M) + 1`.

For our specific case, `M = 5` and `R_val = 1`.
Let `count_mod_1(X)` be the number of integers `x` in `[1, X]` such that `x % 5 == 1`.
`count_mod_1(X) = floor((X - 1) / 5) + 1`.
Using integer division in C++, this is `(X - 1) / 5 + 1`.

The number of candidates `i` in `(K, N]` (or `[K+1, N]`) such that `i % 5 == 1` is:
`count_mod_1(N) - count_mod_1(K)`
`= ((N - 1) / 5 + 1) - ((K - 1) / 5 + 1)`
`= (N - 1) / 5 - (K - 1) / 5`

This formula directly gives the answer for each test case.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (subtraction, division). These operations take constant time. Since there are `T` test cases, the total time complexity is $O(T)$. Given `T <= 1000`, this is highly efficient.
*   **Space Complexity**: The solution uses a few integer variables to store `N`, `K`, `T`, and the calculated count. This amount of memory is constant and does not depend on the input values `N` or `K`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // For input/output operations

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K; // Read N and K for the current test case

    // The problem states that candidate K turns down their offer.
    // This causes all candidates with numbers greater than K to shift up by one position.
    // Candidate i (where i > K) originally had position i.
    // After K withdraws, candidate i moves to position i-1.

    // The joining day for a candidate at position p is ceil(p / 5).
    // Using integer division, this is (p - 1) / 5 + 1.

    // Original joining day for candidate i: D_orig(i) = (i - 1) / 5 + 1
    // New joining day for candidate i (for i > K): D_new(i) = ((i - 1) - 1) / 5 + 1 = (i - 2) / 5 + 1

    // A candidate's joining day changes if D_orig(i) != D_new(i).
    // This inequality (i - 1) / 5 != (i - 2) / 5 holds if and only if
    // (i - 1) is a multiple of 5.
    // So, candidate i (where i > K) changes their joining day if and only if i-1 is a multiple of 5.
    // This means i must be of the form 5m + 1 for some integer m.
    // We need to count how many such candidates i exist in the range (K, N].
    // This is equivalent to counting i such that K < i <= N and i % 5 == 1.

    // We can count this efficiently using a formula.
    // The number of integers x in the range [1, X] such that x % 5 == 1 is floor((X - 1) / 5) + 1.
    // We want to count i in [K + 1, N] such that i % 5 == 1.
    // This is (count of i in [1, N] with i % 5 == 1) - (count of i in [1, K] with i % 5 == 1).

    // Count of i in [1, N] with i % 5 == 1:
    // The numbers are 1, 6, 11, ..., 5*m + 1 <= N
    // 5*m <= N - 1
    // m <= (N - 1) / 5
    // m ranges from 0 to floor((N - 1) / 5).
    // Number of values for m is floor((N - 1) / 5) + 1.
    int count_up_to_N = (N - 1) / 5 + 1;

    // Count of i in [1, K] with i % 5 == 1:
    // The numbers are 1, 6, 11, ..., 5*m + 1 <= K
    // 5*m <= K - 1
    // m <= (K - 1) / 5
    // m ranges from 0 to floor((K - 1) / 5).
    // Number of values for m is floor((K - 1) / 5) + 1.
    int count_up_to_K = (K - 1) / 5 + 1;

    // The number of candidates i in (K, N] with i % 5 == 1 is:
    // count_up_to_N - count_up_to_K
    // = (floor((N - 1) / 5) + 1) - (floor((K - 1) / 5) + 1)
    // = floor((N - 1) / 5) - floor((K - 1) / 5)
    // Using integer division in C++ for floor:
    int changed_days_count = (N - 1) / 5 - (K - 1) / 5;

    std::cout << changed_days_count << "\n"; // Output the total count for this test case
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from C's stdio and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```