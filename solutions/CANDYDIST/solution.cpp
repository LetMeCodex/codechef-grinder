#include <bits/stdc++.h> // Includes iostream and other standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        std::cin >> N >> M; // Read N (number of candies) and M (number of friends)

        // Condition 1: Check if N candies can be distributed equally among M friends
        // and all candies are used. This means N must be perfectly divisible by M.
        if (N % M == 0) {
            // If N is divisible by M, calculate how many candies each friend gets.
            int candies_per_friend = N / M;
            
            // Condition 2: Check if the number of candies each friend gets is an even number.
            if (candies_per_friend % 2 == 0) {
                // Both conditions are met: equal distribution and an even number of candies per friend.
                std::cout << "Yes\n";
            } else {
                // Condition 1 is met, but Condition 2 is not (candies_per_friend is odd).
                std::cout << "No\n";
            }
        } else {
            // Condition 1 is not met: N is not perfectly divisible by M.
            // It's impossible to distribute candies equally and use all of them.
            std::cout << "No\n";
        }
    }

    return 0; // Indicate successful execution
}