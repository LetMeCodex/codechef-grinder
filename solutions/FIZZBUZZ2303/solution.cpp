#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // The problem asks for the number of ways to choose a captain and a vice-captain
        // from a group of N players.
        // This is a permutation problem: P(N, 2) = N * (N - 1).
        // For the captain, there are N choices.
        // Once the captain is chosen, there are N-1 remaining players for the vice-captain.
        // So, the total number of choices is N * (N - 1).
        long long choices = (long long)n * (n - 1);
        std::cout << choices << "\n";
    }
    return 0;
}