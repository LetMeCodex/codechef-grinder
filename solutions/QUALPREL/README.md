# [Qualifying to Pre-Elimination (QUALPREL)](https://www.codechef.com/problems/QUALPREL)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the total number of teams that qualify for a pre-elimination round based on their scores. We are given `N` teams and their respective scores. A parameter `K` is also provided. The qualification rules are:

1.  The top `K` teams (based on their scores) always qualify.
2.  If multiple teams have the same score, they are ranked equally. Crucially, any team whose score is equal to the score of the K-th placed team also qualifies, even if they are not among the initial top `K` positions.

Essentially, we need to find the score of the K-th placed team, and then count all teams whose score is greater than or equal to this threshold score.

## Intuition & Mathematical Observation

The core idea to solve this problem efficiently revolves around identifying the minimum score required to qualify.

1.  **Ranking is Essential**: To determine the "K-th placed team," we first need to establish a ranking of all teams based on their scores. The most straightforward way to do this is to sort all the team scores. Since higher scores are better, we should sort the scores in **descending order**.

2.  **Identify the Qualification Threshold**: Once the scores are sorted in descending order, the score of the K-th placed team will be at a specific index. In a 0-indexed array or vector, the K-th element is located at index `K-1`. Let's call this score `min_qualifying_score`. This `min_qualifying_score` is the threshold: any team with a score greater than or equal to this value qualifies.

3.  **Count Qualified Teams**: After determining `min_qualifying_score`, we iterate through the sorted list of scores. For each score, we check if it is greater than or equal to `min_qualifying_score`. We increment a counter for every team that meets this criterion. An important optimization here is that since the scores are sorted in descending order, as soon as we encounter a score that is *less than* `min_qualifying_score`, we know that all subsequent scores will also be less than `min_qualifying_score`. Therefore, we can stop counting and break out of the loop early.

This approach directly implements the problem's qualification logic by first finding the critical score and then counting all teams that meet or exceed it.

## Complexity Analysis

Let `N` be the number of teams and `K` be the rank threshold.

*   **Time Complexity**:
    *   Reading `N` and `K`: $O(1)$
    *   Reading `N` scores into a `std::vector`: $O(N)$
    *   Sorting the `std::vector` of `N` scores: `std::sort` typically uses an introsort algorithm, which has an average and worst-case time complexity of $O(N \log N)$.
    *   Accessing the `K-1`-th element to find `min_qualifying_score`: $O(1)$
    *   Iterating through the sorted vector to count qualified teams: In the worst case (e.g., all teams have the same score), we might iterate through all `N` elements. In the best case, we might stop much earlier. The upper bound is $O(N)$.
    *   Printing the result: $O(1)$

    The dominant operation is the sorting step. Therefore, the overall time complexity for a single test case is $\mathbf{O(N \log N)}$.
    For `T` test cases, the total time complexity would be $O(T \cdot N \log N)$.

*   **Space Complexity**:
    *   Storing `N` scores in a `std::vector`: $O(N)$
    *   `std::sort` might use some auxiliary space, typically $O(\log N)$ for its recursion stack (introsort) or $O(N)$ if it degenerates to merge sort. However, the primary space usage is for the input vector itself.

    Therefore, the overall space complexity is $\mathbf{O(N)}$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, functional etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K; // Read N (total teams) and K (rank threshold)
    vector<int> S(N); // Create a vector to store team scores
    for (int i = 0; i < N; ++i) {
        cin >> S[i]; // Read each team's score
    }

    // Sort scores in descending order.
    // std::greater<int>() is used as a comparator for descending order.
    sort(S.begin(), S.end(), greater<int>());

    // The K-th placed team's score.
    // Since vectors are 0-indexed, the K-th element is at index K-1.
    // K is guaranteed to be at least 1, so K-1 is always a valid index.
    int min_qualifying_score = S[K - 1];

    // Count the number of teams that qualify.
    // A team qualifies if its score is greater than or equal to min_qualifying_score.
    int qualified_count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] >= min_qualifying_score) {
            qualified_count++;
        } else {
            // Since the scores are sorted in descending order,
            // if the current score S[i] is less than min_qualifying_score,
            // all subsequent scores (S[i+1], S[i+2], ...) will also be less.
            // Therefore, we can stop counting and break out of the loop early.
            break;
        }
    }

    // Print the total number of qualified teams for the current test case.
    cout << qualified_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
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