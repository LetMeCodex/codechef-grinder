# [Final Population (POPULATION)](https://www.codechef.com/problems/POPULATION)

- **Difficulty Rating**: 358
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the initial population of a town ($X$), the number of people who moved out ($Y$), and the number of people who moved in ($Z$), calculate the final population of the town. The formula for the final population is:
$$\text{Final Population} = X - Y + Z$$

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic operation. We start with an initial value $X$, subtract the outflow $Y$, and add the inflow $Z$. Since the constraints are very small ($X, Y, Z \le 10$), there is no risk of integer overflow, but using `long long` is a safe practice in competitive programming to handle larger potential inputs.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // The final population is the initial population minus those who left,
        // plus those who immigrated.
        long long final_population = x - y + z;
        
        cout << final_population << "\n";
    }

    return 0;
}
```