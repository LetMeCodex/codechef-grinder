# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)
- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count the number of "signals" in a given binary string. A signal is defined as a '1' that appears *after* at least one '0' has been encountered in the string. We are given a binary string `s` of length `n`, and we need to output the total count of such signals.

## Intuition & Mathematical Observation
The core of the problem lies in identifying the condition for a '1' to be considered a signal. The condition is straightforward: a '1' is a signal if and only if there has been a '0' *before* it in the string.

This suggests a simple linear scan through the string. We can maintain a flag or a boolean variable that keeps track of whether we have encountered a '0' yet. Let's call this flag `silence_seen`.

We initialize `silence_seen` to `false`. As we iterate through the string from left to right:
1. If we encounter a '0', we set `silence_seen` to `true`. This indicates that the condition for future '1's to be signals has now been met.
2. If we encounter a '1':
   - If `silence_seen` is `true`, it means we have already seen a '0' before this '1'. Therefore, this '1' is a signal, and we increment our signal count.
   - If `silence_seen` is `false`, it means we have not yet encountered any '0's. This '1' is not a signal according to the problem's definition.

By iterating through the entire string and applying this logic, we can accurately count all the signals.

Let's consider an example: `s = "101101"`
- `i = 0`, `s[0] = '1'`: `silence_seen` is `false`. This '1' is not a signal. `count = 0`.
- `i = 1`, `s[1] = '0'`: Set `silence_seen` to `true`. `count = 0`.
- `i = 2`, `s[2] = '1'`: `silence_seen` is `true`. This '1' is a signal. Increment `count`. `count = 1`.
- `i = 3`, `s[3] = '1'`: `silence_seen` is `true`. This '1' is a signal. Increment `count`. `count = 2`.
- `i = 4`, `s[4] = '0'`: Set `silence_seen` to `true`. `count = 2`.
- `i = 5`, `s[5] = '1'`: `silence_seen` is `true`. This '1' is a signal. Increment `count`. `count = 3`.

The final count is 3.

The logic is purely based on the sequential occurrence of characters, making a single pass sufficient. There isn't a complex mathematical formula involved, but rather a direct translation of the problem's conditional definition into an algorithmic approach.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution iterates through the input string `s` exactly once. For each character in the string, a constant number of operations (comparison, assignment, increment) are performed. Therefore, the time complexity is directly proportional to the length of the string, `N`.

- **Space Complexity**: $O(1)$
  The solution uses a few variables (`t`, `n`, `count`, `silence_seen`, `i`) to store the number of test cases, the length of the string, the signal count, the flag, and the loop index. The amount of memory used by these variables is constant and does not depend on the input string's length. The input string `s` itself takes $O(N)$ space, but this is considered input space, not auxiliary space used by the algorithm. The auxiliary space complexity is thus $O(1)$.

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
        int n; // Length of the binary string
        std::cin >> n;
        std::string s; // The binary string
        std::cin >> s;

        int count = 0; // Initialize signal count
        bool silence_seen = false; // Flag to track if a '0' has been encountered

        // Iterate through the string
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                // If a '0' is seen, set the flag to true
                silence_seen = true;
            } else if (s[i] == '1') {
                // If a '1' is seen and we have previously seen a '0'
                if (silence_seen) {
                    // This '1' is a signal, increment the count
                    count++;
                }
            }
        }
        // Output the total count of signals for the current test case
        std::cout << count << "\n";
    }
    return 0;
}
```