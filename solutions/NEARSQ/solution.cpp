#include <bits/stdc++.h> // Includes iostream, cmath, etc.
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Calculate the integer part of the square root of N.
    // The sqrt function returns a double. Casting to int truncates the decimal part,
    // effectively performing the floor operation for positive numbers.
    // For example:
    // if N=10, sqrt(10) is approx 3.16. static_cast<int>(3.16) gives 3.
    // if N=9, sqrt(9) is 3.0. static_cast<int>(3.0) gives 3.
    int B = static_cast<int>(sqrt(N));
    
    // The largest square less than or equal to N is B*B.
    // This is because B is the largest integer such that B*B <= N.
    // (B+1)*(B+1) would be greater than N.
    cout << B * B << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful program execution
}