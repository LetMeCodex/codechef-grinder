#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        int d;
        std::cin >> n >> d;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int switches = 0;
        // Initially holding the close-range gun.
        // current_gun: 0 for close-range, 1 for long-range
        int current_gun = 0; 

        for (int i = 0; i < n; ++i) {
            bool needs_close_range = (a[i] <= d);
            bool needs_long_range = (a[i] > d);

            if (current_gun == 0) { // Currently holding close-range gun
                if (needs_long_range) {
                    // Must switch to long-range gun
                    switches++;
                    current_gun = 1;
                }
                // If needs_close_range, no switch needed.
            } else { // Currently holding long-range gun
                if (needs_close_range) {
                    // Must switch to close-range gun
                    switches++;
                    current_gun = 0;
                }
                // If needs_long_range, no switch needed.
            }
        }
        std::cout << switches << "\n";
    }
    return 0;
}