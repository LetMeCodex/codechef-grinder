# [Existence (EXISTENCE)](https://www.codechef.com/problems/EXISTENCE)
- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem, as implemented by the provided solution code, asks to determine if the equation $X^4 + 4 \cdot Y^2 = 4 \cdot X^2 \cdot Y$ holds true for given positive integers $X$ and $Y$. If it holds, the program should output "YES"; otherwise, it should output "NO".

**Note on Discrepancy:** The CodeChef problem linked, "[Existence (EXISTENCE)](https://www.codechef.com/problems/EXISTENCE)", actually asks a different question: "Determine if there exist two non-negative integers A and B such that A+B=X and A^2+B^2=Y." The provided solution code does *not* correctly solve the problem as stated on CodeChef, as it only checks for a specific sub-case ($X^2=2Y$) which corresponds to $A=B=X/2$. This writeup will explain the logic of the provided code for the problem it *actually* solves (i.e., the algebraic identity check $X^4 + 4 \cdot Y^2 = 4 \cdot X^2 \cdot Y$).

## Intuition & Mathematical Observation

The core of this problem lies in simplifying the given equation: $X^4 + 4 \cdot Y^2 = 4 \cdot X^2 \cdot Y$.

Let's rearrange all terms to one side of the equation:
$X^4 - 4 \cdot X^2 \cdot Y + 4 \cdot Y^2 = 0$

This expression strongly resembles the algebraic identity for squaring a binomial: $(a - b)^2 = a^2 - 2ab + b^2$.
Let's try to match the terms from our rearranged equation to this identity:
1.  The first term is $X^4$. This can be written as $(X^2)^2$. So, we can consider $a = X^2$.
2.  The third term is $4 \cdot Y^2$. This can be written as $(2Y)^2$. So, we can consider $b = 2Y$.

Now, let's check if the middle term, $-4 \cdot X^2 \cdot Y$, matches $-2ab$:
$-2 \cdot (X^2) \cdot (2Y) = -4 \cdot X^2 \cdot Y$.

Indeed, it matches perfectly!
Therefore, the equation $X^4 - 4 \cdot X^2 \cdot Y + 4 \cdot Y^2 = 0$ can be rewritten as:
$(X^2 - 2Y)^2 = 0$

For the square of any real number to be zero, the number itself must be zero. This implies:
$X^2 - 2Y = 0$

Which further simplifies to:
$X^2 = 2Y$

Thus, the original complex equation $X^4 + 4 \cdot Y^2 = 4 \cdot X^2 \cdot Y$ is mathematically equivalent to the much simpler condition $X^2 = 2Y$. The problem then reduces to simply checking if $X \cdot X$ is equal to $2 \cdot Y$.

**Data Type Considerations:**
The problem constraints state that $X$ can be up to $10^9$ and $Y$ up to $10^{18}$.
-   Calculating $X \cdot X$: If $X = 10^9$, then $X \cdot X = (10^9)^2 = 10^{18}$.
-   Calculating $2 \cdot Y$: If $Y = 10^{18}$, then $2 \cdot Y = 2 \cdot 10^{18}$.
Both $10^{18}$ and $2 \cdot 10^{18}$ fit within a `long long` data type in C++ (which typically handles values up to approximately $9 \cdot 10^{18}$). Therefore, it is crucial to use `long long` for variables $X$ and $Y$ to prevent integer overflow during calculations.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a few basic arithmetic operations (one multiplication for $X \cdot X$, one multiplication for $2 \cdot Y$, and one comparison). These operations take a constant amount of time, irrespective of the magnitude of $X$ and $Y$ (within the limits of `long long`). The total time complexity for $T$ test cases would be $O(T)$. Given $T$ up to $10^5$, this approach is highly efficient.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables ($T, X, Y$) to store input and perform calculations. The memory usage does not scale with the input values, resulting in constant space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        long long X, Y; // Declare X and Y as long long to handle large values.
                        // X can be up to 10^9, Y up to 10^18.
                        // X*X can be up to (10^9)^2 = 10^18, which fits in long long.
                        // 2*Y can be up to 2*10^18, which also fits in long long.
        std::cin >> X >> Y; // Read X and Y for the current test case

        // The problem, as implemented by this code, checks the equation:
        // X^4 + 4 * Y^2 = 4 * X^2 * Y
        //
        // Rearranging the equation to one side:
        // X^4 - 4 * X^2 * Y + 4 * Y^2 = 0
        //
        // This expression is a perfect square trinomial of the form (A - B)^2 = A^2 - 2AB + B^2.
        // Let A = X^2 and B = 2*Y.
        //
        // Substituting these into the rearranged equation:
        // (X^2)^2 - 2 * (X^2) * (2*Y) + (2*Y)^2 = 0
        //
        // This simplifies to:
        // (X^2 - 2*Y)^2 = 0
        //
        // For the square of a real number to be zero, the number itself must be zero:
        // X^2 - 2*Y = 0
        //
        // Which further simplifies to:
        // X^2 = 2*Y

        // So, the problem reduces to checking if X*X is equal to 2*Y.
        if (X * X == 2 * Y) {
            std::cout << "YES\n"; // If the condition holds, print YES
        } else {
            std::cout << "NO\n"; // Otherwise, print NO
        }
    }

    return 0; // Indicate successful program execution
}
```