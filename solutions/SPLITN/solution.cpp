#include <iostream> // Required for standard input/output operations (cin, cout)

// Using namespace std; is common in competitive programming to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n;
        cin >> n; // Read the integer N for the current test case

        // The problem asks for the minimum number of operations to break N into powers of 2.
        // Each operation takes one number X and breaks it into two parts Y and Z (X = Y + Z).
        // This means each operation increases the total count of numbers we have by one.
        //
        // We want to express N as a sum of powers of 2. The unique way to do this with distinct powers of 2
        // is given by N's binary representation. For example, if N = 13 (binary 1101),
        // it's 2^3 + 2^2 + 2^0 = 8 + 4 + 1.
        // Here, we need to obtain 3 distinct powers of 2 (8, 4, 1).
        //
        // Initially, we have 1 number (N).
        // We want to end up with 'k' numbers, where 'k' is the count of set bits in N's binary representation.
        // Since each operation increases the number of parts by 1, to go from 1 part to 'k' parts,
        // we need exactly 'k - 1' operations.
        //
        // __builtin_popcount(n) is a GCC extension that efficiently counts the number of set bits (1s)
        // in the binary representation of an integer 'n'.
        int set_bits = __builtin_popcount(n);

        // The minimum number of operations is (number of set bits) - 1.
        cout << set_bits - 1 << "\n";
    }

    return 0; // Indicate successful execution
}