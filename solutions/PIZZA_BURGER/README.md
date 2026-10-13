# [Hungry Ashish (PIZZA_BURGER)](https://www.codechef.com/problems/PIZZA_BURGER)
- **Difficulty Rating**: 1064
- **Solved in**: 1 attempt(s)

## Problem Summary

Ashish has `X` rupees. A pizza costs `Y` rupees, and a burger costs `Z` rupees. Ashish prefers pizza over burger. We need to determine what Ashish will eat based on his money and preferences.

The decision process is as follows:
1. If Ashish can afford a pizza, he will eat pizza.
2. Otherwise (if he cannot afford a pizza), if he can afford a burger, he will eat a burger.
3. Otherwise (if he cannot afford either a pizza or a burger), he will eat nothing.

We need to output "PIZZA", "BURGER", or "NOTHING" accordingly for each test case.

## Intuition & Mathematical Observation

The problem statement explicitly defines Ashish's preference and decision-making hierarchy. This directly translates into a series of conditional checks.

1.  **Prioritize Pizza**: Ashish prefers pizza. So, the first thing to check is if he has enough money (`X`) to buy a pizza (`Y`).
    *   If `X >= Y`, he can afford pizza. Since he prefers it, he will definitely buy pizza.
2.  **Consider Burger (if Pizza is not affordable)**: If Ashish *cannot* afford pizza (i.e., `X < Y`), then he moves on to his next best option: a burger. We then check if he has enough money (`X`) to buy a burger (`Z`).
    *   If `X >= Z` (and we already know `X < Y`), he will buy a burger.
3.  **No Food (if neither is affordable)**: If he cannot afford pizza (`X < Y`) AND he also cannot afford a burger (`X < Z`), then he cannot buy anything.
    *   In this case, he eats "NOTHING".

This logic can be implemented using a simple `if-else if-else` structure. No complex algorithms, data structures, or mathematical observations beyond basic comparisons are required.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution involves reading three integers and performing a few constant-time comparisons and an output operation. These operations take a fixed amount of time regardless of the input values (within integer limits). If there are $T$ test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`X`, `Y`, `Z`, `T`) to store input and loop counters. The memory usage does not grow with the size or value of the inputs.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
// #include <bits/stdc++.h> // A common header in competitive programming that includes most standard libraries.
// Using specific headers like <iostream> is generally better practice for clarity,
// but <bits/stdc++.h> is often allowed and used in contests.
// For this problem, <iostream> is sufficient.

// using namespace std; // This line is often used to avoid typing std:: repeatedly.
// Per problem instructions, it's allowed. I'll use std:: explicitly for clarity.

void solve() {
    int X, Y, Z;
    // Read the money Ashish has (X), cost of PIZZA (Y), and cost of BURGER (Z).
    std::cin >> X >> Y >> Z;

    // Ashish prefers PIZZA over BURGER.
    // First, check if he can afford a PIZZA.
    if (X >= Y) {
        // If he has enough money for PIZZA, he will eat PIZZA.
        std::cout << "PIZZA\n";
    } 
    // If he cannot afford PIZZA (i.e., X < Y), then check if he can afford a BURGER.
    else if (X >= Z) {
        // If he has enough money for BURGER (and couldn't afford PIZZA), he will eat BURGER.
        std::cout << "BURGER\n";
    } 
    // If he cannot afford PIZZA and also cannot afford BURGER, he eats nothing.
    else {
        std::cout << "NOTHING\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases.
    std::cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for the current test case.
    }

    return 0; // Indicate successful execution.
}
```