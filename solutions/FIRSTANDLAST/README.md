# [First and Last (FIRSTANDLAST)](https://www.codechef.com/problems/FIRSTANDLAST)
- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible sum of the first and last elements of an array after performing any number of cyclic rotations. We are given an array $A$ of $N$ integers. A cyclic rotation means moving elements from one end of the array to the other while maintaining their relative order. For example, if the array is `[A_1, A_2, A_3, A_4]`, one cyclic rotation could make it `[A_4, A_1, A_2, A_3]`, and another could make it `[A_2, A_3, A_4, A_1]`. We need to find the maximum sum of the first and last elements among all possible rotated versions of the array.

## Intuition & Mathematical Observation

Let's consider an array $A = [A_0, A_1, \dots, A_{N-1}]$ (using 0-based indexing for convenience).
When we perform cyclic rotations, the elements of the array effectively form a circle. Any element can become the "first" element of the array.

Suppose we choose $A_i$ to be the first element of the rotated array. What will be the last element?
If $A_i$ is the first element, then the elements will appear in the order:
$[A_i, A_{i+1}, \dots, A_{N-1}, A_0, A_1, \dots, A_{i-1}]$

From this sequence, it's clear that if $A_i$ is the first element, then $A_{i-1}$ (or $A_{N-1}$ if $i=0$) will be the last element. In other words, the last element will always be the element that was *immediately preceding* $A_i$ in the original cyclic order of the array.

Let's verify with examples:
*   If $A_0$ is the first element, the array is $[A_0, A_1, \dots, A_{N-1}]$. The last element is $A_{N-1}$. Sum: $A_0 + A_{N-1}$.
*   If $A_1$ is the first element, the array is $[A_1, A_2, \dots, A_{N-1}, A_0]$. The last element is $A_0$. Sum: $A_1 + A_0$.
*   If $A_2$ is the first element, the array is $[A_2, A_3, \dots, A_{N-1}, A_0, A_1]$. The last element is $A_1$. Sum: $A_2 + A_1$.

This pattern shows that for any $A_i$ chosen as the first element, the last element will be $A_{(i-1+N)\%N}$. The $(i-1+N)\%N$ expression correctly handles the wrap-around for $i=0$, where $A_{-1}$ should map to $A_{N-1}$.

Therefore, the problem simplifies to finding the maximum sum of $A_i + A_{(i-1+N)\%N}$ for all possible values of $i$ from $0$ to $N-1$. This means we just need to iterate through all elements and sum each element with its cyclic predecessor, then find the maximum among these sums.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$: $O(1)$
    *   Reading $N$ elements into the vector $A$: $O(N)$
    *   The main loop iterates $N$ times. Inside the loop, we perform constant time operations (array access, addition, modulo, comparison). So, this loop takes $O(N)$ time.
    *   Overall, for each test case, the time complexity is $O(N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   We store the $N$ elements of the array in a `std::vector<long long> A`. This requires $O(N)$ space.
    *   Other variables like `N`, `max_sum`, `current_sum`, `i`, `t` use $O(1)$ space.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm

// It's common practice in competitive programming to use `using namespace std;` globally.
using namespace std;

void solve() {
    int N;
    cin >> N;
    // Using long long for array elements to be safe, as A_i can be up to 10^9.
    // The sum A_i + A_j can be up to 2 * 10^9, which fits in a 32-bit signed int,
    // but using long long for sums is a good general practice to prevent overflow.
    vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0; // A_i >= 1, so the minimum possible sum is 1+1=2. Initializing with 0 is safe.

    // Iterate through all possible pairs (A[i], A[j]) that can become (A_1, A_N)
    // after some rotations. These pairs are always adjacent elements in the original
    // array, considering it cyclically.
    // Specifically, if A[i] becomes the first element (A_1), then the element
    // immediately preceding A[i] in the cyclic array becomes the last element (A_N).
    // In 0-based indexing, the element preceding A[i] is A[(i - 1 + N) % N].
    // The (i - 1 + N) % N ensures correct positive modulo for i=0 (A[-1] becomes A[N-1]).
    for (int i = 0; i < N; ++i) {
        long long current_sum = A[i] + A[(i - 1 + N) % N];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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