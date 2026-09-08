# [Audible Range (AUDIBLE)](https://www.codechef.com/problems/AUDIBLE)
- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef's dog, Binary, can hear sounds within a specific frequency range. Given a frequency $X$, determine if Binary can hear it. Binary can hear sounds with frequencies between 67 Hz and 45000 Hz, inclusive.

## Intuition & Mathematical Observation
The problem statement directly provides the condition for Binary to hear a sound: the frequency $X$ must be greater than or equal to 67 and less than or equal to 45000. This translates to a simple mathematical inequality:

$67 \le X \le 45000$

Therefore, the core of the solution involves reading the input frequency $X$ and checking if it satisfies this inequality. If it does, we output "YES"; otherwise, we output "NO".

The problem also specifies that there will be multiple test cases. This means we need to read the number of test cases $T$ first and then iterate $T$ times, performing the check for each test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
    The solution involves a constant number of operations per test case: reading an integer, performing two comparisons, and printing an output. If there are $T$ test cases, the total time complexity is $O(T)$. However, since the operations per test case are constant, we often refer to the complexity per test case as $O(1)$.

- **Space Complexity**: $O(1)$.
    The solution uses a fixed amount of memory to store variables like $T$, $X$, and loop counters, regardless of the input size. This makes the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X; // Declare an integer variable X to store the frequency of Chef's commands.
        cin >> X; // Read the frequency X for the current test case.

        // Check if the frequency X falls within the audible range for binary.
        // The range is from 67 Hertz to 45000 Hertz, inclusive.
        if (X >= 67 && X <= 45000) {
            // If X is within the range, binary can hear it.
            cout << "YES\n"; // Print "YES" followed by a newline.
        } else {
            // Otherwise, X is outside the audible range.
            cout << "NO\n"; // Print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```