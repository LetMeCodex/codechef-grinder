#include <bits/stdc++.h> // Includes iostream, cmath, etc. for convenience

// Use the standard namespace as requested by competitive programming conventions
using namespace std;

/**
 * @brief Checks if a given integer N is a prime number.
 *
 * A prime number is a natural number greater than 1 that has no positive divisors
 * other than 1 and itself.
 *
 * @param n The integer to be tested for primality.
 * @return true if N is prime, false otherwise.
 */
bool isPrime(int n) {
    // According to the problem statement, 1 is not a prime number.
    // Numbers less than or equal to 1 are not prime.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // All other even numbers (greater than 2) are not prime,
    // as they are divisible by 2.
    if (n % 2 == 0) {
        return false;
    }
    // For odd numbers, we only need to check for odd divisors
    // starting from 3 up to the square root of n.
    // If n has a divisor greater than sqrt(n), it must also have a
    // corresponding divisor smaller than sqrt(n).
    // We use `i * i <= n` instead of `i <= sqrt(n)` to avoid
    // floating-point calculations and potential precision issues.
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            // If we find any divisor, n is not prime.
            return false;
        }
    }
    // If no divisors were found, n is a prime number.
    return true;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;

    // Loop through each test case.
    while (T--) {
        int N;
        // Read the integer to be tested for primality.
        cin >> N;

        // Call the isPrime function and print the result.
        if (isPrime(N)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}