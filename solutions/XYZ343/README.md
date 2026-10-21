# [Savings Account (XYZ343)](https://www.codechef.com/problems/XYZ343)
- **Difficulty Rating**: 720
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `X` income sources, and each source generates `Y` rupees per month. His savings account has a monthly limit of `Z` rupees. If his total income exceeds `Z`, he must reduce some of his income sources to bring the total income within the limit. Chef wants to keep as many income sources as possible. The task is to determine the minimum number of income sources Chef must reduce.

## Intuition & Mathematical Observation

The core of the problem lies in finding the maximum number of income sources Chef can keep while adhering to the account limit and his initial number of sources.

1.  **Total Income Calculation**: If Chef decides to keep `k` income sources, his total monthly income will be `k * Y` rupees.

2.  **Account Limit Constraint**: This total income must not exceed the account limit `Z`. So, we must satisfy the condition:
    `k * Y <= Z`

3.  **Maximum Sources by Limit**: From the inequality `k * Y <= Z`, we can derive the maximum possible integer value for `k`:
    `k <= Z / Y`
    Since `k` must be an integer (representing a count of sources), the maximum number of sources Chef can keep based *solely* on the account limit is `floor(Z / Y)`. In C++ integer division for positive numbers, `Z / Y` automatically computes the floor value. Let's call this `max_sources_by_limit`.

4.  **Initial Sources Constraint**: Chef initially has `X` income sources. He cannot keep more sources than he initially possesses. Therefore, the number of sources he keeps (`k`) also cannot exceed `X`.

5.  **Actual Sources to Keep**: Combining both constraints, the actual number of sources Chef can keep is the minimum of:
    *   His initial number of sources (`X`).
    *   The maximum number of sources allowed by the account limit (`max_sources_by_limit`).
    So, `sources_to_keep = min(X, max_sources_by_limit)`.

6.  **Sources to Reduce**: The problem asks for the minimum number of sources Chef must *reduce*. This is simply the difference between his initial number of sources and the number of sources he decides to keep:
    `sources_to_reduce = X - sources_to_keep`.

This logic directly leads to the solution.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of constant-time operations: reading three integers, one division, one `min` operation, one subtraction, and printing one integer. These operations do not depend on the magnitude of `X`, `Y`, or `Z`. Therefore, the time taken per test case is constant, $O(1)$. The total time complexity is $T$ times this constant time, resulting in $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `X`, `Y`, `Z`, `max_sources_by_limit`, `sources_to_keep`, `sources_to_reduce`) to store input and intermediate results. The amount of memory used by these variables is constant and does not depend on the input values or the number of test cases. Hence, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream and algorithm
using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int X, Y, Z;
        cin >> X >> Y >> Z; // Read X, Y, Z for the current test case

        // Calculate the maximum number of income sources Chef can keep
        // without exceeding the account limit Z.
        // If Chef keeps 'k' sources, his total income is k * Y.
        // This must satisfy k * Y <= Z, which implies k <= Z / Y.
        // Since 'k' must be an integer, the maximum 'k' is floor(Z / Y).
        // Integer division in C++ (for positive numbers) automatically computes floor.
        int max_sources_by_limit = Z / Y;

        // Chef initially has X income sources. He cannot keep more than X sources.
        // So, the actual number of sources Chef will keep is the minimum of:
        // 1. The initial number of sources he has (X).
        // 2. The maximum number of sources allowed by the account limit (max_sources_by_limit).
        int sources_to_keep = min(X, max_sources_by_limit);

        // The number of sources Chef needs to reduce is the difference between
        // his initial number of sources and the number of sources he decides to keep.
        int sources_to_reduce = X - sources_to_keep;

        cout << sources_to_reduce << "\n"; // Output the result for the current test case
    }

    return 0; // Indicate successful execution
}
```