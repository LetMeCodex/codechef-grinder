# Thala For A Reason (THALA7)
- **Difficulty Rating**: 235
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to read an integer `n` from the input. If `n` is equal to 7, we should print "THALA". Otherwise, we should print "SADGE".

## Intuition & Mathematical Observation
The problem statement is quite direct and doesn't involve complex mathematical concepts. The core of the problem lies in a simple conditional check. The number 7 is famously associated with the cricketer MS Dhoni, often referred to as "Thala" in Tamil Nadu. The problem leverages this cultural reference.

The only "observation" needed is to recognize that the problem is a direct implementation of an `if-else` condition based on the input value being exactly 7. There are no intricate mathematical properties or patterns to discover.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading a single integer and performing a single comparison. These operations take constant time, regardless of the magnitude of the input `n`.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable `n` and for standard input/output operations. This memory usage does not grow with the input size, hence it's constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) unties cin from cout, meaning cin operations
    // won't flush cout before they happen, further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Declare an integer variable to store the input.
    cin >> n; // Read the integer input from the standard input.

    // Check if the input integer 'n' is equal to 7.
    if (n == 7) {
        // If 'n' is 7, print "THALA" followed by a newline character.
        cout << "THALA\n";
    } else {
        // If 'n' is not 7, print "SADGE" followed by a newline character.
        cout << "SADGE\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```