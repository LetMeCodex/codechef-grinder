#include <bits/stdc++.h> 

// Using namespace std; is common in competitive programming
// and requested by the problem statement.
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array A.

    int count_odd = 0;  // Counter for odd numbers in the array.
    int count_even = 0; // Counter for even numbers in the array.

    // Iterate through the array elements to count odd and even numbers.
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element A_i.
        if (A_i % 2 == 0) {
            // If A_i is even, increment count_even.
            count_even++;
        } else {
            // If A_i is odd, increment count_odd.
            count_odd++;
        }
    }

    // Determine the minimum number of operations based on the counts.
    // Case 1: All elements are already odd (count_even is 0).
    // Case 2: All elements are already even (count_odd is 0).
    // In both these cases, the array already has elements of the same parity.
    // So, zero operations are needed.
    if (count_odd == 0 || count_even == 0) {
        cout << 0 << "\n";
    } else {
        // Case 3: The array contains a mix of odd and even numbers.
        // We need to make all elements have the same parity.
        //
        // It's impossible to make all elements even if there's at least one odd number,
        // because splitting an odd number always results in one odd and one even number.
        // So, an odd number will always persist in some form.
        //
        // The only option is to make all elements odd.
        // Each even number A_i (where A_i >= 2) can be split into two positive odd integers
        // (e.g., 1 and A_i-1). This takes 1 operation per even number.
        // After this operation, one even number is replaced by two odd numbers.
        // We need to perform this operation for every even number in the array.
        // The total number of operations will be equal to count_even.
        // The problem guarantees that parity can be made equal, so this strategy must work.
        cout << count_even << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}