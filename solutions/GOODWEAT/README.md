# [Good Weather (GOODWEAT)](https://www.codechef.com/problems/GOODWEAT)
- **Difficulty Rating**: 835
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a week has more sunny days than rainy days. We are given the weather for 7 consecutive days, where `1` represents a sunny day and `0` represents a rainy day. We need to output "YES" if there are more sunny days than rainy days, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is straightforward. We need to count the number of sunny days and the number of rainy days over a period of 7 days.

Let $S$ be the count of sunny days and $R$ be the count of rainy days.
The total number of days is fixed at 7. So, $S + R = 7$.

We are given that a sunny day is represented by `1` and a rainy day by `0`.
We can iterate through the 7 given inputs. For each input:
- If the input is `1`, we increment the `sunny_days` counter.
- If the input is `0`, we increment the `rainy_days` counter.

After processing all 7 days, we compare `sunny_days` and `rainy_days`.
- If `sunny_days > rainy_days`, the condition is met, and we output "YES".
- Otherwise (if `sunny_days <= rainy_days`), the condition is not met, and we output "NO".

Alternatively, since $S + R = 7$, the condition $S > R$ is equivalent to $S > 7 - S$, which simplifies to $2S > 7$, or $S > 3.5$. Since $S$ must be an integer, this means $S \ge 4$. So, we only need to count the sunny days and check if the count is 4 or more.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The code iterates through a fixed number of days (7) for each test case. The operations inside the loop (incrementing counters, comparison) take constant time. Therefore, the time complexity per test case is constant. If there are $T$ test cases, the total time complexity is $O(T)$. However, since the problem statement implies a single test case or a fixed number of days per test case, we usually consider the complexity per test case, which is $O(1)$.

- **Space Complexity**: $O(1)$
The code uses a few integer variables (`t`, `sunny_days`, `rainy_days`, `day_type`) to store counts and loop indices. The amount of memory used does not depend on the input size (which is fixed at 7 days per test case). Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int sunny_days = 0;
        int rainy_days = 0;

        // Loop through the 7 days of the week
        for (int i = 0; i < 7; ++i) {
            int day_type; // 1 for sunny, 0 for rainy
            std::cin >> day_type;
            if (day_type == 1) {
                sunny_days++;
            } else {
                rainy_days++;
            }
        }

        // Check if the number of sunny days is greater than rainy days
        if (sunny_days > rainy_days) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```