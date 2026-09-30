# [Adjacent Sum Parity (ADJSUMPAR)](https://www.codechef.com/problems/ADJSUMPAR)
- **Difficulty Rating**: 1013
- **Solved in**: 1 attempt(s)

## Problem Summary

Given an integer $N$ and an array $B$ of $N$ integers, where each $B_i$ is either $0$ or $1$. We need to determine if there exists an array $A$ of $N$ integers such such that the following conditions hold:
1. For $1 \le i < N$: $B_i = (A_i + A_{i+1}) \pmod 2$
2. For $i = N$: $B_N = (A_N + A_1) \pmod 2$

If such an array $A$ exists, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation

The problem deals with parities. Let's denote the parity of an integer $X$ as $x = X \pmod 2$. So, $x$ will be $0$ if $X$ is even, and $1$ if $X$ is odd.
The given conditions can be rewritten in terms of parities of $A_i$ (let's call them $a_i$):
1. For $1 \le i < N$: $B_i = (a_i + a_{i+1}) \pmod 2$
2. For $i = N$: $B_N = (a_N + a_1) \pmod 2$

From the first set of conditions, we can derive a relationship to find $a_{i+1}$ if we know $a_i$ and $B_i$:
$a_{i+1} = (B_i - a_i) \pmod 2$.
Since we are working with $0$s and $1$s, $X \pmod 2$ is always non-negative. To ensure this, we can write $a_{i+1} = (B_i - a_i + 2) \pmod 2$.

This means that if we fix the parity of $A_1$ (i.e., $a_1$), we can uniquely determine the parities of $A_2, A_3, \ldots, A_N$ sequentially:
- $a_2 = (B_1 - a_1 + 2) \pmod 2$
- $a_3 = (B_2 - a_2 + 2) \pmod 2$
- ...
- $a_N = (B_{N-1} - a_{N-1} + 2) \pmod 2$

Once all $a_i$ values are determined, we must check if the final condition $B_N = (a_N + a_1) \pmod 2$ holds. If it holds, then a valid array $A$ exists (we can simply choose $A_i = a_i$). If it doesn't hold, then our initial choice for $a_1$ did not lead to a solution.

The crucial observation is about the dependence of the final condition on the initial choice of $a_1$. Let's expand the sequence:
$a_1$
$a_2 = B_1 - a_1$
$a_3 = B_2 - a_2 = B_2 - (B_1 - a_1) = B_2 - B_1 + a_1$
$a_4 = B_3 - a_3 = B_3 - (B_2 - B_1 + a_1) = B_3 - B_2 + B_1 - a_1$
...
In general, $a_{i+1} = B_i - a_i \pmod 2$. This pattern shows that $a_i$ will be of the form $X \pm a_1 \pmod 2$, where $X$ is some sum/difference of $B_j$'s.
Specifically, $a_N = \left( \sum_{k=1}^{N-1} (-1)^{N-1-k} B_k \right) + (-1)^{N-1} a_1 \pmod 2$.

Let $S = \left( \sum_{k=1}^{N-1} (-1)^{N-1-k} B_k \right) \pmod 2$.
Then $a_N = (S + (-1)^{N-1} a_1) \pmod 2$.

Now, substitute this into the final condition $B_N = (a_N + a_1) \pmod 2$:
$B_N = (S + (-1)^{N-1} a_1 + a_1) \pmod 2$
$B_N = (S + ((-1)^{N-1} + 1) a_1) \pmod 2$

Let's analyze the term $((-1)^{N-1} + 1)$:
- **If $N$ is odd**: Then $N-1$ is even. So, $(-1)^{N-1} = 1$.
  The term becomes $(1 + 1) = 2$.
  The condition becomes $B_N = (S + 2 \cdot a_1) \pmod 2 = S \pmod 2$.
  In this case, the condition for a solution to exist ($B_N = S \pmod 2$) is **independent of $a_1$**.

- **If $N$ is even**: Then $N-1$ is odd. So, $(-1)^{N-1} = -1$.
  The term becomes $(-1 + 1) = 0$.
  The condition becomes $B_N = (S + 0 \cdot a_1) \pmod 2 = S \pmod 2$.
  Again, the condition for a solution to exist ($B_N = S \pmod 2$) is **independent of $a_1$**.

In both cases, the existence of a valid array $A$ (in terms of parities) does not depend on the initial choice of $a_1$. This means we only need to try one possible value for $a_1$ (either $0$ or $1$). If a solution exists for $a_1=0$, it also exists for $a_1=1$ (and vice-versa). If no solution exists for $a_1=0$, then no solution exists for $a_1=1$ either.

Therefore, the strategy is simple:
1. Assume $a_1 = 0$.
2. Sequentially calculate $a_2, a_3, \ldots, a_N$ using $a_{i+1} = (B_i - a_i + 2) \pmod 2$.
3. Check if the final condition $B_N = (a_N + a_1) \pmod 2$ holds.
4. If it holds, output "YES". Otherwise, output "NO".

## Complexity Analysis

-   **Time Complexity**:
    -   Reading $N$ and the array $B$ takes $O(N)$ time.
    -   The `check_solution_existence` function iterates $N-1$ times to determine $a_2, \ldots, a_N$, performing constant time operations in each iteration. This takes $O(N)$ time. The final check is $O(1)$.
    -   Thus, for a single test case, the time complexity is $O(N)$.
    -   Given that the sum of $N$ over all test cases is at most $2 \cdot 10^5$, the total time complexity across all test cases is $O(\sum N)$.

-   **Space Complexity**:
    -   Storing the input array $B$ requires $O(N)$ space.
    -   Storing the calculated parities $a$ also requires $O(N)$ space.
    -   Therefore, the space complexity for a single test case is $O(N)$.
    -   Since the space for $B$ and $a$ can be reused for each test case, the total space complexity is $O(\max N)$, where $\max N$ is the maximum value of $N$ across all test cases.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but often included in competitive programming templates

// Function to check if a valid array A (in terms of parities a) exists
// for a given B and an initial guess for a_1.
// As derived, the existence of a solution does not depend on the choice of a1_initial_guess.
// So, we only need to call this function once with either 0 or 1 for a1_initial_guess.
bool check_solution_existence(int N, const std::vector<int>& B, int a1_initial_guess) {
    // 'a' will store the parities of elements of A.
    // a[0] corresponds to A_1 % 2, a[1] to A_2 % 2, ..., a[N-1] to A_N % 2.
    std::vector<int> a(N);
    a[0] = a1_initial_guess; // Set the initial parity for A_1

    // Use the given conditions B_i = (A_i + A_{i+1}) % 2 to determine
    // a_2, a_3, ..., a_N sequentially.
    // In 0-indexed terms: a[i+1] = (B[i] - a[i] + 2) % 2 for i from 0 to N-2.
    for (int i = 0; i < N - 1; ++i) {
        // From a[i] + a[i+1] = B[i] (mod 2), we get a[i+1] = B[i] - a[i] (mod 2).
        // Adding 2 before modulo ensures the result is always non-negative (0 or 1).
        a[i+1] = (B[i] - a[i] + 2) % 2;
    }

    // After determining a[0] through a[N-1], we must check the final condition:
    // B_N = (A_N + A_1) % 2.
    // In 0-indexed terms: B[N-1] = (a[N-1] + a[0]) % 2.
    return (a[N-1] + a[0]) % 2 == B[N-1];
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // As proven, the existence of a valid array A does not depend on the initial choice
    // of A_1's parity. So, we can just try a_1 = 0. If it works, a solution exists.
    // If it doesn't work, no solution exists (trying a_1 = 1 would also fail).
    if (check_solution_existence(N, B, 0)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```