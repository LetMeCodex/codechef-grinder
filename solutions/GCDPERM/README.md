# Subset GCD (GCDPERM)
- **Difficulty Rating**: 1362
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, we need to find a subset of size $K$ from the set of integers $\{1, 2, \dots, N\}$ such that the greatest common divisor (GCD) of all elements in the subset is maximized. We need to output any such subset.

## Intuition & Mathematical Observation

The problem asks us to maximize the GCD of a subset of size $K$ from the range $[1, N]$. Let the subset be $S = \{a_1, a_2, \dots, a_K\}$, where $1 \le a_i \le N$ for all $i$. We want to maximize $\text{gcd}(a_1, a_2, \dots, a_K)$.

If a number $g$ is the GCD of a set of numbers, then every number in that set must be a multiple of $g$.
So, if we want the GCD of our subset to be $g$, then every element in the subset must be of the form $m \cdot g$ for some integer $m$.

To maximize $g$, we should try to pick the largest possible multiples of $g$ that are still within the range $[1, N]$.
Consider a potential GCD value $g$. If we want to form a subset of size $K$ with GCD $g$, we need to find $K$ distinct multiples of $g$ that are less than or equal to $N$. The smallest $K$ distinct positive multiples of $g$ are $g, 2g, 3g, \dots, Kg$.

For these $K$ multiples to be valid elements of our subset, they must all be less than or equal to $N$. The largest of these multiples is $Kg$. Therefore, we must have $Kg \le N$. This implies $g \le \frac{N}{K}$.

Since we want to maximize $g$, the largest possible integer value for $g$ that satisfies $g \le \frac{N}{K}$ is $\lfloor \frac{N}{K} \rfloor$.
Let $g_{max} = \lfloor \frac{N}{K} \rfloor$.

Now, we need to check if we can actually form a subset of size $K$ with GCD equal to $g_{max}$.
Consider the set of the first $K$ multiples of $g_{max}$:
$\{1 \cdot g_{max}, 2 \cdot g_{max}, 3 \cdot g_{max}, \dots, K \cdot g_{max}\}$.

All these numbers are multiples of $g_{max}$.
The largest number in this set is $K \cdot g_{max}$.
Since $g_{max} = \lfloor \frac{N}{K} \rfloor$, we know that $g_{max} \le \frac{N}{K}$.
Multiplying by $K$ (which is positive), we get $K \cdot g_{max} \le K \cdot \frac{N}{K} = N$.
So, all elements $1 \cdot g_{max}, 2 \cdot g_{max}, \dots, K \cdot g_{max}$ are indeed less than or equal to $N$.

The GCD of the set $\{1 \cdot g_{max}, 2 \cdot g_{max}, \dots, K \cdot g_{max}\}$ is $g_{max} \cdot \text{gcd}(1, 2, \dots, K)$.
The GCD of the first $K$ positive integers is always 1.
Therefore, $\text{gcd}(1 \cdot g_{max}, 2 \cdot g_{max}, \dots, K \cdot g_{max}) = g_{max} \cdot 1 = g_{max}$.

This construction provides a subset of size $K$ from $\{1, 2, \dots, N\}$ whose GCD is $g_{max} = \lfloor \frac{N}{K} \rfloor$. Since we established that the GCD cannot be larger than $\lfloor \frac{N}{K} \rfloor$, this is indeed the maximum possible GCD.

Thus, the strategy is to calculate $g_{max} = \lfloor \frac{N}{K} \rfloor$ and output the subset $\{1 \cdot g_{max}, 2 \cdot g_{max}, \dots, K \cdot g_{max}\}$.

## Complexity Analysis
- **Time Complexity**: $O(K)$
    The dominant part of the algorithm is the loop that prints the $K$ elements of the subset. This loop runs $K$ times. The calculation of `max_gcd` takes constant time. Therefore, the total time complexity is $O(K)$.

- **Space Complexity**: $O(1)$
    The algorithm uses a few variables to store $N$, $K$, `max_gcd`, and loop counters. The amount of memory used does not depend on the input size $N$ or $K$ (beyond what's needed for the output itself, which is not typically counted in space complexity). Thus, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common C++ libraries, as requested

// Use the standard namespace, as requested
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // Calculate the maximum possible GCD.
    // As derived, this is floor(N/K). Integer division in C++
    // automatically computes the floor for positive numbers.
    int max_gcd = n / k;

    // Print the K-sized subset. The simplest subset with GCD 'max_gcd'
    // is {max_gcd, 2*max_gcd, ..., K*max_gcd}.
    // All these numbers are <= N because K * max_gcd <= K * (N/K) = N.
    for (int i = 1; i <= k; ++i) {
        cout << i * max_gcd << (i == k ? "" : " ");
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```