# Rectangle (RECTANGL)
- **Difficulty Rating**: 1146
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if four given side lengths can form a rectangle. We are given four integers representing the lengths of the sides.

## Intuition & Mathematical Observation
A rectangle is a quadrilateral with four right angles. A key property of a rectangle is that its opposite sides are equal in length. This means that a rectangle will always have two pairs of equal sides. For example, a rectangle with sides $l$ and $w$ will have two sides of length $l$ and two sides of length $w$.

If the four given side lengths are $a, b, c, d$, for them to form a rectangle, they must satisfy the condition that there are exactly two distinct lengths, and each length appears exactly twice.

A simple way to check this condition is to sort the four given side lengths. Let the sorted lengths be $s_1, s_2, s_3, s_4$ in non-decreasing order. For these to form a rectangle, the smallest two sides must be equal ($s_1 = s_2$), and the largest two sides must be equal ($s_3 = s_4$). This condition also correctly handles the case of a square, where all four sides are equal ($s_1 = s_2 = s_3 = s_4$).

For example:
- If the sides are 2, 3, 2, 3: Sorted sides are 2, 2, 3, 3. Here, $s_1=s_2=2$ and $s_3=s_4=3$. This forms a rectangle.
- If the sides are 5, 5, 5, 5: Sorted sides are 5, 5, 5, 5. Here, $s_1=s_2=5$ and $s_3=s_4=5$. This forms a square (which is a special type of rectangle).
- If the sides are 1, 2, 3, 4: Sorted sides are 1, 2, 3, 4. Here, $s_1 \neq s_2$ and $s_3 \neq s_4$. This does not form a rectangle.
- If the sides are 2, 2, 2, 3: Sorted sides are 2, 2, 2, 3. Here, $s_1=s_2=2$, but $s_3 \neq s_4$. This does not form a rectangle.

Therefore, the strategy is to read the four side lengths, store them, sort them, and then check if the first two are equal and the last two are equal.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    - For each test case, we read four integers, store them in a vector of size 4, and sort this vector. Sorting a fixed-size array (size 4) takes constant time. The comparisons afterwards also take constant time. The number of test cases is $T$. So, the total time complexity is $O(T \times (\text{constant sorting} + \text{constant comparisons}))$, which simplifies to $O(T)$. If we consider the complexity per test case, it is $O(1)$ because the input size is fixed at 4.

- **Space Complexity**: $O(1)$
    - For each test case, we use a vector of size 4 to store the side lengths. This is a constant amount of extra space, regardless of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream, vector, algorithm

using namespace std; // Allows using standard library components without the std:: prefix

void solve() {
    int a, b, c, d;
    // Read the four side lengths for the current test case
    cin >> a >> b >> c >> d;

    // Store the four side lengths in a vector for easy sorting
    vector<int> sides = {a, b, c, d};

    // Sort the side lengths in non-decreasing order.
    // For a rectangle, there must be two pairs of equal sides.
    // If we sort the four side lengths (s1, s2, s3, s4),
    // they must satisfy s1 = s2 and s3 = s4.
    // This condition covers all cases, including squares (where s1=s2=s3=s4).
    sort(sides.begin(), sides.end());

    // Check if the sorted sides form a rectangle
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES\n"; // If the condition is met, it's a rectangle
    } else {
        cout << "NO\n";  // Otherwise, it's not
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false); // Disables synchronization with C's stdio library
    cin.tie(NULL); // Unties cin from cout, meaning cin will not flush cout before reading input

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}
```