# [Chef and Card Game (CRDGAME)](https://www.codechef.com/problems/CRDGAME)

- **Difficulty Rating**: 1125
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Morty are playing a card game. In each round, both players pick a card with a number on it. The "power" of a card is defined as the sum of its digits. 
- If Chef's power is greater than Morty's, Chef wins the round.
- If Morty's power is greater than Chef's, Morty wins the round.
- If the powers are equal, both players get a point.

Given $N$ rounds, we need to determine the winner (the player with more points) and their total score. If there is a tie in total points, we output `2` and the score.

## Intuition & Mathematical Observation
1. **Digit Summation**: The core of the problem is calculating the sum of digits for any given integer. Since the constraints on the card numbers are manageable, we can convert the integer to a string or use the modulo operator (`% 10`) and integer division (`/ 10`) to extract and sum the digits.
2. **Round Logic**: We maintain two counters, `chef_points` and `morty_points`. For each round:
   - Calculate `sum_digits(A)` and `sum_digits(B)`.
   - Compare the two values and increment the respective counters based on the rules provided.
3. **Final Comparison**: After $N$ rounds, compare the total points:
   - If `chef_points > morty_points`, output `0` and `chef_points`.
   - If `morty_points > chef_points`, output `1` and `morty_points`.
   - If `chef_points == morty_points`, output `2` and `chef_points`.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times D)$, where $T$ is the number of test cases, $N$ is the number of rounds, and $D$ is the number of digits in the card numbers. Since $D$ is small (logarithmic relative to the value of the card), this is highly efficient.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

// Function to calculate the sum of digits of a number
int sum_digits(int n) {
    int sum = 0;
    std::string s = std::to_string(n);
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int chef_points = 0;
        int morty_points = 0;
        
        for (int i = 0; i < n; ++i) {
            int a, b;
            std::cin >> a >> b;
            int chef_power = sum_digits(a);
            int morty_power = sum_digits(b);
            
            if (chef_power > morty_power) {
                chef_points++;
            } else if (morty_power > chef_power) {
                morty_points++;
            } else {
                chef_points++;
                morty_points++;
            }
        }

        // Determine the winner based on total points
        if (chef_points > morty_points) {
            std::cout << "0 " << chef_points << "\n";
        } else if (morty_points > chef_points) {
            std::cout << "1 " << morty_points << "\n";
        } else {
            std::cout << "2 " << chef_points << "\n";
        }
    }
    return 0;
}
```