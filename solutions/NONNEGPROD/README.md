# [Non-Negative Product (NONNEGPROD)](https://www.codechef.com/problems/NONNEGPROD)
- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of elements that need to be removed from a given array `A` such that the product of the remaining elements is non-negative. A non-negative product means the product is either positive or zero.

## Intuition & Mathematical Observation

The product of a set of numbers can be non-negative in two scenarios:
1.  **The product is zero.** This occurs if and only if at least one of the numbers in the set is zero.
2.  **The product is positive.** This occurs if none of the numbers in the set are zero, and the count of negative numbers in the set is even.

Let's analyze these conditions to determine the minimum removals:

*   **Case 1: The array contains at least one zero.**
    If the original array `A` contains a zero, we can simply keep all elements. The product of all elements will be zero (because any product involving zero is zero), which is a non-negative value. In this scenario, no removals are needed. The minimum removals required is `0`.

*   **Case 2: The array does not contain any zeros.**
    In this case, the product of any subset of elements will never be zero. Therefore, we must aim for a positive product. The sign of the product depends solely on the count of negative numbers:
    *   **If the count of negative numbers is even:** The product of all elements will be positive. Since a positive value is non-negative, no removals are needed. The minimum removals required is `0`.
    *   **If the count of negative numbers is odd:** The product of all elements will be negative. To make the product positive, we need to change its sign. The most efficient way to do this with minimum removals is to remove just one negative number. This will reduce the count of negative numbers by one, making it even, and thus making the overall product positive. The minimum removals required is `1`.

Combining these observations, the strategy is:
1.  Iterate through the array to count negative numbers (`neg_count`) and check if any zero is present (`has_zero`).
2.  If `has_zero` is true, output `0`.
3.  Else (no zeros in the array):
    *   If `neg_count` is even, output `0`.
    *   If `neg_count` is odd, output `1`.

This covers all possibilities and ensures we find the minimum number of removals.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    The solution involves a single pass through the input array of size `N` to count negative numbers and check for zeros. This operation takes linear time. Since this is done for `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few constant extra variables (`N`, `neg_count`, `has_zero`, `A_i`) regardless of the input array size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream for input/output

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of elements in the array

    int neg_count = 0; // Counter for negative numbers
    bool has_zero = false; // Flag to check if any zero is present

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the current element

        if (A_i < 0) {
            neg_count++; // Increment count if the element is negative
        } else if (A_i == 0) {
            has_zero = true; // Set flag if the element is zero
        }
    }

    // Determine the minimum removals based on the collected information
    if (has_zero) {
        // If there's any zero, the product will be 0, which is non-negative.
        // No removals needed.
        cout << 0 << "\n";
    } else {
        // If there are no zeros, the product's sign depends on neg_count.
        if (neg_count % 2 == 0) {
            // Even number of negative numbers means the product is positive.
            // No removals needed.
            cout << 0 << "\n";
        } else {
            // Odd number of negative numbers means the product is negative.
            // To make it non-negative (positive), we must remove one negative number.
            // This is the minimum removal required.
            cout << 1 << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```