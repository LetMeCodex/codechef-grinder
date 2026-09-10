# Find maximum in an Array (UWCOI20A)
- **Difficulty Rating**: 650
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum height among a given number of mountains. We are given the number of mountains, $N$, followed by $N$ integers representing the heights of these mountains. We need to output the maximum height found.

## Intuition & Mathematical Observation
The core task is to find the largest value in a sequence of numbers. This is a fundamental problem in computer science. The most straightforward approach is to iterate through all the given numbers and keep track of the largest one encountered so far.

We can initialize a variable, say `max_height`, to a very small value or to the first element of the array. Then, for each subsequent element, we compare it with `max_height`. If the current element is greater than `max_height`, we update `max_height` to the current element's value. After iterating through all elements, `max_height` will hold the maximum value in the array.

Since the problem statement implies that mountain heights are non-negative (ranging from 0 to $10^9$), initializing `max_height` to 0 is a safe and efficient choice. Any valid mountain height will be greater than or equal to 0, so the first mountain's height will correctly update `max_height` if it's positive.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution iterates through the $N$ mountain heights exactly once to find the maximum. For each mountain, we perform a constant number of operations (reading the height and comparing it with the current maximum). Therefore, the total time complexity is directly proportional to the number of mountains, $N$.

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space. We only need a few variables to store the number of mountains ($N$), the current mountain's height, and the maximum height found so far (`max_height`). The space required does not grow with the input size $N$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, algorithm, etc.

// Required using namespace std;
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of mountains

    // Initialize max_height. Since mountain heights are non-negative (0 to 10^9),
    // initializing with 0 is safe. Any valid height will be >= 0.
    // If heights could be negative, it would be safer to initialize with
    // numeric_limits<int>::min() or the first element.
    int max_height = 0; 

    // Loop N times to read each mountain's height
    for (int i = 0; i < N; ++i) {
        int height;
        cin >> height; // Read the current mountain's height

        // Update max_height if the current mountain is taller
        if (height > max_height) {
            max_height = height;
        }
        // Alternatively, using std::max from <algorithm> (included by <bits/stdc++.h>):
        // max_height = max(max_height, height);
    }

    // Output the height of the tallest mountain for this test case
    cout << max_height << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```