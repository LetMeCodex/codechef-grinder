# [Chef loves Pizza Chef loves halfs (CHEFIZZA)](https://www.codechef.com/problems/CHEFIZZA)
- **Difficulty Rating**: 1190
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of "smaller" slices when Chef wants to cut a pizza into `X` total slices. Chef starts with one whole pizza slice. The only allowed operation is to cut an existing slice into two equal halves. The goal is to achieve exactly `X` slices. We need to output the count of slices that are smaller than the largest slices present.

For example:
- If `X=1`, no cuts are made. All 1 slice is equal. Output: 0.
- If `X=2`, the pizza is cut into 2 equal halves. All 2 slices are equal. Output: 0.
- If `X=3`, the pizza is cut into 2 halves. Then one of these halves is cut again. This results in one large slice (1/2 of the original pizza) and two smaller slices (each 1/4 of the original pizza). Output: 2.
- If `X=4`, the pizza is cut into 2, then both are cut into 4 equal slices. All 4 slices are equal. Output: 0.

## Intuition & Mathematical Observation

The key constraint is that Chef can only cut a slice into two *equal* halves. This means that any slice Chef creates will always be a fraction of the original pizza that is a power of 2 (e.g., 1/2, 1/4, 1/8, etc.).

Consider the process of cutting:
1. Start with 1 slice.
2. Cut it into 2 slices.
3. Cut both of these into 4 slices.
4. Cut all of these into 8 slices, and so on.

If `X` is a power of 2 (e.g., 1, 2, 4, 8, ...), Chef can always make `X` perfectly equal slices. In this scenario, there are no "smaller" slices, as all slices are of the same size. The answer would be 0.

If `X` is not a power of 2, Chef cannot make all slices equal. To minimize the number of cuts and maximize the size of the largest slices, Chef should first aim to create as many equal slices as possible, where each slice is as large as possible. This means Chef should cut the pizza until the number of slices is the largest power of 2 that is less than or equal to `X`.

Let `P` be the largest power of 2 such that `P <= X`.
At this point, Chef has `P` equal slices, each of size `1/P` of the original pizza.
Chef needs a total of `X` slices. Currently, Chef has `P` slices.
The number of additional slices needed is `X - P`.

To get these `X - P` additional slices, Chef must take `X - P` of the current `P` slices and cut each of them into two halves.
When a slice of size `1/P` is cut into two halves, it becomes two slices, each of size `1/(2P)`.
After performing these `X - P` cuts:
- `P - (X - P)` slices remain uncut. These slices are still of size `1/P`. These are the largest slices.
- `2 * (X - P)` slices are created from the cuts. These slices are of size `1/(2P)`. These are the smaller slices.

Since `P` is the largest power of 2 less than or equal to `X`, and `X` is not a power of 2 (otherwise `X=P` and the answer is 0), it implies `P < X < 2P`.
Therefore, `1/P > 1/(2P)`, meaning the slices of size `1/(2P)` are indeed smaller than the slices of size `1/P`.

The total number of slices will be `(P - (X - P)) + 2 * (X - P) = P - X + P + 2X - 2P = X`.
The number of slices that are smaller than the largest slices is `2 * (X - P)`.

**Example Walkthrough (`X=6`):**
1. Find the largest power of 2 less than or equal to 6. This is `P=4`.
2. Chef cuts the pizza into 4 equal slices (each 1/4 of the pizza).
3. Chef needs `X - P = 6 - 4 = 2` more slices.
4. Chef takes 2 of the 4 slices and cuts each into two halves.
   - The 2 cut slices (each 1/4) become 4 smaller slices (each 1/8).
   - The remaining `4 - 2 = 2` slices are left uncut (each 1/4).
5. Total slices: 2 (size 1/4) + 4 (size 1/8) = 6 slices.
6. The smaller slices are the 4 slices of size 1/8.
7. Using the formula: `2 * (X - P) = 2 * (6 - 4) = 2 * 2 = 4`. This matches.

The solution involves finding `P` and then calculating `2 * (X - P)`.

## Complexity Analysis

-   **Time Complexity**: $O(\log X)$ per test case.
    The `while` loop iteratively doubles `pow2` until it exceeds `X`. This process is logarithmic with respect to `X`. Specifically, it takes `log2(P)` iterations, where `P` is the largest power of 2 less than or equal to `X`. Since `P <= X`, this is at most `log2(X)` iterations. The operations inside the loop and after it are constant time. For `T` test cases, the total time complexity is $O(T \log X)$.

-   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`X`, `pow2`, `T`) regardless of the input size. Thus, the memory usage remains constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as per instructions
using namespace std;     // Uses the standard namespace as per instructions

void solve() {
    int X;
    cin >> X; // Read the number of slices Chef wants to cut

    // Find the largest power of 2 (pow2) such that pow2 <= X.
    // This represents the state where Chef has cut the pizza into pow2 equal slices,
    // and these are the largest possible equal slices that fit within X.
    int pow2 = 1;
    while ((pow2 << 1) <= X) { // (pow2 << 1) is equivalent to pow2 * 2
        pow2 <<= 1;            // Double pow2
    }

    // The number of additional cuts made beyond the 'pow2' state is (X - pow2).
    // Each additional cut takes one of the current largest slices and divides it into two smaller slices.
    // Therefore, (X - pow2) large slices have been converted into 2 * (X - pow2) smaller slices.
    // These 2 * (X - pow2) slices are the ones that are smaller than the rest.
    cout << 2 * (X - pow2) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```