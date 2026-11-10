#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long q;
        std::cin >> n >> q;
        std::string s;
        std::cin >> s;

        std::map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        std::vector<int> virus_counts;
        for (auto const& [key, val] : counts) {
            virus_counts.push_back(val);
        }
        std::sort(virus_counts.rbegin(), virus_counts.rend()); // Sort in descending order

        for (long long i = 0; i < q; ++i) {
            long long c;
            std::cin >> c;

            long long pending_queue_size = 0;
            long long centers_used = 0;

            for (int count : virus_counts) {
                if (centers_used < c) {
                    // We can place 'count' people in 'count' different centers.
                    // If we have enough centers (c), we can place all of them
                    // without using the pending queue for this virus type.
                    // However, we need to consider how many people *must* go to the pending queue.
                    // The number of people that *must* go to the pending queue for a virus type
                    // is max(0, count - c).
                    // But we are trying to minimize the pending queue.
                    // If we have 'c' centers, we can accommodate up to 'c' people of the same virus type
                    // across these centers.
                    // The number of people that *cannot* be placed in isolation centers for this virus type
                    // is max(0, count - c). These must go to the pending queue.
                    pending_queue_size += std::max(0, count - (int)c);
                } else {
                    // If we have already used all 'c' isolation centers,
                    // all remaining people for this virus type must go to the pending queue.
                    pending_queue_size += count;
                }
            }
            
            // The logic above is slightly flawed. Let's rethink.
            // We have 'c' isolation centers.
            // For each virus type, say 'k' people are infected.
            // We can place at most one person of this virus type in each of the 'c' centers.
            // So, we can place min(k, c) people in isolation centers.
            // The remaining k - min(k, c) people must go to the pending queue.
            // k - min(k, c) = k - (k if k <= c else c)
            // If k <= c, then k - k = 0 people go to pending queue.
            // If k > c, then k - c people go to pending queue.
            // This is equivalent to max(0, k - c).

            pending_queue_size = 0; // Reset for correct calculation
            for (int count : virus_counts) {
                pending_queue_size += std::max(0, count - (int)c);
            }

            std::cout << pending_queue_size << "\n";
        }
    }
    return 0;
}