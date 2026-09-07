# [Small factorials (FCTRL2)](https://www.codechef.com/problems/FCTRL2)

- **Difficulty Rating**: 648
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the factorial of a given integer $n$, where $1 \le n \le 100$. Since $100!$ is a very large number (far exceeding the capacity of standard 64-bit integers like `long long`), we must implement a method to handle "Big Integer" arithmetic.

## Intuition & Mathematical Observation
1. **Big Integer Representation**: Since we cannot store $100!$ in a primitive data type, we store the number as a list (or `vector`) of digits. Each element in the vector represents a single digit of the result.
2. **Multiplication Logic**: To calculate $n!$, we start with $1$ and iteratively multiply by $2, 3, \dots, n$.
3. **Handling Carries**: During multiplication, we multiply each stored digit by the current number $x$ and add the carry from the previous digit's multiplication. We store the result modulo 10 in the current position and carry over the rest to the next positions.
4. **Dynamic Growth**: If the carry remains after iterating through all existing digits, we continue to append the remaining carry digits to the end of our vector.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times D)$, where $T$ is the number of test cases, $N$ is the input number, and $D$ is the number of digits in $N!$. Since $100!$ has 158 digits, this approach is highly efficient for the given constraints.
- **Space Complexity**: $O(D)$, where $D$ is the number of digits required to store the factorial (approximately 158 for $100!$).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Use the standard namespace as requested by the problem statement.
using namespace std;

// Function to calculate and print factorial of n
void factorial(int n) {
    // A vector to store the digits of the factorial.
    // res[0] will store the least significant digit, res[1] the next, and so on.
    vector<int> res;
    res.push_back(1); // Initialize result with 1 (representing 1!)

    // Multiply res by numbers from 2 to n
    // This loop calculates (x-1)! * x to get x!
    for (int x = 2; x <= n; x++) {
        int carry = 0; // Initialize carry for the current multiplication

        // Iterate through the digits of the current result (which holds (x-1)!)
        // and multiply each digit by x, adding the carry from the previous digit.
        for (size_t i = 0; i < res.size(); i++) {
            // Calculate product of digit and x, plus carry.
            long long prod = (long long)res[i] * x + carry; 
            
            res[i] = prod % 10; // Store the last digit of prod in the current position
            carry = prod / 10;  // Update carry for the next digit
        }

        // After multiplying all existing digits, if there's still a carry,
        // append its digits to the end of the result vector.
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print the result. Since digits are stored from least significant to most significant,
    // we need to print them in reverse order to get the correct number.
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << "\n"; // Newline after each factorial
}

int main() {
    // Fast I/O setup to speed up input and output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) { // Loop through each test case
        int n; // Input integer for which factorial is to be calculated
        cin >> n;
        factorial(n); // Call the factorial function
    }

    return 0;
}
```