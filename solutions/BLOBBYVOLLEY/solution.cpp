#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        int alice_score = 0;
        int bob_score = 0;
        char current_server = 'A'; // Initially Alice is the server

        for (char winner : s) {
            if (winner == current_server) {
                // Server wins the point
                if (current_server == 'A') {
                    alice_score++;
                } else {
                    bob_score++;
                }
                // Server remains the same
            } else {
                // Receiver wins the point
                // Receiver's score does not increase
                // Receiver becomes the server for the next turn
                if (current_server == 'A') {
                    current_server = 'B';
                } else {
                    current_server = 'A';
                }
            }
        }
        std::cout << alice_score << " " << bob_score << "\n";
    }
    return 0;
}