# [Alternate Jumps (ALJMP)](https://www.codechef.com/problems/ALJMP)
- **Difficulty Rating**: 648
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given an integer $N$. You start at position $N$. You need to perform $N-1$ jumps. The $i$-th jump (where $i$ ranges from 1 to $N-1$) has a distance of $N-i$. If the jump number $i$ is odd, you move left by the jump distance. If the jump number $i$ is even, you move right by the jump distance. Your task is to find your final position after $N-1$ jumps.

## Intuition & Mathematical Observation

Let's trace the position for a few small values of $N$ to observe a pattern.

- **N = 1**: No jumps. Starting position is 1. Final position is 1.
- **N = 2**:
    - Start at 2.
    - Jump 1 (distance $2-1=1$): Odd jump, move left. Position becomes $2 - 1 = 1$.
    - Final position is 1.
- **N = 3**:
    - Start at 3.
    - Jump 1 (distance $3-1=2$): Odd jump, move left. Position becomes $3 - 2 = 1$.
    - Jump 2 (distance $3-2=1$): Even jump, move right. Position becomes $1 + 1 = 2$.
    - Final position is 2.
- **N = 4**:
    - Start at 4.
    - Jump 1 (distance $4-1=3$): Odd jump, move left. Position becomes $4 - 3 = 1$.
    - Jump 2 (distance $4-2=2$): Even jump, move right. Position becomes $1 + 2 = 3$.
    - Jump 3 (distance $4-3=1$): Odd jump, move left. Position becomes $3 - 1 = 2$.
    - Final position is 2.
- **N = 5**:
    - Start at 5.
    - Jump 1 (distance $5-1=4$): Odd jump, move left. Position becomes $5 - 4 = 1$.
    - Jump 2 (distance $5-2=3$): Even jump, move right. Position becomes $1 + 3 = 4$.
    - Jump 3 (distance $5-3=2$): Odd jump, move left. Position becomes $4 - 2 = 2$.
    - Jump 4 (distance $5-4=1$): Even jump, move right. Position becomes $2 + 1 = 3$.
    - Final position is 3.

Let $P_0 = N$ be the initial position.
The $i$-th jump has a distance $d_i = N-i$.

If $i$ is odd, the change in position is $-d_i = -(N-i)$.
If $i$ is even, the change in position is $+d_i = +(N-i)$.

The final position $P_{N-1}$ can be expressed as:
$P_{N-1} = P_0 + \sum_{i=1}^{N-1} (\text{change in position for jump } i)$
$P_{N-1} = N + \sum_{i=1}^{N-1} \begin{cases} -(N-i) & \text{if } i \text{ is odd} \\ +(N-i) & \text{if } i \text{ is even} \end{cases}$

Let's expand the sum:
For $N=5$:
$P_4 = 5 + (-(5-1)) + (+(5-2)) + (-(5-3)) + (+(5-4))$
$P_4 = 5 + (-4) + (3) + (-2) + (1)$
$P_4 = 5 - 4 + 3 - 2 + 1 = 3$

We can group the terms:
$P_{N-1} = N + \sum_{k=1}^{\lfloor (N-1)/2 \rfloor} [-(N-(2k-1)) + (N-2k)]$
$P_{N-1} = N + \sum_{k=1}^{\lfloor (N-1)/2 \rfloor} [-N + 2k - 1 + N - 2k]$
$P_{N-1} = N + \sum_{k=1}^{\lfloor (N-1)/2 \rfloor} [-1]$

This formula works if $N-1$ is even. If $N-1$ is odd, there will be one last odd jump.

Let's consider the cases:

**Case 1: $N$ is odd.**
Then $N-1$ is even. The number of jumps is $N-1$.
The jumps are $1, 2, 3, \dots, N-1$.
Odd jumps: $1, 3, 5, \dots, N-2$. There are $(N-2 - 1)/2 + 1 = (N-3)/2 + 1 = (N-1)/2$ odd jumps.
Even jumps: $2, 4, 6, \dots, N-1$. There are $(N-1 - 2)/2 + 1 = (N-3)/2 + 1 = (N-1)/2$ even jumps.

The sum can be written as:
$P_{N-1} = N + \sum_{j=1}^{(N-1)/2} [-(N-(2j-1)) + (N-2j)]$
$P_{N-1} = N + \sum_{j=1}^{(N-1)/2} [-N + 2j - 1 + N - 2j]$
$P_{N-1} = N + \sum_{j=1}^{(N-1)/2} [-1]$
$P_{N-1} = N + (N-1)/2 \times (-1)$
$P_{N-1} = N - (N-1)/2$
$P_{N-1} = (2N - (N-1))/2$
$P_{N-1} = (2N - N + 1)/2$
$P_{N-1} = (N+1)/2$

Let's check for odd $N$:
- $N=1$: $(1+1)/2 = 1$. Correct.
- $N=3$: $(3+1)/2 = 2$. Correct.
- $N=5$: $(5+1)/2 = 3$. Correct.

**Case 2: $N$ is even.**
Then $N-1$ is odd. The number of jumps is $N-1$.
The jumps are $1, 2, 3, \dots, N-1$.
Odd jumps: $1, 3, 5, \dots, N-1$. There are $(N-1 - 1)/2 + 1 = (N-2)/2 + 1 = N/2$ odd jumps.
Even jumps: $2, 4, 6, \dots, N-2$. There are $(N-2 - 2)/2 + 1 = (N-4)/2 + 1 = N/2 - 1$ even jumps.

The sum can be written as:
$P_{N-1} = N + \sum_{j=1}^{N/2-1} [-(N-(2j-1)) + (N-2j)] + (-(N-(N-1)))$  (The last term is the $N-1$-th jump, which is odd)
$P_{N-1} = N + \sum_{j=1}^{N/2-1} [-1] - (N-(N-1))$
$P_{N-1} = N + (N/2 - 1) \times (-1) - (1)$
$P_{N-1} = N - (N/2 - 1) - 1$
$P_{N-1} = N - N/2 + 1 - 1$
$P_{N-1} = N/2$

Let's check for even $N$:
- $N=2$: $2/2 = 1$. Correct.
- $N=4$: $4/2 = 2$. Correct.

So, the final position is $(N+1)/2$ if $N$ is odd, and $N/2$ if $N$ is even.
This can be concisely written as $\lfloor (N+1)/2 \rfloor$ or $(N+1)/2$ using integer division.

The provided code implements a direct simulation of the jumps.
Let's analyze the code's logic:
`current_pos = n;` - Initializes position to $N$.
The loop runs from `i = 1` to `n - 1`. This represents the jump number.
`jump_distance = n - i;` - Calculates the distance for the $i$-th jump.
`if (i % 2 == 1)`: If jump number `i` is odd, `current_pos -= jump_distance;` (move left).
`else`: If jump number `i` is even, `current_pos += jump_distance;` (move right).

This directly matches the problem statement and our derived logic. The code will correctly calculate the final position by simulating each jump.

For example, if $N=5$:
`current_pos = 5`
`i = 1`: `jump_distance = 5 - 1 = 4`. `i` is odd. `current_pos = 5 - 4 = 1`.
`i = 2`: `jump_distance = 5 - 2 = 3`. `i` is even. `current_pos = 1 + 3 = 4`.
`i = 3`: `jump_distance = 5 - 3 = 2`. `i` is odd. `current_pos = 4 - 2 = 2`.
`i = 4`: `jump_distance = 5 - 4 = 1`. `i` is even. `current_pos = 2 + 1 = 3`.
Output: 3.

The mathematical observation confirms that the simulation approach is correct and leads to a simple formula. The code directly implements the simulation.

## Complexity Analysis

- **Time Complexity**: $O(N)$
The code iterates through a loop $N-1$ times. Inside the loop, operations are constant time. Therefore, the time complexity is directly proportional to $N$.

- **Space Complexity**: $O(1)$
The code uses a few variables (`t`, `n`, `current_pos`, `i`, `jump_distance`) to store data. The amount of memory used does not grow with the input size $N$. Thus, the space complexity is constant.

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
        int n; // Input integer N
        std::cin >> n;

        long long current_pos = n; // Start at position N

        // Perform N-1 jumps
        // i represents the jump number, from 1 to N-1
        for (int i = 1; i <= n - 1; ++i) {
            int jump_distance = n - i; // Distance of the i-th jump

            if (i % 2 == 1) { // If the jump number is odd, move left
                current_pos -= jump_distance;
            } else { // If the jump number is even, move right
                current_pos += jump_distance;
            }
        }
        // Output the final position
        std::cout << current_pos << "\n";
    }
    return 0;
}
```