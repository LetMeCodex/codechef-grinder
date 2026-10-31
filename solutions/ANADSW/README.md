# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)
- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a given array `A` of `N` integers can be sorted into non-decreasing order using a specific type of swap operation. The allowed swap operation is: two elements `A[i]` and `A[j]` can be swapped if and only if the absolute difference between their indices `|i - j|` is strictly greater than 1. This means we can swap any two elements that are *not* adjacent.

## Intuition & Mathematical Observation

The core of this problem lies in understanding which elements can reach which positions through a series of allowed swaps. If all elements can be moved to their correct sorted positions, then the array can be sorted. This is equivalent to determining if all indices in the array form a single connected component under the allowed swap operation.

Let's analyze the connectivity for different values of `N`:

1.  **`N = 1`**:
    *   An array with a single element is always considered sorted.
    *   No swaps are possible or needed.
    *   **Result: YES**

2.  **`N = 2`**:
    *   The indices are `0` and `1`.
    *   The only possible pair of indices is `(0, 1)`.
    *   The difference `|1 - 0| = 1`.
    *   Since `1` is not strictly greater than `1`, no swaps are allowed.
    *   Therefore, the array can only be sorted if it is already sorted (`A[0] <= A[1]`).
    *   **Result: YES if `A[0] <= A[1]`, else NO.**

3.  **`N = 3`**:
    *   The indices are `0, 1, 2`.
    *   Let's check allowed swaps:
        *   `|1 - 0| = 1` (not allowed)
        *   `|2 - 1| = 1` (not allowed)
        *   `|2 - 0| = 2` (allowed, since `2 > 1`)
    *   This means only `A[0]` and `A[2]` can be swapped. The element `A[1]` is "stuck" in its position and cannot be moved.
    *   For the array to be sortable, `A[1]` must already be the element that belongs in the middle position of the sorted version of the array.
    *   We can check this by sorting a copy of the array and comparing `A[1]` with the middle element of the sorted copy.
    *   **Result: YES if `A[1]` is equal to the middle element of the sorted array, else NO.**

4.  **`N >= 4`**:
    *   This is the general case where all indices become connected.
    *   **Connectivity within same parity indices:**
        *   Consider any two indices `i` and `j` such that `|i - j|` is an even number (e.g., `j = i + 2k`). We can swap `A[i]` with `A[i+2]`, then `A[i+2]` with `A[i+4]`, and so on. This means any element at an even index can be swapped with any other element at an even index. Similarly, any element at an odd index can be swapped with any other element at an odd index.
        *   So, all even-indexed positions form a connected component, and all odd-indexed positions form another connected component.
    *   **Connecting different parity indices:**
        *   To make the entire array sortable, we need to find an allowed swap between an even-indexed position and an odd-indexed position.
        *   Consider indices `0` (even) and `3` (odd). The difference `|3 - 0| = 3`. Since `3 > 1`, `A[0]` and `A[3]` can be swapped.
        *   This single swap `(0, 3)` is sufficient to connect the even-indexed component with the odd-indexed component.
        *   This connection is possible only if index `3` exists, which requires `N` to be at least `4`.
    *   Since all indices are connected for `N >= 4`, any element can be moved to any position. Therefore, the array can always be sorted.
    *   **Result: YES**

Combining these observations, the solution involves a series of `if-else if` statements to handle the small `N` cases specifically, and a general "YES" for `N >= 4`.

## Complexity Analysis

*   **Time Complexity**:
    *   For `N=1, 2, N>=4`, the operations involve reading `N` integers and constant time comparisons/output. This is $O(N)$.
    *   For `N=3`, we read `N` integers, create a copy of size `N`, sort the copy, and perform a comparison. Sorting `N` elements takes $O(N \log N)$. Since `N=3` is a fixed small constant, $O(3 \log 3)$ is effectively $O(1)$.
    *   The dominant factor across all cases for a single test case is reading the input array, which is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   For `N=1, 2, N>=4`, we store the input array `A` of size `N`. This requires $O(N)$ space.
    *   For `N=3`, we store the input array `A` and a copy `B`, both of size `N`. This requires $O(N)$ space.
    *   Thus, the space complexity is $O(N)$ for storing the input array (and its copy for `N=3`).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    if (N == 1) {
        // An array with one element is always sorted.
        std::cout << "YES\n";
    } else if (N == 2) {
        // For N=2, the only possible pair of indices is (0, 1).
        // The condition for swapping is j - i > 1.
        // For (0, 1), j - i = 1, which is not > 1.
        // So, no swaps are possible. The array can be sorted only if it's already sorted.
        if (A[0] <= A[1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else if (N == 3) {
        // For N=3, the only allowed swap is between A[0] and A[2] (j - i = 2 > 1).
        // The element A[1] (at index 1) is fixed and cannot be moved.
        // Therefore, for the array to be sortable, A[1] must already be the middle element
        // of the sorted version of the array.
        std::vector<int> B = A; // Create a copy to sort
        std::sort(B.begin(), B.end()); // Sort the copy
        if (A[1] == B[1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        // For N >= 4, all indices are connected through allowed swaps.
        // 1. All odd indices (1, 3, 5, ...) can swap with each other (e.g., A[k] with A[k+2]).
        // 2. All even indices (0, 2, 4, ...) can swap with each other (e.g., A[k] with A[k+2]).
        // 3. For N >= 4, index 0 (even) can swap with index 3 (odd)
        //    because |3 - 0| = 3 > 1.
        // This connection between an odd-indexed position and an even-indexed position
        // links all positions into a single connected component.
        // In a connected component, any element can be moved to any position,
        // meaning any permutation (including the sorted one) is reachable.
        std::cout << "YES\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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