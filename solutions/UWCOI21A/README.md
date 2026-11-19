# [Hidden Numbers (UWCOI21A)](https://www.codechef.com/problems/UWCOI21A)
- **Difficulty Rating**: 917
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find any two integers, $A$ and $B$, for a given integer $N$, such that their product $A \cdot B$ equals $N$. Additionally, both $A$ and $B$ must satisfy the constraint $1 \le A, B \le 10^9$. The problem guarantees that such a pair always exists.

**Constraints:**
- $1 \le T \le 1000$ (Number of test cases)
- $1 \le N \le 10^9$ (Input integer)

## Intuition & Mathematical Observation

The core of this problem lies in the phrase "find **any** two integers". This often hints that a very simple or trivial solution might exist, rather than requiring complex algorithms.

We are looking for $A$ and $B$ such that $A \cdot B = N$. The most straightforward way to factor any positive integer $N$ is $1 \times N$. Let's check if choosing $A=1$ and $B=N$ satisfies all the given conditions:

1.  **$A \cdot B = N$**:
    *   If $A=1$ and $B=N$, then $A \cdot B = 1 \cdot N = N$. This condition is perfectly satisfied.

2.  **$1 \le A, B \le 10^9$**:
    *   For $A=1$: $1 \le 1 \le 10^9$. This is true.
    *   For $B=N$: The problem constraints state that $1 \le N \le 10^9$. Therefore, $1 \le N \le 10^9$ is also true.

Since both conditions are met by simply choosing $A=1$ and $B=N$, this is the simplest possible solution. No complex factorization, prime number checks, or iterative searches are required. We just need to read $N$ and print `1 N`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading an integer $N$ and printing two integers (1 and $N$). Since there are $T$ test cases, the total time complexity is $T$ multiplied by a constant factor, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$
    We only use a few variables to store the number of test cases ($T$) and the input integer ($N$). The memory usage does not depend on the input size $N$ or the number of test cases $T$ beyond a constant amount. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Enable fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop T times, once for each testcase
    while (T--) {
        int N; // Declare an integer variable N for the input number
        cin >> N; // Read the integer N for the current testcase

        // The problem asks us to find any two integers A and B such that:
        // 1. 1 <= A, B <= 10^9
        // 2. A * B = N
        //
        // The simplest solution that satisfies all conditions is to choose A = 1 and B = N.
        // Let's verify this choice against the constraints:
        //
        // Constraint 1: 1 <= A, B
        // - For A = 1, 1 <= 1 is true.
        // - For B = N, since the problem states 1 <= N, 1 <= N is true.
        //   So, this constraint is satisfied.
        //
        // Constraint 2: A, B <= 10^9
        // - For A = 1, 1 <= 10^9 is true.
        // - For B = N, since the problem states N <= 10^9, N <= 10^9 is true.
        //   So, this constraint is satisfied.
        //
        // Constraint 3: A * B = N
        // - For A = 1 and B = N, A * B = 1 * N = N.
        //   So, this constraint is satisfied.
        //
        // All constraints are met. The value of N (up to 10^9) fits within a standard 'int' type in C++.
        // Therefore, we can simply output 1 and N for each testcase.
        cout << 1 << " " << N << "\n";
    }

    return 0; // Indicate successful execution
}
```