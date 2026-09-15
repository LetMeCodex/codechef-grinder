# [Number of Credits (CREDS)](https://www.codechef.com/problems/CREDS)

- **Difficulty Rating**: 306
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to calculate the total number of credits a student earns based on their course enrollment. The credit distribution is as follows:
- **RTP courses**: 4 credits each.
- **Audit courses**: 2 credits each.
- **Non-RTP courses**: 0 credits each.

Given the number of courses in each category ($X, Y, Z$), we need to output the total credits earned.

## Intuition & Mathematical Observation
The total number of credits is a simple linear combination of the number of courses and their respective credit weights. 

Mathematically, if $X$ is the number of RTP courses, $Y$ is the number of Audit courses, and $Z$ is the number of Non-RTP courses, the total credits $C$ can be calculated as:
$$C = (X \times 4) + (Y \times 2) + (Z \times 0)$$

Since any number multiplied by zero is zero, the formula simplifies to:
$$C = 4X + 2Y$$

We simply read the three integers for each test case, apply this formula, and print the result.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int X, Y, Z;
        // Read the number of RTP, Audit, and Non-RTP courses for the current test case.
        cin >> X >> Y >> Z; 

        // Calculate the total credits based on the given distribution:
        // - Each RTP course gives 4 credits.
        // - Each Audit course gives 2 credits.
        // - Each Non-RTP course gives 0 credits.
        // The total credits will be (X * 4) + (Y * 2) + (Z * 0).
        // Since (Z * 0) is always 0, it simplifies to (X * 4) + (Y * 2).
        int total_credits = (X * 4) + (Y * 2); 

        // Print the calculated total credits for the current test case,
        // followed by a newline character as required by the output format.
        cout << total_credits << "\n";
    }

    return 0; // Indicate successful execution of the program
}
```