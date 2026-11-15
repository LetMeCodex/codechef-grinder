# [Bigger is Better (BIGNAME)](https://www.codechef.com/problems/BIGNAME)
- **Difficulty Rating**: 1227
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given a string $A$ of length $N$ consisting of lowercase English letters. Your task is to find a string $S$ of length $N$, also consisting of lowercase English letters, such that it satisfies two conditions:
1. $S$ is lexicographically greater than $A$ ($S > A$).
2. The reverse of $S$ is lexicographically greater than $A$ ($\text{reverse}(S) > A$).

If such a string $S$ exists, you should print any valid $S$. Otherwise, if no such string exists, print -1.

## Intuition & Mathematical Observation

The problem asks us to find a string $S$ that is "bigger" than $A$ in two ways: directly and when reversed. To maximize our chances of satisfying the "greater than $A$" conditions, it's natural to consider the lexicographically largest possible string of length $N$.

The lexicographically largest string of length $N$ using lowercase English letters is a string consisting of $N$ 'z's. Let's call this string `MAX_S = "zz...z"` (N times).

Let's analyze `MAX_S` as a candidate for $S$:

1.  **Condition 1: Is `MAX_S` lexicographically greater than $A$ (`MAX_S > A`)?**
    *   If $A$ is *not* `zz...z` (i.e., $A$ contains at least one character that is not 'z'), then `MAX_S` will always be lexicographically greater than $A$. This is because `MAX_S` has 'z' at every position. If $A$ is not all 'z's, there must be a first index $k$ where $A[k]$ is less than 'z'. At this index, `MAX_S[k]` ('z') will be greater than `A[k]`, making `MAX_S` lexicographically greater than $A$.
    *   If $A$ *is* `zz...z` (i.e., $A$ consists of $N$ 'z's), then `MAX_S` is equal to $A$. In this case, `MAX_S > A` is false.

2.  **Condition 2: Is `reverse(MAX_S)` lexicographically greater than $A$ (`reverse(MAX_S) > A`)?**
    *   If `S = MAX_S = "zz...z"`, then reversing `S` results in the same string: `reverse(S) = "zz...z"`.
    *   Therefore, `reverse(S)` is identical to `S`. This means Condition 2 is equivalent to Condition 1: `S > A`.

Combining these observations:

*   **Case 1: If $A$ consists of $N$ 'z's (e.g., "zzz")**
    *   In this scenario, $A$ is already the lexicographically largest possible string of length $N$.
    *   No string $S$ of length $N$ can be lexicographically greater than $A$.
    *   Therefore, both conditions ($S > A$ and $\text{reverse}(S) > A$) are impossible to satisfy.
    *   In this case, we should print -1.

*   **Case 2: If $A$ does *not* consist of $N$ 'z's (e.g., "abc", "zza")**
    *   We can choose $S = \text{MAX\_S} = \text{"zz...z"}$.
    *   From our analysis above, `MAX_S > A` will be true (Condition 1 satisfied).
    *   Since `reverse(MAX_S) == MAX_S`, it follows that `reverse(MAX_S) > A` will also be true (Condition 2 satisfied).
    *   Both conditions are met by choosing $S = \text{"zz...z"}$.
    *   In this case, we can print `zz...z`.

This logic covers all possibilities and provides a simple, constructive solution.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading $N$ and string $A$: $O(N)$.
        *   Checking if string $A$ consists of all 'z's: This involves iterating through $A$ once, taking $O(N)$ time in the worst case.
        *   Printing the result (either -1 or $N$ 'z's): This takes $O(N)$ time to print $N$ characters.
    *   Thus, for a single test case, the time complexity is $O(N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing the input string $A$: $O(N)$.
    *   Other variables (like $N$, `all_z`, loop counters): $O(1)$.
    *   The total space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string
#include <vector>   // Not strictly needed for this solution, but often useful
#include <algorithm> // Not strictly needed for this solution, but often useful (e.g., std::reverse)

void solve() {
    int N;
    std::cin >> N;
    std::string A;
    std::cin >> A;

    // Check if string A consists of all 'z's.
    // If A is "zz...z" (N times), then no string S of length N can be lexicographically
    // larger than A, because "zz...z" is the lexicographically largest possible string
    // of length N using lowercase English letters.
    // In this case, S > A is impossible, and thus reverse(S) > A is also impossible.
    // So, if A is all 'z's, no solution exists.
    bool all_z = true;
    for (char c : A) {
        if (c != 'z') {
            all_z = false;
            break; // Found a character not 'z', so A is not all 'z's.
        }
    }

    if (all_z) {
        std::cout << -1 << "\n";
    } else {
        // If A is not all 'z's, we can construct a valid string S.
        // The simplest valid string is one consisting of N 'z's.
        // Let S = "zz...z" (N times).
        //
        // Condition 1: S must be lexicographically larger than A.
        // Since A is not all 'z's, there must be at least one character in A that is not 'z'.
        // Let k be the first index (0-indexed) such that A[k] != 'z'.
        // This means A[0...k-1] are all 'z's.
        // For our constructed string S, S[j] = 'z' for all j from 0 to N-1.
        // So, for j < k, S[j] = 'z' and A[j] = 'z', meaning S[j] == A[j].
        // At index k, S[k] = 'z' and A[k] is some character less than 'z'.
        // Therefore, S[k] > A[k].
        // By the definition of lexicographical comparison, S is lexicographically larger than A.
        //
        // Condition 2: reverse(S) must be lexicographically larger than A.
        // If S consists of N 'z's, then reverse(S) is also "zz...z" (N times).
        // So, reverse(S) == S.
        // Since we already proved S > A, it directly follows that reverse(S) > A.
        //
        // Both conditions are satisfied.
        for (int i = 0; i < N; ++i) {
            std::cout << 'z';
        }
        std::cout << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```