#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the number of people and treats.
    // Using 'long long' to safely handle potential integer overflow,
    // as per critical instructions, even though 'int' would suffice
    // for the given constraints (max total treats = 200,000).
    long long N, M; // N: people in "Bones", M: people in "Blood"
    long long X, Y; // X: treats per person in "Bones", Y: treats per person in "Blood"

    // Read the number of people in "Bones" (N) and "Blood" (M).
    cin >> N >> M;

    // Read the number of treats per person in "Bones" (X) and "Blood" (Y).
    cin >> X >> Y;

    // Calculate the total treats from "Bones" and "Blood" sectors.
    // Total treats from "Bones" = N * X
    // Total treats from "Blood" = M * Y
    // Total treats = (N * X) + (M * Y)
    long long total_treats = (N * X) + (M * Y);

    // Output the total number of treats Suri Bhai will receive, followed by a newline.
    cout << total_treats << "\n";

    return 0;
}