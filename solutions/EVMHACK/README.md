# [EVM Hacking (EVMHACK)](https://www.codechef.com/problems/EVMHACK)
- **Difficulty Rating**: 1223
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes an election scenario across three cities. Chef initially has `A`, `B`, and `C` votes in cities 1, 2, and 3 respectively. The total number of votes cast in these cities are `P`, `Q`, and `R` respectively. Chef has the ability to hack *at most one* Electronic Voting Machine (EVM). If Chef hacks an EVM in a particular city, Chef gains all the votes cast in that city. The task is to determine if Chef can win the election, which means Chef's total votes must be strictly greater than half of the total votes cast across all three cities.

## Intuition & Mathematical Observation
The core of this problem lies in evaluating a limited number of scenarios and checking a simple winning condition.

1.  **Winning Condition**: Chef wins if their total votes are strictly greater than half of the total votes cast. Mathematically, if `V_chef` is Chef's total votes and `V_total` is the total votes cast, Chef wins if `V_chef > V_total / 2`. To avoid potential floating-point issues and for efficiency, this condition is best checked as `2 * V_chef > V_total`. This integer-based comparison is robust.

2.  **Total Votes Cast**: The total number of votes cast across all three cities is `P + Q + R`. This value is constant and does not change regardless of whether Chef hacks an EVM or not. We should calculate this once at the beginning of each test case.

3.  **Hacking Scenarios**: Chef can hack *at most one* EVM. This means there are exactly four distinct scenarios to consider:
    *   **Scenario 1: No Hack**: Chef chooses not to hack any EVM. In this case, Chef's total votes are simply the sum of their initial votes from all three cities: `A + B + C`.
    *   **Scenario 2: Hack EVM 1**: Chef hacks the EVM in City 1. Chef gets all `P` votes from City 1, plus their initial `B` votes from City 2 and `C` votes from City 3. Chef's total votes: `P + B + C`.
    *   **Scenario 3: Hack EVM 2**: Chef hacks the EVM in City 2. Chef gets their initial `A` votes from City 1, all `Q` votes from City 2, and their initial `C` votes from City 3. Chef's total votes: `A + Q + C`.
    *   **Scenario 4: Hack EVM 3**: Chef hacks the EVM in City 3. Chef gets their initial `A` votes from City 1, `B` votes from City 2, and all `R` votes from City 3. Chef's total votes: `A + B + R`.

4.  **Decision Logic**: Chef can win if *any* of these four scenarios results in their total votes satisfying the winning condition (`2 * V_chef > V_total`). If, after checking all four possibilities, none of them lead to a win, then Chef cannot win. The solution simply calculates Chef's votes for each of these four scenarios, checks the winning condition, and prints "YES" if any scenario results in a win, otherwise "NO".

## Complexity Analysis
*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the program performs a fixed number of arithmetic operations (additions, multiplications) and comparisons. Reading the six input integers also takes constant time. Therefore, the operations per test case are constant. If there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: $O(1)$.
    The program uses a fixed number of integer variables to store inputs and intermediate calculations, regardless of the input values. This requires a constant amount of memory.

## Solution Code
```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// Function to solve a single test case
void solve() {
    int A, B, C, P, Q, R;
    // Read the six integers for the current test case
    std::cin >> A >> B >> C >> P >> Q >> R;

    // Calculate the total number of votes cast across all three cities.
    // This value remains constant regardless of hacking.
    int total_votes_cast = P + Q + R;

    // --- Scenario 1: Chef hacks no EVM ---
    // Chef's votes are the sum of initial votes from all cities.
    int chef_votes_no_hack = A + B + C;
    // Check if Chef wins in this scenario: strictly more than half total votes.
    // Using 2 * chef_votes > total_votes_cast avoids floating-point arithmetic.
    if (2 * chef_votes_no_hack > total_votes_cast) {
        std::cout << "YES\n"; // If Chef wins, print YES and we are done for this test case.
        return;
    }

    // --- Scenario 2: Chef hacks EVM 1 ---
    // Chef gets all votes from city 1 (P), plus initial votes from city 2 (B) and city 3 (C).
    int chef_votes_hack_1 = P + B + C;
    if (2 * chef_votes_hack_1 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // --- Scenario 3: Chef hacks EVM 2 ---
    // Chef gets initial votes from city 1 (A), all votes from city 2 (Q), and initial votes from city 3 (C).
    int chef_votes_hack_2 = A + Q + C;
    if (2 * chef_votes_hack_2 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // --- Scenario 4: Chef hacks EVM 3 ---
    // Chef gets initial votes from city 1 (A), initial votes from city 2 (B), and all votes from city 3 (R).
    int chef_votes_hack_3 = A + B + R;
    if (2 * chef_votes_hack_3 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // If none of the above scenarios resulted in Chef winning, then Chef cannot win.
    std::cout << "NO\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}
```