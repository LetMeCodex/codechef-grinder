# [Easy Subarray Sum (P3149)](https://www.codechef.com/problems/P3149)
- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make the maximum subarray sum of a given array `A` equal to the sum of all positive elements in the *original* array `A`. An operation consists of changing any element `A[i]` to `0`.

## Intuition & Mathematical Observation

Let $S_{pos}$ be the sum of all positive elements in the original array `A`. The problem's goal is to modify the array `A` using minimum operations such that its maximum subarray sum becomes exactly $S_{pos}$.

We can analyze this problem by considering two main cases:

**Case 1: The array `A` contains no positive numbers.**
If all elements in `A` are non-positive (i.e., negative or zero), then $S_{pos} = 0$.
In an array consisting only of non-positive numbers, the maximum subarray sum is `0`. This can be achieved by choosing an empty subarray, or if the array contains `0`s, by choosing a subarray consisting only of `0`s.
Since the target maximum subarray sum ($S_{pos}$) is `0`, and the current maximum subarray sum is already `0`, no operations are needed. The answer for this case is `0`.

**Case 2: The array `A` contains at least one positive number.**
If there's at least one positive number, then $S_{pos} > 0$.
To achieve a maximum subarray sum of $S_{pos}$, we *must* ensure that our chosen subarray includes *all* positive numbers from the original array. If we exclude any positive number, the sum of the subarray will be less than $S_{pos}$.

Let's identify the range of indices that encompasses all positive numbers:
-   Let `first_pos` be the index of the first positive element in `A`.
-   Let `last_pos` be the index of the last positive element in `A`.
Any subarray that includes all positive numbers must necessarily span at least from `first_pos` to `last_pos`. The smallest such subarray is `A[first_pos ... last_pos]`.

Now, consider the elements within this critical range `A[first_pos ... last_pos]`:
1.  **Positive elements `A[i] > 0`**: These elements are essential for achieving $S_{pos}$. They contribute positively to the sum and must be kept as they are.
2.  **Zero elements `A[i] == 0`**: These elements contribute neutrally to the sum. They do not need to be changed.
3.  **Negative elements `A[i] < 0`**: If we include these negative elements in our subarray `A[first_pos ... last_pos]`, they will *reduce* the total sum, making it less than $S_{pos}$. To ensure the sum equals $S_{pos}$, these negative elements *must* be changed to `0`. Each such change counts as one operation.

What about elements *outside* the range `A[first_pos ... last_pos]`?
-   By definition of `first_pos` and `last_pos`, there are no positive elements outside this range.
-   Any negative elements `A[i] < 0` outside this range (i.e., `i < first_pos` or `i > last_pos`) do not need to be changed. We simply choose our optimal subarray to be `A[first_pos ... last_pos]` (after modifying its negative elements to `0`). Including these outside negative elements would only decrease the sum, so we exclude them from our chosen subarray.

Therefore, the optimal strategy is:
1.  Iterate through the array to find the index of the first positive element (`first_pos`) and the last positive element (`last_pos`).
2.  If no positive elements are found (`first_pos == -1`), the answer is `0`.
3.  Otherwise, initialize an `operations` counter to `0`. Iterate from `first_pos` to `last_pos` (inclusive). For every element `A[i]` in this range that is strictly negative (`A[i] < 0`), increment the `operations` counter.
4.  The final value of `operations` is the minimum number of changes required.

This approach ensures that all positive numbers are included in the target subarray, and any negative numbers that would otherwise reduce the sum are neutralized, leading to the maximum possible sum of $S_{pos}$ with minimum operations.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading the input `n` and `t` takes $O(1)$ time.
    -   The solution processes `t` test cases.
    -   For each test case:
        -   Reading `n` elements and simultaneously finding `first_pos` and `last_pos` involves a single pass through the array, taking $O(N)$ time.
        -   Counting operations involves another pass, iterating from `first_pos` to `last_pos`. In the worst case (when `first_pos` is 0 and `last_pos` is `n-1`), this also takes $O(N)$ time.
    -   Thus, for each test case, the time complexity is $O(N)$.
    -   The total time complexity across all test cases is $O(T \cdot N)$.

-   **Space Complexity**:
    -   A `std::vector<int> a(n)` is used to store the array elements, which requires $O(N)$ space.
    -   All other variables (`n`, `first_pos`, `last_pos`, `operations`, `t`, loop counters) use a constant amount of space, $O(1)$.
    -   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the array

    std::vector<int> a(n); // Declare a vector to store array elements
    int first_pos = -1;    // Initialize index of the first positive element (0-indexed)
    int last_pos = -1;     // Initialize index of the last positive element (0-indexed)

    // Read array elements and find first_pos and last_pos
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > 0) {
            if (first_pos == -1) {
                first_pos = i; // Found the first positive element
            }
            last_pos = i; // Update last_pos with the current positive element's index
        }
    }

    // Case 1: No positive numbers in the array
    // If all elements are non-positive, the maximum subarray sum is 0 (achieved by an empty subarray).
    // The target sum (sum of all positive numbers) is also 0.
    // No operations are needed to achieve this.
    if (first_pos == -1) {
        std::cout << 0 << "\n";
    } else {
        // Case 2: There is at least one positive number
        // The maximum possible subarray sum we want to achieve is the sum of all positive numbers in the original array.
        // To achieve this sum, we must form a subarray that includes all original positive numbers.
        // This subarray must span from the first positive number to the last positive number (inclusive).
        // Any negative numbers within this range must be changed to 0 to contribute neutrally to the sum.
        // Numbers outside this range (before first_pos or after last_pos) that are negative
        // do not need to be changed, as including them would reduce the sum, and excluding them
        // (by making the subarray start at first_pos and end at last_pos) is optimal.
        
        int operations = 0;
        // Iterate through the subarray from first_pos to last_pos (inclusive)
        for (int i = first_pos; i <= last_pos; ++i) {
            if (a[i] < 0) {
                // If an element is strictly negative, it must be changed to 0
                // to ensure the sum of the subarray containing all positive elements
                // equals the maximum possible sum (sum of all positive elements).
                operations++;
            }
        }
        std::cout << operations << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```