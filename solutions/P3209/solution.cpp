#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int gcd(int a, int b) {
    return std::gcd(a, b);
}

struct Player {
    int id;
    int score;

    bool operator<(const Player& other) const {
        if (score != other.score) {
            return score > other.score; // Higher score comes first
        }
        return id < other.id; // Smaller ID comes first for same score
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::vector<Player> players;
        for (int i = 1; i <= n; ++i) {
            players.push_back({i, gcd(i, n)});
        }

        std::sort(players.begin(), players.end());

        for (int i = 0; i < n; ++i) {
            std::cout << players[i].id << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}