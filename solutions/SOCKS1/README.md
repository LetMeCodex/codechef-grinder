# Valid Pair (SOCKS1)
- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has three socks, each with a different color. The colors are represented by integers $A$, $B$, and $C$. Chef wants to know if it's possible to form at least one pair of socks of the same color.

## Intuition & Mathematical Observation
The problem states that Chef has three socks with colors $A$, $B$, and $C$. To form a pair, two socks must have the same color. Therefore, we need to check if any two of the given three colors are identical.

Mathematically, this can be expressed as checking if:
1. Color $A$ is the same as color $B$ ($A = B$).
2. Color $A$ is the same as color $C$ ($A = C$).
3. Color $B$ is the same as color $C$ ($B = C$).

If any of these conditions are true, Chef can form a pair. Otherwise, if all three colors are distinct, no pair can be formed.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of comparisons (at most three) and a constant number of input/output operations. These operations take a constant amount of time, regardless of the input values.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of integer variables ($A$, $B$, $C$) to store the input. The memory usage does not grow with the input size, making it constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common C++ headers like iostream, vector, algorithm, etc.

using namespace std; // Allows using standard library components without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C; // Declare three integer variables to store the colors of the socks
    
    // Read the three space-separated integers A, B, and C from standard input
    cin >> A >> B >> C;

    // Check if any two socks have the same color.
    // This can be done by comparing A with B, A with C, and B with C.
    // If any of these comparisons are true, it means Chef can form a pair.
    if (A == B || A == C || B == C) {
        // If a pair can be formed, print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If no two socks have the same color, print "NO" followed by a newline character.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution
}
```