#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long t1, t2, r1, r2;
        std::cin >> t1 >> t2 >> r1 >> r2;

        // Kepler's 3rd Law states T^2 is proportional to R^3.
        // This means T^2 / R^3 should be a constant for planets orbiting the same star.
        // So, we need to check if (T1^2 / R1^3) == (T2^2 / R2^3).
        // To avoid floating-point precision issues and potential division by zero (though constraints prevent it here),
        // we can cross-multiply: T1^2 * R2^3 == T2^2 * R1^3.

        // Calculate T^2 and R^3. Use long long to prevent overflow,
        // although with the given constraints (T, R <= 10),
        // T^2 <= 100 and R^3 <= 1000, so even int might be sufficient.
        // However, it's good practice for competitive programming.
        long long t1_squared = t1 * t1;
        long long r1_cubed = r1 * r1 * r1;
        long long t2_squared = t2 * t2;
        long long r2_cubed = r2 * r2 * r2;

        // Check the proportionality by comparing the cross-multiplied values.
        if (t1_squared * r2_cubed == t2_squared * r1_cubed) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}