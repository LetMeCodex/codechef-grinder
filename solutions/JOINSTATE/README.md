# [Join States (JOINSTATE)](https://www.codechef.com/problems/JOINSTATE)
- **Difficulty Rating**: 1043
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of "joined states" we can form from a given list of `n` individual states. Each state `i` has a population `a[i]`. To form a joined state, the sum of populations of the states included in it must be at least `m`. Once states are used to form a joined state, they cannot be used again. We need to maximize the total count of such joined states.

## Intuition & Mathematical Observation

This problem can be solved using a greedy approach. To maximize the number of joined states, we should aim to form each joined state using the *minimum possible total population* that meets the threshold `m`. This strategy ensures that we "save" as much population as possible from subsequent states, making it easier to form additional joined states later.

Consider processing the states in the order they are given. We maintain a `current_sum` which accumulates the populations of states that are currently being considered for forming a joined state.

The greedy strategy is as follows:
1.  Initialize `count = 0` (for the number of joined states formed) and `current_sum = 0`.
2.  Iterate through the states from `i = 0` to `n-1`:
    a.  Add the population of the current state `a[i]` to `current_sum`.
    b.  Check if `current_sum` has reached or exceeded the required threshold `m`.
        i.  If `current_sum >= m`, it means we have successfully gathered enough population to form a joined state. We increment `count` by 1.
        ii. Since these states have now been "used up" to form this joined state, we reset `current_sum` to `0` to start accumulating population for the *next* potential joined state.
3.  After iterating through all states, `count` will hold the maximum number of joined states that can be formed.

This greedy approach works because by forming a joined state as soon as `current_sum` reaches `m` (or crosses it for the first time), we are using the smallest possible contiguous block of states to satisfy the condition. Using more states or a larger sum than necessary for the current joined state would only reduce the available population for future joined states, potentially leading to a suboptimal solution.

## Complexity Analysis

*   **Time Complexity**: The solution involves reading `n` elements into a vector, which takes $O(N)$ time. Subsequently, it iterates through the `n` elements once to calculate the `current_sum` and update the `count`. Each operation inside the loop (addition, comparison, assignment) takes constant time. Therefore, for each test case, the time complexity is $O(N)$.
*   **Space Complexity**: We use a `std::vector<long long> a(n)` to store the populations of the `n` states. This requires $O(N)$ space. All other variables (`t`, `n`, `m`, `count`, `current_sum`, `i`) use a constant amount of space. Thus, the space complexity is $O(N)$ for each test case.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often useful with vectors

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // Number of states
        long long m; // Minimum population required for a joined state
        std::cin >> n >> m;

        std::vector<long long> a(n); // Vector to store populations of n states
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read populations
        }

        int count = 0; // Counter for the number of joined states formed
        long long current_sum = 0; // Accumulator for the current group of states

        // Iterate through the states to apply the greedy strategy
        for (int i = 0; i < n; ++i) {
            current_sum += a[i]; // Add current state's population to the sum
            if (current_sum >= m) { // If the sum meets or exceeds the threshold 'm'
                count++; // Increment the count of joined states
                current_sum = 0; // Reset current_sum to start a new group for the next joined state
            }
        }
        std::cout << count << "\n"; // Output the total count for the current test case
    }
    return 0; // Indicate successful execution
}

```