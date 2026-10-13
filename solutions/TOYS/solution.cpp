#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    while (std::cin >> n >> m) {
        // Chef plays with one toy per day as long as he has at least one toy.
        // He breaks the toy he plays with.
        // So, each day he plays, the number of toys decreases by 1.
        // This continues for M days, or until he runs out of toys.
        // The number of toys broken is the minimum of the initial number of toys (N)
        // and the number of days he plays (M).
        // The number of toys left is the initial number of toys minus the number of toys broken.

        int toys_broken = std::min(n, m);
        int toys_left = n - toys_broken;
        std::cout << toys_left << "\n";
    }
    return 0;
}