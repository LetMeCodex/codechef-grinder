# [Discus Throw (DISCUS)](https://www.codechef.com/problems/DISCUS)
- **Difficulty Rating**: 622
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate a very simple scenario from a discus throw competition. We are given the distances covered by three participants, A, B, and C. Our task is to determine and output the maximum distance achieved among these three participants. This needs to be done for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is to find the largest value among three given integers. This is a fundamental operation in programming and mathematics. There are no complex algorithms or deep mathematical insights required.

The most straightforward way to solve this is:
1. Read the three distances, let's call them `A`, `B`, and `C`.
2. Compare `A` with `B` to find the larger of the two.
3. Compare the result from step 2 with `C` to find the overall largest.

Modern C++ provides convenient functions like `std::max` which can directly handle finding the maximum of two numbers, or even multiple numbers using an initializer list (e.g., `std::max({A, B, C})`). This simplifies the comparison logic significantly.

Given the constraints (distances up to 1000), standard integer types are sufficient, but using `long long` as in the provided solution is a safe practice that prevents overflow issues in problems with larger constraints, even if not strictly necessary here.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    -   For each test case, we perform a constant number of operations: reading three integers, performing a constant number of comparisons (e.g., two comparisons for `max({a, b, c})`), and printing one integer.
    -   Input/output operations for a fixed number of variables are also constant time.
    -   Therefore, the time taken for each test case is independent of the magnitude of the input numbers and is constant.
    -   If there are $T$ test cases, the total time complexity would be $O(T)$.

-   **Space Complexity**: $O(1)$.
    -   We only use a few variables to store the input distances (`a`, `b`, `c`), the number of test cases (`t`), and the result (`result`).
    -   The amount of memory used does not grow with the input values or the number of test cases (beyond the fixed memory for these few variables).
    -   Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes various standard libraries, including iostream and algorithm (for std::max)
using namespace std;

/**
 * Problem: Discus Throw
 * The goal is to find the maximum of three given integers A, B, and C.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    // Read the number of test cases. If input fails, return 0.
    if (!(cin >> t)) return 0;
    
    // Loop through each test case
    while (t--) {
        long long a, b, c; // Variables to store the three distances
        // Read the three distances for the current test case
        cin >> a >> b >> c;
        
        // Use max() function (from <algorithm>) to find the largest of the three distances.
        // The initializer list {a, b, c} allows finding the max of multiple values directly (C++11 and later).
        long long result = max({a, b, c});
        
        // Print the maximum distance followed by a newline character
        cout << result << "\n";
    }
    
    return 0; // Indicate successful execution
}

```