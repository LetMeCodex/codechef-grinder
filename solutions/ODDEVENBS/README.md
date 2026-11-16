# [Odd Even Binary String (ODDEVENBS)](https://www.codechef.com/problems/ODDEVENBS)
- **Difficulty Rating**: 1099
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct an array `A` of length `N` such that all elements in `A` are integers between `1` and `N` (inclusive). We are given an array `B` of length `N`, where `B[k-1]` specifies the parity of the frequency of the number `k` in array `A`. Specifically:
- If `B[k-1] = 1`, the number `k` must appear an odd number of times in `A`.
- If `B[k-1] = 0`, the number `k` must appear an even number of times in `A`.

We need to output "YES" if such an array `A` can be constructed, and "NO" otherwise.

## Intuition & Mathematical Observation

Let `freq[k]` denote the frequency (number of occurrences) of the integer `k` in the array `A`.
From the problem statement, we know that `B[k-1]` represents `freq[k] % 2`. That is:
`freq[k] % 2 = B[k-1]` for all `k` from `1` to `N`.

The total length of array `A` is `N`. This means the sum of frequencies of all distinct elements in `A` must be equal to `N`:
`sum(freq[k] for k=1 to N) = N`

Now, let's consider this equation modulo 2. The parity of the sum must be equal to the parity of `N`:
`sum(freq[k] for k=1 to N) % 2 = N % 2`

Due to the property of modular arithmetic, `(X + Y) % 2 = (X % 2 + Y % 2) % 2`, we can rewrite the left side:
`sum(freq[k] % 2 for k=1 to N) % 2 = N % 2`

Substitute `freq[k] % 2` with `B[k-1]` based on the problem definition:
`sum(B[k-1] for k=1 to N) % 2 = N % 2`

Let `count_ones` be the total number of `1`s in the array `B`. This `count_ones` is precisely `sum(B[k-1] for k=1 to N)`.
So, the necessary condition for constructing array `A` becomes:
`count_ones % 2 = N % 2`

If this condition holds, can we always construct such an array `A`?
Yes.
1.  **Initial Frequencies**: We can initially set `freq[k] = B[k-1]` for each `k`. This ensures that the parity condition for each `k` is met.
2.  **Current Sum**: The sum of these initial frequencies is `sum(B[k-1]) = count_ones`.
3.  **Remaining Elements**: We need the total sum of frequencies to be `N`. The difference we need to account for is `N - count_ones`.
4.  **Parity of Difference**: Since `count_ones % 2 == N % 2`, it implies that `N` and `count_ones` have the same parity. Therefore, their difference `N - count_ones` must be an even number.
5.  **Distributing Remaining Elements**: Since `N - count_ones` is even, we can distribute this remaining count by adding `2` to the frequency of any element `k` `(N - count_ones) / 2` times. For example, we can add `2` to `freq[1]` `(N - count_ones) / 2` times. Adding `2` to any `freq[k]` does not change its parity (`(freq[k] + 2) % 2 = freq[k] % 2`).
6.  **Conclusion**: By adding `2`s to frequencies, we can reach the total sum `N` while preserving all individual parities. Thus, if `count_ones % 2 == N % 2`, a valid array `A` can always be constructed.

Therefore, the problem reduces to simply counting the number of `1`s in array `B` and checking if its parity matches the parity of `N`.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N`: $O(1)$
    -   Iterating through the `N` elements of array `B` to count the `1`s: $O(N)$
    -   Performing the final parity check: $O(1)$
    -   Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.
    -   Overall, the time complexity per test case is $O(N)$.

-   **Space Complexity**:
    -   We only need to store `N`, `count_ones`, and the current element `B_i` being read. No array `B` is stored explicitly.
    -   This requires a constant amount of extra space.
    -   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the arrays A and B

    int count_ones = 0; // Initialize a counter for elements in B that are 1
    for (int i = 0; i < N; ++i) {
        int B_i;
        cin >> B_i; // Read each element of the parity encoding array B
        if (B_i == 1) {
            count_ones++; // If B_i is 1, increment the counter
        }
    }

    // The core logic:
    // The sum of frequencies of all elements in A must be N.
    // That is, sum(freq(k) for k=1 to N) = N.
    // Taking this equation modulo 2:
    // sum(freq(k) mod 2 for k=1 to N) mod 2 = N mod 2.
    // By definition, freq(k) mod 2 = B_k.
    // So, sum(B_k for k=1 to N) mod 2 = N mod 2.
    // The sum(B_k) is simply count_ones.
    // Therefore, count_ones mod 2 must be equal to N mod 2.
    // If this condition holds, we can always construct a valid array A.
    // (For example, assign freq(k)=1 if B_k=1, freq(k)=0 if B_k=0.
    // The sum of these initial frequencies is count_ones.
    // The remaining N - count_ones elements must be added.
    // Since N and count_ones have the same parity, N - count_ones is even.
    // We can add (N - count_ones)/2 pairs of any element (e.g., '1's)
    // to A. Adding a pair of '1's increases freq(1) by 2, preserving its parity.
    // This way, all parities are maintained, and the total length becomes N.)
    
    if (count_ones % 2 == N % 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```