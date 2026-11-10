# [Add 1 or 3 (ADD13)](https://www.codechef.com/problems/ADD13)
- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a specific target sum `M` can be achieved after exactly `N` turns. We start with a total of 0. In each of the `N` turns, we have two choices: either add 1 to our current total or add 3 to our current total. We need to output "YES" if `M` is achievable, and "NO" otherwise.

## Intuition & Mathematical Observation

Let's define our variables:
- `N`: The total number of turns available.
- `M`: The target final sum we want to achieve.

Suppose that in the `N` turns, we choose to add 3 exactly `k` times.
Since there are `N` turns in total, the number of times we must have chosen to add 1 will be `N - k`.

The total sum `X` accumulated after `N` turns can be expressed as:
$X = (k \times 3) + ((N - k) \times 1)$
Let's simplify this equation:
$X = 3k + N - k$
$X = 2k + N$

We are interested in whether the target sum `M` can be achieved. So, we set our derived sum `X` equal to `M`:
$M = 2k + N$

Now, we need to determine if there exists an integer `k` that satisfies this equation and is also valid within the problem constraints. Let's solve for `k`:
$M - N = 2k$
$k = \frac{M - N}{2}$

For `M` to be achievable, `k` must satisfy three crucial conditions:

1.  **`k` must be non-negative**: The number of times we add 3 cannot be a negative value.
    $k \ge 0$
    Substituting the expression for `k`:
    $\frac{M - N}{2} \ge 0$
    Since 2 is positive, we can multiply both sides by 2 without changing the inequality direction:
    $M - N \ge 0$
    $M \ge N$
    *   **Interpretation**: The minimum possible sum we can achieve in `N` turns is `N` (by adding 1 in all `N` turns). If the target `M` is less than this minimum, it's impossible.

2.  **`k` must not exceed `N`**: The number of times we add 3 cannot be more than the total number of turns `N`.
    $k \le N$
    Substituting the expression for `k`:
    $\frac{M - N}{2} \le N$
    Multiply both sides by 2:
    $M - N \le 2N$
    Add `N` to both sides:
    $M \le 3N$
    *   **Interpretation**: The maximum possible sum we can achieve in `N` turns is `3N` (by adding 3 in all `N` turns). If the target `M` is greater than this maximum, it's impossible.

3.  **`k` must be an integer**: The number of times we add 3 must be a whole number.
    This implies that $(M - N)$ must be an even number.
    $(M - N) \pmod 2 = 0$
    *   **Interpretation**: This condition is equivalent to saying that `M` and `N` must have the same parity (both even or both odd). If `M - N` is odd, then `k` would be a fraction, which is not possible for a count of turns.

If all three conditions (`M >= N`, `M <= 3N`, and `(M - N) % 2 == 0`) are met, then it is possible to achieve the target sum `M`, and we output "YES". Otherwise, if any of these conditions are violated, it is not possible, and we output "NO".

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution involves a few basic arithmetic operations (subtraction, division, modulo) and comparisons. These operations are constant time operations. Therefore, if there are `T` test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: The solution uses a fixed number of variables (`N`, `M`, `T`) to store input and perform calculations. The memory usage does not grow with the input size. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid prefixing std:: to standard library components
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, M; // Declare N and M as long long to handle values up to 10^9.
                    // This is crucial because 3 * N can be up to 3 * 10^9,
                    // which exceeds the typical 2 * 10^9 limit of a 32-bit signed integer.
    cin >> N >> M; // Read the number of turns (N) and the target final value (M)

    // Let 'k' be the number of times we choose to add 3.
    // Since there are N turns in total, the number of times we add 1 must be (N - k).
    // The total sum X will be:
    // X = (k * 3) + ((N - k) * 1)
    // X = 3k + N - k
    // X = 2k + N

    // We are checking if it's possible for the final value X to be M.
    // So, we need to find if there exists an integer 'k' such that:
    // M = 2k + N

    // From this equation, we can derive 'k':
    // M - N = 2k
    // k = (M - N) / 2

    // For 'M' to be achievable, 'k' must satisfy three conditions:

    // Condition 1: 'k' must be a non-negative number of turns.
    // This means k >= 0.
    // (M - N) / 2 >= 0  =>  M - N >= 0  =>  M >= N.
    // The minimum possible sum is N (achieved by adding 1 in all N turns).
    // If M is less than N, it's impossible.
    if (M < N) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // Condition 2: 'k' cannot exceed the total number of turns N.
    // This means k <= N.
    // (M - N) / 2 <= N  =>  M - N <= 2N  =>  M <= 3N.
    // The maximum possible sum is 3N (achieved by adding 3 in all N turns).
    // If M is greater than 3N, it's impossible.
    if (M > 3 * N) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // Condition 3: 'k' must be an integer.
    // This means (M - N) must be an even number, so (M - N) % 2 must be 0.
    // This is equivalent to M and N having the same parity (both even or both odd).
    if ((M - N) % 2 != 0) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // If all three conditions are met, it is possible to form M.
    cout << "YES\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input
    while (T--) { // Loop T times, processing one test case in each iteration
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```