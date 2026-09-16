# [Netflix (NETFLIX)](https://www.codechef.com/problems/NETFLIX)
- **Difficulty Rating**: 493
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a Netflix subscription can be afforded by any two out of three friends. We are given the amount of money Alice (`A`), Bob (`B`), and Charlie (`C`) each have, and the total cost of the Netflix subscription (`X`). We need to output "YES" if any pair of friends can pool their money to meet or exceed the cost `X`, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in checking all possible combinations of two friends. Since there are three friends (Alice, Bob, Charlie), there are exactly three unique pairs we need to consider:

1.  **Alice and Bob**: Can they afford it? This is true if `A + B >= X`.
2.  **Alice and Charlie**: Can they afford it? This is true if `A + C >= X`.
3.  **Bob and Charlie**: Can they afford it? This is true if `B + C >= X`.

If *any* of these conditions are met, then the subscription can be afforded by a pair of friends, and the answer is "YES". If *none* of these conditions are met, then no pair of friends can afford it, and the answer is "NO".

This can be directly translated into a logical OR condition:
`((A + B >= X) || (A + C >= X) || (B + C >= X))`

If this entire expression evaluates to true, we print "YES"; otherwise, we print "NO".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a fixed number of operations: reading four integers, three additions, three comparisons, and two logical OR operations. These are all constant-time operations.
    *   Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `A`, `B`, `C`, `X`) to store input and loop counters.
    *   The amount of memory used does not depend on the input values or the number of test cases (beyond storing `T` itself).
    *   This constant memory usage leads to a space complexity of $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int A, B, C, X; // Variables to store Alice's, Bob's, Charlie's money and Netflix cost
        cin >> A >> B >> C >> X; // Read the four integers for the current test case

        // Check if any two of them can contribute enough money to buy the subscription.
        // There are three possible pairs: (Alice, Bob), (Alice, Charlie), (Bob, Charlie).
        // If the sum of money for any pair is greater than or equal to the subscription cost X,
        // then they can afford it.
        if ((A + B >= X) || (A + C >= X) || (B + C >= X)) {
            cout << "YES\n"; // Output YES if at least one pair can afford it
        } else {
            cout << "NO\n"; // Output NO otherwise
        }
    }

    return 0; // Indicate successful execution
}
```