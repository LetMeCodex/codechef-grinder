# [Elections in Chefland (ELECTIONS)](https://www.codechef.com/problems/ELECTIONS)
- **Difficulty Rating**: 1034
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the winner of an election in Chefland. There are three candidates: A, B, and C. We are given the percentage of votes each candidate received, denoted as `xa`, `xb`, and `xc` respectively. A candidate wins the election if they receive strictly more than 50% of the total votes. If no candidate manages to secure strictly more than 50% of the votes, then the outcome is "NOTA" (None Of The Above). We need to process multiple test cases.

## Intuition & Mathematical Observation
The core of this problem lies in a straightforward conditional check based on the given percentages.
According to the problem statement:
1. If candidate A gets strictly more than 50% votes (`xa > 50`), then A wins.
2. Else, if candidate B gets strictly more than 50% votes (`xb > 50`), then B wins.
3. Else, if candidate C gets strictly more than 50% votes (`xc > 50`), then C wins.
4. Else (if none of the above conditions are met), "NOTA" wins.

It's a fundamental property of percentages that if `xa`, `xb`, and `xc` represent valid percentages summing to 100%, then at most one candidate can receive strictly more than 50% of the votes. For example, if A gets 51%, then B and C combined can only get 49%, meaning neither B nor C can individually get more than 50%. This simplifies our logic, as we don't need to worry about multiple winners. The `if-else if-else` structure perfectly captures this logic, checking for a winner in a specific order and defaulting to "NOTA" if no winner is found.

## Complexity Analysis
- **Time Complexity**: $O(T)$
    - The program processes `T` test cases.
    - For each test case, it reads three integers (`xa`, `xb`, `xc`) and performs a series of constant-time comparisons (`>`, `else if`) and a single print operation.
    - Reading integers and printing a short string are considered $O(1)$ operations.
    - Therefore, the operations within each test case take constant time, $O(1)$.
    - The total time complexity is $O(T \times 1) = O(T)$, where $T$ is the number of test cases.

- **Space Complexity**: $O(1)$
    - The program uses a fixed number of integer variables (`t`, `xa`, `xb`, `xc`) regardless of the input values or the number of test cases.
    - These variables occupy a constant amount of memory.
    - Thus, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further optimizing I/O when mixing cin and cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare variable for the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        int xa, xb, xc; // Declare variables for vote percentages of candidates A, B, and C.
        std::cin >> xa >> xb >> xc; // Read the vote percentages for the current test case.

        // Check if candidate A wins (gets strictly more than 50% votes).
        if (xa > 50) {
            std::cout << "A\n"; // If A wins, print "A".
        } 
        // Else, if A didn't win, check if candidate B wins.
        else if (xb > 50) {
            std::cout << "B\n"; // If B wins, print "B".
        } 
        // Else, if neither A nor B won, check if candidate C wins.
        else if (xc > 50) {
            std::cout << "C\n"; // If C wins, print "C".
        } 
        // Else, if none of the candidates A, B, or C got strictly more than 50% votes,
        // then "NOTA" wins.
        else {
            std::cout << "NOTA\n"; // Print "NOTA".
        }
    }

    return 0; // Indicate successful program execution.
}

```