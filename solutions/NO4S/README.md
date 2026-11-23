# [No 4 Please (NO4S)](https://www.codechef.com/problems/NO4S)
- **Difficulty Rating**: 993
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of elements to delete from a given array `A` such that the resulting array is "good". An array is considered "good" if there are no two distinct indices `i` and `j` such that `A[i] + A[j] = 4`. The elements `A[i]` are integers, and their values are constrained to be between 1 and 3, inclusive (`1 <= A[i] <= 3`). We need to solve this for multiple test cases.

## Intuition & Mathematical Observation

The core of the problem lies in identifying which pairs of elements sum to 4 and then determining the minimum deletions to eliminate all such pairs. Since the array elements `A[i]` can only be 1, 2, or 3, let's list all possible pairs `(A[i], A[j])` (where `i != j`) that sum to 4:

1.  **`1 + 3 = 4`**: If the array contains at least one `1` and at least one `3`, then any `1` and any `3` will form a forbidden pair. To resolve this conflict, we must eliminate *all* `1`s or *all* `3`s from the array. To minimize the number of deletions, we should choose to delete the type of element that appears fewer times. If `count1` is the number of `1`s and `count3` is the number of `3`s, the minimum deletions for this conflict type will be `min(count1, count3)`.

2.  **`2 + 2 = 4`**: If the array contains two or more `2`s, then any pair of `2`s will form a forbidden pair. To resolve this conflict, we can keep at most *one* element of value `2`. If there are `count2` elements of value `2`:
    *   If `count2` is 0 or 1, no deletions are needed for `2`s, as no pair of `2`s can be formed.
    *   If `count2 > 1`, we must delete `count2 - 1` elements of value `2` to ensure only one `2` (or zero `2`s) remains.
    This can be compactly expressed as `max(0, count2 - 1)` deletions.

3.  **Other pairs**:
    *   `1 + 1 = 2` (not 4)
    *   `1 + 2 = 3` (not 4)
    *   `3 + 3 = 6` (not 4)
    *   `2 + 3 = 5` (not 4)
    These pairs do not sum to 4, so they do not cause any conflicts and do not require any deletions.

Crucially, the conflicts arising from `(1, 3)` pairs and `(2, 2)` pairs are independent. Deleting `1`s or `3`s does not affect the count of `2`s, and deleting `2`s does not affect the count of `1`s or `3`s. Therefore, the total minimum deletions will be the sum of the minimum deletions required for each independent conflict type.

**Algorithm:**
1.  Initialize three counters: `count1`, `count2`, and `count3` to zero.
2.  Iterate through the input array `A` of size `N`. For each element `val`:
    *   If `val == 1`, increment `count1`.
    *   If `val == 2`, increment `count2`.
    *   If `val == 3`, increment `count3`.
3.  Initialize `total_deletions = 0`.
4.  Add deletions for `(1, 3)` conflicts: `total_deletions += min(count1, count3)`.
5.  Add deletions for `(2, 2)` conflicts: `total_deletions += max(0, count2 - 1)`.
6.  Print `total_deletions`.

## Complexity Analysis

*   **Time Complexity**:
    *   The dominant part of the solution is iterating through the input array of size `N` to count the occurrences of 1s, 2s, and 3s. This takes $O(N)$ time.
    *   All other operations (reading `N`, calculating `min` and `max`, printing) take constant time, $O(1)$.
    *   Since this process is repeated for `T` test cases, the total time complexity is $O(T \cdot N)$.
    *   Given `N` up to $10^5$ and `T` up to $10^3$, the maximum operations would be around $10^3 \cdot 10^5 = 10^8$, which is acceptable within typical time limits for competitive programming (usually 1-2 seconds).

*   **Space Complexity**:
    *   We use a few integer variables (`N`, `count1`, `count2`, `count3`, `val`, `deletions`, `T`) to store counts and intermediate results. These variables occupy a constant amount of memory regardless of the input array size.
    *   The input array itself is not stored explicitly; elements are read and processed one by one.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by the problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array

    int count1 = 0; // Count of elements with value 1
    int count2 = 0; // Count of elements with value 2
    int count3 = 0; // Count of elements with value 3

    // Read array elements and count their occurrences
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 1) {
            count1++;
        } else if (val == 2) {
            count2++;
        } else { // val must be 3, as per constraints 1 <= A_i <= 3
            count3++;
        }
    }

    int deletions = 0;

    // Condition for a "good" array: no two elements from different indices sum to 4.
    // The possible values for A_i are 1, 2, 3.
    // Let's analyze pairs that sum to 4:
    // 1. (1, 3): If both 1s and 3s are present in the array, any 1 and any 3 will sum to 4.
    //    To resolve this conflict, we must eliminate all 1s or all 3s.
    //    To minimize deletions, we choose to delete the group with fewer elements.
    //    The number of deletions for this conflict is min(count1, count3).
    deletions += min(count1, count3);

    // 2. (2, 2): If there are two or more 2s in the array, any pair of them will sum to 4.
    //    To resolve this conflict, we can keep at most one element of value 2.
    //    If count2 is 0 or 1, no deletions are needed for 2s.
    //    If count2 > 1, we must delete (count2 - 1) elements of value 2.
    //    The number of deletions for this conflict is max(0, count2 - 1).
    deletions += max(0, count2 - 1);

    // Output the total minimum deletions
    cout << deletions << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```