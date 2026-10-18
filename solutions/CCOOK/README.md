# [Chef and Cook-Off (CCOOK)](https://www.codechef.com/problems/CCOOK)
- **Difficulty Rating**: 961
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to classify competitors in a Cook-Off contest based on the number of problems they solved. There are a total of 5 problems in the contest. For each competitor, we are given 5 integers, where each integer is either `1` (if the competitor solved that specific problem) or `0` (if they did not). We need to read the number of competitors `N`, and then for each of the `N` competitors, read their problem statuses, count the total problems solved, and print their corresponding classification:

*   **0 problems solved**: "Beginner"
*   **1 problem solved**: "Junior Developer"
*   **2 problems solved**: "Middle Developer"
*   **3 problems solved**: "Senior Developer"
*   **4 problems solved**: "Hacker"
*   **5 problems solved**: "Jeff Dean"

## Intuition & Mathematical Observation

The problem is a straightforward counting and conditional logic exercise. For each competitor, the core task is to iterate through the status of the 5 problems and simply count how many of them are marked as `1`. Once this count is obtained, we use a series of `if-else if` statements to match the count to the specified classification string and print it.

There are no complex algorithms, data structures, or deep mathematical observations required. The number of problems (5) is fixed and very small, making a direct iteration and counting approach highly efficient. The problem essentially tests basic input/output, loop structures, and conditional statements.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   The program reads `N`, the number of competitors, which is an $O(1)$ operation.
    *   There is an outer loop that runs `N` times, once for each competitor.
    *   Inside this outer loop, there's an inner loop that runs exactly 5 times (for the 5 problems).
    *   Within the inner loop, we perform constant time operations: reading an integer, an `if` condition, and potentially incrementing a counter. This takes $O(1)$ time per problem status.
    *   After the inner loop, a series of `if-else if` statements are executed to determine the classification. This is also a constant time operation, as there are a fixed number of conditions (6 in total). Printing a string also takes time proportional to its length, but since the maximum length is constant ("Junior Developer" has 16 characters), this is also considered $O(1)$.
    *   Therefore, for each competitor, the operations take $5 \times O(1) + O(1) = O(1)$ time.
    *   Since this is repeated `N` times, the total time complexity is $N \times O(1) = O(N)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`N`, `solved_problems_count`, `problem_status`, loop counters `i`, `j`).
    *   These variables occupy a constant amount of memory regardless of the input size `N`.
    *   No arrays, vectors, or other data structures whose size scales with `N` are used.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for convenience in competitive programming

// Using the standard namespace to avoid writing std:: repeatedly.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer N to store the number of competitors.
    cin >> N; // Read the value of N from standard input.

    // Loop N times, once for each competitor.
    for (int i = 0; i < N; ++i) {
        int solved_problems_count = 0; // Initialize a counter for problems solved by the current competitor.

        // Loop 5 times to read the status of each of the five problems.
        for (int j = 0; j < 5; ++j) {
            int problem_status; // Declare an integer to store the status of the current problem (0 or 1).
            cin >> problem_status; // Read the problem status.

            // If the problem status is 1, it means the competitor solved this problem.
            if (problem_status == 1) {
                solved_problems_count++; // Increment the counter.
            }
        }

        // Based on the total number of problems solved, classify the competitor.
        if (solved_problems_count == 0) {
            cout << "Beginner\n"; // Print "Beginner" if 0 problems solved.
        } else if (solved_problems_count == 1) {
            cout << "Junior Developer\n"; // Print "Junior Developer" if 1 problem solved.
        } else if (solved_problems_count == 2) {
            cout << "Middle Developer\n"; // Print "Middle Developer" if 2 problems solved.
        } else if (solved_problems_count == 3) {
            cout << "Senior Developer\n"; // Print "Senior Developer" if 3 problems solved.
        } else if (solved_problems_count == 4) {
            cout << "Hacker\n"; // Print "Hacker" if 4 problems solved.
        } else if (solved_problems_count == 5) {
            cout << "Jeff Dean\n"; // Print "Jeff Dean" if all 5 problems solved.
        }
    }

    return 0; // Indicate successful execution of the program.
}
```