#include <iostream>
#include <unordered_map> // For efficient frequency counting

void solve() {
    int N;
    std::cin >> N;
    std::unordered_map<int, int> counts; // Map to store frequencies of numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i;
        counts[A_i]++; // Increment frequency for A_i
    }

    long long total_good_pairs = 0;
    // Iterate through the map to calculate pairs for each distinct number
    for (auto const& pair_entry : counts) {
        // pair_entry.first is the number, pair_entry.second is its count
        long long count = pair_entry.second; // Use long long for count to avoid overflow in multiplication
        if (count >= 2) {
            // If a number appears 'count' times, the number of ways to choose 2 elements
            // from these 'count' occurrences is count * (count - 1) / 2.
            total_good_pairs += count * (count - 1) / 2;
        }
    }
    std::cout << total_good_pairs << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}