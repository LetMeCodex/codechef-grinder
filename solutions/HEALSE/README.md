# Healthy Sleep (HEALSE)
- **Difficulty Rating**: 250
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a person's sleep duration, given in hours ($H$), is "LESS", "PERFECT", or "MORE" compared to the ideal sleep duration of 8 hours.

## Intuition & Mathematical Observation

The problem statement directly provides the criteria for classifying the sleep duration:
- If the sleep duration $H$ is less than 8 hours, it's "LESS".
- If the sleep duration $H$ is exactly 8 hours, it's "PERFECT".
- If the sleep duration $H$ is more than 8 hours, it's "MORE".

This is a straightforward conditional logic problem. We just need to compare the input value $H$ with the constant value 8 and print the corresponding string.

Mathematically, we can express this as:
- If $H < 8$, output "LESS".
- If $H = 8$, output "PERFECT".
- If $H > 8$, output "MORE".

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves a single read operation and a few constant-time comparisons. The number of operations does not depend on the input size (which is a single integer).

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable $H$ and a few other variables. The memory usage does not grow with the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H; // Variable to store the sleep duration in hours
    cin >> H; // Read the sleep duration from standard input

    // Compare the sleep duration with the ideal of 8 hours
    if (H < 8) {
        // If sleep duration is less than 8 hours
        cout << "LESS\n";
    } else if (H == 8) {
        // If sleep duration is exactly 8 hours
        cout << "PERFECT\n";
    } else { // H > 8
        // If sleep duration is more than 8 hours
        cout << "MORE\n";
    }

    return 0; // Indicate successful execution
}
```