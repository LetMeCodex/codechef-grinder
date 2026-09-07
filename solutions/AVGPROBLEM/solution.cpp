#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        // The condition is (A + B) / 2 > C
        // To avoid floating-point arithmetic and potential precision issues,
        // we can multiply both sides by 2.
        // Since A, B, and C are positive, multiplying by 2 preserves the inequality.
        // So, the condition becomes A + B > 2 * C
        if (a + b > 2 * c) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}