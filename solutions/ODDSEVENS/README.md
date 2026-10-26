# [Odds and Evens (ODDSEVENS)](https://www.codechef.com/problems/ODDSEVENS)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a simple game played by Alice and Bob. Alice chooses a number `A` and Bob chooses a number `B`. They then calculate the sum of their chosen numbers, `A + B`.

The rules for determining the winner are:
1. If the sum `A + B` is **odd**, Alice wins.
2. If the sum `A + B` is **even**, Bob wins.

We are given `T` test cases. For each test case, we need to read Alice's number `A` and Bob's number `B`, and then output "Alice" or "Bob" based on the parity of their sum.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of parity (whether a number is even or odd) when adding two integers. Let's recall the rules for addition of parities:

*   **Even + Even = Even**
*   **Odd + Odd = Even**
*   **Even + Odd = Odd**
*   **Odd + Even = Odd**

From these rules, we can observe a pattern:
*   If both numbers (`A` and `B`) have the **same parity** (both even, or both odd), their sum `A + B` will always be **even**.
*   If the numbers (`A` and `B`) have **different parities** (one even and one odd), their sum `A + B` will always be **odd**.

The problem statement directly tells us that Alice wins if `A + B` is odd, and Bob wins if `A + B` is even.
Therefore, the strategy is straightforward:
1.  Read the two numbers, `A` and `B`.
2.  Calculate their sum, `S = A + B`.
3.  Check the parity of `S`:
    *   If `S % 2 == 1` (i.e., `S` is odd), Alice wins.
    *   If `S % 2 == 0` (i.e., `S` is even), Bob wins.

This approach directly implements the given winning conditions based on the sum's parity.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a constant number of operations: reading two integers, performing one addition, one modulo operation, and one print operation. These operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`t`, `a`, `b`, `sum`) regardless of the input values or the number of test cases. These variables occupy a constant amount of memory.
    *   Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of testcases.
    cin >> t; // Read the number of testcases from standard input.

    // Loop 't' times, once for each testcase.
    while (t--) {
        int a, b; // Declare two integer variables 'a' and 'b' for Alice's and Bob's numbers.
        cin >> a >> b; // Read Alice's and Bob's numbers from standard input.

        int sum = a + b; // Calculate the sum of the numbers played by Alice and Bob.

        // Determine the winner based on the parity of the sum.
        // If the sum is odd (sum % 2 == 1), Alice wins.
        // Otherwise (if sum % 2 == 0), the sum is even, and Bob wins.
        if (sum % 2 == 1) {
            cout << "Alice\n"; // Output "Alice" followed by a newline if Alice wins.
        } else {
            cout << "Bob\n"; // Output "Bob" followed by a newline if Bob wins.
        }
    }

    return 0; // Indicate successful program execution.
}
```