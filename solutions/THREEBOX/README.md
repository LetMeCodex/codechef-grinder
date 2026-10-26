# [Three Boxes (THREEBOX)](https://www.codechef.com/problems/THREEBOX)
- **Difficulty Rating**: 1183
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the sizes of three boxes, $A$, $B$, and $C$, and the capacity of a bag, $D$. We need to find the minimum number of bags required to store all three boxes. We can place multiple boxes into a single bag as long as their total size does not exceed the bag's capacity $D$.

## Intuition & Mathematical Observation
The problem asks for the minimum number of bags. This suggests we should try to pack as many boxes as possible into a single bag.

Let the sizes of the three boxes be $A$, $B$, and $C$, and the bag capacity be $D$. We are given that $A \le B \le C$.

We can consider the following scenarios to minimize the number of bags:

1.  **Can all three boxes fit into one bag?**
    If the sum of the sizes of all three boxes ($A + B + C$) is less than or equal to the bag capacity ($D$), then we can fit all of them into a single bag. This is the most optimal scenario, requiring only 1 bag.
    Condition: $A + B + C \le D$

2.  **If not all three, can two boxes fit into one bag?**
    If the first condition is not met (i.e., $A + B + C > D$), we cannot fit all three boxes into one bag. The next best option is to try and fit two boxes into one bag and the remaining box into another. Since we want to minimize bags, we should try to combine the smallest boxes first. Given $A \le B \le C$, the smallest sum of two boxes is $A + B$.
    If $A + B \le D$, we can place boxes $A$ and $B$ into one bag. Box $C$ will then require its own bag. Since it's guaranteed that $C \le D$ (as $A, B, C$ are box sizes and $D$ is a bag capacity, and we are not told otherwise, it's implied individual boxes can fit), box $C$ will fit into the second bag. This scenario requires 2 bags.
    Condition: $A + B \le D$ (and $A + B + C > D$)

3.  **If neither of the above, each box needs its own bag.**
    If both of the above conditions are false, it means:
    *   $A + B + C > D$ (cannot fit all three in one bag)
    *   $A + B > D$ (cannot even fit the two smallest boxes together in one bag)
    In this case, no two boxes can be combined into a single bag. Therefore, each of the three boxes must be placed in its own separate bag. This scenario requires 3 bags.

The problem statement implies that individual boxes can always fit into a bag, i.e., $A \le D$, $B \le D$, and $C \le D$. This is crucial for the logic in case 2, where box $C$ is placed alone.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    For each test case, we perform a fixed number of comparisons and arithmetic operations. The number of operations does not depend on the input values $A, B, C, D$ in terms of scaling.
-   **Space Complexity**: $O(1)$
    We only use a few variables to store the input values and perform calculations. The memory usage is constant and does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B, C, D; // Variables to store box sizes A, B, C and bag size D
        cin >> A >> B >> C >> D; // Read the four integers for the current test case

        // Logic to determine the minimum number of bags:

        // 1. Check if all three boxes can fit into a single bag.
        // This is possible if the sum of their sizes (A + B + C) does not exceed the bag size D.
        if (A + B + C <= D) {
            cout << 1 << "\n"; // If they fit, only 1 bag is needed.
        }
        // 2. If all three boxes cannot fit into one bag (i.e., A + B + C > D),
        // check if two boxes can fit into one bag, with the third box in another bag.
        // Since A <= B <= C, the smallest sum of two boxes is A + B.
        // If A + B fits into a bag, we can use 2 bags: one for (A+B) and one for (C).
        // (Box C will always fit alone because C <= D is given).
        else if (A + B <= D) {
            cout << 2 << "\n"; // If A and B fit together, 2 bags are needed.
        }
        // 3. If neither of the above conditions is met, it means:
        //    - A + B + C > D (cannot fit all three in one bag)
        //    - A + B > D (cannot fit even the two smallest boxes together in one bag)
        // In this scenario, no two boxes can be combined into a single bag.
        // Therefore, each box must go into its own separate bag.
        else {
            cout << 3 << "\n"; // Each box needs its own bag, so 3 bags are needed.
        }
    }

    return 0; // Indicate successful execution
}
```