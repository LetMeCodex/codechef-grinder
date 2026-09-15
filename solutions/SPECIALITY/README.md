# [Speciality (SPECIALITY)](https://www.codechef.com/problems/SPECIALITY)
- **Difficulty Rating**: 434
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine who among a Setter, a Tester, and an Editorialist is the "specialist" based on three given scores, $x$, $y$, and $z$. The Setter's score is $x$, the Tester's score is $y$, and the Editorialist's score is $z$. The specialist is the one who has the highest score among the three.

## Intuition & Mathematical Observation
The problem is a straightforward comparison of three numbers. We are given three integer scores, $x$, $y$, and $z$, representing the scores of the Setter, Tester, and Editorialist, respectively. We need to find which of these three scores is the maximum.

The logic is as follows:
1. If $x$ is greater than both $y$ and $z$, then the Setter is the specialist.
2. If $y$ is greater than both $x$ and $z$, then the Tester is the specialist.
3. If neither of the above conditions is met, it implies that $z$ must be the highest score (or tied for the highest). In this case, the Editorialist is the specialist.

This can be implemented using a series of `if-else if-else` statements.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of comparisons and input/output operations for each test case. The number of operations does not depend on the magnitude of the input numbers or the number of test cases (beyond the loop for test cases). Therefore, the time complexity per test case is constant.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store the input variables ($t$, $x$, $y$, $z$) and a few other variables for control flow. This memory usage is constant and does not grow with the input size.

## Solution Code
```cpp
#include <iostream>
#include <algorithm> // Although not strictly necessary for this solution, it's good practice to include for potential future use or if using std::max

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, y, z; // Scores for Setter, Tester, and Editorialist
        std::cin >> x >> y >> z;

        // Check if Setter has the highest score
        if (x > y && x > z) {
            std::cout << "Setter\n";
        }
        // Check if Tester has the highest score
        else if (y > x && y > z) {
            std::cout << "Tester\n";
        }
        // If neither Setter nor Tester has the highest score, Editorialist must have it
        else {
            std::cout << "Editorialist\n";
        }
    }
    return 0;
}
```