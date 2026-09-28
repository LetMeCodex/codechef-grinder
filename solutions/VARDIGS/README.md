# [Varied Digits (VARDIGS)](https://www.codechef.com/problems/VARDIGS)
- **Difficulty Rating**: 215
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given two-digit integer has distinct digits. If the two digits are different, we should output "Yes"; otherwise, we should output "No".

## Intuition & Mathematical Observation
The core of the problem lies in comparing the two digits of a two-digit number. A two-digit integer $X$ can be represented as $10 \times \text{tens\_digit} + \text{units\_digit}$.

To extract the units digit, we can use the modulo operator. For any integer $X$, $X \pmod{10}$ gives its units digit.
For example, if $X = 47$, then $47 \pmod{10} = 7$.

To extract the tens digit, we can use integer division. For a two-digit number $X$, $X / 10$ (integer division) gives its tens digit.
For example, if $X = 47$, then $47 / 10 = 4$.

Once we have both digits, we simply need to compare them. If `units_digit != tens_digit`, the number has varied digits.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (modulo and division) and a single comparison. These operations take constant time, regardless of the input value (as long as it fits within standard integer types).

- **Space Complexity**: $O(1)$
The solution uses a few integer variables to store the input and the extracted digits. The amount of memory used is constant and does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream for cin/cout

// Using namespace std; is requested by the problem.
using namespace std;

int main() {
    // Fast I/O is requested by the problem.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement specifies: "The only line of input will contain a single 2-digit integer, X."
    // This indicates that there is only one test case per execution, so no explicit loop for 't' test cases is needed.

    int X;
    cin >> X; // Read the 2-digit integer X

    // To determine if the digits are different, we need to extract them.
    // For a 2-digit number X:
    // The units digit can be obtained using the modulo operator: X % 10
    // The tens digit can be obtained using integer division: X / 10

    int units_digit = X % 10;
    int tens_digit = X / 10;

    // Compare the two extracted digits.
    // If they are different, the number is "varied".
    // Otherwise, it is not "varied".
    if (units_digit != tens_digit) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
```