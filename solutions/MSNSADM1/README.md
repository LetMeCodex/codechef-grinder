# [Football (MSNSADM1)](https://www.codechef.com/problems/MSNSADM1)
- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate points for `N` football players and determine the maximum points achieved by any single player. For each player, we are given the number of goals they scored (`A[i]`) and the number of fouls they committed (`B[i]`).

The point calculation rules are:
1. Each goal contributes `20` points.
2. Each foul deducts `10` points.
3. If a player's total calculated points are negative, their final points are considered `0`.

We need to output the highest final points among all `N` players for each test case.

## Intuition & Mathematical Observation

The problem is a straightforward simulation and maximum finding task. For each player, we simply need to apply the given rules to calculate their points and then keep track of the highest points encountered so far.

Let's denote the goals scored by player `i` as `A[i]` and fouls committed as `B[i]`.
The raw points for player `i` can be calculated as:
`raw_points_i = (A[i] * 20) - (B[i] * 10)`

According to the rule that points cannot be negative, the final points for player `i` will be:
`final_points_i = max(0, raw_points_i)`

Our goal is to find the maximum value among all `final_points_i` for `i` from `0` to `N-1`. We can initialize a variable `max_overall_points` to `0` (since points cannot be negative) and update it whenever we find a player with higher `final_points_i`.

The process for each test case will be:
1. Read `N`.
2. Read all `A[i]` values into a vector.
3. Read all `B[i]` values into another vector.
4. Initialize `max_overall_points = 0`.
5. Iterate from `i = 0` to `N-1`:
    a. Calculate `raw_points_i = (A[i] * 20) - (B[i] * 10)`.
    b. Calculate `final_points_i = max(0, raw_points_i)`.
    c. Update `max_overall_points = max(max_overall_points, final_points_i)`.
6. Print `max_overall_points`.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N`: $O(1)$
    -   Reading `N` goals into vector `A`: $O(N)$
    -   Reading `N` fouls into vector `B`: $O(N)$
    -   Iterating through `N` players to calculate points and find the maximum: This loop runs `N` times. Inside the loop, all operations (multiplication, subtraction, `max` function calls) take constant time, $O(1)$. Thus, this part takes $O(N)$ time.
    -   Total time complexity for one test case is $O(1) + O(N) + O(N) + O(N) = O(N)$.
    -   Since there are `T` test cases, the overall time complexity will be $O(T \cdot N)$.

-   **Space Complexity**:
    -   Storing `N` goals in vector `A`: $O(N)$ space.
    -   Storing `N` fouls in vector `B`: $O(N)$ space.
    -   Other variables (`N`, `max_overall_points`, `goals`, `fouls`, `raw_points`, `current_player_points`) use constant extra space, $O(1)$.
    -   Total space complexity for one test case is $O(N) + O(N) + O(1) = O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Use standard namespace for convenience

void solve() {
    int N;
    cin >> N; // Read the number of players
    
    // Read goals scored by each player
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read fouls committed by each player
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    int max_overall_points = 0; // Initialize max points to 0, as points cannot be negative
    
    // Iterate through each player to calculate their points and find the maximum
    for (int i = 0; i < N; ++i) {
        int goals = A[i];
        int fouls = B[i];
        
        // Calculate raw points: 20 for each goal, -10 for each foul
        int raw_points = (goals * 20) - (fouls * 10);
        
        // Apply the rule: if points are negative, they become 0
        int current_player_points = max(0, raw_points);
        
        // Update the maximum overall points found so far
        max_overall_points = max(max_overall_points, current_player_points);
    }
    
    // Print the maximum points for the current test case
    cout << max_overall_points << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the function to solve each test case
    }
    
    return 0; // Indicate successful execution
}
```