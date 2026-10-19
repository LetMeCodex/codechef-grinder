# [Sequential Clamp (SEQCLAMP)](https://www.codechef.com/problems/SEQCLAMP)
- **Difficulty Rating**: 935
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given $N$ pairs of integers $(A_i, B_i)$. We need to find the maximum possible value of a function $f(X)$ which is defined iteratively. Initially, we can think of $f(X)$ as being unbounded (or effectively positive infinity). For each pair $(A_i, B_i)$, the value of $f(X)$ is updated according to the rule:
$f(X) = \max(A_i, \min(f(X), B_i))$

This update is applied sequentially for $i = 1, 2, \dots, N$. We need to find the maximum possible value that $f(X)$ can take after all $N$ updates have been applied.

## Intuition & Mathematical Observation

Let's denote the value of $f(X)$ after processing the $i$-th pair as $f_i(X)$.
Initially, before any updates, we can consider $f_0(X)$ to be effectively positive infinity for any $X$.

For the first pair $(A_1, B_1)$, the update rule is:
$f_1(X) = \max(A_1, \min(f_0(X), B_1))$
Since $f_0(X)$ is effectively infinity, $\min(f_0(X), B_1) = B_1$.
So, $f_1(X) = \max(A_1, B_1)$.

For the second pair $(A_2, B_2)$, the update rule is:
$f_2(X) = \max(A_2, \min(f_1(X), B_2))$
Substituting $f_1(X)$:
$f_2(X) = \max(A_2, \min(\max(A_1, B_1), B_2))$

This iterative application suggests that the final value of $f(X)$ will depend on the sequence of $A_i$ and $B_i$.
Let $Y$ represent the current value of $f(X)$ as it's being updated. Initially, we can imagine $Y$ as being very large (effectively infinity).

The update rule $Y = \max(A_i, \min(Y, B_i))$ can be broken down:
1. $\min(Y, B_i)$: This part clamps the current value of $Y$ from above by $B_i$. If $Y$ was already less than or equal to $B_i$, it remains unchanged. If $Y$ was greater than $B_i$, it becomes $B_i$.
2. $\max(A_i, \dots)$: This part then ensures that the new value of $Y$ is at least $A_i$. If the result from step 1 was less than $A_i$, the value becomes $A_i$. Otherwise, it remains the result from step 1.

So, for each pair $(A_i, B_i)$, the current value of $Y$ is updated to be:
- At least $A_i$.
- At most $B_i$.
- And it also respects the previous clamping.

Let's trace the value of $Y$ with an initial large value (e.g., 101, since $B_i \le 100$).
Let `current_max_Y` be the variable holding the effective value of $f(X)$ after each step.
Initially, `current_max_Y = infinity` (or a sufficiently large number like 101).

For pair $(A_1, B_1)$:
`current_max_Y = max(A_1, min(current_max_Y, B_1))`
Since `current_max_Y` is initially large, `min(current_max_Y, B_1)` will be `B_1`.
So, `current_max_Y = max(A_1, B_1)`.

For pair $(A_2, B_2)$:
`current_max_Y = max(A_2, min(current_max_Y, B_2))`
Here, `current_max_Y` is the value after the first step.
The expression `min(current_max_Y, B_2)` ensures that the value does not exceed $B_2$.
The expression `max(A_2, ...)` ensures that the value is at least $A_2$.

This process effectively finds the maximum possible value that $f(X)$ can attain. The crucial observation is that the initial value of $f(X)$ can be thought of as being arbitrarily large. The clamping operations $\max(A_i, \dots)$ and $\min(\dots, B_i)$ progressively restrict the possible range of $f(X)$.

The final value of `current_max_Y` after iterating through all pairs will be the maximum possible value $f(X)$ can take. This is because at each step, we are taking the maximum of the lower bound $A_i$ and the clamped previous value. If the previous value was already restricted by a $B_j$ from a previous step, this restriction carries forward. The $\max(A_i, \dots)$ ensures that we are always pushing the potential maximum value up if $A_i$ is large enough.

Consider the constraints: $1 \le N \le 10^5$ and $1 \le A_i, B_i \le 100$.
The maximum possible value for $B_i$ is 100. This means that at any step $i$, the value of $f(X)$ will be clamped by $B_i$ to be at most $B_i$. Therefore, the final result can never exceed 100.
If we initialize `current_max_Y` to a value greater than or equal to 100 (e.g., 101), the first `min(current_max_Y, B_1)` will correctly become $B_1$.

The logic is:
Start with `current_max_Y = infinity`.
For each $(A_i, B_i)$:
  `current_max_Y = max(A_i, min(current_max_Y, B_i))`

This single pass correctly computes the maximum possible value. The problem asks for the maximum possible value of $f(X)$ over all possible initial $X$. Since the function $f(X)$ is defined by sequential clamping, and the initial value can be considered as infinity, the iterative update directly computes the maximum achievable value.

Let's trace with an example:
N = 3
Pairs: (10, 20), (15, 25), (5, 30)

Initial `current_max_Y = 101` (or any value >= 100)

1. Pair (10, 20):
   `current_max_Y = max(10, min(101, 20))`
   `current_max_Y = max(10, 20)`
   `current_max_Y = 20`

2. Pair (15, 25):
   `current_max_Y = max(15, min(20, 25))`
   `current_max_Y = max(15, 20)`
   `current_max_Y = 20`

3. Pair (5, 30):
   `current_max_Y = max(5, min(20, 30))`
   `current_max_Y = max(5, 20)`
   `current_max_Y = 20`

Final answer: 20.

Let's try another example:
N = 3
Pairs: (10, 20), (25, 30), (15, 40)

Initial `current_max_Y = 101`

1. Pair (10, 20):
   `current_max_Y = max(10, min(101, 20))`
   `current_max_Y = max(10, 20)`
   `current_max_Y = 20`

2. Pair (25, 30):
   `current_max_Y = max(25, min(20, 30))`
   `current_max_Y = max(25, 20)`
   `current_max_Y = 25`

3. Pair (15, 40):
   `current_max_Y = max(15, min(25, 40))`
   `current_max_Y = max(15, 25)`
   `current_max_Y = 25`

Final answer: 25.

The logic holds. The key is that `current_max_Y` represents the upper bound of what $f(X)$ *could* be after considering all previous constraints. The $\max(A_i, \dots)$ ensures that we are always trying to achieve at least $A_i$, and the $\min(\dots, B_i)$ ensures we don't exceed the current $B_i$. The initial large value for `current_max_Y` is important to correctly establish the first upper bound from $B_1$.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the $N$ pairs exactly once. Inside the loop, there are a constant number of operations (reading two integers, `min`, `max`, assignment). Therefore, the time complexity is linear with respect to the number of pairs, $N$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of extra space regardless of the input size $N$. We only store a few integer variables: `N`, `T`, `A`, `B`, and `current_max_Y`. The space used does not grow with $N$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

using namespace std; // Use the standard namespace as requested

void solve() {
    int N;
    cin >> N; // Read the number of pairs

    // Initialize current_max_Y to a value that effectively represents positive infinity
    // for the given constraints. The maximum B_i is 100.
    // Any value >= 100 will work for the first step's min(current_max_Y, B) operation
    // as it will always be greater than or equal to B.
    // A safe choice is 101, or even INT_MAX from <limits> for general cases.
    // Given the constraints (B_i <= 100), 101 is perfectly fine and clear.
    int current_max_Y = 101; 

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B; // Read the i-th pair (A_i, B_i)

        // Apply the clamping rule: Y = max(A_i, min(Y, B_i))
        // This updates current_max_Y to reflect the maximum possible value
        // after processing the current pair, assuming Y started at infinity.
        current_max_Y = max(A, min(current_max_Y, B));
    }

    // After processing all N pairs, current_max_Y holds the maximum possible
    // value of f(X) across all possible input integers X.
    cout << current_max_Y << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```