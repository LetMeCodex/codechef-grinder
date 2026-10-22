# [Divisible Duel (P2209)](https://www.codechef.com/problems/P2209)
- **Difficulty Rating**: 628
- **Solved in**: 3 attempt(s)

## Problem Summary

Alice is given two positive integers, $X$ and $Y$. She considers all multiples of $X$ that are less than or equal to $Y$. Let these multiples be $M_1, M_2, \dots, M_k$, where $k = \lfloor Y/X \rfloor$.

She calculates two sums:
- $S_{even}$: The sum of all even multiples among $M_1, \dots, M_k$.
- $S_{odd}$: The sum of all odd multiples among $M_1, \dots, M_k$.

Alice is happy if $S_{even} \ge S_{odd}$. The task is to determine if Alice is happy for given $X$ and $Y$.

## Intuition & Mathematical Observation

Let the multiples of $X$ up to $Y$ be $1 \cdot X, 2 \cdot X, 3 \cdot X, \dots, k \cdot X$, where $k = \lfloor Y/X \rfloor$.
We need to compare $S_{even}$ (sum of $m \cdot X$ where $m \cdot X$ is even) with $S_{odd}$ (sum of $m \cdot X$ where $m \cdot X$ is odd).

We can analyze this based on the parity of $X$:

### Case 1: $X$ is an even number.
If $X$ is even, then any multiple $m \cdot X$ will also be even, regardless of the parity of $m$. This is because (any integer) $\times$ (even integer) = (even integer).
For example, if $X=2$: $1 \cdot 2 = 2$ (even), $2 \cdot 2 = 4$ (even), $3 \cdot 2 = 6$ (even), etc.
This means all multiples $1 \cdot X, 2 \cdot X, \dots, k \cdot X$ will be even.
Consequently:
- $S_{odd}$ will be $0$ (as there are no odd multiples).
- $S_{even}$ will be the sum of all multiples $X, 2X, \dots, kX$. Since $Y \ge X \ge 1$, $k$ must be at least $1$, so $S_{even}$ will be a positive value.
Since $S_{even} > 0$ and $S_{odd} = 0$, it is always true that $S_{even} \ge S_{odd}$.
Therefore, if $X$ is even, Alice is always happy.

### Case 2: $X$ is an odd number.
If $X$ is odd, the parity of a multiple $m \cdot X$ depends entirely on the parity of $m$:
- If $m$ is odd, then $m \cdot X$ is odd $\times$ odd = odd.
- If $m$ is even, then $m \cdot X$ is even $\times$ odd = even.

So, $S_{odd}$ is the sum of $(m \cdot X)$ for all odd $m$ such that $m \cdot X \le Y$.
And $S_{even}$ is the sum of $(m \cdot X)$ for all even $m$ such that $m \cdot X \le Y$.

We can factor out $X$ from both sums:
$S_{odd} = X \cdot (\text{sum of odd integers } m \text{ such that } m \le k)$
$S_{even} = X \cdot (\text{sum of even integers } m \text{ such that } m \le k)$

Since $X$ is a positive integer, the condition $S_{even} \ge S_{odd}$ is equivalent to comparing the sums of the corresponding $m$ values:
$(\text{sum of even } m \text{'s up to } k) \ge (\text{sum of odd } m \text{'s up to } k)$

Let's denote $SumEven_k = \sum_{j=1, 2j \le k} 2j$ and $SumOdd_k = \sum_{j=1, 2j-1 \le k} (2j-1)$.
We need to compare $SumEven_k$ and $SumOdd_k$.

#### Subcase 2a: $k$ is an even number.
The integers $m$ from $1$ to $k$ are $1, 2, 3, \dots, k-1, k$.
- The even $m$'s are $2, 4, \dots, k$. There are $k/2$ such numbers.
- The odd $m$'s are $1, 3, \dots, k-1$. There are $k/2$ such numbers.
Since the sequence of even numbers starts with $2$ and ends with $k$, and the sequence of odd numbers starts with $1$ and ends with $k-1$, and both sequences have the same number of terms, the sum of even numbers will be greater.
More formally, using the sum of an arithmetic progression $S_n = \frac{n}{2}(a_1 + a_n)$:
$SumEven_k = \frac{k/2}{2}(2 + k) = \frac{k(k+2)}{4}$.
$SumOdd_k = \frac{k/2}{2}(1 + (k-1)) = \frac{k \cdot k}{4} = \frac{k^2}{4}$.
Since $k \ge 1$, $k+2 > k$, so $\frac{k(k+2)}{4} > \frac{k^2}{4}$.
Thus, $SumEven_k > SumOdd_k$. Alice is happy.

#### Subcase 2b: $k$ is an odd number.
The integers $m$ from $1$ to $k$ are $1, 2, 3, \dots, k-1, k$.
- The even $m$'s are $2, 4, \dots, k-1$. There are $(k-1)/2$ such numbers.
- The odd $m$'s are $1, 3, \dots, k$. There are $(k+1)/2$ such numbers.
In this case, there is one more odd number than even numbers, and the largest number ($k$) is odd.
$SumEven_k = \frac{(k-1)/2}{2}(2 + (k-1)) = \frac{(k-1)(k+1)}{4} = \frac{k^2-1}{4}$.
$SumOdd_k = \frac{(k+1)/2}{2}(1 + k) = \frac{(k+1)^2}{4} = \frac{k^2+2k+1}{4}$.
Since $k \ge 1$, $k^2-1 < k^2+2k+1$.
Thus, $SumEven_k < SumOdd_k$. Alice is sad.

### Conclusion:
1.  If $X$ is even, Alice is happy ("YES").
2.  If $X$ is odd:
    a. Calculate $k = \lfloor Y/X \rfloor$.
    b. If $k$ is even, Alice is happy ("YES").
    c. If $k$ is odd, Alice is sad ("NO").

This logic is directly implemented in the provided solution code.

## Complexity Analysis
-   **Time Complexity**: For each test case, the solution performs a constant number of arithmetic operations (modulo, division, comparisons). These operations take $O(1)$ time. Since there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a fixed number of integer variables ($t, x, y, k$) to store input and intermediate results. This amount of memory does not depend on the input size, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int x, y;
        std::cin >> x >> y; // Read X and Y for each test case

        // Case 1: X is an even number.
        // If X is even, all its multiples (X, 2X, 3X, ...) are also even.
        // This means S_odd will be 0.
        // Since Y >= X >= 1, there is at least one multiple (X itself), so S_even will be positive.
        // Therefore, S_even >= S_odd (S_even >= 0) is always true. Alice is happy.
        if (x % 2 == 0) {
            std::cout << "YES\n";
        } 
        // Case 2: X is an odd number.
        // If X is odd, the parity of a multiple (m*X) depends on the parity of m.
        // m*X is odd if m is odd.
        // m*X is even if m is even.
        // We need to compare the sum of (odd m * X) with the sum of (even m * X).
        // This is equivalent to comparing the sum of odd m's with the sum of even m's.
        // Let k be the largest integer such that k*X <= Y. So k = floor(Y/X).
        else {
            int k = y / x; // Calculate k = floor(Y/X)

            // If k is even:
            // The sequence of m's is 1, 2, ..., k.
            // Sum of even m's (2+4+...+k) will be greater than sum of odd m's (1+3+...+(k-1)).
            // Example: k=4. Even m's: 2, 4. Sum = 6. Odd m's: 1, 3. Sum = 4. 6 >= 4. Alice is happy.
            if (k % 2 == 0) {
                std::cout << "YES\n";
            } 
            // If k is odd:
            // The sequence of m's is 1, 2, ..., k.
            // Sum of even m's (2+4+...+ (k-1)) will be less than sum of odd m's (1+3+...+k).
            // Example: k=3. Even m's: 2. Sum = 2. Odd m's: 1, 3. Sum = 4. 2 < 4. Alice is sad.
            else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}
```