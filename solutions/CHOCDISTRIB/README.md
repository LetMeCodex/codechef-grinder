# [Chocolate Distribution (CHOCDISTRIB)](https://www.codechef.com/problems/CHOCDISTRIB)
- **Difficulty Rating**: 595
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ chocolates, we need to distribute them among some children. Each child can receive either 1 or 2 chocolates. We need to find the minimum and maximum possible number of children among whom these $N$ chocolates can be distributed.

## Intuition & Mathematical Observation

Let $N$ be the total number of chocolates.
Let $C$ be the number of children.
Let $c_i$ be the number of chocolates given to the $i$-th child, where $c_i \in \{1, 2\}$.

The total number of chocolates distributed is $\sum_{i=1}^{C} c_i = N$.

**To find the Minimum Number of Children:**

To minimize the number of children, we should maximize the number of chocolates given to each child. The maximum number of chocolates a child can receive is 2.
So, we should try to give 2 chocolates to as many children as possible.

If we give 2 chocolates to $k$ children, we use $2k$ chocolates.
The remaining chocolates will be $N - 2k$.
If $N - 2k > 0$, these remaining chocolates must be distributed to at least one more child. Since each child can take at most 2, if $N - 2k = 1$, one child takes 1 chocolate. If $N - 2k = 2$, one child takes 2 chocolates.

Consider the total number of chocolates $N$.
If we give 2 chocolates to each child, we can have $N/2$ children if $N$ is even.
If $N$ is odd, say $N = 2k + 1$, we can give 2 chocolates to $k$ children and 1 chocolate to one child. This makes a total of $k+1$ children.
In general, the minimum number of children is achieved when we distribute as many 2s as possible.
This is equivalent to finding the smallest $C$ such that $C \times 2 \ge N$.
The smallest integer $C$ satisfying this is $\lceil N/2 \rceil$.
Using integer division, this can be calculated as $(N + 1) / 2$.

For example:
- If $N=5$: $(5+1)/2 = 3$. We can give (2, 2, 1) to 3 children.
- If $N=6$: $(6+1)/2 = 3$. We can give (2, 2, 2) to 3 children.

**To find the Maximum Number of Children:**

To maximize the number of children, we should minimize the number of chocolates given to each child. The minimum number of chocolates a child can receive is 1.
So, we should give 1 chocolate to as many children as possible.

If we give 1 chocolate to each child, we can have $N$ children, each receiving 1 chocolate. This uses exactly $N$ chocolates.
Since each child must receive at least 1 chocolate, we cannot have more than $N$ children.

For example:
- If $N=5$: We can give (1, 1, 1, 1, 1) to 5 children.
- If $N=6$: We can give (1, 1, 1, 1, 1, 1) to 6 children.

Therefore, the maximum number of children is $N$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations and reading input. These operations take constant time, regardless of the input size $N$. The loop runs $t$ times, where $t$ is the number of test cases. For each test case, the computation is $O(1)$. So, the total time complexity is $O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store $t$, $n$, `min_children`, and `max_children`. The amount of memory used does not depend on the input size $N$. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of chocolates
        std::cin >> n;

        // Minimum number of children:
        // To minimize the number of children, we give as many chocolates as possible
        // to each child, which is 2.
        // If N chocolates are distributed, and each child gets at most 2,
        // the minimum number of children C must satisfy C * 2 >= N.
        // The smallest integer C is ceil(N/2).
        // In integer arithmetic, ceil(N/2) can be computed as (N + 1) / 2.
        // Example:
        // N=5: (5+1)/2 = 3. Distribution: (2, 2, 1)
        // N=6: (6+1)/2 = 3. Distribution: (2, 2, 2)
        int min_children = (n + 1) / 2;

        // Maximum number of children:
        // To maximize the number of children, we give as few chocolates as possible
        // to each child, which is 1.
        // If N chocolates are distributed, and each child gets at least 1,
        // the maximum number of children C is N, where each child gets 1 chocolate.
        // Example:
        // N=5: Distribution: (1, 1, 1, 1, 1)
        // N=6: Distribution: (1, 1, 1, 1, 1, 1)
        int max_children = n;

        std::cout << min_children << " " << max_children << "\n";
    }
    return 0;
}
```