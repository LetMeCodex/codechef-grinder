# [Odd Pairs (ODDPAIRS)](https://www.codechef.com/problems/ODDPAIRS)
- **Difficulty Rating**: 1044
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the number of pairs of integers $(A, B)$ such that $1 \le A, B \le N$ and their sum $A + B$ is odd.

## Intuition & Mathematical Observation
The sum of two integers $A$ and $B$ is odd if and only if one of the integers is odd and the other is even. There are two possible scenarios for this:
1. $A$ is odd and $B$ is even.
2. $A$ is even and $B$ is odd.

Let's determine the count of odd and even numbers in the range $[1, N]$.

- **Number of odd integers up to $N$**:
  - If $N$ is even, say $N = 2k$, the odd numbers are $1, 3, \dots, 2k-1$. There are $k$ odd numbers.
  - If $N$ is odd, say $N = 2k+1$, the odd numbers are $1, 3, \dots, 2k+1$. There are $k+1$ odd numbers.
  In general, the number of odd integers up to $N$ can be calculated using integer division as `(N + 1) / 2`.

- **Number of even integers up to $N$**:
  - If $N$ is even, say $N = 2k$, the even numbers are $2, 4, \dots, 2k$. There are $k$ even numbers.
  - If $N$ is odd, say $N = 2k+1$, the even numbers are $2, 4, \dots, 2k$. There are $k$ even numbers.
  In general, the number of even integers up to $N$ can be calculated using integer division as `N / 2`.

Let `num_odd` be the count of odd integers in $[1, N]$ and `num_even` be the count of even integers in $[1, N]$.

Now, let's consider the two scenarios for an odd sum:

1. **$A$ is odd and $B$ is even**:
   The number of choices for $A$ is `num_odd`.
   The number of choices for $B$ is `num_even`.
   The total number of pairs in this case is `num_odd * num_even`.

2. **$A$ is even and $B$ is odd**:
   The number of choices for $A$ is `num_even`.
   The number of choices for $B$ is `num_odd`.
   The total number of pairs in this case is `num_even * num_odd`.

The total number of pairs $(A, B)$ such that $A+B$ is odd is the sum of the counts from these two disjoint cases:
Total pairs = (Number of pairs where $A$ is odd and $B$ is even) + (Number of pairs where $A$ is even and $B$ is odd)
Total pairs = `(num_odd * num_even) + (num_even * num_odd)`
Total pairs = `2 * num_odd * num_even`

Substituting the formulas for `num_odd` and `num_even`:
`num_odd = (N + 1) / 2`
`num_even = N / 2`

So, the result is `2 * ((N + 1) / 2) * (N / 2)`.

Let's verify with examples:
- If $N=4$:
  Odd numbers: 1, 3 (num_odd = 2)
  Even numbers: 2, 4 (num_even = 2)
  Result = $2 * 2 * 2 = 8$.
  Pairs: (1,2), (1,4), (3,2), (3,4), (2,1), (2,3), (4,1), (4,3). Sums: 3, 5, 5, 7, 3, 5, 5, 7. All odd. Correct.

- If $N=5$:
  Odd numbers: 1, 3, 5 (num_odd = 3)
  Even numbers: 2, 4 (num_even = 2)
  Result = $2 * 3 * 2 = 12$.
  Pairs: (1,2), (1,4), (3,2), (3,4), (5,2), (5,4), (2,1), (2,3), (2,5), (4,1), (4,3), (4,5). Sums: 3, 5, 5, 7, 7, 9, 3, 5, 7, 5, 7, 9. All odd. Correct.

The logic holds.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations and a loop that runs $T$ times (where $T$ is the number of test cases). Inside the loop, the operations are constant time. Therefore, for each test case, the time complexity is $O(1)$. The total time complexity for $T$ test cases is $O(T)$.

- **Space Complexity**: $O(1)$
  The solution uses a few variables to store $N$, the counts of odd and even numbers, and the result. The memory usage is constant and does not depend on the input size $N$.

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
        long long n; // Input integer N
        std::cin >> n;

        // Calculate the number of odd integers in the range [1, N]
        // For N=1, odd=1. (1+1)/2 = 1
        // For N=2, odd=1. (2+1)/2 = 1
        // For N=3, odd=2. (3+1)/2 = 2
        // For N=4, odd=2. (4+1)/2 = 2
        long long num_odd = (n + 1) / 2;

        // Calculate the number of even integers in the range [1, N]
        // For N=1, even=0. 1/2 = 0
        // For N=2, even=1. 2/2 = 1
        // For N=3, even=1. 3/2 = 1
        // For N=4, even=2. 4/2 = 2
        long long num_even = n / 2;

        // The sum A + B is odd if one is odd and the other is even.
        // Number of pairs (odd, even) = num_odd * num_even
        // Number of pairs (even, odd) = num_even * num_odd
        // Total pairs = (num_odd * num_even) + (num_even * num_odd) = 2 * num_odd * num_even
        long long result = 2 * num_odd * num_even;

        std::cout << result << "\n";
    }
    return 0;
}
```