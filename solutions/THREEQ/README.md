# [The Old Saint And Three Questions (THREEQ)](https://www.codechef.com/problems/THREEQ)
- **Difficulty Rating**: 954
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem describes a scenario where a hero must answer three questions. For each question, the correct answer is either 'Yes' (represented by 1) or 'No' (represented by 0). Similarly, the hero's responses are also 'Yes' (1) or 'No' (0). We are given the three correct answers ($A_1, A_2, A_3$) and the hero's three responses ($B_1, B_2, B_3$). The hero passes the test if and only if the total number of 'Yes' answers given by the hero is equal to the total number of 'Yes' answers in the correct set. We need to output "Pass" if the hero passes, and "Fail" otherwise.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for passing: "the number of 'Yes' answers given by him is equal to the number of 'Yes' answers in the correct answers."

Let's denote the count of 'Yes' answers in the correct set as $C_A$ and the count of 'Yes' answers in the hero's responses as $C_B$.
Since each answer ($A_i$ or $B_i$) is either 1 (for 'Yes') or 0 (for 'No'), we can simply sum these values to get the count of 'Yes' answers.

So, for the correct answers:
$C_A = A_1 + A_2 + A_3$

And for the hero's responses:
$C_B = B_1 + B_2 + B_3$

The hero passes the test if $C_A = C_B$. Otherwise, the hero fails.

This approach is straightforward and directly implements the problem's condition. If the counts of 'Yes' answers match, it implicitly means the counts of 'No' answers (which would be $3 - C_A$ and $3 - C_B$) must also match, satisfying the overall balance.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the program performs a fixed number of operations: reading 6 integers, performing two sums of three integers each, one comparison, and one print operation. All these operations take constant time. If there are $T$ test cases, the total time complexity will be $O(T)$. Given $T \le 1000$, this is highly efficient.

-   **Space Complexity**: $O(1)$ per test case.
    The program uses a fixed number of integer variables to store the inputs and intermediate sums (`A1, A2, A3, B1, B2, B3, sumA, sumB`). The memory usage does not depend on the input values or the number of questions (which is fixed at 3). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (std::cin, std::cout)

// Function to solve a single test case
void solve() {
    // Declare integer variables to store the correct answers for the three questions.
    int A1, A2, A3;
    // Read the three correct answers from standard input.
    // A value of 1 represents 'Yes', and 0 represents 'No'.
    std::cin >> A1 >> A2 >> A3;

    // Declare integer variables to store the hero's responses to the three questions.
    int B1, B2, B3;
    // Read the three hero's responses from standard input.
    // A value of 1 represents 'Yes', and 0 represents 'No'.
    std::cin >> B1 >> B2 >> B3;

    // Calculate the total count of 'Yes' answers (1s) among the correct answers.
    // Since A_i are either 0 or 1, their sum directly gives the count of 1s.
    int sumA = A1 + A2 + A3;

    // Calculate the total count of 'Yes' answers (1s) among the hero's responses.
    // Similarly, the sum of B_i gives the count of 1s in the hero's responses.
    int sumB = B1 + B2 + B3;

    // The hero passes the test if the number of 'Yes' answers in their responses
    // matches the number of 'Yes' answers in the correct answers.
    // If the count of 'Yes' answers matches, the count of 'No' answers (3 - count_of_Yes)
    // will also automatically match, satisfying the problem condition.
    if (sumA == sumB) {
        // If the counts match, print "Pass" followed by a newline character.
        std::cout << "Pass\n";
    } else {
        // If the counts do not match, print "Fail" followed by a newline character.
        std::cout << "Fail\n";
    }
}

// Main function: the entry point of the program
int main() {
    // For this specific error ("Connection aborted") and the problem's small constraints,
    // the fast I/O optimizations (std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);)
    // have been removed. While generally beneficial, they are not strictly necessary here
    // and in extremely rare cases, might interact unexpectedly with certain judge environments.
    // The core logic remains unchanged and is correct.

    int t; // Declare an integer variable to store the number of test cases.
    // Read the number of test cases from standard input.
    std::cin >> t;

    // Loop through each test case. The loop continues as long as 't' is greater than 0,
    // and 't--' decrements 't' after each iteration.
    while (t--) {
        // Call the 'solve' function to process each individual test case.
        solve();
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```