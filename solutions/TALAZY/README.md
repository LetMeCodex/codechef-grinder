# [Lazy Jem (TALAZY)](https://www.codechef.com/problems/TALAZY)
- **Difficulty Rating**: 1120
- **Solved in**: 1 attempt(s)

## Problem Summary

Jem has `N` problems to solve. He solves them in phases, following a specific routine:
1.  **Problems per phase**: If `N` (the current number of remaining problems) is even, he solves `N/2` problems. If `N` is odd, he solves `(N+1)/2` problems.
2.  **Time per problem**: Initially, each problem takes `M` minutes.
3.  **Breaks**: After completing a phase, if there are still problems remaining, he takes a break of `B` minutes. No break is taken after the very last problem is solved.
4.  **Time increase**: After each break, the time taken per problem *doubles* for the *next* phase.

The goal is to calculate the total time Jem takes to solve all `N` problems.

## Intuition & Mathematical Observation

The problem describes a process that can be directly simulated. We need to keep track of the remaining problems (`current_N`), the current time taken per problem (`current_M`), and the accumulated total time (`total_time`).

The core idea is to iterate through the phases until all problems are solved:
1.  **Loop Condition**: The process continues as long as `current_N` (remaining problems) is greater than 0.
2.  **Calculate Problems for Current Phase**:
    *   If `current_N` is even, `problems_to_solve_in_phase = current_N / 2`.
    *   If `current_N` is odd, `problems_to_solve_in_phase = (current_N + 1) / 2`.
3.  **Add Time for Solving**: The time spent in this phase is `problems_to_solve_in_phase * current_M`. Add this to `total_time`.
4.  **Update Remaining Problems**: Subtract `problems_to_solve_in_phase` from `current_N`.
5.  **Handle Breaks and Time Doubling**: After updating `current_N`, check if `current_N` is still greater than 0.
    *   If `current_N > 0`, it means there are more problems to solve, so Jem takes a break: add `B` to `total_time`.
    *   Also, for the next phase, the time per problem doubles: `current_M *= 2`.
    *   If `current_N == 0`, all problems are solved, so no break is taken, and the loop terminates.

**Data Type Considerations**:
The maximum value for `N`, `B`, and `M` is $10^9$.
The number of phases will be approximately $\log_2 N$. For $N=10^9$, this is about 30 phases.
In each phase, `current_M` can double. So, `current_M` can become `M_{initial} \times 2^{30}$.
The total time can be roughly estimated as `(number of phases) * (average problems per phase) * (average M)`.
A more precise estimate: in each phase `i` (from 0 to $\log_2 N - 1$), `current_N` is roughly `N / 2^i` and `current_M` is `M_{initial} * 2^i`. The problems solved are roughly `current_N / 2`. So, time for phase `i` is approximately `(N / 2^{i+1}) * (M_{initial} * 2^i) = N * M_{initial} / 2`.
Summing this over $\log_2 N$ phases gives `(log_2 N) * (N * M_{initial} / 2)`.
For `N=10^9, M=10^9`, this is approximately `30 * (10^9 * 10^9 / 2) = 15 \times 10^{18}`.
A `long long` in C++ can store values up to approximately $9 \times 10^{18}$, which is sufficient for `total_time` and intermediate calculations involving `N`, `B`, and `M`.

## Complexity Analysis

*   **Time Complexity**: $O(\log N)$
    The `while` loop continues as long as `current_N > 0`. In each iteration, `current_N` is reduced by approximately half (either `current_N / 2` or `(current_N + 1) / 2`). This means the number of iterations is logarithmic with respect to the initial value of `N`. All operations inside the loop (arithmetic, comparisons) take constant time. Therefore, the total time complexity is $O(\log N)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`N`, `B`, `M`, `current_N`, `current_M`, `total_time`, `problems_to_solve_in_phase`) regardless of the input size `N`. No dynamic data structures or arrays are used. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout

// Function to solve a single test case
void solve() {
    long long N, B, M; // Use long long for N, B, M to handle large inputs and intermediate calculations
    std::cin >> N >> B >> M;

    long long current_N = N; // Remaining problems
    long long current_M = M; // Time per problem for the current phase
    long long total_time = 0; // Accumulator for total time

    // Loop until all problems are solved
    while (current_N > 0) {
        long long problems_to_solve_in_phase;

        // Determine how many problems to solve in this phase
        // If N is even, solve N/2 problems.
        // If N is odd, solve (N+1)/2 problems.
        if (current_N % 2 == 0) {
            problems_to_solve_in_phase = current_N / 2;
        } else {
            problems_to_solve_in_phase = (current_N + 1) / 2;
        }

        // Add time spent solving problems in this phase
        total_time += problems_to_solve_in_phase * current_M;

        // Update remaining problems
        current_N -= problems_to_solve_in_phase;

        // If there are still problems left, take a break and double the time per problem
        // No break is taken after the very last problem is finished.
        if (current_N > 0) {
            total_time += B; // Add break time
            current_M *= 2;   // Double time per problem for the next phase
        }
    }

    // Output the total time for the current test case
    std::cout << total_time << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        solve();
    }

    return 0; // Indicate successful execution
}
```