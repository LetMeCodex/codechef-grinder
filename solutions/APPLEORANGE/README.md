# [Apples and oranges (APPLEORANGE)](https://www.codechef.com/problems/APPLEORANGE)
- **Difficulty Rating**: 1040
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of contestants such that we can distribute $N$ apples and $M$ oranges equally among them. This means that each contestant must receive the same number of apples, and each contestant must receive the same number of oranges.

## Intuition & Mathematical Observation
Let $K$ be the number of contestants.
For the apples to be distributed equally among $K$ contestants, the total number of apples $N$ must be perfectly divisible by $K$. This can be expressed as $N \pmod K = 0$.
Similarly, for the oranges to be distributed equally among $K$ contestants, the total number of oranges $M$ must be perfectly divisible by $K$. This can be expressed as $M \pmod K = 0$.

We are looking for the *maximum* possible value of $K$ that satisfies both conditions.
In mathematical terms, we are looking for the largest integer $K$ that is a common divisor of both $N$ and $M$. This is precisely the definition of the Greatest Common Divisor (GCD) of $N$ and $M$.

Therefore, the solution to the problem is to compute the GCD of $N$ and $M$.

## Complexity Analysis
- **Time Complexity**: $O(\log(\min(N, M)))$
    The `std::gcd` function in C++ typically uses the Euclidean algorithm. The time complexity of the Euclidean algorithm for finding the GCD of two numbers $a$ and $b$ is logarithmic with respect to the smaller of the two numbers, i.e., $O(\log(\min(a, b)))$. In this problem, $N$ and $M$ can be up to $10^9$, so the time complexity per test case is $O(\log(\min(N, M)))$. Since there are $T$ test cases, the total time complexity is $O(T \log(\min(N, M)))$.

- **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `T`, `N`, `M`, and `result`. The `std::gcd` function also uses a constant amount of space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, numeric, and other standard libraries as requested

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing each test case.
    while (T--) {
        long long N, M; // Declare two long long variables for N (number of apples)
                        // and M (number of oranges).
                        // 'long long' is used to safely handle input values up to 10^9.
        cin >> N >> M; // Read N and M for the current test case.

        // Calculate the Greatest Common Divisor (GCD) of N and M.
        // The std::gcd function is part of the C++ Standard Library (available since C++17)
        // and is typically found in the <numeric> header.
        // The GCD represents the maximum number of contestants such that
        // both N apples and M oranges can be divided equally among them.
        long long result = std::gcd(N, M);

        // Print the calculated result followed by a newline character.
        // Using "\n" instead of std::endl is generally preferred in competitive programming
        // for performance, as "\n" only adds a newline character, while std::endl also
        // forces a flush of the output buffer, which can be slower.
        cout << result << "\n";
    }

    return 0; // Indicate successful program execution.
}
```