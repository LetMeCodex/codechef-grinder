#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        std::vector<long long> counts = {a, b, c};
        std::sort(counts.begin(), counts.end());
        long long max_count = counts[2];
        long long sum_others = counts[0] + counts[1];

        // The condition for being able to arrange the strips such that no two
        // adjacent strips have the same color is that the count of the most
        // frequent color must not be more than the sum of the counts of the
        // other two colors plus one.
        // This is because in the best-case scenario for the most frequent color,
        // we can place it in alternating positions, separated by strips of other colors.
        // For example, if we have counts like 10, 3, 3, the arrangement could be
        // M O M O M O M O M O M O M O M O M O M, where M is the most frequent color
        // and O is one of the other colors.
        // The total number of slots for the most frequent color is (total_strips + 1) / 2.
        // If the count of the most frequent color is greater than this, it's impossible.
        // Equivalently, if max_count > sum_others + 1, it's impossible.
        // This is because even if we perfectly intersperse the other colors,
        // we can only place at most sum_others + 1 strips of the most frequent color.
        // For example, if we have 10 of color A, and 3 of B, 3 of C. Total 16.
        // Max A can be is 9 (A B A C A B A C A B A C A B A).
        // If max_count = 10, sum_others = 6. 10 > 6 + 1. NO.
        // If max_count = 7, sum_others = 6. 7 <= 6 + 1. YES. (e.g., 7 3 3 -> A B A C A B A C A B A A - wait, this is wrong.
        // The logic is: the most frequent color can occupy at most `sum_others + 1` positions.
        // Example: A=7, B=3, C=3. Total 13.
        // Arrangement: A B A C A B A C A B A. This uses 7 A's, 3 B's, 3 C's.
        // The number of A's is 7. The number of other colors is 3+3=6.
        // 7 <= 6 + 1. YES.
        // Example: A=8, B=3, C=3. Total 14.
        // Arrangement: A B A C A B A C A B A A. This uses 8 A's, 3 B's, 3 C's.
        // The number of A's is 8. The number of other colors is 3+3=6.
        // 8 > 6 + 1. NO.

        if (max_count <= sum_others + 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}