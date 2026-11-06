# Find Second Largest (SECLAR)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the second largest among three distinct given numbers.

## Intuition & Mathematical Observation
Given three distinct numbers, say $a$, $b$, and $c$, we need to identify the one that is neither the largest nor the smallest.

There are a couple of intuitive ways to approach this:

1.  **Sorting:** If we sort the three numbers in ascending order, the second largest number will be the middle element. For example, if the sorted numbers are $x \le y \le z$, then $y$ is the second largest.

2.  **Summation and Extremes:** We know that the sum of three numbers is $a + b + c$. If we can find the largest and the smallest among them, say `largest` and `smallest`, then the remaining number must be the second largest. This can be expressed mathematically as:
    `second_largest = (a + b + c) - largest - smallest`.

The problem statement guarantees that the three numbers are distinct, which simplifies things as we don't need to handle cases with duplicate values.

The provided solution uses the second approach (Summation and Extremes) as it's slightly more direct for exactly three numbers without requiring a separate data structure like a vector or explicit sorting function calls.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (addition, subtraction) and comparisons (`max`, `min`) on three numbers. These operations take constant time, regardless of the magnitude of the numbers.

- **Space Complexity**: $O(1)$
    The solution uses a few variables (`a`, `b`, `c`, `largest`, `smallest`, `second_largest`) to store the input numbers and intermediate results. The amount of memory used is constant and does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies multiple test cases are not present,
    // as it doesn't specify a number of test cases 't'.
    // If there were multiple test cases, the structure would be:
    // int t;
    // cin >> t;
    // while (t--) {
    //     // ... solve one test case ...
    // }
    // Given the constraints and problem type, it's a single test case.

    long long a, b, c;
    cin >> a >> b >> c;

    // To find the second largest among three distinct numbers,
    // we can sort them and pick the middle element.
    // Since the numbers are distinct, we don't need to worry about duplicates.

    // Method 1: Using std::sort
    // vector<long long> nums = {a, b, c};
    // sort(nums.begin(), nums.end());
    // cout << nums[1] << "\n";

    // Method 2: Using conditional logic (more efficient for just 3 numbers)
    // The largest number is max(a, b, c).
    // The smallest number is min(a, b, c).
    // The sum of the three numbers is a + b + c.
    // The second largest number is (a + b + c) - max(a, b, c) - min(a, b, c).

    long long largest = max({a, b, c});
    long long smallest = min({a, b, c});
    long long second_largest = (a + b + c) - largest - smallest;

    cout << second_largest << "\n";

    return 0;
}
```