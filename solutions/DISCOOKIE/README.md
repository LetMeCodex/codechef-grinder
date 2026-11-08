# [Distribute Cookies (DISCOOKIE)](https://www.codechef.com/problems/DISCOOKIE)
- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of cookies we need to add or remove from an initial `M` cookies such that they can be distributed equally among `N` kids. A crucial constraint is that each kid must receive at least one cookie. We need to output this minimum number of operations (adding or removing a single cookie counts as one operation).

## Intuition & Mathematical Observation

The core requirements are:
1.  The total number of cookies, let's call it `M'`, must be a multiple of `N`.
2.  Each kid must receive at least one cookie. This implies that `M'` must be at least `N` (since `M'/N >= 1`).

Let's analyze the initial number of cookies `M` and the number of kids `N`. The key to solving this problem lies in understanding the remainder when `M` is divided by `N`. Let `rem = M % N`.

**Case 1: `rem == 0`**
If `M` is already a multiple of `N`, then `M` cookies can be distributed equally among `N` kids. Since the problem constraints state `M >= 1` and `N >= 1`, it implies that `M/N` will be at least 1. Thus, each kid will receive `M/N` cookies, satisfying the "at least one cookie" condition. In this scenario, no changes are needed, so the minimum time taken is `0`.

**Case 2: `rem != 0`**
If `M` is not a multiple of `N`, we need to change `M` to some `M'` that is a multiple of `N` and `M' >= N`. We have two primary options:

*   **Option A: Increase cookies to the next multiple of `N`**
    *   The current `M` can be expressed as `(M / N) * N + rem` (where `M / N` is integer division).
    *   The next multiple of `N` is `(M / N + 1) * N`.
    *   The number of cookies to add is `(M / N + 1) * N - M`.
    *   Simplifying this, we get `(M / N * N + N) - (M / N * N + rem) = N - rem`.
    *   This option always results in `M' >= N` because `M / N` is at least 0 (since `M, N >= 1`), so `M / N + 1` is at least 1. Thus, `(M / N + 1) * N` is at least `N`. This option is always valid.
    *   The cost for this option is `N - rem`.

*   **Option B: Decrease cookies to the previous multiple of `N`**
    *   The previous multiple of `N` is `(M / N) * N`.
    *   The number of cookies to remove is `M - (M / N) * N`.
    *   Simplifying this, we get `(M / N * N + rem) - (M / N * N) = rem`.
    *   This option is only valid if the resulting number of cookies, `(M / N) * N`, is at least `N`. This means `M / N` must be at least 1, which implies `M >= N`. If `M < N`, then `M / N` (integer division) is 0, and `(M / N) * N` would be 0. Distributing 0 cookies among `N` kids means each kid gets 0, violating the "at least one cookie" condition.
    *   The cost for this option is `rem`.

**Combining the options for `rem != 0`:**

*   **If `M >= N`**: Both Option A (increase) and Option B (decrease) are valid. We choose the one that requires fewer operations: `min(N - rem, rem)`.
*   **If `M < N`**: Only Option A (increase) is valid. Option B would lead to 0 cookies per kid. In this specific case, `M / N` (integer division) is 0, and `rem` will simply be `M`. So, the cost for Option A becomes `N - M`. This is the only valid choice.

The solution implements this logic directly.

## Complexity Analysis

*   **Time Complexity**: The `solve()` function performs a constant number of arithmetic operations (modulo, division, addition, subtraction) and comparisons. These operations take $O(1)$ time. The `main()` function iterates `T` times, calling `solve()` for each test case. Therefore, the total time complexity is $\mathcal{O}(T)$, where $T$ is the number of test cases.

*   **Space Complexity**: The solution uses a few `long long` variables (`N`, `M`, `rem`, `cost_to_increase`, `cost_to_decrease`) to store input and intermediate calculations. The amount of memory used is constant and does not depend on the magnitude of `N` or `M`. Thus, the space complexity is $\mathcal{O}(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// It's common practice in competitive programming to use the entire std namespace
// to avoid prefixing std:: to every standard library element.
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, M; // N: number of kids, M: initial number of cookies
    cin >> N >> M;

    // Calculate the remainder when M is divided by N.
    // This tells us how many cookies are "left over" if we try to distribute M cookies
    // as evenly as possible without making/destroying.
    long long rem = M % N;

    // If the remainder is 0, M is already a multiple of N.
    // Since M >= 1 and N >= 1 (from constraints), M/N will be an integer and M/N >= 1,
    // so each kid can get M/N cookies.
    // No changes needed, so time taken is 0.
    if (rem == 0) {
        cout << 0 << "\n";
    } else {
        // If rem != 0, M is not a multiple of N. We need to change M.
        // We have two main options to reach a total number of cookies M' that is a multiple of N:

        // Option 1: Increase cookies to the next multiple of N.
        // The current M is (M/N)*N + rem.
        // The next multiple of N is (M/N + 1)*N.
        // The number of cookies per kid would be (M/N + 1). This is always >= 1
        // because M/N is at least 0 (since M, N >= 1), so M/N + 1 is at least 1.
        // The cost for this option is (M/N + 1)*N - M = N - rem.
        long long cost_to_increase = N - rem;

        // Option 2: Decrease cookies to the previous multiple of N.
        // The previous multiple of N is (M/N)*N.
        // The number of cookies per kid would be (M/N).
        // The cost for this option is M - (M/N)*N = rem.
        // This option is only valid if (M/N) >= 1, meaning each kid gets at least 1 cookie.
        // If M < N, then M/N is 0, which means 0 cookies per kid, which is not allowed.

        // Check if decreasing cookies is a valid option (i.e., M/N >= 1).
        // This is equivalent to checking if M >= N.
        if (M >= N) {
            // Both options are valid. We choose the one with minimum cost.
            long long cost_to_decrease = rem;
            cout << min(cost_to_increase, cost_to_decrease) << "\n";
        } else {
            // M < N, so M/N is 0. Decreasing cookies to 0 is not allowed.
            // Only the option to increase cookies is valid.
            // In this case, M/N is 0, so (M/N + 1)*N = N.
            // The cost is N - M (which is N - rem, since rem = M when M < N).
            cout << cost_to_increase << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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