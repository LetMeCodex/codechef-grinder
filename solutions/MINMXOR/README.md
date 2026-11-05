# [Minimum XOR (MINMXOR)](https://www.codechef.com/problems/MINMXOR)
- **Difficulty Rating**: 1154
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible XOR sum of an array after removing *at most one* element. We are given an array `A` of `N` integers. We need to perform this operation for `T` test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of the XOR operation. We need to consider two main scenarios:

1.  **Removing zero elements**: In this case, the XOR sum is simply the XOR sum of all elements in the original array. Let's call this `total_xor`.
2.  **Removing exactly one element**: If we choose to remove an element `A[i]`, we need to find the XOR sum of the remaining `N-1` elements.

Let's denote the XOR sum of all elements as `total_xor = A[0] ^ A[1] ^ ... ^ A[N-1]`.
If we remove `A[i]`, the new XOR sum, let's call it `xor_sum_without_A_i`, would be `A[0] ^ ... ^ A[i-1] ^ A[i+1] ^ ... ^ A[N-1]`.

We know that `total_xor = xor_sum_without_A_i ^ A[i]`.
A crucial property of XOR is that it is its own inverse: `X ^ X = 0` and `X ^ 0 = X`.
Using this, we can isolate `xor_sum_without_A_i`:
`total_xor ^ A[i] = (xor_sum_without_A_i ^ A[i]) ^ A[i]`
`total_xor ^ A[i] = xor_sum_without_A_i ^ (A[i] ^ A[i])`
`total_xor ^ A[i] = xor_sum_without_A_i ^ 0`
`total_xor ^ A[i] = xor_sum_without_A_i`

This means that if we remove an element `A[i]`, the new XOR sum of the array is simply `total_xor ^ A[i]`.

**Algorithm:**

1.  First, calculate the `total_xor` of all elements in the given array `A`.
2.  Initialize a variable `min_final_xor` with `total_xor`. This covers the case where we remove zero elements.
3.  Iterate through each element `A[i]` in the array.
4.  For each `A[i]`, calculate the XOR sum if `A[i]` were removed: `current_xor_if_removed = total_xor ^ A[i]`.
5.  Update `min_final_xor = std::min(min_final_xor, current_xor_if_removed)`.
6.  After iterating through all elements, `min_final_xor` will hold the minimum possible XOR sum.

This approach efficiently checks all `N+1` possibilities (removing zero elements or removing any one of the `N` elements).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` elements and computing their `total_xor`: This involves a single loop that runs `N` times. Each operation inside the loop (reading an integer, XORing) takes constant time. So, this step is $O(N)$.
    *   Iterating through the array again to find the minimum XOR sum after removing each element: This also involves a single loop that runs `N` times. Inside the loop, XOR operation and `std::min` take constant time. So, this step is $O(N)$.
    *   Overall time complexity for a single test case is $O(N) + O(N) = O(N)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given $N \le 10^5$ and $T \le 10$, $T \cdot N \le 10^6$, which is well within typical time limits.

*   **Space Complexity**:
    *   We use a `std::vector<int> A(N)` to store the `N` input elements. This requires $O(N)$ space.
    *   Other variables like `N`, `total_xor`, `min_final_xor`, and loop counters use constant space, $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // For standard input/output operations (cin, cout)
#include <vector>   // For using std::vector to store the array elements
#include <algorithm> // For std::min

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    std::vector<int> A(N); // Declare a vector of size N to store the elements
    int total_xor = 0;     // Initialize total_xor to 0 (identity for XOR)

    // Read elements and compute their total XOR sum
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        total_xor ^= A[i]; // Accumulate XOR sum
    }

    // Initialize the minimum final XOR with the XOR sum of all elements.
    // This covers the case where we choose not to remove any element.
    int min_final_xor = total_xor;

    // Iterate through each element to consider removing it.
    // If element A[i] is removed, the new XOR sum is total_xor ^ A[i].
    // This is derived from the property: (XOR_sum_without_A_i) ^ A_i = total_xor,
    // which implies XOR_sum_without_A_i = total_xor ^ A_i.
    for (int i = 0; i < N; ++i) {
        min_final_xor = std::min(min_final_xor, total_xor ^ A[i]);
    }

    // Output the minimum XOR sum found
    std::cout << min_final_xor << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times for each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```