# [Plant (TEMPPLANT)](https://www.codechef.com/problems/TEMPPLANT)
- **Difficulty Rating**: 675
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum possible height a plant can grow. We are provided with `N` daily temperatures, `A_1, A_2, ..., A_N`.
The rules for plant growth are:
1.  A plant is planted on a specific day, say day `i`.
2.  It grows on day `i` and the subsequent day, `i+1`.
3.  The final height the plant reaches is the minimum of the temperatures on day `i` and day `i+1`.
Our task is to choose the optimal day to plant the tree such that its final height is maximized.

## Intuition & Mathematical Observation
Let's represent the given temperatures using 0-based indexing, as is common in programming: `A[0], A[1], ..., A[N-1]`.

According to the problem statement, if a plant is planted on day `i` (0-indexed), its height will be `min(A[i], A[i+1])`. Our goal is to find the largest possible height among all valid planting days.

Let's consider the range of possible days to plant:
*   **Earliest day**: If we plant on day `0`, the plant uses temperatures `A[0]` and `A[1]`. The height would be `min(A[0], A[1])`.
*   **Subsequent days**: If we plant on day `1`, it uses `A[1]` and `A[2]`. The height would be `min(A[1], A[2])`. This pattern continues.
*   **Latest day**: What is the last possible day to plant? If we plant on day `N-1`, we would need the temperature for day `N` (i.e., `A[N]`), which is not provided in the input array. Therefore, the last valid day to plant is day `N-2`. If planted on day `N-2`, the plant uses temperatures `A[N-2]` and `A[N-1]`, both of which are available.

This leads to a straightforward approach:
1.  Initialize a variable, `max_height`, to `0`. Since all temperatures `A_i` are guaranteed to be at least `1`, any valid plant height will be at least `1`, making `0` a safe initial minimum.
2.  Iterate through all possible planting days `i` from `0` up to `N-2`.
3.  For each day `i`, calculate the height the plant would achieve if planted on that day: `current_height = min(A[i], A[i+1])`.
4.  Compare `current_height` with `max_height`. If `current_height` is greater, update `max_height` to `current_height`.
5.  After the loop completes, `max_height` will store the maximum possible height a plant can achieve.

This approach systematically checks every valid planting option and correctly identifies the maximum height according to the problem's rules.

## Complexity Analysis
-   **Time Complexity**: $O(N)$
    -   Reading the integer `N` takes $O(1)$ time.
    -   Reading the `N` temperatures into a vector takes $O(N)$ time.
    -   The core logic involves a single `for` loop that iterates `N-1` times (from `i = 0` to `N-2`). Inside the loop, operations like `min()` and assignment are constant time, $O(1)$.
    -   Therefore, for each test case, the total time complexity is dominated by input reading and the linear scan, resulting in $O(N)$.
    -   Given `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    -   We use a `std::vector<int> A` to store the `N` temperatures, which requires $O(N)$ space.
    -   A few additional integer variables (`N`, `max_height`, `current_height`, `i`, `T`) use $O(1)$ space.
    -   Thus, the total space complexity for each test case is $O(N)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of days

    // Create a vector to store the temperatures
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read each temperature
    }

    // Initialize max_height to 0. Since all temperatures A_i >= 1,
    // any valid tree height will be at least 1, so 0 is a safe initial minimum.
    int max_height = 0;

    // Iterate through all possible planting days.
    // If planted on day i (0-indexed), it grows on day i and day i+1.
    // The first day to plant is 0 (using A[0] and A[1]).
    // The last possible day to plant is N-2 (using A[N-2] and A[N-1]).
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the height if planted on day i
        int current_height = min(A[i], A[i+1]);
        
        // Update max_height if the current height is greater
        if (current_height > max_height) {
            max_height = current_height;
        }
        // Alternatively, using std::max: max_height = max(max_height, current_height);
    }

    // Output the maximum possible height for the current test case
    cout << max_height << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```