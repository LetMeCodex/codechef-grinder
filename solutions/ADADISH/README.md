# [Ada and Dishes (ADADISH)](https://www.codechef.com/problems/ADADISH)
- **Difficulty Rating**: 1237
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum time required to cook `N` dishes using two burners. Each dish `i` has a cooking time `C_i`. We can cook dishes on the two burners in parallel. If multiple dishes are assigned to the same burner, they must be cooked sequentially on that burner. The total time taken is the maximum of the total cooking times on the two burners. We need to assign dishes to burners such that this maximum time is minimized. The number of dishes `N` is very small, up to 4.

## Intuition & Mathematical Observation

The core idea is to distribute the `N` dishes between two burners such that the total cooking time on the busier burner is minimized. This is a classic optimization problem, a variation of the Partition Problem. Since `N` is extremely small (1 to 4), we can analyze each case or use a brute-force approach for the general case.

Let `C` be the array of cooking times for the `N` dishes.

1.  **Case N = 1**:
    If there's only one dish, it goes on one burner, and the other burner remains idle.
    The total time is simply `C[0]`.

2.  **Case N = 2**:
    With two dishes, `C[0]` and `C[1]`, we can put `C[0]` on burner 1 and `C[1]` on burner 2. They cook in parallel.
    The total time is `max(C[0], C[1])`.

3.  **Case N = 3**:
    Let's sort the dish times in ascending order: `c[0] <= c[1] <= c[2]`.
    To minimize the maximum time, we want to balance the load.
    The largest dish, `c[2]`, must go on one burner (say, burner 1).
    Now we have `c[0]` and `c[1]` remaining.
    If we put `c[1]` on burner 2, and then `c[0]` on burner 2 after `c[1]` finishes, the total time for burner 2 would be `c[1] + c[0]`.
    Burner 1 takes `c[2]` time.
    The total time for this configuration is `max(c[2], c[0] + c[1])`.
    This strategy is optimal because `c[2]` is the bottleneck if it's very large, otherwise `c[0]+c[1]` is the bottleneck. By putting `c[0]` and `c[1]` together on the second burner, we ensure that the smaller dishes contribute to the load of the less busy burner.

4.  **Case N = 4**:
    For `N=4`, we need to partition the four dishes into two sets, `S1` and `S2`, corresponding to the dishes assigned to burner 1 and burner 2, respectively. The total time for burner 1 will be `sum(S1)` and for burner 2 will be `sum(S2)`. We want to minimize `max(sum(S1), sum(S2))`.

    Since `N` is very small, we can brute-force all possible partitions. There are $2^N$ ways to assign `N` items to two categories (burner 1 or burner 2). Each assignment can be represented by a bitmask of length `N`.
    *   A bitmask `i` from `0` to `2^N - 1` can represent an assignment.
    *   If the `j`-th bit of `i` is 0, dish `j` is assigned to burner 1.
    *   If the `j`-th bit of `i` is 1, dish `j` is assigned to burner 2.

    We iterate through all such masks:
    1.  For each mask, calculate `sum1` (total time for dishes assigned to burner 1) and `sum2` (total time for dishes assigned to burner 2).
    2.  Calculate `current_max_sum = max(sum1, sum2)`.
    3.  Keep track of the minimum `current_max_sum` found across all masks.

    **Optimization for N=4 (and general N):**
    The partition `{S1, S2}` is equivalent to `{S2, S1}`. To avoid redundant calculations, we can fix one dish (e.g., `C[0]`) to always be on burner 1. Then, we only need to decide the assignment for the remaining `N-1` dishes. This reduces the number of masks to iterate through from `2^N` to `2^(N-1)`.
    For `N=4`, this means iterating `2^(4-1) = 2^3 = 8` times, which is very efficient.

    The provided code implements this optimized bitmask approach for `N=4`. It initializes `sum1` with `c[0]` and then iterates through `j` from `1` to `N-1`. The `(j-1)`-th bit of the mask `i` determines if `c[j]` goes to `sum1` or `sum2`.

## Complexity Analysis

-   **Time Complexity**:
    *   For `N=1, 2, 3`: The operations involve a few comparisons, additions, and potentially a sort for `N=3`. Sorting 3 elements is constant time. Thus, these cases are `O(1)`.
    *   For `N=4`: The code iterates `2^(N-1)` times (which is `2^3 = 8` for `N=4`). Inside the loop, it iterates `N-1` times to assign dishes and calculate sums. This results in `O((N-1) * 2^(N-1))` operations. Since `N` is a small constant (4), this is effectively `O(1)`.
    *   Overall, for `T` test cases, the total time complexity is `T * O(1)`.

-   **Space Complexity**:
    *   The solution uses a `std::vector<int> c` to store the dish cooking times. This requires `O(N)` space.
    *   Since `N` is at most 4, this is `O(1)` space.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath> // Not strictly needed for max, but often included for math functions

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    if (n == 1) {
        return c[0];
    }
    if (n == 2) {
        return max(c[0], c[1]);
    }
    if (n == 3) {
        sort(c.begin(), c.end()); // Sort to easily identify smallest, middle, largest
        // Optimal strategy for N=3:
        // Put the largest dish (c[2]) on burner 1.
        // Put the second largest dish (c[1]) on burner 2.
        // When c[1] finishes, put the smallest dish (c[0]) on burner 2.
        // Total time = max(time on burner 1, time on burner 2)
        //            = max(c[2], c[1] + c[0])
        return max(c[2], c[0] + c[1]);
    }

    // For N=4, we use a bitmask approach to explore all partitions.
    // We want to partition the N dishes into two sets (for burner 1 and burner 2)
    // such that the maximum of the sums of times in each set is minimized.

    int min_max_sum = -1; // Initialize with an invalid value or a very large number

    // Iterate through all possible subsets of dishes for burner 1.
    // The remaining dishes go to burner 2.
    // There are 2^N subsets. To avoid duplicate partitions (e.g., {A,B} on B1, {C,D} on B2
    // is the same as {C,D} on B1, {A,B} on B2), we fix dish c[0] to always be on burner 1.
    // Then we iterate through assignments for the remaining N-1 dishes.
    // This means iterating from 0 to 2^(N-1) - 1.
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        long long sum1 = 0;
        long long sum2 = 0;

        // Dish 0 is always assigned to burner 1 (as per the optimization)
        sum1 += c[0];

        // Assign remaining dishes (from c[1] to c[N-1]) based on the bitmask 'i'
        for (int j = 1; j < n; ++j) {
            // Check the (j-1)-th bit of 'i'
            // If bit is set (1), assign dish c[j] to burner 2
            // If bit is not set (0), assign dish c[j] to burner 1
            if ((i >> (j - 1)) & 1) { 
                sum2 += c[j];
            } else { 
                sum1 += c[j];
            }
        }
        
        int current_max_sum = max(sum1, sum2);
        if (min_max_sum == -1 || current_max_sum < min_max_sum) {
            min_max_sum = current_max_sum;
        }
    }

    return min_max_sum;
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        cout << solve() << "\n"; // Call solve() for each test case and print result
    }

    return 0;
}
```