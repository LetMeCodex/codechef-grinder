# [Processing a string (KOL15A)](https://www.codechef.com/problems/KOL15A)
- **Difficulty Rating**: 870
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to process a given string for multiple test cases. For each string, we need to find the sum of all the digits present in it. For example, if the string is "ab123c", the digits are '1', '2', '3', and their sum is 1 + 2 + 3 = 6.

## Intuition & Mathematical Observation

The core idea is straightforward: we need to iterate through each character of the input string. For every character, we check if it is a digit. If it is, we convert this character digit into its corresponding integer value and add it to a running total.

Here's how we can achieve this:
1.  **Iterate**: Loop through the string character by character.
2.  **Check for Digit**: For each character `c`, use a function like `std::isdigit(c)` (from the `<cctype>` header) to determine if `c` is a numerical digit ('0' through '9').
3.  **Convert and Sum**: If `c` is a digit, convert it to its integer value. This can be done by `c - '0'`. For example, `'5' - '0'` evaluates to the integer `5`. Add this integer value to a `sum` variable.
4.  **Output**: After iterating through the entire string, print the final `sum`.

Since the sum of digits can potentially be large (e.g., a string of 100,000 '9's would sum to 900,000), it's good practice to use a `long long` data type for the `sum` variable to prevent potential integer overflow, although for the given constraints (max string length 10^5, max sum 9 * 10^5), a standard `int` would also suffice.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    -   For each test case, we iterate through the input string once. If the length of the string is `N`, this loop performs `N` constant-time operations (checking `isdigit`, character arithmetic, and addition).
    -   Given `T` test cases, the total time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of a string across all test cases.
-   **Space Complexity**: $O(N)$ per test case.
    -   We store the input string `s`, which requires $O(N)$ space, where `N` is the length of the string.
    -   A few additional variables (`t`, `sum`, `c`) use constant $O(1)$ space.
    -   Thus, the dominant factor is the storage of the string.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string
#include <cctype>   // For std::isdigit

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        std::string s; // Variable to store the input string
        std::cin >> s; // Read the string for the current test case
        long long sum = 0; // Initialize sum of digits to 0. Using long long for safety.

        // Iterate through each character in the string
        for (char c : s) {
            // Check if the current character is a digit
            if (std::isdigit(c)) {
                // If it's a digit, convert it to its integer value
                // and add it to the sum.
                // 'c' - '0' converts a character digit (e.g., '5') to its integer value (5).
                sum += (c - '0');
            }
        }
        std::cout << sum << "\n"; // Print the calculated sum followed by a newline
    }

    return 0; // Indicate successful execution
}

```