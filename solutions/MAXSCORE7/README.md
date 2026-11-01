# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)
- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible score achievable by performing a sequence of operations on an array initially containing only `0`s and `1`s. In each operation:
1.  Choose two distinct elements, say $A_i$ and $A_j$, from the array.
2.  Remove $A_i$ and $A_j$ from the array.
3.  Add their sum, $A_i + A_j$, back to the array.
4.  If $A_i + A_j = 1$, you gain 1 point. Otherwise (if $A_i + A_j = 0$ or $A_i + A_j = 2$), you gain 0 points.
This process is repeated until only one element remains in the array. We need to maximize the total score.

## Intuition & Mathematical Observation

1.  **Scoring Condition:** A score of 1 is awarded exclusively when the sum of two chosen elements is 1. Given that the initial elements are `0` or `1`, this condition ($A_i + A_j = 1$) can only be met by picking one `0` and one `1`.
    *   `0 + 0 = 0` (0 points)
    *   `1 + 1 = 2` (0 points)
    *   `0 + 1 = 1` (1 point)

2.  **Goal:** To maximize the total score, we must maximize the number of times we perform the `(0, 1)` pairing operation.

3.  **Effect of a `(0, 1)` operation:** When we pick a `0` and a `1`:
    *   One `0` is removed from the array.
    *   One `1` is removed from the array.
    *   Their sum, `0 + 1 = 1`, is added back to the array.
    *   We gain 1 point.

4.  **Key Interpretation (to match the provided solution):** The crucial aspect here is how the `1` that is added back (from `0+1=1`) affects future scoring opportunities. For the solution `min(count0, count1)` to be correct, it implies that this newly added `1` is *not* considered a "fresh" `1` that can be paired with a `0` to score another point. Instead, each `(0,1)` operation effectively consumes one `0` and one `1` from the *initial pool* of elements, permanently reducing the count of available `0`s and `1`s for scoring purposes. Any elements that become `2` (from `1+1`) also cannot contribute to scoring.

5.  **Limiting Factor:** Under this interpretation, each `(0,1)` operation that yields a point consumes one `0` and one `1` from our available counts. Therefore, the maximum number of such operations we can perform is limited by the count of whichever element (`0` or `1`) is scarcer. If we have `count0` zeros and `count1` ones, we can perform at most `min(count0, count1)` such operations.

6.  **Final State:** After performing `min(count0, count1)` operations, we will have exhausted either all `0`s or all `1`s (or both, if `count0 == count1`). At this point, it's impossible to form any more `(0,1)` pairs. Any remaining elements will be of the same type (all `0`s or all `1`s, or potentially `2`s if `1+1` operations were performed). Any subsequent operations will involve `(0,0)`, `(1,1)`, or elements that are `2` or higher, none of which yield 1 point.

7.  **Conclusion:** The maximum score is simply the minimum of the initial count of `0`s and the initial count of `1`s.

The solution involves a single pass through the input array to count the occurrences of `0`s and `1`s, and then printing the minimum of these two counts.

## Complexity Analysis

*   **Time Complexity**: The solution iterates through the input array of size `N` once to count the occurrences of `0`s and `1`s. This takes $O(N)$ time. The `std::min` operation is $O(1)$. For `T` test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**: The solution uses a few integer variables (`n`, `count0`, `count1`, `val`, `t`) to store counts and loop variables. This requires a constant amount of extra space, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard library headers, including iostream and algorithm.

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the array

    int count0 = 0; // Counter for the number of zeros
    int count1 = 0; // Counter for the number of ones

    // Iterate through the array elements to count zeros and ones
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read each element of the array
        if (val == 0) {
            count0++; // If the element is 0, increment count0
        } else {
            count1++; // If the element is 1, increment count1
        }
    }

    // The maximum score is the minimum of the total counts of zeros and ones.
    // This is because each operation that yields a score of 1 consumes one 0 and one 1.
    // We can always perform min(count0, count1) such operations.
    // After these operations, all remaining elements will be identical (either all 0s or all 1s),
    // so any subsequent operations will yield a score of 0.
    std::cout << std::min(count0, count1) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```