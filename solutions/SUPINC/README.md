# [Superincreasing (SUPINC)](https://www.codechef.com/problems/SUPINC)
- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct an array $A$ of $N$ positive integers such that it satisfies the "superincreasing" property, and its $K$-th element, $A_K$, is equal to a given value $X$.

An array $A$ is superincreasing if for every $i$ from $2$ to $N$, the element $A_i$ is strictly greater than the sum of all preceding elements: $A_i > A_1 + A_2 + \dots + A_{i-1}$. All elements $A_j$ must be positive integers.

We are given $N$, $K$, and $X$, and need to output "Yes" or "No".

## Intuition & Mathematical Observation

Let $S_{i-1} = A_1 + A_2 + \dots + A_{i-1}$. The superincreasing condition states $A_i > S_{i-1}$. Since $A_i$ must be an integer, this implies $A_i \ge S_{i-1} + 1$.

Our goal is to check if $A_K = X$ is possible. For this to be true, $X$ must satisfy the superincreasing condition at index $K$: $X > S_{K-1}$. To give $X$ the best chance of satisfying this condition, we need to minimize the sum $S_{K-1} = A_1 + A_2 + \dots + A_{K-1}$.

Let's find the minimum possible values for $A_1, A_2, \dots, A_{K-1}$ while maintaining the superincreasing property and being positive integers:
1.  **$A_1$**: Must be a positive integer. The smallest possible value is $A_1 = 1$.
2.  **$A_2$**: Must satisfy $A_2 \ge S_1 + 1 = A_1 + 1$. With $A_1=1$, the smallest $A_2$ is $1+1=2$.
3.  **$A_3$**: Must satisfy $A_3 \ge S_2 + 1 = (A_1 + A_2) + 1$. With $A_1=1, A_2=2$, the smallest $A_3$ is $(1+2)+1=4$.
4.  **Generalizing**: If we choose $A_j = S_{j-1} + 1$ for $j=2, \dots, K-1$, we get the minimum possible sum $S_{K-1}$.
    The sequence $A_1, A_2, A_3, \dots$ would be:
    *   $A_1 = 1 = 2^0$
    *   $A_2 = 2 = 2^1$
    *   $A_3 = 4 = 2^2$
    *   ...
    *   $A_j = 2^{j-1}$ for $j=1, \dots, K-1$.

Now, let's calculate the minimum possible sum $S_{K-1}$:
$S_{K-1} = A_1 + A_2 + \dots + A_{K-1} = 1 + 2 + 4 + \dots + 2^{K-2}$.
This is a geometric series sum, which evaluates to $2^{K-1} - 1$.

So, for $A_K = X$ to be possible, it must satisfy $X > S_{K-1}$. Using the minimum possible $S_{K-1}$, we require:
$X > (2^{K-1} - 1)$
Since $X$ is an integer, this is equivalent to:
$X \ge 2^{K-1}$

If this condition ($X \ge 2^{K-1}$) holds, we can always construct such an array:
1.  Set $A_i = 2^{i-1}$ for $i=1, \dots, K-1$. This ensures $S_{K-1}$ is minimized to $2^{K-1}-1$.
2.  Set $A_K = X$. Since $X \ge 2^{K-1}$, it implies $X > 2^{K-1}-1$, so $A_K > S_{K-1}$ is satisfied.
3.  For $i=K+1, \dots, N$, we can simply set $A_i = S_{i-1} + 1$. This will always maintain the superincreasing property and positive integers.

Therefore, the problem reduces to checking if $X \ge 2^{K-1}$.

**Handling Large Values of K:**
$K$ can be up to $2 \cdot 10^5$. $K-1$ can be up to $2 \cdot 10^5 - 1$.
$2^{K-1}$ can be an extremely large number, potentially exceeding the maximum value of $X$ ($10^9$) and even the capacity of a `long long` (approximately $9 \cdot 10^{18}$).

We need to compare $X$ (max $10^9$) with $2^{K-1}$.
Let's find the smallest power of 2 that exceeds $10^9$:
*   $2^{29} = 536,870,912$
*   $2^{30} = 1,073,741,824$

If $K-1 \ge 30$, then $2^{K-1} \ge 2^{30} > 10^9$. Since $X$ is at most $10^9$, it will always be strictly less than $2^{K-1}$ in this case. Thus, the condition $X \ge 2^{K-1}$ can never be met. So, if $K-1 \ge 30$, the answer is "No".

If $K-1 < 30$ (i.e., $K-1$ is between $0$ and $29$ inclusive), then $2^{K-1}$ will be at most $2^{29}$. This value fits comfortably within a `long long` and is less than $10^9$. In this scenario, we can safely compute $2^{K-1}$ (using `1LL << (K-1)`) and compare it with $X$.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a few constant-time operations: reading inputs, a comparison, and potentially a bit shift. This takes $O(1)$ time per test case. Given $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: We only use a few variables to store $N, K, X$, and the calculated minimum required value for $X$. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

// Function to solve a single test case
void solve() {
    long long N, K, X; // Declare N, K, X as long long to accommodate their maximum values
    std::cin >> N >> K >> X; // Read N, K, X for the current test case

    // Problem Analysis:
    // An array A is superincreasing if A_i > A_1 + A_2 + ... + A_{i-1} for i from 2 to N.
    // All elements must be positive integers.
    // Let S_{i-1} = A_1 + A_2 + ... + A_{i-1}. The condition is A_i > S_{i-1}.
    // Since A_i must be an integer, this implies A_i >= S_{i-1} + 1.

    // To determine if A_K = X is possible, we need to find the minimum possible value for S_{K-1}.
    // The minimum S_{K-1} is achieved by choosing the smallest possible positive integers for A_1, ..., A_{K-1}
    // while maintaining the superincreasing property.
    // A_1 must be at least 1. Let's choose A_1 = 1.
    // For i from 2 to K-1, we choose A_i = S_{i-1} + 1.
    // This sequence for A_1, ..., A_{K-1} would be [1, 2, 4, 8, ..., 2^(K-2)].
    // The sum S_{K-1} = A_1 + ... + A_{K-1} = 1 + 2 + 4 + ... + 2^(K-2)
    // This is a geometric series sum: 2^(K-1) - 1.
    // So, the minimum possible sum S_{K-1} is 2^(K-1) - 1.

    // For A_K = X to be valid, it must satisfy A_K > S_{K-1}.
    // Using the minimum possible S_{K-1}, we must have X > (2^(K-1) - 1).
    // Since X is an integer, this is equivalent to X >= 2^(K-1).

    // If this condition (X >= 2^(K-1)) holds, we can construct such an array:
    // 1. Set A_i = 2^(i-1) for i = 1, ..., K-1. (This ensures S_{K-1} is minimized).
    // 2. Set A_K = X. (This satisfies A_K > S_{K-1} because X >= 2^(K-1) > 2^(K-1)-1).
    // 3. For i = K+1, ..., N, set A_i = S_{i-1} + 1. (This ensures subsequent elements are valid).
    // All elements will be positive and the superincreasing property will hold.

    // Therefore, the problem reduces to checking if X >= 2^(K-1).

    // Handling large K:
    // K can be up to 2 * 10^5. K-1 can be up to 2 * 10^5 - 1.
    // 2^(K-1) can be a very large number, potentially exceeding the maximum value of X (10^9)
    // and even the capacity of a `long long` (which is typically 2^63 - 1).
    // We need to compare X with 2^(K-1).
    // The maximum value of X is 10^9.
    // Let's find the smallest power of 2 that exceeds 10^9:
    // 2^29 = 536,870,912
    // 2^30 = 1,073,741,824
    // If K-1 >= 30, then 2^(K-1) will be greater than or equal to 2^30,
    // which is already greater than 10^9.
    // Since X is at most 10^9, if K-1 >= 30, then X will always be strictly less than 2^(K-1).
    // In this scenario, the condition X >= 2^(K-1) can never be met.
    if (K - 1 >= 30) {
        std::cout << "No\n";
    } else {
        // If K-1 < 30 (i.e., K-1 is between 0 and 29 inclusive),
        // then 2^(K-1) will be at most 2^29, which is 536,870,912.
        // This value fits comfortably within a `long long` and is less than 10^9.
        // So we can safely compute 2^(K-1) using bit shift and compare it with X.
        long long min_required_X = 1LL << (K - 1); // Calculate 2^(K-1)
        if (X >= min_required_X) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare T for the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function for each test case
    }
    return 0; // Indicate successful execution
}
```