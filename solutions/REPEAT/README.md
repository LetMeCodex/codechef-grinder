Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem "Odd Repeat (REPEAT)".

---

# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)
- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find a specific odd number, let's call it $X$. We are given three integers: $N$, $K$, and $S$.
The sequence of numbers is constructed as follows:
1. It contains the first $N$ positive odd numbers.
2. One of these $N$ odd numbers, $X$, appears exactly $K$ times.
3. All other $N-1$ distinct odd numbers appear exactly once.
4. The sum of all numbers in this sequence is $S$.

Our task is to determine the value of $X$.

## Intuition & Mathematical Observation

The core of this problem lies in a well-known mathematical property and careful manipulation of the given sum.

1.  **Sum of the first $N$ positive odd numbers**:
    A fundamental property of odd numbers is that the sum of the first $N$ positive odd numbers is always $N^2$.
    For example:
    - $N=1$: $1 = 1^2$
    - $N=2$: $1+3 = 4 = 2^2$
    - $N=3$: $1+3+5 = 9 = 3^2$
    So, if all $N$ distinct odd numbers appeared exactly once, their total sum would be $N^2$.

2.  **How $X$ affects the total sum $S$**:
    Let's consider the sum $N^2$ as our baseline. This sum includes one instance of every odd number from the first $N$ odd numbers.
    In our actual sequence:
    - One specific odd number, $X$, is supposed to appear $K$ times.
    - All other $N-1$ distinct odd numbers appear once.

    We can express the given total sum $S$ by starting with the sum of all $N$ distinct odd numbers ($N^2$) and then adjusting for $X$:
    - The sum $N^2$ already counts $X$ once.
    - Since $X$ actually appears $K$ times, its contribution to the sum should be $K \cdot X$.
    - To get from $N^2$ to $S$, we effectively remove the single count of $X$ that was part of $N^2$, and then add back its actual contribution, $K \cdot X$.

    So, the equation becomes:
    $S = (\text{Sum of first } N \text{ distinct odd numbers}) - (\text{one instance of } X) + (\text{K instances of } X)$
    $S = N^2 - X + K \cdot X$

3.  **Solving for $X$**:
    Now we have an algebraic equation for $X$:
    $S = N^2 + (K \cdot X - X)$
    $S = N^2 + (K-1) \cdot X$

    To isolate $X$:
    $S - N^2 = (K-1) \cdot X$
    $X = \frac{S - N^2}{K-1}$

4.  **Constraints and Data Types**:
    - $N, K \le 10^4$
    - $S \le 10^9$
    - $N^2$ can be up to $(10^4)^2 = 10^8$. This fits within a standard 32-bit signed integer (`int`).
    - $S - N^2$ can be up to $10^9 - 10^8 \approx 9 \cdot 10^8$. This also fits within an `int`.
    - $K-1$ can be up to $10^4 - 1$. This fits within an `int`.
    - $X$ is one of the first $N$ odd numbers. The largest $N$-th odd number is $2N-1$. For $N=10^4$, $X$ can be up to $2 \cdot 10^4 - 1 \approx 2 \cdot 10^4$. This fits within an `int`.
    While `int` would technically suffice for all calculations given these constraints, using `long long` for intermediate sums like `sum_of_first_N_odds` and `numerator` (as done in the provided solution) is a robust practice to prevent potential overflow, especially if constraints were slightly larger. The cast `(long long)N * N` ensures the product is computed using `long long` precision.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a fixed number of arithmetic operations (multiplication, subtraction, division). These operations take constant time. Since there are $T$ test cases, the total time complexity is directly proportional to the number of test cases.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of memory to store variables like $N, K, S$, and intermediate results. The memory usage does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, etc. for standard I/O and other utilities

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, K, S;
        cin >> N >> K >> S; // Read N, K, S for the current test case

        // The sum of the first N positive odd numbers is N*N.
        // Let X be the number that appears K times.
        // All other N-1 distinct odd numbers appear once.
        // The total sum S can be expressed as:
        // S = (sum of all N distinct odd numbers) - X (because it's counted once in N*N) + K*X (its actual contribution)
        // S = N*N - X + K*X

        // Rearranging the equation to solve for X:
        // S - N*N = (K-1)*X
        // X = (S - N*N) / (K-1)

        // N, K, S are within int limits (N, K <= 10^4, S <= 10^9).
        // N*N can be up to 10^4 * 10^4 = 10^8, which fits in an int.
        // S - N*N can be up to 10^9 - 10^8 (approx 9*10^8), which fits in an int.
        // K-1 can be up to 10^4 - 1, which fits in an int.
        // X will be one of the first N odd numbers, so max 2*10^4 - 1, which fits in an int.
        // Therefore, 'int' type is sufficient for all calculations.
        // However, using 'long long' for intermediate sums is a good practice for robustness,
        // especially if constraints were slightly larger.

        long long sum_of_first_N_odds = (long long)N * N; // Cast N to long long to ensure the product is long long
                                                          // (even though N*N fits in int for these constraints)
        
        long long numerator = S - sum_of_first_N_odds;
        long long denominator = K - 1;

        long long X = numerator / denominator; // Calculate X

        cout << X << "\n"; // Print the result followed by a newline
    }

    return 0; // Indicate successful execution
}
```