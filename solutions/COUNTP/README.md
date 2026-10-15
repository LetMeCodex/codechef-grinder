# [Counting Problem (COUNTP)](https://www.codechef.com/problems/COUNTP)
- **Difficulty Rating**: 1065
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to partition a given array `A` of `N` integers into two non-empty subsequences, `S1` and `S2`, such that the product of their sums, `sum(S1) * sum(S2)`, is an odd number.

## Intuition & Mathematical Observation

Let's break down the conditions required for `sum(S1) * sum(S2)` to be odd:

1.  **Product of two integers is odd**: The product of two integers is odd if and only if *both* integers are odd.
    Therefore, for `sum(S1) * sum(S2)` to be odd, we must have:
    *   `sum(S1)` is odd
    *   `sum(S2)` is odd

2.  **Sum of integers is odd**: A sum of integers is odd if and only if it contains an *odd number of odd integers*.
    *   If a sum contains an even number of odd integers (e.g., `1+3=4`, `1+3+5+7=16`), the sum is even.
    *   If a sum contains an odd number of odd integers (e.g., `1+2=3`, `1+3+5=9`), the sum is odd.
    *   Even numbers do not affect the parity of the sum (adding an even number to an odd sum keeps it odd; adding an even number to an even sum keeps it even).

Combining these observations:

*   For `sum(S1)` to be odd, `S1` must contain an odd number of odd integers. Let this count be `odd_in_S1`.
*   For `sum(S2)` to be odd, `S2` must contain an odd number of odd integers. Let this count be `odd_in_S2`.

Let `total_odd_count` be the total number of odd integers in the original array `A`. Since `S1` and `S2` form a partition of `A`, we have `total_odd_count = odd_in_S1 + odd_in_S2`.

From our requirements, `odd_in_S1` must be odd, and `odd_in_S2` must be odd.
*   If we sum two odd numbers (`odd + odd`), the result is always an **even** number.
*   Therefore, `total_odd_count` must be an **even** number.

Additionally, for `odd_in_S1` and `odd_in_S2` to both be odd, the smallest possible value for each is 1.
*   So, `odd_in_S1 >= 1` and `odd_in_S2 >= 1`.
*   This implies `total_odd_count = odd_in_S1 + odd_in_S2 >= 1 + 1 = 2`.

**Conclusion:**
For a valid partition to exist, the `total_odd_count` in the array `A` must satisfy two conditions:
1.  `total_odd_count` must be an **even** number.
2.  `total_odd_count` must be **greater than 0** (specifically, `>= 2`).

If these conditions are met, can we always form such a partition? Yes.
Suppose `total_odd_count` is even and `>= 2`.
*   We can place one odd number into `S1`.
*   We can place the remaining `total_odd_count - 1` odd numbers into `S2`. Since `total_odd_count` is even and `>= 2`, `total_odd_count - 1` will be an odd number and `>= 1`.
*   All even numbers from the original array `A` can be distributed arbitrarily (e.g., all placed into `S1`).
*   This construction ensures `S1` has an odd number of odd elements (1), and `S2` has an odd number of odd elements (`total_odd_count - 1`).
*   Both `S1` and `S2` will be non-empty because they each contain at least one odd number.
*   Thus, `sum(S1)` will be odd, `sum(S2)` will be odd, and their product `sum(S1) * sum(S2)` will be odd.

**Summary of conditions:**
*   If `total_odd_count == 0`: All numbers are even. Any sum will be even. Product will be even. `NO`.
*   If `total_odd_count` is odd: Impossible to split an odd number of odd elements into two odd counts (odd + odd = even). `NO`.
*   If `total_odd_count` is even AND `total_odd_count > 0` (i.e., `>= 2`): `YES`.

The solution involves simply counting the number of odd integers in the input array and checking this condition.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ for each test case. We iterate through the array once to count the odd numbers. If there are $T$ test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**: $O(1)$ auxiliary space. We only use a few integer variables to store `N`, `count_odd`, and the current element `A_i`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace for convenience, as is common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int count_odd = 0; // Initialize a counter for odd numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element of the array
        if (A_i % 2 != 0) { // Check if the element is odd
            count_odd++;    // Increment the counter if it's odd
        }
    }

    // The product of two integers sum(S1) * sum(S2) is odd if and only if
    // both sum(S1) and sum(S2) are odd.

    // A sum of integers is odd if and only if it contains an odd number of odd integers.
    // So, for sum(S1) to be odd, S1 must contain an odd number of odd elements.
    // And for sum(S2) to be odd, S2 must contain an odd number of odd elements.

    // Let odd_S1 be the count of odd numbers in S1, and odd_S2 be the count of odd numbers in S2.
    // We need odd_S1 to be odd and odd_S2 to be odd.
    // The total count of odd numbers in A is count_odd = odd_S1 + odd_S2.
    // If odd_S1 is odd and odd_S2 is odd, then their sum (odd + odd) must be even.
    // Therefore, count_odd must be an even number.

    // Additionally, for odd_S1 and odd_S2 to both be odd, they must each be at least 1.
    // This implies count_odd = odd_S1 + odd_S2 >= 1 + 1 = 2.
    // So, count_odd must be an even number and must be at least 2.

    // Combining these conditions:
    // We need count_odd to be even AND count_odd to be greater than 0.
    // If count_odd is 0, all elements are even, sums will be even, product even. NO.
    // If count_odd is odd, impossible to split into two odd counts. NO.
    // If count_odd is even and > 0 (i.e., >= 2), then YES.
    // We can put one odd number in S1, and the remaining (count_odd - 1) odd numbers in S2.
    // Both S1 and S2 will be non-empty and have odd sums.
    // Even numbers can be distributed arbitrarily (e.g., all to S1).
    if (count_odd % 2 == 0 && count_odd > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```