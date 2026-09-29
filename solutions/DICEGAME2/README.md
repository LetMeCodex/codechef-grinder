# Best of Two (DICEGAME2)
- **Difficulty Rating**: 789
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to simulate a dice game between two players, Alice and Bob. Each player rolls three dice. The score for each player is determined by summing the two highest rolls out of their three dice. We are given the results of three dice rolls for Alice and three dice rolls for Bob. We need to determine who wins the game (Alice or Bob) or if it's a tie.

## Intuition & Mathematical Observation
The core of the problem lies in calculating each player's score. For a player who rolls three dice with values $r_1, r_2, r_3$, their score is the sum of the two largest values.

A straightforward way to find the sum of the two largest values is to:
1. Sum all three rolls: $r_1 + r_2 + r_3$.
2. Find the minimum roll among the three: $\min(r_1, r_2, r_3)$.
3. Subtract the minimum roll from the total sum. The result will be the sum of the two largest rolls.

Mathematically, if the rolls are $r_1, r_2, r_3$, the score is $(r_1 + r_2 + r_3) - \min(r_1, r_2, r_3)$.

Once we have calculated Alice's score and Bob's score using this method, we can simply compare them:
- If Alice's score is greater than Bob's score, Alice wins.
- If Bob's score is greater than Alice's score, Bob wins.
- If their scores are equal, it's a tie.

The problem involves multiple test cases, so we need to read the number of test cases and then process each case independently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
    For each test case, we read 6 integers, perform a constant number of arithmetic operations (additions, finding minimums) and comparisons. These operations take constant time, regardless of the input values (as they are within integer limits). Since there are $T$ test cases, the total time complexity is $O(T)$. However, when analyzing per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$.
    We only use a few variables to store the dice rolls, scores, and the number of test cases. The memory usage does not grow with the input size, making it constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions
using namespace std;       // Uses the standard namespace, as per problem instructions

// Function to calculate a player's score based on three dice rolls
int calculate_player_score(int r1, int r2, int r3) {
    // The score is the sum of the two highest rolls.
    // This can be calculated by summing all three rolls and subtracting the minimum roll.
    int total_sum = r1 + r2 + r3;
    int min_roll = min({r1, r2, r3}); // Using initializer list for min (C++11 feature)
    return total_sum - min_roll;
}

void solve() {
    int A1, A2, A3, B1, B2, B3;
    // Read Alice's three rolls and Bob's three rolls
    cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

    // Calculate Alice's score
    int alice_score = calculate_player_score(A1, A2, A3);

    // Calculate Bob's score
    int bob_score = calculate_player_score(B1, B2, B3);

    // Determine the winner or if it's a tie
    if (alice_score > bob_score) {
        cout << "Alice\n";
    } else if (bob_score > alice_score) {
        cout << "Bob\n";
    } else {
        cout << "Tie\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```