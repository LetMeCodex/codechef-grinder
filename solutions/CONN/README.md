# [Construct N (CONN)](https://www.codechef.com/problems/CONN)
- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, determine if it's possible to express $N$ as a sum of some number of 2s and some number of 7s. In other words, can we find non-negative integers $X$ and $Y$ such that $2 \cdot X + 7 \cdot Y = N$?

## Intuition & Mathematical Observation
The problem asks us to determine if a given integer $N$ can be represented in the form $2X + 7Y$, where $X \ge 0$ and $Y \ge 0$ are integers. This is a classic example of a linear Diophantine equation with the additional constraint that the variables must be non-negative.

We can rephrase the problem as: for a given $N$, can we find a non-negative integer $Y$ such that $N - 7Y$ is a non-negative even number? If $N - 7Y$ is a non-negative even number, let's call it $R$. Then we can set $X = R/2$, and since $R$ is non-negative and even, $X$ will be a non-negative integer.

To check this, we can iterate through all possible non-negative values of $Y$. What is the maximum possible value for $Y$? Since $7Y$ must be less than or equal to $N$ (because $2X \ge 0$), the maximum value $Y$ can take is $N/7$.

So, we can iterate $Y$ from $0$ up to $N/7$. For each value of $Y$, we calculate `remaining = N - 7 * Y`. If `remaining` is non-negative and `remaining % 2 == 0`, then we have found a valid pair $(X, Y)$, and the answer is "YES". If we iterate through all possible values of $Y$ and do not find such a `remaining` value, then it's impossible to construct $N$, and the answer is "NO".

Let's consider some small values of $N$:
- $N=1$: $2X+7Y=1$. No non-negative $X, Y$ satisfy this. (NO)
- $N=2$: $2(1)+7(0)=2$. (YES)
- $N=3$: $2X+7Y=3$. No non-negative $X, Y$ satisfy this. (NO)
- $N=4$: $2(2)+7(0)=4$. (YES)
- $N=5$: $2(1)+7(0)=2$, $2(0)+7(0)=0$. $2X+7Y=5$. No non-negative $X, Y$ satisfy this. (NO)
- $N=6$: $2(3)+7(0)=6$. (YES)
- $N=7$: $2(0)+7(1)=7$. (YES)
- $N=8$: $2(4)+7(0)=8$. (YES)
- $N=9$: $2(1)+7(1)=9$. (YES)
- $N=10$: $2(5)+7(0)=10$. (YES)
- $N=11$: $2(2)+7(1)=11$. (YES)
- $N=12$: $2(6)+7(0)=12$. (YES)
- $N=13$: $2(3)+7(1)=13$. (YES)
- $N=14$: $2(7)+7(0)=14$ or $2(0)+7(2)=14$. (YES)

The smallest numbers that cannot be formed are 1, 3, 5. It seems that all numbers greater than or equal to 6 can be formed. This is related to the Frobenius Coin Problem. For two coin denominations $a$ and $b$ that are coprime, the largest number that cannot be expressed in the form $aX + bY$ for non-negative integers $X, Y$ is $ab - a - b$. For 2 and 7, this is $2 \cdot 7 - 2 - 7 = 14 - 9 = 5$. So, any integer greater than 5 can be formed. This confirms our observation.

However, the iterative approach is simple and efficient enough for the given constraints.

## Complexity Analysis
- **Time Complexity**: The loop iterates from $y=0$ to $N/7$. In each iteration, we perform constant time operations (subtraction, multiplication, modulo). Therefore, the time complexity for each test case is $O(N/7)$, which simplifies to $O(N)$. Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$. Given the constraints on $N$ (up to $10^9$), this might be too slow if $N$ is large for many test cases. However, the problem statement usually implies that $N$ is within reasonable bounds for typical competitive programming problems where $O(N)$ per test case is acceptable if $N$ is up to $10^5$ or $10^6$. If $N$ can be $10^9$, then a more optimized approach would be needed. Let's re-examine the constraints. If $N$ is up to $10^9$, then $O(N)$ per test case is definitely too slow.

    Let's reconsider the constraints. The problem is rated 860, which is typically in the "easy" to "medium-easy" range. An $O(N)$ solution per test case where $N$ can be $10^9$ would be too slow. This suggests that either $N$ is not that large in practice for this problem, or there's a mathematical shortcut.

    The mathematical observation about the Frobenius number suggests that for $N > 5$, the answer is always YES. We only need to check for small values of $N$.
    The numbers that *cannot* be formed are: 1, 3, 5.
    All other non-negative integers can be formed.
    So, if $N=1$, $N=3$, or $N=5$, the answer is NO. Otherwise, the answer is YES.

    This optimized approach would have a time complexity of $O(1)$ per test case.

    Let's verify the provided solution code. The code implements the iterative approach.
    ```cpp
    for (int y = 0; y * 7 <= n; ++y) {
        int remaining = n - y * 7;
        if (remaining >= 0 && remaining % 2 == 0) {
            possible = true;
            break;
        }
    }
    ```
    If $N$ can be up to $10^9$, this loop will run up to $10^9 / 7 \approx 1.4 \times 10^8$ times. This is too slow for a typical time limit of 1-2 seconds.

    **Correction based on typical competitive programming problem constraints and difficulty:**
    Given the difficulty rating (860) and the common constraints for such problems, it's highly probable that $N$ is not intended to be $10^9$ for this problem, or there's a misunderstanding of the typical constraints for this rating. If $N$ were up to $10^5$ or $10^6$, the $O(N)$ solution would be acceptable.

    However, if we strictly adhere to the possibility of $N$ being $10^9$, the $O(1)$ solution based on the Frobenius number is the correct one. The provided solution code, while logically correct for the problem statement, might time out if $N$ is indeed very large.

    Let's assume for the purpose of this writeup that the iterative solution is what was intended or that the test cases don't push $N$ to its absolute maximum for the $O(N)$ approach. If the problem setter intended $N$ up to $10^9$, then the $O(1)$ solution is the only viable one.

    **Revisiting the provided solution's complexity:**
    The loop runs at most $N/7 + 1$ times.
    Time Complexity: $O(N)$ per test case.
    Space Complexity: $O(1)$ per test case (uses a few variables).

    **If $N$ can be up to $10^9$, the correct complexity analysis for the *intended* solution would be $O(1)$ per test case.**
    The $O(1)$ solution would be:
    ```cpp
    #include <iostream>

    int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int t;
        std::cin >> t;
        while (t--) {
            int n;
            std::cin >> n;
            if (n == 1 || n == 3 || n == 5) {
                std::cout << "NO\n";
            } else {
                std::cout << "YES\n";
            }
        }
        return 0;
    }
    ```
    This $O(1)$ solution is much more likely to pass if $N$ can be very large.

    Since the provided solution code is the iterative one, we will analyze its complexity.

- **Time Complexity**: $O(N)$ per test case. The loop runs approximately $N/7$ times.
- **Space Complexity**: $O(1)$ per test case. The solution uses a constant amount of extra space for variables like `t`, `n`, `possible`, `y`, and `remaining`.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // The target number to construct
        std::cin >> n;

        bool possible = false; // Flag to indicate if N can be constructed

        // We want to find non-negative integers X and Y such that 2*X + 7*Y = N.
        // This equation can be rewritten as 2*X = N - 7*Y.
        // For a solution to exist, N - 7*Y must be:
        // 1. Non-negative (since 2*X must be non-negative).
        // 2. Even (since 2*X is always even).
        //
        // We can iterate through possible values of Y.
        // Since 7*Y must be less than or equal to N (because 2*X >= 0),
        // the maximum value of Y we need to check is N/7.
        // We start Y from 0 and go up to N/7.
        for (int y = 0; y * 7 <= n; ++y) {
            int remaining = n - y * 7; // Calculate the value that should be 2*X

            // Check if the 'remaining' value satisfies the conditions:
            // 1. remaining >= 0: Ensures that 2*X is non-negative.
            // 2. remaining % 2 == 0: Ensures that 'remaining' is an even number,
            //    so it can be represented as 2*X for some integer X.
            if (remaining >= 0 && remaining % 2 == 0) {
                possible = true; // We found a valid combination of X and Y
                break;           // No need to check further for this N
            }
        }

        // Output the result based on whether a solution was found
        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```