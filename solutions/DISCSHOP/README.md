# Discount in a Shop (DISCSHOP)
- **Difficulty Rating**: 1300
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a positive integer $N$, we need to find the smallest possible positive integer that can be obtained by removing exactly one digit from $N$. The resulting number should not have leading zeros, unless the number itself is 0 (which is not possible here since $N$ is positive and we remove one digit).

## Intuition & Mathematical Observation
The problem asks us to find the minimum number after removing one digit. This means we need to consider all possible numbers formed by removing each digit of $N$ one by one and then find the minimum among them.

Let $N$ be represented as a string of digits $d_k d_{k-1} \dots d_1 d_0$. If we remove the digit $d_i$, the resulting number will be formed by concatenating the digits $d_k \dots d_{i+1} d_{i-1} \dots d_0$.

The key observation is that to minimize the resulting number, we should try to remove a digit that has a larger value and is at a more significant position (further to the left). For example, if we have $N = 523$, removing '5' gives $23$, removing '2' gives $53$, and removing '3' gives $52$. The minimum is $23$.

However, we must also consider the impact of leading zeros. If removing a digit results in a leading zero, that number might be smaller than expected if we naively convert it. For instance, if $N = 105$, removing '1' gives $05$, which is $5$. Removing '0' gives $15$. Removing '5' gives $10$. The minimum is $5$. The `stoll` function in C++ correctly handles this by ignoring leading zeros.

The most straightforward approach is to iterate through each digit of the number $N$. For each digit, we construct a new string by excluding that digit. Then, we convert this new string to a number and keep track of the minimum number found so far.

## Complexity Analysis
- **Time Complexity**: $O(L^2)$, where $L$ is the number of digits in $N$.
    - The outer loop iterates $L$ times (once for each digit to remove).
    - Inside the loop, constructing the new string takes $O(L)$ time.
    - Converting the string to a `long long` using `stoll` can take up to $O(L)$ time in the worst case.
    - Therefore, the total time complexity is $O(L \times (L + L)) = O(L^2)$.
    - Since $N$ can be up to $10^{18}$, $L$ is at most 19. $19^2$ is a small constant, so this is very efficient.

- **Space Complexity**: $O(L)$, where $L$ is the number of digits in $N$.
    - We use a temporary string `temp` to store the number after removing a digit. The maximum length of this string is $L$.
    - This space is reused in each iteration.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        long long n; // The input number
        cin >> n;
        string s = to_string(n); // Convert the number to a string for easy digit manipulation
        long long min_price = -1; // Initialize min_price to -1 to indicate it hasn't been set yet

        // Iterate through each digit of the number
        for (int i = 0; i < s.length(); ++i) {
            string temp = ""; // Temporary string to build the number after removing a digit
            // Construct the new string by excluding the digit at index 'i'
            for (int j = 0; j < s.length(); ++j) {
                if (i == j) continue; // Skip the digit at the current index 'i'
                temp += s[j]; // Append the digit to the temporary string
            }

            // Convert the resulting string to a long long.
            // The problem statement allows leading zeros in the intermediate
            // representation, but the final output should not have leading zeros.
            // `stoll` handles this correctly by ignoring leading zeros.
            // For example, if temp is "05", stoll("05") will correctly return 5.
            long long current_price = stoll(temp);

            // Update min_price if this is the first price calculated or if the current price is smaller
            if (min_price == -1 || current_price < min_price) {
                min_price = current_price;
            }
        }
        // Output the minimum price found for the current test case
        cout << min_price << "\n";
    }
    return 0;
}
```