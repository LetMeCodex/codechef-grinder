#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare two integer variables N and M.
    int N, M;

    // Read the two space-separated integers from standard input.
    std::cin >> N >> M;

    // Apply the condition: if 2 * M is greater than or equal to N,
    // it means errors are present in at least half of the total lines.
    if (2 * M >= N) {
        // If the condition is true, Ved is a NEWBIE.
        std::cout << "NEWBIE\n";
    } else {
        // Otherwise, Ved is a PRO.
        std::cout << "PRO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}