# [Equal Coins (EQUALCOIN)](https://www.codechef.com/problems/EQUALCOIN)
- **Difficulty Rating**: 1233
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `X` 1-rupee coins and `Y` 2-rupee coins. He has two sons and wants to distribute all the coins such that both sons receive an equal total amount of money. We need to determine if this is possible and print "YES" or "NO" accordingly.

## Intuition & Mathematical Observation

Let the total amount of money Chef has be $S$.
$S = X \cdot 1 + Y \cdot 2 = X + 2Y$.

For the two sons to receive an equal total amount of money, each son must receive $S/2$ rupees. This implies two crucial conditions:

1.  **The total amount $S$ must be an even number.**
    Since $S = X + 2Y$, and $2Y$ is always an even number, $S$ will be even if and only if $X$ is an even number.
    If $X$ is odd, then $S$ will be odd, making it impossible to divide $S$ equally into two integer amounts. In this case, the answer is "NO".

2.  **If $X$ is even (and thus $S$ is even), it must be possible to form the target amount $S/2$ for each son using the available coins.**
    Each son needs to receive $S/2 = (X + 2Y)/2 = X/2 + Y$ rupees. Let's analyze this based on the value of $X$:

    *   **Case 1: $X = 0$**
        If Chef has no 1-rupee coins, then $X$ is even. Each son needs $0/2 + Y = Y$ rupees.
        Chef only has $Y$ 2-rupee coins. To give $Y$ rupees to each son, he must give $Y/2$ 2-rupee coins to each. This is only possible if $Y$ is an even number.
        *   If $Y$ is even (e.g., $X=0, Y=2$), each son gets one 2-rupee coin, total 2 rupees each. Possible. "YES".
        *   If $Y$ is odd (e.g., $X=0, Y=1$), each son needs 1 rupee, but only 2-rupee coins are available. Impossible. "NO".

    *   **Case 2: $X > 0$ (and $X$ is even, so $X \ge 2$)**
        If Chef has at least two 1-rupee coins, he has enough flexibility to make up any parity difference.
        Each son needs $X/2 + Y$ rupees.
        Consider the total value $V = X + 2Y$. Each son needs $V/2$.
        *   If $Y$ is even: We can give $Y/2$ 2-rupee coins to each son. Then we are left with $X$ 1-rupee coins. Each son still needs $X/2$ rupees. We can give $X/2$ 1-rupee coins to each. This works.
        *   If $Y$ is odd: We have $Y$ 2-rupee coins. We can give $(Y-1)/2$ 2-rupee coins to son 1 and $(Y-1)/2$ 2-rupee coins to son 2. This uses $Y-1$ 2-rupee coins, leaving one 2-rupee coin.
            Now, son 1 has $(Y-1)$ rupees from 2-rupee coins, and son 2 has $(Y-1)$ rupees from 2-rupee coins.
            We are left with $X$ 1-rupee coins and one 2-rupee coin. The total value of these remaining coins is $X+2$.
            Each son still needs $(X/2 + Y) - (Y-1) = X/2 + 1$ rupees from these remaining coins.
            We can give the remaining one 2-rupee coin to one son (say, son 1). Now son 1 has $(Y-1)+2 = Y+1$ rupees from 2-rupee coins, and son 2 has $Y-1$ rupees from 2-rupee coins.
            We have $X$ 1-rupee coins left.
            Son 1 needs $(X/2 + Y) - (Y+1) = X/2 - 1$ more rupees.
            Son 2 needs $(X/2 + Y) - (Y-1) = X/2 + 1$ more rupees.
            Since $X$ is even and $X \ge 2$, $X/2 \ge 1$. We can give $X/2 - 1$ 1-rupee coins to son 1 and $X/2 + 1$ 1-rupee coins to son 2. This uses $(X/2 - 1) + (X/2 + 1) = X$ 1-rupee coins. This distribution is valid.
            Therefore, if $X$ is even and $X > 0$, it's always possible. "YES".

**Combining the conditions:**

*   If $X$ is odd: "NO".
*   If $X$ is even:
    *   If $X=0$: "YES" if $Y$ is even, "NO" if $Y$ is odd.
    *   If $X>0$: "YES".

This can be concisely expressed as: "YES" if `(X is even) AND (Y is even OR X > 0)`. Otherwise, "NO".

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a few constant-time arithmetic operations (modulo, comparison). Since there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a fixed number of integer variables ($X, Y, T$). This results in a constant space complexity of $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    cin >> X >> Y; // Read X (1-rupee coins) and Y (2-rupee coins)

    // The condition for a "YES" answer is:
    // (X is even) AND (Y is even OR X > 0)
    //
    // Explanation:
    // 1. Total value (X + 2Y) must be even for equal distribution.
    //    Since 2Y is always even, (X + 2Y) is even if and only if X is even.
    //    If X is odd, the total value is odd, so it's impossible. Output "NO".
    //
    // 2. If X is even:
    //    Each son needs (X + 2Y) / 2 = X/2 + Y rupees.
    //    a. If X = 0:
    //       Chef only has 2-rupee coins. Each son needs Y rupees.
    //       To form Y rupees using only 2-rupee coins, Y must be even.
    //       If Y is odd (e.g., X=0, Y=1), it's impossible. Output "NO".
    //       If Y is even (e.g., X=0, Y=2), it's possible. Output "YES".
    //    b. If X > 0 (and X is even, so X >= 2):
    //       Chef has at least two 1-rupee coins. This provides enough flexibility
    //       to adjust the parity of the sum for each son. It can be shown that
    //       it's always possible to distribute the coins equally in this scenario.
    //       Output "YES".
    //
    // Combining these:
    // Output "NO" if (X is odd) OR (X is 0 AND Y is odd).
    // Otherwise, output "YES".
    // This is equivalent to:
    // Output "YES" if (X is even) AND (Y is even OR X > 0).

    if (X % 2 == 0) { // X is even
        if (Y % 2 == 0 || X > 0) { // Y is even OR X > 0
            cout << "YES\n";
        } else { // This specific case is X=0 and Y is odd
            cout << "NO\n";
        }
    } else { // X is odd
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```