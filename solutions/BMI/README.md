# [Body Mass Index (BMI)](https://www.codechef.com/problems/BMI)
- **Difficulty Rating**: 845
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the Body Mass Index (BMI) for a given weight ($m$ in kilograms) and height ($h$ in meters). Based on the calculated BMI, we need to categorize the individual into one of four categories:
- Category 1: BMI $\le$ 18
- Category 2: 19 $\le$ BMI $\le$ 24
- Category 3: 25 $\le$ BMI $\le$ 29
- Category 4: BMI $\ge$ 30

The input consists of a number of test cases, followed by pairs of weight and height for each test case.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the formula for BMI and how to apply the given categorization rules.

The standard formula for BMI is:
$$ \text{BMI} = \frac{\text{weight (kg)}}{\text{height (m)}^2} $$

The problem statement provides weight in kilograms ($m$) and height in meters ($h$). Therefore, we can directly apply this formula.

The categorization rules are given as ranges:
- If BMI $\le$ 18, output 1.
- If 19 $\le$ BMI $\le$ 24, output 2.
- If 25 $\le$ BMI $\le$ 29, output 3.
- If BMI $\ge$ 30, output 4.

It's important to note that the problem statement uses integer division for calculating BMI. This means that any fractional part of the result will be truncated. For example, if the calculated BMI is 24.9, integer division will result in 24. This is crucial for correctly applying the boundary conditions of the categories.

The provided solution code directly implements these observations:
1. It reads the number of test cases ($t$).
2. It iterates through each test case.
3. For each test case, it reads the weight ($m$) and height ($h$).
4. It calculates BMI using integer division: `int bmi = m / (h * h);`.
5. It then uses a series of `if-else if-else` statements to check which category the calculated `bmi` falls into and prints the corresponding category number.

The use of `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` is a standard optimization in competitive programming for faster input/output operations, which is good practice.

## Complexity Analysis

- **Time Complexity**: $O(T)$
  The program iterates through $T$ test cases. Inside the loop, the operations (reading input, calculating BMI, and performing comparisons) take constant time, $O(1)$. Therefore, the total time complexity is proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  The program uses a fixed amount of memory to store variables like `t`, `m`, `h`, and `bmi`, regardless of the input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;

    // Loop through each test case
    while (t--) {
        int m; // Weight in kilograms
        int h; // Height in meters
        std::cin >> m >> h;

        // Calculate BMI using integer division as per problem constraints
        // BMI = weight (kg) / (height (m))^2
        int bmi = m / (h * h);

        // Categorize BMI based on the given ranges
        if (bmi <= 18) {
            std::cout << 1 << "\n"; // Underweight
        } else if (bmi >= 19 && bmi <= 24) {
            std::cout << 2 << "\n"; // Normal weight
        } else if (bmi >= 25 && bmi <= 29) {
            std::cout << 3 << "\n"; // Overweight
        } else { // bmi >= 30
            std::cout << 4 << "\n"; // Obesity
        }
    }

    return 0;
}
```