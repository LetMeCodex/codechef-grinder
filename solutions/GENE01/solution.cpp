#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char parent1, parent2;
    std::cin >> parent1 >> parent2;

    // The problem states that 'brown' (R) is most common,
    // 'green' (G) is rarest, and 'blue' (B) is in between.
    // The child's eye color is most likely to be the most common
    // eye color between the two parents.

    // We can establish a hierarchy of commonality: R > B > G.
    // If both parents have the same eye color, the child will have that color.
    // If the parents have different eye colors, the child will have the color
    // that is more common between the two.

    if (parent1 == parent2) {
        std::cout << parent1 << "\n";
    } else {
        // Determine which of the two parent colors is more common.
        // We can use a simple comparison based on the hierarchy R > B > G.
        // If one parent is R, it's the most common.
        // If one parent is B and the other is G, B is more common.

        if (parent1 == 'R' || parent2 == 'R') {
            std::cout << 'R' << "\n";
        } else if (parent1 == 'B' || parent2 == 'B') {
            // If neither is 'R', and at least one is 'B', then 'B' is the most common.
            // This covers cases like (B, B), (B, G), (G, B).
            // (B, B) is already handled by the first if.
            // So this branch handles (B, G) and (G, B).
            std::cout << 'B' << "\n";
        } else {
            // The only remaining case is (G, G), which is handled by the first if.
            // This branch should theoretically not be reached if the first if is correct.
            // However, if we reach here, it implies both are 'G', which is handled.
            // But to be explicit and cover all combinations:
            // If neither is R and neither is B, they must both be G.
            std::cout << 'G' << "\n";
        }
    }

    return 0;
}