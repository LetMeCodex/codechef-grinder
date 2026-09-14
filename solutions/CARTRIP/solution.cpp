#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        // The cost is 10 per km, but at least 300 km must be paid for.
        // So, the number of kilometers to charge for is the maximum of x and 300.
        long long kilometers_to_charge = std::max(x, 300);
        long long cost = kilometers_to_charge * 10LL;
        std::cout << cost << "\n";
    }
    return 0;
}