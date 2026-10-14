#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::unordered_map<int, int> swipe_counts;
        int current_people = 0;
        int max_people = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            swipe_counts[a[i]]++;
            if (swipe_counts[a[i]] % 2 == 1) {
                // Odd swipe count means entering
                current_people++;
            } else {
                // Even swipe count means leaving
                current_people--;
            }
            max_people = std::max(max_people, current_people);
        }
        std::cout << max_people << "\n";
    }
    return 0;
}