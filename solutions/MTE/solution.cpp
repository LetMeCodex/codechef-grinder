#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the size of the array

    int count_odd = 0;  // Counter for odd numbers
    int count_even = 0; // Counter for even numbers

    // Iterate through the array elements to count parities
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a; // Read an element
        if (a % 2 == 0) {
            count_even++; // Increment even count if element is even
        } else {
            count_odd++;  // Increment odd count if element is odd
        }
    }

    // If all elements are already of the same parity, 0 operations are needed.
    // This means either there are no odd numbers (all even) or no even numbers (all odd).
    if (count_odd == 0 || count_even == 0) {
        cout << 0 << "\n";
    } else {
        // The parity of the count of odd numbers (count_odd) is an invariant.
        // This means if count_odd is initially odd, it will always remain odd.
        // If count_odd is initially even, it will always remain even.

        // Case 1: Initial count_odd is odd.
        // Since count_odd must always be odd, we can never reach a state where count_odd = 0 (which is an even number).
        // Therefore, we cannot make all elements even.
        // We must make all elements odd. This means we need to eliminate all even numbers.
        // The only operation that reduces the count of even numbers is (even + odd -> odd).
        // Each such operation reduces count_even by 1.
        // We need to perform 'count_even' such operations to eliminate all even numbers.
        // This is always possible because count_odd is odd, meaning count_odd >= 1, so there's always an odd number to pair with an even number.
        if (count_odd % 2 == 1) { // count_odd is odd
            cout << count_even << "\n";
        } 
        // Case 2: Initial count_odd is even.
        // Since count_odd must always be even, we can potentially reach count_odd = 0 (all even).
        // We can also potentially reach count_even = 0 (all odd).
        // We need to find the minimum operations for these two possibilities.
        else { // count_odd is even
            // Option A: Make all elements even (target count_odd = 0).
            // To do this, we pair up odd numbers: (odd + odd -> even).
            // Each such operation reduces count_odd by 2.
            // Since count_odd is even, we can form count_odd / 2 pairs.
            // This takes count_odd / 2 operations.
            int ops_to_all_even = count_odd / 2;

            // Option B: Make all elements odd (target count_even = 0).
            // To do this, we pair up even and odd numbers: (even + odd -> odd).
            // Each such operation reduces count_even by 1.
            // We need to perform 'count_even' such operations to eliminate all even numbers.
            int ops_to_all_odd = count_even;
            
            // The minimum operations is the smaller of these two options.
            cout << min(ops_to_all_even, ops_to_all_odd) << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}