#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for string manipulation
#include <vector>   // Not strictly needed for this problem, but often included with <bits/stdc++.h>
#include <algorithm> // Not strictly needed for this problem, but often included with <bits/stdc++.h>

// For competitive programming, it's common to include <bits/stdc++.h>
// which pulls in many standard library headers.
// #include <bits/stdc++.h> 

void solve() {
    int N;
    std::cin >> N; // Read the number of gestures
    std::string s;
    std::cin >> s; // Read the string of gestures

    bool found_I = false; // Flag to track if an 'I' gesture is found
    bool found_Y = false; // Flag to track if a 'Y' gesture is found

    // Iterate through each character in the gesture string
    for (char c : s) {
        if (c == 'I') {
            found_I = true; // Set flag if 'I' is found
        } else if (c == 'Y') {
            found_Y = true; // Set flag if 'Y' is found
        }
        // 'N' gestures do not change the flags, so no specific action is needed for 'N'.
    }

    // Apply the logic based on the flags
    if (found_I) {
        // If an 'I' gesture was found, the person must be INDIAN.
        std::cout << "INDIAN\n";
    } else if (found_Y) {
        // If no 'I' gesture was found, but a 'Y' gesture was found,
        // the person must be NOT INDIAN (foreigner).
        std::cout << "NOT INDIAN\n";
    } else {
        // If neither 'I' nor 'Y' gestures were found, it means only 'N' gestures were made.
        // In this case, we cannot be sure.
        std::cout << "NOT SURE\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}