# [Chef And Babla (BAB_I)](https://www.codechef.com/problems/BAB_I)
- **Difficulty Rating**: 1346
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the largest non-negative integer `X` such that for all given integers `A_i` in a list, `A_i` is *not* contained within the closed interval `[-X, X]`. If no such `X` exists, we should output `-1`.

## Intuition & Mathematical Observation

Let's first understand the condition: "A_i is not in the range `[-X, X]`".
This means that for every `A_i`, one of the following must be true:
1. `A_i < -X`
2. `A_i > X`

Both of these conditions can be combined into a single absolute value inequality: `|A_i| > X`.
So, the problem boils down to finding the largest non-negative integer `X` such that `|A_i| > X` for *all* `A_i` in the input list.

Let `min_abs_val` be the minimum of the absolute values of all elements in the input list:
`min_abs_val = min(|A_1|, |A_2|, ..., |A_N|)`

For `X` to be strictly less than `|A_i|` for *all* `i`, it must be strictly less than the *smallest* of these absolute values. Therefore, the condition becomes:
`X < min_abs_val`

Now, we need to find the *largest non-negative integer* `X` that satisfies `X < min_abs_val`.

Let's consider two cases:

1.  **Case 1: One or more `A_i` values are 0.**
    If any `A_i` is 0, then `|A_i| = |0| = 0`. In this situation, `min_abs_val` will be 0.
    The condition `X < min_abs_val` becomes `X < 0`.
    However, the problem states that `X` must be a *non-negative integer*. There is no non-negative integer `X` that is strictly less than 0.
    Therefore, if any `A_i` is 0, no such `X` exists, and we should output `-1`.

2.  **Case 2: No `A_i` values are 0.**
    If no `A_i` is 0, then all `A_i` are non-zero. This implies that `|A_i| >= 1` for all `i`.
    Consequently, `min_abs_val` will be at least 1 (since it's the minimum of values that are all `>= 1`).
    We need the largest non-negative integer `X` such that `X < min_abs_val`.
    If `min_abs_val` is, for example, 5, then `X < 5`. The largest integer `X` satisfying this is 4.
    In general, if `min_abs_val` is `K` (where `K >= 1`), the largest integer `X` satisfying `X < K` is `K - 1`.
    Since `min_abs_val >= 1`, `min_abs_val - 1` will always be a non-negative integer.
    So, in this case, the answer is `min_abs_val - 1`.

**Algorithm:**
1.  Initialize `min_abs_val` to a very large value (e.g., `LLONG_MAX` to ensure any `|A_i|` will be smaller).
2.  Initialize a boolean flag `found_zero` to `false`.
3.  Iterate through each element `A_i` in the input list:
    a.  Read `A_i`.
    b.  If `A_i` is 0, set `found_zero = true`.
    c.  Update `min_abs_val = min(min_abs_val, abs(A_i))`.
4.  After iterating through all elements:
    a.  If `found_zero` is `true`, print `-1`.
    b.  Else (if no zero was found), print `min_abs_val - 1`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    For each test case, we iterate through the `N` elements of the input array exactly once. Inside the loop, operations like reading an integer, checking for zero, calculating absolute value, and finding the minimum are all constant time operations. Therefore, the time complexity for processing one test case is linear with respect to `N`.
    Given `T` test cases, the total time complexity will be $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few variables (`N`, `min_abs_val`, `found_zero`, `A_i`, `T`) to store input and intermediate results. These variables consume a constant amount of memory, irrespective of the input size `N`. We do not store the entire input array.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <algorithm> // For std::min
#include <cmath>    // For std::abs (specifically for long long)
#include <climits>  // For LLONG_MAX

// It's good practice to put the solution logic for a single test case in a function.
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    long long min_abs_val = LLONG_MAX; // Initialize with the largest possible long long value
                                       // This ensures any abs(A_i) will be smaller.

    bool found_zero = false; // Flag to track if any element is 0

    for (int i = 0; i < N; ++i) {
        long long A_i;
        std::cin >> A_i; // Read each element

        if (A_i == 0) {
            found_zero = true; // If 0 is found, set the flag
        }
        // Update min_abs_val with the minimum of its current value and the absolute value of A_i
        min_abs_val = std::min(min_abs_val, std::abs(A_i));
    }

    if (found_zero) {
        // If any element was 0, no such X exists because 0 is always in [-X, X] for X >= 0.
        std::cout << -1 << "\n";
    } else {
        // If no zero was found, min_abs_val will be at least 1 (since all A_i are non-zero).
        // The condition is |A_i| > X for all i, which means X < |A_i| for all i.
        // This implies X < min(|A_i|).
        // Since X must be an integer, the maximum integer X satisfying X < min(|A_i|) is min(|A_i|) - 1.
        // This value is guaranteed to be non-negative because min_abs_val >= 1.
        std::cout << min_abs_val - 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```