# [Chef and Gym (CGYM)](https://www.codechef.com/problems/CGYM)
- **Difficulty Rating**: 496
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to go to the gym. There are two costs involved: the gym membership cost ($X$) and the personal trainer cost ($Y$). Chef has a budget ($Z$). We need to determine how many of these services Chef can afford:
- If Chef can afford both the gym membership and the personal trainer, output 2.
- If Chef can afford only the gym membership (but not both), output 1.
- If Chef cannot afford even the gym membership, output 0.

## Intuition & Mathematical Observation
The problem can be solved by a series of conditional checks based on Chef's budget ($Z$) and the costs ($X$ and $Y$).

1.  **Can Chef afford both?**
    The total cost for both the gym membership and the personal trainer is $X + Y$. If this sum is less than or equal to Chef's budget $Z$, then Chef can afford both. In this case, the answer is 2.

2.  **If not both, can Chef afford only the gym?**
    If the condition in step 1 is false (i.e., $X + Y > Z$), it means Chef cannot afford both. Now, we check if Chef can afford just the gym membership. The cost for the gym membership is $X$. If $X$ is less than or equal to Chef's budget $Z$, then Chef can afford the gym. Since we already know Chef cannot afford both, this implies Chef can afford only the gym. In this case, the answer is 1.

3.  **If not even the gym, what then?**
    If both the conditions in step 1 and step 2 are false (i.e., $X + Y > Z$ and $X > Z$), it means Chef cannot afford the gym membership alone, and therefore cannot afford the personal trainer either (as the trainer is an additional cost). In this case, Chef can afford neither. The answer is 0.

These three conditions cover all possible scenarios and can be implemented using `if-else if-else` statements.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    For each test case, we perform a fixed number of comparisons and arithmetic operations. The number of operations does not depend on the input values $X, Y, Z$ or the number of test cases $T$ in a way that scales linearly. Thus, the time complexity per test case is constant. Since there are $T$ test cases, the total time complexity is $O(T)$. However, in competitive programming contexts, when analyzing a single test case, it's often considered $O(1)$.

- **Space Complexity**: $O(1)$
    We only use a few integer variables ($T, X, Y, Z$) to store the input and perform calculations. The amount of memory used is constant and does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard library headers

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // Variables for gym cost, trainer cost, and budget
        cin >> X >> Y >> Z; // Read X, Y, Z for the current test case

        // Condition 1: Can Chef afford both the gym membership and a personal trainer?
        // The total cost for both is X (gym) + Y (trainer).
        if (X + Y <= Z) {
            cout << 2 << "\n"; // If affordable, output 2
        } 
        // Condition 2: If Chef cannot afford both, can he at least afford only the gym membership?
        // This 'else if' block is reached only if X + Y > Z (meaning trainer is too expensive).
        else if (X <= Z) {
            cout << 1 << "\n"; // If only gym is affordable, output 1
        } 
        // Condition 3: If Chef cannot even afford the gym membership (X > Z).
        // This 'else' block is reached only if X > Z (meaning even the gym is too expensive).
        else {
            cout << 0 << "\n"; // If nothing is affordable, output 0
        }
    }

    return 0; // Indicate successful program execution
}
```