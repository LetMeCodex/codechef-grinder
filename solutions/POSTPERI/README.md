# [Poster Perimeter (POSTPERI)](https://www.codechef.com/problems/POSTPERI)
- **Difficulty Rating**: 812
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible absolute difference between the perimeter of a rectangle and a given target perimeter `K`. We are given constraints on the maximum allowed length `N` and maximum allowed width `M` for the rectangle. Specifically, the length `l` must be an integer such that `1 <= l <= N`, and the width `w` must be an integer such that `1 <= w <= M`. We need to output this minimum absolute difference for each test case.

## Intuition & Mathematical Observation

The perimeter of a rectangle with length `l` and width `w` is given by the formula `P = 2 * (l + w)`.
We are looking to minimize the value `|P - K|`, where `P` is the perimeter of a valid rectangle and `K` is the target perimeter.

Given the constraints on `N` and `M` (both up to 100), the total number of possible integer pairs `(l, w)` is relatively small.
- `l` can range from `1` to `N`.
- `w` can range from `1` to `M`.

Since `N` and `M` are at most 100, the maximum number of `(l, w)` pairs to check is `100 * 100 = 10,000`. For each pair, we calculate the perimeter and its absolute difference from `K`. This suggests a straightforward brute-force approach:

1. Initialize a variable `min_diff` to a very large value (e.g., `numeric_limits<int>::max()`).
2. Iterate `l` from `1` to `N`.
3. Inside this loop, iterate `w` from `1` to `M`.
4. For each `(l, w)` pair:
    a. Calculate `perimeter = 2 * (l + w)`.
    b. Calculate `current_diff = abs(perimeter - K)`.
    c. Update `min_diff = min(min_diff, current_diff)`.
5. After checking all possible `(l, w)` pairs, `min_diff` will hold the smallest absolute difference.

This approach is efficient enough given the problem constraints.

## Complexity Analysis

-   **Time Complexity**:
    -   For each test case, we have two nested loops. The outer loop runs `N` times (for length `l`), and the inner loop runs `M` times (for width `w`).
    -   Inside the innermost part of the loop, we perform constant-time operations (addition, multiplication, `abs`, `min`).
    -   Therefore, for a single test case, the time complexity is `O(N * M)`.
    -   Since there are `T` test cases, the total time complexity is `O(T * N * M)`.
    -   Given `T <= 100`, `N <= 100`, `M <= 100`, the maximum operations would be approximately `100 * 100 * 100 = 10^6`, which is well within typical time limits for competitive programming (usually around `10^8` operations per second).

-   **Space Complexity**:
    -   We only use a few integer variables to store `N`, `M`, `K`, `min_diff`, `l`, `w`, `perimeter`, and `current_diff`.
    -   The amount of memory used does not depend on the input values `N`, `M`, or `K` beyond a constant number of variables.
    -   Thus, the space complexity is `O(1)`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries like iostream, algorithm, limits

// Using namespace std; is common in competitive programming to avoid writing std::
using namespace std; 

// Function to solve a single test case
void solve() {
    int N, M, K;
    // Read the maximum allowed length (N), maximum allowed width (M),
    // and the target perimeter (K) for the current test case.
    cin >> N >> M >> K; 

    // Initialize min_diff to the maximum possible integer value.
    // This ensures that any valid difference found will be smaller.
    int min_diff = numeric_limits<int>::max(); 

    // Iterate through all possible integer lengths 'l' from 1 to N.
    for (int l = 1; l <= N; ++l) {
        // Iterate through all possible integer widths 'w' from 1 to M.
        for (int w = 1; w <= M; ++w) {
            // Calculate the perimeter for the current length and width.
            int perimeter = 2 * (l + w);
            
            // Calculate the absolute difference between the current perimeter and the target K.
            int current_diff = abs(perimeter - K);
            
            // Update min_diff if the current difference is smaller than the smallest found so far.
            min_diff = min(min_diff, current_diff);
        }
    }
    // Output the minimum possible difference for the current test case, followed by a newline.
    cout << min_diff << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL); // Unties cin from cout, preventing flushes

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```