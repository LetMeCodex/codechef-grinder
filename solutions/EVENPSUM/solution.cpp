#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        // For X + Y to be even, either both X and Y are even, or both are odd.

        // Count of even numbers in [1, A]
        long long even_a = a / 2;
        // Count of odd numbers in [1, A]
        long long odd_a = (a + 1) / 2;

        // Count of even numbers in [1, B]
        long long even_b = b / 2;
        // Count of odd numbers in [1, B]
        long long odd_b = (b + 1) / 2;

        // Case 1: X is even, Y is even
        // Number of pairs = (count of even X) * (count of even Y)
        long long even_even_pairs = even_a * even_b;

        // Case 2: X is odd, Y is odd
        // Number of pairs = (count of odd X) * (count of odd Y)
        long long odd_odd_pairs = odd_a * odd_b;

        // Total valid pairs = (even X, even Y) + (odd X, odd Y)
        long long total_pairs = even_even_pairs + odd_odd_pairs;

        std::cout << total_pairs << "\n";
    }
    return 0;
}