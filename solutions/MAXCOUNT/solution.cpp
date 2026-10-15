#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> // For std::pair

// Function to find the most frequent element and its count
std::pair<int, int> mostFrequent(int N, std::vector<int>& A) {
    std::map<int, int> counts; // Use std::map to store frequencies. It keeps keys sorted.

    // Populate the frequency map
    for (int x : A) {
        counts[x]++;
    }

    int max_freq = 0;
    int best_element = -1; // Placeholder, will be updated. Initialize with a value that won't be in constraints if possible, or handle first element specially.
                           // Since A[i] >= 1, -1 is a safe initial placeholder.

    // Iterate through the frequency map to find the element with the maximum frequency.
    // The map iterates in increasing order of keys (elements).
    for (auto const& [element, freq] : counts) {
        if (freq > max_freq) {
            max_freq = freq;
            best_element = element;
        } else if (freq == max_freq) {
            // If frequencies are equal, we want the smaller element.
            // Since the map iterates in increasing order of 'element',
            // the 'best_element' will already be the smallest one encountered
            // for this 'max_freq'. No explicit update needed here.
        }
    }

    return {best_element, max_freq};
}

// The main function structure for competitive programming platforms
// This part is usually provided by the platform, but we include it for completeness
// and to show how mostFrequent would be called.
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }
        std::pair<int, int> res = mostFrequent(N, A);
        std::cout << res.first << " " << res.second << "\n";
    }
    return 0;
}
*/