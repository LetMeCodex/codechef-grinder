# [Range Minimize (MNR)](https://www.codechef.com/problems/MNR)
- **Difficulty Rating**: 949
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we can perform an operation of deleting at most two elements from the array. The goal is to minimize the difference between the maximum and minimum elements in the remaining array.

## Intuition & Mathematical Observation
The problem asks us to minimize the range (maximum - minimum) of an array after deleting at most two elements. The key insight is that to minimize the range, we should always consider deleting elements that are either the smallest or the largest in the array. This is because the range is determined by the extreme values.

Let the given array be $A$. If we sort the array $A$ in non-decreasing order, say $a_0, a_1, \dots, a_{n-1}$, then the minimum element is $a_0$ and the maximum element is $a_{n-1}$. The initial range is $a_{n-1} - a_0$.

We are allowed to delete at most two elements. This means we can delete 0, 1, or 2 elements.

Let's analyze the possible scenarios after sorting:

1.  **Delete 0 elements:**
    The remaining array is the original sorted array. The range is $a_{n-1} - a_0$.

2.  **Delete 1 element:**
    *   If we delete the smallest element ($a_0$), the new minimum is $a_1$ and the maximum remains $a_{n-1}$. The range is $a_{n-1} - a_1$.
    *   If we delete the largest element ($a_{n-1}$), the minimum remains $a_0$ and the new maximum is $a_{n-2}$. The range is $a_{n-2} - a_0$.
    We should choose the deletion that results in a smaller range, so we consider $\min(a_{n-1} - a_1, a_{n-2} - a_0)$.

3.  **Delete 2 elements:**
    There are a few strategic ways to delete two elements to minimize the range:
    *   **Delete the two smallest elements:** Delete $a_0$ and $a_1$. The new minimum is $a_2$ and the maximum is $a_{n-1}$. The range is $a_{n-1} - a_2$.
    *   **Delete the two largest elements:** Delete $a_{n-1}$ and $a_{n-2}$. The minimum is $a_0$ and the new maximum is $a_{n-3}$. The range is $a_{n-3} - a_0$.
    *   **Delete one smallest and one largest element:** Delete $a_0$ and $a_{n-1}$. The new minimum is $a_1$ and the new maximum is $a_{n-2}$. The range is $a_{n-2} - a_1$.

    We need to consider the minimum among these three possibilities: $\min(a_{n-1} - a_2, a_{n-3} - a_0, a_{n-2} - a_1)$.

Since $N \ge 3$ is guaranteed by the problem constraints (implicitly, as we need at least 3 elements to consider deleting 2 and still have elements left), all the indices used in the above cases ($0, 1, 2, n-3, n-2, n-1$) will be valid.

The overall minimum range will be the minimum of the ranges calculated from all these valid scenarios (deleting 0, 1, or 2 elements).

Therefore, the strategy is:
1. Sort the array $A$.
2. Calculate the range for each of the following scenarios:
    *   No deletions: $a_{n-1} - a_0$
    *   Delete $a_0$: $a_{n-1} - a_1$
    *   Delete $a_{n-1}$: $a_{n-2} - a_0$
    *   Delete $a_0, a_1$: $a_{n-1} - a_2$
    *   Delete $a_{n-2}, a_{n-1}$: $a_{n-3} - a_0$
    *   Delete $a_0, a_{n-1}$: $a_{n-2} - a_1$
3. The answer is the minimum of these calculated ranges.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$
    The dominant operation is sorting the array, which takes $O(N \log N)$ time. The subsequent calculations to find the minimum range take constant time, $O(1)$, as they involve a fixed number of comparisons and subtractions on array elements.

- **Space Complexity**: $O(N)$ or $O(1)$
    If we consider the space used by the input array, it's $O(N)$. If we are allowed to modify the input array in-place for sorting, then the auxiliary space complexity is $O(1)$ (or $O(\log N)$ or $O(N)$ depending on the sorting algorithm's implementation, e.g., `std::sort` might use introsort which has $O(\log N)$ auxiliary space on average). If a copy of the array is made, it would be $O(N)$. In this solution, `std::vector` is used, and `std::sort` is applied in-place, so the auxiliary space is typically $O(\log N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For LLONG_MAX

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Size of the array
        std::cin >> n;
        std::vector<long long> a(n); // Array to store input numbers
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // Sort the array in non-decreasing order.
        // This is crucial because the minimum and maximum elements will be at the ends.
        std::sort(a.begin(), a.end());

        // We can delete at most two elements.
        // The goal is to minimize max(A) - min(A).
        // After sorting, the minimum element is a[0] and the maximum is a[n-1].
        // To minimize the range, we should try to remove elements that are
        // either very small or very large.

        // Initialize min_range to a very large value.
        long long min_range = LLONG_MAX;

        // Case 1: Delete 0 elements.
        // The range is the difference between the largest and smallest elements.
        min_range = std::min(min_range, a[n - 1] - a[0]);

        // Case 2: Delete 1 element.
        // Option 2a: Delete the smallest element (a[0]).
        // The new range is from a[1] to a[n-1].
        min_range = std::min(min_range, a[n - 1] - a[1]);
        // Option 2b: Delete the largest element (a[n-1]).
        // The new range is from a[0] to a[n-2].
        min_range = std::min(min_range, a[n - 2] - a[0]);

        // Case 3: Delete 2 elements.
        // Option 3a: Delete the two smallest elements (a[0] and a[1]).
        // The new range is from a[2] to a[n-1].
        min_range = std::min(min_range, a[n - 1] - a[2]);
        // Option 3b: Delete the two largest elements (a[n-2] and a[n-1]).
        // The new range is from a[0] to a[n-3].
        min_range = std::min(min_range, a[n - 3] - a[0]);
        // Option 3c: Delete one smallest (a[0]) and one largest (a[n-1]) element.
        // The new range is from a[1] to a[n-2].
        min_range = std::min(min_range, a[n - 2] - a[1]);

        // Print the minimum possible range found.
        std::cout << min_range << "\n";
    }
    return 0;
}
```