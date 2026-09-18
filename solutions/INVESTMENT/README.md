# Good Investment or Not (INVESTMENT)
- **Difficulty Rating**: 357
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an investment is "good" based on its interest rate ($X$) and the inflation rate ($Y$). An investment is considered "good" if its interest rate is at least twice the inflation rate. We are given $T$ test cases, and for each test case, we receive two integers, $X$ and $Y$. We need to output "YES" if the investment is good, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in translating the definition of a "good" investment into a mathematical condition. The problem statement explicitly states the condition:
"Interest Rate ($X$) >= 2 * Inflation Rate ($Y$)"

Therefore, for each given pair of $X$ and $Y$, we simply need to check if this inequality holds true. If $X \ge 2 \times Y$, the investment is good, and we should print "YES". Otherwise, if $X < 2 \times Y$, the investment is not good, and we should print "NO".

The constraints on $X$ and $Y$ are $1 \le X, Y \le 20$. These are very small values, meaning that the multiplication $2 \times Y$ will not overflow standard integer types. The number of test cases $T$ is up to 400. This suggests that a solution that processes each test case independently and efficiently will pass within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(T)$
    For each of the $T$ test cases, we perform a constant number of operations: reading two integers, performing a multiplication, a comparison, and printing a string. Thus, the total time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the input values ($T$, $X$, $Y$) and loop counters. The amount of memory used does not grow with the input size or the number of test cases. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition for a "good" investment is:
 * Interest Rate (X) >= 2 * Inflation Rate (Y)
 * 
 * Constraints:
 * 1 <= T <= 400
 * 1 <= X, Y <= 20
 * 
 * Since X and Y are small integers, standard integer types are sufficient.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    if (!(cin >> t)) return 0; // Handle potential input errors

    // Process each test case
    while (t--) {
        int x, y;
        // Read the interest rate (X) and inflation rate (Y)
        cin >> x >> y;

        // Check if the interest rate is at least twice the inflation rate
        if (x >= 2 * y) {
            // If the condition is met, it's a good investment
            cout << "YES" << "\n";
        } else {
            // Otherwise, it's not a good investment
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```