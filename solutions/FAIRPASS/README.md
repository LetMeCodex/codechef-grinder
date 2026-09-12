# Passes for Fair (FAIRPASS)
- **Difficulty Rating**: 342
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to go to a fair with his $N$ friends. He has $K$ passes. Each person (including Chef) needs one pass to enter the fair. Determine if Chef can enter the fair with all his friends given the number of passes he has.

## Intuition & Mathematical Observation
The core of the problem is to determine if the total number of passes Chef possesses is sufficient for everyone who wants to enter the fair.

Chef himself needs one pass.
He also wants to bring $N$ friends, and each friend needs one pass.
Therefore, the total number of people who need passes is Chef (1) + his friends ($N$).
This sums up to $1 + N$ people.

Chef has $K$ passes.
If the number of passes Chef has ($K$) is greater than or equal to the total number of people who need passes ($1 + N$), then everyone can enter. Otherwise, they cannot.

Mathematically, the condition for everyone to enter is:
$K \ge N + 1$

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations and comparisons for each test case. The loop runs $T$ times, where $T$ is the number of test cases. For each test case, the operations are constant time. Thus, the total time complexity is $O(T)$, but for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a few integer variables to store the input values ($T, N, K$) and intermediate calculations. The amount of memory used does not grow with the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from input

    while (T--) { // Loop T times, decrementing T in each iteration
        int N, K; // Declare integer variables N and K for friends and passes
        cin >> N >> K; // Read N and K for the current test case

        // Calculate the total number of people who need passes.
        // This includes Chef himself (1 person) and his N friends.
        int people_needed = N + 1;

        // Check if Chef has enough passes (K) for all the people (people_needed).
        if (K >= people_needed) {
            // If K is greater than or equal to people_needed, Chef can enter with everyone.
            cout << "YES\n"; // Print YES followed by a newline
        } else {
            // Otherwise, Chef does not have enough passes for everyone.
            cout << "NO\n"; // Print NO followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}
```