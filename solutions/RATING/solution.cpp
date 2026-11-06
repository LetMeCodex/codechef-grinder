#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        long long S;
        std::cin >> S;
        // The maximum product is achieved when X is minimized and Y is maximized (closest to 0).
        // Given X > 0 and Y < 0, and X + Y = S.
        // We need X >= 1 and Y <= -1.
        // Substituting Y = S - X into Y <= -1 gives S - X <= -1, which means X >= S + 1.
        // To maximize X * Y = X * (S - X) = SX - X^2, we need to pick the smallest valid X.
        // The smallest valid integer X is S + 1.
        // If X = S + 1, then Y = S - (S + 1) = -1.
        // The product is (S + 1) * (-1) = -(S + 1).
        long long max_product = -(S + 1);
        std::cout << max_product << "\n";
    }

    return 0;
}