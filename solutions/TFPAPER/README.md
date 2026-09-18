# [True and False Paper (TFPAPER)](https://www.codechef.com/problems/TFPAPER)
- **Difficulty Rating**: 398
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $N$ questions and scores $K$ marks, meaning she answered $K$ questions correctly and $N-K$ questions incorrectly. Bob marks the opposite of Alice for every question. If Alice answered a question correctly, Bob answered it incorrectly, and vice-versa. We need to determine Bob's score.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the relationship between Alice's and Bob's answers.
Let:
- $N$ be the total number of questions.
- $K$ be the number of questions Alice answered correctly.
- $N-K$ be the number of questions Alice answered incorrectly.

Bob's marking strategy is the inverse of Alice's:
- If Alice answered a question correctly, Bob marked it incorrectly.
- If Alice answered a question incorrectly, Bob marked it correctly.

This means that the number of questions Bob answered correctly is precisely the number of questions Alice answered incorrectly.

Therefore, Bob's score is equal to the number of questions Alice answered incorrectly.
Bob's score = $N - K$.

The constraints ($T \le 2000$, $N \le 100$, $0 \le K \le N$) are small, and the calculation $N-K$ will easily fit within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
  For each test case, we perform a single subtraction operation ($N-K$) and an input/output operation. Since the number of operations is constant and does not depend on the input size $N$, the time complexity per test case is $O(1)$. With $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$ per test case.
  We only use a few variables to store the input values ($N$, $K$) and the result. The amount of memory used is constant and does not grow with the input size. Thus, the space complexity per test case is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has N questions.
 * Alice scored K marks, meaning she answered K questions correctly and (N - K) questions incorrectly.
 * Bob marked the opposite of Alice for every question.
 * 
 * If Alice answered a question correctly, Bob answered it incorrectly.
 * If Alice answered a question incorrectly, Bob answered it correctly.
 * 
 * Therefore, the number of questions Bob answered correctly is equal to the number of 
 * questions Alice answered incorrectly.
 * 
 * Bob's score = N - K.
 * 
 * Constraints:
 * T <= 2000, N <= 100, 0 <= K <= N.
 * The logic N - K fits within standard integer types.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    if (!(cin >> t)) return 0; // Read the number of test cases, exit if read fails
    
    while (t--) { // Loop through each test case
        long long n, k; // N: total questions, K: Alice's correct answers
        cin >> n >> k; // Read N and K for the current test case
        
        // Bob's score is the number of questions Alice got wrong.
        // If Alice got K correct out of N, she got N-K wrong.
        // Bob gets credit for every question Alice got wrong.
        long long bobs_score = n - k;
        
        cout << bobs_score << "\n"; // Output Bob's score followed by a newline
    }
    
    return 0; // Indicate successful execution
}
```