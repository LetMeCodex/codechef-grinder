# [A Balanced Contest (PERFCONT)](https://www.codechef.com/problems/PERFCONT)
- **Difficulty Rating**: 1184
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a programming contest is "balanced" given the number of problems ($N$) and the total number of participants ($P$). A contest is considered balanced if it has exactly one "cakewalk" problem and exactly two "hard" problems.

A problem is defined as:
- **Cakewalk**: If the number of participants who solved it is greater than or equal to $P/2$.
- **Hard**: If the number of participants who solved it is less than or equal to $P/10$.

We are given the number of participants who solved each of the $N$ problems and need to output "yes" if the contest is balanced, and "no" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in correctly identifying and counting the cakewalk and hard problems based on the given definitions.

Let $S_i$ be the number of participants who solved the $i$-th problem.
The conditions for a problem to be cakewalk or hard are:
- Cakewalk: $S_i \ge \lfloor P/2 \rfloor$
- Hard: $S_i \le \lfloor P/10 \rfloor$

Note that integer division in C++ (and most programming languages) automatically performs the floor operation for positive numbers, so $P/2$ and $P/10$ directly translate to $\lfloor P/2 \rfloor$ and $\lfloor P/10 \rfloor$.

A contest is balanced if and only if:
- The count of problems satisfying the cakewalk condition is exactly 1.
- The count of problems satisfying the hard condition is exactly 2.

We need to iterate through all $N$ problems, check if each problem meets the cakewalk criterion, and if it meets the hard criterion. We maintain two counters: one for cakewalk problems and one for hard problems. After processing all $N$ problems, we compare these counts with the required values (1 for cakewalk, 2 for hard).

It's important to note that a problem *could* potentially satisfy both conditions if $P/10 \ge P/2$. However, for any positive $P$, $P/10 < P/2$. Thus, a problem cannot be both cakewalk and hard simultaneously. This simplifies our counting: we don't need to worry about double-counting a single problem as both.

The algorithm would be:
1. Read the number of test cases, $T$.
2. For each test case:
   a. Read $N$ (number of problems) and $P$ (total participants).
   b. Calculate the cakewalk threshold: `cakewalk_threshold = P / 2`.
   c. Calculate the hard threshold: `hard_threshold = P / 10`.
   d. Initialize `cakewalk_count = 0` and `hard_count = 0`.
   e. Loop $N$ times:
      i. Read the number of solvers for the current problem, `solvers`.
      ii. If `solvers >= cakewalk_threshold`, increment `cakewalk_count`.
      iii. If `solvers <= hard_threshold`, increment `hard_count`.
   f. After the loop, check if `cakewalk_count == 1` AND `hard_count == 2`.
   g. If both conditions are true, print "yes". Otherwise, print "no".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case.
  We iterate through each of the $N$ problems once to check the conditions. The calculations for thresholds and the final comparison take constant time. Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$. Given the typical constraints for competitive programming problems, this linear time complexity per test case is efficient enough.

- **Space Complexity**: $O(1)$ per test case.
  We only use a few integer variables to store $N$, $P$, the thresholds, and the counts of cakewalk and hard problems. The amount of memory used does not depend on the input size $N$ or $P$, hence it's constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, P;
    cin >> N >> P; // Read the number of problems (N) and total participants (P)

    // Calculate the thresholds for cakewalk and hard problems using integer division
    // Integer division automatically handles the floor operation for positive integers.
    int cakewalk_threshold = P / 2;
    int hard_threshold = P / 10;

    int cakewalk_count = 0; // Counter for problems categorized as cakewalk
    int hard_count = 0;     // Counter for problems categorized as hard

    // Loop through each of the N problems
    for (int i = 0; i < N; ++i) {
        int solvers;
        cin >> solvers; // Read the number of participants who solved the current problem

        // Check if the current problem is a cakewalk problem
        if (solvers >= cakewalk_threshold) {
            cakewalk_count++;
        }
        // Check if the current problem is a hard problem
        // Note: A problem cannot be both cakewalk and hard because P/10 < P/2 for P > 0.
        if (solvers <= hard_threshold) {
            hard_count++;
        }
    }

    // Determine if the contest is balanced based on the counts
    // A balanced contest must have exactly 1 cakewalk and exactly 2 hard problems
    if (cakewalk_count == 1 && hard_count == 2) {
        cout << "yes\n"; // If balanced, print "yes"
    } else {
        cout << "no\n";  // Otherwise, print "no"
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```