# [Four Tickets (FOURTICKETS)](https://www.codechef.com/problems/FOURTICKETS)

- **Difficulty Rating**: 302
- **Solved in**: 1 attempt(s)

## Problem Summary
There are 4 friends who want to go to a concert. Each ticket costs $X$ rupees. The group can afford to go if the total cost of the 4 tickets is less than or equal to 1000 rupees. Given $X$, determine if they can afford the tickets.

## Intuition & Mathematical Observation
The problem asks us to evaluate a simple inequality. Since there are 4 friends and each ticket costs $X$, the total cost is calculated as:
$$\text{Total Cost} = 4 \times X$$

The condition for the group to attend the concert is:
$$4 \times X \le 1000$$

We simply need to read the input $X$ for each test case, compute the product, and check if it satisfies the condition. If it does, output "YES"; otherwise, output "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated cost, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 4 friends, each ticket costs X.
 * Total cost = 4 * X.
 * Condition to go: Total cost <= 1000.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X <= 1000
 * Max total cost = 4 * 1000 = 4000, which fits in a standard 32-bit integer.
 * Using long long is safe practice for competitive programming.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate total cost
        long long total_cost = 4 * x;
        
        // Check condition
        if (total_cost <= 1000) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```