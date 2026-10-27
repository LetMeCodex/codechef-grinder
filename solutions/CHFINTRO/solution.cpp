#include <iostream> // Required for cin and cout
// #include <bits/stdc++.h> // A common competitive programming header, includes iostream and many others

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Number of contestants
    int r; // Minimum rating required to not forget flushing

    // Read N and r from the first line of input
    std::cin >> N >> r;

    // Loop N times, once for each contestant
    for (int i = 0; i < N; ++i) {
        int R; // Rating of the current contestant
        // Read the contestant's rating
        std::cin >> R;

        // Check if the contestant's rating R is at least r
        if (R >= r) {
            // If rating is sufficient, print "Good boi"
            std::cout << "Good boi\n";
        } else {
            // Otherwise, print "Bad boi"
            std::cout << "Bad boi\n";
        }
    }

    return 0; // Indicate successful execution
}