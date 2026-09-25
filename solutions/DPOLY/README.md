# [Degree of Polynomial (DPOLY)](https://www.codechef.com/problems/DPOLY)
- **Difficulty Rating**: 793
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the degree of a polynomial given its coefficients. A polynomial is represented as $A_0 + A_1x + A_2x^2 + \dots + A_{N-1}x^{N-1}$, where $A_i$ are the coefficients. The degree of a polynomial is defined as the highest power of $x$ whose coefficient is non-zero. If all coefficients are zero (i.e., it's the zero polynomial), its degree is considered to be -1. We are given $N$, the number of coefficients, followed by $N$ integers representing $A_0, A_1, \dots, A_{N-1}$.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the definition of a polynomial's degree. For a polynomial $P(x) = A_0 + A_1x + A_2x^2 + \dots + A_{N-1}x^{N-1}$:
1. Each term $A_i x^i$ has a degree of $i$.
2. The degree of the entire polynomial is the maximum index $i$ for which the coefficient $A_i$ is non-zero.
3. If all coefficients $A_i$ are zero, the polynomial is the zero polynomial, and its degree is -1.

Based on this definition, we can iterate through the coefficients from $A_0$ up to $A_{N-1}$. We maintain a variable, say `max_degree`, initialized to -1 (to handle the zero polynomial case). As we read each coefficient $A_i$:
- If $A_i$ is non-zero, it means that the term $x^i$ is present in the polynomial. Since we are iterating from lower powers ($i=0$) to higher powers ($i=N-1$), any non-zero $A_i$ we encounter means that the current degree is at least $i$. We update `max_degree` to $i$.
- If $A_i$ is zero, this term does not contribute to the degree, so we simply ignore it and move to the next coefficient.

By the end of the iteration, `max_degree` will hold the largest index $i$ for which $A_i$ was non-zero. If no $A_i$ was ever non-zero, `max_degree` will remain -1, which is the correct output for the zero polynomial.

Let's consider an example:
$N=5$, coefficients $A = [1, 0, 5, 0, 3]$
The polynomial is $1 + 0x + 5x^2 + 0x^3 + 3x^4$.
1. Initialize `max_degree = -1`.
2. Read $A_0 = 1$. Since $1 \neq 0$, update `max_degree = 0$.
3. Read $A_1 = 0$. No change.
4. Read $A_2 = 5$. Since $5 \neq 0$, update `max_degree = 2$.
5. Read $A_3 = 0$. No change.
6. Read $A_4 = 3$. Since $3 \neq 0$, update `max_degree = 4$.
After processing all coefficients, `max_degree` is 4. This is the correct degree of the polynomial.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    For each test case, we read $N$ coefficients and perform a constant number of operations (comparison and assignment) for each coefficient. This results in a linear scan of the coefficients. Given $T$ test cases, the total time complexity will be $O(T \cdot N)$. With $N$ up to $10^5$ and $T$ up to $10$, the total operations are around $10 \cdot 10^5 = 10^6$, which is well within typical time limits.

-   **Space Complexity**: $O(N)$ per test case.
    We use a `std::vector<int> a` to store all $N$ coefficients. This requires $O(N)$ space. Other variables like `t`, `n`, `max_degree`, and loop counter `i` consume $O(1)$ space. With $N$ up to $10^5$, storing $10^5$ integers (each typically 4 bytes) requires about 400 KB, which is well within typical memory limits (e.g., 256 MB).

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for using std::vector to store coefficients
#include <algorithm> // Not strictly needed for this solution, but often included for competitive programming

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer 't' to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop 't' times, decrementing 't' in each iteration
        int n; // Declare an integer 'n' to store the number of coefficients for the current test case
        std::cin >> n; // Read the number of coefficients

        // Declare a vector 'a' of size 'n' to store the coefficients.
        // a[i] will store the coefficient of x^i.
        std::vector<int> a(n);

        // Initialize max_degree to -1.
        // This handles the case of a zero polynomial (all coefficients are 0),
        // where the degree is defined as -1.
        int max_degree = -1;

        // Loop through each coefficient from index 0 to n-1.
        // The index 'i' directly corresponds to the power of x (x^i).
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read the i-th coefficient into a[i]

            // If the current coefficient a[i] is not zero, it means x^i is a term
            // in the polynomial. Since we are iterating from lower powers to higher powers,
            // the last 'i' for which a[i] is non-zero will represent the highest degree.
            if (a[i] != 0) {
                max_degree = i; // Update max_degree to the current power 'i'
            }
        }

        // After iterating through all coefficients, max_degree will hold the highest power
        // with a non-zero coefficient, or -1 if all coefficients were zero.
        std::cout << max_degree << "\n"; // Print the calculated maximum degree followed by a newline
    }

    return 0; // Indicate successful program execution
}

```