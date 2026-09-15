# [Chef and Masks (CMASKS)](https://www.codechef.com/problems/CMASKS)
- **Difficulty Rating**: 432
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef needs to buy masks for 100 days and has two options:
1.  **Disposable masks**: Cost $X$ rupees per mask, each usable for 1 day.
2.  **Cloth masks**: Cost $Y$ rupees per mask, each usable for 10 days.

Chef wants to minimize his total expenditure over 100 days. If both options result in the same total cost, he prefers cloth masks (due to their eco-friendly nature). The task is to determine which type of mask Chef should buy.

## Intuition & Mathematical Observation

The problem asks us to compare the total cost of using disposable masks versus cloth masks for a period of 100 days. We need to calculate the total expenditure for each option and then choose the cheaper one, with a tie-breaking rule favoring cloth masks.

1.  **Calculate cost for Disposable Masks:**
    *   Each disposable mask lasts 1 day.
    *   To cover 100 days, Chef needs $100 / 1 = 100$ disposable masks.
    *   If each disposable mask costs $X$ rupees, the total cost for disposable masks will be $100 \times X$.

2.  **Calculate cost for Cloth Masks:**
    *   Each cloth mask lasts 10 days.
    *   To cover 100 days, Chef needs $100 / 10 = 10$ cloth masks.
    *   If each cloth mask costs $Y$ rupees, the total cost for cloth masks will be $10 \times Y$.

3.  **Compare and Decide:**
    *   Let `cost_disposable = 100 * X`
    *   Let `cost_cloth = 10 * Y`
    *   Chef chooses the option with the minimum cost.
    *   If `cost_cloth <= cost_disposable`, Chef chooses "CLOTH" (because cloth masks are cheaper or equal in cost, and he prefers cloth in case of a tie).
    *   Otherwise (`cost_cloth > cost_disposable`), Chef chooses "DISPOSABLE".

This approach involves simple arithmetic calculations and a conditional comparison for each test case.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: two multiplications, one division (implicitly in the problem logic), one comparison, and one print operation. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the number of test cases ($T$), the costs ($X$, $Y$), and the calculated total costs (`cost_disposable`, `cost_cloth`). The amount of memory used does not depend on the input values or the number of test cases (beyond storing $T$ itself), making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std; 

int main() {
    // Enable fast I/O operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X, Y;
        cin >> X >> Y; // Read the cost of disposable (X) and cloth (Y) masks

        // Calculate the total cost for disposable masks for 100 days.
        // Each disposable mask lasts 1 day, so 100 masks are needed.
        int cost_disposable = 100 * X;

        // Calculate the total cost for cloth masks for 100 days.
        // Each cloth mask lasts 10 days, so 100 / 10 = 10 masks are needed.
        int cost_cloth = 10 * Y;

        // Apply Chef's decision logic:
        // Chef chooses the masks which cost him the least.
        // In case of a tie, Chef chooses cloth masks (eco-friendly).
        // This means Chef chooses CLOTH if its cost is less than or equal to DISPOSABLE's cost.
        if (cost_cloth <= cost_disposable) {
            cout << "CLOTH\n"; // Print "CLOTH" if cloth masks are cheaper or equal in cost
        } else {
            cout << "DISPOSABLE\n"; // Otherwise, print "DISPOSABLE"
        }
    }

    return 0; // Indicate successful execution
}
```