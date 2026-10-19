# Passing Exams (PASSEXAMS)
- **Difficulty Rating**: 480
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a student can pass a course based on their marks in three subjects: Mathematics (M), Physics (P), and Chemistry (C). A student passes the course if they score at least 50 marks in at least two of these three subjects. We are given the marks for each subject and need to output "Yes" if the student passes, and "No" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in counting how many subjects the student has passed. A student passes a subject if their score in that subject is 50 or greater. The condition for passing the course is that the number of subjects passed must be at least 2.

Let $M$, $P$, and $C$ be the marks obtained by the student in Mathematics, Physics, and Chemistry, respectively.

The conditions for passing each subject are:
- Mathematics: $M \ge 50$
- Physics: $P \ge 50$
- Chemistry: $C \ge 50$

We need to count how many of these conditions are true. Let's say `passed_count` is the number of subjects the student passed.

`passed_count` can be calculated as:
`passed_count = (M >= 50) + (P >= 50) + (C >= 50)`
(where boolean expressions evaluate to 1 if true, and 0 if false).

The student passes the course if `passed_count >= 2`.

Therefore, the logic is straightforward:
1. Read the marks for the three subjects.
2. Initialize a counter for passed subjects to 0.
3. For each subject, check if the marks are 50 or greater. If so, increment the counter.
4. After checking all three subjects, if the counter is 2 or more, output "Yes". Otherwise, output "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$
The program performs a fixed number of operations regardless of the input values. It reads three integers, performs three comparisons, and a final comparison. These operations take constant time.

- **Space Complexity**: $O(1)$
The program uses a fixed amount of memory to store the input variables ($t$, $x$, $y$, $z$) and a counter variable (`passed_exams`). This memory usage does not grow with the input size, hence it's constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x, y, z; // Marks in Mathematics, Physics, and Chemistry
        cin >> x >> y >> z;

        int passed_exams = 0; // Counter for subjects passed

        // Check if the student passed Mathematics
        if (x >= 50) {
            passed_exams++;
        }
        // Check if the student passed Physics
        if (y >= 50) {
            passed_exams++;
        }
        // Check if the student passed Chemistry
        if (z >= 50) {
            passed_exams++;
        }

        // The student passes the course if they passed at least 2 subjects
        if (passed_exams >= 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
```