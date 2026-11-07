#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long x;
        std::cin >> x;
        // The given equation is 2*a + 2*b + a*b = X
        // We can rewrite this equation by adding 4 to both sides:
        // a*b + 2*a + 2*b + 4 = X + 4
        // This can be factored as:
        // (a + 2)(b + 2) = X + 4
        // Let A = a + 2 and B = b + 2.
        // Since a and b are positive integers (a > 0, b > 0),
        // it implies a >= 1 and b >= 1.
        // Therefore, A = a + 2 >= 1 + 2 = 3, and B = b + 2 >= 1 + 2 = 3.
        // So, we need to find if there exist two integers A and B, both >= 3,
        // such that A * B = X + 4.

        long long target = x + 4;

        // We need to find if 'target' can be expressed as a product of two integers,
        // both of which are greater than or equal to 3.
        // This means we are looking for a divisor 'A' of 'target' such that:
        // 1. A >= 3
        // 2. target / A >= 3

        // We can iterate through possible values of 'A' starting from 3.
        // The maximum possible value for 'A' would be sqrt(target).
        // If we find such an 'A', then B = target / A will also be >= 3.
        // If target is prime and greater than or equal to 3, it cannot be factored into two integers >= 3.
        // If target is 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12...
        // X = 2 => target = 6. Factors of 6 are (1,6), (2,3), (3,2), (6,1).
        // For (1,6), a+2=1 => a=-1 (not positive).
        // For (2,3), a+2=2 => a=0 (not positive).
        // For (3,2), a+2=3 => a=1, b+2=2 => b=0 (not positive).
        // For (6,1), a+2=6 => a=4, b+2=1 => b=-1 (not positive).
        // So for X=2, NO.

        // X = 5 => target = 9. Factors of 9 are (1,9), (3,3), (9,1).
        // For (3,3), a+2=3 => a=1, b+2=3 => b=1. Both are positive. YES.

        // X = 6 => target = 10. Factors of 10 are (1,10), (2,5), (5,2), (10,1).
        // For (2,5), a+2=2 => a=0 (not positive).
        // For (5,2), a+2=5 => a=3, b+2=2 => b=0 (not positive).
        // So for X=6, NO.

        // X = 12 => target = 16. Factors of 16 are (1,16), (2,8), (4,4), (8,2), (16,1).
        // For (4,4), a+2=4 => a=2, b+2=4 => b=2. Both are positive. YES.

        // The condition is that 'target' must have at least one pair of factors (A, B)
        // such that A >= 3 and B >= 3.
        // This is equivalent to checking if 'target' has any divisor 'A' such that
        // 3 <= A <= sqrt(target). If such an 'A' exists, then B = target / A will also be >= 3
        // because if A <= sqrt(target), then target/A >= target/sqrt(target) = sqrt(target).
        // If target is a perfect square, A = sqrt(target), then B = sqrt(target).
        // If A < sqrt(target), then B > sqrt(target).
        // In both cases, if A >= 3 and A <= sqrt(target), then B = target/A will be >= sqrt(target).
        // If sqrt(target) >= 3, then B >= 3.
        // The only edge case is when target is a perfect square and sqrt(target) < 3.
        // This happens if target is 4 or 9.
        // If target = 4, sqrt(target) = 2. No divisor A >= 3.
        // If target = 9, sqrt(target) = 3. Divisor A=3. B=3. Both >= 3.

        // So, we need to check if 'target' has a divisor 'A' such that 3 <= A <= sqrt(target).
        // If target < 9, it's impossible to have two factors >= 3.
        // For example, if target = 8, sqrt(8) approx 2.8. No divisor >= 3.
        // If target = 7, sqrt(7) approx 2.6. No divisor >= 3.
        // If target = 6, sqrt(6) approx 2.4. No divisor >= 3.
        // If target = 5, sqrt(5) approx 2.2. No divisor >= 3.
        // If target = 4, sqrt(4) = 2. No divisor >= 3.
        // If target = 3, sqrt(3) approx 1.7. No divisor >= 3.
        // If target = 2, sqrt(2) approx 1.4. No divisor >= 3.
        // If target = 1, sqrt(1) = 1. No divisor >= 3.

        // So, if target < 9, it's impossible.
        // If target >= 9, we check for divisors.
        // We only need to check divisors up to sqrt(target).
        // If we find a divisor 'i' such that 3 <= i <= sqrt(target),
        // then target/i will be >= sqrt(target).
        // Since target >= 9, sqrt(target) >= 3.
        // So, if i >= 3, then target/i >= 3.
        // Thus, we just need to find if there is any divisor 'i' of 'target'
        // such that 3 <= i <= sqrt(target).

        bool found = false;
        if (target >= 9) {
            long long limit = sqrt(target);
            for (long long i = 3; i <= limit; ++i) {
                if (target % i == 0) {
                    // We found a divisor 'i'.
                    // Let A = i and B = target / i.
                    // Since i >= 3 and i <= sqrt(target),
                    // we have A >= 3.
                    // And B = target / i >= target / sqrt(target) = sqrt(target).
                    // Since target >= 9, sqrt(target) >= 3.
                    // So B >= 3.
                    // Thus, we found a pair (A, B) both >= 3.
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}