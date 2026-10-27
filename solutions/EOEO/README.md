# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)
- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary

Tom starts with `TS` energy. Jerry chooses an initial energy `JS` such that `1 <= JS <= TS`.
The problem states:
- Tom wins if `TS` is an even multiple of `JS`.
- Jerry wins if `TS` is an odd multiple of `JS`.

The goal is to find the number of possible values for `JS` (from `1` to `TS`) for which Jerry wins.

## Intuition & Mathematical Observation

The problem statement can be a bit tricky. A literal interpretation of "Tom wins if `TS` is an even multiple of `JS`" means `TS = k * JS` where `k` is an even integer. Similarly, for Jerry to win, `TS = k * JS` where `k` is an odd integer. If `TS` is not a multiple of `JS`, neither wins.

However, the provided solution code (which passed) suggests a different, more common interpretation in competitive programming for problems involving "even/odd multiples" or "powers of 2". Let's analyze the code's logic to understand the actual winning condition.

Let $v_2(X)$ denote the exponent of the highest power of 2 that divides $X$. For example, $v_2(12) = 2$ because $12 = 2^2 \times 3$, and $v_2(7) = 0$ because $7 = 2^0 \times 7$.

The code's logic can be unified as follows:
Jerry wins if and only if $v_2(JS) > v_2(TS)$.
We need to count the number of `JS` values such that $1 \le JS \le TS$ and $v_2(JS) > v_2(TS)$.

Let $p = v_2(TS)$. The condition $v_2(JS) > v_2(TS)$ means $v_2(JS) \ge p+1$.
This implies that `JS` must be a multiple of $2^{p+1}$.
So, we need to count the number of multiples of $2^{p+1}$ that are less than or equal to `TS`.

The multiples of $2^{p+1}$ are $1 \cdot 2^{p+1}, 2 \cdot 2^{p+1}, 3 \cdot 2^{p+1}, \dots$.
The largest multiple of $2^{p+1}$ that is $\le TS$ is $k \cdot 2^{p+1}$ where $k = \lfloor \frac{TS}{2^{p+1}} \rfloor$.
Since $k$ must be a positive integer, the number of such values is simply $\lfloor \frac{TS}{2^{p+1}} \rfloor$. In C++, integer division `TS / (1LL << (p+1))` directly computes this for positive numbers.

Let's verify this unified logic with the two cases in the code:

1.  **If `TS` is odd**:
    In this case, $TS = 2^0 \times TS_{odd}$, so $p = v_2(TS) = 0$.
    According to our unified logic, Jerry wins if $v_2(JS) \ge 0+1 = 1$. This means `JS` must be an even number.
    We need to count even numbers `JS` such that $1 \le JS \le TS$.
    The even numbers are $2, 4, 6, \dots, TS-1$ (since `TS` is odd, `TS-1` is even).
    The count of these numbers is $(TS-1)/2$.
    This matches the code's logic for the `TS % 2 != 0` case.

2.  **If `TS` is even**:
    First, we find $p = v_2(TS)$ by repeatedly dividing `TS` by 2 until it becomes odd.
    Let $TS = 2^p \times TS_{odd}$, where $TS_{odd}$ is odd.
    According to our unified logic, Jerry wins if $v_2(JS) \ge p+1$.
    This means `JS` must be a multiple of $2^{p+1}$.
    We need to count multiples of $2^{p+1}$ that are $\le TS$.
    The count is $TS / (2^{p+1})$.
    This matches the code's logic for the `TS % 2 == 0` case, where `target_divisor = 1LL << (p+1)`.

Therefore, the core observation for this problem, as implemented by the solution, is that Jerry wins if `JS` has a strictly greater power of 2 in its prime factorization than `TS`.

## Complexity Analysis

-   **Time Complexity**: $O(T \log TS)$
    -   For each test case, the `solve()` function performs:
        -   An $O(1)$ check for `TS` parity.
        -   If `TS` is odd, an $O(1)$ calculation.
        -   If `TS` is even, a `while` loop to find `p`. This loop divides `TS` by 2 repeatedly until it becomes odd. The number of divisions is $p = v_2(TS)$, which is at most $\log_2(TS)$. Thus, this step takes $O(\log TS)$ time.
        -   Subsequent calculations are $O(1)$.
    -   Since there are $T$ test cases, the total time complexity is $O(T \log TS)$. Given $TS \le 10^{18}$, $\log_2(10^{18}) \approx 18 \log_2(10) \approx 18 \times 3.32 \approx 59.79$, so $\log TS$ is very small.

-   **Space Complexity**: $O(1)$
    -   The solution uses a few `long long` and `int` variables to store `TS`, `temp_TS`, `p`, `target_divisor`, and `t`. This requires a constant amount of auxiliary space, independent of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // As requested by the problem statement

using namespace std; // As requested by the problem statement

void solve() {
    long long TS;
    cin >> TS;

    if (TS % 2 != 0) { // TS is odd
        // If TS is odd, v_2(TS) = 0.
        // Jerry wins if v_2(JS) > v_2(TS), which means v_2(JS) >= 1 (JS is even).
        // We need to count even JS values such that 1 <= JS <= TS.
        // The even values are 2, 4, 6, ..., (TS - 1) (since TS is odd, TS-1 is even).
        // The count of these values is (TS - 1) / 2.
        cout << (TS - 1) / 2 << "\n";
    } else { // TS is even
        // If TS is even, let TS = 2^p * TS_odd, where TS_odd is an odd number.
        // So, v_2(TS) = p.
        // Jerry wins if v_2(JS) > v_2(TS), which means v_2(JS) >= p+1.
        // This implies JS must be a multiple of 2^(p+1).

        // Step 1: Find p, the number of factors of 2 in TS (i.e., v_2(TS)).
        long long temp_TS = TS;
        int p = 0;
        while (temp_TS % 2 == 0) { // TS >= 1, so temp_TS will be positive until it becomes odd.
            temp_TS /= 2;
            p++;
        }

        // Step 2: Calculate the target divisor, which is 2^(p+1).
        // We use 1LL to ensure the shift operation is performed on a long long,
        // preventing overflow if p+1 is large (e.g., > 30 for int, TS up to 10^18 means p can be up to ~60).
        long long target_divisor = 1LL << (p + 1);

        // Step 3: Count the number of multiples of target_divisor that are <= TS.
        // These are 1 * target_divisor, 2 * target_divisor, ..., k * target_divisor.
        // The largest k satisfies k * target_divisor <= TS, so k <= TS / target_divisor.
        // Since k must be a positive integer, the number of possible values for k is floor(TS / target_divisor).
        // Integer division in C++ automatically performs floor for positive numbers.
        cout << TS / target_divisor << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}
```