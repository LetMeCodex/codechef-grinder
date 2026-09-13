# [Sale Season (SALESEASON)](https://www.codechef.com/problems/SALESEASON)

- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the final price of an item after applying a discount based on its original price ($X$). The discount rules are as follows:
- If $X \le 100$, there is no discount.
- If $100 < X \le 1000$, the discount is 25.
- If $1000 < X \le 5000$, the discount is 100.
- If $X > 5000$, the discount is 500.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the price ranges are mutually exclusive and cover all possible values of $X$, we can use an `if-else if-else` ladder to determine the final amount. 

- **Logic**:
    - For $X \le 100$: `final_amount = X`
    - For $100 < X \le 1000$: `final_amount = X - 25`
    - For $1000 < X \le 5000$: `final_amount = X - 100`
    - For $X > 5000$: `final_amount = X - 500`

Using `long long` for the variable $X$ ensures that we handle potential large inputs correctly, although the constraints for this specific problem fit within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons and arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Sale Season
 * Logic: Apply conditional logic based on the value of X to determine the discount.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
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
        
        long long final_amount;
        
        if (x <= 100) {
            final_amount = x;
        } else if (x <= 1000) {
            final_amount = x - 25;
        } else if (x <= 5000) {
            final_amount = x - 100;
        } else {
            final_amount = x - 500;
        }
        
        cout << final_amount << "\n";
    }
    
    return 0;
}
```