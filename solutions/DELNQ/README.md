# [Delete Not Equal (DELNQ)](https://www.codechef.com/problems/DELNQ)
- **Difficulty Rating**: 1118
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we can perform an operation: choose two adjacent characters $S[i]$ and $S[i+1]$. If $S[i] \neq S[i+1]$, we can delete both characters. The goal is to find the minimum possible length of the string after applying this operation any number of times.

## Intuition & Mathematical Observation

The core of the problem lies in understanding when we can reduce the string and to what extent. The operation allows us to remove adjacent *different* characters.

Let's consider the possible scenarios:

1.  **String consists of only '0's or only '1's:** If the string is monochromatic (e.g., "0000" or "1111"), there are no adjacent characters that are different. Therefore, no operations can be performed. The length of the string will remain $N$.

2.  **String contains both '0's and '1's:** If the string contains at least one '0' and at least one '1', we can always perform operations to reduce the string.
    *   Consider a string like "0101". We can delete the first "01" to get "01", and then delete that "01" to get an empty string (length 0).
    *   Consider "1001". We can delete "10" to get "01", and then delete "01" to get an empty string.
    *   Consider "0011". We can delete "01" to get "01", and then delete "01" to get an empty string.

    The key observation is that as long as there are *both* '0's and '1's present in the string, there must be at least one boundary where a '0' is adjacent to a '1' (or vice-versa). This is because if we traverse the string, we must transition from a block of one character to a block of the other at some point. For example, in "000111", the transition is between the last '0' and the first '1'.

    When we have such an adjacent pair of different characters, we can delete them. This operation effectively "removes" one instance of '0' and one instance of '1'. If we can always find such a pair as long as both characters exist, we can continue this process.

    Let's think about the parity of the counts. Each operation removes one '0' and one '1'. So, the difference between the count of '0's and '1's remains invariant modulo 2. However, this is not directly helpful for the minimum length.

    The crucial insight is that if we have at least one '0' and at least one '1', we can *always* reduce the string to a single character. Why? Imagine we have $C_0$ zeros and $C_1$ ones. If $C_0 > 0$ and $C_1 > 0$, we can always find an adjacent pair $S[i] \neq S[i+1]$. Deleting them reduces both counts by one. We can repeat this.
    If we can reduce the string to a single character, what would that character be? It doesn't matter. The problem asks for the *minimum possible length*.

    Consider the case where we can reduce the string to a single character. For example, if we have "001". We can delete "01" to get "0". Length 1.
    If we have "110". We can delete "10" to get "1". Length 1.

    The only scenario where we *cannot* reduce the string is when all characters are the same. In all other cases, we can perform operations. The question is, can we always reduce it to length 1 if it's not monochromatic?

    Let's re-examine the operation: "choose two adjacent characters $S[i]$ and $S[i+1]$. If $S[i] \neq S[i+1]$, we can delete both characters."

    If the string is not monochromatic, it must contain both '0's and '1's. This implies there must be at least one index $i$ such that $S[i] \neq S[i+1]$. We can perform the operation at this index. This reduces the length of the string by 2. We can repeat this.

    If we can always find adjacent different characters as long as both '0's and '1's exist, we can keep reducing. The process stops when either only '0's remain or only '1's remain.
    If the initial counts were $C_0$ and $C_1$, and we perform $k$ operations, we remove $k$ '0's and $k$ '1's. The remaining counts are $C_0 - k$ and $C_1 - k$. The process stops when $C_0 - k = 0$ or $C_1 - k = 0$.
    This means $k = C_0$ or $k = C_1$. The total number of characters removed is $2k$.
    The final length would be $N - 2k$.

    However, the problem statement implies we can reach a state where no more operations are possible. If we have both '0's and '1's, we can always find an adjacent pair $S[i] \neq S[i+1]$.
    Example: "01010"
    Delete "01" -> "010"
    Delete "01" -> "0" (Length 1)

    Example: "10101"
    Delete "10" -> "101"
    Delete "10" -> "1" (Length 1)

    Example: "00110"
    Delete "10" -> "001"
    Delete "01" -> "0" (Length 1)

    It seems that if the string is not monochromatic, we can always reduce it to a single character. The minimum length would be 1.

    The only edge case is when the string is monochromatic. In that case, no operations are possible, and the length remains $N$.

    So, the logic is:
    *   Count the number of '0's and '1's.
    *   If `count0 == 0` or `count1 == 0`, the string is monochromatic. The minimum length is $N$.
    *   Otherwise (if `count0 > 0` AND `count1 > 0`), the string is not monochromatic. The minimum length is 1.

    Let's double-check the problem constraints and examples. The problem statement is simple and the logic seems robust. The difficulty rating (1118) also suggests a straightforward observation rather than a complex algorithm.

    The provided solution code implements exactly this logic. It counts '0's and '1's. If either count is zero, it prints $N$. Otherwise, it prints 1. This matches our derived logic.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The code iterates through the string once to count the occurrences of '0' and '1'. This takes time proportional to the length of the string, $N$. The rest of the operations (reading input, comparisons, printing output) take constant time per test case. Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$. However, if we consider the complexity per test case, it is $O(N)$.

-   **Space Complexity**: $O(N)$
    The string $S$ itself takes $O(N)$ space to store. The variables `t`, `n`, `count0`, `count1` take constant space, $O(1)$. Therefore, the dominant space usage is for the input string. If we consider the space used *in addition* to the input string, it's $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm> // Not strictly necessary for this problem, but often useful.

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the length of the string
        std::string s;
        std::cin >> s; // Read the binary string

        int count0 = 0;
        int count1 = 0;
        // Count occurrences of '0' and '1'
        for (char c : s) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }
        }

        // Apply the revised logic
        if (count0 == 0 || count1 == 0) {
            // If the string is monochromatic (all '0's or all '1's),
            // no operations can be performed. The length remains N.
            std::cout << n << "\n";
        } else {
            // If the string contains both '0's and '1's,
            // it's always possible to reduce it to a single character.
            std::cout << 1 << "\n";
        }
    }
    return 0;
}
```