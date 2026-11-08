# [Chef in Fantasy League (FFL)](https://www.codechef.com/problems/FFL)
- **Difficulty Rating**: 1225
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to form a fantasy league team. The team requires exactly one defender and one forward. Chef has a budget of 100 units. He is given a list of $N$ players, each with a price and a role (defender or forward). Chef has already selected some players and spent $S$ units. He needs to select one more defender and one more forward from the remaining players to complete his team. The goal is to determine if Chef can select one defender and one forward such that their combined price does not exceed his remaining budget.

## Intuition & Mathematical Observation
The problem asks if it's *possible* to complete the team, not for the *optimal* way to do so. This means we only need to find the cheapest available defender and the cheapest available forward. If the sum of their prices is within Chef's remaining budget, then it's possible to form the team.

Chef's total budget is 100. He has already spent $S$ units. Therefore, his remaining budget is $100 - S$.

To minimize the cost of acquiring a defender and a forward, Chef should pick the player with the lowest price for each role. Let $P_{min\_defender}$ be the minimum price of an available defender, and $P_{min\_forward}$ be the minimum price of an available forward.

The condition for Chef to be able to complete his team is:
$P_{min\_defender} + P_{min\_forward} \le 100 - S$

If there are no defenders available, or no forwards available, then it's impossible to complete the team. We can handle this by initializing the minimum prices to a value larger than any possible player price (e.g., 101, since the maximum player price is 100). If after iterating through all players, the minimum price for a role remains at this initial large value, it signifies that no player of that role was found.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution iterates through the $N$ players once to read their prices and types, and to find the minimum prices for defenders and forwards. The operations inside the loop (comparisons and `min` function) take constant time. The main function also has a loop that runs $T$ times, and inside each iteration, `solve()` is called, which takes $O(N)$ time. Thus, the total time complexity is $O(T \cdot N)$. However, if we consider the complexity per test case, it is $O(N)$.

- **Space Complexity**: $O(N)$
  The solution uses a `std::vector<int> P` to store the prices of $N$ players. This vector takes $O(N)$ space. The other variables (`N`, `S`, `min_defender_price`, `min_forward_price`, `remaining_budget`, `player_type`, `T`) take constant space. Therefore, the total space complexity is dominated by the vector, making it $O(N)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace for convenience

void solve() {
    int N, S;
    cin >> N >> S;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Initialize min prices to a value greater than any possible player price (max P_i is 100).
    // This value (101) serves two purposes:
    // 1. It's an initial maximum for finding the minimum price.
    // 2. If no player of a certain type is found, its price will remain 101.
    //    The sum of prices will then be high enough to exceed the maximum possible remaining budget (100 - 13 = 87),
    //    correctly indicating that it's impossible to complete the team.
    int min_defender_price = 101; 
    int min_forward_price = 101;

    // Read player types and update minimum prices for defenders and forwards.
    // The i-th price P[i] corresponds to the i-th player type.
    for (int i = 0; i < N; ++i) {
        int player_type;
        cin >> player_type;
        if (player_type == 0) { // Defender
            min_defender_price = min(min_defender_price, P[i]);
        } else { // Forward (player_type == 1)
            min_forward_price = min(min_forward_price, P[i]);
        }
    }

    // Calculate the remaining budget Chef has for the two new players.
    int remaining_budget = 100 - S;

    // Check if the sum of the cheapest defender and cheapest forward
    // is within the remaining budget.
    // This condition implicitly handles cases where no defender or no forward was found
    // because their respective min_price would still be 101, making the sum too high.
    if (min_defender_price + min_forward_price <= remaining_budget) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```