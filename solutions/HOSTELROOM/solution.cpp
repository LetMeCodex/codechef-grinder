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
        long long x;
        std::cin >> n >> x;
        long long current_people = x;
        long long max_people = x;
        for (int i = 0; i < n; ++i) {
            long long a;
            std::cin >> a;
            current_people += a;
            if (current_people > max_people) {
                max_people = current_people;
            }
        }
        std::cout << max_people << "\n";
    }
    return 0;
}