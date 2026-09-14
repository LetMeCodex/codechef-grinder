# Water Filling (WATERFILLING)
- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if it's "Water filling time" based on the state of three bottles. Each bottle can be either empty (represented by 0) or full (represented by 1). The condition for "Water filling time" is that at least two of the three bottles must be empty.

## Intuition & Mathematical Observation
The core of the problem lies in checking the condition: "at least two bottles are empty". We are given the states of three bottles, $B_1, B_2, B_3$, where each can be either 0 (empty) or 1 (full).

To check if at least two bottles are empty, we can simply count the number of bottles that have a state of 0. If this count is greater than or equal to 2, then it's "Water filling time".

Alternatively, we can observe the sum of the states of the bottles.
- If all three bottles are empty (0, 0, 0), the sum is 0.
- If two bottles are empty and one is full (0, 0, 1 or permutations), the sum is 1.
- If one bottle is empty and two are full (0, 1, 1 or permutations), the sum is 2.
- If all three bottles are full (1, 1, 1), the sum is 3.

The condition "at least two bottles are empty" corresponds to the cases where the sum of the bottle states is 0 or 1. Therefore, an equivalent condition is that the sum of $B_1, B_2, B_3$ is less than or equal to 1.

The provided solution uses the direct counting method, which is clear and easy to implement.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  The program iterates through $T$ test cases. For each test case, it reads three integers and performs a constant number of comparisons and additions to count the empty bottles. This takes constant time per test case. Therefore, the total time complexity is proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of integer variables ($t, b_1, b_2, b_3$, `empty_count`) regardless of the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers B1, B2, B3 representing the state of three bottles.
 * 0 = empty, 1 = full.
 * Condition for "Water filling time": At least two bottles are empty.
 * This means the count of zeros must be >= 2.
 * Equivalently, the sum of B1, B2, and B3 must be <= 1 (since 0+0+1 = 1, 0+0+0 = 0).
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; // Read the number of test cases
    
    while (t--) { // Loop through each test case
        int b1, b2, b3;
        cin >> b1 >> b2 >> b3; // Read the state of the three bottles
        
        // Count how many bottles are empty (value is 0)
        int empty_count = 0;
        if (b1 == 0) empty_count++;
        if (b2 == 0) empty_count++;
        if (b3 == 0) empty_count++;
        
        // If at least two are empty, it's water filling time
        if (empty_count >= 2) {
            cout << "Water filling time" << "\n";
        } else {
            cout << "Not now" << "\n";
        }
    }
    
    return 0;
}
```