# [Make A and B equal (EQUALISE)](https://www.codechef.com/problems/EQUALISE)
- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether two given positive integers, `A` and `B`, can be made equal by repeatedly applying a specific operation. The allowed operation is: choose either `A` or `B` and multiply it by 2. We need to determine if it's possible to reach a state where `A` equals `B` using any number of these operations.

## Intuition & Mathematical Observation

Let's analyze the effect of the allowed operation: multiplying a number by 2.

Any positive integer `N` can be uniquely represented in the form `N = O * 2^P`, where `O` is an odd integer (its largest odd divisor) and `P` is a non-negative integer (the power of 2 in its prime factorization).

When we multiply `N` by 2, it becomes `N * 2 = (O * 2^P) * 2 = O * 2^(P+1)`.
Notice that the odd part `O` remains unchanged; only the power of 2 (`P`) increases.

If we want to make `A` and `B` equal to some common value `X` by repeatedly multiplying by 2:
1.  If `A` can be transformed into `X`, then `X` must have the same largest odd divisor as `A`.
2.  If `B` can be transformed into `X`, then `X` must have the same largest odd divisor as `B`.

For `A` and `B` to be transformable into the *same* `X`, it logically follows that `A` and `B` must have the same largest odd divisor. If their largest odd divisors are different, say `O_A` and `O_B` where `O_A != O_B`, then no matter how many times we multiply `A` or `B` by 2, their odd parts will never change, and thus they can never become equal.

Conversely, if `A` and `B` *do* have the same largest odd divisor, let's call it `O`. Then `A = O * 2^P_A` and `B = O * 2^P_B` for some non-negative integers `P_A` and `P_B`. Without loss of generality, assume `P_A <= P_B`. We can multiply `A` by 2 exactly `(P_B - P_A)` times. This will transform `A` into `O * 2^(P_A + (P_B - P_A)) = O * 2^P_B`, which is equal to `B`. Thus, if their largest odd divisors are the same, they can always be made equal.

Therefore, the problem reduces to checking if `A` and `B` have the same largest odd divisor.

**Algorithm:**
1.  For each test case, read `A` and `B`.
2.  Calculate the largest odd divisor of `A` by repeatedly dividing `A` by 2 until it becomes odd.
3.  Calculate the largest odd divisor of `B` using the same method.
4.  If these two largest odd divisors are equal, print "YES". Otherwise, print "NO".

## Complexity Analysis

*   **`get_largest_odd_divisor(int n)` function**:
    This function repeatedly divides `n` by 2 until it becomes odd. The number of divisions is equal to the exponent of 2 in the prime factorization of `n`, which is $\log_2 n$. For `n` up to $10^9$, $\log_2 10^9 \approx 30$. So, this function runs in $O(\log N)$ time.

*   **Time Complexity**:
    For each test case, we call `get_largest_odd_divisor` twice (once for `A` and once for `B`). This takes $O(\log A + \log B)$ time. Since there are `T` test cases, the total time complexity is $O(T \cdot (\log A + \log B))$. Given $A, B \le 10^9$ and $T \le 1000$, this is approximately $1000 \cdot (30 + 30) = 60000$ operations, which is very efficient and well within typical time limits.
    More precisely, it's $O(T \cdot \log(\max(A, B)))$.

*   **Space Complexity**:
    The solution uses a few integer variables to store `T`, `A`, `B`, and their largest odd divisors. No data structures that grow with the input size are used. Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace, as requested.
using namespace std;

// Function to get the largest odd divisor of a number.
// This is done by repeatedly dividing the number by 2 until it becomes odd.
int get_largest_odd_divisor(int n) {
    // Since constraints are 1 <= A, B, n will always be positive.
    // The loop continues as long as n is even.
    while (n % 2 == 0) {
        n /= 2;
    }
    return n; // The remaining n is the largest odd divisor
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T each iteration
        int A, B;
        cin >> A >> B; // Read the two numbers A and B for the current test case

        // Calculate the largest odd divisor for both A and B.
        // If A can be transformed into X and B can be transformed into X,
        // then X must have the same largest odd divisor as A, and also as B.
        // Therefore, A and B must have the same largest odd divisor initially.
        int odd_A = get_largest_odd_divisor(A);
        int odd_B = get_largest_odd_divisor(B);

        // Compare the largest odd divisors.
        if (odd_A == odd_B) {
            // If they are equal, Chef can make A and B equal.
            // For example, if A = odd_A * 2^p and B = odd_B * 2^q,
            // and odd_A == odd_B, then we can multiply the number with the smaller
            // power of 2 until its power of 2 matches the other.
            cout << "YES\n";
        } else {
            // If they are not equal, Chef cannot make A and B equal,
            // because multiplying by 2 only changes the power of 2 factor,
            // not the odd part.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution
}
```