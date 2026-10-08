# [All Even (ALLEV)](https://www.codechef.com/problems/ALLEV)
- **Difficulty Rating**: 617
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem presents a blackboard with $N$ integers. We are allowed to perform an operation: choose any two adjacent numbers, erase them, and write their sum in their place. This operation reduces the number of elements on the blackboard by one. We can perform this operation any number of times. The objective is to determine if it's possible to reach a state where *all* numbers currently on the blackboard are even.

## Intuition & Mathematical Observation

1.  **Effect of the Operation on Parity**:
    When two adjacent numbers, say $x$ and $y$, are replaced by their sum $x+y$, their parities combine as follows:
    *   Even + Even = Even
    *   Even + Odd = Odd
    *   Odd + Even = Odd
    *   Odd + Odd = Even
    A key takeaway is that the sum $x+y$ is even if and only if $x$ and $y$ have the same parity. If they have different parities, their sum is odd.

2.  **Structure of the Resulting Array**:
    When we combine adjacent elements, the new element is always the sum of a contiguous subarray of the original array. For example, if we start with `[A[0], A[1], A[2], A[3], A[4]]` and combine `A[1]` and `A[2]` to get `A[1]+A[2]`, the array becomes `[A[0], A[1]+A[2], A[3], A[4]]`. If we then combine `A[0]` and `A[1]+A[2]` to get `A[0]+A[1]+A[2]`, the array becomes `[A[0]+A[1]+A[2], A[3], A[4]]`. Notice that `A[0]+A[1]+A[2]` is a sum of a contiguous segment of the original array.

    A crucial observation is that we can *always* achieve a specific structure for the final array. If we want to end up with $k$ elements on the blackboard, we can perform $N-k$ operations such that the resulting array is `[A[0], A[1], ..., A[k-2], sum(A[k-1]...A[N-1])]`.
    This specific structure can be achieved by repeatedly combining the rightmost two adjacent numbers. For example, starting with `A[N-2]` and `A[N-1]`, replace them with `A[N-2]+A[N-1]`. Then, combine `A[N-3]` with `(A[N-2]+A[N-1])`, and so on, for $N-k$ times. This process effectively "collapses" the suffix `A[k-1]...A[N-1]` into a single sum, while leaving the prefix `A[0]...A[k-2]` untouched.

3.  **Strategy**:
    Based on the above observation, the problem reduces to checking if there exists *any* $k$ (where $1 \le k \le N$) such that the array `[A[0], A[1], ..., A[k-2], sum(A[k-1]...A[N-1])]` consists entirely of even numbers.

    For a given $k$:
    *   The elements `A[0], A[1], ..., A[k-2]` must all be even. (If $k=1$, this prefix is empty, which is vacuously true, meaning the condition is met).
    *   The sum `sum(A[k-1]...A[N-1])` must be even.

    We can iterate through all possible values of $k$ from $1$ to $N$. For each $k$:
    1.  Check if all elements in the prefix `A[0], ..., A[k-2]` are even. If any of them is odd, this $k$ is not a valid candidate.
    2.  If the prefix elements are all even (or the prefix is empty for $k=1$), calculate the sum of the suffix `A[k-1], ..., A[N-1]`.
    3.  If this suffix sum is also even, then we have found a valid configuration. We can immediately output "Yes" and terminate, as we only need to find one such possibility.

    If we iterate through all $k$ from $1$ to $N$ and don't find such a configuration, then it's impossible, and we output "No".

## Complexity Analysis

*   **Time Complexity**:
    The provided solution iterates through `k` from $1$ to $N$.
    For each `k`:
    1.  It iterates from `j = 0` to `k-2` to check the parity of the prefix elements. This loop takes $O(k)$ time in the worst case.
    2.  If the prefix is all even, it then iterates from `j = k-1` to `N-1` to calculate the suffix sum. This loop takes $O(N-k)$ time in the worst case.
    In the worst case, for each `k`, these two loops combined take $O(k + (N-k)) = O(N)$ time.
    Since the outer loop runs $N$ times, the total time complexity is $O(N \cdot N) = O(N^2)$ per test case.

    *Note*: For typical competitive programming constraints where $N$ can be up to $10^5$, an $O(N^2)$ solution would generally be too slow and result in a Time Limit Exceeded (TLE). However, given the problem's low difficulty rating (617) and the fact that the solution passed, it's likely that the test cases are not strong enough to fail an $O(N^2)$ solution, or the average $N$ across test cases is small. An optimized approach could compute the prefix parity check and suffix sum incrementally in $O(1)$ per `k` iteration, leading to an overall $O(N)$ time complexity per test case.

*   **Space Complexity**:
    The solution uses a `std::vector<int> A` of size $N$ to store the input numbers. This requires $O(N)$ space. All other variables use constant space.
    Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but useful for sum operations

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    bool possible = false;

    // Iterate through all possible number of elements 'k' that could remain on the blackboard.
    // 'k' ranges from 1 to N.
    // If 'k' elements remain, it means we performed N-k operations.
    // The resulting array would be [A[0], A[1], ..., A[k-2], sum(A[k-1]...A[N-1])]
    // (using 0-indexed array A)
    for (int k = 1; k <= N; ++k) {
        bool prefix_all_even = true;
        // Check if A[0]...A[k-2] are all even.
        // This loop runs for j from 0 to k-2.
        // If k=1, this loop doesn't run, which means prefix_all_even remains true (vacuously true).
        for (int j = 0; j < k - 1; ++j) {
            if (A[j] % 2 != 0) { // If A[j] is odd
                prefix_all_even = false;
                break;
            }
        }

        if (prefix_all_even) {
            // If the prefix elements are all even (or k=1), check the sum of the remaining suffix.
            long long suffix_sum = 0; // Use long long for sum to be safe, though int is fine for given constraints
            for (int j = k - 1; j < N; ++j) {
                suffix_sum += A[j];
            }

            if (suffix_sum % 2 == 0) { // If the suffix sum is even
                possible = true;
                break; // Found a way to make all numbers even, no need to check further k
            }
        }
    }

    if (possible) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```