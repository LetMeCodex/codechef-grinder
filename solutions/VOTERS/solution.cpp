#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    fast_io();

    int N1, N2, N3;
    std::cin >> N1 >> N2 >> N3;

    // Use a map to store voter IDs and their counts across lists.
    // Key: voter ID, Value: count of lists it appears in.
    std::map<int, int> voter_counts;

    // Process the first list
    for (int i = 0; i < N1; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID
    }

    // Process the second list
    for (int i = 0; i < N2; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID
    }

    // Process the third list
    for (int i = 0; i < N3; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID
    }

    // Collect the results
    std::vector<int> result;
    for (auto const& [id, count] : voter_counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the results
    std::cout << result.size() << "\n";
    for (int id : result) {
        std::cout << id << "\n";
    }

    return 0;
}