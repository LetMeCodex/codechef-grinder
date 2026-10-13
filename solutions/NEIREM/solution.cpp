#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // Read the number of neighborhoods Chef has already visited

    // Calculate the number of neighborhoods Chef still needs to visit
    // Total neighborhoods are 100.
    // Chef has visited N.
    // Remaining = Total - Visited
    int remaining_neighborhoods = 100 - N;

    cout << remaining_neighborhoods << "\n"; // Print the result

    return 0;
}