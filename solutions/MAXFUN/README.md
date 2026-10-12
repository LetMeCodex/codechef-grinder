# [Maximise Function (MAXFUN)](https://www.codechef.com/problems/MAXFUN)
- **Difficulty Rating**: 1301
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible value of the expression `|A_x - A_y| + |A_y - A_z| + |A_z - A_x|` for a given array `A` of `N` integers. The indices `x, y, z` must be distinct, and `N` is guaranteed to be at least 3.

## Intuition & Mathematical Observation

The core of this problem lies in simplifying the given expression `|A_x - A_y| + |A_y - A_z| + |A_z - A_x|`. Let's consider any three distinct numbers `a, b, c` from the array `A`.

Without loss of generality, let's assume `a <= b <= c`. Then the absolute differences can be written as:
- `|a - b| = b - a` (since `a <= b`)
- `|b - c| = c - b` (since `b <= c`)
- `|c - a| = c - a` (since `a <= c`)

Now, let's sum these up:
`(b - a) + (c - b) + (c - a)`
`= b - a + c - b + c - a`
`= (b - b) + (c + c) + (-a - a)`
`= 0 + 2c - 2a`
`= 2 * (c - a)`

In this specific ordering (`a <= b <= c`), `a` is the minimum of the three numbers and `c` is the maximum. So, we can generalize this observation: for any three numbers `a, b, c`, the expression `|a - b| + |b - c| + |c - a|` is always equal to `2 * (max(a, b, c) - min(a, b, c))`.

To maximize `2 * (max(A_x, A_y, A_z) - min(A_x, A_y, A_z))`, we need to:
1. Maximize `max(A_x, A_y, A_z)`.
2. Minimize `min(A_x, A_y, A_z)`.

This implies that we should choose `A_x, A_y, A_z` such that one of them is the overall maximum element in the entire array `A`, and another is the overall minimum element in the entire array `A`.
Let `min_overall` be the minimum element in the entire array `A`, and `max_overall` be the maximum element in the entire array `A`.

Since `N >= 3`, we can always pick three distinct indices. We can choose `A_x` to be `max_overall` and `A_y` to be `min_overall`. For `A_z`, we can pick any other element from the array (which is guaranteed to exist because `N >= 3`).
When we pick `max_overall`, `min_overall`, and any third element `A_k`, the minimum of these three chosen elements will be `min_overall`, and the maximum of these three will be `max_overall`.

Therefore, the maximum possible value of the expression is `2 * (max_overall - min_overall)`.

The algorithm is straightforward:
1. Read the number of elements `N`.
2. Iterate through the array `A` to find its minimum element (`min_val`) and maximum element (`max_val`).
3. The result is `2 * (max_val - min_val)`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    We iterate through the `N` elements of the array once to find the minimum and maximum values. All other operations (reading `N`, calculating the result, printing) take constant time. If there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    We only need to store a few variables (`N`, `min_val`, `max_val`, `current_A`, `result`). We do not need to store the entire array `A` in memory.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, climits, etc. for convenience

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the number of elements

    long long min_val, max_val; // Variables to store the minimum and maximum values found

    // Read the first element and initialize min_val and max_val with it.
    // This is safe because N >= 3, so there's always at least one element.
    long long first_A;
    cin >> first_A;
    min_val = first_A;
    max_val = first_A;

    // Iterate through the remaining N-1 elements
    for (int i = 1; i < n; ++i) {
        long long current_A;
        cin >> current_A; // Read the current element
        
        // Update min_val and max_val using std::min and std::max
        min_val = min(min_val, current_A);
        max_val = max(max_val, current_A);
    }

    // The problem asks to maximize |Ax-Ay| + |Ay-Az| + |Az-Ax|.
    // For any three numbers a, b, c, this expression is equivalent to
    // 2 * (max(a,b,c) - min(a,b,c)).
    // To maximize this, we need to pick three numbers from the sequence A
    // such that their maximum is as large as possible and their minimum is as small as possible.
    // This means we should pick the overall maximum element from A (max_val)
    // and the overall minimum element from A (min_val).
    // Since N >= 3, we can always pick a third distinct element.
    // The minimum of these three chosen elements will be min_val, and the maximum will be max_val.
    // Thus, the maximum possible value of the expression is 2 * (max_val - min_val).
    long long result = 2 * (max_val - min_val);
    
    cout << result << "\n"; // Print the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```