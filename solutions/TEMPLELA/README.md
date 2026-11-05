# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given strip of land, represented by a sequence of `N` integer heights, can be used to build a "temple". A strip of land qualifies as a temple land if it satisfies four specific conditions:

1.  **Odd Length**: The strip must have an odd number of parts (`N` must be odd).
2.  **Starting Height**: The height of the first part (`h[0]`) must be `1`.
3.  **Increasing Heights**: From the first part up to the center part, the height of each subsequent part must increase by exactly `1` compared to the previous part.
4.  **Decreasing Heights**: From the center part up to the last part, the height of each subsequent part must decrease by exactly `1` compared to the previous part.

We are given `S` test cases, and for each test case, we need to read `N` and the `N` heights, then output "yes" if it's a temple land, and "no" otherwise.

**Example Temple Land Patterns:**
*   `N=1`: `[1]`
*   `N=3`: `[1, 2, 1]`
*   `N=5`: `[1, 2, 3, 2, 1]`
*   `N=7`: `[1, 2, 3, 4, 3, 2, 1]`

## Intuition & Mathematical Observation

The problem conditions are very explicit, making the solution straightforward: we simply need to check each condition in order. If any condition is violated, the strip is immediately invalid, and we can stop checking further.

Let's break down the checks:

1.  **Check for Odd Length**: The first and most fundamental condition is that `N` must be odd. If `N % 2 == 0`, it's not a temple land.
2.  **Calculate Center Index**: If `N` is odd, there's a unique center element. Its 0-indexed position will be `(N - 1) / 2`. For example, if `N=5`, `center_idx = (5-1)/2 = 2`.
3.  **Check Starting Height**: The height of the first part `h[0]` must be `1`. If `h[0] != 1`, it's not a temple land.
4.  **Check Increasing Sequence**: We iterate from the second element (`i = 1`) up to the `center_idx`. For each `i`, we must ensure `h[i] == h[i-1] + 1`. If this condition fails for any `i`, it's not a temple land.
5.  **Check Decreasing Sequence**: We then iterate from the element *after* the center (`i = center_idx + 1`) up to the last element (`N - 1`). For each `i`, we must ensure `h[i] == h[i-1] - 1`. If this condition fails for any `i`, it's not a temple land.

If all these checks pass, then the strip is a valid temple land. We use a boolean flag (e.g., `is_valid`) to track the validity throughout these checks.

## Complexity Analysis

Let `N` be the number of parts in a strip and `S` be the number of test cases.

*   **Time Complexity**: $O(N)$ per test case.
    *   Reading `N` heights takes $O(N)$ time.
    *   Checking `N % 2` and `h[0]` takes $O(1)$ time.
    *   The loop for increasing heights runs approximately `N/2` times (from index 1 to `(N-1)/2`). This takes $O(N)$ time.
    *   The loop for decreasing heights runs approximately `N/2` times (from index `(N-1)/2 + 1` to `N-1`). This also takes $O(N)$ time.
    *   Since these operations are sequential, the total time for one test case is dominated by $O(N)$.
    *   For `S` test cases, the total time complexity is $O(S \cdot N_{max})$, where $N_{max}$ is the maximum possible value of `N`.

*   **Space Complexity**: $O(N)$ per test case.
    *   We use a `std::vector<int> h` to store the `N` heights, which requires $O(N)$ space.
    *   All other variables (like `n`, `is_valid`, `center_idx`, loop counters) use a constant amount of space, $O(1)$.
    *   Thus, the total space complexity for one test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector

// Using namespace std; is common practice in competitive programming.
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the strip
    vector<int> h(n); // Create a vector to store heights
    for (int i = 0; i < n; ++i) {
        cin >> h[i]; // Read heights into the vector
    }

    bool is_valid = true; // Flag to track if the strip is valid

    // Condition 1: The strip must have an odd number of parts to have a unique center.
    if (n % 2 == 0) {
        is_valid = false;
    }

    // Proceed with other checks only if the strip length is valid so far
    if (is_valid) {
        int center_idx = (n - 1) / 2; // Calculate the 0-indexed center position

        // Condition 2: The first height must be 1.
        if (h[0] != 1) {
            is_valid = false;
        }

        // Condition 3: Heights must increase by exactly 1 from the start to the center.
        // Loop from the second element (index 1) up to the center_idx (inclusive).
        if (is_valid) {
            for (int i = 1; i <= center_idx; ++i) {
                if (h[i] != h[i-1] + 1) {
                    is_valid = false;
                    break; // No need to check further if a condition is violated
                }
            }
        }

        // Condition 4: Heights must decrease by exactly 1 from the center to the end.
        // Loop from the element after the center (center_idx + 1) up to the last element (n-1).
        if (is_valid) {
            for (int i = center_idx + 1; i < n; ++i) {
                if (h[i] != h[i-1] - 1) {
                    is_valid = false;
                    break; // No need to check further if a condition is violated
                }
            }
        }
    }

    // Output the result for the current strip
    if (is_valid) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s; // Read the number of strips (test cases)
    while (s--) { // Loop through each test case
        solve(); // Call the solve function for each strip
    }

    return 0; // Indicate successful execution
}
```