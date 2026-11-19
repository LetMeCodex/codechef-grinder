#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        std::vector<int> pos(n + 1); // pos[person_id] = index in p
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            pos[p[i]] = i;
        }

        long long total_disturbed = 0;
        
        // We need to keep track of the occupied seats.
        // Initially, all seats are occupied.
        // As people leave, their seats become free.
        // However, the problem statement implies that people leave from their current seat.
        // The crucial part is how many *other people* they have to pass by.
        // This means we need to know the positions of people *currently in the theatre*.
        // A simpler way to think about this is that when a person leaves, they are removed from the row.
        // The people to their left and right are now adjacent.
        // The number of people disturbed is the minimum of people to their left and people to their right.

        // Let's maintain the current state of the row.
        // We can use a boolean array or a set to mark occupied seats.
        // Since N is small (up to 10), we can simulate this directly.
        // However, the sum of N can be large, so a direct simulation of the row might be too slow if N was large.
        // For N <= 10, the total number of operations per test case is manageable.

        // Let's track the occupied seats.
        std::vector<bool> occupied(n, true);
        
        // People leave in decreasing order of their number.
        for (int person_id = n; person_id >= 1; --person_id) {
            int current_seat_idx = pos[person_id];
            
            // Find the number of occupied seats to the left and right of the current person.
            int left_count = 0;
            for (int i = 0; i < current_seat_idx; ++i) {
                if (occupied[i]) {
                    left_count++;
                }
            }
            
            int right_count = 0;
            for (int i = current_seat_idx + 1; i < n; ++i) {
                if (occupied[i]) {
                    right_count++;
                }
            }
            
            // The person chooses the direction that minimizes disturbances.
            total_disturbed += std::min(left_count, right_count);
            
            // Mark the current person's seat as unoccupied.
            occupied[current_seat_idx] = false;
        }
        
        std::cout << total_disturbed << "\n";
    }
    return 0;
}