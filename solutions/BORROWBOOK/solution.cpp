#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::map<int, int> return_day_to_max_late_days;
        for (int i = 1; i <= n; ++i) {
            int return_day;
            std::cin >> return_day;
            // The i-th book (1-indexed) was returned i days late.
            // We need to find the maximum penalty for books returned on the same day.
            // The penalty for the i-th book is i days late.
            // The problem states "It was returned i days late." for the i-th book.
            // This means the i-th book in the input array corresponds to the i-th book Chef borrowed.
            // The problem statement says "For the i-th book (1 <= i <= N): It was returned i days late."
            // This implies the book that is i days late is the i-th book Chef borrowed.
            // And then it says "It was returned on day A_i".
            // So, the i-th book borrowed (which is i days late) was returned on day A_i.
            // The penalty for this book is i.
            // We need to group by return_day (A_i) and find the max penalty (i) for each day.

            // Let's re-read carefully:
            // "For the i-th book (1 <= i <= N):
            // - It was returned i days late.
            // - It was returned on day A_i."
            // This means the book that is i days late is the i-th book Chef borrowed.
            // The input A_i is the return day for the i-th book.
            // The penalty for the i-th book is i.
            // So, for the i-th book (which is i days late), its return day is A_i.
            // The penalty for this book is i.
            // We need to find the maximum penalty among books returned on the same day.

            // Example 2:
            // N = 4
            // A = [1, 1, 2, 2]
            // Book 1: 1 day late, returned on day A_1 = 1. Penalty = 1.
            // Book 2: 2 days late, returned on day A_2 = 1. Penalty = 2.
            // Book 3: 3 days late, returned on day A_3 = 2. Penalty = 3.
            // Book 4: 4 days late, returned on day A_4 = 2. Penalty = 4.

            // On day 1, books returned:
            // Book 1 (1 day late, penalty 1)
            // Book 2 (2 days late, penalty 2)
            // Highest penalty on day 1 is max(1, 2) = 2.

            // On day 2, books returned:
            // Book 3 (3 days late, penalty 3)
            // Book 4 (4 days late, penalty 4)
            // Highest penalty on day 2 is max(3, 4) = 4.

            // Total penalty = 2 + 4 = 6. This matches sample output.

            // So, the i-th element in the input array `A` corresponds to the return day of the book that is `i` days late.
            // The penalty for this book is `i`.
            // We need to map `return_day` to the maximum `penalty` (which is `i`) for that `return_day`.

            int penalty = i; // The i-th book is i days late.
            if (return_day_to_max_late_days.find(return_day) == return_day_to_max_late_days.end()) {
                return_day_to_max_late_days[return_day] = penalty;
            } else {
                return_day_to_max_late_days[return_day] = std::max(return_day_to_max_late_days[return_day], penalty);
            }
        }

        long long total_penalty = 0;
        for (auto const& [day, max_penalty] : return_day_to_max_late_days) {
            total_penalty += max_penalty;
        }
        std::cout << total_penalty << "\n";
    }
    return 0;
}