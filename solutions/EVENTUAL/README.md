# [Even-tual Reduction (EVENTUAL)](https://www.codechef.com/problems/EVENTUAL)
- **Difficulty Rating**: 1040
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given string `S` of length `N`, consisting of lowercase English letters, can be completely erased. The allowed operation is to choose any two adjacent identical characters and erase them. This operation can be repeated any number of times. We need to output "YES" if the string can be completely erased, and "NO" otherwise.

**Example:**
- `abccba` -> `abba` (erased `cc`) -> `aa` (erased `bb`) -> `` (erased `aa`). Output: YES.
- `abacaba`: No adjacent identical characters. Cannot erase. Output: NO.
- `aabbc` -> `bbc` (erased `aa`) -> `c` (erased `bb`). Remaining `c` cannot be erased. Output: NO.

## Intuition & Mathematical Observation

Let's analyze the effect of the given operation: "choose two adjacent identical characters and erase them."
When we erase a pair of identical characters, say `XX`, the count of character `X` in the string decreases by 2. The counts of all other characters remain unchanged.

Consider the parity (even or odd) of the character counts:
- If a character `X` appears an odd number of times initially (e.g., 1, 3, 5 times), and we repeatedly apply the operation, each operation reduces its count by 2. An odd number minus 2 (any number of times) will always result in an odd number. For example, `5 -> 3 -> 1`. Eventually, we will be left with a single `X`. A single character cannot be erased by the given operation, as it requires *two* adjacent identical characters. Therefore, if any character appears an odd number of times, the string can never be completely erased.

- If a character `X` appears an even number of times initially (e.g., 2, 4, 6 times), and we repeatedly apply the operation, each operation reduces its count by 2. An even number minus 2 (any number of times) will always result in an even number. For example, `6 -> 4 -> 2 -> 0`. This means it's *possible* for the count to become 0.

This leads to a strong hypothesis: **A string can be completely erased if and only if every character in the string appears an even number of times.**

Let's prove this:
1.  **Necessity (If the string can be erased, then all character counts must be even):**
    As discussed, each operation removes two identical characters, thus changing the count of that character by -2. This preserves the parity of the character's count. If the string is completely erased, all character counts become 0 (which is an even number). Since parity is preserved, their initial counts must also have been even.

2.  **Sufficiency (If all character counts are even, then the string can be erased):**
    This part is a known property in string reduction problems, often solvable using a stack. If all characters appear an even number of times, the string can always be reduced to an empty string using the given operation.
    Consider processing the string from left to right using a stack:
    - If the current character is the same as the character at the top of the stack, pop the stack (simulating erasure of an adjacent pair).
    - Otherwise, push the current character onto the stack.
    If all character counts are even, the stack will be empty at the end. This implies that every character pushed onto the stack eventually found a matching character to be popped with, effectively removing all characters.

Therefore, the problem simplifies to a frequency counting problem: count the occurrences of each character in the string. If all counts are even, output "YES"; otherwise, output "NO".

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    1.  Reading the input string `S` of length `N` takes $O(N)$ time.
    2.  Iterating through the string `S` once to populate the frequency counts takes $O(N)$ time. For each character, accessing and incrementing an element in the `counts` array (or vector) is an $O(1)$ operation.
    3.  Iterating through the `counts` array (which has a fixed size of 26 for lowercase English letters) to check the parity of each count takes $O(26)$, which simplifies to $O(1)$ time.
    4.  The total time complexity for a single test case is $O(N) + O(1) = O(N)$.
    5.  Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    1.  Storing the input string `S` requires $O(N)$ space.
    2.  The `counts` vector (or array) used to store character frequencies has a fixed size of 26, regardless of the input string's length `N`. This requires $O(26)$, which simplifies to $O(1)$ auxiliary space.
    3.  Therefore, the total space complexity is dominated by the input string, resulting in $O(N)$. If we consider only auxiliary space (space used by our algorithm beyond input storage), it is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the string

    // Use a vector to store frequency counts of characters.
    // Since S contains only lowercase English letters, we can use an array/vector of size 26.
    // 'a' will map to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> counts(26, 0);

    // Iterate through the string to populate character counts
    for (char c : s) {
        counts[c - 'a']++; // Increment count for the corresponding character
    }

    // Check if all character counts are even
    bool possible = true;
    for (int count : counts) {
        if (count % 2 != 0) { // If any character has an odd count
            possible = false; // It's not possible to erase the whole string
            break;            // No need to check further
        }
    }

    // Print the result
    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}

```