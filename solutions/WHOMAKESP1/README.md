# [Who Makes P1 (WHOMAKESP1)](https://www.codechef.com/problems/WHOMAKESP1)
- **Difficulty Rating**: 363
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a scenario involving two characters, Tyro and Dom, related to making a problem. Tyro has a patience level denoted by `A`, and Dom will attempt to make the problem for `B` attempts.

The rules for determining who makes the problem are:
1. If Tyro's patience level (`A`) is less than or equal to Dom's maximum attempts (`B`), Tyro will be convinced and makes the problem.
2. Otherwise (if Tyro's patience level `A` is strictly greater than Dom's maximum attempts `B`), Dom gives up before Tyro is convinced, and thus Dom makes the problem.

The task is to read pairs of `A` and `B` and output "Tyro" or "Dom" based on these rules. The input format implies multiple test cases, which should be read until the End Of File (EOF).

## Intuition & Mathematical Observation

The problem boils down to a straightforward comparison between two integer values, `A` and `B`.

- **Tyro's Patience (`A`)**: Represents how long Tyro is willing to wait or how many attempts Tyro can endure from Dom.
- **Dom's Attempts (`B`)**: Represents the maximum number of attempts Dom will make.

We need to determine whose "limit" is reached first.

1.  **If `A <= B`**: This means Tyro's patience (`A`) is sufficient to cover all of Dom's `B` attempts. Tyro will wait until Dom has tried everything. Since Tyro is still patient, Tyro makes the problem.
2.  **If `A > B`**: This means Dom's attempts (`B`) run out before Tyro's patience (`A`) does. Dom gives up, and since Tyro is still waiting, Dom makes the problem.

Therefore, the core logic is a simple conditional statement:
- If `A <= B`, output "Tyro".
- Else (if `A > B`), output "Dom".

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution involves reading two integers (`A` and `B`) and performing a single comparison and a print operation for each test case. Each of these operations takes constant time, $O(1)$. The `while (cin >> A >> B)` loop continues as long as there is input, effectively processing $N$ test cases. Therefore, the total time complexity is $N \times O(1) = O(N)$, where $N$ is the number of test cases (pairs of `A` and `B` in the input).

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory regardless of the input size. It only declares a few integer variables (`A`, `B`) to store the current input values. No data structures that grow with the input size are used. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Only iostream is needed for input/output

// Use the standard namespace to avoid std:: prefix
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B; // Declare two integer variables for Tyro's patience and Dom's attempts

    // Read A and B repeatedly until there is no more input (End Of File - EOF).
    // This handles multiple test cases where the number of test cases 'T' is not explicitly given.
    while (cin >> A >> B) {
        // Compare A and B to determine who makes the problem
        // If Tyro's patience level (A) is less than or equal to Dom's maximum attempts (B),
        // Tyro will be convinced and makes the problem.
        if (A <= B) {
            cout << "Tyro\n"; // Output "Tyro" followed by a newline
        } else {
            // Otherwise (if A > B), Dom gives up before Tyro is convinced,
            // so Dom makes the problem.
            cout << "Dom\n"; // Output "Dom" followed by a newline
        }
    }

    return 0; // Indicate successful execution
}
```