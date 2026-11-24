#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long N, K, x, y;
        cin >> N >> K >> x >> y;

        // The direction vector (dir_x, dir_y) cycles through (1,1) -> (-1,1) -> (-1,-1) -> (1,-1) -> (1,1)
        // every 4 collisions. So we only need to simulate K mod 4 steps.
        // If K mod 4 is 0, it means the 4th step in the cycle.
        long long effective_k = K % 4;
        if (effective_k == 0) {
            effective_k = 4;
        }

        long long curr_x = x;
        long long curr_y = y;
        long long dir_x = 1;
        long long dir_y = 1;

        bool stopped_at_corner = false;

        for (long long i = 0; i < effective_k; ++i) {
            long long dx_dist, dy_dist;

            // Calculate distance to the next vertical wall
            if (dir_x == 1) { // Moving right
                dx_dist = N - curr_x;
            } else { // Moving left
                dx_dist = curr_x;
            }

            // Calculate distance to the next horizontal wall
            if (dir_y == 1) { // Moving up
                dy_dist = N - curr_y;
            } else { // Moving down
                dy_dist = curr_y;
            }

            long long t_step = min(dx_dist, dy_dist);

            // Update position
            curr_x += dir_x * t_step;
            curr_y += dir_y * t_step;

            // Check if it hit a corner
            if (dx_dist == dy_dist) {
                stopped_at_corner = true;
                break; // Ball stops at a corner
            } else if (dx_dist < dy_dist) {
                // Hit a vertical wall
                dir_x = -dir_x;
            } else {
                // Hit a horizontal wall
                dir_y = -dir_y;
            }
        }

        cout << curr_x << " " << curr_y << endl;
    }

    return 0;
}