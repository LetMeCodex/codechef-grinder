# [Bob at the Bank (BOBBANK)](https://www.codechef.com/problems/BOBBANK)

- **Difficulty Rating**: 481
- **Solved in**: 2 attempt(s)

## Problem Summary
Bob starts with an initial balance of $W$. Every month, he deposits $X$ amount into his bank account and withdraws $Y$ amount. We need to calculate the final balance in Bob's account after $Z$ months.

## Intuition & Mathematical Observation
The problem can be solved using a simple linear equation. 
1. Each month, the net change in the balance is the difference between the deposit and the withdrawal: `Net Change = X - Y`.
2. Over a period of $Z$ months, the total change in the balance is `(X - Y) * Z`.
3. Adding this total change to the initial balance $W$ gives the final result:
   $$\text{Final Balance} = W + (X - Y) \times Z$$

**Constraints Note:** 
Given the constraints ($W, X, Y, Z \le 10^4$), the maximum possible value is approximately $10^8$, which fits comfortably within a standard 32-bit `int`. However, using `long long` is a good practice in competitive programming to prevent potential overflow if constraints were slightly larger.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Initial balance = W
 * Monthly deposit = X
 * Monthly deduction = Y
 * Net change per month = (X - Y)
 * Total change after Z months = (X - Y) * Z
 * Final balance = W + (X - Y) * Z
 */

void solve() {
    long long w, x, y, z;
    if (!(cin >> w >> x >> y >> z)) return;
    
    // Calculate final balance: Initial + (Net Monthly Change * Months)
    long long final_balance = w + (x - y) * z;
    
    cout << final_balance << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }

    return 0;
}
```