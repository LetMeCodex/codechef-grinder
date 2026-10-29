#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int calculate_hamming_distance(const std::string& s1, const std::string& s2) {
    int distance = 0;
    for (size_t i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string a, b;
        std::cin >> a >> b;

        int min_hamming_distance = m; // Maximum possible Hamming distance is M

        for (int i = 0; i <= n - m; ++i) {
            std::string sub_a = a.substr(i, m);
            int current_distance = calculate_hamming_distance(sub_a, b);
            min_hamming_distance = std::min(min_hamming_distance, current_distance);
        }
        std::cout << min_hamming_distance << "\n";
    }
    return 0;
}