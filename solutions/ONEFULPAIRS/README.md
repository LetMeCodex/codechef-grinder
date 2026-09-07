# [Oneful Pairs (ONEFULPAIRS)](https://www.codechef.com/problems/ONEFULPAIRS)
- **Difficulty Rating**: 374
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given pair of positive integers `(a, b)` is "oneful". A pair `(a, b)` is defined as oneful if the expression `a + b + (a * b)` evaluates to `111`. We need to output "Yes" if the pair is oneful, and "No" otherwise. The input integers `a` and `b` are constrained to be between 1 and 100, inclusive.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for a pair `(a, b)` to be oneful: `a + b + (a * b) == 111`.
This means we don't need to derive any complex mathematical properties or algorithms. The solution is a straightforward implementation of this given condition.

Our approach will be:
1. Read the two integers, `a` and `b`.
2. Calculate the value of the expression `a + b + (a * b)`.
3. Compare this calculated value with `111`.
4. If they are equal, print "Yes". Otherwise, print "No".

Given the constraints `1 <= a, b <= 100`, the maximum possible value for `a + b + (a * b)` would occur when `a = 100` and `b = 100`:
`100 + 100 + (100 * 100) = 200 + 10000 = 10200`.
This value fits comfortably within standard integer types (like `int` or `long long` in C++), so there's no concern about overflow. The use of `long long` in the provided solution is perfectly safe, though `int` would also suffice for these constraints.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations: reading two integers, performing two additions and one multiplication, and then a comparison and a print operation. These operations take constant time regardless of the magnitude of `a` and `b` (within their given constraints). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of memory to store the two input integers `a` and `b`, and potentially a temporary variable for the calculation. No additional data structures are used that would scale with input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is good practice for competitive programming, though not strictly
    // necessary for problems with very small input/output like this one.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b; // Declare two variables to store the input integers.
                    // Using long long is safe, though int would also work
                    // given the constraints (1 <= a, b <= 100).

    std::cin >> a >> b; // Read the two integers from standard input.

    // Check the oneful condition: a + b + (a * b) == 111
    if (a + b + (a * b) == 111) {
        std::cout << "Yes\n"; // If the condition is true, print "Yes".
    } else {
        std::cout << "No\n";  // Otherwise, print "No".
    }

    return 0; // Indicate successful execution of the program.
}

```