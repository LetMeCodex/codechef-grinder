# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)
- **Difficulty Rating**: 1197
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to take an array `A` of `N` positive integers and transform it into a permutation of `1` to `N` (i.e., an array containing `1, 2, ..., N` exactly once). The only allowed operation is to decrease an element `A[i]` by `1`. We need to find the minimum total number of operations required. If it's impossible to form such a permutation, we should output `-1`.

## Intuition & Mathematical Observation

The core idea revolves around a greedy strategy combined with sorting.

1.  **Goal and Operations**: We want to transform the given array `A` into `[1, 2, ..., N]` (or any permutation of it) using the minimum number of decrement operations. Since we can only decrease elements, we cannot increase any `A[i]`.

2.  **Sorting is Key**: Consider the sorted version of the input array `A`. Let this sorted array be `A_sorted = [a_1, a_2, ..., a_N]`, where `a_1 \le a_2 \le \dots \le a_N`.
    To minimize operations, we should try to map the smallest elements in `A_sorted` to the smallest target values in the permutation `[1, 2, ..., N]`.
    *   It makes intuitive sense to try to transform `a_1` into `1`.
    *   Then, `a_2` into `2`.
    *   And generally, `a_i` into `i`.

    Why is this greedy assignment optimal?
    Suppose we have `a_i` and `a_j` with `i < j` (so `a_i \le a_j`). We want to assign them target values `x` and `y` from the permutation `[1, ..., N]` such that `x < y`.
    *   Option 1: `a_i \to x`, `a_j \to y`. Operations: `(a_i - x) + (a_j - y)`.
    *   Option 2: `a_i \to y`, `a_j \to x`. Operations: `(a_i - y) + (a_j - x)`.
    Since `a_i \le a_j` and `x < y`, we know that `a_i - x \le a_j - x` and `a_i - y \le a_j - y`.
    Comparing the total operations:
    `(a_i - x) + (a_j - y)` vs `(a_i - y) + (a_j - x)`
    Rearranging: `a_i - x - y + a_j` vs `a_i - y - x + a_j`.
    These are actually equal! This means that swapping the target values `x` and `y` between `a_i` and `a_j` doesn't change the total operations *if both assignments are possible*.

    However, the crucial part is *possibility*. If we assign `a_i` to `y` (where `y > x`), it might require more operations than `a_i` to `x`. More importantly, if `a_i` is assigned to `y`, then `a_j` must be assigned to `x`. But if `a_j` is too large to become `x` (i.e., `a_j > x`), then this assignment is impossible. By assigning `a_i` to `x` (the smallest available target), we maximize the chances for `a_j` to be assigned to `y` (the next smallest available target), as `a_j` is larger than `a_i`. This greedy approach ensures that we are always trying to make the smallest possible changes and checking for impossibility conditions as early as possible.

3.  **Greedy Strategy**:
    *   Sort the array `A` in non-decreasing order.
    *   Initialize `total_operations = 0`.
    *   Iterate `i` from `0` to `N-1` (using 0-indexed array `A` and 1-indexed target values `1, ..., N`):
        *   The target value for `A[i]` is `(i+1)`.
        *   **Impossibility Check**: If `A[i] > (i+1)`, it's impossible to form the permutation. Why?
            If `A[i] > (i+1)`, it means that the first `(i+1)` elements of the sorted array (`A[0], A[1], ..., A[i]`) are all greater than or equal to `A[i]`. Therefore, all these `(i+1)` elements are strictly greater than `(i+1)`.
            These `(i+1)` elements must be mapped to `(i+1)` distinct values in the final permutation. The smallest `(i+1)` distinct values available are `1, 2, ..., (i+1)`.
            However, since `A[j] > (i+1)` for all `j \le i`, none of these `A[j]` can be transformed into any value `v \le (i+1)` (because we can only decrease, so `A[j]` must be at least `v`).
            Thus, if `A[i] > (i+1)`, we cannot assign `(i+1)` distinct values from `1` to `(i+1)` to `A[0], ..., A[i]`. In this case, output `-1`.
        *   **Calculate Operations**: If `A[i] \le (i+1)`, we can transform `A[i]` into `(i+1)`. The number of operations needed for this specific element is `(i+1) - A[i]`. Add this to `total_operations`.

4.  **Final Result**: If the loop completes without encountering an impossibility, `total_operations` will hold the minimum number of operations.

**Example:**
`N = 3`, `A = [4, 1, 2]`

1.  Sort `A`: `A = [1, 2, 4]`
2.  `i = 0`: `A[0] = 1`. Target `(0+1) = 1`. `A[0] \le 1`. Operations: `1 - 1 = 0`. `total_operations = 0`.
3.  `i = 1`: `A[1] = 2`. Target `(1+1) = 2`. `A[1] \le 2`. Operations: `2 - 2 = 0`. `total_operations = 0`.
4.  `i = 2`: `A[2] = 4`. Target `(2+1) = 3`. `A[2] > 3` (4 > 3). Impossible! Output `-1`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `N` and array `A`: $O(N)$
    *   Sorting the array `A`: $O(N \log N)$
    *   Iterating through the sorted array to calculate operations: $O(N)$
    *   The dominant factor is sorting. Therefore, the time complexity for a single test case is $O(N \log N)$.
    *   With `T` test cases, the total time complexity is $O(T \cdot N \log N)$.
    *   Given $N \le 10^5$ and $T \le 10$, this is approximately $10 \cdot 10^5 \cdot \log(10^5) \approx 10^6 \cdot 17 \approx 1.7 \cdot 10^7$ operations, which is well within typical time limits.

*   **Space Complexity**:
    *   Storing the input array `A`: $O(N)$
    *   Other variables (like `N`, `operations`, `possible`, loop counter `i`): $O(1)$
    *   The total space complexity is $O(N)$.
    *   Given $N \le 10^5$, a vector of $10^5$ integers requires about $400$ KB, which is well within typical memory limits.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    std::vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements into the vector
    }

    // Sort the array A in non-decreasing order.
    // This is crucial for the greedy strategy to work.
    std::sort(A.begin(), A.end());

    long long operations = 0; // Variable to store the total number of operations.
                              // Using long long to be safe, as total operations can exceed int max for N=10^5.
                              // Max operations: sum(i+1 - 1) for i=0 to N-1 = sum(i) for i=0 to N-1 = N*(N-1)/2
                              // For N=10^5, this is approx (10^5)^2 / 2 = 5 * 10^9, which requires long long.
    bool possible = true;     // Flag to track if it's possible to form a permutation.

    // Iterate through the sorted array.
    // For each element A[i] (0-indexed), its ideal target value in the permutation
    // is (i+1) (1-indexed).
    for (int i = 0; i < N; ++i) {
        // If the current element A[i] is greater than its ideal target value (i+1),
        // it's impossible to form a permutation.
        // (Refer to the "Intuition & Mathematical Observation" section for details).
        if (A[i] > (i + 1)) {
            possible = false; // Mark as impossible
            break;            // No need to check further
        }
        // If A[i] <= (i+1), we can transform A[i] into (i+1).
        // The number of operations required for this element is (i+1) - A[i].
        operations += ((i + 1) - A[i]);
    }

    // Output the result based on whether it was possible or not.
    if (possible) {
        std::cout << operations << "\n";
    } else {
        std::cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}

```