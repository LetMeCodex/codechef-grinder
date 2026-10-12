#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming
using namespace std;     // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases

    while (t--) { // Loop through each testcase
        int n, k;
        cin >> n >> k; // Read N (total track length) and K (max speed stretch length)

        vector<int> a(n); // Declare a vector of size N to store girl counts per kilometre
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Read the number of girls for each kilometre
        }

        int current_window_sum = 0;
        // Calculate the sum of girls in the first K kilometres (initial window)
        // This covers the window from index 0 to K-1
        for (int i = 0; i < k; ++i) {
            current_window_sum += a[i];
        }

        int max_girls_impressed = current_window_sum; // Initialize max_girls_impressed with the first window's sum

        // Slide the window across the track
        // The loop starts from 'i = k'. In each iteration:
        // 'a[i]' is the new element entering the window (rightmost element of the new window).
        // 'a[i - k]' is the element leaving the window (leftmost element of the previous window).
        for (int i = k; i < n; ++i) {
            // Update the current window sum:
            // Subtract the element that is leaving the window (a[i-k])
            // Add the element that is entering the window (a[i])
            current_window_sum = current_window_sum - a[i - k] + a[i];
            
            // Update the maximum sum found so far if the current window sum is greater
            max_girls_impressed = max(max_girls_impressed, current_window_sum);
        }

        // Print the maximum number of girls Vishal can impress for the current testcase
        // Follows the output format: one integer per line.
        cout << max_girls_impressed << "\n";
    }

    return 0; // Indicate successful execution
}