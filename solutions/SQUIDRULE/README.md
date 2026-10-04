# [The Squid Game (SQUIDRULE)](https://www.codechef.com/problems/SQUIDRULE)
- **Difficulty Rating**: 970
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game with $N$ players, each possessing a certain amount of money $A_i$. The game rules are:
1. One player is chosen as the winner.
2. All other $N-1$ players are eliminated.
3. The money $A_j$ of each eliminated player $j$ is added to a prize pool.
4. The winner receives the entire prize pool.

The organizers want to maximize the prize pool by strategically choosing the winner. We need to find the maximum possible prize pool.

## Intuition & Mathematical Observation

Let's denote the total sum of money of all players as $S = \sum_{i=1}^{N} A_i$.

If a specific player, say player $k$, is chosen as the winner, then all other players (i.e., all players $j$ where $j \neq k$) are eliminated. The money from these eliminated players forms the prize pool.

The prize pool, in this case, would be the sum of money of all players *except* player $k$. Mathematically, this can be expressed as:
Prize Pool (if player $k$ wins) = $S - A_k$.

Our goal is to maximize this prize pool. Since $S$ (the total sum of all players' money) is a constant value regardless of who wins, to maximize $S - A_k$, we must minimize the value of $A_k$.

Therefore, the optimal strategy for the organizers is to choose the player with the minimum amount of money as the winner. The maximum possible prize pool will then be $S - \min(A_i)$, where $\min(A_i)$ is the minimum amount of money among all players.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    We iterate through the $N$ players' money amounts once to calculate the total sum and find the minimum value. Each operation (reading an integer, adding to sum, comparing for minimum) takes constant time. Thus, for each test case, the time complexity is linear with respect to the number of players $N$. If there are $T$ test cases, the total time complexity would be $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    We only store a few variables: `N`, `total_sum`, `min_A`, and a temporary variable for `A_i`. The amount of memory used does not depend on the input size $N$. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of players
    
    long long total_sum = 0; // Initialize total sum of A_i. Use long long to prevent overflow.
    // A_i values are between 0 and 10^4. Initialize min_A to a value greater than max possible A_i.
    int min_A = 10001; 
    
    // Iterate N times to read all A_i values
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the current A_i value
        total_sum += A_i; // Add it to the total sum
        
        // Update min_A if the current A_i is smaller
        if (A_i < min_A) {
            min_A = A_i;
        }
    }
    
    // The maximum prize is achieved when the winner is the player
    // whose elimination would add the minimum amount (min_A) to the prize pool.
    // This means we subtract min_A from the total sum of all A_i.
    cout << total_sum - min_A << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}
```