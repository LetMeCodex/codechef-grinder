# [Even Sum (EVENSUM1)](https://www.codechef.com/problems/EVENSUM1)
- **Difficulty Rating**: 607
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to remove exactly one element from a given array of `N` integers such that the sum of the remaining `N-1` elements is even. We need to output "Yes" if such an element can be removed, and "No" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of even and odd numbers, specifically how their sums and differences behave.

Let `S` be the sum of all `N` elements in the given array.
If we remove an element `A_i` from the array, the sum of the remaining `N-1` elements will be `S - A_i`.
Our goal is to make `S - A_i` an even number.

Let's recall the rules for parity in subtraction:
1.  **Even - Even = Even**
2.  **Even - Odd = Odd**
3.  **Odd - Even = Odd**
4.  **Odd - Odd = Even**

From these rules, we can observe that `S - A_i` is even if and only if `S` and `A_i` have the *same parity*.

This leads us to two distinct cases:

**Case 1: The total sum `S` of all `N` elements is Even.**
*   If `S` is even, for `S - A_i` to be even, `A_i` must also be **even** (Even - Even = Even).
*   Therefore, if the total sum `S` is even, we need to find and remove an even number from the array. This is possible if and only if there is at least one even number present in the input array.

**Case 2: The total sum `S` of all `N` elements is Odd.**
*   If `S` is odd, for `S - A_i` to be even, `A_i` must also be **odd** (Odd - Odd = Even).
*   Therefore, if the total sum `S` is odd, we need to find and remove an odd number from the array. This is possible if and only if there is at least one odd number present in the input array.

Based on this observation, the strategy is straightforward:
1.  Calculate the total sum `S` of all elements in the array.
2.  While calculating the sum, also keep track of the count of even numbers and odd numbers in the array.
3.  If `S` is even: Check if `even_count > 0`. If yes, print "Yes"; otherwise, print "No".
4.  If `S` is odd: Check if `odd_count > 0`. If yes, print "Yes"; otherwise, print "No".

This approach correctly covers all scenarios and efficiently determines the answer.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    For each test case, we iterate through the `N` elements of the array exactly once to calculate the total sum and count the even and odd numbers. All other operations (reading `N`, `T`, `cin`/`cout`, arithmetic operations, comparisons) are constant time. Thus, the time complexity per test case is linear with respect to `N`. Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`N`, `total_sum`, `even_count`, `odd_count`, `A_i`, `T`, `i`) to store counts and sums. The amount of memory used by these variables is constant and does not depend on the input size `N`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int total_sum = 0;
    int even_count = 0;
    int odd_count = 0;

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element

        total_sum += A_i; // Add to total sum

        // Check parity of the current element
        if (A_i % 2 == 0) {
            even_count++; // Increment count of even numbers
        } else {
            odd_count++;  // Increment count of odd numbers
        }
    }

    // Determine if a suitable element can be removed
    // We want (total_sum - A_i) to be even.
    // This happens if total_sum and A_i have the same parity.

    if (total_sum % 2 == 0) {
        // If the total sum is even, we need to remove an even number.
        // This is possible if there is at least one even number in the array.
        if (even_count > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        // If the total sum is odd, we need to remove an odd number.
        // This is possible if there is at least one odd number in the array.
        if (odd_count > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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

    return 0;
}
```