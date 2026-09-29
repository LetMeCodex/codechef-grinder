# [Rearranging digits to get a multiple of 5 (DIGARR)](https://www.codechef.com/problems/DIGARR)
- **Difficulty Rating**: 949
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to rearrange the digits of a given number `N` (which is provided as a string) to form a new number that is a multiple of 5. We are given the length of the number `D` and the number `N` itself.

## Intuition & Mathematical Observation

The core of this problem lies in a fundamental property of divisibility by 5:
A number is a multiple of 5 if and only if its last digit is either '0' or '5'.

The problem statement allows us to *rearrange* the digits of the given number `N`. This is a crucial detail. If we can rearrange the digits, it means we can pick any digit present in `N` and place it at the last position of our new number.

Consider these two cases:

1.  **If the number `N` contains at least one '0' or at least one '5'**:
    If `N` contains a '0' or a '5', we can simply take one of those digits and place it at the very end of our rearranged number. The remaining digits can be arranged in any order before it. For example, if `N = "12354"`, we can rearrange it to `12345`. If `N = "7801"`, we can rearrange it to `7810`. In both cases, the resulting number will end in '0' or '5', making it a multiple of 5. Thus, the answer is "Yes".

2.  **If the number `N` does NOT contain any '0' or '5'**:
    If `N` consists only of digits other than '0' or '5' (i.e., only '1', '2', '3', '4', '6', '7', '8', '9'), then no matter how we rearrange its digits, the last digit of the new number will *never* be '0' or '5'. Therefore, it's impossible to form a number that is a multiple of 5. In this case, the answer is "No".

Based on this observation, the solution simplifies to a straightforward check: iterate through the digits of the input string `N`. If we find a '0' or a '5', we can immediately conclude "Yes". If we iterate through all digits and don't find either '0' or '5', then the answer is "No".

## Complexity Analysis

-   **Time Complexity**: $O(D)$ per test case.
    For each test case, we read the length `D` and the string `N`. Then, we iterate through the characters of the string `N` once. In the worst case, we might have to check all `D` digits (e.g., if `N` contains no '0' or '5', or if '0'/'5' is the last digit). In the best case, we find '0' or '5' at the very first digit and stop.
    Given that the sum of `D` over all test cases is at most $10^5$, the total time complexity across all test cases will be $O(\sum D)$. This is efficient enough.

-   **Space Complexity**: $O(D)$ per test case.
    We need to store the input string `N`, which has a length of `D`. Other variables (like `d`, `t`, `found_zero_or_five`, `digit`) take constant space.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int d;
        std::cin >> d; // Read the length of the number (D)
        std::string n;
        std::cin >> n; // Read the number N as a string

        bool found_zero_or_five = false;
        // Iterate through each character (digit) in the string N
        for (char digit : n) {
            // Check if the current digit is '0' or '5'
            if (digit == '0' || digit == '5') {
                found_zero_or_five = true; // Set flag to true
                break; // No need to check further, we found a suitable digit
            }
        }

        // Based on the flag, print "Yes" or "No"
        if (found_zero_or_five) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}

```