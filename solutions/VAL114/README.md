# [Valentines Contest (VAL114)](https://www.codechef.com/problems/VAL114)
- **Difficulty Rating**: 318
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given "starters" contest number `N` is "Likely" to be organized on Valentine's Day. The problem statement explicitly provides the condition: "starters 121 is likely to be organised on Valentine's day." For any other starters number, it is implied to be "Unlikely". The input `N` is an integer between 120 and 123, inclusive.

## Intuition & Mathematical Observation

This is a very basic conditional problem. The problem statement directly gives us the rule to follow:
- If the given contest number `N` is `121`, then it is "Likely" to be organized on Valentine's Day.
- For any other valid contest number `N` (i.e., 120, 122, or 123), it is "Unlikely".

There are no complex algorithms, data structures, or mathematical observations required beyond a direct interpretation of this rule. We simply need to read the input `N` and check if it equals `121`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value: one input read, one comparison, and one output write. All these operations take constant time.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a single integer variable `N`. No additional data structures are used that would scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input.
    int N;

    // Read the single integer N from standard input.
    cin >> N;

    // According to the problem statement, "starters 121 is likely to be organised on Valentine's day."
    // For any other starters number within the given constraints (120 to 123),
    // it is implied to be "Unlikely".
    if (N == 121) {
        // If N is 121, output "Likely".
        cout << "Likely\n";
    } else {
        // For any other value of N (120, 122, or 123), output "Unlikely".
        cout << "Unlikely\n";
    }

    return 0; // Indicate successful program execution.
}
```