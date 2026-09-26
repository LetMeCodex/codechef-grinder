# [Shopping Change (SHOPCHANGE)](https://www.codechef.com/problems/SHOPCHANGE)
- **Difficulty Rating**: 526
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef goes shopping and buys some items. He pays with a 100 rupee note. The problem asks us to calculate the change Chef should receive if the total cost of the items is `X` rupees. This calculation needs to be performed for multiple test cases.

**Input:**
- The first line contains an integer `T`, the number of test cases.
- Each subsequent line contains a single integer `X`, representing the cost of the items for that test case.

**Output:**
- For each test case, print the change Chef receives on a new line.

**Constraints:**
- $1 \le T \le 100$
- $1 \le X \le 100$

## Intuition & Mathematical Observation

The problem is a very basic arithmetic task. Chef pays with a fixed amount (100 rupees) and the items cost `X` rupees. To find the change, we simply subtract the cost of the items from the amount paid.

Mathematically, the change `C` can be expressed as:
$C = 100 - X$

Given the constraints ($1 \le X \le 100$), the change will always be between $0$ and $99$ (inclusive), which fits perfectly within a standard integer type. There are no edge cases or complex scenarios to consider beyond this simple subtraction.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   The program iterates `T` times, once for each test case.
    -   Inside the loop, it performs a constant number of operations: reading an integer `X`, performing a subtraction (`100 - X`), and printing the result. Each of these operations takes constant time, $O(1)$.
    -   Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    -   The program uses a few integer variables (`t`, `x`, `change`) to store the number of test cases, the item cost, and the calculated change, respectively.
    -   The memory used by these variables is constant and does not depend on the input size (`T` or `X`).
    -   No dynamic data structures or arrays are used that would consume memory proportional to the input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int x; // Declare an integer variable 'x' to store the price of items.
        cin >> x; // Read the price of items for the current test case.

        // Calculate the change Chef should receive.
        // Chef pays with 100 rupees, and items cost 'x' rupees.
        // The change is simply 100 - x.
        int change = 100 - x;

        // Print the calculated change followed by a newline character.
        // The problem requires output for each test case on a new line.
        cout << change << "\n";
    }

    return 0; // Indicate successful program execution.
}
```