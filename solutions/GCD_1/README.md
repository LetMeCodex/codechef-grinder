# [GCD to 1 (Easy) (GCD_1)](https://www.codechef.com/problems/GCD_1)
- **Difficulty Rating**: 1277
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to construct an $N \times M$ matrix $A$ where all elements $A_{ij}$ are positive integers. Specifically, each element $A_{ij}$ must satisfy $2 \le A_{ij} \le 10^9$. The core requirements are that the greatest common divisor (GCD) of all elements in any given row must be 1, and similarly, the GCD of all elements in any given column must also be 1. We are given $T$ test cases, and for each test case, we need to output such a matrix.
Constraints: $1 \le T \le 100$, $2 \le N, M \le 500$.

## Intuition & Mathematical Observation
The central challenge is to ensure that the GCD of elements in any row and any column is 1. A fundamental property of GCD is that the GCD of any sequence of two or more consecutive integers is always 1. For example, $\text{GCD}(k, k+1) = 1$, and more generally, $\text{GCD}(k, k+1, \dots, k+L-1) = 1$ for any $L \ge 2$.

This property provides a powerful strategy: if we can construct the matrix such that each row consists of $M$ consecutive integers and each column consists of $N$ consecutive integers, then both GCD conditions will be automatically satisfied, given that $N, M \ge 2$.

Let's try to find a simple linear formula for $A_{ij}$ that achieves this. A common approach for matrix construction problems is to use formulas involving $i$ (row index) and $j$ (column index).
Consider the formula used in the provided solution: $A_{ij} = i + j + M + 2$. Let's analyze how this formula satisfies all conditions:

1.  **Elements in Row `i`**:
    For a fixed row `i`, as `j` varies from $0$ to $M-1$, the elements are:
    *   $A_{i0} = i + 0 + M + 2 = i + M + 2$
    *   $A_{i1} = i + 1 + M + 2 = i + M + 3$
    *   ...
    *   $A_{i,M-1} = i + (M-1) + M + 2 = i + 2M + 1$
    This sequence is $(i+M+2), (i+M+3), \dots, (i+2M+1)$. This is a sequence of $M$ consecutive integers. Since $M \ge 2$, the GCD of these $M$ consecutive integers is 1. Thus, the row GCD condition is satisfied.

2.  **Elements in Column `j`**:
    For a fixed column `j`, as `i` varies from $0$ to $N-1$, the elements are:
    *   $A_{0j} = 0 + j + M + 2 = j + M + 2$
    *   $A_{1j} = 1 + j + M + 2 = j + M + 3$
    *   ...
    *   $A_{N-1,j} = (N-1) + j + M + 2 = N + j + M + 1$
    This sequence is $(j+M+2), (j+M+3), \dots, (N+j+M+1)$. This is a sequence of $N$ consecutive integers. Since $N \ge 2$, the GCD of these $N$ consecutive integers is 1. Thus, the column GCD condition is satisfied.

3.  **Element Bounds ($2 \le A_{ij} \le 10^9$)**:
    *   **Minimum Value**: The smallest element occurs at $i=0, j=0$.
        $A_{00} = 0 + 0 + M + 2 = M + 2$.
        Since $M \ge 2$, the minimum value of $A_{00}$ is $2+2=4$. This satisfies $A_{ij} \ge 2$.
    *   **Maximum Value**: The largest element occurs at $i=N-1, j=M-1$.
        $A_{N-1,M-1} = (N-1) + (M-1) + M + 2 = N + 2M$.
        Given $N, M \le 500$, the maximum value is $500 + 2 \times 500 = 500 + 1000 = 1500$.
        This is well within the $10^9$ limit.

All problem conditions are successfully met by the simple formula $A_{ij} = i + j + M + 2$. The constant $M+2$ is chosen to ensure the minimum value is at least 2 and to make the consecutive integer property work cleanly. Any constant $C \ge 2$ would work for $A_{ij} = i+j+C$ as long as $C$ is large enough to ensure $A_{00} \ge 2$. Using $M+2$ is a simple and effective choice.

## Complexity Analysis
-   **Time Complexity**: For each test case, we iterate through an $N \times M$ matrix. Inside the nested loops, we perform a constant number of arithmetic operations (addition) and print operations for each cell. Therefore, for one test case, the time complexity is $O(N \cdot M)$. Since there are $T$ test cases, the total time complexity is $O(T \cdot N \cdot M)$.
    Given the maximum constraints $T=100$, $N=500$, $M=500$, the maximum number of operations would be approximately $100 \times 500 \times 500 = 2.5 \times 10^7$, which is well within typical time limits for competitive programming (usually around $10^8$ operations per second).

-   **Space Complexity**: The solution generates and prints the matrix elements directly without storing the entire matrix in memory. It only uses a few integer variables (`N`, `M`, `i`, `j`, `T`) which occupy a constant amount of memory. Therefore, the space complexity is $O(1)$ (excluding the output buffer used by `cout`).

## Solution Code
```cpp
#include <bits/stdc++.h> // Required header

using namespace std; // Required

void solve() {
    int N, M;
    cin >> N >> M; // Read N and M for the current test case

    // Iterate through rows (0-indexed)
    for (int i = 0; i < N; ++i) {
        // Iterate through columns (0-indexed)
        for (int j = 0; j < M; ++j) {
            // Calculate the element A_ij using the formula: i + j + M + 2
            // This formula ensures:
            // 1. All elements are >= 2 (min value is M+2, which is >= 4 since M >= 2).
            // 2. All elements are <= 10^9 (max value is N+2M, which is approx 1500 for N,M=500).
            // 3. Each row contains M consecutive integers, so its GCD is 1.
            //    (e.g., for row i: (i+M+2), (i+M+3), ..., (i+M+2+M-1))
            // 4. Each column contains N consecutive integers, so its GCD is 1.
            //    (e.g., for col j: (j+M+2), (j+M+3), ..., (j+M+2+N-1))
            cout << (i + j + M + 2);

            // Print a space after the element if it's not the last one in the row
            if (j < M - 1) {
                cout << " ";
            }
        }
        // Print a newline character after each row
        cout << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Process each test case
    while (T--) {
        solve();
    }

    return 0;
}
```