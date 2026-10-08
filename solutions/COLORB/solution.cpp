#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using namespace std; is generally fine for competitive programming
using namespace std;

int main() {
    // Enable fast I/O. This is a standard optimization in competitive programming
    // to speed up input and output operations, especially for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read R and B, the initial number of red and blue orbs Chef has.
    int R, B;
    cin >> R >> B;

    // Chef can buy 1 green orb at the cost of 1 red orb + 1 blue orb.
    // This means that the number of green orbs Chef can obtain is limited
    // by the minimum of the available red and blue orbs.
    // For example, if Chef has 3 red and 4 blue orbs, he can make at most 3 trades
    // because he only has 3 red orbs. After 3 trades, he will run out of red orbs.
    int K_max = min(R, B);

    // After making K_max trades, we need to calculate the final count of each orb type.
    // Red orbs remaining: Initial R minus K_max (orbs used for trades).
    int remaining_R = R - K_max;
    // Blue orbs remaining: Initial B minus K_max (orbs used for trades).
    int remaining_B = B - K_max;
    // Green orbs obtained: K_max (each trade yields 1 green orb).
    int green_orbs = K_max;

    // Now, calculate the total skill based on the final orb counts and their values.
    // 1 red orb increases skill by 1.
    // 1 blue orb increases skill by 2.
    // 1 green orb increases skill by 5.
    int total_skill = (remaining_R * 1) + // Skill from remaining red orbs
                      (remaining_B * 2) + // Skill from remaining blue orbs
                      (green_orbs * 5);   // Skill from green orbs obtained

    // Output the maximum skill Chef can obtain.
    // The problem constraints (R, B <= 10) ensure that the total skill
    // will be small and fit comfortably within an 'int' data type.
    cout << total_skill << "\n";

    return 0; // Indicate successful execution of the program.
}