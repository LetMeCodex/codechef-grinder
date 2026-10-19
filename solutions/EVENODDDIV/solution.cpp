#include <bits/stdc++.h> // Includes iostream and other useful headers

// Using the standard namespace for brevity as allowed by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        // Case 1: N is odd.
        // This means the exponent of 2 in N's prime factorization (let's call it 'a') is 0.
        // Number of even divisors f(N) = a * g(N) = 0 * g(N) = 0.
        // Number of odd divisors g(N) is always at least 1 (since 1 is always an odd divisor).
        // Therefore, f(N) < g(N).
        cout << -1 << "\n";
    } else if (N % 4 != 0) {
        // Case 2: N is even but not divisible by 4.
        // This means N can be written as 2 * (an odd number).
        // The exponent of 2 in N's prime factorization ('a') is 1.
        // Number of even divisors f(N) = a * g(N) = 1 * g(N) = g(N).
        // Therefore, f(N) = g(N).
        cout << 0 << "\n";
    } else {
        // Case 3: N is divisible by 4.
        // This means N can be written as 4 * (some integer).
        // The exponent of 2 in N's prime factorization ('a') is 2 or more (a >= 2).
        // Number of even divisors f(N) = a * g(N).
        // Since a >= 2 and g(N) >= 1, we have f(N) = a * g(N) >= 2 * g(N) > g(N).
        // Therefore, f(N) > g(N).
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup to speed up input and output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0;
}