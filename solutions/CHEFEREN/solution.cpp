#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, a, b;
        std::cin >> n >> a >> b;
        long long odd_episodes = (n + 1) / 2;
        long long even_episodes = n / 2;
        long long total_duration = odd_episodes * b + even_episodes * a;
        std::cout << total_duration << "\n";
    }
    return 0;
}