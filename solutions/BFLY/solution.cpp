#include <iostream>   // Required for input/output operations (std::cin, std::cout)
#include <algorithm>  // Required for std::max (used with an initializer list)
#include <vector>     // Not strictly necessary for this solution, but often included with <algorithm> or <bits/stdc++.h>

void solve() {
    long long R, G, B; // Use long long to handle values up to 10^8 and their sums
    std::cin >> R >> G >> B;

    // The problem can be solved by checking if the largest count among R, G, B
    // is less than or equal to the sum of the other two counts.
    // This is equivalent to checking the "triangle inequality" for the three counts.

    // Find the maximum of the three numbers.
    // std::max can take an initializer list {R, G, B} in C++11 and later.
    long long max_val = std::max({R, G, B});

    // Calculate the sum of all three numbers.
    long long total_sum = R + G + B;

    // The sum of the other two numbers is simply total_sum - max_val.
    long long sum_of_others = total_sum - max_val;

    // If the largest count is less than or equal to the sum of the other two,
    // then a valid assignment is possible. Otherwise, it's not.
    if (max_val <= sum_of_others) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}