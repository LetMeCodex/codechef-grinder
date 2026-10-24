# [Non-matching Name (ABNOMAT)](https://www.codechef.com/problems/ABNOMAT)
- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if there exists a lowercase English alphabet character `c` such that `c` is *not* present in a given string `S_A` AND `c` is *not* present in another given string `S_B`. We are provided with the lengths of the strings, `N` and `M`, and the strings `S_A` and `S_B` themselves. We need to output "Yes" if such a character exists, and "No" otherwise.

## Intuition & Mathematical Observation

The core of the problem is to find a character that is simultaneously absent from both input strings. Since we are dealing with lowercase English alphabet characters, there are only 26 possibilities ('a' through 'z'). This small, fixed number of possible characters is a key observation.

Here's the thought process:

1.  **Identify the target**: We need to find a character `c` such that `c` is *not* in `S_A` AND `c` is *not* in `S_B`.
2.  **Efficiently check character presence**: For each string, we need a quick way to determine if a specific character is present or absent.
    *   Iterating through the entire string for each character check would be inefficient, especially if we do it for all 26 possible characters.
    *   A more efficient approach is to pre-process each string to build a set of its unique characters. A `std::set<char>` in C++ or a boolean array of size 26 (e.g., `bool present[26]`) would be suitable for this.
        *   Using `std::set<char>`: Insert all characters from the string into the set. Checking for presence then takes `O(log K)` time, where `K` is the number of unique characters (at most 26).
        *   Using a boolean array: Initialize an array of 26 booleans to `false`. For each character `ch` in the string, set `present[ch - 'a'] = true`. Checking for presence then takes `O(1)` time.
3.  **Algorithm**:
    *   First, create a data structure (e.g., `std::set<char>`) to store all unique characters present in `S_A`. Let's call this `chars_sa`.
    *   Similarly, create another data structure `chars_sb` for string `S_B`.
    *   Populate `chars_sa` by iterating through `S_A` and inserting each character.
    *   Populate `chars_sb` by iterating through `S_B` and inserting each character.
    *   Now, iterate through all 26 possible lowercase English characters, from 'a' to 'z'. For each character `c`:
        *   Check if `c` is *not* found in `chars_sa` (i.e., `chars_sa.find(c) == chars_sa.end()`).
        *   Simultaneously, check if `c` is *not* found in `chars_sb` (i.e., `chars_sb.find(c) == chars_sb.end()`).
        *   If both conditions are true, we have found such a character. We can immediately print "Yes" and terminate for the current test case.
    *   If the loop finishes without finding any such character (meaning all 26 characters are present in at least one of the strings), then print "No".

This approach ensures that we efficiently determine the presence/absence of characters and then perform a constant number of checks (26) to find our target character.

## Complexity Analysis

Let `N` be the length of string `S_A` and `M` be the length of string `S_B`.
Let `T` be the number of test cases.

*   **Time Complexity**:
    *   **Input Reading**: Reading strings `S_A` and `S_B` takes `O(N + M)` time.
    *   **Populating `chars_sa`**: We iterate through `S_A` (length `N`). For each character, inserting into `std::set<char>` takes `O(log K)` time, where `K` is the current number of unique characters in the set (at most 26). Since `log 26` is a constant, this step is effectively `O(N)`.
    *   **Populating `chars_sb`**: Similarly, this step takes `O(M)`.
    *   **Checking for possible character**: We iterate through all 26 lowercase English characters. For each character, we perform two `find` operations on `std::set<char>`. Each `find` operation takes `O(log K)` time (constant `O(log 26)`). Thus, this entire loop takes `26 * O(log 26)`, which simplifies to `O(1)`.
    *   **Total for one test case**: `O(N + M + 1)` which simplifies to `O(N + M)`.
    *   **Total for `T` test cases**: `T` times the complexity for one test case, so $O(T \cdot (N + M))$.

*   **Space Complexity**:
    *   **Storing `S_A`**: `O(N)` characters.
    *   **Storing `S_B`**: `O(M)` characters.
    *   **`chars_sa` set**: Stores at most 26 unique characters. This is `O(1)` auxiliary space.
    *   **`chars_sb` set**: Stores at most 26 unique characters. This is `O(1)` auxiliary space.
    *   **Total Space Complexity**: The dominant factor is storing the input strings, so $O(N + M)$. If we consider only auxiliary space (excluding input storage), it's $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n, m;
        std::cin >> n >> m; // Read lengths of strings (not strictly needed for logic, but part of input)
        std::string sa, sb;
        std::cin >> sa >> sb; // Read the two strings

        // Create a set to store unique characters present in string sa
        std::set<char> chars_sa;
        for (char c : sa) {
            chars_sa.insert(c);
        }

        // Create a set to store unique characters present in string sb
        std::set<char> chars_sb;
        for (char c : sb) {
            chars_sb.insert(c);
        }

        bool possible = false;
        // Iterate through all lowercase English alphabet characters from 'a' to 'z'
        for (char c = 'a'; c <= 'z'; ++c) {
            // Check if character 'c' is NOT found in chars_sa AND NOT found in chars_sb
            if (chars_sa.find(c) == chars_sa.end() && chars_sb.find(c) == chars_sb.end()) {
                possible = true; // Such a character exists
                break;           // No need to check further, we found one
            }
        }

        // Output "Yes" or "No" based on whether a non-matching character was found
        if (possible) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}

```