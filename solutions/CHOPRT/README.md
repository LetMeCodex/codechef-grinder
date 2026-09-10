# [Chef And Operators (CHOPRT)](https://www.codechef.com/problems/CHOPRT)
- **Difficulty Rating**: 770
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read two integers, `A` and `B`, for a given number of test cases `T`. For each pair of integers, we need to determine their relationship:
- If `A` is strictly less than `B`, print `<`.
- If `A` is strictly greater than `B`, print `>`.
- If `A` is equal to `B`, print `=`.
Each output should be followed by a newline character.

## Intuition & Mathematical Observation

This is a very basic comparison problem. The core idea is to directly compare the two given integers `A` and `B` using standard relational operators. There are three possible outcomes for any two numbers: one can be less than the other, greater than the other, or equal to the other. We can use a simple `if-else if-else` construct to check these three conditions sequentially and print the corresponding character.

For example:
- If `A < B`, we know `A` is smaller.
- If `A > B`, we know `A` is larger.
- If neither of the above is true, it implies `A` must be equal to `B`.

No complex mathematical operations or advanced algorithms are required; it's a direct application of conditional logic.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program first performs constant time setup operations (`std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);`).
    -   It then reads the number of test cases `T`, which is an $O(1)$ operation.
    -   The `while (t--)` loop iterates `T` times.
    -   Inside the loop, for each test case:
        -   Reading two `long long` integers `a` and `b` takes $O(1)$ time.
        -   The `if-else if-else` block involves a constant number of comparisons and a constant time print operation. This is $O(1)$.
    -   Since the operations inside the loop are constant time, the total time complexity is $T \times O(1) = O(T)$. Given typical constraints for `T` (e.g., up to $10^5$), this is highly efficient.

-   **Space Complexity**: $O(1)$
    -   The program uses a few variables: `t`, `a`, and `b`. These variables store integer values and occupy a fixed amount of memory regardless of the input values (within the limits of their data types).
    -   No dynamic data structures, arrays, or recursive calls that would consume additional memory proportional to the input size are used.
    -   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    while (t--) {
        long long a, b; // Declare two long long integer variables 'a' and 'b'.
                        // 'long long' is used to accommodate potentially large integer values.
        std::cin >> a >> b; // Read the two integers for the current test case.

        // Compare 'a' and 'b' and print the appropriate operator.
        if (a < b) {
            std::cout << "<\n"; // If 'a' is less than 'b', print '<' followed by a newline.
        } else if (a > b) {
            std::cout << ">\n"; // If 'a' is greater than 'b', print '>' followed by a newline.
        } else {
            std::cout << "=\n"; // If 'a' is neither less than nor greater than 'b', they must be equal.
                               // Print '=' followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}

```