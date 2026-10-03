#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        // For A + B to be odd, one of A and B must be odd, and the other must be even.
        // Let's count the number of odd and even integers between 1 and N.
        // Number of odd integers: ceil(N / 2.0)
        // Number of even integers: floor(N / 2.0)

        // If N is even, say N = 2k, then there are k odd numbers (1, 3, ..., 2k-1)
        // and k even numbers (2, 4, ..., 2k).
        // Number of pairs (odd, even) = k * k
        // Number of pairs (even, odd) = k * k
        // Total pairs = k * k + k * k = 2 * k * k
        // Since N = 2k, k = N/2. So, total pairs = 2 * (N/2) * (N/2) = 2 * (N^2 / 4) = N^2 / 2.

        // If N is odd, say N = 2k + 1, then there are k+1 odd numbers (1, 3, ..., 2k+1)
        // and k even numbers (2, 4, ..., 2k).
        // Number of pairs (odd, even) = (k+1) * k
        // Number of pairs (even, odd) = k * (k+1)
        // Total pairs = (k+1) * k + k * (k+1) = 2 * k * (k+1)
        // Since N = 2k + 1, k = (N-1)/2.
        // Total pairs = 2 * ((N-1)/2) * ((N-1)/2 + 1)
        // Total pairs = 2 * ((N-1)/2) * ((N+1)/2)
        // Total pairs = 2 * (N^2 - 1) / 4
        // Total pairs = (N^2 - 1) / 2.

        // A more unified way:
        // Number of odd numbers up to N is (N + 1) / 2 (integer division)
        // Number of even numbers up to N is N / 2 (integer division)
        long long num_odd = (n + 1) / 2;
        long long num_even = n / 2;

        // The number of pairs (A, B) where A is odd and B is even is num_odd * num_even.
        // The number of pairs (A, B) where A is even and B is odd is num_even * num_odd.
        // Total pairs = (num_odd * num_even) + (num_even * num_odd) = 2 * num_odd * num_even.
        long long result = 2 * num_odd * num_even;
        std::cout << result << "\n";
    }
    return 0;
}