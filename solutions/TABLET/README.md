# [Buying New Tablet (TABLET)](https://www.codechef.com/problems/TABLET)
- **Difficulty Rating**: 1037
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the largest area of a tablet that can be purchased given a budget `b`. We are given `n` tablets, and for each tablet, we know its width `w`, height `h`, and price `p`. We can only afford a tablet if its price `p` is less than or equal to our budget `b`.

## Intuition & Mathematical Observation
The core of the problem is to iterate through all available tablets and identify those that are within our budget. For each tablet that we can afford, we need to calculate its area (width * height). Our goal is to find the maximum area among all affordable tablets.

If no tablets are affordable (i.e., all tablets are more expensive than our budget), we should report that no tablet can be bought.

The mathematical observation is straightforward:
1. **Affordability Check**: For each tablet `i`, check if `p_i <= b`.
2. **Area Calculation**: If affordable, calculate the area `A_i = w_i * h_i`.
3. **Maximum Area Tracking**: Keep track of the maximum area found so far among all affordable tablets. Initialize this maximum area to a value that indicates no tablet has been found yet (e.g., -1).

If after checking all tablets, the maximum area is still the initial "not found" value, then no tablet can be purchased. Otherwise, the tracked maximum area is the answer.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution iterates through each of the `N` tablets exactly once. For each tablet, it performs a constant number of operations (reading input, comparison, multiplication, and `std::max`). Therefore, the total time complexity is directly proportional to the number of tablets, `N`.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of extra space regardless of the input size. It only stores a few variables to keep track of the number of test cases `t`, the budget `b`, the number of tablets `n`, and the current tablet's dimensions and price (`w`, `h`, `p`), as well as the `max_area`. This space requirement does not grow with `N`.

## Solution Code
```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of tablets
        long long b; // Budget
        std::cin >> n >> b;

        long long max_area = -1; // Initialize max_area to -1 to indicate no tablet found yet.

        for (int i = 0; i < n; ++i) {
            long long w, h, p; // width, height, price of the current tablet
            std::cin >> w >> h >> p;

            // Check if the current tablet is affordable within the budget.
            if (p <= b) {
                // If affordable, calculate its area and update max_area if this tablet's area is larger.
                max_area = std::max(max_area, w * h);
            }
        }

        // After checking all tablets, if max_area is still -1, it means no tablet was affordable.
        if (max_area == -1) {
            std::cout << "no tablet\n";
        } else {
            // Otherwise, print the largest area found among affordable tablets.
            std::cout << max_area << "\n";
        }
    }
    return 0;
}
```