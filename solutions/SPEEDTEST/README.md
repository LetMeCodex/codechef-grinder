# [Speed Limit Test (SPEEDTEST)](https://www.codechef.com/problems/SPEEDTEST)
- **Difficulty Rating**: 718
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the speeds of Alice and Bob. We are given the distance Alice covered (`a`) and the time she took (`x`), and similarly for Bob (`b` and `y`). We need to determine who is faster or if they have the same speed.

## Intuition & Mathematical Observation
The core of this problem is understanding how to calculate speed and compare it. Speed is defined as distance divided by time.

For Alice, her speed can be calculated as:
$ \text{Alice's Speed} = \frac{a}{x} $

For Bob, his speed can be calculated as:
$ \text{Bob's Speed} = \frac{b}{y} $

Once we have these two values, we can directly compare them:
- If Alice's Speed > Bob's Speed, Alice is faster.
- If Bob's Speed > Alice's Speed, Bob is faster.
- If Alice's Speed = Bob's Speed, they have equal speeds.

A crucial aspect when dealing with floating-point numbers (like speeds calculated by division) is that direct equality comparisons (`==`) can be unreliable due to potential precision errors. It's standard practice to use a small tolerance (epsilon) when comparing floating-point numbers for equality. If the absolute difference between two floating-point numbers is less than this epsilon, we consider them equal.

In this solution, we use `double` for calculations and compare `alice_speed` and `bob_speed`.
- `alice_speed > bob_speed + epsilon` checks if Alice's speed is significantly greater than Bob's.
- `bob_speed > alice_speed + epsilon` checks if Bob's speed is significantly greater than Alice's.
- If neither of the above conditions is met, it implies their speeds are approximately equal within the given epsilon.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations (division, comparison) for each test case. Since the number of test cases `t` is processed in a loop, and each iteration takes constant time, the overall time complexity is $O(t)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store variables like `t`, `a`, `x`, `b`, `y`, `alice_speed`, `bob_speed`, and `epsilon`, regardless of the input size. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <iostream>
#include <iomanip> // Not strictly necessary for this logic, but good practice for floating point output

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        double a, x, b, y; // Distance and time for Alice (a, x) and Bob (b, y)
        std::cin >> a >> x >> b >> y;
        
        // Calculate speeds
        double alice_speed = a / x;
        double bob_speed = b / y;
        
        // Using a small epsilon for floating-point comparisons to handle precision issues
        double epsilon = 1e-9; 
        
        // Compare speeds
        if (alice_speed > bob_speed + epsilon) {
            // Alice's speed is significantly greater than Bob's
            std::cout << "Alice\n";
        } else if (bob_speed > alice_speed + epsilon) {
            // Bob's speed is significantly greater than Alice's
            std::cout << "Bob\n";
        } else {
            // Speeds are approximately equal within the epsilon tolerance
            std::cout << "Equal\n";
        }
    }
    return 0;
}
```