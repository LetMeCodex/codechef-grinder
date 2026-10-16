# [String Game (ABSTRING)](https://www.codechef.com/problems/ABSTRING)
- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game played by Alice and Bob using a string `S` of length `N`. They take turns picking characters from `S`. Alice takes the first character, Bob takes the second, Alice takes the third, and so on. Alice concatenates the characters she picks to form string `A`, and Bob concatenates the characters he picks to form string `B`. Alice will pick `ceil(N/2)` characters, and Bob will pick `floor(N/2)` characters. The task is to determine if it's possible for them to play such that strings `A` and `B` are identical.

The phrasing "Alice takes the first character, Bob takes the second, Alice takes the third, and so on" is crucial. In competitive programming, this often implies a strategic choice from the *remaining* characters, rather than picking from fixed indices of the original string `S`. Given the difficulty rating and the common patterns in such problems, the interpretation is that they pick characters from the available pool, and the "first", "second" refer to the order of characters in their respective strings `A` and `B`.

## Intuition & Mathematical Observation

Let's analyze the conditions under which strings `A` and `B` can be identical.

1.  **Length Mismatch**:
    *   Alice picks `ceil(N/2)` characters.
    *   Bob picks `floor(N/2)` characters.
    *   If `N` is odd, then `ceil(N/2)` will be `(N+1)/2` and `floor(N/2)` will be `(N-1)/2`. These lengths are different. For example, if `N=5`, Alice takes 3 characters and Bob takes 2.
    *   Strings of different lengths cannot be identical.
    *   Therefore, if `N` is odd, it's impossible for `A` and `B` to be identical. The answer is "NO".

2.  **Length Match (N is even)**:
    *   If `N` is even, then `ceil(N/2)` and `floor(N/2)` are both equal to `N/2`.
    *   In this case, Alice and Bob each form a string of length `N/2`. Let `k = N/2`.
    *   Alice forms `A = a_1 a_2 ... a_k`.
    *   Bob forms `B = b_1 b_2 ... b_k`.
    *   For `A` and `B` to be identical, we must have `a_i = b_i` for all `i` from 1 to `k`.

    Consider the turns and how they would achieve `a_i = b_i`:
    *   **Turn 1 (Alice):** Alice picks her first character, `a_1`. Let's say she picks character `X`.
    *   **Turn 2 (Bob):** Bob picks his first character, `b_1`. To make `a_1 = b_1`, Bob *must* pick an identical character `X`.
    *   **Turn 3 (Alice):** Alice picks her second character, `a_2`. Let's say she picks character `Y`.
    *   **Turn 4 (Bob):** Bob picks his second character, `b_2`. To make `a_2 = b_2`, Bob *must* pick an identical character `Y`.
    *   This pattern continues for all `k` pairs of characters.

    This strategy implies that for every character Alice picks, there must be an identical character available in `S` for Bob to pick immediately after. This is only possible if all characters in the original string `S` appear an *even number of times*.

    *   **Why even counts are necessary:** If any character `C` appears an odd number of times in `S` (e.g., 3 times: `C, C, C`), Alice and Bob can pair up `C`s until only one `C` remains. When it's a player's turn to pick this last `C`, the other player will not be able to match it, thus making `A` and `B` different.
    *   **Why even counts are sufficient:** If all characters appear an even number of times, Alice and Bob can always play optimally. Whenever Alice picks a character `X`, Bob can always pick another available `X` (since `X` appeared an even number of times, there's always a pair). This ensures that `a_i = b_i` for all `i`, making `A` and `B` identical.

**Conclusion:**
The problem can be solved by checking two conditions:
1.  If `N` is odd, output "NO".
2.  If `N` is even, count the frequency of each character in `S`. If all character frequencies are even, output "YES". Otherwise (if at least one character has an odd frequency), output "NO".

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `S`: $O(N)$
    *   Checking if `N` is odd: $O(1)$
    *   Calculating character frequencies: The loop iterates `N` times (once for each character in `S`). Inside the loop, incrementing a frequency count in a `std::vector` (or array) is an $O(1)$ operation. Thus, this step is $O(N)$.
    *   Checking if all frequencies are even: The loop iterates 26 times (for 'a' through 'z'). Each check is $O(1)$. Thus, this step is $O(26)$, which simplifies to $O(1)$ as it's a constant number of operations regardless of `N`.
    *   Overall, for each test case, the time complexity is dominated by reading the string and calculating frequencies, resulting in $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(\sum N)$ where $\sum N$ is the sum of `N` over all test cases. With `N` up to $10^5$ and total `N` up to $2 \cdot 10^5$, this is efficient enough.

*   **Space Complexity**:
    *   Storing the input string `S`: $O(N)$ space.
    *   Storing character frequencies: A `std::vector<int> freq(26)` is used, which takes $O(26)$ space. This is constant space, $O(1)$, as it does not depend on `N`.
    *   Overall, the space complexity is $O(N)$ due to storing the input string.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the string S

    // Condition 1: If N is odd, the lengths of strings A and B will be different.
    // Alice takes ceil(N/2) characters and Bob takes floor(N/2) characters.
    // If N is odd, ceil(N/2) != floor(N/2).
    // For example, if N=5, Alice takes 3, Bob takes 2. A and B cannot be the same.
    if (n % 2 != 0) {
        std::cout << "NO\n";
        return; // No need to proceed further for this test case
    }

    // Condition 2: If N is even, Alice and Bob each take N/2 characters.
    // For their strings A and B to be identical, they must have the same characters
    // in the same order. Let k = N/2.
    // A = c1 c2 ... ck
    // B = c1 c2 ... ck
    // This implies that Alice picks c1, then Bob must pick c1.
    // Then Alice picks c2, then Bob must pick c2, and so on.
    // This strategy is possible if and only if for every character Alice picks,
    // there is an identical character available in S for Bob to pick immediately after.
    // This means that every character in the original string S must appear an even number of times.
    // If any character appears an odd number of times, it's impossible to pair them up.
    // One instance of that character will always be left unpaired, meaning Alice or Bob
    // will pick it, and the other player won't be able to match it, thus making A != B.

    // Use a frequency array for lowercase English alphabets (a-z)
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> freq(26, 0); 
    for (char c : s) {
        freq[c - 'a']++; // Increment count for the character
    }

    bool possible = true;
    // Check if all character counts are even
    for (int count : freq) {
        if (count % 2 != 0) { // If any character has an odd count
            possible = false; // It's not possible to make A and B identical
            break;            // No need to check further
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```