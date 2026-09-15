# [TV Discount (TVDISC)](https://www.codechef.com/problems/TVDISC)
- **Difficulty Rating**: 447
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the final prices of two televisions after applying their respective discounts. We are given the marked price and discount amount for each TV. We need to determine which TV is cheaper or if they have the same final price.

## Intuition & Mathematical Observation
The core of the problem is to calculate the final price of each TV and then compare them.

For the first TV:
- Marked Price: $A$
- Discount: $C$
- Final Price: $A - C$

For the second TV:
- Marked Price: $B$
- Discount: $D$
- Final Price: $B - D$

After calculating `final_price_A = A - C` and `final_price_B = B - D`, we need to perform a simple comparison:
1. If `final_price_A < final_price_B`, the first TV is cheaper.
2. If `final_price_B < final_price_A`, the second TV is cheaper.
3. If `final_price_A == final_price_B`, both TVs have the same price.

The problem statement guarantees that the marked prices are always greater than or equal to their respective discounts, ensuring that the final prices will be non-negative.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations and comparisons for each test case. The number of operations does not depend on the input values $A, B, C, D$ or the number of test cases $T$ in a way that scales linearly. For each test case, we perform a constant number of reads, subtractions, and comparisons. Therefore, the time complexity per test case is constant. Since there are $T$ test cases, the total time complexity is $O(T)$. However, if we consider the complexity *per test case*, it is $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of integer variables ($T, A, B, C, D$, `final_price_A`, `final_price_B`) regardless of the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, C, D; // Declare integer variables for prices and discounts.
        // Read the marked price of the first TV (A), second TV (B),
        // discount for the first TV (C), and discount for the second TV (D).
        std::cin >> A >> B >> C >> D;

        // Calculate the final price of the first TV after discount.
        int final_price_A = A - C;
        // Calculate the final price of the second TV after discount.
        int final_price_B = B - D;

        // Compare the final prices to determine which TV is cheaper.
        if (final_price_A < final_price_B) {
            // If the first TV is cheaper, print "First".
            std::cout << "First\n";
        } else if (final_price_B < final_price_A) {
            // If the second TV is cheaper, print "Second".
            std::cout << "Second\n";
        } else {
            // If both TVs cost the same, print "Any".
            std::cout << "Any\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```