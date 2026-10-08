# [Zero String (ZEROSTRING)](https://www.codechef.com/problems/ZEROSTRING)
- **Difficulty Rating**: 1042
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to transform a given binary string `S` of length `N` into a string consisting entirely of '0's. We have two types of operations, each costing 1:

1.  **Delete a '1'**: Remove any '1' from the string.
2.  **Flip the entire string**: All '0's become '1's, and all '1's become '0's.

## Intuition & Mathematical Observation

Let's denote the number of '1's in the initial string `S` as `count_1` and the number of '0's as `count_0`. We know that `count_0 = N - count_1`.

We need to achieve a state where the string contains only '0's. Let's consider the possible strategies:

**Strategy 1: Only use deletion operations.**
If we choose to only delete '1's, we must delete every '1' present in the string. Each deletion costs 1 operation.
Therefore, the total cost for this strategy is simply `count_1`.

**Strategy 2: Use one flip operation, then deletion operations.**
What if we decide to perform a single flip operation?
1.  **Perform the flip**: This costs 1 operation.
    After the flip, the string changes:
    *   All original `count_0` '0's become '1's.
    *   All original `count_1` '1's become '0's.
    Now, the string effectively contains `count_0` '1's and `count_1` '0's.
2.  **Delete remaining '1's**: To make the string all '0's, we must delete all the '1's that resulted from the flip. The number of '1's to delete is `count_0`. Each deletion costs 1 operation.
    So, deleting these '1's costs `count_0` operations.

The total cost for this strategy is `1` (for the flip) + `count_0` (for deletions).
Since `count_0 = N - count_1`, this cost can be written as `1 + (N - count_1)`.

**Comparing the strategies:**
The minimum number of operations will be the minimum of the costs calculated from these two strategies.
So, the answer is `min(count_1, 1 + (N - count_1))`.

**Edge Case:**
If the string `S` already consists of all '0's (i.e., `count_1 = 0`), then no operations are needed.
Our formula `min(0, 1 + (N - 0))` simplifies to `min(0, 1 + N)`, which correctly evaluates to `0`. So, the formula naturally handles this edge case. The provided solution code explicitly checks for `count_1 == 0` and prints `0`, which is also a valid approach.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `S`: $O(N)$
    *   Counting `count_1`: Iterating through the string `S` once takes $O(N)$ time.
    *   Calculating `count_0` and the minimum: $O(1)$
    *   For `T` test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**:
    *   Storing the input string `S`: $O(N)$
    *   Other variables (`n`, `count_1`, `count_0`, etc.): $O(1)$
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std; 

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the binary string

    int count_1 = 0;
    // Count the number of '1's in the string
    for (char c : s) {
        if (c == '1') {
            count_1++;
        }
    }

    // If there are no '1's, the string already consists of all '0's.
    // No operations are needed.
    if (count_1 == 0) {
        cout << 0 << "\n";
        return; // Done with this test case
    }

    // Strategy 1: Achieve the goal by only deleting '1's.
    // Each '1' must be deleted. Each deletion costs 1 operation.
    // So, the total cost for this strategy is simply the number of '1's.
    int cost_only_deletions = count_1;

    // Strategy 2: Achieve the goal by performing one flip operation,
    // and then deleting the '1's that result from the flip.
    //
    // Step 1: Perform a flip operation. This costs 1 operation.
    // After flipping, all original '0's become '1's, and all original '1's become '0's.
    //
    // Step 2: Delete the new '1's.
    // The number of original '0's is (n - count_1).
    // These original '0's are now '1's after the flip.
    // We need to delete all of them. This costs (n - count_1) operations.
    //
    // Total cost for this strategy: 1 (for flip) + (n - count_1) (for deletions).
    int count_0 = n - count_1;
    int cost_flip_then_delete = 1 + count_0;

    // The minimum number of operations is the minimum of the costs of these two strategies.
    cout << min(cost_only_deletions, cost_flip_then_delete) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```