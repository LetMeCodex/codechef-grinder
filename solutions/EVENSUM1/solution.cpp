#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int total_sum = 0;
    int even_count = 0;
    int odd_count = 0;

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element

        total_sum += A_i; // Add to total sum

        // Check parity of the current element
        if (A_i % 2 == 0) {
            even_count++; // Increment count of even numbers
        } else {
            odd_count++;  // Increment count of odd numbers
        }
    }

    // Determine if a suitable element can be removed
    // We want (total_sum - A_i) to be even.
    // This happens if total_sum and A_i have the same parity.

    if (total_sum % 2 == 0) {
        // If the total sum is even, we need to remove an even number.
        // This is possible if there is at least one even number in the array.
        if (even_count > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        // If the total sum is odd, we need to remove an odd number.
        // This is possible if there is at least one odd number in the array.
        if (odd_count > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}