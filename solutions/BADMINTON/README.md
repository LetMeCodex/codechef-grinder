# [Badminton Serves (BADMINTON)](https://www.codechef.com/problems/BADMINTON)
- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is playing a game of badminton and has already scored $P$ points. The rules for serving are:
1. If the server's score is even, they serve from the right side of the court.
2. If the server's score is odd, they serve from the left side of the court.

We are told that Chef always serves first. The task is to determine how many times Chef has served from the right side of the court so far. The information about winning conditions (21 points, deuce at 20-20) is flavor text and not relevant to the question.

## Intuition & Mathematical Observation

The problem states that Chef always serves first. This is a crucial detail. It implies that Chef is the server for every point scored *up to* his current score $P$.
Therefore, Chef serves when his score is 0, then when his score is 1, then 2, and so on, up to his current score $P$.

According to the rules, Chef serves from the right side if his score *at the moment of serving* is even. So, we need to count how many even numbers are there in the sequence of scores Chef had when he served: $0, 1, 2, \dots, P$.

Let's trace this for a few values of $P$:
- If $P=0$: Chef served when his score was 0. (0 is even). Count = 1.
- If $P=1$: Chef served when his score was 0 (even), then 1 (odd). Count = 1.
- If $P=2$: Chef served when his score was 0 (even), then 1 (odd), then 2 (even). Count = 2.
- If $P=3$: Chef served when his score was 0 (even), then 1 (odd), then 2 (even), then 3 (odd). Count = 2.
- If $P=4$: Chef served when his score was 0 (even), then 1 (odd), then 2 (even), then 3 (odd), then 4 (even). Count = 3.

Observing the pattern:
- For $P=0, 1$, the count is 1.
- For $P=2, 3$, the count is 2.
- For $P=4, 5$, the count is 3.

This pattern suggests a simple mathematical formula: `P / 2 + 1` using integer division.

Let's verify this formula:
- If $P$ is even, say $P=2k$: The even scores in $[0, 2k]$ are $0, 2, \dots, 2k$. There are $k+1$ such scores. The formula gives $(2k)/2 + 1 = k + 1$. This matches.
- If $P$ is odd, say $P=2k+1$: The even scores in $[0, 2k+1]$ are $0, 2, \dots, 2k$. There are $k+1$ such scores. The formula gives $(2k+1)/2 + 1 = k + 1$ (due to integer division, $(2k+1)/2$ evaluates to $k$). This also matches.

Thus, the number of times Chef served from the right side is simply `P / 2 + 1`.

## Complexity Analysis

-   **Time Complexity**: For each test case, we perform a single integer division and addition, which are constant time operations. Given $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: We only use a few integer variables to store the number of test cases ($T$), Chef's score ($P$), and the calculated result. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers
using namespace std;     // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int P;
        cin >> P; // Read the points obtained by Chef

        // The number of times Chef serves from the right side is determined
        // by the number of even scores Chef has when he is about to serve.
        // Chef serves when his score is 0, 1, 2, ..., up to P.
        // He serves from the right side if his score at that moment is even.
        // So, we count the even numbers in the range [0, P].
        //
        // For any integer P, the count of even numbers in [0, P] is P/2 + 1
        // using integer division.
        // Example:
        // P=0: Even numbers are {0}. Count = 1. (0/2 + 1 = 1)
        // P=1: Even numbers are {0}. Count = 1. (1/2 + 1 = 1)
        // P=2: Even numbers are {0, 2}. Count = 2. (2/2 + 1 = 2)
        // P=3: Even numbers are {0, 2}. Count = 2. (3/2 + 1 = 2)
        // P=4: Even numbers are {0, 2, 4}. Count = 3. (4/2 + 1 = 3)
        int right_serves = P / 2 + 1;

        cout << right_serves << "\n"; // Output the result followed by a newline
    }

    return 0; // Indicate successful execution
}
```