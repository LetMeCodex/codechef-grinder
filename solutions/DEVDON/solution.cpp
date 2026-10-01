#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies a single test case based on the input format
    // and lack of explicit mention of multiple test cases.
    // If there were multiple test cases, the input format would typically include
    // a number 't' indicating the count of test cases.
    // Given the constraints and problem type, a single calculation is expected.

    long long x, y;
    cin >> x >> y;

    // The total calories consumed is the number of donuts multiplied by the calories per donut.
    // Using long long to prevent potential integer overflow, although with the given constraints
    // (X <= 10, Y <= 300), the maximum product is 10 * 300 = 3000, which fits within a standard int.
    // However, it's good practice to use long long for products in competitive programming
    // to handle larger constraints if they were present or if intermediate calculations could overflow.
    long long total_calories = x * y;

    cout << total_calories << "\n";

    return 0;
}