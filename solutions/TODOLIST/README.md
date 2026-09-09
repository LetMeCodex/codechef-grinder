# [Problems in your to-do list (TODOLIST)](https://www.codechef.com/problems/TODOLIST)
- **Difficulty Rating**: 580
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef manage his to-do list of competitive programming problems. Chef wants to remove all problems from his list that have a difficulty rating of 1000 or more. We are given the number of problems `N` and then `N` integer values representing the difficulty of each problem. Our task is to count how many problems Chef needs to remove from his list. This process needs to be repeated for multiple test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for removing a problem: its difficulty must be 1000 or greater. This translates to a simple conditional check for each problem.

The intuition is straightforward:
1. Initialize a counter for problems to be removed to zero.
2. For each problem in the list:
    a. Read its difficulty.
    b. If the difficulty is greater than or equal to 1000, increment the counter.
3. After checking all problems, the final value of the counter is the answer for that test case.

There are no complex mathematical observations or algorithms required; it's a direct implementation of the given condition.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    For each test case, we read an integer `N` and then iterate `N` times. Inside the loop, we perform constant time operations: reading an integer, a comparison, and potentially an increment. Thus, the total time complexity for one test case is directly proportional to `N`. If there are `T` test cases, the total time complexity would be $O(\sum N)$ over all test cases.

-   **Space Complexity**: $O(1)$.
    We only use a few integer variables (`t`, `n`, `problems_to_remove`, `difficulty`, `i`) to store the current test case count, number of problems, the count of problems to remove, the current problem's difficulty, and the loop counter. These variables occupy a constant amount of memory regardless of the input size `N`. We do not store the difficulties of all problems in an array or vector.

## Solution Code

```cpp
#include <iostream>
#include <vector> // Not strictly needed for this solution, but often included
#include <algorithm> // Not strictly needed for this solution, but often included

int main() {
    // Fast I/O: Unties C++ standard streams from C standard streams
    // and prevents flushing of cout before cin reads.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n;
        std::cin >> n; // Read the number of problems for the current test case
        int problems_to_remove = 0; // Initialize counter for problems to remove
        for (int i = 0; i < n; ++i) { // Loop N times to read each problem's difficulty
            int difficulty;
            std::cin >> difficulty; // Read the difficulty of the current problem
            // Check if the difficulty meets the removal criteria
            if (difficulty >= 1000) {
                problems_to_remove++; // Increment counter if criteria met
            }
        }
        // Output the total count of problems to remove for the current test case
        std::cout << problems_to_remove << "\n"; 
    }
    return 0; // Indicate successful execution
}

```