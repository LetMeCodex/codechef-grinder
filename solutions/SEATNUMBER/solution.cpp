#include <iostream>
#include <string>
#include <vector>

void solve() {
    int N;
    std::cin >> N;

    std::string deck_type;
    std::string seat_type;

    // Determine the deck
    if (N >= 1 && N <= 15) { // Lower deck
        deck_type = "Lower";
        // Determine seat type for Lower deck based on image
        if (N >= 1 && N <= 10) {
            seat_type = "Double";
        } else { // N >= 11 && N <= 15
            seat_type = "Single";
        }
    } else { // N >= 16 && N <= 30 (Upper deck)
        deck_type = "Upper";
        // Determine seat type for Upper deck based on image
        if (N >= 16 && N <= 25) {
            seat_type = "Double";
        } else { // N >= 26 && N <= 30
            seat_type = "Single";
        }
    }

    std::cout << deck_type << " " << seat_type << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}