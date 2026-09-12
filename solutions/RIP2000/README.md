# [2000 (RIP2000)](https://www.codechef.com/problems/RIP2000)
- **Difficulty Rating**: 284
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of legs for a given number of animals. Each animal is stated to have exactly 4 legs. We are given an integer $N$, representing the number of animals, and we need to output the total number of legs.

## Intuition & Mathematical Observation

The core of the problem is a simple multiplication. If each animal has 4 legs, and we have $N$ animals, then the total number of legs will be the number of animals multiplied by the number of legs per animal.

Mathematically, this can be expressed as:

Total Legs = Number of Animals $\times$ Legs per Animal

Given that the number of animals is $N$ and each animal has 4 legs, the formula becomes:

Total Legs = $N \times 4$

This is a straightforward linear relationship.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves a single multiplication operation and a single input/output operation. These operations take constant time, regardless of the input value of $N$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable $N$ and the result variable. This memory usage does not grow with the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Declare an integer variable 'n' to store the number of animals.
    int n;
    
    // Read the input value for 'n' from standard input.
    std::cin >> n;
    
    // Calculate the total number of legs by multiplying 'n' by 4.
    // Each animal has 4 legs.
    int result = n * 4;
    
    // Print the calculated 'result' to standard output, followed by a newline.
    std::cout << result << std::endl;
    
    // Return 0 to indicate successful execution of the program.
    return 0;
}
```