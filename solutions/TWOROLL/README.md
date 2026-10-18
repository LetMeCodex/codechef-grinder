# [Two Rolls (TWOROLL)](https://www.codechef.com/problems/TWOROLL)
- **Difficulty Rating**: 653
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at position $X$ on a number line and wants to reach position 50. Chef has two dice, and the first die shows the value $Y$. The second die is identical to the first, meaning it also shows values from $Y$ to $Y+5$. Chef rolls both dice and moves forward by the sum of the values shown on the two dice. We need to determine if it's possible for Chef to reach exactly position 50.

## Intuition & Mathematical Observation

Chef is currently at position $X$ and wants to reach position 50. This means Chef needs to move exactly $50 - X$ steps forward. Let $S$ be the total number of steps Chef moves in a turn. Chef wins if $S = 50 - X$.

Chef rolls two dice. The first die shows a value $Y$. The second die is identical, meaning it also shows values from $Y$ to $Y+5$.
Let $D_1$ be the value shown on the first die and $D_2$ be the value shown on the second die.
We know that $Y \le D_1 \le Y+5$ and $Y \le D_2 \le Y+5$.

The total number of steps Chef moves is $S = D_1 + D_2$.
To determine if Chef can reach position 50, we need to find the minimum and maximum possible values for $S$.

**Minimum possible sum ($S_{min}$):**
This occurs when both dice show their minimum possible value, which is $Y$.
$S_{min} = Y + Y = 2Y$.

**Maximum possible sum ($S_{max}$):**
This occurs when both dice show their maximum possible value, which is $Y+5$.
$S_{max} = (Y+5) + (Y+5) = 2Y + 10$.

Therefore, the total number of steps Chef can move in a single turn, $S$, will be in the range $[2Y, 2Y+10]$.

Chef can reach position 50 if and only if the required number of steps, $50 - X$, falls within this possible range of sums.
So, Chef can win if $2Y \le (50 - X) \le 2Y + 10$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations and a comparison. The number of operations does not depend on the input values $X$ and $Y$ or the number of test cases $T$ (beyond the loop for test cases). For each test case, the time complexity is constant.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store input values and intermediate calculations. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Adhering to the instruction

void solve() {
    int X, Y;
    cin >> X >> Y; // Read current position X and starting die value Y

    // Calculate the exact number of steps Chef needs to move to reach 50.
    int target_steps = 50 - X;

    // Calculate the minimum possible sum from rolling two dice.
    // Each die can show values from Y to Y+5.
    // The minimum value for a single die is Y.
    // So, the minimum sum for two dice is Y + Y = 2Y.
    int min_roll_sum = 2 * Y;

    // Calculate the maximum possible sum from rolling two dice.
    // The maximum value for a single die is Y+5.
    // So, the maximum sum for two dice is (Y+5) + (Y+5) = 2Y + 10.
    int max_roll_sum = 2 * Y + 10;

    // Chef can win if the required 'target_steps' falls within the
    // possible range of sums from the two dice.
    if (target_steps >= min_roll_sum && target_steps <= max_roll_sum) {
        cout << "Yes\n"; // If possible, output "Yes"
    } else {
        cout << "No\n";  // Otherwise, output "No"
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```