#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    // The problem statement implies a single test case,
    // but the template suggests handling multiple test cases.
    // Based on the problem constraints and typical CodeChef format,
    // it's likely a single test case. If multiple were intended,
    // the problem statement would usually specify the number of test cases.
    // However, to be safe and adhere to the template, we'll assume
    // the possibility of multiple test cases, although the provided
    // examples and constraints don't necessitate it.
    // If it were truly multiple test cases, the input format would
    // typically start with an integer 't' indicating the number of test cases.
    // Since it's not, we'll process the single input 'x' directly.

    // The phone model is named 'K' followed by the last two digits of the year X.
    // We can get the last two digits of X by taking X modulo 100.
    int last_two_digits = x % 100;

    // We need to print the last two digits, ensuring leading zeros are preserved.
    // For example, if X is 2000, last_two_digits will be 0. We need to print "00".
    // If X is 2005, last_two_digits will be 5. We need to print "05".
    // The `std::cout` stream with `std::setw` and `std::setfill` can handle this.
    cout << "K";
    cout << setw(2) << setfill('0') << last_two_digits << "\n";

    return 0;
}