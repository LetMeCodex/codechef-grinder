# [IceCream Cones (ICECONE6)](https://www.codechef.com/problems/ICECONE6)
- **Difficulty Rating**: 484
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the amount of ice cream remaining after a certain period, given its initial quantity and a constant melting rate. Specifically, we are given:
1.  `X`: The initial amount of ice cream in grams.
2.  `Y`: The amount of ice cream that melts per minute.
3.  `N`: The total time in minutes for which the ice cream is exposed.

We need to determine the final amount of ice cream left. If all the ice cream melts, the remaining amount should be 0.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic.

1.  **Calculate total melted amount**: If `Y` grams of ice cream melt every minute, then over `N` minutes, the total amount of ice cream that melts will be `Y * N` grams.

2.  **Calculate theoretical remaining amount**: Subtract the total melted amount from the initial amount: `X - (Y * N)`.

3.  **Handle negative remaining amount**: Ice cream cannot exist in negative quantities. If the calculated `X - (Y * N)` is less than 0, it means all the ice cream has melted, and the actual remaining amount is 0. Therefore, the final amount should be the maximum of 0 and the theoretical remaining amount. This can be expressed as `max(0, X - (Y * N))`.

This simple formula directly gives us the solution for each test case.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of operations: reading three integers, one multiplication, one subtraction, and one `max` operation. These operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `X`, `Y`, `N`, `melted_amount`, `remaining_amount`, `final_amount`) to store input and intermediate results. The amount of memory used by these variables is constant and does not depend on the input values or the number of test cases. Hence, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream, algorithm, etc.

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int X, Y, N;
        cin >> X >> Y >> N; // Read initial ice cream (X), melting rate (Y), and time (N)

        // Calculate the total amount of ice cream that melts over N minutes.
        // Each minute, Y grams melt, so after N minutes, Y * N grams melt.
        int melted_amount = Y * N;

        // Calculate the amount of ice cream theoretically remaining.
        // This could be negative if more ice cream melts than initially present.
        int remaining_amount = X - melted_amount;

        // Ice cream cannot be negative. If the calculated remaining_amount is less than 0,
        // it means all the ice cream has melted, and 0 grams are left.
        // std::max(0, remaining_amount) ensures the output is never negative.
        int final_amount = max(0, remaining_amount);

        cout << final_amount << "\n"; // Output the final amount of ice cream left, followed by a newline
    }

    return 0; // Indicate successful program execution
}
```