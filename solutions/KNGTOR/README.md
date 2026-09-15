# [Tour of King (KNGTOR)](https://www.codechef.com/problems/KNGTOR)

- **Difficulty Rating**: 283
- **Solved in**: 2 attempt(s)

## Problem Summary
The King wants to take his subjects on a tour. He has $N$ cars that can each hold 5 people and $M$ cars that can each hold 7 people. The goal is to calculate the total number of people that can be accommodated in all the cars combined.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since each of the $N$ cars holds 5 people, they contribute $N \times 5$ to the total capacity. Similarly, each of the $M$ cars holds 7 people, contributing $M \times 7$ to the total.

The total number of people is simply the sum of these two products:
$$\text{Total People} = (N \times 5) + (M \times 7)$$

Given the constraints, the result will fit within a standard integer type, though using `long long` is a safe practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize standard I/O operations for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        
        // Calculate total capacity: 5 people per N-car and 7 per M-car
        long long total_people = n * 5 + m * 7;
        
        std::cout << total_people << "\n";
    }
    return 0;
}
```