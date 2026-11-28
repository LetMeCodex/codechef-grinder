# [Spell Bob (SPELLBOB)](https://www.codechef.com/problems/SPELLBOB)
- **Difficulty Rating**: 1283
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem presents three cards, each with a character on its top face and another character on its bottom face. We are given two strings, `s1` and `s2`, each of length 3. `s1[i]` represents the character on the top face of the i-th card, and `s2[i]` represents the character on the bottom face of the i-th card. We can choose to flip any of the cards. The goal is to determine if it's possible to spell the word "bob" using the visible faces of the three cards. We must use exactly one face from each of the three cards.

## Intuition & Mathematical Observation

The core of the problem lies in exploring the choices for each card. For each of the three cards, we have two options:
1. Use the character on its top face (`s1[i]`).
2. Use the character on its bottom face (`s2[i]`).

Since there are 3 cards and 2 choices for each card, the total number of distinct combinations of visible faces is $2 \times 2 \times 2 = 2^3 = 8$. This is a very small number, which suggests that we can simply try out all possible combinations.

For each combination of visible faces, we collect the three characters. To spell "bob", we need exactly two 'b's and one 'o' among these three characters. The order of the characters doesn't matter, only their counts.

Therefore, the strategy is:
1. Iterate through all 8 possible ways to choose the visible faces for the three cards.
2. For each combination, count the occurrences of 'b' and 'o' among the three chosen characters.
3. If at any point we find a combination where there are exactly two 'b's and one 'o', then it's possible to spell "bob", and we can immediately conclude "yes".
4. If after checking all 8 combinations, none satisfy the condition, then it's not possible, and we conclude "no".

The bit manipulation `(i >> k) & 1` is a concise way to represent these choices. If the k-th bit of `i` is 0, we choose the top face (`s1[k]`); if it's 1, we choose the bottom face (`s2[k]`).

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we iterate through a fixed number of combinations (8 combinations). Inside the loop, we perform a constant number of operations (character comparisons, increments). The length of the input strings `s1` and `s2` is also fixed at 3. Therefore, the operations per test case are constant. If there are `T` test cases, the total time complexity is $O(T \times 8)$, which simplifies to $O(T)$. Since 8 is a constant, we can say the time complexity per test case is $O(1)$.

-   **Space Complexity**: $O(1)$
    We store two strings `s1` and `s2`, each of length 3. This requires a constant amount of memory. A few integer variables (`i`, `count_b`, `count_o`, `t`) and a boolean flag `possible` are also used, which consume constant space. Thus, the space complexity is constant, $O(1)$, regardless of the input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace for convenience

void solve() {
    string s1, s2; // s1 for top faces, s2 for bottom faces
    cin >> s1 >> s2;

    bool possible = false; // Flag to track if "bob" can be spelled

    // Iterate through all 2^3 = 8 combinations of flipping cards.
    // Each integer 'i' from 0 to 7 represents a unique flip configuration.
    // The k-th bit of 'i' determines whether to use the top (0) or bottom (1)
    // face for the k-th card.
    for (int i = 0; i < (1 << 3); ++i) {
        int count_b = 0; // Count of 'b' characters
        int count_o = 0; // Count of 'o' characters

        // Determine the visible character for Card 0
        // If the 0-th bit of 'i' is 1, use s2[0] (bottom face); otherwise, use s1[0] (top face).
        char c0 = ((i >> 0) & 1) ? s2[0] : s1[0];
        if (c0 == 'b') {
            count_b++;
        } else if (c0 == 'o') {
            count_o++;
        }

        // Determine the visible character for Card 1
        // If the 1-st bit of 'i' is 1, use s2[1]; otherwise, use s1[1].
        char c1 = ((i >> 1) & 1) ? s2[1] : s1[1];
        if (c1 == 'b') {
            count_b++;
        } else if (c1 == 'o') {
            count_o++;
        }

        // Determine the visible character for Card 2
        // If the 2-nd bit of 'i' is 1, use s2[2]; otherwise, use s1[2].
        char c2 = ((i >> 2) & 1) ? s2[2] : s1[2];
        if (c2 == 'b') {
            count_b++;
        } else if (c2 == 'o') {
            count_o++;
        }

        // Check if the current combination of visible letters can spell "bob".
        // This means we need exactly two 'b's and one 'o'.
        if (count_b == 2 && count_o == 1) {
            possible = true; // Found a valid combination
            break;           // No need to check further combinations
        }
    }

    // Output the result for the current test case
    if (possible) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```