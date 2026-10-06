# [Relativity (RELATIVE)](https://www.codechef.com/problems/RELATIVE)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the maximum height `H` that a person can jump on a planet, given the planet's gravitational acceleration `g` and the speed of light `c`. The problem provides a direct formula for this calculation: `H = c^2 / (2 * g)`. We are given `T` test cases, and for each test case, we need to read `g` and `c`, then output the calculated height `H`. The problem guarantees that `c^2` is always divisible by `2 * g`, implying that `H` will always be an integer.

## Intuition & Mathematical Observation
The core of this problem lies in the direct application of the provided formula: `H = c^2 / (2 * g)`.

1.  **Direct Formula Application**: The most straightforward approach is to implement the given formula directly. There's no complex algorithm or data structure required; it's a simple arithmetic calculation.
2.  **Integer Arithmetic**: The problem statement explicitly guarantees that `c^2` is perfectly divisible by `2 * g`. This is a crucial detail, as it means we can perform integer division without worrying about precision issues that might arise with floating-point numbers. The result `H` will always be an integer.
3.  **Handling Large Values (Potential Overflow)**: The constraints for `c` are up to $10^9$. When `c` is squared (`c*c`), the result can be as large as $(10^9)^2 = 10^{18}$. A standard 32-bit integer (`int` in C++) can typically store values up to approximately $2 \times 10^9$. Therefore, `c*c` would overflow an `int`. To correctly store `c^2` and subsequently `H`, we must use a 64-bit integer type, such as `long long` in C++. The solution code correctly addresses this by casting `c` to `long long` before multiplication to ensure the product is computed using `long long` arithmetic.

## Complexity Analysis
-   **Time Complexity**: $O(T)$
    For each of the `T` test cases, the solution performs a constant number of arithmetic operations (one multiplication, one division). These operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, making it $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory regardless of the input values or the number of test cases. It only stores a few variables (`T`, `g`, `c`, `c_squared`, `H`) at any given time. This constant memory usage leads to a space complexity of $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int g, c; // Declare integer variables g (gravity) and c (speed of light).
        cin >> g >> c; // Read g and c for the current test case.

        // Calculate c^2.
        // We cast 'c' to 'long long' before multiplication to ensure that
        // the product c*c is computed as a long long. This is crucial
        // because 'c' can be up to 10^9, making 'c*c' up to 10^18,
        // which would overflow a standard 32-bit integer type (int).
        long long c_squared = (long long)c * c;

        // Calculate the required height H using the formula H = c^2 / (2 * g).
        // The problem guarantees that (2 * g) divides c^2, so the result will be an integer.
        long long H = c_squared / (2 * g);

        // Output the calculated height H, followed by a newline character.
        cout << H << "\n";
    }

    return 0; // Indicate successful program execution.
}
```