# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)
- **Difficulty Rating**: 1368
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ and a target sum $S$. We have an array $A$ where $A[i] = i$ for $1 \le i \le N$. We need to find an index $x$ ($1 \le x \le N$) such that if we remove the element $A[x]$ from the array, the sum of the remaining elements is exactly $S$. If no such index $x$ exists, we should output -1.

## Intuition & Mathematical Observation

The array $A$ contains elements $1, 2, 3, \dots, N$.
The sum of all elements in this array is the sum of the first $N$ natural numbers, which can be calculated using the formula:
$$ \text{Total Sum} = \sum_{i=1}^{N} i = \frac{N \times (N + 1)}{2} $$

We are looking for an index $x$ ($1 \le x \le N$) such that the sum of elements *excluding* $A[x]$ equals $S$.
This can be expressed as:
$$ (\sum_{i=1}^{N} A[i]) - A[x] = S $$

Since $A[i] = i$, we can substitute this into the equation:
$$ \left(\sum_{i=1}^{N} i\right) - x = S $$

Using the formula for the sum of the first $N$ natural numbers:
$$ \frac{N \times (N + 1)}{2} - x = S $$

Now, we can rearrange this equation to solve for $x$:
$$ x = \frac{N \times (N + 1)}{2} - S $$

Once we calculate this value of $x$, we need to check if it's a valid index within the array. A valid index $x$ must satisfy $1 \le x \le N$.
- If the calculated $x$ falls within this range, then that's our answer.
- If the calculated $x$ is less than 1 or greater than $N$, it means no such element can be removed to achieve the target sum $S$, so we should output -1.

It's important to use `long long` for calculations involving $N \times (N+1)/2$ to avoid potential integer overflow, especially for large values of $N$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations (multiplication, addition, division, subtraction) and a comparison. These operations take constant time, regardless of the input size $N$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`t`, `n`, `s`, `total_sum`, `required_x`) to store intermediate values. The memory usage does not grow with the input size $N$.

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
        long long n, s; // N: size of the array, S: target sum
        std::cin >> n >> s;

        // The array A is defined as A[i] = i for 1 <= i <= N.
        // The sum of all elements in the array is the sum of integers from 1 to N.
        // Sum(1 to N) = N * (N + 1) / 2.
        // We are looking for a position x (1 <= x <= N) such that
        // (A[1] + ... + A[x-1]) + (A[x+1] + ... + A[N]) = S.
        // This is equivalent to:
        // (Sum of all elements) - A[x] = S
        // (N * (N + 1) / 2) - x = S
        // So, x = (N * (N + 1) / 2) - S.

        // Calculate the total sum of elements from 1 to N.
        // Use long long to prevent overflow for large N.
        long long total_sum = n * (n + 1) / 2;

        // Calculate the required value of x.
        // This is the element that needs to be removed to achieve the sum S.
        long long required_x = total_sum - s;

        // Check if the calculated x is a valid position in the array.
        // A valid position x must satisfy 1 <= x <= N.
        if (required_x >= 1 && required_x <= n) {
            std::cout << required_x << "\n";
        } else {
            // If no such valid position exists, print -1.
            std::cout << -1 << "\n";
        }
    }
    return 0;
}
```