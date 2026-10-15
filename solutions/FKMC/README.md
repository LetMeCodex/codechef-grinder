# [Fake Certificate (FKMC)](https://www.codechef.com/problems/FKMC)
- **Difficulty Rating**: 1074
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice has a binary string of length `N`, where '1' represents being present and '0' represents being absent. She wants to maximize the total number of days she is marked present. She can perform *at most one* operation: choose a contiguous subsegment of '0's and change all '0's within that subsegment to '1's. The task is to find the maximum possible number of '1's Alice can achieve.

## Intuition & Mathematical Observation

The problem asks us to maximize the total count of '1's after performing at most one operation. Let's break down the components:

1.  **Initial '1's**: Any '1's already present in the string contribute to the final count and cannot be changed by the operation (as the operation only affects '0's). So, we should count all existing '1's.

2.  **The Operation**: Alice can choose *one* contiguous subsegment of '0's and convert them all to '1's. This operation adds a certain number of '1's to the total. If she chooses a subsegment of `k` zeros, she effectively adds `k` new '1's.

3.  **Maximizing the Gain**: To maximize the total number of '1's, Alice should choose the subsegment of '0's that, when converted, yields the largest increase in '1's. This means she should find the *longest* contiguous subsegment of '0's in the original string. Flipping any other subsegment of '0's (or choosing not to flip any) would result in an equal or smaller gain.

4.  **Combining**: The maximum number of '1's will therefore be the sum of:
    *   The total count of '1's initially present in the string.
    *   The length of the longest contiguous subsegment of '0's found in the string.

For example, if the string is `1001000`:
*   Initial '1's count: 2 (at indices 0 and 3).
*   Contiguous '0's segments: "00" (length 2) and "000" (length 3).
*   Longest contiguous '0's segment length: 3.
*   Maximum '1's = 2 (initial '1's) + 3 (longest '0's segment) = 5.
    (The string would become `1001111` if she flips the "000" segment).

The algorithm will involve a single pass through the string to simultaneously count initial '1's and track the maximum length of consecutive '0's.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   We iterate through the input string `s` of length `N` exactly once. Inside the loop, operations like character comparison, incrementing counters, and `max()` are all $O(1)$.
    *   Reading input and printing output also take $O(N)$ and $O(1)$ respectively.
    *   Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   We store the input string `s`, which takes $O(N)$ space.
    *   A few integer variables (`n`, `total_ones`, `max_consecutive_zeros`, `current_consecutive_zeros`) are used, which take $O(1)$ additional space.
    *   Therefore, the dominant factor is the storage of the string, making the space complexity $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the binary string

    int total_ones = 0; // Stores the count of '1's initially present in the string
    int max_consecutive_zeros = 0; // Stores the maximum length of a contiguous block of '0's found
    int current_consecutive_zeros = 0; // Stores the length of the current contiguous block of '0's

    // Iterate through the string to count '1's and find the longest block of '0's
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            total_ones++; // Increment count of '1's
            // If a '1' is encountered, it breaks any ongoing sequence of '0's.
            // So, reset the current consecutive zeros count.
            current_consecutive_zeros = 0;
        } else { // s[i] == '0'
            current_consecutive_zeros++; // Increment current consecutive zeros count
            // Update the maximum consecutive zeros found so far
            max_consecutive_zeros = max(max_consecutive_zeros, current_consecutive_zeros);
        }
    }

    // The maximum number of days Alice will be marked present is the sum of:
    // 1. Days she was already present (total_ones).
    // 2. Days she can convert from absent to present using one operation (max_consecutive_zeros).
    cout << total_ones + max_consecutive_zeros << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```