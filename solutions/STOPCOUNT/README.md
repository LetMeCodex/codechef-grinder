# [Stop The Count (STOPCOUNT)](https://www.codechef.com/problems/STOPCOUNT)
- **Difficulty Rating**: 893
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "winning ways" Chef can stop counting problems in a contest. Chef participates in a contest with $N$ problems. The results are given as a binary string $S$ of length $N$, where $S_i = '1'$ means Chef solved the $i$-th problem, and $S_i = '0'$ means Chef did not solve it.

Chef can choose to stop counting problems after any number of problems from $1$ to $N$. He "wins" if, at the point he stops, the number of problems he solved is strictly greater than the number of problems he did not solve. We need to find the total number of such winning ways.

For example, if $N=5$ and $S = "10101"$:
- After 1 problem ($S[0]$): Solved=1, Unsolved=0. (1 > 0) -> Win!
- After 2 problems ($S[0..1]$): Solved=1, Unsolved=1. (1 > 1) -> Not a win.
- After 3 problems ($S[0..2]$): Solved=2, Unsolved=1. (2 > 1) -> Win!
- After 4 problems ($S[0..3]$): Solved=2, Unsolved=2. (2 > 2) -> Not a win.
- After 5 problems ($S[0..4]$): Solved=3, Unsolved=2. (3 > 2) -> Win!

Total winning ways = 3.

## Intuition & Mathematical Observation

The problem essentially asks us to iterate through all possible stopping points, which correspond to prefixes of the given binary string $S$. For each prefix, we need to calculate the number of solved problems and unsolved problems and then check if the winning condition (solved > unsolved) is met.

We can achieve this by maintaining two counters: `chef_votes` for problems solved and `antichef_votes` for problems not solved. We iterate through the input string $S$ from left to right, character by character.
1. When we encounter an '1', we increment `chef_votes`.
2. When we encounter a '0', we increment `antichef_votes`.
3. After processing each character `S[i]`, we have the cumulative counts for the prefix $S[0 \dots i]$. At this point, we check if `chef_votes > antichef_votes`. If this condition is true, it means Chef wins if he stops after $i+1$ problems, so we increment a `winning_ways` counter.

This process is repeated for all $N$ possible stopping points (from 1 problem up to $N$ problems). The final value of `winning_ways` will be our answer. No complex mathematical observations or data structures are required; a direct simulation of the process described in the problem statement is sufficient.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    The solution involves a single loop that iterates $N$ times (once for each character in the input string $S$). Inside the loop, operations like character comparison, counter increments, and integer comparison are all constant time operations. Therefore, the time taken is directly proportional to $N$. Given $T$ test cases, the total time complexity will be $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$ per test case.
    The primary space usage comes from storing the input string $S$, which has a length of $N$. Apart from the string, we use a few integer variables (`N`, `chef_votes`, `antichef_votes`, `winning_ways`, `T`), which consume a constant amount of space, $O(1)$. Thus, the overall space complexity is dominated by the input string, resulting in $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of problems
    string S;
    cin >> S; // Read the binary string representing Chef's results

    int chef_votes = 0;       // Counter for problems Chef solved ('1')
    int antichef_votes = 0;   // Counter for problems Chef did not solve ('0')
    int winning_ways = 0;     // Counter for the number of times Chef wins

    // Iterate through each possible stopping point, from 1 vote up to N votes.
    // The loop variable 'i' corresponds to the 0-based index of the current vote.
    // So, after processing S[i], we have counted i+1 votes.
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            chef_votes++; // Chef solved this problem
        } else { // S[i] == '0'
            antichef_votes++; // Chef did not solve this problem
        }

        // Check if Chef wins after counting the current set of votes.
        // A tie is not a win, so strictly greater is required.
        if (chef_votes > antichef_votes) {
            winning_ways++; // Increment winning ways if Chef has more solved problems
        }
    }

    cout << winning_ways << "\n"; // Output the total number of winning ways
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve(); // Call the function to solve the current test case.
    }

    return 0;
}

```