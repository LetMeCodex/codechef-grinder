#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Id and Ship (FLOW010)
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a single character.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        char id;
        cin >> id;

        // Check the ID and print the corresponding Ship Class
        // Using if-else to handle both uppercase and lowercase inputs
        if (id == 'B' || id == 'b') {
            cout << "BattleShip" << "\n";
        } else if (id == 'C' || id == 'c') {
            cout << "Cruiser" << "\n";
        } else if (id == 'D' || id == 'd') {
            cout << "Destroyer" << "\n";
        } else if (id == 'F' || id == 'f') {
            cout << "Frigate" << "\n";
        }
    }

    return 0;
}