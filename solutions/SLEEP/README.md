# [Sleep deprivation (SLEEP)](https://www.codechef.com/problems/SLEEP)
- **Difficulty Rating**: 348
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Chef is sleep deprived. According to the problem statement, a person is considered sleep deprived if they sleep strictly less than 7 hours. We are given the number of hours Chef slept, `X`, for several test cases. For each test case, we need to output "YES" if Chef is sleep deprived, and "NO" otherwise.

## Intuition & Mathematical Observation
This is a very basic conditional problem. The core logic revolves around a single comparison:
- If the number of hours Chef slept (`X`) is strictly less than 7, then Chef is sleep deprived.
- Otherwise (if `X` is 7 or more), Chef is not sleep deprived.

There are no complex mathematical observations or algorithms required. We simply need to read the input `X` and apply this direct comparison.

## Complexity Analysis
- **Time Complexity**: $O(T)$
    - The program reads `T` (number of test cases) once.
    - It then enters a loop that iterates `T` times.
    - Inside the loop, it performs a constant number of operations: reading an integer `X`, performing a comparison (`X < 7`), and printing a string ("YES" or "NO"). Each of these operations takes constant time, $O(1)$.
    - Therefore, the total time complexity is proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
    - The program uses a few integer variables (`T`, `X`) to store input and loop counters. These variables occupy a constant amount of memory, regardless of the input values or the number of test cases.
    - No data structures (like arrays, vectors, maps, etc.) are used that would grow with the input size.
    - Hence, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // T-- decrements T after each iteration, and the loop continues as long as T is non-zero.
    while (T--) {
        int X; // Declare an integer variable X to store the hours Chef slept.
        cin >> X; // Read the number of hours Chef slept for the current test case.

        // A person is sleep deprived if they slept strictly less than 7 hours.
        // Check if X is less than 7.
        if (X < 7) {
            // If X is strictly less than 7, Chef is sleep deprived.
            // Output "YES" followed by a newline character.
            cout << "YES\n";
        } else {
            // If X is 7 or more, Chef is not sleep deprived.
            // Output "NO" followed by a newline character.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```