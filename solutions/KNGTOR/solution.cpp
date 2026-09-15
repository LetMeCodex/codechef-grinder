#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, m;
        std::cin >> n >> m;
        long long total_people = n * 5 + m * 7;
        std::cout << total_people << "\n";
    }
    return 0;
}