# [Maximum Score (MXSCWN)](https://www.codechef.com/problems/MXSCWN)
- **Difficulty Rating**: 843
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum possible total score in a game involving $N$ matches. For each match $i$, we are given two scores: $A_i$ (score if we win) and $B_i$ (score if we lose). The rules state that we must win exactly $N-1$ matches and lose exactly $1$ match. Our goal is to choose which single match to lose such that our total score is maximized.

## Intuition & Mathematical Observation

Let's consider the total score if we were to win *all* $N$ matches. This hypothetical maximum score would simply be the sum of all $A_i$ values: $\sum_{i=1}^{N} A_i$.

Now, the problem states we must lose exactly one match. Suppose we decide to lose match $k$.
If we lose match $k$:
1. For all matches $i \neq k$, we win and score $A_i$.
2. For match $k$, we lose and score $B_k$.

So, the total score if we lose match $k$ would be:
$S_k = \left( \sum_{i=1, i \neq k}^{N} A_i \right) + B_k$

We can rewrite the sum of $A_i$ for $i \neq k$ as $(\sum_{i=1}^{N} A_i) - A_k$.
Substituting this back into the score formula:
$S_k = \left( \sum_{i=1}^{N} A_i \right) - A_k + B_k$
$S_k = \left( \sum_{i=1}^{N} A_i \right) - (A_k - B_k)$

Let $P_k = A_k - B_k$. This term $P_k$ represents the "penalty" or "score reduction" incurred by losing match $k$ instead of winning it. If we win match $k$, we get $A_k$. If we lose it, we get $B_k$. The difference $A_k - B_k$ is how much less we score by losing that specific match compared to winning it.

Our objective is to maximize $S_k$. From the formula $S_k = \left( \sum_{i=1}^{N} A_i \right) - P_k$, we can see that to maximize $S_k$, we need to minimize the penalty $P_k$.

Therefore, the optimal strategy is:
1. Calculate the sum of all $A_i$ values.
2. For each match $i$, calculate its penalty $P_i = A_i - B_i$.
3. Find the minimum penalty among all $P_i$ values. Let this be $P_{min}$.
4. The maximum possible score will be $(\sum_{i=1}^{N} A_i) - P_{min}$.

This approach ensures we lose the match that costs us the least amount of score compared to winning it, thereby maximizing our overall total.

## Complexity Analysis

Let $N$ be the number of matches.

-   **Time Complexity**: $O(N)$
    1.  Reading $N$: $O(1)$.
    2.  Reading $N$ values for array $A$ and calculating their sum: This involves a loop that runs $N$ times. Inside the loop, input and addition operations are $O(1)$. Total: $O(N)$.
    3.  Reading $N$ values for array $B$ and finding the minimum penalty: This involves another loop that runs $N$ times. Inside the loop, input, subtraction, and `min` operations are $O(1)$. Total: $O(N)$.
    4.  Calculating the final score and printing: $O(1)$.
    Combining these, the dominant operations are the two loops, resulting in a total time complexity of $O(N)$ per test case. Since there are $T$ test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    1.  `vector<int> A(N)`: Stores $N$ integers, requiring $O(N)$ space.
    2.  `vector<int> B(N)`: Stores $N$ integers, requiring $O(N)$ space.
    3.  Other variables (`N`, `total_A_sum`, `min_penalty`, `max_score`, etc.) use a constant amount of space, $O(1)$.
    Therefore, the total space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm etc.

using namespace std; // As requested

void solve() {
    int N;
    cin >> N; // Read N

    vector<int> A(N);
    long long total_A_sum = 0;
    // Read A_i values and calculate their sum
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_A_sum += A[i];
    }

    vector<int> B(N);
    // Initialize min_penalty with a value larger than any possible penalty.
    // Max A_i - B_i is 100 - 1 = 99. So 101 is a safe initial value.
    int min_penalty = 101; 
    // Read B_i values and find the minimum penalty (A_i - B_i)
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        int penalty = A[i] - B[i];
        min_penalty = min(min_penalty, penalty); // Update min_penalty if current penalty is smaller
    }

    // The maximum score is the sum of all A_i minus the minimum penalty incurred by losing one match.
    long long max_score = total_A_sum - min_penalty;
    cout << max_score << "\n"; // Output the result
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```