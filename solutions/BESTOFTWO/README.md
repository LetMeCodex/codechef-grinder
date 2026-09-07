# [Best of Two (BESTOFTWO)](https://www.codechef.com/problems/BESTOFTWO)
- **Difficulty Rating**: 284
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to read two integers, `X` and `Y`, for a given number of test cases `T`. For each test case, we need to determine and print the larger of the two integers.

## Intuition & Mathematical Observation
The problem statement "Best of Two" directly implies finding the maximum value between two given numbers. This is a very fundamental operation in programming and mathematics.

- **Intuition**: To find the "best" or "greater" of two numbers, we simply compare them. If the first number is greater than the second, it's the best. Otherwise, the second number is the best (or they are equal, in which case either can be chosen as the maximum).
- **Mathematical Observation**: This operation is precisely what the `max(a, b)` function (or equivalent conditional logic) performs. It returns `a` if `a >= b`, and `b` otherwise.

## Complexity Analysis
- **Time Complexity**:
    - For each test case, we perform the following operations:
        1. Read two integers (`x`, `y`). This is an $O(1)$ operation.
        2. Compare `x` and `y` to find the maximum using `std::max`. This is an $O(1)$ operation.
        3. Print the maximum value. This is an $O(1)$ operation.
    - Since there are `T` test cases, and each test case takes constant time, the total time complexity is $O(T)$.

- **Space Complexity**:
    - We only use a few integer variables to store `t`, `x`, and `y` at any point in time. The amount of memory used does not depend on the input values or the number of test cases `T`.
    - Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code
```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::max function

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop 't' times, once for each test case.
    while (t--) {
        int x, y; // Declare two integer variables 'x' and 'y' for the current test case.
        std::cin >> x >> y; // Read the two integers for the current test case.

        // Use std::max to find the larger of x and y, and print it followed by a newline.
        std::cout << std::max(x, y) << "\n";
    }

    return 0; // Indicate successful program execution.
}

```