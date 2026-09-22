# The Ides of March (IDESM)
- **Difficulty Rating**: 231
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ is equal to 15. If $N$ is 15, we should output "Yes". Otherwise, we should output "No".

## Intuition & Mathematical Observation
The problem statement is remarkably straightforward. It directly asks for a comparison of the input integer $N$ with the specific value 15. There are no complex mathematical concepts or algorithms involved. The core of the problem is a simple conditional check.

The "Ides of March" is historically significant as the date of Julius Caesar's assassination. In this context, the number 15 holds a special meaning related to this event. The problem leverages this historical reference to frame a very simple programming task.

Therefore, the only "observation" needed is that the problem is a direct check for equality with 15.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading a single integer and performing a single comparison. These operations take constant time, regardless of the magnitude of the input integer $N$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable $N$ and for standard input/output operations. This memory usage does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio,
    // potentially speeding up I/O.
    // cin.tie(NULL) unties cin from cout, meaning cin operations
    // won't flush cout automatically, further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable to store the input.
    cin >> N; // Read the integer N from standard input.

    // Check if the input integer N is exactly equal to 15.
    if (N == 15) {
        // If N is 15, print "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // If N is not 15, print "No" followed by a newline character.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```