# [The Three Topics (THREETOPICS)](https://www.codechef.com/problems/THREETOPICS)
- **Difficulty Rating**: 573
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a specific topic, represented by an integer `X`, is among a list of three available topics, represented by integers `A`, `B`, and `C`. We need to output "Yes" if `X` matches any of `A`, `B`, or `C`, and "No" otherwise.

## Intuition & Mathematical Observation

This is a very basic comparison problem. The core idea is to check if the value of `X` is equal to `A`, or equal to `B`, or equal to `C`. If any of these conditions hold true, it means `X` is one of the three topics, and we should output "Yes". If `X` does not match `A`, and also does not match `B`, and also does not match `C`, then it's not among the three topics, and we should output "No".

This can be directly translated into a logical OR operation: `(X == A) || (X == B) || (X == C)`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values. It reads four integers, performs at most three comparisons and two logical OR operations, and then prints a string. All these operations take constant time.

- **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store four integer variables (`A`, `B`, `C`, `X`). The memory usage does not scale with any input parameter, hence it is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B, C, X; // Declare four integer variables to store the topic IDs.

    // Read the four integer values from standard input.
    std::cin >> A >> B >> C >> X;

    // Check if X is equal to A, or B, or C using logical OR (||).
    if (X == A || X == B || X == C) {
        // If X matches any of the three topics, print "Yes".
        std::cout << "Yes\n";
    } else {
        // Otherwise (if X does not match any of them), print "No".
        std::cout << "No\n";
    }

    return 0; // Indicate successful program execution.
}

```