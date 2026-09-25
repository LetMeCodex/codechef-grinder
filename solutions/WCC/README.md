# [World Chess Championship (WCC)](https://www.codechef.com/problems/WCC)
- **Difficulty Rating**: 935
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the prize money for Magnus Carlsen in a World Chess Championship match against Chef. We are given the value of $X$, which is a multiplier for the prize money. The match consists of 14 games, and the results of these games are provided as a string.

The scoring system is as follows:
- A win for Carlsen ('C') gives him 2 points.
- A win for Chef ('N') gives Chef 2 points.
- A draw ('D') gives both Carlsen and Chef 1 point.

The prize money is determined by the total points scored by Carlsen relative to Chef:
- If Carlsen scores strictly more points than Chef, he wins the championship and gets $60 \times X$.
- If Chef scores strictly more points than Carlsen, Carlsen loses and gets $40 \times X$.
- If Carlsen and Chef have equal points, Carlsen, being the defending champion, is declared the winner and gets $55 \times X$.

## Intuition & Mathematical Observation
The core of the problem lies in accurately calculating the total points for both players based on the game outcomes and then applying the correct prize money rule.

Let $P_C$ be the total points for Carlsen and $P_N$ be the total points for Chef.
We are given a string $S$ of length 14, where each character represents the outcome of a game.

We can iterate through the string $S$ and update the points for Carlsen and Chef based on each character:
- If $S[i] == 'C'$, $P_C$ increases by 2.
- If $S[i] == 'N'$, $P_N$ increases by 2.
- If $S[i] == 'D'$, both $P_C$ and $P_N$ increase by 1.

After iterating through all 14 games, we will have the final scores $P_C$ and $P_N$.
Then, we apply the prize money logic:
1. If $P_C > P_N$: Carlsen wins the championship. Prize = $60 \times X$.
2. If $P_N > P_C$: Chef wins the championship. Prize = $40 \times X$.
3. If $P_C = P_N$: The match is tied. Carlsen, as the defending champion, wins. Prize = $55 \times X$.

The problem statement guarantees that the string $S$ will always have a length of 14. The value of $X$ can be up to $10^6$. The maximum possible prize money would be $60 \times 10^6 = 6 \times 10^7$. An `int` data type in C++ typically has a maximum value of around $2 \times 10^9$, so it can hold this value. However, using `long long` for prize money calculations is a safer practice to avoid potential overflow issues in general programming, especially when intermediate calculations might exceed `int` limits, although in this specific case, `int` would suffice. The problem statement mentions $X$ can be up to $10^6$, and the prize money calculation involves multiplying by constants like 60, 40, or 55. The maximum possible value for $60 \times X$ would be $60 \times 10^6 = 6 \times 10^7$. This fits within a standard 32-bit signed integer range (typically up to $2 \times 10^9$). However, using `long long` for `X` and the prize money is a good defensive programming choice.

## Complexity Analysis
- **Time Complexity**: $O(L)$, where $L$ is the length of the game results string. Since the length of the string is fixed at 14, the time complexity for processing each test case is constant, $O(14)$, which simplifies to $O(1)$. The overall time complexity for $T$ test cases is $O(T)$.

- **Space Complexity**: $O(L)$ to store the input string $S$. Since $L$ is fixed at 14, the space complexity is $O(14)$, which simplifies to $O(1)$. We only use a few variables to store points and the prize money, which also contribute $O(1)$ space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    long long X; // X can be up to 10^6. Prize money (e.g., 60*X) can be 6*10^7.
                 // Using long long for X and prize money is a good practice
                 // to ensure no overflow, even though int might suffice for 6*10^7.
    cin >> X;
    string S; // String to store the results of the 14 games
    cin >> S;

    int carlsen_points = 0; // Carlsen's total points
    int chef_points = 0;    // Chef's total points

    // Iterate through each game result in the string S
    for (char outcome : S) {
        if (outcome == 'C') {
            // Carlsen wins: Carlsen gets 2 points
            carlsen_points += 2;
        } else if (outcome == 'N') {
            // Chef wins: Chef gets 2 points
            chef_points += 2;
        } else { // outcome == 'D'
            // Draw: Both players get 1 point
            carlsen_points += 1;
            chef_points += 1;
        }
    }

    long long carlsen_prize; // Variable to store Carlsen's prize money

    // Determine Carlsen's prize based on the final points
    if (carlsen_points > chef_points) {
        // Carlsen has strictly more points, he is the champion
        carlsen_prize = 60 * X;
    } else if (chef_points > carlsen_points) {
        // Chef has strictly more points, Carlsen is the loser
        carlsen_prize = 40 * X;
    } else { // carlsen_points == chef_points
        // Points are tied. Carlsen is declared the winner as defending champion.
        carlsen_prize = 55 * X;
    }

    // Output Carlsen's prize money followed by a newline
    cout << carlsen_prize << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```