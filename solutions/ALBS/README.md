# [Alternating Binary String (ALBS)](https://www.codechef.com/problems/ALBS)
- **Difficulty Rating**: 1156
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to transform a given binary string $S$ of length $N$ into an "alternating binary string". An operation consists of choosing an index $i$ and flipping the character $S_i$ (changing '0' to '1' or '1' to '0'). An alternating binary string is defined as one where no two adjacent characters are the same (e.g., "01010", "10101").

## Intuition & Mathematical Observation

The provided solution implements a straightforward greedy approach. It iterates through the string and counts instances where adjacent characters are identical. The core idea is based on the following observations and assumptions:

1.  **Local Violation Detection**: An alternating string requires that for every index `i` from `1` to `N-1`, `S[i]` must be different from `S[i-1]`. If `S[i] == S[i-1]`, this constitutes a violation of the alternating property.
2.  **Independent Operations (Assumption)**: The solution assumes that each time `S[i] == S[i-1]`, exactly one operation is needed to fix this specific pair, and this operation does not negatively impact the count of operations needed for other pairs. For example, in the string "000":
    *   `S[0]` and `S[1]` are "00". The `operations` counter is incremented to 1.
    *   `S[1]` and `S[2]` are "00". The `operations` counter is incremented to 2.
    The final count is 2. This implies that each adjacent pair `S[i-1]S[i]` that is `00` or `11` contributes exactly one operation to the total, regardless of how a conceptual flip might propagate or affect subsequent comparisons.
3.  **Counting Strategy**: The algorithm iterates from the second character (`i = 1`) up to the last character (`N-1`). For each position `i`, it compares `s_vec[i]` with `s_vec[i-1]`. If they are found to be equal, it increments a counter `operations`. This counter directly represents the total number of such adjacent identical pairs found in the original string.

This approach effectively counts the number of times a character is identical to its immediate predecessor.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution involves reading the input string of length $N$, which takes $O(N)$ time. The main logic is a single `for` loop that iterates from `i = 1` to `N-1`. Inside the loop, constant-time operations (character comparison and integer increment) are performed. Therefore, the total time complexity is linear with respect to the length of the string, $N$.

-   **Space Complexity**: $O(N)$
    The solution uses a `std::vector<char>` of size `N+1` to store the input binary string. This storage is directly proportional to the length of the string $N$. No other data structures that scale with $N$ are used. Hence, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <cstdio> // For scanf and printf
#include <vector>   // For std::vector<char>

// No 'using namespace std;' to be explicit and avoid potential conflicts.

void solve() {
    int n;
    // Read N using scanf
    scanf("%d", &n);

    // Use std::vector<char> to store the string.
    // It's dynamically sized and handles memory safely.
    // +1 for the null terminator that scanf expects.
    std::vector<char> s_vec(n + 1); 
    // Read the binary string into the vector's underlying C-style array.
    scanf("%s", s_vec.data());

    int operations = 0;

    // Iterate from the second character (index 1 in 0-indexed string)
    // up to the last character.
    // We compare s_vec[i] with s_vec[i-1].
    for (int i = 1; i < n; ++i) {
        // If the current character is the same as the previous one,
        // an operation is required according to this logic.
        if (s_vec[i] == s_vec[i-1]) {
            operations++;
        }
    }
    
    // Output the minimum number of operations using printf.
    printf("%d\n", operations);
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false) and cin.tie(NULL)
    // are not strictly necessary as they primarily optimize C++ streams.
    // However, including them doesn't hurt and might be useful if other C++ streams are used.
    // For this specific problem, they are not needed.
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int t;
    // Read the number of test cases using scanf.
    scanf("%d", &t); 
    while (t--) { // Loop through each test case.
        solve();
    }

    return 0;
}
```