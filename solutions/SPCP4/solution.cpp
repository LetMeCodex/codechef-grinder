#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x, k;
        std::cin >> n >> x >> k;
        long long boys = x;
        long long girls = n - x;

        // Number of groups of boys
        long long boy_groups = boys / k;
        // Number of boys remaining after forming groups
        long long remaining_boys = boys % k;

        // Number of groups of girls
        long long girl_groups = girls / k;
        // Number of girls remaining after forming groups
        long long remaining_girls = girls % k;

        // Students who can dance around the bonfire are limited by the minimum of remaining boys and girls
        long long dancing_pairs = std::min(remaining_boys, remaining_girls);

        // Students who will be reading are those remaining after forming dancing pairs
        long long reading_students = (remaining_boys - dancing_pairs) + (remaining_girls - dancing_pairs);

        std::cout << reading_students << "\n";
    }
    return 0;
}