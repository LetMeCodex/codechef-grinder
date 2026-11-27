# [Cricket Nets (CRNET)](https://www.codechef.com/problems/CRNET)
- **Difficulty Rating**: 529
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum cost for Chef to score a total of $X$ runs in a cricket net practice session. The practice session has two phases:

1.  **Phase 1**: The first 20 balls. Each ball scores 1 run and costs 10 rupees.
2.  **Phase 2**: After the first 20 balls. Each ball scores 2 runs and costs 5 rupees.

We need to find the total cost for a given $X$. It's guaranteed that if $X > 20$, then $X$ will be an even number.

## Intuition & Mathematical Observation

The key to solving this problem is to understand the cost-efficiency of each phase:

*   **Phase 1**: 1 run costs 10 rupees. So, the cost per run is 10 rupees.
*   **Phase 2**: 2 runs cost 5 rupees. So, the cost per run is $5 / 2 = 2.5$ rupees.

Since Phase 2 is significantly cheaper per run (2.5 rupees vs 10 rupees), Chef should ideally score as many runs as possible in Phase 2. However, Phase 2 only becomes available *after* the first 20 balls (Phase 1) are completed. This leads to a clear case distinction:

1.  **Case 1: $X \le 20$ runs**
    If the total runs needed ($X$) are 20 or less, Chef can score all these runs within Phase 1. He will play $X$ balls.
    *   Each ball scores 1 run and costs 10 rupees.
    *   Total cost = $X \times 10$.

2.  **Case 2: $X > 20$ runs**
    If Chef needs more than 20 runs, he *must* complete Phase 1 to access Phase 2.
    *   **Cost for Phase 1**: Chef plays all 20 balls of Phase 1.
        *   Runs scored in Phase 1 = 20 runs.
        *   Cost for Phase 1 = $20 \text{ balls} \times 10 \text{ rupees/ball} = 200$ rupees.
    *   **Remaining runs**: After Phase 1, Chef has scored 20 runs. He still needs $X - 20$ runs. These remaining runs must be scored in Phase 2.
    *   **Cost for Phase 2**: In Phase 2, each ball scores 2 runs and costs 5 rupees.
        *   Number of balls needed in Phase 2 = (remaining runs) / 2.
        *   Since $X > 20$ implies $X$ is even, $X - 20$ will also be even, ensuring that `(X - 20) / 2` is always an integer.
        *   Cost for Phase 2 = (Number of balls in Phase 2) $\times 5$.
    *   **Total cost** = (Cost for Phase 1) + (Cost for Phase 2).

The solution implements these two cases directly.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of arithmetic operations (reading input, comparisons, multiplications, additions, divisions) and prints an integer. These operations take constant time regardless of the input value $X$. The `main()` function calls `solve()` $T$ times. Therefore, the total time complexity is $O(T)$, where $T$ is the number of test cases. Since each test case is processed in constant time, we can say the complexity per test case is $O(1)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`X`, `total_cost`, `remaining_runs`, `balls_in_phase2`, `T`). The memory used by these variables is constant and does not depend on the input size $X$ or the number of test cases $T$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

// Using the standard namespace as requested
using namespace std;

void solve() {
    int X;
    cin >> X; // Read the total runs X for the current test case
    
    int total_cost = 0;
    
    // Check if all runs can be scored within Phase 1
    if (X <= 20) {
        // In Phase 1: 1 run per ball, 10 rupees per ball.
        // To score X runs, Chef plays X balls.
        total_cost = X * 10;
    } else {
        // If X > 20, Chef completes Phase 1 and then proceeds to Phase 2.
        
        // Cost for Phase 1:
        // Chef plays all 20 balls of Phase 1.
        // Runs scored in Phase 1 = 20 runs (1 run/ball * 20 balls).
        // Cost for Phase 1 = 20 balls * 10 rupees/ball = 200 rupees.
        total_cost = 20 * 10; 
        
        // Remaining runs to be scored in Phase 2:
        int remaining_runs = X - 20;
        
        // In Phase 2: 2 runs per ball, 5 rupees per ball.
        // Number of balls needed in Phase 2 = remaining_runs / 2.
        // (X is guaranteed even, so X-20 is even, ensuring integer division).
        int balls_in_phase2 = remaining_runs / 2;
        
        // Cost for Phase 2 = balls_in_phase2 * 5 rupees.
        total_cost += balls_in_phase2 * 5;
    }
    
    // Output the total calculated cost for the current test case
    cout << total_cost << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}
```