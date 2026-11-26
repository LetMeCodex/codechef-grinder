# [Three Powers of Two (THREEPOW2)](https://www.codechef.com/problems/THREEPOW2)
- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given positive integer $X$, represented as a binary string $S$ of length $N$, can be expressed as the sum of exactly three non-negative powers of two. That is, we need to check if there exist non-negative integers $a, b, c$ such that $X = 2^a + 2^b + 2^c$.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of binary representations and the "popcount" (number of set bits or '1's) of a number. Let $P(Y)$ denote the popcount of an integer $Y$.

A fundamental property of popcount is that for any non-negative integers $A$ and $B$, $P(A+B) \le P(A) + P(B)$. This property extends to any number of terms.
In our case, we are looking for $X = 2^a + 2^b + 2^c$.
Each power of two, $2^k$, has a popcount of 1 (its binary representation is a single '1' followed by $k$ zeros).
Therefore, if $X$ can be represented as the sum of three powers of two, its popcount must satisfy:
$P(X) = P(2^a + 2^b + 2^c) \le P(2^a) + P(2^b) + P(2^c) = 1 + 1 + 1 = 3$.

This is a crucial observation: **If a number $X$ can be expressed as the sum of exactly three non-negative powers of two, its popcount $P(X)$ must be less than or equal to 3.**
This immediately tells us that if $P(X) > 3$, the answer is "NO".

Now, we analyze the cases where $P(X) \le 3$. Let `ones_count` be the popcount of $X$.

1.  **`ones_count == 0`**: This would mean $X=0$. The problem states $X$ is a positive integer, so this case is not possible.

2.  **`ones_count == 1`**:
    If $P(X) = 1$, then $X$ itself is a power of two, say $X = 2^k$ for some $k \ge 0$.
    We need to represent $2^k$ as $2^a + 2^b + 2^c$.
    *   If $k=0$, $X=2^0=1$. The smallest possible sum of three non-negative powers of two is $2^0 + 2^0 + 2^0 = 1+1+1=3$. Since $1 < 3$, $X=1$ cannot be represented. (Binary string "1")
    *   If $k=1$, $X=2^1=2$. Similarly, $2 < 3$, so $X=2$ cannot be represented. (Binary string "10")
    *   If $k \ge 2$, $X=2^k$. We can represent $2^k$ as $2^{k-1} + 2^{k-2} + 2^{k-2}$. For example:
        *   $2^2 = 4 = 2^1 + 2^0 + 2^0 = 2+1+1$.
        *   $2^3 = 8 = 2^2 + 2^1 + 2^1 = 4+2+2$.
        *   $2^4 = 16 = 2^3 + 2^2 + 2^2 = 8+4+4$.
        In general, for $k \ge 2$, $2^k$ can be expressed as the sum of three powers of two.
    So, for `ones_count == 1`, the answer is "NO" if $X=1$ or $X=2$, and "YES" otherwise.

3.  **`ones_count == 2`**:
    If $P(X) = 2$, then $X = 2^k + 2^j$ for some $k > j \ge 0$.
    We can always split one of the powers of two. Since $k > j$, $k \ge 1$. We can write $2^k = 2^{k-1} + 2^{k-1}$.
    Thus, $X = 2^k + 2^j = 2^{k-1} + 2^{k-1} + 2^j$. These are three non-negative powers of two.
    *   Example: $X=3$ (binary "11") $= 2^1 + 2^0 = 2^0 + 2^0 + 2^0 = 1+1+1$.
    *   Example: $X=5$ (binary "101") $= 2^2 + 2^0 = 2^1 + 2^1 + 2^0 = 2+2+1$.
    *   Example: $X=9$ (binary "1001") $= 2^3 + 2^0 = 2^2 + 2^2 + 2^0 = 4+4+1$.
    So, for `ones_count == 2`, the answer is always "YES".

4.  **`ones_count == 3`**:
    If $P(X) = 3$, then $X = 2^k + 2^j + 2^m$ for some distinct $k > j > m \ge 0$.
    This is already in the desired form (sum of three distinct non-negative powers of two).
    *   Example: $X=7$ (binary "111") $= 2^2 + 2^1 + 2^0$.
    *   Example: $X=25$ (binary "11001") $= 2^4 + 2^3 + 2^0$.
    So, for `ones_count == 3`, the answer is always "YES".

**Summary of Logic:**
1.  Count the number of '1's (`ones_count`) in the input binary string $S$.
2.  If `ones_count > 3`, print "NO".
3.  If `ones_count == 1`:
    *   If $S$ is "1" or $S$ is "10", print "NO".
    *   Otherwise, print "YES".
4.  If `ones_count == 2` or `ones_count == 3`, print "YES".

## Complexity Analysis

Let $N$ be the length of the binary string $S$.
Let $T$ be the number of test cases.

-   **Time Complexity**:
    For each test case:
    1.  Reading $N$ and $S$: $O(N)$.
    2.  Counting '1's in $S$: This involves iterating through the string once, taking $O(N)$ time.
    3.  Conditional checks and printing: These are constant time operations, $O(1)$.
    Thus, for a single test case, the time complexity is $O(N)$.
    The problem constraints state that the sum of $N$ over all test cases does not exceed $10^5$. Therefore, the total time complexity across all test cases is $O(\sum N)$, which is $O(10^5)$. This is well within typical time limits.

-   **Space Complexity**:
    For each test case:
    1.  Storing the input string $S$: $O(N)$ space.
    2.  Other variables (like `N`, `ones_count`, `T`): $O(1)$ space.
    Thus, the space complexity for each test case is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <algorithm> // Required for std::count (though a manual loop is also fine)

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the binary string
    std::string S;
    std::cin >> S; // Read the binary string

    // Count the number of '1's in the binary string S
    int ones_count = 0;
    for (char c : S) {
        if (c == '1') {
            ones_count++;
        }
    }
    // Alternatively, using std::count:
    // int ones_count = std::count(S.begin(), S.end(), '1');

    // Apply the derived rules based on the count of '1's (popcount)
    if (ones_count == 1) {
        // If the number X has only one '1' in its binary representation,
        // it means X is a power of two (X = 2^k).
        // We need to represent X as 2^a + 2^b + 2^c.
        // The smallest possible sum of three non-negative powers of two is 2^0 + 2^0 + 2^0 = 1 + 1 + 1 = 3.
        // So, if X is 1 (S="1", k=0) or 2 (S="10", k=1), it cannot be represented.
        // For X = 2^k where k >= 2 (e.g., 4, 8, 16, ...), it can be represented.
        // For example, 4 = 2^2 = 2^1 + 2^0 + 2^0.
        // In general, 2^k = 2^{k-1} + 2^{k-2} + 2^{k-2} for k >= 2.
        if (S == "1" || S == "10") {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    } else if (ones_count == 2) {
        // If X has two '1's in its binary representation, X = 2^k + 2^j where k > j >= 0.
        // This can always be represented as a sum of three powers of two.
        // Since k > j >= 0, k must be at least 1.
        // We can split 2^k into 2^{k-1} + 2^{k-1}.
        // So, X = 2^{k-1} + 2^{k-1} + 2^j. These are three non-negative powers.
        // Example: 9 (1001_2) = 2^3 + 2^0 = 2^2 + 2^2 + 2^0.
        // Example: 3 (11_2) = 2^1 + 2^0 = 2^0 + 2^0 + 2^0.
        std::cout << "YES\n";
    } else if (ones_count == 3) {
        // If X has three '1's in its binary representation, X = 2^k + 2^j + 2^m where k > j > m >= 0.
        // This is already a sum of three distinct non-negative powers of two.
        // Example: 25 (11001_2) = 2^4 + 2^3 + 2^0.
        std::cout << "YES\n";
    } else { // ones_count > 3
        // It's a known property that for any positive integers A, B, C,
        // popcount(A + B + C) <= popcount(A) + popcount(B) + popcount(C).
        // If A=2^a, B=2^b, C=2^c, then popcount(A)=1, popcount(B)=1, popcount(C)=1.
        // So, popcount(2^a + 2^b + 2^c) <= 1 + 1 + 1 = 3.
        // Therefore, if the given number X has more than 3 '1's in its binary representation,
        // it cannot be represented as a sum of exactly three powers of two.
        // Example: 15 (1111_2) has 4 '1's. It cannot be represented.
        std::cout << "NO\n";
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