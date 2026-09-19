# [Sasta Shark Tank (SST)](https://www.codechef.com/problems/SST)
- **Difficulty Rating**: 592
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine which of two investors offers a better deal for a startup.
The first investor offers $A$ dollars for 10% of the company.
The second investor offers $B$ dollars for 20% of the company.
We need to output "FIRST" if the first investor's offer is better, "SECOND" if the second investor's offer is better, and "ANY" if both offers are equally good.

## Intuition & Mathematical Observation

To compare the two offers, we need to determine the total valuation of the company implied by each offer. The valuation represents the total worth of the company.

**Investor 1:**
If the first investor offers $A$ dollars for 10% of the company, this means that 10% of the company's total valuation is equal to $A$.
Let $V_1$ be the total valuation of the company according to the first investor.
We can write this as:
$0.10 \times V_1 = A$

To find the total valuation $V_1$, we can rearrange the equation:
$V_1 = \frac{A}{0.10}$
$V_1 = A \times 10$

So, the total valuation implied by the first investor's offer is $A \times 10$.

**Investor 2:**
Similarly, if the second investor offers $B$ dollars for 20% of the company, this means that 20% of the company's total valuation is equal to $B$.
Let $V_2$ be the total valuation of the company according to the second investor.
We can write this as:
$0.20 \times V_2 = B$

To find the total valuation $V_2$, we can rearrange the equation:
$V_2 = \frac{B}{0.20}$
$V_2 = B \times 5$

So, the total valuation implied by the second investor's offer is $B \times 5$.

**Comparison:**
Now we can compare the two valuations:
- If $V_1 > V_2$, the first investor's offer implies a higher total company valuation, meaning they are getting a smaller percentage of a more valuable company for their money. This is a better deal for the startup.
- If $V_2 > V_1$, the second investor's offer implies a higher total company valuation, meaning they are getting a smaller percentage of a more valuable company for their money. This is a better deal for the startup.
- If $V_1 = V_2$, both offers imply the same total company valuation, and thus are equally good for the startup.

Substituting the derived formulas for $V_1$ and $V_2$:
- If $A \times 10 > B \times 5$, output "FIRST".
- If $B \times 5 > A \times 10$, output "SECOND".
- If $A \times 10 = B \times 5$, output "ANY".

The problem involves a small number of test cases and simple arithmetic operations, making this a straightforward comparison. The use of `long long` for $A$ and $B$ is appropriate to handle potential large input values, and their products ($A \times 10$ and $B \times 5$) will also fit within `long long`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  For each test case, we perform a fixed number of arithmetic operations (multiplication and comparison). Since the number of test cases is $T$, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it is constant.

- **Space Complexity**: $O(1)$
  We only use a few variables to store the input values and the calculated valuations. The memory usage does not depend on the input size, making it constant.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        long long a, b; // Variables to store the offers from the two investors.
        std::cin >> a >> b; // Read the offers.

        // Calculate the total valuation of the company by the first investor.
        // If the first investor offers A dollars for 10% of the company,
        // then the total valuation is A / 0.10 = A * 10.
        long long valuation1 = a * 10;

        // Calculate the total valuation of the company by the second investor.
        // If the second investor offers B dollars for 20% of the company,
        // then the total valuation is B / 0.20 = B * 5.
        long long valuation2 = b * 5;

        // Compare the valuations to determine the better offer.
        if (valuation1 > valuation2) {
            // If the first investor's implied valuation is higher, it's a better deal for the startup.
            std::cout << "FIRST\n";
        } else if (valuation2 > valuation1) {
            // If the second investor's implied valuation is higher, it's a better deal for the startup.
            std::cout << "SECOND\n";
        } else {
            // If both implied valuations are equal, the offers are equally good.
            std::cout << "ANY\n";
        }
    }
    return 0; // Indicate successful execution.
}
```