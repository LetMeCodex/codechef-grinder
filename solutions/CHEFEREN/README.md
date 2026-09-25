# [Chef Eren (CHEFEREN)](https://www.codechef.com/problems/CHEFEREN)

- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $n$ episodes of a series to watch. 
- Even-numbered episodes (2, 4, 6, ...) have a duration of $a$ minutes.
- Odd-numbered episodes (1, 3, 5, ...) have a duration of $b$ minutes.

The goal is to calculate the total duration required to watch all $n$ episodes.

## Intuition & Mathematical Observation
To solve this efficiently without iterating through every episode, we can use simple arithmetic:
1. **Counting Episodes**:
   - The number of **even** episodes in the range $[1, n]$ is given by $n / 2$ (integer division).
   - The number of **odd** episodes in the range $[1, n]$ is given by $(n + 1) / 2$.
2. **Calculation**:
   - Total duration = (Number of even episodes $\times a$) + (Number of odd episodes $\times b$).
3. **Data Types**: Since $n, a,$ and $b$ can be large, we use `long long` to prevent potential integer overflow during multiplication.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        long long n, a, b;
        std::cin >> n >> a >> b;

        // Calculate counts of odd and even episodes
        long long odd_episodes = (n + 1) / 2;
        long long even_episodes = n / 2;

        // Calculate total duration
        long long total_duration = (odd_episodes * b) + (even_episodes * a);
        
        std::cout << total_duration << "\n";
    }
    return 0;
}
```