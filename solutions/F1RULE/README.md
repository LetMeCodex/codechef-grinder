# [Miami GP (F1RULE)](https://www.codechef.com/problems/F1RULE)
- **Difficulty Rating**: 487
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a Formula 1 driver, Chef, qualifies for the next race based on the "107% rule". This rule states that a driver's qualifying time must be within 107% of the fastest qualifying time. We are given the fastest qualifying time ($X$) and Chef's qualifying time ($Y$), and we need to output "YES" if Chef qualifies, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in understanding and implementing the 107% rule. The rule can be expressed mathematically as:

Chef's time ($Y$) $\le$ 107% of the fastest time ($X$)

This translates to:

$Y \le X \times 1.07$

When dealing with programming contests, especially with integer inputs, it's often best to avoid floating-point arithmetic if possible to prevent potential precision errors. We can rewrite the inequality to use only integers.

Multiplying both sides by 100 to remove the decimal:

$Y \times 100 \le X \times 1.07 \times 100$
$Y \times 100 \le X \times 107$

This integer-based comparison is robust and avoids any issues with floating-point representation. Therefore, Chef qualifies if and only if $Y \times 100 \le X \times 107$.

The solution involves reading the number of test cases ($t$), and for each test case, reading the values of $X$ and $Y$. Then, we apply the derived integer inequality to check the condition and print "YES" or "NO" accordingly.

The provided C++ solution uses `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` for fast I/O, which is a common optimization in competitive programming.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  For each test case, we perform a constant number of arithmetic operations and comparisons. Since the number of test cases is $t$, the total time complexity is $O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
  We only use a few variables to store the input values and the loop counter. The memory usage does not grow with the input size, making the space complexity constant.

## Solution Code
```cpp
#include <iostream>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Disables synchronization with C standard streams and unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        int x, y; // x: fastest qualifying time, y: Chef's qualifying time.
        std::cin >> x >> y; // Read the two qualifying times.

        // The 107% rule states that Chef's time (Y) must be less than or equal to 107% of the fastest time (X).
        // Mathematically, this is Y <= X * 1.07.
        // To avoid potential floating-point precision issues and work with integers,
        // we can rewrite the inequality by multiplying both sides by 100:
        // Y * 100 <= X * 1.07 * 100
        // Y * 100 <= X * 107
        // This integer comparison is accurate and safe.
        if (y * 100 <= x * 107) {
            std::cout << "YES\n"; // Chef qualifies.
        } else {
            std::cout << "NO\n"; // Chef does not qualify.
        }
    }
    return 0; // Indicate successful execution.
}
```