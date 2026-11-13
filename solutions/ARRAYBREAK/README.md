# [Break the elements (ARRAYBREAK)](https://www.codechef.com/problems/ARRAYBREAK)
- **Difficulty Rating**: 1191
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given an array `A` of `N` positive integers. You can perform an operation: choose an element `X` from the array, remove it, and add two positive integers `Y` and `Z` such that `Y + Z = X`. This operation costs 1. The goal is to make all elements in the array have the same parity (all odd or all even) using the minimum number of operations.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the parity of numbers changes (or doesn't change) when an element `X` is split into `Y` and `Z` such that `Y + Z = X`.

Let's analyze the parity of `Y` and `Z` based on the parity of `X`:

1.  **If `X` is even:**
    *   `X = Y + Z`
    *   This implies `Y` and `Z` must have the same parity.
    *   Case A: `Y` is even, `Z` is even (e.g., `4 = 2 + 2`).
    *   Case B: `Y` is odd, `Z` is odd (e.g., `4 = 1 + 3`).
    *   **Observation:** An even number can be split into two odd numbers. This is crucial. For example, any even number `E >= 2` can be split into `1` and `E-1`. Since `E` is even, `E-1` is odd. Both `1` and `E-1` are positive.

2.  **If `X` is odd:**
    *   `X = Y + Z`
    *   This implies `Y` and `Z` must have different parities.
    *   Case A: `Y` is even, `Z` is odd (e.g., `3 = 2 + 1`).
    *   Case B: `Y` is odd, `Z` is even (e.g., `3 = 1 + 2`).
    *   **Observation:** An odd number, when split, *always* produces one even and one odd number. This means an odd number can never be completely eliminated from the array to achieve an "all even" state. If you start with an odd number, you will always end up with at least one odd number in the array, no matter how many times you split it.

Now, let's consider the two target states:

*   **Target: Make all elements even.**
    *   Based on our observation, if there is *any* odd number in the initial array, it's impossible to make all elements even. An odd number will always persist in some form.
    *   Therefore, if the initial array contains at least one odd number (`count_odd > 0`), we cannot achieve the "all even" state.
    *   If the initial array contains *no* odd numbers (`count_odd == 0`), then all elements are already even. In this case, 0 operations are needed.

*   **Target: Make all elements odd.**
    *   If there are even numbers in the initial array, we need to convert them to odd numbers.
    *   From our observation, an even number `X` can be split into two odd numbers (e.g., `1` and `X-1`). This costs 1 operation. After this operation, one even number is replaced by two odd numbers.
    *   We can apply this operation to every even number in the array. Each even number will require 1 operation to be replaced by two odd numbers.
    *   The total number of operations needed to make all elements odd will be equal to the count of even numbers (`count_even`).
    *   If the initial array contains *no* even numbers (`count_even == 0`), then all elements are already odd. In this case, 0 operations are needed.

**Combining these observations:**

1.  First, count the number of odd elements (`count_odd`) and even elements (`count_even`) in the initial array.
2.  **If `count_odd == 0` or `count_even == 0`**: This means all elements in the array already have the same parity (all even or all odd). No operations are needed. Output `0`.
3.  **Else (if `count_odd > 0` AND `count_even > 0`)**: The array contains a mix of odd and even numbers.
    *   We cannot make all elements even (because odd numbers persist).
    *   We *can* make all elements odd by converting each even number into two odd numbers. This requires 1 operation per even number.
    *   Therefore, the minimum number of operations is `count_even`. Output `count_even`.

This strategy guarantees the minimum operations because:
*   If the array is already uniform, 0 operations is clearly minimal.
*   If it's mixed, we've shown "all even" is impossible. To achieve "all odd", each even number *must* be operated on at least once to change its parity. Splitting an even number into two odds is the most efficient way to remove an even number and replace it with odds, costing 1 operation.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through the input array once to count odd and even numbers. This loop runs `N` times.
    *   Reading `N` integers takes $O(N)$ time.
    *   The final conditional check and printing take $O(1)$ time.
    *   For `T` test cases, the total time complexity is $O(\sum N)$, where $\sum N$ is the sum of `N` over all test cases. Given the constraints, this is efficient enough.

*   **Space Complexity**: $O(1)$.
    *   We only use a few integer variables (`N`, `count_odd`, `count_even`, `A_i`, `T`) to store counts and loop variables. No data structures that scale with `N` are used.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using namespace std; is common in competitive programming
// and requested by the problem statement.
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array A.

    int count_odd = 0;  // Counter for odd numbers in the array.
    int count_even = 0; // Counter for even numbers in the array.

    // Iterate through the array elements to count odd and even numbers.
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element A_i.
        if (A_i % 2 == 0) {
            // If A_i is even, increment count_even.
            count_even++;
        } else {
            // If A_i is odd, increment count_odd.
            count_odd++;
        }
    }

    // Determine the minimum number of operations based on the counts.
    // Case 1: All elements are already odd (count_even is 0).
    // Case 2: All elements are already even (count_odd is 0).
    // In both these cases, the array already has elements of the same parity.
    // So, zero operations are needed.
    if (count_odd == 0 || count_even == 0) {
        cout << 0 << "\n";
    } else {
        // Case 3: The array contains a mix of odd and even numbers.
        // We need to make all elements have the same parity.
        //
        // It's impossible to make all elements even if there's at least one odd number,
        // because splitting an odd number always results in one odd and one even number.
        // So, an odd number will always persist in some form.
        //
        // The only option is to make all elements odd.
        // Each even number A_i (where A_i >= 2) can be split into two positive odd integers
        // (e.g., 1 and A_i-1). This takes 1 operation per even number.
        // After this operation, one even number is replaced by two odd numbers.
        // We need to perform this operation for every even number in the array.
        // The total number of operations will be equal to count_even.
        // The problem guarantees that parity can be made equal, so this strategy must work.
        cout << count_even << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```