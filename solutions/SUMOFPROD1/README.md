# [Sum of Product 1 (SUMOFPROD1)](https://www.codechef.com/problems/SUMOFPROD1)
- **Difficulty Rating**: 1340
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the sum of products `A[i] * A[j]` for all pairs of indices `(i, j)` such that `0 <= i <= j < N`, where `N` is the length of the array `A`. The array `A` contains only `0`s and `1`s.

Since `A[i]` and `A[j]` can only be `0` or `1`, their product `A[i] * A[j]` will be `1` if and only if both `A[i]` and `A[j]` are `1`. Otherwise, the product will be `0`.
Therefore, the problem simplifies to counting the number of pairs `(i, j)` such that `0 <= i <= j < N` and both `A[i] = 1` and `A[j] = 1`. For each such pair, we add `1` to our total sum.

## Intuition & Mathematical Observation

Let's consider a contiguous block of `k` ones in the array. For example, `[..., 0, 1, 1, 1, 0, ...]`, where the `1`s form a block of length `k=3`.
Any pair `(i, j)` where `i` and `j` both fall within this block of `k` ones (and `i <= j`) will contribute `1` to our total sum. We need to count how many such pairs exist within a block of `k` ones.

If we have `k` ones, say at indices `p, p+1, ..., p+k-1`, we are looking for pairs `(i, j)` such that `p <= i <= j <= p+k-1`.
This is a classic combinatorial problem: choosing `2` elements from `k` elements with replacement, where order doesn't matter, or equivalently, choosing `2` elements from `k` elements where the same element can be chosen twice.

Let's list the pairs for a block of `k` ones:
-   Pairs where `i = j`: There are `k` such pairs (e.g., `(p, p), (p+1, p+1), ..., (p+k-1, p+k-1)`).
-   Pairs where `i < j`: These are combinations of `2` distinct elements chosen from `k` elements. The number of ways to choose `2` distinct elements from `k` is given by the binomial coefficient "k choose 2", which is `k * (k-1) / 2`.

Summing these two cases, the total number of pairs `(i, j)` with `i <= j` within a block of `k` ones is:
`k + k * (k-1) / 2`
`= (2k + k^2 - k) / 2`
`= (k^2 + k) / 2`
`= k * (k+1) / 2`

This formula `k * (k+1) / 2` represents the sum of the first `k` natural numbers (1 + 2 + ... + k), which is also the number of ways to choose 2 items from k items with replacement, where order doesn't matter.

The solution strategy is to iterate through the array, keeping track of the `current_ones_count` in the current contiguous block of ones. When we encounter a `0`, it signifies the end of a block of ones. At this point, we calculate the contribution of the just-finished block using the formula `current_ones_count * (current_ones_count + 1) / 2` and add it to our `total_sum`. Then, we reset `current_ones_count` to `0`.
After the loop finishes, if the array ends with a block of ones, `current_ones_count` will be non-zero. We must add the contribution from this final block to `total_sum` one last time.

The `total_sum` can be quite large (for `N=10^5`, if all are ones, `total_sum` is approx `5 * 10^9`), so it must be stored in a `long long` data type.

## Complexity Analysis

-   **Time Complexity**: The solution involves a single pass through the input array `A` of size `N`. For each element, we perform constant-time operations (read, comparison, increment, arithmetic operations). Therefore, for each test case, the time complexity is $O(N)$. Given `T` test cases, the total time complexity is $O(T \cdot N)$.
-   **Space Complexity**: The solution uses a few variables (`N`, `total_sum`, `current_ones_count`, `val`, `T`, loop counter `i`). These variables consume a constant amount of memory regardless of the input array size `N`. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array

    long long total_sum = 0; // Stores the final sum of products, needs long long for large N
    long long current_ones_count = 0; // Stores the count of consecutive 1s in the current block

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read the current element

        if (val == 1) {
            // If the element is 1, increment the count of consecutive 1s
            current_ones_count++;
        } else { // If the element is 0
            // A block of 1s has ended (or was empty).
            // Calculate the sum of products for the just-finished block of 1s.
            // A block of k ones contributes k*(k+1)/2 to the total sum.
            total_sum += current_ones_count * (current_ones_count + 1) / 2;
            // Reset the count for the next potential block of 1s
            current_ones_count = 0;
        }
    }

    // After the loop, if the array ends with 1s, current_ones_count will be non-zero.
    // We need to add the contribution from this final block.
    total_sum += current_ones_count * (current_ones_count + 1) / 2;
    
    // Output the final result for the current test case
    cout << total_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```