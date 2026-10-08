#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    std::cin >> x;
    // Christmas is on December 25th.
    // Chef bakes one practice cake every day from December 1st to December 24th.
    // Today is the X-th of December.
    // We need to find how many practice cakes Chef will bake starting from today.
    // This means we need to count the number of days from X to 24, inclusive.
    // The number of days is 24 - X + 1.
    int cakes_to_bake = 24 - x + 1;
    std::cout << cakes_to_bake << "\n";
    return 0;
}