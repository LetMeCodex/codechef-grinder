# [Streak Star (STKSTR)](https://www.codechef.com/problems/STKSTR)
- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible length of a non-decreasing subarray in a given array `A` of `N` integers. We are allowed to perform at most one operation: choose an index `i` (from `0` to `N-1`) and replace `A[i]` with `A[i] * X`, where `X` is a given integer.

## Intuition & Mathematical Observation

The core of the problem lies in the phrase "at most one operation". This means we have two main scenarios to consider:

1.  **No operation is performed:** We simply find the longest non-decreasing subarray in the original array `A`.
2.  **Exactly one operation is performed:** We choose *one* index `i` (from `0` to `N-1`), multiply `A[i]` by `X`, and then find the longest non-decreasing subarray in this modified array. We must do this for every possible choice of `i`.

Since we need to maximize the length, we will calculate the longest non-decreasing subarray for each of these `N+1` scenarios (1 for no operation, `N` for one operation at each possible index) and take the maximum among all results.

**Algorithm Breakdown:**

1.  Initialize `max_streak = 0`.
2.  **Scenario 1: No operation.**
    *   Iterate through the original array `A` to find the longest non-decreasing subarray.
    *   Update `max_streak` with this value.
3.  **Scenario 2: Perform one operation.**
    *   Loop `i` from `0` to `N-1`:
        *   Create a temporary copy of the original array, let's call it `B`.
        *   Modify `B[i]` by setting `B[i] = A[i] * X`.
        *   Iterate through this modified array `B` to find the longest non-decreasing subarray.
        *   Update `max_streak` with the maximum streak found in `B`.
4.  After checking all `N+1` scenarios, `max_streak` will hold the final answer.

The process of finding the longest non-decreasing subarray in a given array is a standard linear scan:
*   Initialize `current_streak = 1` (if the array is not empty).
*   Iterate from the second element (`j=1`) to the end of the array.
*   If `array[j] >= array[j-1]`, increment `current_streak`.
*   Else (if `array[j] < array[j-1]`), the non-decreasing sequence is broken. Update `max_streak = std::max(max_streak, current_streak)` and reset `current_streak = 1`.
*   After the loop, make sure to update `max_streak` one last time with the final `current_streak` (in case the longest streak ends at the last element).

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot N^2)$
    *   There are `T` test cases.
    *   For each test case:
        *   Reading input array `A`: $O(N)$.
        *   **Scenario 1 (No operation):** Finding the longest non-decreasing subarray takes $O(N)$ time.
        *   **Scenario 2 (One operation):** This involves a loop that runs `N` times (for each possible index `i` to apply the operation).
            *   Inside this loop, we create a copy of the array `B`, which takes $O(N)$ time.
            *   Then, we find the longest non-decreasing subarray in `B`, which also takes $O(N)$ time.
            *   Thus, each iteration of the `N` loop takes $O(N) + O(N) = O(N)$ time.
            *   Total for Scenario 2: $N \times O(N) = O(N^2)$.
    *   Combining these, the total time per test case is $O(N) + O(N^2) = O(N^2)$.
    *   Overall time complexity: $O(T \cdot N^2)$.
    *   Given $N \le 2000$ and $T \le 10$, the maximum operations would be approximately $10 \cdot (2000)^2 = 10 \cdot 4 \cdot 10^6 = 4 \cdot 10^7$, which is well within typical time limits (usually $10^8$ operations per second).

*   **Space Complexity**: $O(N)$
    *   We store the input array `A` in a `std::vector<long long> a(n)`, which takes $O(N)$ space.
    *   Inside the loop for Scenario 2, a temporary copy `std::vector<long long> b = a;` is created. This also takes $O(N)$ space. Since this copy is created and destroyed in each iteration, the maximum additional space used at any point is $O(N)$.
    *   Therefore, the total space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n;
        long long x;
        std::cin >> n >> x; // Read array size N and multiplier X

        std::vector<long long> a(n); // Declare a vector of size N
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read elements into the vector
        }

        int max_streak = 0; // Initialize maximum streak found so far

        // Handle the case of an empty array explicitly
        if (n == 0) {
            std::cout << 0 << "\n";
            continue; // Move to the next test case
        }

        // Case 1: No operation is performed
        int current_streak = 1; // A single element is a streak of 1
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) {
                current_streak++; // Extend the streak
            } else {
                max_streak = std::max(max_streak, current_streak); // Update max_streak
                current_streak = 1; // Reset streak for the new element
            }
        }
        max_streak = std::max(max_streak, current_streak); // Update max_streak one last time for the final streak

        // Case 2: Perform operation at most once (i.e., exactly once at each possible index)
        for (int i = 0; i < n; ++i) {
            std::vector<long long> b = a; // Create a copy of the original array
            b[i] *= x; // Perform the operation: multiply element at index i by X

            current_streak = 1; // Reset current streak for the modified array
            for (int j = 1; j < n; ++j) {
                if (b[j] >= b[j - 1]) {
                    current_streak++; // Extend the streak
                } else {
                    max_streak = std::max(max_streak, current_streak); // Update max_streak
                    current_streak = 1; // Reset streak
                }
            }
            max_streak = std::max(max_streak, current_streak); // Update max_streak one last time
        }
        
        std::cout << max_streak << "\n"; // Output the maximum streak found
    }
    return 0; // Indicate successful execution
}

```