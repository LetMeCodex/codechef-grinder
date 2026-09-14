# [Packaging Cupcakes (MUFFINS3)](https://www.codechef.com/problems/MUFFINS3)

- **Difficulty Rating**: 1023
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ cupcakes, we need to choose a package size $A$ (where $1 \le A \le N$) such that the number of leftover cupcakes, calculated as $N \pmod A$, is maximized. If there are multiple package sizes that yield the same maximum remainder, we choose the largest package size among them.

## Intuition & Mathematical Observation
To maximize $N \pmod A$, we want to find an $A$ such that $A$ is just slightly larger than half of $N$.

1.  **Case $N=2$**: $2 \pmod 2 = 0$. The formula $N/2 + 1$ gives $2/2 + 1 = 2$.
2.  **Case $N=5$**: 
    *   $5 \pmod 2 = 1$
    *   $5 \pmod 3 = 2$
    *   $5 \pmod 4 = 1$
    *   $5 \pmod 5 = 0$
    *   The maximum remainder is 2, achieved at $A=3$. Note that $5/2 + 1 = 3$.
3.  **General Logic**: 
    *   If we choose $A = N/2 + 1$, the remainder is $N - (N/2 + 1)$. 
    *   For any $A \le N/2$, the remainder will always be smaller than the remainder obtained by choosing $A = N/2 + 1$. 
    *   Any $A > N/2$ will result in $N \pmod A = N - A$. To maximize this, we need to minimize $A$ such that $A > N/2$. The smallest integer greater than $N/2$ is $\lfloor N/2 \rfloor + 1$.

Thus, the optimal package size is always **$N/2 + 1$**.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to maximize N % A.
 * If we pick A = N/2 + 1, the remainder is N - (N/2 + 1) = (N-1)/2.
 * This is the largest possible remainder we can get for any N.
 * For N=2, N/2 + 1 = 2, 2 % 2 = 0 (Correct).
 * For N=5, 5/2 + 1 = 3, 5 % 3 = 2 (Correct).
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;
        
        // The optimal package size to maximize leftovers is N/2 + 1
        cout << (N / 2) + 1 << "\n";
    }

    return 0;
}
```