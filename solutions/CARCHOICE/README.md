# [Car Choice (CARCHOICE)](https://www.codechef.com/problems/CARCHOICE)
- **Difficulty Rating**: 861
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the cost-effectiveness of two cars for a given distance. We are given the price of diesel per litre and the mileage (kilometers per litre) for Car 1, and similarly for petrol for Car 2. We need to determine which car is cheaper to travel a certain distance, or if they have the same cost. The output should be -1 if Car 1 is cheaper, 1 if Car 2 is cheaper, and 0 if they have the same cost.

## Intuition & Mathematical Observation
To determine which car is cheaper, we need to calculate the cost per kilometer for each car.

Let:
- $x_1$ be the mileage of Car 1 (kilometers per litre of diesel).
- $y_1$ be the price of diesel per litre.
- $x_2$ be the mileage of Car 2 (kilometers per litre of petrol).
- $y_2$ be the price of petrol per litre.

The cost per kilometer for Car 1 can be calculated as:
$$ \text{Cost per km for Car 1} = \frac{\text{Price of diesel per litre}}{\text{Mileage of Car 1}} = \frac{y_1}{x_1} $$

Similarly, the cost per kilometer for Car 2 is:
$$ \text{Cost per km for Car 2} = \frac{\text{Price of petrol per litre}}{\text{Mileage of Car 2}} = \frac{y_2}{x_2} $$

We need to compare $\frac{y_1}{x_1}$ and $\frac{y_2}{x_2}$.

A common pitfall when dealing with floating-point numbers is precision issues. While direct comparison of `double` values might work for many cases, it's generally safer to avoid division if possible, especially when comparing for equality.

We can rewrite the comparison $\frac{y_1}{x_1} < \frac{y_2}{x_2}$ by cross-multiplying. Since $x_1$ and $x_2$ represent mileage, they are always positive. Therefore, we can multiply both sides by $x_1 \cdot x_2$ without changing the direction of the inequality:
$$ y_1 \cdot x_2 < y_2 \cdot x_1 $$

Similarly:
- If $\frac{y_1}{x_1} > \frac{y_2}{x_2}$, then $y_1 \cdot x_2 > y_2 \cdot x_1$.
- If $\frac{y_1}{x_1} = \frac{y_2}{x_2}$, then $y_1 \cdot x_2 = y_2 \cdot x_1$.

The problem constraints state that $x_1, x_2, y_1, y_2$ are between 1 and 50. Multiplying two numbers up to 50 will result in a maximum value of $50 \times 50 = 2500$. This value fits comfortably within standard integer types like `int` or `long long` in C++, thus avoiding potential floating-point precision issues entirely if we choose to use integer arithmetic for comparison.

However, the provided solution uses `double` for direct calculation of cost per km. Given the small constraints and the nature of the division (simple ratios), `double` precision is usually sufficient for this problem. The direct comparison of `double` values `cost1_per_km < cost2_per_km` is also a valid approach here and is often accepted in competitive programming for such problems.

The logic is:
1. Calculate `cost1_per_km = y1 / x1`.
2. Calculate `cost2_per_km = y2 / x2`.
3. If `cost1_per_km < cost2_per_km`, Car 1 is cheaper (output -1).
4. If `cost1_per_km > cost2_per_km`, Car 2 is cheaper (output 1).
5. Otherwise (if they are equal), output 0.

The use of `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` is for optimizing I/O operations, which is a standard practice in competitive programming to speed up execution, especially when dealing with a large number of test cases.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  The code processes $T$ test cases. For each test case, it performs a constant number of arithmetic operations (division and comparison). Therefore, the time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store variables ($t, x1, x2, y1, y2$, and the calculated costs per km). This memory usage does not depend on the input size or the number of test cases. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>
#include <iomanip> // Not strictly necessary for this problem, but good for general floating point output formatting

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        double x1, x2, y1, y2; // Mileage and price for Car 1 and Car 2
        std::cin >> x1 >> x2 >> y1 >> y2;

        // Calculate the cost per kilometer for each car.
        // Car 1: Cost per km = (Price of diesel per litre) / (Kilometers per litre of diesel) = y1 / x1
        // Car 2: Cost per km = (Price of petrol per litre) / (Kilometers per litre of petrol) = y2 / x2
        double cost1_per_km = y1 / x1;
        double cost2_per_km = y2 / x2;

        // Compare the costs per kilometer to determine which car is cheaper.
        // The problem asks for specific outputs:
        // -1 if Car 1 is cheaper
        //  1 if Car 2 is cheaper
        //  0 if both have the same cost

        if (cost1_per_km < cost2_per_km) {
            // Car 1 has a lower cost per kilometer, so it's cheaper.
            std::cout << -1 << "\n";
        } else if (cost1_per_km > cost2_per_km) {
            // Car 2 has a lower cost per kilometer, so it's cheaper.
            std::cout << 1 << "\n";
        } else {
            // The costs per kilometer are equal.
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
```