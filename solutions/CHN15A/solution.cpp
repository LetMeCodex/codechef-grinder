#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int N, K;
        std::cin >> N >> K;
        int wolverine_count = 0;
        for (int i = 0; i < N; ++i) {
            int initial_char;
            std::cin >> initial_char;
            if ((initial_char + K) % 7 == 0) {
                wolverine_count++;
            }
        }
        std::cout << wolverine_count << std::endl;
    }
    return 0;
}