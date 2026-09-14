# [Id and Ship (FLOW010)](https://www.codechef.com/problems/FLOW010)

- **Difficulty Rating**: 847
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to identify the name of a ship based on a single character ID provided as input. The mapping is as follows:
- **B** or **b**: BattleShip
- **C** or **c**: Cruiser
- **D** or **d**: Destroyer
- **F** or **f**: Frigate

The program must handle $T$ test cases, reading one character per test case and outputting the corresponding full name.

## Intuition & Mathematical Observation
The problem is a straightforward mapping exercise. Since the input is a single character, we can use conditional statements (`if-else` or `switch`) to check the character against the specified IDs. 

**Key Observations:**
1. The problem statement specifies that the input can be either uppercase or lowercase (e.g., 'B' or 'b'). Therefore, our logic must account for both cases for every ship type.
2. Since there are only four categories, a simple `if-else` ladder is efficient and readable.
3. Using `ios_base::sync_with_stdio(false); cin.tie(NULL);` ensures that the I/O operations are fast enough to handle the constraints within the time limit.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ work per test case.
- **Space Complexity**: $O(1)$, as we only store a single character variable regardless of the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Id and Ship (FLOW010)
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a single character.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        char id;
        cin >> id;

        // Check the ID and print the corresponding Ship Class
        // Using if-else to handle both uppercase and lowercase inputs
        if (id == 'B' || id == 'b') {
            cout << "BattleShip" << "\n";
        } else if (id == 'C' || id == 'c') {
            cout << "Cruiser" << "\n";
        } else if (id == 'D' || id == 'd') {
            cout << "Destroyer" << "\n";
        } else if (id == 'F' || id == 'f') {
            cout << "Frigate" << "\n";
        }
    }

    return 0;
}
```