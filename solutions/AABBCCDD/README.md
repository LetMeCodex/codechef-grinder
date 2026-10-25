# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)
- **Difficulty Rating**: 972
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible score achievable from a given string of length $N$. The score is defined as the maximum frequency of any character in the string. We are allowed to perform at most one operation of two types:
1. **Operation 1**: Choose a character and change all its occurrences to any other character.
2. **Operation 2**: Choose a character and change all its occurrences to its lowercase version (if it's uppercase).

We can perform at most one operation in total. This means we can either perform Operation 1, or Operation 2, or no operation at all.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how the operations affect character frequencies and how to maximize the frequency of a single character.

First, let's consider the effect of case. Operation 2 allows us to convert uppercase characters to their lowercase counterparts. This means that 'A' and 'a' are effectively the same character for scoring purposes if we choose to convert 'A' to 'a'. Since we want to maximize the frequency of *any* character, it's always optimal to convert an uppercase character to its lowercase equivalent if we decide to use Operation 2 on it. Therefore, we can treat all characters as their lowercase versions from the start. For example, if the string is "AaBb", we can consider it as "aabb". The initial counts would be {'a': 2, 'b': 2}.

Now, let's analyze the operations:

1.  **No Operation**: If we perform no operation, the score is simply the maximum frequency of any character in the original string (after normalizing cases).

2.  **Operation 2 (Convert uppercase to lowercase)**: As discussed, this is equivalent to normalizing all characters to lowercase. If we use Operation 2, we can convert any uppercase character to its lowercase form. For example, if we have "AaB", we can convert 'A' to 'a' to get "aab", or 'B' to 'b' to get "Aab". The most beneficial use of Operation 2 is to consolidate all occurrences of a character, regardless of its initial case. So, if we have 'a' and 'A', we can make them both 'a'. This is already handled by our initial case normalization. The problem statement implies we can use Operation 2 *once*. If we have "Aa", and we apply Operation 2 to 'A', it becomes "aa". If we apply it to 'a', it remains "aa". The key is that we can pick *one* character and convert *all* its occurrences to its lowercase version. This means if we have 'a' and 'A', and we choose to operate on 'A', it becomes 'a'. The total count of 'a' increases. This is effectively what our initial case normalization does: it sums up counts of 'a' and 'A' into 'a'. So, Operation 2, when used optimally, is implicitly handled by normalizing all characters to lowercase at the beginning.

3.  **Operation 1 (Convert one character to another)**: This is the more powerful operation. We can pick a character (say, 'x') and change all its occurrences to another character (say, 'y'). This means the count of 'x' is added to the count of 'y', and the count of 'x' becomes zero. Our goal is to maximize the count of *some* character.

Let's combine these observations.
First, we normalize all characters to lowercase and calculate their initial frequencies. Let `counts[c]` be the frequency of character `c` (lowercase) in the string.

The maximum score can be achieved in two main ways:

*   **Scenario A: The maximum frequency is achieved without using Operation 1 to merge characters.**
    In this case, the score is simply the maximum frequency of any character after normalizing cases. This covers the "no operation" case and the optimal use of Operation 2.

*   **Scenario B: The maximum frequency is achieved by using Operation 1 to merge characters.**
    We can pick a character `source_char` and convert all its occurrences to `target_char`. The new frequency of `target_char` will be `counts[target_char] + counts[source_char]`. We want to find the pair `(source_char, target_char)` that maximizes this sum. We need to iterate through all possible `source_char` and `target_char` pairs.

The overall maximum score will be the maximum value obtained from Scenario A and all possible combinations in Scenario B.

**Example Walkthrough:**
String: "AabBcCDd"
N = 8

1.  **Normalize cases and count frequencies:**
    'a': 1 (from 'a') + 1 (from 'A') = 2
    'b': 1 (from 'b') + 1 (from 'B') = 2
    'c': 1 (from 'c') + 1 (from 'C') = 2
    'd': 1 (from 'd') + 1 (from 'D') = 2
    `initial_counts = {'a': 2, 'b': 2, 'c': 2, 'd': 2}`

2.  **Scenario A (No Operation 1):**
    Maximum frequency is 2. `max_score = 2`.

3.  **Scenario B (Using Operation 1):**
    We iterate through all `source_char` and `target_char`.
    Let's consider `source_char = 'a'`, `target_char = 'b'`:
    `current_counts` becomes `{'a': 0, 'b': 2 + 2 = 4, 'c': 2, 'd': 2}`.
    Maximum frequency is 4. `max_score = max(2, 4) = 4`.

    Let's consider `source_char = 'c'`, `target_char = 'a'`:
    `current_counts` becomes `{'a': 2 + 2 = 4, 'b': 2, 'c': 0, 'd': 2}`.
    Maximum frequency is 4. `max_score = max(4, 4) = 4`.

    We continue this for all 26 * 25 pairs of (source, target).
    The maximum score will be updated if any of these merges result in a higher frequency.

The provided code implements this logic directly. It first calculates the initial counts after normalizing cases. Then, it finds the maximum count among these initial counts (Scenario A). Finally, it iterates through all possible `source_char` and `target_char` pairs, simulates the merge, calculates the maximum frequency in the merged string, and updates the overall `max_score` (Scenario B).

## Complexity Analysis

*   **Time Complexity**:
    - Normalizing cases and calculating initial counts: $O(N)$, where $N$ is the length of the string.
    - Finding the maximum initial count: $O(26)$ which is $O(1)$ as the alphabet size is constant.
    - Iterating through all possible `source_char` and `target_char` pairs: There are $26 \times 25$ such pairs. For each pair:
        - Copying the map: $O(26)$ which is $O(1)$.
        - Performing the merge: $O(1)$.
        - Finding the maximum count in the modified map: $O(26)$ which is $O(1)$.
    - The dominant part is the nested loop for `source_char` and `target_char`.
    - Total time complexity = $O(N + 26 \times 26 \times 26) = O(N + K^3)$, where $K=26$ is the alphabet size. Since $K$ is a constant, the time complexity is effectively $O(N)$.

*   **Space Complexity**:
    - Storing the `initial_counts` map: $O(26)$ which is $O(1)$.
    - Storing the `current_counts` map inside the loop: $O(26)$ which is $O(1)$.
    - Total space complexity = $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype> // For islower, tolower

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Disables synchronization with C's stdio and unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the string
        std::cin >> n;
        std::string s; // The input string
        std::cin >> s;

        // Step 1: Calculate initial counts after converting all uppercase to lowercase.
        // This effectively handles Operation 2 by consolidating counts of 'a' and 'A' into 'a', etc.
        std::map<char, int> initial_counts;
        for (char c : s) {
            if (std::islower(c)) {
                initial_counts[c]++;
            } else {
                // Convert uppercase to lowercase and increment count.
                initial_counts[std::tolower(c)]++;
            }
        }

        int max_score = 0;

        // Step 2: Consider the case where Operation 1 is not used to merge characters.
        // The maximum score in this scenario is the maximum count of any single character
        // after initial case normalization. This covers the "no operation" and optimal "Operation 2" cases.
        for (char c = 'a'; c <= 'z'; ++c) {
            max_score = std::max(max_score, initial_counts[c]);
        }

        // Step 3: Consider all possible uses of Operation 1 (merging characters).
        // Iterate through all possible source characters to be converted.
        for (char source_char = 'a'; source_char <= 'z'; ++source_char) {
            // Iterate through all possible target characters to convert to.
            for (char target_char = 'a'; target_char <= 'z'; ++target_char) {
                // If source and target are the same, Operation 1 has no effect, so skip.
                if (source_char == target_char) {
                    continue;
                }

                // Create a temporary map to simulate the operation without altering initial_counts.
                std::map<char, int> current_counts = initial_counts;

                // Perform the conversion: all occurrences of source_char become target_char.
                // Add the count of source_char to target_char's count.
                current_counts[target_char] += current_counts[source_char];
                // Set the count of source_char to 0 as they are all converted.
                current_counts[source_char] = 0;

                // Find the maximum count in the modified string after this specific merge.
                int current_max_for_this_op = 0;
                for (char c = 'a'; c <= 'z'; ++c) {
                    current_max_for_this_op = std::max(current_max_for_this_op, current_counts[c]);
                }

                // Update the overall maximum score if this merge yields a better score.
                max_score = std::max(max_score, current_max_for_this_op);
            }
        }

        // Output the maximum achievable score for the current test case.
        std::cout << max_score << "\n";
    }
    return 0;
}
```