# [Chef and Fruits (FRUITS)](https://www.codechef.com/problems/FRUITS)
- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible absolute difference between the number of apples (`N`) and oranges (`M`) after Chef has spent at most `K` gold coins. Each gold coin can be used to buy exactly one fruit, either an apple or an orange.

## Intuition & Mathematical Observation

The goal is to minimize the absolute difference `|N - M|`. Chef has `K` gold coins, and each coin can increase either `N` or `M` by 1.

Let's consider how spending a coin affects the difference:

1.  **Initial Difference**: Calculate the absolute difference between the current number of apples and oranges: `initial_diff = abs(N - M)`.

2.  **Optimal Strategy for Spending Coins**: To reduce the absolute difference, Chef should always buy the type of fruit that he currently has *less* of.
    *   If `N > M`: Chef has more apples. To reduce the difference `N - M`, he should buy an orange. This increases `M` by 1. The new difference becomes `N - (M+1)`, which is `(N - M) - 1`. So, the difference reduces by 1.
    *   If `M > N`: Chef has more oranges. To reduce the difference `M - N`, he should buy an apple. This increases `N` by 1. The new difference becomes `(M - (N+1))`, which is `(M - N) - 1`. So, the difference reduces by 1.
    *   If `N = M`: The difference is already 0. Any fruit Chef buys will increase the count of one fruit type, making the difference 1. In this case, he should stop spending coins if his goal is to minimize the difference.

3.  **Effect of Each Coin**: From the above observations, each optimally spent coin reduces the absolute difference `|N - M|` by exactly 1.

4.  **Total Reduction**: Chef has `K` coins. Therefore, he can reduce the initial absolute difference by at most `K`.

5.  **Minimum Possible Difference**:
    *   If `initial_diff - K` is positive, it means Chef did not have enough coins to make the number of apples and oranges equal. The best he could do is reduce the difference by `K`, resulting in a final difference of `initial_diff - K`.
    *   If `initial_diff - K` is zero or negative, it means Chef had enough coins (or more than enough) to make the number of apples and oranges equal. In this scenario, he can spend exactly `initial_diff` coins to equalize the counts, achieving a difference of 0. Any remaining coins would only increase the difference again.
    *   Combining these, the minimum possible difference is `max(0, initial_diff - K)`.

This simple mathematical observation leads directly to the solution.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function involves a few constant-time arithmetic operations (`abs`, `-`, `max`) and input/output operations. Since these operations do not depend on the magnitude of `N`, `M`, or `K` (only on their existence), each test case is processed in constant time. If there are `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`N`, `M`, `K`, `initial_diff`, `min_possible_diff`, `t`). The memory usage does not grow with the input values, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream, cmath, algorithm

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

void solve() {
    int N, M, K;
    // Read the number of apples (N), oranges (M), and gold coins (K) for the current test case.
    cin >> N >> M >> K;

    // Calculate the initial absolute difference between the number of apples and oranges.
    // Chef wants to minimize this difference.
    int initial_diff = abs(N - M);

    // Chef can spend K gold coins. Each coin can be used to buy one fruit.
    // To reduce the difference, Chef should always buy the fruit type that he has less of.
    // For example, if N > M, he should buy an orange. This increases M by 1, reducing N-M by 1.
    // If M > N, he should buy an apple. This increases N by 1, reducing M-N by 1.
    // In either case, each coin spent optimally reduces the absolute difference by 1.

    // Chef can reduce the difference by at most K.
    // So, the difference after spending K coins would ideally be initial_diff - K.

    // However, the difference cannot be negative. The minimum possible difference is 0.
    // If `initial_diff - K` results in a negative value, it means Chef has enough coins
    // (or more than enough) to make the number of apples and oranges equal.
    // In such a scenario, he can spend exactly `initial_diff` coins to equalize the counts
    // and achieve a difference of 0. He doesn't need to spend any remaining coins.
    // Therefore, the minimum possible difference is the maximum of 0 and `initial_diff - K`.
    
    int min_possible_diff = max(0, initial_diff - K);
    
    // Output the calculated minimum possible difference, followed by a newline.
    cout << min_possible_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard I/O.
    // `cin.tie(NULL)` prevents `cout` from flushing before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t;
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```