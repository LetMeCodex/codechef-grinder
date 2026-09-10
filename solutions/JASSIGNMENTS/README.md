# [Janmansh and Assignments (JASSIGNMENTS)](https://www.codechef.com/problems/JASSIGNMENTS)
- **Difficulty Rating**: 513
- **Solved in**: 1 attempt(s)

## Problem Summary

Janmansh has 3 assignments to complete. Each assignment takes 1 hour to finish. He starts working at `X` PM and needs to submit all assignments by 10 PM. The task is to determine if Janmansh can complete all his assignments on time.

## Intuition & Mathematical Observation

The core of the problem lies in calculating Janmansh's finish time and comparing it against the deadline.

1.  **Time per assignment**: Each assignment takes 1 hour.
2.  **Total assignments**: There are 3 assignments.
3.  **Total time required**: To complete all 3 assignments, Janmansh will need `3 * 1 = 3` hours.
4.  **Starting time**: He starts working at `X` PM.
5.  **Finish time**: If he starts at `X` PM and works for 3 hours, he will finish at `X + 3` PM.
6.  **Deadline**: The deadline for submission is 10 PM.

Therefore, Janmansh can complete all his assignments on time if and only if his calculated finish time (`X + 3`) is less than or equal to the deadline (10 PM).
Mathematically, this translates to the condition: `X + 3 <= 10`.

If this condition is true, the answer is "Yes"; otherwise, it's "No".

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading an integer, one addition, one comparison, and printing a string. These operations take constant time, $O(1)$. Thus, the total time complexity is proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `X`, `finish_time`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of `X` or `T` (beyond `T` being the number of iterations, not an input size for an array or similar data structure). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

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
        int X; // Declare an integer variable X to store the starting time.
        cin >> X; // Read the starting time X for the current test case.

        // Calculate the time Janmansh will finish all 3 assignments.
        // Each assignment takes 1 hour, so 3 assignments take 3 hours.
        int finish_time = X + 3;

        // Check if the finish time is on or before 10 PM.
        if (finish_time <= 10) {
            // If he finishes by 10 PM, he can complete them on time.
            cout << "Yes\n"; // Output "Yes" followed by a newline.
        } else {
            // If he finishes after 10 PM, he cannot complete them on time.
            cout << "No\n"; // Output "No" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```