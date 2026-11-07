#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is common in competitive programming.
using namespace std;

int main() {
    // Fast I/O to speed up input and output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of testcases
    cin >> T;
    while (T--) {
        int X, Y; // Initial position of Chef and partner
        cin >> X >> Y;

        if (X == Y) {
            // If Chef is already at the partner's position, 0 moves are needed.
            cout << 0 << "\n";
        } else if (Y > X) {
            // Chef needs to move to a higher position.
            // The Moonwalk move (k -> k+2) is generally efficient for increasing position.
            // The Slide move (k -> k-1) decreases position.

            int diff = Y - X; // The positive difference Chef needs to cover.

            if (diff % 2 == 0) {
                // If the difference is even, Chef can reach Y purely by Moonwalks.
                // Each Moonwalk covers 2 units. So, diff / 2 Moonwalks are needed.
                // Example: X=3, Y=7. diff=4. Moves = 4/2 = 2. (3->5->7)
                cout << diff / 2 << "\n";
            } else {
                // If the difference is odd, Chef cannot reach Y purely by Moonwalks.
                // This means Chef must use at least one Slide move.
                // The optimal strategy is to either:
                // 1. Moonwalk until Y+1, then slide once.
                //    This takes (diff/2 + 1) Moonwalks to reach Y+1, and 1 Slide to Y.
                //    Total moves = (diff/2 + 1) + 1 = diff/2 + 2.
                //    Example: X=3, Y=8. diff=5. 5/2 = 2. Moves = 2+2 = 4. (3->5->7->9->8)
                // 2. Slide once to X-1, then Moonwalk to Y.
                //    This takes 1 Slide. The new difference is (Y-(X-1)) = (Y-X)+1 = diff+1.
                //    Since diff is odd, diff+1 is even. So (diff+1)/2 Moonwalks are needed.
                //    Total moves = 1 + (diff+1)/2.
                //    Example: X=3, Y=8. diff=5. Moves = 1 + (5+1)/2 = 1 + 3 = 4. (3->2->4->6->8)
                // Both strategies yield the same minimum moves.
                cout << diff / 2 + 2 << "\n";
            }
        } else { // Y < X
            // Chef needs to move to a lower position.
            // The Slide move (k -> k-1) is the only move that decreases position.
            // Using a Moonwalk (k -> k+2) would move Chef further away from Y,
            // requiring even more Slide moves later, thus increasing total moves.
            // So, the optimal strategy is to only use Slide moves.
            // The number of moves is simply the absolute difference X - Y.
            // Example: X=8, Y=3. Moves = 8-3 = 5. (8->7->6->5->4->3)
            cout << X - Y << "\n";
        }
    }

    return 0;
}