# [Problem (PR0BLEM)](https://www.codechef.com/problems/PR0BLEM)
- **Difficulty Rating**: 908
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether it's possible for Alice and Bob to reach a state where they have the same number of problems. Initially, Alice has $N$ problems and Bob has $M$ problems. In each step, Alice can give one problem to Bob, or Bob can give one problem to Alice.

## Intuition & Mathematical Observation

Let $N$ be the number of problems Alice has and $M$ be the number of problems Bob has.
In each operation, one of the following happens:
1. Alice gives a problem to Bob: $N \to N-1$, $M \to M+1$. The sum $N+M$ remains constant. The difference $N-M$ changes by $-2$.
2. Bob gives a problem to Alice: $N \to N+1$, $M \to M-1$. The sum $N+M$ remains constant. The difference $N-M$ changes by $+2$.

We want to know if it's possible to reach a state where $N' = M'$.
If $N' = M'$, then the difference $N' - M' = 0$.

Consider the parity of the number of problems.
- If Alice gives a problem to Bob:
    - If $N$ was even, $N-1$ is odd.
    - If $N$ was odd, $N-1$ is even.
    - If $M$ was even, $M+1$ is odd.
    - If $M$ was odd, $M+1$ is even.
    In this operation, the parity of $N$ flips, and the parity of $M$ flips.

- If Bob gives a problem to Alice:
    - If $N$ was even, $N+1$ is odd.
    - If $N$ was odd, $N+1$ is even.
    - If $M$ was even, $M-1$ is odd.
    - If $M$ was odd, $M-1$ is even.
    In this operation, the parity of $N$ flips, and the parity of $M$ flips.

In both operations, the parity of both $N$ and $M$ flips simultaneously. This means that the relationship between the parities of $N$ and $M$ remains invariant.
- If $N$ is even and $M$ is even, after an operation, $N$ becomes odd and $M$ becomes odd. They still have the same parity.
- If $N$ is odd and $M$ is odd, after an operation, $N$ becomes even and $M$ becomes even. They still have the same parity.
- If $N$ is even and $M$ is odd, after an operation, $N$ becomes odd and $M$ becomes even. They still have different parities.
- If $N$ is odd and $M$ is even, after an operation, $N$ becomes even and $M$ becomes odd. They still have different parities.

Therefore, if Alice and Bob are to reach a state where they have the same number of problems ($N' = M'$), their initial numbers of problems ($N$ and $M$) must have the same parity. If $N$ and $M$ have different parities initially, they will always have different parities, and thus can never reach a state where $N' = M'$.

Conversely, if $N$ and $M$ have the same parity, can we always reach a state where $N' = M'$?
Let's consider the total number of problems $S = N+M$. If $N'=M'$, then $N'+M' = 2N'$. This means the total number of problems must be even. If $N$ and $M$ have the same parity, their sum $N+M$ is always even. So, the total number of problems is always even.

If $N$ and $M$ have the same parity, we can always make them equal.
Suppose $N > M$. We can have Bob give problems to Alice until $N=M$. This is possible as long as $M > 0$. If $M=0$ and $N>0$, and they have the same parity, then $N$ must be even. In this case, Alice can give problems to Bob until $N=M$.
More generally, if $N$ and $M$ have the same parity, we can always reach a state where $N'=M'$. For example, if $N > M$, Alice can give $N-M$ problems to Bob. This would result in Alice having $N - (N-M) = M$ problems and Bob having $M + (N-M) = N$ problems. This is not what we want.

Let's re-examine the operations.
If $N$ and $M$ have the same parity, their difference $N-M$ is even.
Each operation changes the difference $N-M$ by $\pm 2$.
If $N-M$ is even, and we change it by $\pm 2$, the new difference will also be even.
We want to reach a state where $N'-M' = 0$. Since $0$ is even, this is consistent.

Consider the case where $N$ and $M$ have the same parity.
If $N=M$, we are already done.
If $N \neq M$, assume $N > M$.
Alice can give a problem to Bob: $N \to N-1$, $M \to M+1$. The difference becomes $(N-1) - (M+1) = N-M-2$.
Bob can give a problem to Alice: $N \to N+1$, $M \to M-1$. The difference becomes $(N+1) - (M-1) = N-M+2$.
Since $N-M$ is even, we can always reduce the absolute difference $|N-M|$ by repeatedly applying the operation that brings them closer. For example, if $N > M$, Alice can give a problem to Bob. This reduces the difference by 2. We can continue this until $N=M$. This is possible as long as Bob has problems to give (i.e., $M>0$) or Alice has problems to give (i.e., $N>0$).

The only constraint is that we cannot perform an operation if the person giving the problem has 0 problems.
However, if $N$ and $M$ have the same parity, and $N \neq M$, then at least one of them must be positive.
If $N > M$:
If $M > 0$, Bob can give a problem to Alice. This increases $N$ and decreases $M$. This moves them further apart.
Alice can give a problem to Bob. This decreases $N$ and increases $M$. This brings them closer.
We can continue this process. If $N > M$, Alice gives a problem to Bob. The new counts are $N-1, M+1$. The difference is $(N-1)-(M+1) = N-M-2$.
We can repeat this $k$ times. The counts become $N-k, M+k$. The difference is $(N-k)-(M+k) = N-M-2k$.
We want to find $k$ such that $N-k = M+k$, which means $N-M = 2k$, or $k = (N-M)/2$.
Since $N$ and $M$ have the same parity, $N-M$ is even, so $k$ is an integer.
We need to ensure that at each step, the person giving the problem has at least one problem.
If Alice gives a problem, we need $N > 0$.
If Bob gives a problem, we need $M > 0$.

If $N$ and $M$ have the same parity, and $N \neq M$.
Assume $N > M$.
We want to reach $N' = M'$.
The total number of problems is $N+M$. If $N'=M'$, then $N'+M' = 2N'$. So $N+M$ must be even. This is guaranteed if $N$ and $M$ have the same parity.
Let $N+M = S$. We want to reach $N' = S/2$ and $M' = S/2$.
If $N > S/2$, Alice needs to give $N - S/2$ problems.
If $M < S/2$, Bob needs to receive $S/2 - M$ problems.
Note that $N - S/2 = N - (N+M)/2 = (2N - N - M)/2 = (N-M)/2$.
And $S/2 - M = (N+M)/2 - M = (N+M - 2M)/2 = (N-M)/2$.
So, Alice needs to give $(N-M)/2$ problems to Bob.
This is possible if Alice has at least $(N-M)/2$ problems to give, i.e., $N \ge (N-M)/2$.
$2N \ge N-M \implies N+M \ge 0$, which is always true since $N, M \ge 0$.
And Bob needs to receive $(N-M)/2$ problems. This is always possible.

The crucial part is that the operations preserve the parity of the difference $N-M$.
If $N$ and $M$ have the same parity, $N-M$ is even.
If $N$ and $M$ have different parities, $N-M$ is odd.
We want to reach $N'=M'$, which means $N'-M'=0$.
Since $0$ is an even number, we can only reach this state if the initial difference $N-M$ was even.
The difference $N-M$ is even if and only if $N$ and $M$ have the same parity.

So, the condition is simply that $N$ and $M$ must have the same parity.

Example:
N=3, M=5. Same parity (odd).
Alice gives to Bob: N=2, M=6. Same parity (even).
Alice gives to Bob: N=1, M=7. Same parity (odd).
Alice gives to Bob: N=0, M=8. Same parity (even).
Bob gives to Alice: N=1, M=7.
Bob gives to Alice: N=2, M=6.
Bob gives to Alice: N=3, M=5.
Bob gives to Alice: N=4, M=4. YES.

Example:
N=2, M=5. Different parity.
Alice gives to Bob: N=1, M=6. Different parity.
Bob gives to Alice: N=3, M=4. Different parity.
No matter what, the parities will always be different. So they can never be equal.

The logic holds. The condition is $(N \pmod 2) == (M \pmod 2)$.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations (modulo and comparison) for each test case. If there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$ per test case. We only use a few variables to store $N$, $M$, and $T$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, M;
    cin >> N >> M; // Read initial problems for Alice (N) and Bob (M)

    // The core logic: check if N and M have the same parity.
    // If N % 2 == M % 2, they have the same parity (both even or both odd).
    // If they have the same parity, it's possible to reach a state where they have
    // the same number of problems. Otherwise, it's impossible.
    if ((N % 2) == (M % 2)) {
        cout << "YES\n"; // Output YES if parities are the same
    } else {
        cout << "NO\n";  // Output NO if parities are different
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before reading input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```