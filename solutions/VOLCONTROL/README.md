# [Volume Control (VOLCONTROL)](https://www.codechef.com/problems/VOLCONTROL)
- **Difficulty Rating**: 409
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of button presses required to change the volume of a device from an initial volume $X$ to a final volume $Y$. The device has two buttons: one to increase the volume by 1, and another to decrease the volume by 1.

## Intuition & Mathematical Observation
The core of this problem lies in understanding how to reach the target volume $Y$ from the starting volume $X$ using the minimum number of operations. Each operation (increasing or decreasing volume by 1) changes the volume by exactly 1 unit.

If the initial volume $X$ is less than the target volume $Y$, we need to increase the volume. The most efficient way to do this is to press the "increase volume" button repeatedly until we reach $Y$. The number of presses required will be the difference between $Y$ and $X$, i.e., $Y - X$.

If the initial volume $X$ is greater than the target volume $Y$, we need to decrease the volume. The most efficient way to do this is to press the "decrease volume" button repeatedly until we reach $Y$. The number of presses required will be the difference between $X$ and $Y$, i.e., $X - Y$.

Notice that in both cases, the number of presses is the absolute difference between $X$ and $Y$. The absolute difference, denoted as $|X - Y|$, elegantly captures both scenarios:
- If $X < Y$, $|X - Y| = Y - X$.
- If $X > Y$, $|X - Y| = X - Y$.

Therefore, the minimum number of button presses is simply the absolute difference between the initial volume $X$ and the final volume $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves reading two integers and performing a single subtraction and an absolute value calculation. These operations take constant time, regardless of the magnitude of the input numbers (within the limits of integer types). The loop runs $T$ times, where $T$ is the number of test cases. For each test case, the time complexity is $O(1)$. Thus, the total time complexity for $T$ test cases is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables ($T$, $X$, $Y$, `presses`) to store input and intermediate results. The amount of memory used does not grow with the input size. Therefore, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for the std::abs function to calculate absolute difference

// Using the standard namespace to avoid repeatedly writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for initial and final volume.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the minimum number of button presses.
        // This is simply the absolute difference between the initial and final volume.
        // std::abs() function returns the absolute value of its argument.
        int presses = abs(X - Y);

        // Output the calculated number of presses, followed by a newline character.
        // The newline ensures that each test case's output is on a separate line.
        cout << presses << "\n";
    }

    return 0; // Indicate successful program execution.
}
```