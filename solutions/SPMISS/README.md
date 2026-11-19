# [Special Missions (SPMISS)](https://www.codechef.com/problems/SPMISS)
- **Difficulty Rating**: 1026
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of coins we can obtain by completing missions. We are given `N` missions, each with a reward `A[i]`. Additionally, we are given a string `S` of length `N`, where `S[i] == '0'` indicates a "non-special" mission and `S[i] == '1'` indicates a "special" mission.

We can always complete non-special missions. However, to complete any special mission, we must first pay a wizard fee `C`. This fee can only be paid if we currently possess at least `C` coins. We want to maximize our final coin count.

## Intuition & Mathematical Observation

The problem presents a clear choice: either pay the wizard fee or don't. This suggests we should evaluate both scenarios and pick the one that yields the maximum coins.

Let's analyze the two main scenarios:

1.  **Do not pay the wizard fee:**
    If we choose not to pay the wizard fee, we are restricted to completing only the non-special missions. In this case, the total coins we can obtain will be the sum of rewards `A[i]` for all missions where `S[i] == '0'`. Let's call this `sum_non_special`. This is our baseline maximum if we don't engage with the special missions.

2.  **Consider paying the wizard fee:**
    To pay the wizard fee `C`, we must have at least `C` coins *before* paying. The only way to earn coins without having paid the fee is by completing non-special missions. Therefore, we can only afford to pay the fee if `sum_non_special >= C`.
    *   If `sum_non_special < C`, we cannot afford the fee, so this scenario is impossible.
    *   If `sum_non_special >= C`, we *can* pay the fee. Once the fee is paid, we gain the ability to complete *all* missions (both non-special and special). The total coins we would accumulate from all missions is the sum of all `A[i]`. Let's call this `sum_all_missions`. After paying the fee, our net coins would be `sum_all_missions - C`.

**Combining these observations:**

*   First, calculate `sum_non_special` (sum of rewards for `S[i] == '0'`) and `sum_all_missions` (sum of rewards for all `A[i]`).
*   Initialize our `max_coins` with `sum_non_special` (this covers Scenario 1).
*   Then, check if we can afford to pay the fee: `if (sum_non_special >= C)`.
    *   If yes, calculate the coins from Scenario 2: `sum_all_missions - C`.
    *   Update `max_coins = max(max_coins, sum_all_missions - C)`.
*   The final `max_coins` will be our answer.

The problem constraints ($N \le 10^5$, $A[i] \le 10^3$) mean that `sum_all_missions` could be up to $10^5 \times 10^3 = 10^8$. This fits within a standard 32-bit integer. However, using `long long` for sums and `C` is a good practice to prevent potential overflow issues, especially in competitive programming where constraints can sometimes be tricky or slightly larger than expected. The provided solution correctly uses `long long`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`, `C`, `A` (vector), and `S` (string) takes $O(N)$ time.
    *   The loop to calculate `sum_non_special` and `sum_all_missions` iterates `N` times, performing constant time operations in each iteration. This takes $O(N)$ time.
    *   The final comparison and `max` operation take $O(1)$ time.
    *   Therefore, for a single test case, the time complexity is $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing the mission rewards in `vector<int> A` requires $O(N)$ space.
    *   Storing the mission types in `string S` requires $O(N)$ space.
    *   All other variables (`N`, `C`, `sum_non_special`, `sum_all_missions`, `max_coins`) use $O(1)$ space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    long long C; // Using long long for C and sums to be safe, though int is sufficient given constraints.
    cin >> N >> C;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    string S;
    cin >> S;

    long long sum_non_special = 0;
    long long sum_all_missions = 0;

    // Calculate sum of all mission rewards and sum of non-special mission rewards
    for (int i = 0; i < N; ++i) {
        sum_all_missions += A[i];
        if (S[i] == '0') { // If it's a non-special mission
            sum_non_special += A[i];
        }
    }

    // Scenario 1: Do not pay the wizard fee.
    // In this case, we can only complete non-special missions.
    // The maximum coins obtained is the sum of rewards from all non-special missions.
    long long max_coins = sum_non_special;

    // Scenario 2: Consider paying the wizard fee.
    // To pay the fee, we must have at least C coins.
    // The best way to accumulate coins before paying the fee is by completing all non-special missions.
    if (sum_non_special >= C) {
        // If we have enough coins from non-special missions, we can pay the fee.
        // After paying, we can complete all missions (both non-special and special).
        // The total coins would be (sum of all A_i) - C.
        // We take the maximum between this and not paying the fee.
        max_coins = max(max_coins, sum_all_missions - C);
    }
    
    // Output the maximum coins obtainable for the current test case.
    cout << max_coins << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```