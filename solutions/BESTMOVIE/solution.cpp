#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        int min_cost = std::numeric_limits<int>::max(); // Initialize with a very large value
        bool found_suitable_movie = false;
        for (int i = 0; i < N; ++i) {
            int A, B;
            std::cin >> A >> B;
            if (A >= 7) {
                found_suitable_movie = true;
                min_cost = std::min(min_cost, B);
            }
        }
        if (found_suitable_movie) {
            std::cout << min_cost << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}