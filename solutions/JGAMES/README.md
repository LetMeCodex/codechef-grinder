# [Janmansh and Games (JGAMES)](https://www.codechef.com/problems/JGAMES)
- **Difficulty Rating**: 772
- **Solved in**: 1 attempt(s)

## Problem Summary
Janmansh starts with an integer $X$. He and Jay take turns modifying $X$. In each turn, a player can either increment or decrement $X$ by 1. Janmansh goes first. They play a total of $Y$ moves. Janmansh wins if the final value of $X$ is even, and Jay wins if the final value of $X$ is odd. Both players play optimally.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the parity of the number $X$ changes with each move and how the total number of moves $Y$ influences the final parity.

Each move consists of either adding 1 or subtracting 1 from $X$.
- If $X$ is even, adding or subtracting 1 makes it odd.
- If $X$ is odd, adding or subtracting 1 makes it even.

This means that every single move flips the parity of $X$.

Let's consider the initial parity of $X$ and the total number of moves $Y$.
Suppose the initial parity of $X$ is $P_{initial}$ (0 for even, 1 for odd).
After 1 move, the parity becomes $P_{initial} \oplus 1$.
After 2 moves, the parity becomes $(P_{initial} \oplus 1) \oplus 1 = P_{initial}$.
After $k$ moves, the parity becomes $P_{initial} \oplus (k \pmod 2)$.

Therefore, after $Y$ moves, the parity of the final number, $P_{final}$, will be:
$P_{final} = P_{initial} \oplus (Y \pmod 2)$

This can be expressed using the modulo operator:
$P_{final} = (X \pmod 2 + Y \pmod 2) \pmod 2$

Now, let's analyze the winning conditions:
- Janmansh wins if the final number is even ($P_{final} = 0$).
- Jay wins if the final number is odd ($P_{final} = 1$).

Janmansh wins if $(X \pmod 2 + Y \pmod 2) \pmod 2 = 0$.
This condition is met in two scenarios:
1. $X$ is even ($X \pmod 2 = 0$) AND $Y$ is even ($Y \pmod 2 = 0$).
   $(0 + 0) \pmod 2 = 0$.
2. $X$ is odd ($X \pmod 2 = 1$) AND $Y$ is odd ($Y \pmod 2 = 1$).
   $(1 + 1) \pmod 2 = 0$.

In both these scenarios, $X \pmod 2$ is equal to $Y \pmod 2$.
So, Janmansh wins if $X$ and $Y$ have the same parity.

Conversely, Jay wins if $(X \pmod 2 + Y \pmod 2) \pmod 2 = 1$.
This condition is met in two scenarios:
1. $X$ is even ($X \pmod 2 = 0$) AND $Y$ is odd ($Y \pmod 2 = 1$).
   $(0 + 1) \pmod 2 = 1$.
2. $X$ is odd ($X \pmod 2 = 1$) AND $Y$ is even ($Y \pmod 2 = 0$).
   $(1 + 0) \pmod 2 = 1$.

In both these scenarios, $X \pmod 2$ is not equal to $Y \pmod 2$.
So, Jay wins if $X$ and $Y$ have different parities.

The mention of "optimal play" might seem confusing, but since each move strictly flips the parity, and players can always choose to increment or decrement, they cannot alter the fact that after $Y$ moves, the parity is fixed based on the initial parity of $X$ and the parity of $Y$. The players don't have a strategic choice that can change the final parity outcome; they can only influence *which* specific number with that parity is reached, but the problem only cares about the parity itself.

Therefore, the winner is determined solely by the parities of $X$ and $Y$.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case.
  The solution involves a few arithmetic operations (modulo, comparison) which take constant time. Since there are $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$ per test case.
  The solution uses a fixed amount of memory for variables like $t, x, y$, regardless of the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, y; // Initial number X and total moves Y
        std::cin >> x >> y;

        // The parity of the final number is determined by the parity of X and Y.
        // Each move flips the parity. After Y moves, the final parity is:
        // initial_parity(X) XOR parity(Y)
        // which is equivalent to (X % 2 + Y % 2) % 2.

        // Janmansh wins if the final number is even (parity is 0).
        // Jay wins if the final number is odd (parity is 1).

        // Janmansh wins if (X % 2 + Y % 2) % 2 == 0.
        // This occurs when X % 2 == Y % 2 (i.e., X and Y have the same parity).
        // If X is even and Y is even: (0 + 0) % 2 = 0 (Janmansh wins)
        // If X is odd and Y is odd: (1 + 1) % 2 = 0 (Janmansh wins)

        // Jay wins if (X % 2 + Y % 2) % 2 == 1.
        // This occurs when X % 2 != Y % 2 (i.e., X and Y have different parities).
        // If X is even and Y is odd: (0 + 1) % 2 = 1 (Jay wins)
        // If X is odd and Y is even: (1 + 0) % 2 = 1 (Jay wins)

        if ((x % 2) == (y % 2)) {
            // X and Y have the same parity, so the final number will be even.
            std::cout << "Janmansh\n";
        } else {
            // X and Y have different parities, so the final number will be odd.
            std::cout << "Jay\n";
        }
    }
    return 0;
}
```