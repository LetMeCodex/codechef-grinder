#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    long long x, y;
};

// Function to calculate squared distance between two points
long long distSq(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        long long R;
        std::cin >> R;
        Point chef, server, souschef;
        std::cin >> chef.x >> chef.y;
        std::cin >> server.x >> server.y;
        std::cin >> souschef.x >> souschef.y;

        long long rSq = R * R;

        // Check direct communication for each pair
        bool chef_server_direct = distSq(chef, server) <= rSq;
        bool chef_souschef_direct = distSq(chef, souschef) <= rSq;
        bool server_souschef_direct = distSq(server, souschef) <= rSq;

        // Check if all three can communicate.
        // This happens if at least one person can reach the other two directly.
        // Or if any two can reach each other directly, and the third can reach at least one of them.
        // The problem statement implies that if any two can communicate directly,
        // they are considered "in contact". The question is if *all three* can communicate.
        // This means that for any pair that *cannot* communicate directly,
        // there must be a third person who can communicate with *both* of them.

        // A simpler way to think about it:
        // All three can communicate if:
        // 1. Chef can reach Server AND Chef can reach Sous-Chef (Chef is the intermediary)
        // OR
        // 2. Server can reach Chef AND Server can reach Sous-Chef (Server is the intermediary)
        // OR
        // 3. Sous-Chef can reach Chef AND Sous-Chef can reach Server (Sous-Chef is the intermediary)

        bool possible = false;

        // Case 1: Chef can reach both Server and Sous-Chef
        if (distSq(chef, server) <= rSq && distSq(chef, souschef) <= rSq) {
            possible = true;
        }
        // Case 2: Server can reach both Chef and Sous-Chef
        if (distSq(server, chef) <= rSq && distSq(server, souschef) <= rSq) {
            possible = true;
        }
        // Case 3: Sous-Chef can reach both Chef and Server
        if (distSq(souschef, chef) <= rSq && distSq(souschef, server) <= rSq) {
            possible = true;
        }

        if (possible) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}