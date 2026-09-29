#include <iostream>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        long long M, N, K;
        std::cin >> M >> N >> K; // Read M, N, and K for each test case

        // Calculate the total time required to watch all episodes
        // Use long long for total_watch_time to prevent potential overflow
        // since N and K can be up to 10^4, their product can be up to 10^8.
        // M can be up to 10^9.
        long long total_watch_time = N * K;

        // Check if the total watch time is strictly less than the time until the exam
        if (total_watch_time < M) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}