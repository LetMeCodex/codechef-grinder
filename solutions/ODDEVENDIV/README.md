# [Check Odd Even Divisors (ODDEVENDIV)](https://www.codechef.com/problems/ODDEVENDIV)
- **Difficulty Rating**: 1105
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to find a positive integer $N$ such that it has exactly $A$ odd divisors and exactly $B$ even divisors. We are given two non-negative integers $A$ and $B$ as input.

## Intuition & Mathematical Observation

Let's consider the prime factorization of any positive integer $N$. We can write $N$ as:
$N = 2^k \cdot M$
where $k \ge 0$ is an integer, and $M$ is an odd integer (meaning $M$ is not divisible by 2).
$M$ itself can be written as $p_1^{e_1} \cdot p_2^{e_2} \cdots p_m^{e_m}$, where $p_i$ are distinct odd prime numbers and $e_i \ge 1$.

Now, let's analyze the divisors of $N$:

1.  **Odd Divisors of $N$**:
    An odd divisor of $N$ cannot have any factor of 2. This means any odd divisor of $N$ must be a divisor of $M$.
    Therefore, the number of odd divisors of $N$ is exactly the number of divisors of $M$.
    Let $\tau(M)$ denote the number of divisors of $M$.
    From the problem statement, the number of odd divisors is $A$. So, we must have $A = \tau(M)$.

2.  **Even Divisors of $N$**:
    An even divisor of $N$ must have at least one factor of 2.
    Any divisor of $N$ is of the form $2^j \cdot d'$, where $0 \le j \le k$ and $d'$ is a divisor of $M$.
    For a divisor to be even, $j$ must be at least 1. So, $j \in \{1, 2, \ldots, k\}$.
    For each divisor $d'$ of $M$, we can form $k$ distinct even divisors: $2^1 d', 2^2 d', \ldots, 2^k d'$.
    Since there are $\tau(M)$ choices for $d'$, the total number of even divisors is $k \cdot \tau(M)$.
    From the problem statement, the number of even divisors is $B$. So, we must have $B = k \cdot \tau(M)$.

Now we have two key relationships:
1.  $A = \tau(M)$
2.  $B = k \cdot \tau(M)$

Let's analyze these relationships based on the given values of $A$ and $B$:

*   **Case 1: $A = 0$**
    If $A=0$, it means $\tau(M)=0$. This is impossible for any positive integer $M$, because every positive integer has at least one divisor (1). Even if $M=1$, $\tau(M)=1$.
    Therefore, if $A=0$, it's impossible to construct such an $N$. We output "No".

*   **Case 2: $A > 0$**
    If $A > 0$, it is always possible to find an odd integer $M$ such that $\tau(M) = A$. For example, if $A=1$, we can choose $M=1$. If $A > 1$, we can choose $M = p^{A-1}$ for any odd prime $p$ (e.g., $3^{A-1}$), which will have $A$ divisors. So, the existence of $M$ is guaranteed.
    Now, substitute $A = \tau(M)$ into the second equation: $B = k \cdot A$.

    *   **Subcase 2.1: $B = 0$**
        If $B=0$, then $k \cdot A = 0$. Since we are in the $A > 0$ case, this implies $k=0$.
        If $k=0$, it means $N = 2^0 \cdot M = M$. In this scenario, $N$ is an odd number. An odd number has no even divisors, and all its divisors are odd. This perfectly matches $B=0$ and $A=\tau(M)$.
        Thus, if $A > 0$ and $B = 0$, it is possible. We output "Yes".

    *   **Subcase 2.2: $B > 0$**
        If $B > 0$, then from $B = k \cdot A$, we need to find a non-negative integer $k$. Since $A > 0$ and $B > 0$, $k$ must be a positive integer.
        This implies $k = B/A$. For $k$ to be a valid exponent, it must be an integer.
        Therefore, $B$ must be perfectly divisible by $A$.
        *   If $B \% A == 0$: We can find an integer $k = B/A$. We can then construct $N = 2^k \cdot M$ (where $M$ is an odd number with $A$ divisors). This is possible. We output "Yes".
        *   If $B \% A \ne 0$: $k$ would not be an integer, which is impossible. We output "No".

Combining these observations leads directly to the logic implemented in the solution code.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution involves reading two `long long` integers and performing a few constant-time arithmetic operations (comparisons, modulo). This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few variables (`A`, `B`, `T`) to store input and loop counters. This requires a constant amount of memory, regardless of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // As requested by the problem statement

void solve() {
    long long A, B; // A, B can be up to 10^9, so long long is used for safety.
    cin >> A >> B; // Read A and B

    if (A == 0) {
        // Case 1: A = 0. Impossible, as any positive integer has at least one odd divisor (1).
        // The number of odd divisors (A) must be equal to tau(M), where M is the odd part of N.
        // tau(M) is always >= 1 for any positive M. So A cannot be 0.
        cout << "No\n";
    } else { // A > 0
        // Case 2: A > 0. An odd integer M with A divisors can always be constructed.
        // For example, if A=1, M=1. If A>1, M = 3^(A-1) has A divisors.
        // Now we check the even divisors. We know B = k * A, where k is the exponent of 2 in N.
        if (B == 0) {
            // Subcase 2.1: B = 0. This means N must be an odd number (k=0).
            // An odd number has no even divisors. All its divisors are odd.
            // This is possible if A > 0.
            cout << "Yes\n";
        } else { // B > 0
            // Subcase 2.2: B > 0. We need B = k * A for some positive integer k.
            // This implies B must be perfectly divisible by A to get an integer k.
            if (B % A == 0) {
                cout << "Yes\n";
            } else {
                // If B is not divisible by A, k would not be an integer, which is impossible.
                cout << "No\n";
            }
        }
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```