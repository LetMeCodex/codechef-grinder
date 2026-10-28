#include <iostream>

void solve() {
    int N, M;
    std::cin >> N >> M;
    
    // If N*M is odd, it's impossible. This happens if both N and M are odd.
    // If N*M is even, it's always possible. This happens if N is even or M is even (or both).
    if (N % 2 == 0 || M % 2 == 0) {
        std::cout << "YES\n";
    } else {
        // Both N and M are odd
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}