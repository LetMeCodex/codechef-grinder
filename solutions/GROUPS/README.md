# Chef and Groups (GROUPS)
- **Difficulty Rating**: 1176
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count the number of "groups" of consecutive '1's in a given binary string. A group of '1's is defined as one or more consecutive '1's. For example, in the string "110111001", there are three groups of '1's: "11", "111", and "1".

## Intuition & Mathematical Observation
The core idea is to identify the start of each new group of '1's. A new group begins when we encounter a '1' and the previous character was either a '0' or it's the very first character of the string and it's a '1'.

We can iterate through the string character by character. We need a way to keep track of whether we are currently inside a group of '1's. A boolean flag, let's call it `in_group`, can serve this purpose.

When we encounter a '1':
- If `in_group` is `false`, it means we are entering a new group of '1's. So, we increment our `groups` counter and set `in_group` to `true`.
- If `in_group` is already `true`, it means we are continuing an existing group, so we do nothing.

When we encounter a '0':
- This signifies the end of any current group of '1's. So, we simply set `in_group` to `false`.

By following this logic, we can accurately count the number of distinct groups of consecutive '1's.

Let's trace an example: `s = "110111001"`

1. Initialize `groups = 0`, `in_group = false`.
2. `c = '1'`: `in_group` is `false`. Increment `groups` to 1. Set `in_group` to `true`.
3. `c = '1'`: `in_group` is `true`. Do nothing.
4. `c = '0'`: Set `in_group` to `false`.
5. `c = '1'`: `in_group` is `false`. Increment `groups` to 2. Set `in_group` to `true`.
6. `c = '1'`: `in_group` is `true`. Do nothing.
7. `c = '1'`: `in_group` is `true`. Do nothing.
8. `c = '0'`: Set `in_group` to `false`.
9. `c = '0'`: Set `in_group` to `false`.
10. `c = '1'`: `in_group` is `false`. Increment `groups` to 3. Set `in_group` to `true`.

End of string. The final count is 3.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the input string. We iterate through the string exactly once.
- **Space Complexity**: $O(1)$. We only use a few extra variables (`t`, `groups`, `in_group`, `c`) regardless of the input string's size. The input string itself takes $O(N)$ space, but this is input space, not auxiliary space.

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
        std::string s; // The input binary string
        std::cin >> s;

        int groups = 0; // Counter for the number of groups of '1's
        bool in_group = false; // Flag to track if we are currently inside a group of '1's

        // Iterate through each character of the string
        for (char c : s) {
            if (c == '1') {
                // If we encounter a '1' and we were not previously in a group,
                // it means a new group has started.
                if (!in_group) {
                    groups++;      // Increment the group count
                    in_group = true; // Set the flag to indicate we are now in a group
                }
            } else {
                // If we encounter a '0', it signifies the end of any current group of '1's.
                in_group = false; // Reset the flag
            }
        }
        // Print the total number of groups for the current test case
        std::cout << groups << "\n";
    }
    return 0;
}
```