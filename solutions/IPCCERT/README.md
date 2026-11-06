# [Chef and IPC Certificates (IPCCERT)](https://www.codechef.com/problems/IPCCERT)
- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of students who are eligible to receive an IPC certificate. There are `N` students in total. For each student, we are given `K` lecture minutes they watched and the number of questions (`Q_i`) they asked. A student is eligible for a certificate if they meet two criteria:
1.  Their total lecture minutes watched across all `K` lectures must be at least `M` (a given minimum threshold).
2.  The number of questions they asked (`Q_i`) must be no more than 10.

We need to output the total count of eligible students.

## Intuition & Mathematical Observation

The problem is a straightforward counting problem that requires iterating through each student and applying a set of conditions. There are no complex algorithms or data structures needed.

For each student, the process is as follows:
1.  We need to calculate the sum of minutes watched for all `K` lectures. This involves reading `K` integer values and accumulating them into a `total_lecture_minutes` variable.
2.  After summing the lecture minutes, we read the number of questions asked by the student, `Q_i`.
3.  We then check if both eligibility conditions are met:
    *   `total_lecture_minutes >= M`
    *   `Q_i <= 10`
4.  If both conditions are true, we increment a counter for eligible students.

After processing all `N` students, the final value of the counter will be our answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the initial `N`, `M`, `K` takes constant time, $O(1)$.
    *   The program iterates `N` times, once for each student.
    *   Inside this loop, for each student, it iterates `K` times to read and sum the lecture minutes. This part takes $O(K)$ time.
    *   Reading `Q_i` and performing the conditional check takes constant time, $O(1)$.
    *   Therefore, the total time complexity is dominated by the nested loops, resulting in $N$ iterations, each performing $K$ operations. This gives a total time complexity of $O(N \cdot K)$.
    *   Given `N` up to $10^5$ and `K` up to $1000$, the maximum operations would be around $10^5 \times 1000 = 10^8$, which is acceptable within typical time limits for competitive programming (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   The solution uses a few integer variables to store `N`, `M`, `K`, `eligible_students_count`, `total_lecture_minutes`, `T_ij`, and `Q_i`.
    *   These variables occupy a constant amount of memory regardless of the input size `N` or `K`.
    *   Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    // Read the number of students (N), the minimum required total lecture minutes (M),
    // and the number of lectures (K) from the first line of input.
    cin >> N >> M >> K;

    int eligible_students_count = 0; // Initialize a counter for students who meet the certificate criteria.

    // Loop through each of the N students.
    for (int i = 0; i < N; ++i) {
        long long total_lecture_minutes = 0; // Variable to store the total minutes watched by the current student.
                                            // Using 'long long' to be safe against potential overflow,
                                            // although 'int' would be sufficient given the problem constraints
                                            // (max sum: 1000 lectures * 1000 min/lecture = 10^6 minutes,
                                            // which fits within a standard 32-bit integer).
        
        // Loop through each of the K lectures for the current student.
        // Read the minutes watched for each lecture and add it to the total.
        for (int j = 0; j < K; ++j) {
            int T_ij; // Minutes watched for the j-th lecture by the i-th student.
            cin >> T_ij;
            total_lecture_minutes += T_ij; // Accumulate the minutes.
        }

        int Q_i; // Number of times the current student asked the question.
        cin >> Q_i;

        // Check if the current student meets both criteria for receiving a certificate:
        // 1. The total lecture minutes watched must be at least M.
        // 2. The number of questions asked must be no more than 10.
        if (total_lecture_minutes >= M && Q_i <= 10) {
            eligible_students_count++; // If both criteria are met, increment the counter.
        }
    }

    // Print the final count of eligible participants to standard output, followed by a newline.
    cout << eligible_students_count << "\n";

    return 0; // Indicate successful program execution.
}
```