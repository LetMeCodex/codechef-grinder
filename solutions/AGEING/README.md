# [Ageing (AGEING)](https://www.codechef.com/problems/AGEING)
- **Difficulty Rating**: 299
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem states that Chef is currently 20 years old and Chefina is currently 10 years old. We are given Chef's future age, $X$, and we need to find Chefina's age at that same future time.

## Intuition & Mathematical Observation
The core of this problem lies in understanding the relationship between Chef's and Chefina's ages.

Currently:
- Chef's age = 20
- Chefina's age = 10

The difference in their ages is $20 - 10 = 10$ years. This age difference will *always* remain constant, regardless of how many years pass.

If Chef's future age is $X$, and Chef is always 10 years older than Chefina, then Chefina's age at that future time will be Chef's age minus the age difference.

Chefina's future age = Chef's future age - Age difference
Chefina's future age = $X - 10$

Therefore, for any given future age $X$ of Chef, Chefina's age will be $X - 10$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations for each test case: reading an integer, performing a subtraction, and printing an integer. These operations take constant time, regardless of the input value $X$. Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$. However, in competitive programming, when the operations per test case are constant, we often refer to the complexity per test case as $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the number of test cases, Chef's age, and Chefina's age. The amount of memory used does not depend on the input size $X$ or the number of test cases $T$. Thus, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries for convenience

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int X; // Declare an integer variable X to store Chef's age.
        cin >> X; // Read Chef's age for the current test case.

        // Chef's current age is 20, and Chefina's current age is 10.
        // This means Chef is 20 - 10 = 10 years older than Chefina.
        // Since their age difference remains constant, when Chef is X years old,
        // Chefina will be X - 10 years old.
        int chefina_age = X - 10;

        // Output Chefina's calculated age, followed by a newline character.
        // The newline character ensures each output is on a separate line as required.
        cout << chefina_age << "\n";
    }

    return 0; // Indicate successful program execution.
}
```