# [Coloured Orbs (COLORB)](https://www.codechef.com/problems/COLORB)
- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with `R` red orbs and `B` blue orbs.
He has an option to perform a trade: 1 red orb + 1 blue orb = 1 green orb.
Each type of orb contributes to Chef's skill points as follows:
- 1 red orb: 1 skill point
- 1 blue orb: 2 skill points
- 1 green orb: 5 skill points

The objective is to determine the maximum total skill Chef can obtain by strategically making trades.

## Intuition & Mathematical Observation
The core decision Chef needs to make is how many green orbs to create. To figure this out, let's analyze the change in total skill points when Chef makes one trade:

1.  **Skill points lost**: When Chef makes a trade, he uses 1 red orb and 1 blue orb.
    *   1 red orb contributes 1 skill point.
    *   1 blue orb contributes 2 skill points.
    *   Total skill points lost per trade = $1 + 2 = 3$ skill points.

2.  **Skill points gained**: In return for the red and blue orbs, Chef obtains 1 green orb.
    *   1 green orb contributes 5 skill points.
    *   Total skill points gained per trade = $5$ skill points.

3.  **Net change in skill per trade**:
    *   Net gain = (Skill gained) - (Skill lost) = $5 - 3 = 2$ skill points.

Since each trade results in a net gain of 2 skill points, it is always beneficial for Chef to make as many trades as possible to maximize his total skill.

The number of trades Chef can make is limited by the minimum available count of red and blue orbs. If Chef has `R` red orbs and `B` blue orbs, he can make at most `min(R, B)` trades. Let `K_max = min(R, B)` be the maximum number of green orbs Chef can create.

After making `K_max` trades:
*   **Red orbs remaining**: `R - K_max` (initial red orbs minus those used for trades).
*   **Blue orbs remaining**: `B - K_max` (initial blue orbs minus those used for trades).
*   **Green orbs obtained**: `K_max` (one for each trade).

The total skill will then be calculated by summing the skill contributions from all remaining orbs:
`Total Skill = (remaining_R * 1) + (remaining_B * 2) + (green_orbs * 5)`

This greedy strategy is optimal because each trade provides a positive net skill gain, and the cost/benefit of each trade is independent of previous trades.

## Complexity Analysis
*   **Time Complexity**: The solution involves reading two integers, performing a `min` operation, a few subtractions, multiplications, and additions, and finally printing an integer. All these operations are constant time. Therefore, the time complexity is $O(1)$.
*   **Space Complexity**: The solution uses a fixed number of integer variables to store `R`, `B`, `K_max`, `remaining_R`, `remaining_B`, `green_orbs`, and `total_skill`. The memory usage does not depend on the input values (beyond the fixed size of an integer data type). Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using namespace std; is generally fine for competitive programming
using namespace std;

int main() {
    // Enable fast I/O. This is a standard optimization in competitive programming
    // to speed up input and output operations, especially for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read R and B, the initial number of red and blue orbs Chef has.
    int R, B;
    cin >> R >> B;

    // Chef can buy 1 green orb at the cost of 1 red orb + 1 blue orb.
    // This means that the number of green orbs Chef can obtain is limited
    // by the minimum of the available red and blue orbs.
    // For example, if Chef has 3 red and 4 blue orbs, he can make at most 3 trades
    // because he only has 3 red orbs. After 3 trades, he will run out of red orbs.
    int K_max = min(R, B);

    // After making K_max trades, we need to calculate the final count of each orb type.
    // Red orbs remaining: Initial R minus K_max (orbs used for trades).
    int remaining_R = R - K_max;
    // Blue orbs remaining: Initial B minus K_max (orbs used for trades).
    int remaining_B = B - K_max;
    // Green orbs obtained: K_max (each trade yields 1 green orb).
    int green_orbs = K_max;

    // Now, calculate the total skill based on the final orb counts and their values.
    // 1 red orb increases skill by 1.
    // 1 blue orb increases skill by 2.
    // 1 green orb increases skill by 5.
    int total_skill = (remaining_R * 1) + // Skill from remaining red orbs
                      (remaining_B * 2) + // Skill from remaining blue orbs
                      (green_orbs * 5);   // Skill from green orbs obtained

    // Output the maximum skill Chef can obtain.
    // The problem constraints (R, B <= 10) ensure that the total skill
    // will be small and fit comfortably within an 'int' data type.
    cout << total_skill << "\n";

    return 0; // Indicate successful execution of the program.
}
```