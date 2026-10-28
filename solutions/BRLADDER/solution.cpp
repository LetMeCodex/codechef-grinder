#include <cstdio>   // For scanf, printf
#include <cmath>    // For std::abs
#include <algorithm> // For std::min

int main() {
    // For scanf/printf, no need for ios_base::sync_with_stdio(false) or cin.tie(NULL).
    // These optimizations are specific to C++ iostreams (cin/cout).

    int Q;
    scanf("%d", &Q); // Read the number of queries using scanf

    while (Q--) { // Loop Q times for each query
        long long a, b;
        scanf("%lld %lld", &a, &b); // Read the two distinct cities using scanf with %lld for long long

        // Calculate the absolute difference between a and b.
        // std::abs() is overloaded for long long in <cmath> and works independently of I/O method.
        long long diff = std::abs(a - b);

        if (diff == 1) {
            // Case 1: Cities are consecutive (e.g., 1-2, 3-4).
            // A road exists if the smaller city is odd.
            // This corresponds to roads of type (2*i+1, 2*i+2), where 2*i+1 is always odd.
            // std::min() is overloaded for long long in <algorithm> and works independently of I/O method.
            if (std::min(a, b) % 2 == 1) {
                printf("YES\n"); // Print "YES" using printf
            } else {
                // If the smaller city is even (e.g., 2-3, 4-5), no road of this type.
                printf("NO\n"); // Print "NO" using printf
            }
        } else if (diff == 2) {
            // Case 2: Cities differ by 2 (e.g., 1-3, 2-4, 3-5, 4-6).
            // If two numbers differ by 2, they must have the same parity.
            // - If both are odd (e.g., 1-3), it matches the "consecutive odd numbers" rule.
            // - If both are even (e.g., 2-4), it matches the "consecutive even numbers" rule.
            // In both scenarios, a road exists.
            printf("YES\n"); // Print "YES" using printf
        } else {
            // Case 3: Cities differ by more than 2.
            // Based on the problem description, no roads exist for differences greater than 2.
            printf("NO\n"); // Print "NO" using printf
        }
    }

    return 0; // Indicate successful execution
}