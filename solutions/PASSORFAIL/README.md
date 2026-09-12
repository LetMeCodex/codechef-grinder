# Pass or Fail (PASSORFAIL)
- **Difficulty Rating**: 730
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a student, Chef, passes or fails a test based on their performance. The test has $N$ questions. Chef answers $X$ questions correctly. Each correct answer earns 3 marks, and each incorrect answer deducts 1 mark. To pass the test, Chef's total score must be greater than or equal to a passing mark $P$.

## Intuition & Mathematical Observation
The core of the problem lies in calculating Chef's total score and comparing it with the passing mark $P$.

1.  **Score from Correct Answers**: Chef answers $X$ questions correctly. Each correct answer is worth 3 marks. So, the total marks obtained from correct answers are $X \times 3$.

2.  **Score from Incorrect Answers**: The total number of questions is $N$. If Chef answers $X$ questions correctly, then the number of incorrect answers is $N - X$. Each incorrect answer deducts 1 mark. So, the total marks deducted for incorrect answers are $(N - X) \times 1$.

3.  **Total Score**: Chef's total score is the sum of marks from correct answers minus the marks deducted for incorrect answers.
    Total Score = (Marks from Correct Answers) - (Marks from Incorrect Answers)
    Total Score = $(X \times 3) - ((N - X) \times 1)$
    Total Score = $3X - (N - X)$
    Total Score = $3X - N + X$
    Total Score = $4X - N$

4.  **Pass/Fail Condition**: Chef passes if their Total Score is greater than or equal to the passing mark $P$.
    If $(4X - N) \ge P$, Chef passes.
    Otherwise, Chef fails.

The problem involves multiple test cases, so we need to read the number of test cases $T$ and then iterate through each test case, performing the calculation and printing "PASS" or "FAIL" accordingly.

## Complexity Analysis
-   **Time Complexity**: $O(T)$
    The code reads the number of test cases $T$. For each test case, it performs a constant number of arithmetic operations and comparisons. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The code uses a fixed number of integer variables ($T, N, X, P$, and `chef_score`) regardless of the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream> // Required for cin and cout

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of testcases
    std::cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int N, X, P; // Declare variables for total questions, correct answers, and passing marks
        std::cin >> N >> X >> P; // Read N, X, P for the current testcase

        // Calculate Chef's total score
        // Score from correct answers: X * 3
        // Score from incorrect answers: (N - X) * (-1)
        // Total Score = (X * 3) + ((N - X) * -1)
        // Simplified: Total Score = 3X - N + X = 4X - N
        int chef_score = (X * 3) - ((N - X) * 1); 
        // Alternatively, using the simplified formula: int chef_score = (4 * X) - N;

        // Check if Chef's score is greater than or equal to the passing marks P
        if (chef_score >= P) {
            std::cout << "PASS\n"; // If score is sufficient, print PASS
        } else {
            std::cout << "FAIL\n"; // Otherwise, print FAIL
        }
    }

    return 0; // Indicate successful execution
}
```