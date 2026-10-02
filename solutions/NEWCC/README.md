# [All New CodeChef (NEWCC)](https://www.codechef.com/problems/NEWCC)
- **Difficulty Rating**: 354
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the runtime of two systems, an "old" system and a "new" system, for a given task. We are provided with two integer values, `X` and `Y`, representing the runtime of the old system and the new system, respectively. We need to output "New" if the new system is faster, "Old" if the old system is faster, and "Same" if they have the same runtime.

## Intuition & Mathematical Observation
The core of the problem is a simple comparison between two numbers. The runtime of a system directly indicates its speed: a smaller runtime means a faster system.

Let `X` be the runtime of the old system and `Y` be the runtime of the new system.
We need to determine the relationship between `X` and `Y`:

1.  **If `Y < X`**: This means the new system takes less time to complete the task than the old system. Therefore, the new system is faster.
2.  **If `X < Y`**: This means the old system takes less time to complete the task than the new system. Therefore, the old system is faster.
3.  **If `X == Y`**: This means both systems take the same amount of time to complete the task. Therefore, they are equally fast.

This logic directly translates into a series of conditional statements (if-else if-else).

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves reading two integers and performing a constant number of comparisons and one output operation. These operations take a fixed amount of time, regardless of the input values.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store the two input variables (`X` and `Y`) and a few other variables for program control. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y; // Declare two integer variables for runtimes

    // Read the two space-separated integers X and Y from standard input
    cin >> X >> Y;

    // Compare the runtimes to determine which system is faster
    if (Y < X) {
        // If the new system's runtime (Y) is less than the old system's (X),
        // the new system is faster.
        cout << "New\n";
    } else if (X < Y) {
        // If the old system's runtime (X) is less than the new system's (Y),
        // the old system is faster.
        cout << "Old\n";
    } else {
        // If both runtimes are equal, they are equally fast.
        cout << "Same\n";
    }

    return 0; // Indicate successful execution
}
```