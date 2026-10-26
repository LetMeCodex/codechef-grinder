#include <bits/stdc++.h> // Required by problem statement

// Use standard namespace as requested
using namespace std;

// Function to count the total number of divisors for a given number.
// This function works for num >= 1.
int count_divisors(int num) {
    int count = 0;
    // Iterate from 1 up to the square root of num.
    // Using i * i <= num avoids floating-point operations and potential precision issues
    // compared to i <= sqrt(num).
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            // If i*i == num, then i is the square root of num.
            // In this case, i and num/i are the same divisor (e.g., for num=9, i=3, num/i=3).
            // So, we count it only once.
            if (i * i == num) {
                count++;
            } else {
                // Otherwise, i and num/i are two distinct divisors (e.g., for num=12, i=2, num/i=6).
                // So, we count both.
                count += 2;
            }
        }
    }
    return count;
}

// Function to solve a single test case.
void solve() {
    int N;
    cin >> N; // Read the integer N for the current test case.

    int temp_N = N;
    // Find the largest odd divisor of N.
    // This is done by repeatedly dividing N by 2 until it becomes an odd number.
    // For example:
    // If N = 12: temp_N = 12 -> 6 -> 3. The largest odd divisor is 3.
    // If N = 8: temp_N = 8 -> 4 -> 2 -> 1. The largest odd divisor is 1.
    // If N = 3: temp_N = 3. The largest odd divisor is 3.
    while (temp_N % 2 == 0) { 
        temp_N /= 2;
    }
    // The number of odd divisors of N is equal to the total number of divisors
    // of its largest odd divisor (temp_N).
    int odd_divisors_count = count_divisors(temp_N);
    
    // Calculate the total number of divisors for the original N.
    int total_divisors_count = count_divisors(N);
    
    // The number of even divisors is the total number of divisors minus the number of odd divisors.
    int even_divisors_count = total_divisors_count - odd_divisors_count;

    // Output the results in the required format: odd_divisors_count followed by even_divisors_count.
    cout << odd_divisors_count << " " << even_divisors_count << "\n";
}

int main() {
    // Enable fast I/O operations as requested.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times, calling solve() for each test case.
        solve();
    }

    return 0;
}