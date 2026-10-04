#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the number of t-shirts Chef paid for.
    // The problem guarantees X is an even integer between 2 and 100.
    int X;

    // Read the value of X from standard input.
    cin >> X;

    // According to the problem statement, for every 2 t-shirts bought,
    // Chef receives a third one for free.
    // This means for every pair of t-shirts Chef paid for, he gets one free.
    // The number of pairs Chef paid for is X / 2.
    // Therefore, the number of free t-shirts Chef receives is X / 2.
    int free_tshirts = X / 2;

    // The total number of t-shirts Chef gets is the sum of t-shirts paid for
    // and the free t-shirts received.
    int total_tshirts = X + free_tshirts;

    // Output the total number of t-shirts Chef received, followed by a newline character.
    cout << total_tshirts << "\n";

    return 0; // Indicate successful execution of the program.
}