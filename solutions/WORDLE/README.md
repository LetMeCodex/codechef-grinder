# Wordle (WORDLE)
- **Difficulty Rating**: 804
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to simulate a simplified version of the game Wordle. We are given a 5-letter secret word `s` and a 5-letter guess word `guess`. Our task is to compare these two words character by character and produce a 5-character result string `m`. If the character at a specific position in `guess` matches the character at the same position in `s`, we append 'G' to `m`. Otherwise, if the characters do not match, we append 'B' to `m`.

## Intuition & Mathematical Observation
The core of this problem lies in a direct character-by-character comparison. There are no complex mathematical properties or algorithms involved. The intuition is straightforward: for each position in the 5-letter words, we need to check for equality.

Let the secret word be $S = s_0s_1s_2s_3s_4$ and the guess word be $G = g_0g_1g_2g_3g_4$.
We need to construct a result string $M = m_0m_1m_2m_3m_4$ where:
- $m_i = 'G'$ if $s_i = g_i$
- $m_i = 'B'$ if $s_i \neq g_i$

This is a simple conditional check for each of the 5 positions. The problem statement guarantees that both words will always be 5 letters long, so we don't need to handle variable lengths or edge cases related to word length.

## Complexity Analysis
- **Time Complexity**: $O(L)$ where $L$ is the length of the words. In this specific problem, the length of the words is fixed at 5. Therefore, the time complexity is effectively $O(5)$, which is a constant time complexity, $O(1)$. The loop iterates exactly 5 times for each test case, performing constant time operations within the loop.

- **Space Complexity**: $O(L)$ where $L$ is the length of the words. We are creating a result string `m` of length 5. Since the length is fixed, the space complexity is effectively $O(5)$, which is a constant space complexity, $O(1)$.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        std::string s, guess;
        std::cin >> s >> guess; // Read the hidden word and the guess word

        std::string m = ""; // Initialize the result string M
        for (int i = 0; i < 5; ++i) {
            if (s[i] == guess[i]) {
                m += 'G'; // If characters match, append 'G'
            } else {
                m += 'B'; // If characters don't match, append 'B'
            }
        }
        std::cout << m << "\n"; // Print the resulting string M
    }
    return 0;
}
```