# [Balls and Boxes (BALLBOX)](https://www.codechef.com/problems/BALLBOX)
- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible to distribute `N` balls into `K` boxes such such that each box contains a *distinct positive* number of balls. We need to output "YES" if it's possible, and "NO" otherwise.

## Intuition & Mathematical Observation

To determine if it's possible to distribute `N` balls into `K` boxes with distinct positive counts, we should consider the *minimum* number of balls required to satisfy this condition. If the total number of balls `N` is greater than or equal to this minimum required sum, then it is possible. Otherwise, it is not.

To minimize the sum of balls across `K` boxes, while ensuring each box has a distinct positive number of balls, we should assign the smallest possible distinct positive integers to the boxes. These integers are `1, 2, 3, ..., K`.

The sum of the first `K` positive integers is given by the arithmetic series formula:
$S_K = 1 + 2 + 3 + \dots + K = \frac{K \times (K + 1)}{2}$

So, the minimum number of balls required is $\frac{K \times (K + 1)}{2}$.

If `N` (the total balls available) is greater than or equal to this minimum sum, then it's possible to distribute the balls. Any excess balls (`N - S_K`) can be added to one or more boxes (e.g., by adding all of them to the box with `K` balls, making it `K + (N - S_K)` balls, while still maintaining distinctness and positivity for all boxes).

Therefore, the condition for possibility is:
$N \ge \frac{K \times (K + 1)}{2}$

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, we perform a constant number of arithmetic operations (multiplication, addition, division) and a comparison. Reading `N` and `K` also takes constant time. Given `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$.
    We only use a few integer variables to store `N`, `K`, `min_sum_required`, and `T`. This requires a constant amount of memory regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    cin >> N >> K; // Read the number of balls (N) and boxes (K)

    // Calculate the minimum sum of balls required to satisfy the conditions.
    // To have K distinct positive integers, the smallest possible sum is 1 + 2 + ... + K.
    // This sum is given by the formula K * (K + 1) / 2.
    // We cast K to long long before multiplication to prevent potential integer overflow
    // if K*(K+1) were to exceed the maximum value of an int.
    // For K <= 10^4, K*(K+1) is at most 10^4 * 10^4 = 10^8, which fits in a 32-bit int.
    // However, using long long for min_sum_required is a good practice for sums
    // and ensures safety if K were larger, or if N (up to 10^9) was compared against a larger sum.
    long long min_sum_required = (long long)K * (K + 1) / 2;

    // If the total number of balls N is greater than or equal to the minimum required sum,
    // then it is possible to divide the balls as per the conditions.
    // Otherwise, it is not possible.
    if (N >= min_sum_required) {
        cout << "YES\n"; // Output YES if possible
    } else {
        cout << "NO\n";  // Output NO if not possible
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio library.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```