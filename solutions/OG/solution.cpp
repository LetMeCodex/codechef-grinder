#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// Function to calculate the origin of a number
int get_origin(long long n) {
    while (n >= 10) {
        long long sum = 0;
        std::string s = std::to_string(n);
        for (char c : s) {
            sum += c - '0';
        }
        n = sum;
    }
    return n;
}

// Function to calculate the sum of origins from 1 to n
// This is the core of the solution, using digit DP or a similar approach
// The origin of a number x is (x-1) % 9 + 1, except for multiples of 9 where it's 9.
// This can be simplified: origin(x) = x % 9, if x % 9 != 0, else 9.
// Or even more simply: origin(x) = (x - 1) % 9 + 1.
// We need to calculate sum_{i=1 to N} ((i-1) % 9 + 1)

// Let's analyze the sum:
// Sum = sum_{i=1 to N} ((i-1) % 9 + 1)
// Sum = sum_{i=1 to N} (i-1) % 9 + sum_{i=1 to N} 1
// Sum = sum_{j=0 to N-1} (j % 9) + N

// The sum of j % 9 for j from 0 to M-1 is:
// If M is a multiple of 9, say M = 9k, then the sum is k * (0+1+2+3+4+5+6+7+8) = k * 36.
// If M = 9k + r, where 0 < r < 9, then the sum is k * 36 + (0+1+...+r-1).

// Let's define a helper function to calculate sum of (i-1)%9 for i from 1 to n.
// This is equivalent to sum of j%9 for j from 0 to n-1.
long long sum_mod_9(long long n) {
    if (n == 0) return 0;
    // We need to sum j % 9 for j from 0 to n-1.
    // Let's consider blocks of 9: 0..8, 9..17, etc.
    // In each block of 9, the sum of (j % 9) is 0+1+..+8 = 36.
    long long num_blocks = n / 9;
    long long remainder = n % 9;

    long long total_sum = num_blocks * 36; // Sum for full blocks of 9

    // Sum for the remaining part
    for (long long i = 0; i < remainder; ++i) {
        total_sum += i;
    }
    return total_sum;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        // The origin of a positive integer x is (x-1) % 9 + 1.
        // We need to calculate sum_{i=1 to N} ((i-1) % 9 + 1)
        // This is sum_{i=1 to N} (i-1) % 9 + sum_{i=1 to N} 1
        // Let j = i-1. When i=1, j=0. When i=N, j=N-1.
        // So, sum_{j=0 to N-1} (j % 9) + N

        long long sum_of_origins = sum_mod_9(n) + n;
        std::cout << sum_of_origins << "\n";
    }
    return 0;
}