# [Break the Stick (BREAKSTICK)](https://www.codechef.com/problems/BREAKSTICK)
- **Difficulty Rating**: 1026
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a stick of length $N$. We can break this stick into two pieces of integer lengths. We are also given a target length $X$. We want to determine if it's possible to obtain a piece of length $X$ by repeatedly breaking the stick. Each break must result in two pieces with positive integer lengths.

## Intuition & Mathematical Observation

Let's analyze the possible lengths we can obtain.
Initially, we have a stick of length $N$.

**Case 1: We want to obtain a piece of length $X$, and $X$ is odd.**
If we want to obtain a piece of length $X$, and $X$ is odd, we can always achieve this.
Consider the initial stick of length $N$.
If $N$ is odd and $X$ is odd, we can break the stick into pieces of length $X$ and $N-X$. Since $N$ and $X$ are both odd, $N-X$ will be even. This is a valid break as long as $N-X > 0$. If $N=X$, we already have the piece.
If $N$ is even and $X$ is odd, we can break the stick into pieces of length $X$ and $N-X$. Since $N$ is even and $X$ is odd, $N-X$ will be odd. This is a valid break as long as $N-X > 0$.

The key observation is that any break of a stick of length $L$ into two pieces of lengths $a$ and $b$ ($a+b=L$, $a>0$, $b>0$) preserves the parity of the sum of lengths. If we are aiming for a piece of odd length $X$, we can always try to make a cut such that one piece is $X$. The other piece will have length $N-X$.
If $X$ is odd, we can always make a cut to get $X$ if $N \ge X$.
If $N$ is odd, we can cut $N$ into $X$ (odd) and $N-X$ (even).
If $N$ is even, we can cut $N$ into $X$ (odd) and $N-X$ (odd).
In both scenarios, if $X$ is odd, we can obtain it as long as $N \ge X$. The problem statement implies we can always make a cut if $N > 1$. If $N=X$, we already have the piece. If $N > X$, we can cut $N$ into $X$ and $N-X$. Since $X$ is odd, $N-X$ will have the same parity as $N$. If $N-X > 0$, this is a valid cut. The problem doesn't restrict the parity of the other piece, only that it must be a positive integer. So, if $X$ is odd, we can always obtain it.

**Case 2: We want to obtain a piece of length $X$, and $X$ is even.**
If $X$ is even, we can only obtain it if the initial stick length $N$ is also even.
Let's consider the parity of the lengths.
If we break a stick of length $L$ into two pieces of lengths $a$ and $b$, where $a+b=L$.
- If $L$ is even:
    - $a$ (even) + $b$ (even) = $L$ (even)
    - $a$ (odd) + $b$ (odd) = $L$ (even)
- If $L$ is odd:
    - $a$ (even) + $b$ (odd) = $L$ (odd)
    - $a$ (odd) + $b$ (even) = $L$ (odd)

Notice that if the original stick length $N$ is odd, any break will result in one even piece and one odd piece. This means we can never obtain an even length piece if $N$ is odd, because all subsequent pieces will be derived from these odd and even pieces. Any piece derived from an odd piece will be odd (if it's the only piece) or will be a sum of an odd piece and potentially other pieces.
More formally, if $N$ is odd, any break $N \to a, b$ implies one of $a, b$ is odd and the other is even. If we then break an odd piece $a$, it becomes $c, d$ where one is odd and one is even. If we break an even piece $b$, it becomes $e, f$ where both $e, f$ are even. However, we started with an odd $N$. All pieces will ultimately be formed by sums of initial pieces. If $N$ is odd, we can never form an even length piece.

If $N$ is even, we can break it into two even pieces (e.g., $N/2, N/2$) or two odd pieces (e.g., $1, N-1$). This means if $N$ is even, we can potentially obtain even length pieces. If $X$ is even, we can obtain it if and only if $N$ is also even.

**Consolidated Logic:**
- If $X$ is odd: Always possible.
- If $X$ is even: Possible only if $N$ is even.

This logic covers all cases. The constraints $N, X \ge 1$ and the ability to break into positive integer lengths are implicitly handled by this parity argument. If $N=X$, we already have the piece. If $N>X$, we can make a cut. The parity argument dictates possibility.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations (modulo and comparisons) which take constant time. The input reading and output printing are also constant time per test case.
- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store $N$, $X$, and the loop counter $T$. This requires constant extra space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid std:: prefix
using namespace std;

void solve() {
    long long N, X;
    cin >> N >> X;

    // Apply the consolidated logic:
    // If X is odd, we can always obtain it.
    // If X is even, we can only obtain it if N is also even.
    if (X % 2 == 1) { // X is odd
        cout << "YES\n";
    } else { // X is even
        if (N % 2 == 1) { // N is odd
            cout << "NO\n";
        } else { // N is even
            cout << "YES\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0;
}
```