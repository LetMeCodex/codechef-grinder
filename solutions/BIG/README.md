# [Big Achiever (BIG)](https://www.codechef.com/problems/BIG)
- **Difficulty Rating**: 699
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine, for each student in a line, whether they are a "Big Achiever". A student is considered a Big Achiever if their achievement score is strictly greater than the achievement scores of all students who came before them in the line. We are given $N$ students, and their achievement scores $A_1, A_2, \ldots, A_N$. For each student, we need to output `1` if they are a Big Achiever, and `0` otherwise. The achievement scores are distinct integers from $1$ to $N$.

## Intuition & Mathematical Observation

The core of the problem lies in comparing each student's score with the scores of all preceding students. A naive approach might involve iterating through all previous students for each current student, which would be inefficient.

A more efficient approach leverages the fact that we only care about whether the current student's score is *strictly greater than all* previous scores. This is equivalent to checking if the current student's score is strictly greater than the *maximum* score among all previous students.

Let's maintain a variable, say `current_max`, which stores the maximum achievement score encountered among the students processed *so far*.

When we are at student $i$ (with score $A_i$):
1. We compare $A_i$ with `current_max`.
2. If $A_i > \text{current\_max}$, then student $i$ is a Big Achiever, because their score is greater than the maximum of all preceding scores. We record `1` for this student.
3. Otherwise ($A_i \le \text{current\_max}$), student $i$ is not a Big Achiever. We record `0` for this student.
4. After processing student $i$, we must update `current_max` to include $A_i$. The new `current_max` will be $\max(\text{current\_max}, A_i)$. This updated value will be used for the next student ($i+1$).

For the very first student ($i=0$), there are no students before them. Since achievement scores are distinct integers from $1$ to $N$, $A_0$ will always be at least $1$. If we initialize `current_max` to $0$, then $A_0$ will always be greater than `current_max`, correctly identifying the first student as a Big Achiever.

This approach processes each student exactly once, making it efficient.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading $N$ and the $N$ achievement scores takes $O(N)$ time.
    -   The main loop iterates $N$ times. Inside the loop, we perform a constant number of operations (one comparison, one `max` operation, one assignment). Thus, the loop takes $O(N)$ time.
    -   Printing the $N$ results takes $O(N)$ time.
    -   Overall, for a single test case, the time complexity is $O(N)$.
    -   Given $T$ test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    -   We use a `vector<int> A` to store the $N$ achievement scores, requiring $O(N)$ space.
    -   We use another `vector<int> results` to store the $N$ binary outcomes, requiring $O(N)$ space.
    -   Variables like `N`, `current_max`, `i`, etc., use $O(1)$ space.
    -   Overall, the space complexity for a single test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for convenience in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Vector to store the input achievement scores
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Vector to store the results (1 for happy, 0 for not happy)
    vector<int> results(N);
    
    // current_max stores the maximum achievement score encountered among students
    // processed so far (i.e., students before the current one).
    // Initialize to 0 because achievement scores A_i are distinct integers from 1 to N,
    // so A_i will always be >= 1.
    int current_max = 0; 

    // Iterate through each student from left to right
    for (int i = 0; i < N; ++i) {
        // A student is happy if their score A[i] is greater than
        // all students before them. This is equivalent to A[i] being
        // strictly greater than the maximum score among students before them.
        if (A[i] > current_max) {
            results[i] = 1; // Student is happy (Big Achiever)
        } else {
            results[i] = 0; // Student is not happy
        }
        
        // Update current_max to include the current student's score.
        // This updated current_max will be used for the next student.
        current_max = max(current_max, A[i]);
    }

    // Print the results for the current test case
    for (int i = 0; i < N; ++i) {
        cout << results[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```