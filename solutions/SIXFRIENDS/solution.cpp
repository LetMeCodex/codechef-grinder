#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y;
        std::cin >> x >> y;
        // Option 1: Three double rooms. Each double room accommodates 2 people.
        // To accommodate 6 people, we need 6 / 2 = 3 double rooms.
        // Total cost = 3 * X
        long long cost_double_rooms = 3 * x;

        // Option 2: Two triple rooms. Each triple room accommodates 3 people.
        // To accommodate 6 people, we need 6 / 3 = 2 triple rooms.
        // Total cost = 2 * Y
        long long cost_triple_rooms = 2 * y;

        // The minimum amount is the minimum of these two options.
        long long min_cost = std::min(cost_double_rooms, cost_triple_rooms);
        std::cout << min_cost << "\n";
    }
    return 0;
}