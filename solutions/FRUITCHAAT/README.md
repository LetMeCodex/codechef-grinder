# Chef and His Fruit Stand (FRUITCHAAT)

- **Difficulty Rating**: 822
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to make fruit chaats. Each fruit chaat requires 2 bananas and 1 apple. Given the number of bananas ($X$) and apples ($Y$) Chef has, determine the maximum number of fruit chaats he can prepare.

## Intuition & Mathematical Observation

The problem states that each fruit chaat requires a fixed set of ingredients: 2 bananas and 1 apple. This means that the number of chaats Chef can make is constrained by the availability of *both* ingredients.

Let's consider the constraints imposed by each fruit individually:

1.  **Bananas:** Chef has $X$ bananas. Since each chaat requires 2 bananas, the maximum number of chaats he can make based *solely* on the number of bananas is $X / 2$. We use integer division here because any leftover banana (if $X$ is odd) cannot be used to form a complete chaat. For example, if Chef has 7 bananas, he can make $7 / 2 = 3$ chaats, using 6 bananas and having 1 banana remaining.

2.  **Apples:** Chef has $Y$ apples. Since each chaat requires 1 apple, the maximum number of chaats he can make based *solely* on the number of apples is $Y / 1 = Y$.

To successfully make a fruit chaat, Chef needs *both* 2 bananas and 1 apple. Therefore, the total number of chaats he can make is limited by the ingredient that runs out first. This is equivalent to finding the minimum of the maximum number of chaats possible from each ingredient.

Mathematically, the maximum number of chaats is:
$$ \text{max\_chaats} = \min(\lfloor X / 2 \rfloor, Y) $$
where $\lfloor X / 2 \rfloor$ represents the integer division of $X$ by 2.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (division, minimum) and input/output operations per test case. The number of test cases is read once, and then for each test case, the calculation is constant time. Thus, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the input values and the result. The memory usage does not grow with the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up I/O operations significantly in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of testcases.
    cin >> T; // Read the number of testcases.

    // Loop T times, once for each testcase.
    while (T--) {
        int X, Y; // Declare integer variables X for bananas and Y for apples.
        cin >> X >> Y; // Read the number of bananas and apples for the current testcase.

        // Calculate the maximum number of chaats Chef can make.
        // Each fruit chaat requires 2 bananas and 1 apple.
        //
        // The number of chaats is limited by two factors:
        // 1. The available bananas: With X bananas, Chef can make at most X / 2 chaats.
        //    (Integer division X / 2 correctly handles cases where X is odd,
        //    e.g., 7 bananas can make 3 chaats, using 6 bananas).
        // 2. The available apples: With Y apples, Chef can make at most Y chaats.
        //
        // To make a chaat, both conditions must be met. Therefore, the total number
        // of chaats Chef can make is limited by the minimum of these two quantities.
        int max_chaats = min(X / 2, Y);

        // Output the result for the current testcase, followed by a newline.
        cout << max_chaats << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```