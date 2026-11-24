# Even Sum (EVENGAME)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a game played by two players, Player 1 and Player 2, involving a list of $N$ given integers. Both players take turns assigning a sign ($+$ or $-$) to each of the $N$ numbers. Player 1 goes first. After all numbers have been assigned a sign, the sum of these signed numbers is calculated. Player 1 wins if the final sum is even, and Player 2 wins if the final sum is odd. We need to determine the winner assuming optimal play.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the signs assigned by the players affect the parity of the final sum. Let the given numbers be $A_1, A_2, \dots, A_N$. The final sum will be $S = \sum_{i=1}^N \text{sign}_i \cdot A_i$, where $\text{sign}_i \in \{+1, -1\}$.

We are interested in the parity of $S$, i.e., $S \pmod 2$.
The parity of a sum is determined by the parity of its terms.
$S \pmod 2 = \left(\sum_{i=1}^N \text{sign}_i \cdot A_i\right) \pmod 2$.

Consider the contribution of an even number $A_i$ to the sum's parity.
If $A_i$ is even, then $A_i \pmod 2 = 0$.
So, $(\text{sign}_i \cdot A_i) \pmod 2 = (\text{sign}_i \cdot 0) \pmod 2 = 0$.
This means that even numbers, regardless of the sign assigned to them, do not affect the parity of the final sum.

Now, consider the contribution of an odd number $A_i$ to the sum's parity.
If $A_i$ is odd, then $A_i \pmod 2 = 1$.
So, $(\text{sign}_i \cdot A_i) \pmod 2 = (\text{sign}_i \cdot 1) \pmod 2 = \text{sign}_i \pmod 2$.
If $\text{sign}_i = +1$, its contribution to parity is $1 \pmod 2 = 1$.
If $\text{sign}_i = -1$, its contribution to parity is $-1 \pmod 2 = 1$.
Wait, this is incorrect. $-1 \pmod 2$ is $1$ in modular arithmetic, but we are interested in the actual value of the sign.
Let's rephrase:
$(\text{sign}_i \cdot A_i) \pmod 2 = (\text{sign}_i \pmod 2 \cdot A_i \pmod 2) \pmod 2$.
If $A_i$ is odd, $A_i \pmod 2 = 1$.
So, $(\text{sign}_i \cdot A_i) \pmod 2 = (\text{sign}_i \pmod 2 \cdot 1) \pmod 2 = \text{sign}_i \pmod 2$.
This is still not quite right. The issue is that $\text{sign}_i$ is either $+1$ or $-1$.
Let's look at the sum modulo 2 directly:
$S \pmod 2 = \left(\sum_{\text{even } A_i} \text{sign}_i \cdot A_i + \sum_{\text{odd } A_i} \text{sign}_i \cdot A_i\right) \pmod 2$.
Since $\text{sign}_i \cdot A_i \pmod 2 = 0$ for even $A_i$, the sum simplifies to:
$S \pmod 2 = \left(\sum_{\text{odd } A_i} \text{sign}_i \cdot A_i\right) \pmod 2$.

Let $O$ be the set of indices $i$ where $A_i$ is odd. Let $|O|$ be the count of odd numbers.
$S \pmod 2 = \left(\sum_{i \in O} \text{sign}_i \cdot A_i\right) \pmod 2$.
Since $A_i$ is odd for $i \in O$, $A_i \equiv 1 \pmod 2$.
So, $\text{sign}_i \cdot A_i \equiv \text{sign}_i \cdot 1 \pmod 2 \equiv \text{sign}_i \pmod 2$.
This means the parity of $\text{sign}_i \cdot A_i$ is the same as the parity of $\text{sign}_i$.
If $\text{sign}_i = +1$, then $\text{sign}_i \cdot A_i$ is odd.
If $\text{sign}_i = -1$, then $\text{sign}_i \cdot A_i$ is odd.
This is still not the right way to think about it.

Let's consider the sum of the parities of the terms:
$S \pmod 2 = \left(\sum_{i=1}^N (\text{sign}_i \cdot A_i \pmod 2)\right) \pmod 2$.
If $A_i$ is even, $A_i \pmod 2 = 0$, so $\text{sign}_i \cdot A_i \pmod 2 = 0$.
If $A_i$ is odd, $A_i \pmod 2 = 1$.
Then $\text{sign}_i \cdot A_i \pmod 2 = (\text{sign}_i \pmod 2 \cdot A_i \pmod 2) \pmod 2 = (\text{sign}_i \pmod 2 \cdot 1) \pmod 2 = \text{sign}_i \pmod 2$.
This is still problematic because $\text{sign}_i$ is $+1$ or $-1$.

Let's use the property that $x \pmod 2 = y \pmod 2$ if and only if $x-y$ is even.
$S = \sum \text{sign}_i A_i$.
$S \pmod 2 = \left(\sum \text{sign}_i A_i\right) \pmod 2$.
Consider the sum of the absolute values: $\sum |A_i|$.
$S = \sum \text{sign}_i A_i$.
$S - \sum A_i = \sum (\text{sign}_i - 1) A_i$.
If $\text{sign}_i = +1$, $(\text{sign}_i - 1) = 0$.
If $\text{sign}_i = -1$, $(\text{sign}_i - 1) = -2$.
So, $S - \sum A_i = \sum_{i \text{ where } \text{sign}_i = -1} (-2) A_i$.
This difference is always even.
Therefore, $S \equiv \sum A_i \pmod 2$.

This is a crucial simplification! The parity of the final sum $S$ is the same as the parity of the sum of the original numbers $\sum A_i$.
The parity of $\sum A_i$ is determined by the number of odd numbers in the list.
$\sum A_i \pmod 2 = (\text{count of odd numbers}) \pmod 2$.

Let `odd_count` be the number of odd integers in the input list.
The parity of the final sum $S$ will be `odd_count % 2`.

- If `odd_count` is even, then $\sum A_i$ is even, and thus $S$ will always be even. Player 1 wins.
- If `odd_count` is odd, then $\sum A_i$ is odd, and thus $S$ will always be odd. Player 2 wins.

The players take turns assigning signs. Player 1 goes first. There are $N$ numbers, so $N$ turns in total.
Player 1 makes $\lceil N/2 \rceil$ moves.
Player 2 makes $\lfloor N/2 \rfloor$ moves.

However, the observation $S \equiv \sum A_i \pmod 2$ means that the final parity is *independent* of the signs chosen by the players. The players are essentially playing a game where the outcome is predetermined by the initial input. The game mechanics of taking turns assigning signs become irrelevant to determining the winner.

The winner is solely determined by the parity of the count of odd numbers.

Let's re-verify this.
Suppose we have numbers $A_1, A_2, \dots, A_N$.
The sum is $S = \sigma_1 A_1 + \sigma_2 A_2 + \dots + \sigma_N A_N$, where $\sigma_i \in \{+1, -1\}$.
We want to know $S \pmod 2$.
$S \pmod 2 = (\sigma_1 A_1 \pmod 2 + \sigma_2 A_2 \pmod 2 + \dots + \sigma_N A_N \pmod 2) \pmod 2$.

If $A_i$ is even, $A_i \pmod 2 = 0$. So $\sigma_i A_i \pmod 2 = 0$.
If $A_i$ is odd, $A_i \pmod 2 = 1$. So $\sigma_i A_i \pmod 2 = (\sigma_i \cdot 1) \pmod 2$.
If $\sigma_i = +1$, then $\sigma_i A_i \pmod 2 = 1 \pmod 2 = 1$.
If $\sigma_i = -1$, then $\sigma_i A_i \pmod 2 = -1 \pmod 2 = 1$.
This is still leading to the same confusion.

Let's use the property: $a \equiv b \pmod m \iff a-b$ is divisible by $m$.
$S = \sum \sigma_i A_i$.
Consider the sum of original numbers: $S_{orig} = \sum A_i$.
$S - S_{orig} = \sum \sigma_i A_i - \sum A_i = \sum (\sigma_i - 1) A_i$.
If $\sigma_i = +1$, then $\sigma_i - 1 = 0$. The term is $0 \cdot A_i = 0$.
If $\sigma_i = -1$, then $\sigma_i - 1 = -2$. The term is $-2 \cdot A_i$.
So, $S - S_{orig} = \sum_{\text{where } \sigma_i = -1} (-2) A_i$.
This sum is always an even number, as it's a sum of multiples of 2.
Therefore, $S - S_{orig}$ is even.
This implies $S \equiv S_{orig} \pmod 2$.

The parity of the final sum $S$ is the same as the parity of the sum of the original numbers $S_{orig}$.
The parity of $S_{orig} = \sum A_i$ is determined by the number of odd terms in the sum.
$S_{orig} \pmod 2 = (\text{count of odd } A_i) \pmod 2$.

Let `odd_count` be the number of odd integers in the input.
If `odd_count` is even, $S_{orig}$ is even, so $S$ is even. Player 1 wins.
If `odd_count` is odd, $S_{orig}$ is odd, so $S$ is odd. Player 2 wins.

The players' turns and optimal play are irrelevant because the outcome is fixed by the input. The problem is simply asking us to count the odd numbers and determine the winner based on the parity of that count.

Example:
N = 3, numbers = [2, 3, 4]
odd_count = 1 (only 3 is odd)
Since odd_count is odd, Player 2 should win.
Let's trace:
Player 1 assigns sign to 2.
Player 2 assigns sign to 3.
Player 1 assigns sign to 4.

Possible sums:
If all signs are +: 2 + 3 + 4 = 9 (odd)
If signs are +, +, -: 2 + 3 - 4 = 1 (odd)
If signs are +, -, +: 2 - 3 + 4 = 3 (odd)
If signs are +, -, -: 2 - 3 - 4 = -5 (odd)
If signs are -, +, +: -2 + 3 + 4 = 5 (odd)
If signs are -, +, -: -2 + 3 - 4 = -3 (odd)
If signs are -, -, +: -2 - 3 + 4 = -1 (odd)
If signs are -, -, -: -2 - 3 - 4 = -9 (odd)

In all cases, the sum is odd. Player 2 wins. This matches our logic.

Example:
N = 2, numbers = [3, 5]
odd_count = 2 (both 3 and 5 are odd)
Since odd_count is even, Player 1 should win.
Possible sums:
If signs are +, +: 3 + 5 = 8 (even)
If signs are +, -: 3 - 5 = -2 (even)
If signs are -, +: -3 + 5 = 2 (even)
If signs are -, -: -3 - 5 = -8 (even)

In all cases, the sum is even. Player 1 wins. This matches our logic.

The logic seems solid. The problem is simpler than it appears due to the property $S \equiv \sum A_i \pmod 2$.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  We iterate through the $N$ input numbers once to count the odd numbers. The operations inside the loop (reading a number, checking parity) are constant time. The final check and output are also constant time.

- **Space Complexity**: $O(1)$
  We only use a few variables to store the count of odd numbers and loop indices. The space used does not depend on the input size $N$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of integers in the list
        std::cin >> n;

        int odd_count = 0; // Counter for odd numbers
        for (int i = 0; i < n; ++i) {
            long long a; // Use long long to handle potentially large input numbers
            std::cin >> a;
            // Check if the number is odd
            if (a % 2 != 0) {
                odd_count++;
            }
        }

        // The parity of the final sum is determined by the parity of the count of odd numbers.
        // If the count of odd numbers is even, the final sum will be even. Player 1 wins.
        // If the count of odd numbers is odd, the final sum will be odd. Player 2 wins.
        // This is because S = sum(sign_i * A_i).
        // S mod 2 = (sum(sign_i * A_i)) mod 2.
        // We proved that S mod 2 = (sum(A_i)) mod 2.
        // And (sum(A_i)) mod 2 = (count of odd A_i) mod 2.

        if (odd_count % 2 == 0) {
            // If odd_count is even, the sum will be even. Player 1 wins.
            std::cout << "1\n";
        } else {
            // If odd_count is odd, the sum will be odd. Player 2 wins.
            std::cout << "2\n";
        }
    }
    return 0;
}
```