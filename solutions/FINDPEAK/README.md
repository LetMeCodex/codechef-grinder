# [Find Peak Element (FINDPEAK)](https://www.codechef.com/problems/FINDPEAK)
- **Difficulty Rating**: 1250
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to find and return the index of *any* peak element in a given integer array `nums`.

A peak element is defined as an element `nums[i]` such that it is strictly greater than its neighbors. That is, `nums[i] > nums[i-1]` and `nums[i] > nums[i+1]`.

For elements at the boundaries:
- For `nums[0]`, its left neighbor `nums[-1]` is considered to be `-infinity`. Thus, `nums[0]` is always greater than its left neighbor.
- For `nums[N-1]`, its right neighbor `nums[N]` is considered to be `-infinity`. Thus, `nums[N-1]` is always greater than its right neighbor.

The problem guarantees that a peak element always exists in the array. The array `nums` will have at least one element (`N >= 1`).

## Intuition & Mathematical Observation

The key insight for this problem, especially given the "find *any* peak" requirement and the typical constraints for a 1250-rated problem, is to use **binary search**. The guarantee that a peak always exists is crucial for this approach.

Let's consider an element `nums[mid]` during a binary search:

1.  **Base Case (N=1)**: If the array has only one element, `nums[0]`, it is trivially a peak (greater than `-infinity` on both sides). Its index `0` is the answer.

2.  **General Case (N > 1)**:
    *   **Check if `nums[mid]` is a peak**:
        *   We need to compare `nums[mid]` with `nums[mid-1]` and `nums[mid+1]`.
        *   **Boundary `mid = 0`**: `nums[0]` is always greater than its left neighbor (`-infinity`). So, we only need to check `nums[0] > nums[1]`. If true, `0` is a peak.
        *   **Boundary `mid = N-1`**: `nums[N-1]` is always greater than its right neighbor (`-infinity`). So, we only need to check `nums[N-1] > nums[N-2]`. If true, `N-1` is a peak.
        *   **General `0 < mid < N-1`**: `nums[mid]` is a peak if `nums[mid] > nums[mid-1]` AND `nums[mid] > nums[mid+1]`. If this condition holds, we return `mid`.

    *   **If `nums[mid]` is NOT a peak, where to search?**
        *   **Case 1: `nums[mid] < nums[mid-1]` (Decreasing slope to the left)**:
            This means we are on a downward slope if we look left from `mid`. Since `nums[0]` is always greater than its left neighbor (`-infinity`), and we are currently at `mid` where `nums[mid] < nums[mid-1]`, there *must* be a peak somewhere to the left of `mid` (including `mid-1`). Imagine starting at `nums[0]` and moving right. If you never find a peak, the array must be strictly increasing until `mid-1`, and then `nums[mid-1]` is greater than `nums[mid]`. So, a peak must exist in the range `[low, mid-1]`. We update `high = mid - 1`.
        *   **Case 2: `nums[mid] < nums[mid+1]` (Increasing slope to the right)**:
            This means we are on an upward slope if we look right from `mid`. Since `nums[N-1]` is always greater than its right neighbor (`-infinity`), and we are currently at `mid` where `nums[mid] < nums[mid+1]`, there *must* be a peak somewhere to the right of `mid` (including `mid+1`). Imagine starting at `nums[N-1]` and moving left. If you never find a peak, the array must be strictly decreasing until `mid+1`, and then `nums[mid+1]` is greater than `nums[mid]`. So, a peak must exist in the range `[mid+1, high]`. We update `low = mid + 1`.
        *   **Note**: The `else if (!is_greater_than_left)` condition in the code covers `nums[mid] < nums[mid-1]`. The final `else` block covers the scenario where `is_greater_than_left` is true (i.e., `nums[mid] > nums[mid-1]`) but `is_greater_than_right` is false (i.e., `nums[mid] < nums[mid+1]`). This perfectly aligns with the two cases described above for narrowing the search space.

This binary search strategy efficiently narrows down the search space until a peak element is found. Since a peak is guaranteed to exist, the loop will always terminate by returning an index.

## Complexity Analysis

-   **Time Complexity**: $O(\log N)$
    The algorithm employs binary search. In each iteration, the search space (defined by `low` and `high`) is approximately halved. For an array of size `N`, this logarithmic reduction in search space leads to a time complexity of $O(\log N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space for variables like `N`, `low`, `high`, `mid`, `is_greater_than_left`, and `is_greater_than_right`. It does not use any auxiliary data structures whose size depends on the input array `N`.

## Solution Code

```cpp
#include <vector>   // Required for std::vector

// The problem statement implies that the function findPeakElement should be provided.
// CodeChef often wraps such functions in a class named 'Solution'.
// The compilation errors indicate this is the expected structure.
class Solution {
public:
    // Function to find the index of a peak element
    int findPeakElement(const std::vector<int>& nums) {
        int N = nums.size();
        
        // Edge case: If there's only one element, it's always a peak.
        // Based on problem constraints (N >= 1), this is a valid scenario.
        if (N == 1) {
            return 0;
        }

        int low = 0;
        int high = N - 1;

        // Binary search for a peak element.
        // The loop condition low <= high ensures that the search space is valid
        // and covers all possible indices.
        while (low <= high) {
            // Calculate mid to prevent potential integer overflow for large low/high values.
            int mid = low + (high - low) / 2;

            // Determine if nums[mid] is strictly greater than its left neighbor.
            // If mid is 0, its left neighbor is considered -infinity, so nums[0] is always greater.
            bool is_greater_than_left;
            if (mid == 0) {
                is_greater_than_left = true;
            } else {
                is_greater_than_left = (nums[mid] > nums[mid - 1]);
            }

            // Determine if nums[mid] is strictly greater than its right neighbor.
            // If mid is N-1, its right neighbor is considered -infinity, so nums[N-1] is always greater.
            bool is_greater_than_right;
            if (mid == N - 1) {
                is_greater_than_right = true;
            } else {
                is_greater_than_right = (nums[mid] > nums[mid + 1]);
            }

            // If both conditions are true, nums[mid] is a peak element.
            if (is_greater_than_left && is_greater_than_right) {
                return mid;
            } 
            // If nums[mid] is not greater than its left neighbor, it means nums[mid] < nums[mid-1]
            // (since mid=0 case makes is_greater_than_left true).
            // This implies we are on a decreasing slope. A peak must exist to the left of mid
            // (including mid-1, which is now the largest element in the left segment).
            // So, we discard mid and search in the left half.
            else if (!is_greater_than_left) {
                high = mid - 1;
            } 
            // If nums[mid] is greater than its left neighbor but not its right neighbor,
            // it means nums[mid] > nums[mid-1] AND nums[mid] < nums[mid+1]
            // (since mid=N-1 case makes is_greater_than_right true).
            // This implies we are on an increasing slope. A peak must exist to the right of mid
            // (including mid+1, which is now the largest element in the right segment).
            // So, we discard mid and search in the right half.
            else { // !is_greater_than_right
                low = mid + 1;
            }
        }
        
        // A peak element is guaranteed to exist based on the problem constraints and boundary conditions.
        // Therefore, this line should theoretically never be reached.
        // It's good practice to have a return statement for all paths, even if unreachable.
        return -1; 
    }
};

// The main function and fast I/O setup are typically provided by the CodeChef platform
// when submitting a class-based solution. Therefore, it should not be included in your submission.
```