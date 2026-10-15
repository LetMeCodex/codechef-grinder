#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output, as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a; // 'a' can be up to 10^18, so long long is necessary
    cin >> a;

    // Calculate the remainder when 'a' is divided by 6.
    // Based on the pattern analysis, Chef can reach point 'a' if and only if
    // 'a' modulo 6 is 0, 1, or 3.
    long long remainder = a % 6;

    if (remainder == 0 || remainder == 1 || remainder == 3) {
        cout << "yes\n"; // If the remainder is 0, 1, or 3, Chef can reach 'a'
    } else {
        cout << "no\n";  // Otherwise, Chef cannot reach 'a'
    }

    return 0; // Indicate successful execution
}