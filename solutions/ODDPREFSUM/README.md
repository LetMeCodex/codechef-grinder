# [All Odd Prefix Sums (ODDPREFSUM)](https://www.codechef.com/problems/ODDPREFSUM)
- **Difficulty Rating**: 1085
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to determine if it's possible to rearrange the elements of $A$ to form a new array $B$ such that all prefix sums of $B$ are odd. That is, for the rearranged array $B = [B_1, B_2, \dots, B_N]$, the following conditions must hold:
- $B_1$ is odd.
- $B_1 + B_2$ is odd.
- $B_1 + B_2 + B_3$ is odd.
- ...
- $B_1 + B_2 + \dots + B_N$ is odd.

## Intuition & Mathematical Observation

Let's analyze the parity (even or odd) of the prefix sums.
Let $P_k = B_1 + B_2 + \dots + B_k$ be the $k$-th prefix sum.
We are given that $P_k$ must be odd for all $1 \le k \le N$.

Consider the relationship between consecutive prefix sums:
$P_k = P_{k-1} + B_k$ (where $P_0 = 0$).

We require $P_k$ to be odd for all $k$.
- For $k=1$: $P_1 = B_1$. This means $B_1$ must be odd.
- For $k=2$: $P_2 = P_1 + B_2$. Since $P_1$ is odd and $P_2$ must be odd, their difference $B_2 = P_2 - P_1$ must be even (Odd - Odd = Even).
- For $k=3$: $P_3 = P_2 + B_3$. Since $P_2$ is odd and $P_3$ must be odd, their difference $B_3 = P_3 - P_2$ must be even (Odd - Odd = Even).

Generalizing this, for any $k > 1$, we have $P_k = P_{k-1} + B_k$.
If both $P_k$ and $P_{k-1}$ are odd, then $B_k = P_k - P_{k-1}$ must be even.

Therefore, for all prefix sums to be odd, the rearranged array $B$ must satisfy the following parity conditions:
- $B_1$ must be odd.
- $B_2, B_3, \dots, B_N$ must all be even.

This means that the rearranged array $B$ must consist of exactly one odd number (at the first position) and $N-1$ even numbers.

The problem then reduces to checking if the original array $A$ contains the necessary counts of odd and even numbers to form such an array $B$.
If the original array $A$ contains exactly one odd number and $N-1$ even numbers, we can always rearrange them to satisfy the condition (place the single odd number at $B_1$ and the $N-1$ even numbers at $B_2, \dots, B_N$).
If the original array $A$ does not have exactly one odd number, it's impossible to form the required array $B$.
- If there are zero odd numbers in $A$, we cannot make $B_1$ odd.
- If there are more than one odd numbers in $A$, after placing one odd number at $B_1$, we will have at least one remaining odd number. This remaining odd number would have to be placed at some position $B_i$ where $i > 1$. However, for $i > 1$, $B_i$ must be even. This creates a contradiction.

So, the condition for being able to rearrange the array $A$ to satisfy the problem statement is that the count of odd numbers in $A$ must be exactly 1.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the input array once to count the number of odd elements. Reading $N$ integers takes $O(N)$ time. The rest of the operations (reading $T$, looping $T$ times, and printing the result) are constant time per test case or proportional to $T$. Thus, the dominant factor is reading the input array, making the time complexity $O(N)$ per test case.

- **Space Complexity**: $O(1)$
  The solution uses a few integer variables (`N`, `odd_count`, `A_i`, `T`) to store the input and intermediate counts. The amount of memory used does not depend on the size of the input array $N$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int odd_count = 0; // Counter for odd numbers in the array

    // Loop N times to read each element and determine its parity
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element
        if (A_i % 2 != 0) { // Check if A_i is odd (remainder is not 0 when divided by 2)
            odd_count++; // Increment the odd_count if the number is odd
        }
    }

    // Based on the parity analysis:
    // For all prefix sums to be odd, the first element (B_1) must be odd,
    // and all subsequent elements (B_2, ..., B_N) must be even.
    // This implies that the original array A must contain exactly one odd number
    // and N-1 even numbers.
    // If odd_count is 1, it means there is exactly one odd number available for B_1.
    // Since odd_count + even_count = N, if odd_count = 1, then even_count must be N-1.
    // This perfectly satisfies the required distribution of parities.
    // If odd_count is 0, we cannot make B_1 odd.
    // If odd_count > 1, we will have remaining odd numbers that must be placed
    // in positions B_i (for i > 1), but those positions require even numbers.
    if (odd_count == 1) {
        cout << "Yes\n"; // It is possible to rearrange the array
    } else {
        cout << "No\n"; // It is not possible
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```