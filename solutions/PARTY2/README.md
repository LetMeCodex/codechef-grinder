# [Chef gives Party (PARTY2)](https://www.codechef.com/problems/PARTY2)

- **Difficulty Rating**: 363
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to host a party for $N$ friends. Each friend consumes one burger, and each burger costs $X$ rupees. Chef currently has $K$ rupees in his pocket. We need to determine if Chef has enough money to pay for all the burgers required for his friends.

## Intuition & Mathematical Observation
The total cost of the party is calculated by multiplying the number of friends ($N$) by the cost per burger ($X$). 
- Total Cost = $N \times X$

Chef can afford the party if his total money ($K$) is greater than or equal to the total cost.
- Condition: $N \times X \le K$

If the condition holds true, output `YES`; otherwise, output `NO`. Given the constraints ($N, X \le 100$ and $K \le 10000$), the maximum possible cost is $10,000$, which comfortably fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple multiplication and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N friends and each burger costs X.
 * Total cost required = N * X.
 * Chef has K rupees.
 * Chef can afford the party if (N * X) <= K.
 * 
 * Constraints:
 * N, X <= 100
 * K <= 10000
 * N * X max value is 100 * 100 = 10000.
 * Since 10000 fits in a standard 32-bit integer, 'int' is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;
        
        // Calculate total cost
        long long total_cost = n * x;
        
        // Check if Chef has enough money
        if (total_cost <= k) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```