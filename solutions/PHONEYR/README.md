# [Yearly Phone (PHONEYR)](https://www.codechef.com/problems/PHONEYR)
- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the model name of a phone based on a given year `X`. The phone model is named 'K' followed by the last two digits of the year `X`. For example, if the year is 2005, the phone model is "K05". If the year is 2000, the phone model is "K00".

## Intuition & Mathematical Observation
The core of the problem lies in extracting the last two digits of the given year `X`. In the decimal number system, the last two digits of any integer can be obtained by taking the number modulo 100.

For any integer `X`, `X % 100` will give us the remainder when `X` is divided by 100. This remainder will always be an integer between 0 and 99, inclusive.

For instance:
- If `X = 2005`, then `2005 % 100 = 5`.
- If `X = 1998`, then `1998 % 100 = 98`.
- If `X = 2000`, then `2000 % 100 = 0`.

The problem also specifies that the output should preserve leading zeros. This means if the last two digits are, for example, 5, we should output "05", not just "5". Similarly, if the last two digits are 0, we should output "00".

Most programming languages provide mechanisms to format output, including padding with leading zeros. In C++, the `std::setw` manipulator from the `<iomanip>` header can be used to set the width of the output field, and `std::setfill` can be used to specify the character used for padding.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a single arithmetic operation (modulo) and a constant number of output operations. These operations take a fixed amount of time, regardless of the input value `X` (within the integer limits).

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable `x` and the calculated `last_two_digits`. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
#include <iomanip> // Required for std::setw and std::setfill

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Disables synchronization with C's stdio and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    // The problem statement implies a single test case.
    // If multiple test cases were intended, the input would typically start
    // with an integer 't' indicating the number of test cases, and the loop
    // would be structured around reading 't'. Given the problem's simplicity
    // and typical CodeChef format for such problems, processing a single 'x'
    // is the expected approach.

    // To get the last two digits of the year X, we use the modulo operator.
    // X % 100 will give a result in the range [0, 99].
    int last_two_digits = x % 100;

    // The phone model is 'K' followed by the last two digits.
    // We need to ensure that the two digits are printed with leading zeros
    // if they are less than 10. For example, 5 should be printed as "05".
    // std::setw(2) sets the output field width to 2 characters.
    // std::setfill('0') specifies that '0' should be used for padding.
    cout << "K";
    cout << setw(2) << setfill('0') << last_two_digits << "\n";

    return 0;
}
```