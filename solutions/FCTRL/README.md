# [Factorial (FCTRL)](https://www.codechef.com/problems/FCTRL)

- **Difficulty Rating**: 878
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, calculate the number of trailing zeros in the decimal representation of $N!$ (N factorial). Since $N$ can be as large as $10^9$, calculating the factorial directly is impossible due to integer overflow and time constraints.

## Intuition & Mathematical Observation
A trailing zero is created by the product of $2 \times 5$. In the prime factorization of $N!$, the number of trailing zeros is determined by the number of pairs of $(2, 5)$. 

Since there are always significantly more factors of $2$ than factors of $5$ in any factorial, the number of trailing zeros is strictly limited by the number of times the prime factor $5$ appears in the prime factorization of $N!$.

According to **Legendre's Formula**, the exponent of a prime $p$ in the prime factorization of $N!$ is:
$$E_p(N!) = \sum_{k=1}^{\infty} \lfloor \frac{N}{p^k} \rfloor$$

For $p=5$, the number of trailing zeros $Z(N)$ is:
$$Z(N) = \lfloor \frac{N}{5} \rfloor + \lfloor \frac{N}{25} \rfloor + \lfloor \frac{N}{125} \rfloor + \dots$$

We can implement this efficiently by repeatedly dividing $N$ by $5$ and accumulating the quotient until $N$ becomes less than $5$.

## Complexity Analysis
- **Time Complexity**: $O(\log_5 N)$ per test case. Given $N \le 10^9$, $\log_5(10^9) \approx 13$ iterations, which is highly efficient for the given constraints.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the running count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The number of trailing zeros in N! is determined by the number of times 
 * the factor 5 appears in the prime factorization of N!.
 * 
 * Using Legendre's Formula:
 * Z(N) = floor(N/5) + floor(N/25) + floor(N/125) + ...
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    long long count = 0;
    // We divide n by powers of 5 to count the factors of 5
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```