# Pseudo Sorted Array (PSEUDOSORT)
- **Difficulty Rating**: 1067
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if an array can be made sorted in non-decreasing order by performing at most one swap of adjacent elements.

## Intuition & Mathematical Observation
A sorted array has the property that for all $i$ from $0$ to $n-2$, $a[i] \le a[i+1]$. If an array is already sorted, it satisfies the condition.

If an array is not sorted, it must contain at least one "inversion" where $a[i] > a[i+1]$ for some $i$. The problem allows us to perform at most one swap of adjacent elements. This means we can fix at most one such inversion.

Consider the implications of performing one adjacent swap. If we swap $a[i]$ and $a[i+1]$ where $a[i] > a[i+1]$, we are essentially trying to resolve this specific inversion. For the array to become sorted after this single swap, two conditions must be met:

1.  **Only one adjacent inversion exists:** If there are two or more adjacent inversions (i.e., $a[i] > a[i+1]$ and $a[j] > a[j+1]$ for $i \neq j$), a single adjacent swap cannot fix both. For example, if we have `[3, 1, 2]`, there's an inversion at index 0 (`3 > 1`). Swapping `3` and `1` gives `[1, 3, 2]`. Now there's an inversion at index 1 (`3 > 2`). A single swap cannot fix both.

2.  **The swap resolves the inversion and maintains order elsewhere:** If there is exactly one adjacent inversion at index $i$ (i.e., $a[i] > a[i+1]$ and for all $j \neq i$, $a[j] \le a[j+1]$), we can swap $a[i]$ and $a[i+1]$. After the swap, the new array will have $a[i+1]$ at index $i$ and $a[i]$ at index $i+1$. For the array to be sorted, we need to ensure that this swap doesn't create new inversions with the elements immediately surrounding the swapped pair:
    *   The element before the swapped pair (if it exists), $a[i-1]$, must be less than or equal to the new element at index $i$ (which was originally $a[i+1]$). So, $a[i-1] \le a[i+1]$.
    *   The new element at index $i+1$ (which was originally $a[i]$) must be less than or equal to the element after the swapped pair (if it exists), $a[i+2]$. So, $a[i] \le a[i+2]$.

Therefore, the strategy is to iterate through the array and count the number of adjacent inversions.
*   If the count is 0, the array is already sorted, and the answer is "YES".
*   If the count is greater than 1, we cannot sort it with one adjacent swap, and the answer is "NO".
*   If the count is exactly 1, let the inversion be at index $i$ ($a[i] > a[i+1]$). We then check the two conditions mentioned above:
    *   If $i > 0$, check if $a[i-1] \le a[i+1]$.
    *   If $i+1 < n-1$, check if $a[i] \le a[i+2]$.
    If both these conditions hold (or if the boundary elements don't exist), then one swap is sufficient, and the answer is "YES". Otherwise, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We iterate through the array once to count inversions and perform checks.
- **Space Complexity**: $O(1)$ (excluding the input array storage). We only use a few variables to keep track of the inversion count and index.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Checks if an array can be made sorted by performing at most one adjacent swap.
 * 
 * An array is pseudo-sorted if it is already sorted or can be sorted by swapping
 * exactly one pair of adjacent elements.
 * 
 * @param a The input vector of integers.
 * @return true if the array is pseudo-sorted, false otherwise.
 */
bool is_pseudo_sorted(const std::vector<int>& a) {
    int n = a.size();
    int inversion_index = -1; // Stores the index of the first element of an adjacent inversion
    int inversion_count = 0;  // Counts the number of adjacent inversions

    // Iterate through the array to find adjacent inversions
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            inversion_count++;
            if (inversion_count > 1) {
                // If more than one adjacent inversion is found, it cannot be sorted
                // with a single adjacent swap.
                return false; 
            }
            inversion_index = i; // Record the index of the inversion
        }
    }

    // Case 1: No inversions found. The array is already sorted.
    if (inversion_count == 0) {
        return true; 
    }

    // Case 2: Exactly one adjacent inversion found at inversion_index.
    // We need to check if swapping a[inversion_index] and a[inversion_index+1]
    // results in a sorted array. This requires checking the elements
    // adjacent to the swapped pair.

    // Condition 1: Check the element before the swapped pair (if it exists).
    // The element at inversion_index - 1 must be less than or equal to the
    // element that will be moved to inversion_index (which is a[inversion_index + 1]).
    if (inversion_index > 0) {
        if (a[inversion_index - 1] > a[inversion_index + 1]) {
            return false; // Swapping would create an inversion with the preceding element.
        }
    }

    // Condition 2: Check the element after the swapped pair (if it exists).
    // The element that will be moved to inversion_index + 1 (which is a[inversion_index])
    // must be less than or equal to the element at inversion_index + 2.
    if (inversion_index + 1 < n - 1) {
        if (a[inversion_index] > a[inversion_index + 2]) {
            return false; // Swapping would create an inversion with the succeeding element.
        }
    }

    // If we have exactly one inversion and the checks for adjacent elements pass,
    // then swapping the single inversion pair will sort the array.
    return true;
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Size of the array
        std::cin >> n;
        std::vector<int> a(n); // The input array
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        
        // Call the helper function to check if the array is pseudo-sorted
        if (is_pseudo_sorted(a)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}
```