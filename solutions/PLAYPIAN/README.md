# [Play Piano (PLAYPIAN)](https://www.codechef.com/problems/PLAYPIAN)
- **Difficulty Rating**: 980
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given sequence of piano playing actions, represented by a binary string `s` of length `N` (where `N` is always even), is valid. The rules are:
1. Each person plays exactly once per day.
2. The log entries are given in chronological order.
3. The string `s` represents the sequence of actions for `N/2` days.
4. Each day consists of two actions, one by each person.

We need to output "yes" if the sequence is valid and "no" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the constraints imposed by the daily playing schedule. Since each person plays exactly once per day, and the log entries are chronological, we can group the actions into pairs, where each pair represents a single day.

The string `s` has a length `N`, which is guaranteed to be even. This means we can perfectly divide the string into `N/2` pairs of characters. The first pair `s[0]s[1]` represents the actions of day 1, the second pair `s[2]s[3]` represents day 2, and so on, up to `s[N-2]s[N-1]` for day `N/2`.

For a day's log to be valid, it must contain one action from each of the two people. Since the actions are represented by 'A' and 'B', this implies that for any given day, the two actions must be different. If both actions on a particular day were 'A' or both were 'B', it would violate the rule that each person plays exactly once per day.

Therefore, the condition for a valid sequence is that for every pair of consecutive characters `s[i]` and `s[i+1]` where `i` is an even index (0, 2, 4, ...), these two characters must be different. If we find any pair `s[i]s[i+1]` where `s[i] == s[i+1]`, the sequence is invalid.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The solution iterates through the input string `s` once. The loop runs `N/2` times, where `N` is the length of the string. Inside the loop, we perform a constant number of operations (character comparison). Therefore, the time complexity is directly proportional to the length of the string, which is $O(N)$.

- **Space Complexity**: $O(N)$
  The primary space usage comes from storing the input string `s`. In C++, `std::string` can take up to $O(N)$ space. If we consider the input string as part of the input and not auxiliary space, then the auxiliary space complexity is $O(1)$ as we only use a few variables for loop control and the boolean flag. However, if we include the input string storage, it's $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        std::string s; // The log of piano playing actions
        std::cin >> s;

        bool possible = true; // Flag to track if the sequence is valid

        // The problem states that each person plays exactly once per day.
        // The log entries are given in sequence.
        // Since |s| is even, we can group the entries into pairs representing days.
        // Each day's log must consist of one 'A' and one 'B'.
        // This means that for any pair of consecutive characters that form a day's log,
        // they must be different.
        // The string s is a concatenation of these daily logs.
        // So, we need to check pairs s[0]s[1], s[2]s[3], s[4]s[5], etc.
        // For each pair s[i]s[i+1] (where i is even), we must have s[i] != s[i+1].
        for (int i = 0; i < s.length(); i += 2) {
            // Check the pair s[i] and s[i+1]
            // If the characters are the same, it means both actions on this day
            // were performed by the same person, which is invalid.
            if (s[i] == s[i+1]) {
                possible = false; // Mark as impossible
                break;            // No need to check further, the sequence is invalid
            }
        }

        // Output the result based on the 'possible' flag
        if (possible) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}
```