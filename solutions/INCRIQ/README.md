# [Increase IQ (INCRIQ)](https://www.codechef.com/problems/INCRIQ)
- **Difficulty Rating**: 478
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef's IQ will be strictly greater than 170 after he learns a musical instrument. Chef's current IQ is given as `X`. Learning a musical instrument increases his IQ by 7 points. We need to output "Yes" if his new IQ is greater than 170, and "No" otherwise.

## Intuition & Mathematical Observation

The problem is straightforward and involves a simple arithmetic calculation followed by a comparison.

1.  **Calculate Chef's new IQ**: Chef's current IQ is `X`. When he learns a musical instrument, his IQ increases by 7 points. Therefore, his new IQ will be `X + 7`.
2.  **Compare with Einstein's IQ**: We need to check if this new IQ is *strictly greater* than 170. This translates to the condition `(X + 7) > 170`.
3.  **Output**: If the condition `(X + 7) > 170` is true, we print "Yes". Otherwise, we print "No".

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a direct implementation of the problem statement.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations: reading an integer, performing one addition, one comparison, and one print operation. These operations take constant time, regardless of the input value of `X`.
*   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`X`, `final_iq`). The memory usage does not depend on the input value or any other factor, hence it is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store Chef's current IQ.
    cin >> X; // Read Chef's current IQ from standard input.

    // Calculate Chef's IQ after learning a musical instrument.
    // The problem states that playing an instrument increases IQ by 7 points.
    int final_iq = X + 7;

    // Determine if Chef's final IQ is strictly greater than Einstein's IQ (170).
    if (final_iq > 170) {
        // If Chef's final IQ is strictly greater than 170, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, print "No".
        cout << "No\n";
    }

    return 0; // Indicate successful execution of the program.
}
```