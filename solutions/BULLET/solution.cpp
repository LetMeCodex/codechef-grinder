#include <bits/stdc++.h> // Includes iostream, algorithm, etc. for competitive programming

// Use the standard namespace for brevity in competitive programming
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables for speed (X), distance (Y), and minimum total time (Z).
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the time it takes for the bullet to travel from Mario to the goomba.
        // The problem states that X divides Y, so Y / X will always be an integer.
        int time_bullet_travel = Y / X;

        // We want the total time from 'now' until the bullet hits the goomba to be at least Z.
        // Let 'shoot_delay' be the time Mario waits before shooting.
        // The total time is: shoot_delay + time_bullet_travel.
        // So, we need: shoot_delay + time_bullet_travel >= Z.
        // Rearranging for shoot_delay: shoot_delay >= Z - time_bullet_travel.

        // The minimum possible shoot_delay is 0 (Mario shoots immediately).
        // If Z - time_bullet_travel is negative, it means the bullet would hit
        // the goomba in less than Z seconds even if shot immediately. In this case,
        // the minimum shoot_delay is 0. Otherwise, it's Z - time_bullet_travel.
        // The max(0, ...) function handles this condition correctly.
        int required_delay = Z - time_bullet_travel;
        int actual_shoot_delay = max(0, required_delay);

        // Output the calculated minimum shoot delay, followed by a newline character.
        cout << actual_shoot_delay << "\n";
    }

    return 0; // Indicate successful program execution.
}