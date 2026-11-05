# Nearest Square (NEARSQ)

- **Difficulty Rating**: 570
- **Solved in**: 1 attempt(s)

## Problem Summary

Given an integer $N$, find the largest perfect square that is less than or equal to $N$.

## Intuition & Mathematical Observation

The problem asks us to find the largest perfect square that does not exceed a given number $N$. A perfect square is an integer that is the square of another integer. For example, $0, 1, 4, 9, 16, 25, \dots$ are perfect squares ($0^2, 1^2, 2^2, 3^2, 4^2, 5^2, \dots$).

Let the largest perfect square less than or equal to $N$ be $S$. This means $S = k^2$ for some non-negative integer $k$, and $k^2 \le N$. We want to find the maximum such $k^2$.

If we consider the square root of $N$, denoted by $\sqrt{N}$, we know that $k^2 \le N$ implies $k \le \sqrt{N}$. Since we are looking for the largest integer $k$ that satisfies this condition, $k$ must be the floor of $\sqrt{N}$. In other words, $k = \lfloor \sqrt{N} \rfloor$.

Once we find this integer $k$, the largest perfect square less than or equal to $N$ will be $k^2$.

For example:
- If $N = 10$, $\sqrt{10} \approx 3.16$. The floor of $3.16$ is $3$. So, $k=3$. The nearest square is $3^2 = 9$.
- If $N = 25$, $\sqrt{25} = 5$. The floor of $5$ is $5$. So, $k=5$. The nearest square is $5^2 = 25$.
- If $N = 24$, $\sqrt{24} \approx 4.89$. The floor of $4.89$ is $4$. So, $k=4$. The nearest square is $4^2 = 16$.

The C++ `sqrt()` function typically returns a `double`. Casting this `double` to an `int` in C++ truncates the decimal part, which is equivalent to the floor operation for non-negative numbers. Therefore, `static_cast<int>(sqrt(N))` will give us the desired integer $k$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The `sqrt()` function and basic arithmetic operations take constant time. The number of test cases $T$ does not affect the complexity of processing a single test case.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of extra space for variables like $N$, $B$, $T$, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc.
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Calculate the integer part of the square root of N.
    // The sqrt function returns a double. Casting to int truncates the decimal part,
    // effectively performing the floor operation for positive numbers.
    // For example:
    // if N=10, sqrt(10) is approx 3.16. static_cast<int>(3.16) gives 3.
    // if N=9, sqrt(9) is 3.0. static_cast<int>(3.0) gives 3.
    int B = static_cast<int>(sqrt(N));
    
    // The largest square less than or equal to N is B*B.
    // This is because B is the largest integer such that B*B <= N.
    // (B+1)*(B+1) would be greater than N.
    cout << B * B << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful program execution
}
```