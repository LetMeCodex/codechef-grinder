# Coins And Triangle (TRICOIN)

- **Difficulty Rating**: 1075
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible height of a triangle that can be formed using at most $N$ coins. A triangle of height $h$ is formed by stacking rows of coins, where the $i$-th row (from the top, 1-indexed) has $i$ coins. Thus, a triangle of height $h$ requires $1 + 2 + \dots + h$ coins.

## Intuition & Mathematical Observation

The total number of coins required to form a triangle of height $h$ is the sum of the first $h$ positive integers, which is given by the formula:
$$ \text{Coins}(h) = \frac{h(h+1)}{2} $$

We are given a total of $N$ coins and we want to find the largest integer $h$ such that $\text{Coins}(h) \le N$.
$$ \frac{h(h+1)}{2} \le N $$
$$ h(h+1) \le 2N $$

Since $h(h+1)$ is an increasing function for positive $h$, we can observe that if a height $h$ is achievable, any height less than $h$ is also achievable. This monotonicity suggests that we can use binary search to find the maximum possible height.

We need to search for the optimal height $h$ within a certain range.
- The minimum possible height is $0$ (or $1$ if we consider a non-empty triangle).
- For the maximum possible height, let's consider the upper bound. If $h(h+1) \approx h^2$, then $h^2 \le 2N$, which means $h \le \sqrt{2N}$. Given $N \le 10^9$, $2N \le 2 \times 10^9$, and $\sqrt{2 \times 10^9} \approx \sqrt{20 \times 10^8} \approx 4.47 \times 10^4$. So, a height around $45000$ is expected. A safe upper bound for binary search could be $200000$ to ensure that $mid \times (mid+1)$ does not overflow `long long` and to comfortably cover the possible range of $h$.

The binary search will work as follows:
1. Initialize `low = 0` and `high = 200000` (a safe upper bound).
2. While `low <= high`:
   a. Calculate `mid = low + (high - low) / 2`.
   b. Calculate the number of coins needed for a triangle of height `mid`: `coins_needed = mid * (mid + 1) / 2`.
   c. If `coins_needed <= n`:
      This `mid` height is achievable. We store `mid` as a potential answer (`ans = mid`) and try to find a larger height by searching in the upper half: `low = mid + 1`.
   d. If `coins_needed > n`:
      This `mid` height is not achievable. We need to try a smaller height by searching in the lower half: `high = mid - 1`.
3. The final value of `ans` will be the maximum possible height.

**Important Note on Data Types**:
The input $N$ can be up to $10^9$, which fits in a standard `int`. However, when calculating `mid * (mid + 1) / 2`, if `mid` is around $45000$, then `mid * (mid + 1)` can be approximately $45000^2 \approx 2 \times 10^9$. If `mid` were larger (e.g., close to our upper bound of $200000$), `mid * (mid + 1)` could be up to $200000 \times 200001 \approx 4 \times 10^{10}$. This value exceeds the capacity of a 32-bit integer (`int`), which typically goes up to $2 \times 10^9$. Therefore, `mid` and `coins_needed` must be `long long` to prevent overflow.

## Complexity Analysis

- **Time Complexity**: $O(\log(\text{MAX_H}))$, where $\text{MAX_H}$ is the upper bound for our binary search (e.g., $200000$). This is because binary search halves the search space in each step. For a fixed upper bound, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the state of the binary search and the input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, etc.

using namespace std; // Use standard namespace

void solve() {
    int n; // N up to 10^9 fits in a standard 32-bit integer
    cin >> n;

    long long low = 0; // Minimum possible height
    // A safe upper bound for h. For N=10^9, h is approx 45000.
    // 200000 is a generous upper bound that ensures mid * (mid+1) fits in long long.
    long long high = 200000; 
    long long ans = 0; // Stores the maximum valid height found

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Calculate coins needed for a triangle of height 'mid'.
        // mid * (mid + 1) can be up to 200000 * 200001 approx 4 * 10^10,
        // which requires a long long to prevent overflow.
        long long coins_needed = mid * (mid + 1) / 2;

        if (coins_needed <= n) {
            // If 'mid' height is possible with 'n' coins,
            // it's a candidate for the answer. Try to find a higher height.
            ans = mid;
            low = mid + 1;
        } else {
            // If 'mid' height requires too many coins,
            // we need to try a smaller height.
            high = mid - 1;
        }
    }
    cout << ans << "\n"; // Output the maximum possible height
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```