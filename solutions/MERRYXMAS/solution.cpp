#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the available hours.
    cin >> X; // Read the value of X from standard input.

    int activities_completed = 0; // Initialize a counter for completed activities.

    // To maximize the number of activities, Chef should always choose the activities
    // that take the least amount of time first. This greedy approach ensures that
    // more time is left for subsequent activities.
    // The activity durations are: 1 hour, 2 hours, and 4 hours.
    // We process them in increasing order of duration: 1, then 2, then 4.

    // Try to complete the 1-hour activity (Decorating a Christmas tree).
    // If Chef has at least 1 hour remaining, he can do this activity.
    if (X >= 1) {
        X -= 1; // Deduct the time taken for this activity from the available hours.
        activities_completed++; // Increment the count of completed activities.
    }

    // Try to complete the 2-hour activity (Baking cookies).
    // If Chef has at least 2 hours remaining after potentially completing the 1-hour activity,
    // he can do this activity.
    if (X >= 2) {
        X -= 2; // Deduct the time taken for this activity.
        activities_completed++; // Increment the count of completed activities.
    }

    // Try to complete the 4-hour activity (Making a gingerbread house).
    // If Chef has at least 4 hours remaining after potentially completing the 1-hour and 2-hour activities,
    // he can do this activity.
    if (X >= 4) {
        X -= 4; // Deduct the time taken for this activity.
        activities_completed++; // Increment the count of completed activities.
    }

    // Output the maximum number of activities Chef can complete.
    cout << activities_completed << "\n";

    return 0; // Indicate successful execution.
}