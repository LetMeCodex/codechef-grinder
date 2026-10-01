#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <numeric>  // Not strictly needed if using a manual loop, but useful for std::count

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the strings
    std::string a, b;
    std::cin >> a >> b; // Read the binary strings A and B

    // Count the number of '1's in string A
    int countA_ones = 0;
    for (char c : a) {
        if (c == '1') {
            countA_ones++;
        }
    }

    // Count the number of '1's in string B
    int countB_ones = 0;
    for (char c : b) {
        if (c == '1') {
            countB_ones++;
        }
    }

    // The core logic:
    // We can reverse any substring of length X, where X is a prime number.
    // Since 2 is a prime number, we can choose X=2.
    // Reversing a substring of length 2 (e.g., A[i]A[i+1]) effectively swaps
    // the two adjacent characters (A[i+1]A[i]).
    // The ability to swap any two adjacent characters means we can achieve any
    // permutation of the string's characters. This is a fundamental property
    // of permutations (e.g., bubble sort uses adjacent swaps to sort).
    //
    // Therefore, if string A can be transformed into string B, they must have
    // the same multiset of characters. Since these are binary strings, this
    // simply means they must have the same count of '0's and the same count of '1's.
    // If the count of '1's in A is equal to the count of '1's in B, then
    // the count of '0's must also be equal (since total length N is the same).
    // In this scenario, we can always rearrange the characters of A to match B.
    // If the counts of '1's differ, it's impossible to make them equal, as
    // reversing a substring does not change the counts of characters within it,
    // and thus does not change the total counts in the string.
    if (countA_ones == countB_ones) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}