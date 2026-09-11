# Battery Low (BATTERYLOW)
- **Difficulty Rating**: 479
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a phone's battery is "low" given its current charge level. A battery is considered low if its charge level is 15% or less. We are given the current battery charge as an integer `x` (representing percentage) and need to output "Yes" if `x <= 15` and "No" otherwise. This check needs to be performed for multiple test cases.

## Intuition & Mathematical Observation
The problem statement directly provides the condition for a "low" battery: the charge level must be less than or equal to 15%. There's no complex logic or mathematical derivation required. The core of the problem is a simple conditional check.

Given an input `x` representing the battery percentage, we just need to evaluate the boolean expression `x <= 15`.

- If `x <= 15` is true, the battery is low, and we should output "Yes".
- If `x <= 15` is false (meaning `x > 15`), the battery is not low, and we should output "No".

The problem also specifies that there will be multiple test cases, so we need to read the number of test cases `t` and then loop `t` times, performing the check for each test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
    The solution involves reading an integer and performing a single comparison. These operations take constant time. Since there are `t` test cases, the total time complexity is $O(t)$. However, when analyzing the complexity *per test case*, it's $O(1)$.

- **Space Complexity**: $O(1)$.
    The solution uses a few integer variables (`t`, `x`) to store input and loop counters. The amount of memory used does not grow with the input size, making it constant space.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x; // Variable to store the battery charge percentage
        cin >> x; // Read the battery charge percentage

        // Check if the battery charge is 15% or less
        if (x <= 15) {
            cout << "Yes\n"; // If low, print "Yes"
        } else {
            cout << "No\n"; // If not low, print "No"
        }
    }

    return 0; // Indicate successful execution
}
```