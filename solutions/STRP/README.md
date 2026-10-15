# [String protocol (STRP)](https://www.codechef.com/problems/STRP)
- **Difficulty Rating**: 1065
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum time required to transmit a binary string of length $N$. We can transmit characters in blocks. In one unit of time, we can transmit either:
1. A single character.
2. Two identical consecutive characters.

We want to minimize the total time taken.

## Intuition & Mathematical Observation

The core idea is to greedily transmit characters in a way that maximizes the use of the "two identical consecutive characters" rule. This rule allows us to transmit two characters in the same time it takes to transmit one. Therefore, whenever we encounter two identical consecutive characters, we should always choose to transmit them together.

Let's consider the string character by character. We maintain a pointer `i` to the current position in the string.

- If the current character `s[i]` is the same as the next character `s[i+1]`, we can transmit both `s[i]` and `s[i+1]` in one unit of time. After transmitting these two characters, we advance our pointer `i` by 2.

- If the current character `s[i]` is different from the next character `s[i+1]` (or if `s[i]` is the last character of the string), we can only transmit `s[i]` as a single character in one unit of time. After transmitting this character, we advance our pointer `i` by 1.

In both cases, each step of processing (either transmitting one or two characters) takes exactly one unit of time. We simply need to count how many such steps we take to traverse the entire string.

This greedy approach works because transmitting two identical characters together is always more efficient than transmitting them separately. There's no benefit to delaying the transmission of a pair of identical characters, as it doesn't enable any better transmission opportunities later on.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The solution iterates through the string once. In each iteration of the `while` loop, the index `i` is incremented by either 1 or 2. Therefore, the loop will run at most $N$ times. The operations inside the loop (character comparison, arithmetic, and incrementing `i`) are all constant time operations.

- **Space Complexity**: $O(N)$
  The space complexity is dominated by storing the input string `s`, which takes $O(N)$ space. The other variables (`t`, `n`, `time`, `i`) use constant extra space. If we consider the input string as part of the input and not extra space, then the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the binary string
        std::cin >> n;
        std::string s; // The binary string
        std::cin >> s;

        int time = 0; // Initialize total time taken
        int i = 0;    // Pointer to the current position in the string

        // Iterate through the string
        while (i < n) {
            time++; // Each step (transmitting 1 or 2 chars) takes 1 unit of time

            // Check if there's a next character and if it's identical to the current one
            if (i + 1 < n && s[i] == s[i + 1]) {
                // If current and next characters are the same, transmit them as a pair.
                // This takes 1 unit of time. Advance pointer by 2.
                i += 2;
            } else {
                // If current character is the last one, or different from the next,
                // transmit the current character alone.
                // This takes 1 unit of time. Advance pointer by 1.
                i += 1;
            }
        }
        std::cout << time << "\n"; // Output the minimum time for this test case
    }
    return 0;
}
```