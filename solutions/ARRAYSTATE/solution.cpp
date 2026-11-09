#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <deque>    // For std::deque
#include <set>      // For std::multiset
#include <algorithm> // For std::min, std::max, std::prev
#include <limits>   // For std::numeric_limits

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K;

    // deque to store the initial sorted elements that haven't been picked yet
    // These elements remain sorted relative to each other.
    std::deque<long long> dq;
    for (int i = 0; i < N; ++i) {
        long long val;
        std::cin >> val;
        dq.push_back(val);
    }

    // multiset to store the sums (X+Y) generated.
    // It automatically keeps elements sorted and allows efficient min/max access.
    std::multiset<long long> sums;

    // Perform K operations
    for (int op = 0; op < K; ++op) {
        long long X, Y;

        // --- Find X (overall minimum element) ---
        // Get minimum from deque (if not empty), using LLONG_MAX as sentinel if empty
        long long dq_min = dq.empty() ? std::numeric_limits<long long>::max() : dq.front();
        // Get minimum from multiset (if not empty), using LLONG_MAX as sentinel if empty
        long long sums_min = sums.empty() ? std::numeric_limits<long long>::max() : *sums.begin();
        
        if (dq_min <= sums_min) { // If deque's min is smaller or equal, it's the overall minimum
            X = dq.front();
            dq.pop_front();
        } else { // Otherwise, multiset's min is the overall minimum
            X = *sums.begin();
            sums.erase(sums.begin()); // Erase only one occurrence of X
        }

        // --- Find Y (overall maximum element) ---
        // Get maximum from deque (if not empty), using LLONG_MIN as sentinel if empty
        long long dq_max = dq.empty() ? std::numeric_limits<long long>::min() : dq.back();
        // Get maximum from multiset (if not empty), using LLONG_MIN as sentinel if empty
        long long sums_max = sums.empty() ? std::numeric_limits<long long>::min() : *sums.rbegin();
        
        if (dq_max >= sums_max) { // If deque's max is larger or equal, it's the overall maximum
            Y = dq.back();
            dq.pop_back();
        } else { // Otherwise, multiset's max is the overall maximum
            Y = *sums.rbegin();
            // std::prev(sums.end()) gets an iterator to the last element in the multiset
            sums.erase(std::prev(sums.end())); // Erase only one occurrence of Y
        }
        
        // Append X+Y to the array (by inserting into the sums multiset)
        sums.insert(X + Y);
    }

    // --- Collect and print the final array ---
    // The remaining elements in dq are sorted.
    // The elements in sums are also sorted (due to multiset property).
    // We merge these two sorted sequences into a single sorted vector.
    std::vector<long long> result;
    auto dq_it = dq.begin();
    auto sums_it = sums.begin();

    while (dq_it != dq.end() || sums_it != sums.end()) {
        if (dq_it != dq.end() && sums_it != sums.end()) {
            // Both containers have elements, compare their current minimums
            if (*dq_it < *sums_it) {
                result.push_back(*dq_it);
                dq_it++;
            } else {
                result.push_back(*sums_it);
                sums_it++;
            }
        } else if (dq_it != dq.end()) { // Only dq has elements left
            result.push_back(*dq_it);
            dq_it++;
        } else { // Only sums has elements left
            result.push_back(*sums_it);
            sums_it++;
        }
    }

    // Print the elements of the final array, space-separated
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}