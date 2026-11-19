# [Chef Judges a Competition (CO92JUDG)](https://www.codechef.com/problems/CO92JUDG)
- **Difficulty Rating**: 984
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a competition between two participants, Alice and Bob, across `N` races. For each race, both Alice and Bob record a time. To determine the winner, each participant discards their single worst (longest) race time. The total sum of the remaining `N-1` race times is then calculated for both. The participant with the smaller total sum wins. If their sums are equal, the result is a draw. We need to output "Alice", "Bob", or "Draw" for each test case.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to minimize the sum of `N-1` race times when given `N` race times.

1.  **Optimal Strategy for Discarding**: To achieve the smallest possible sum of `N-1` elements from a set of `N` elements, one must always remove the *largest* element from the set. This is a greedy approach: by removing the highest value, the sum of the remaining values will be minimized. In the context of races, a "worst" time means the longest duration, which corresponds to the maximum value among the recorded times.

2.  **Calculating Scores**:
    *   For Alice: We need to find the sum of all her `N` race times (`sumA`) and identify her single longest race time (`maxA`). Her effective score will then be `sumA - maxA`.
    *   For Bob: Similarly, we calculate the sum of all his `N` race times (`sumB`) and find his single longest race time (`maxB`). His effective score will be `sumB - maxB`.

3.  **Determining the Winner**: After calculating the optimal scores for both Alice and Bob, we simply compare them:
    *   If `alice_score < bob_score`, Alice wins.
    *   If `bob_score < alice_score`, Bob wins.
    *   If `alice_score == bob_score`, it's a Draw.

This approach ensures that each participant's score is calculated optimally according to the problem rules, allowing for a direct comparison.

## Complexity Analysis

Let `N` be the number of races and `T` be the number of test cases.

*   **Time Complexity**:
    *   For each test case:
        *   Reading `N`: $O(1)$.
        *   Processing Alice's times: We iterate through `N` race times to calculate `sumA` and `maxA`. This takes $O(N)$ time.
        *   Processing Bob's times: Similarly, we iterate through `N` race times to calculate `sumB` and `maxB`. This also takes $O(N)$ time.
        *   Calculating final scores and comparing them: These are constant time operations, $O(1)$.
    *   Total time for one test case: $O(N) + O(N) + O(1) = O(N)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.
    *   Given constraints: $T \le 100$ and $N \le 10^5$. The maximum operations would be approximately $100 \times 10^5 = 10^7$, which is well within typical time limits for competitive programming (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   For each test case, we only store a few variables: `N`, `sumA`, `maxA`, `sumB`, `maxB`, `time` (for current input), `alice_score`, and `bob_score`. The number of these variables is constant and does not depend on `N`.
    *   Therefore, the space complexity is $O(1)$ (excluding the space required for input/output operations).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of races

    // Process Alice's times
    // We need to calculate the sum of her times and find her maximum time.
    // Alice will optimally discard her largest time.
    long long sumA = 0; // Use long long for sums to be safe, though int is sufficient for given constraints (max N*max_time = 10^5 * 1000 = 10^8, which fits in int)
    int maxA = 0;       // Stores the maximum time for Alice. Initialized to 0 as times are >= 1.
    for (int i = 0; i < N; ++i) {
        int time;
        cin >> time; // Read Alice's time for the current race
        sumA += time; // Add to total sum
        if (time > maxA) {
            maxA = time; // Update maximum time if current time is greater
        }
    }

    // Process Bob's times
    // Similar to Alice, calculate sum and find maximum time for Bob.
    long long sumB = 0;
    int maxB = 0;
    for (int i = 0; i < N; ++i) {
        int time;
        cin >> time; // Read Bob's time for the current race
        sumB += time; // Add to total sum
        if (time > maxB) {
            maxB = time; // Update maximum time if current time is greater
        }
    }

    // Calculate optimal scores for Alice and Bob
    // Each player's effective score is their total sum minus their largest single race time.
    long long alice_score = sumA - maxA;
    long long bob_score = sumB - maxB;

    // Compare the optimal scores to determine the winner
    if (alice_score < bob_score) {
        cout << "Alice\n"; // Alice wins if her score is smaller
    } else if (bob_score < alice_score) {
        cout << "Bob\n";   // Bob wins if his score is smaller
    } else {
        cout << "Draw\n";  // It's a draw if scores are equal
    }
}

int main() {
    // Fast I/O setup for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```