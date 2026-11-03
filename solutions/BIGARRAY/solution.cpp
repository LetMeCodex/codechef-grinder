#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, s;
        std::cin >> n >> s;

        // The array A is defined as A[i] = i for 1 <= i <= N.
        // The sum of all elements in the array is the sum of integers from 1 to N.
        // Sum(1 to N) = N * (N + 1) / 2.
        // We are looking for a position x (1 <= x <= N) such that
        // (A[1] + ... + A[x-1]) + (A[x+1] + ... + A[N]) = S.
        // This is equivalent to:
        // (Sum of all elements) - A[x] = S
        // (N * (N + 1) / 2) - x = S
        // So, x = (N * (N + 1) / 2) - S.

        // Calculate the total sum of elements from 1 to N.
        // Use long long to prevent overflow for large N.
        long long total_sum = n * (n + 1) / 2;

        // Calculate the required value of x.
        long long required_x = total_sum - s;

        // Check if the calculated x is a valid position in the array.
        // A valid position x must satisfy 1 <= x <= N.
        if (required_x >= 1 && required_x <= n) {
            std::cout << required_x << "\n";
        } else {
            // If no such valid position exists, print -1.
            std::cout << -1 << "\n";
        }
    }
    return 0;
}