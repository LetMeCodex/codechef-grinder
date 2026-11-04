# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a string $S$, we define two operations:
1. **Left Shift ($L$):** Move the first character to the end of the string.
2. **Right Shift ($R$):** Move the last character to the beginning of the string.

We need to determine if there exists a string $V$ such that $L(V) = S$ and $R(V) = S$. In simpler terms, we must check if the string $S$ obtained by shifting left is identical to the string $S$ obtained by shifting right.

## Intuition & Mathematical Observation
To satisfy $L(V) = S$ and $R(V) = S$, the string $S$ must be equal to both its left-shifted version and its right-shifted version. 

Let $n$ be the length of the string $S$.
- The left shift $L(S)$ results in the string: $S[1], S[2], \dots, S[n-1], S[0]$.
- The right shift $R(S)$ results in the string: $S[n-1], S[0], S[1], \dots, S[n-2]$.

For $L(S)$ to equal $R(S)$, every character at index $i$ in the left-shifted string must match the character at index $i$ in the right-shifted string.
- The character at index $i$ in $L(S)$ is $S[(i+1) \pmod n]$.
- The character at index $i$ in $R(S)$ is $S[(i-1) \pmod n]$.

Therefore, the condition for the string to be valid is:
$$S[(i+1) \pmod n] = S[(i-1) \pmod n] \quad \text{for all } i \in \{0, \dots, n-1\}$$

This simplifies to checking if $S[i] = S[(i+2) \pmod n]$ for all $i$. Essentially, all characters at even positions must be identical, and all characters at odd positions must be identical. Note that for strings of length $\le 2$, this condition is trivially satisfied or handled by the logic.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to perform the comparison.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();

        // Strings of length 1 or 2 always satisfy the condition
        // because shifting left and right results in the same string.
        if (n <= 2) {
            std::cout << "YES\n";
            continue;
        }

        bool possible = true;
        // Check if S[i] == S[(i+2) % n] for all i
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[(i + 2) % n]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```