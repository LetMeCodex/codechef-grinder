# Mario and Transformation (TRANSFORM)
- **Difficulty Rating**: 649
- **Solved in**: 1 attempt(s)

## Problem Summary
Mario starts in a "normal" state. He can consume mushrooms that transform him. The transformations follow a cycle: normal -> huge -> small -> normal. Given the number of mushrooms Mario consumes, determine his final state.

## Intuition & Mathematical Observation
The problem describes a cyclical transformation process. Let's represent the states numerically:
- Normal: 0
- Huge: 1
- Small: 2

Mario starts in the "normal" state (0).
When he consumes the first mushroom, he transforms from normal to huge.
When he consumes the second mushroom, he transforms from huge to small.
When he consumes the third mushroom, he transforms from small back to normal.

This pattern repeats every 3 mushrooms. This is a clear indication of a modulo operation.

If Mario consumes $X$ mushrooms, his final state can be determined by considering the number of transformations modulo 3.

Let the initial state be $S_0 = 0$ (normal).
After 1 mushroom, the state is $(S_0 + 1) \pmod 3 = 1$ (huge).
After 2 mushrooms, the state is $(S_0 + 2) \pmod 3 = 2$ (small).
After 3 mushrooms, the state is $(S_0 + 3) \pmod 3 = 0$ (normal).
After $X$ mushrooms, the state will be $(S_0 + X) \pmod 3$.
Since $S_0 = 0$, the final state is simply $X \pmod 3$.

We can then map the result of $X \pmod 3$ back to the states:
- If $X \pmod 3 = 0$, the final state is NORMAL.
- If $X \pmod 3 = 1$, the final state is HUGE.
- If $X \pmod 3 = 2$, the final state is SMALL.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a single modulo operation and a few conditional checks, which take constant time regardless of the input value of $X$. The loop for test cases runs $T$ times, where $T$ is the number of test cases. Thus, for each test case, the time complexity is $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store variables like `t`, `x`, and `final_state`. This memory usage does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // Mario's initial size is 'normal'.
        // The transformations cycle through: normal -> huge -> small -> normal ...
        // This is a cycle of length 3.
        // We can represent the states numerically:
        // normal: 0
        // huge: 1
        // small: 2
        //
        // Initial state: normal (0)
        // After 1 mushroom: huge (1)
        // After 2 mushrooms: small (2)
        // After 3 mushrooms: normal (0)
        // After 4 mushrooms: huge (1)
        //
        // The state after X mushrooms is (initial_state + X) mod 3.
        // Since initial_state is normal (0), the state is X mod 3.

        int final_state = x % 3;

        if (final_state == 0) {
            cout << "NORMAL\n";
        } else if (final_state == 1) {
            cout << "HUGE\n";
        } else { // final_state == 2
            cout << "SMALL\n";
        }
    }
    return 0;
}
```