#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        if (n < 3) {
            std::cout << -1 << "\n";
        } else {
            // To maximize the perimeter, we should pick the three largest sticks.
            // Let the lengths be a, b, c such that c > b > a.
            // The triangle inequality states that the sum of any two sides must be greater than the third side.
            // For a non-degenerate triangle, 2 * max(a, b, c) < a + b + c.
            // If we pick the three largest sticks, their lengths are n, n-1, n-2.
            // Let c = n, b = n-1, a = n-2.
            // We need to check if 2 * n < n + (n-1) + (n-2).
            // 2 * n < 3*n - 3
            // 3 < n
            // This inequality holds for n > 3.
            // If n = 3, the sticks are 1, 2, 3.
            // The largest is 3. 2 * 3 = 6. The sum is 1 + 2 + 3 = 6.
            // 6 < 6 is false, so a degenerate triangle is formed.
            // Thus, for n=3, no non-degenerate triangle can be formed with sticks 1, 2, 3.
            // The problem states we have sticks 1, 2, ..., N.
            // For n=3, sticks are 1, 2, 3. Max perimeter is -1.
            // For n=4, sticks are 1, 2, 3, 4. We can pick 4, 3, 2.
            // Max side is 4. 2 * 4 = 8. Sum is 4 + 3 + 2 = 9.
            // 8 < 9 is true. Perimeter is 9.
            // So, if n >= 4, we can always form a triangle with sticks n, n-1, n-2.
            // The perimeter will be n + (n-1) + (n-2) = 3*n - 3.
            if (n == 3) {
                std::cout << -1 << "\n";
            } else {
                // For n >= 4, the sticks n, n-1, n-2 form a valid triangle.
                // The largest perimeter is achieved by picking the three largest sticks.
                long long perimeter = n + (n - 1) + (n - 2);
                std::cout << perimeter << "\n";
            }
        }
    }
    return 0;
}