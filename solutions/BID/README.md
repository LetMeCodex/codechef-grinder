# Pep Bidding (BID)
- **Difficulty Rating**: 833
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine which team, Team A or Team P, Pep will bid for. Pep's decision is based on comparing the total attack and total defense powers of the two teams. Pep will bid for Team A if Team A's total attack power is strictly greater than Team P's total attack power, AND Team A's total defense power is strictly greater than Team P's total defense power. Similarly, Pep will bid for Team P if Team P's total attack power is strictly greater than Team A's total attack power, AND Team P's total defense power is strictly greater than Team A's total defense power. If neither of these conditions is met, Pep will bid for a draw. We are given the number of players $N$, and then four lines of $N$ integers each, representing the attack powers of Team A, defense powers of Team A, attack powers of Team P, and defense powers of Team P, respectively.

## Intuition & Mathematical Observation
The problem statement directly provides the conditions for Pep's bidding strategy. The core of the problem is to calculate the sum of attack and defense powers for each team and then apply the given comparison logic.

Let:
- $A_{att}$ be the sum of attack powers for Team A.
- $A_{def}$ be the sum of defense powers for Team A.
- $P_{att}$ be the sum of attack powers for Team P.
- $P_{def}$ be the sum of defense powers for Team P.

The conditions are:
1. Pep bids for Team A if $A_{att} > P_{att}$ AND $A_{def} > P_{def}$.
2. Pep bids for Team P if $P_{att} > A_{att}$ AND $P_{def} > A_{def}$.
3. Otherwise, Pep bids for DRAW.

The mathematical observation is straightforward: we need to compute four sums and then perform two conditional checks. The constraints on $N$ (up to 1000) and the individual player powers (up to 1000) mean that the total sums will not exceed $1000 \times 1000 = 1,000,000$. This fits comfortably within a standard 32-bit signed integer type.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    - For each test case, we read $N$ integers four times to calculate the sums of attack and defense for both teams. This involves four loops, each iterating $N$ times.
    - The comparison and output operations take constant time, $O(1)$.
    - Therefore, the total time complexity per test case is $O(N + N + N + N) = O(4N) = O(N)$.
    - If there are $T$ test cases, the total time complexity is $O(T \times N)$.

- **Space Complexity**: $O(1)$
    - We only use a few integer variables to store the sums of attack and defense powers for both teams, and loop counters. The amount of memory used does not depend on the input size $N$.
    - Thus, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <iostream> // Only include necessary header for input/output

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of players

    // Initialize total attack and defense powers for both teams.
    // Using int, as max sum (2000 * 1000 = 2,000,000) fits comfortably in a 32-bit signed int.
    int total_attA = 0;
    int total_defA = 0;
    int total_attP = 0;
    int total_defP = 0;

    // Read attack powers for Team A and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_attA += val;
    }

    // Read defense powers for Team A and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_defA += val;
    }

    // Read attack powers for Team P and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_attP += val;
    }

    // Read defense powers for Team P and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_defP += val;
    }

    // Apply Pep's bidding strategy
    // Pep bids for Team A if its total attack AND total defense are strictly greater than Team P's
    if (total_attA > total_attP && total_defA > total_defP) {
        std::cout << "A\n";
    } 
    // Pep bids for Team P if its total attack AND total defense are strictly greater than Team A's
    else if (total_attP > total_attA && total_defP > total_defA) {
        std::cout << "P\n";
    } 
    // Otherwise, if neither team strictly dominates in both categories, Pep bids for a draw
    else {
        std::cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    std::ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    std::cin.tie(NULL);                     // Prevents cin from flushing cout

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```