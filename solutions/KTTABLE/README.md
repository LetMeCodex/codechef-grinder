# Kitchen Timetable (KTTABLE)
- **Difficulty Rating**: 997
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine how many students can successfully cook their dishes given a timetable. We are provided with two arrays: `A` of size `N`, where `A[i]` is the finish time by which the `i`-th student must complete their dish, and `B` of size `N`, where `B[i]` is the time required for the `i`-th student to cook their dish. The students cook sequentially. The first student starts at time 0. The `i`-th student can only start cooking after the `(i-1)`-th student has finished. We need to find the number of students who can finish their cooking within their allotted time.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the time available for each student. Since students cook sequentially, the `i`-th student can only start cooking after the `(i-1)`-th student has finished.

Let's denote:
- `A[i]` as the finish time for the `i`-th student.
- `B[i]` as the cooking time required for the `i`-th student.

The `0`-th student (first student) starts at time 0 and must finish by `A[0]`. The time available for the `0`-th student is `A[0] - 0 = A[0]`. They can cook if `B[0] <= A[0]`.

The `1`-st student starts cooking only after the `0`-th student finishes. The `0`-th student finishes at time `A[0]`. So, the `1`-st student starts at time `A[0]` and must finish by `A[1]`. The time available for the `1`-st student is `A[1] - A[0]`. They can cook if `B[1] <= A[1] - A[0]`.

Generalizing this, for the `i`-th student:
- They start cooking at time `A[i-1]` (where `A[-1]` is considered 0 for the first student).
- They must finish cooking by time `A[i]`.
- The time available for the `i`-th student is `A[i] - A[i-1]`.
- The `i`-th student can cook their dish if `B[i] <= A[i] - A[i-1]`.

We can iterate through the students from `i = 0` to `N-1`. For each student, we calculate the available time and compare it with their required cooking time. If the available time is greater than or equal to the required time, we increment a counter.

To implement this efficiently, we can maintain a variable `prev_finish_time` which stores the finish time of the previous student. Initially, `prev_finish_time` is 0 (representing the start time for the first student). In each iteration `i`:
1. The current student's finish time is `A[i]`.
2. The available time for the current student is `A[i] - prev_finish_time`.
3. If `B[i] <= A[i] - prev_finish_time`, increment the count.
4. Update `prev_finish_time` to `A[i]` for the next iteration.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    The code iterates through the `N` students once to check if they can cook. Reading the input also takes $O(N)$ time. Therefore, the total time complexity is linear with respect to the number of students.

- **Space Complexity**: $O(N)$
    We use two vectors, `A` and `B`, each of size `N`, to store the finish times and cooking times, respectively. This results in a space complexity of $O(N)$. If we were allowed to modify the input arrays or process them on the fly without storing them entirely, it might be possible to reduce this, but given the standard problem structure, $O(N)$ is typical and acceptable.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as per instructions
using namespace std;

void solve() {
    int N;
    cin >> N;

    // Read the finish times A1, A2, ..., AN
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Read the cooking times needed B1, B2, ..., BN
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int count = 0; // Counter for students who can cook
    int prev_finish_time = 0; // Represents A0, the start time for the first student (time 0)

    // Iterate through each student
    for (int i = 0; i < N; ++i) {
        int current_finish_time = A[i];
        
        // Calculate the time available for the current student.
        // This is the difference between their scheduled finish time (A[i])
        // and their scheduled start time (A[i-1], or 0 for the first student).
        int available_time = current_finish_time - prev_finish_time;
        
        // Get the time needed by the current student
        int needed_time = B[i];

        // Check if the student has enough time
        if (needed_time <= available_time) {
            count++;
        }
        
        // Update prev_finish_time for the next iteration.
        // The current student's finish time becomes the next student's start time.
        prev_finish_time = current_finish_time;
    }

    // Output the total count of students who can cook
    cout << count << "\n";
}

int main() {
    // Enable fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```