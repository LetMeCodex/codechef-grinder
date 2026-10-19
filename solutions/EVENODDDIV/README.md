# [Even vs Odd Divisors (EVENODDDIV)](https://www.codechef.com/problems/EVENODDDIV)
- **Difficulty Rating**: 642
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to determine the relationship between the number of its even divisors and the number of its odd divisors. Specifically, we need to output:
- `-1` if the number of even divisors is strictly less than the number of odd divisors.
- `0` if the number of even divisors is equal to the number of odd divisors.
- `1` if the number of even divisors is strictly greater than the number of odd divisors.

## Intuition & Mathematical Observation

Let the prime factorization of $N$ be $N = 2^a \cdot p_1^{b_1} \cdot p_2^{b_2} \cdots p_k^{b_k}$, where $p_i$ are distinct odd prime numbers and $a, b_i \ge 0$.

Any divisor $d$ of $N$ can be expressed in the form $d = 2^x \cdot p_1^{y_1} \cdot p_2^{y_2} \cdots p_k^{y_k}$, where $0 \le x \le a$ and $0 \le y_i \le b_i$ for all $i$.

Now, let's consider the parity of a divisor $d$:
- **Odd Divisors**: A divisor $d$ is odd if and only if the exponent of 2 in its prime factorization is 0. This means $x$ must be 0. The odd divisors are of the form $p_1^{y_1} \cdot p_2^{y_2} \cdots p_k^{y_k}$, where $0 \le y_i \le b_i$. The number of such divisors is $(b_1+1)(b_2+1)\cdots(b_k+1)$. Let's denote this count as $g(N)$. Note that $g(N)$ is always at least 1, as $1$ is always an odd divisor (when all $y_i=0$).

- **Even Divisors**: A divisor $d$ is even if and only if the exponent of 2 in its prime factorization is greater than 0. This means $x$ can be any integer from $1$ to $a$. The even divisors are of the form $2^x \cdot p_1^{y_1} \cdot p_2^{y_2} \cdots p_k^{y_k}$, where $1 \le x \le a$ and $0 \le y_i \le b_i$. The number of choices for $x$ is $a$. The number of choices for $y_i$ is $(b_i+1)$. Therefore, the total number of even divisors is $a \cdot (b_1+1)(b_2+1)\cdots(b_k+1) = a \cdot g(N)$. Let's denote this count as $f(N)$.

We need to compare $f(N)$ and $g(N)$:
- $f(N) < g(N) \iff a \cdot g(N) < g(N)$. Since $g(N) \ge 1$, this inequality holds if and only if $a < 1$, which means $a=0$.
- $f(N) = g(N) \iff a \cdot g(N) = g(N)$. Since $g(N) \ge 1$, this equality holds if and only if $a = 1$.
- $f(N) > g(N) \iff a \cdot g(N) > g(N)$. Since $g(N) \ge 1$, this inequality holds if and only if $a > 1$.

Now, let's relate the value of $a$ to the properties of $N$:
1.  **$N$ is odd**: This means the exponent of 2 in its prime factorization is 0. So, $a=0$. In this case, $f(N) = 0 \cdot g(N) = 0$. Since $g(N) \ge 1$, we have $f(N) < g(N)$. The output should be `-1`.

2.  **$N$ is even but not divisible by 4**: This means $N$ is of the form $2 \times (\text{odd number})$. The exponent of 2 in its prime factorization is 1. So, $a=1$. In this case, $f(N) = 1 \cdot g(N) = g(N)$. The output should be `0`.

3.  **$N$ is divisible by 4**: This means $N$ is of the form $4 \times (\text{integer})$. The exponent of 2 in its prime factorization is 2 or more. So, $a \ge 2$. In this case, $f(N) = a \cdot g(N)$. Since $a \ge 2$ and $g(N) \ge 1$, we have $f(N) \ge 2 \cdot g(N) > g(N)$. The output should be `1`.

These three cases cover all possibilities for an integer $N$.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case. The solution only involves checking the divisibility of $N$ by 2 and 4, which are constant time operations.
- **Space Complexity**: $O(1)$ per test case. The solution uses a fixed amount of memory regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other useful headers

// Using the standard namespace for brevity as allowed by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        // Case 1: N is odd.
        // The exponent of 2 in N's prime factorization is 0 (a=0).
        // Number of even divisors f(N) = a * g(N) = 0 * g(N) = 0.
        // Number of odd divisors g(N) is always at least 1.
        // Therefore, f(N) < g(N).
        cout << -1 << "\n";
    } else if (N % 4 != 0) {
        // Case 2: N is even but not divisible by 4.
        // This means N is of the form 2 * (odd number).
        // The exponent of 2 in N's prime factorization is 1 (a=1).
        // Number of even divisors f(N) = a * g(N) = 1 * g(N) = g(N).
        // Therefore, f(N) = g(N).
        cout << 0 << "\n";
    } else {
        // Case 3: N is divisible by 4.
        // This means N is of the form 4 * (some integer).
        // The exponent of 2 in N's prime factorization is 2 or more (a >= 2).
        // Number of even divisors f(N) = a * g(N).
        // Since a >= 2 and g(N) >= 1, we have f(N) = a * g(N) >= 2 * g(N) > g(N).
        // Therefore, f(N) > g(N).
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup to speed up input and output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0;
}
```