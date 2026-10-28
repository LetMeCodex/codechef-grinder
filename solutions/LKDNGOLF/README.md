# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)
- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a golf course with tiles numbered from `0` to `N+1`. There are two ways a golf ball can be hit:

1.  **From tile 0**: The ball lands on tiles `0, k, 2k, 3k, ...` (i.e., multiples of `k`).
2.  **From tile N+1**: The ball lands on tiles `N+1, N+1-k, N+1-2k, ...` (i.e., `N+1` minus multiples of `k`).

Given `N`, `x` (the tile number of the hole), and `k`, we need to determine if a hole at tile `x` can be reached by *either* of these two methods. We should output "YES" if it can be reached, and "NO" otherwise.

## Intuition & Mathematical Observation

Let's analyze the conditions for reaching tile `x` for each type of shot:

1.  **Ball hit from tile 0**:
    The ball lands on tiles `0, k, 2k, 3k, ...`. For the ball to land on tile `x`, `x` must be a non-negative multiple of `k`.
    Mathematically, this means `x % k == 0`.
    Since `x` is always within the range `0` to `N+1`, we don't need to explicitly check `x >= 0`.

2.  **Ball hit from tile N+1**:
    The ball lands on tiles `N+1, N+1-k, N+1-2k, ...`. For the ball to land on tile `x`, the distance from `N+1` to `x` must be a non-negative multiple of `k`.
    The distance is `(N+1) - x`.
    Mathematically, this means `(N+1 - x) % k == 0`.
    Again, `x` is within the valid range, so `(N+1 - x)` will be non-negative.

The problem asks if the hole at `x` can be reached by *either* method. Therefore, we need to check if at least one of these two conditions is true.

**Combined Condition:**
The hole at `x` can be reached if `(x % k == 0)` OR `((N + 1 - x) % k == 0)`.

The solution simply implements this logical check for each test case.

## Complexity Analysis

-   **Time Complexity**: For each test case, we perform a few arithmetic operations (subtraction, modulo) and comparisons. These operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity is $O(T)$. Given `T` up to $10^5$, this is highly efficient.

-   **Space Complexity**: We only use a few variables (`T`, `N`, `x`, `k`, `found`) to store input and intermediate results. The amount of memory used does not depend on the input size `N` or `k`. Thus, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Using the standard namespace to avoid prefixing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N, x, k; // Declare N, x, k as long long to handle values up to 10^9 safely
        cin >> N >> x >> k; // Read N, x, and k for the current test case

        bool found = false; // Flag to track if the hole is found

        // Check for the forward journey:
        // The ball starts at tile 0 and lands on tiles 0, k, 2k, ...
        // If x is a multiple of k, the ball lands on tile x.
        if (x % k == 0) {
            found = true;
        }

        // If the hole was not found in the forward journey, check the backward journey.
        // The ball starts at tile N+1 and lands on tiles (N+1), (N+1-k), (N+1-2k), ...
        // If (N+1 - x) is a multiple of k, the ball lands on tile x.
        // (N+1 - x) represents the distance from N+1 to x, which must be a multiple of k.
        if (!found) { 
            if ((N + 1 - x) % k == 0) {
                found = true;
            }
        }

        // Output "YES" if the hole was found in either journey, otherwise "NO".
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution
}

```