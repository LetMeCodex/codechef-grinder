#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, algorithm, etc.
using namespace std;     // Required namespace for competitive programming

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables for the prices.
    // X: price of one bucket of popcorn
    // Y: price of one drink
    // Z: price of one combo (one popcorn + one drink)
    int X, Y, Z;

    // Read the three prices from standard input.
    cin >> X >> Y >> Z;

    // Chef needs to buy 2 buckets of popcorn and 3 drinks.
    // This requirement can be broken down into:
    // (1 popcorn + 1 drink)
    // + (1 popcorn + 1 drink)
    // + (1 drink)

    // First, determine the most cost-effective way to acquire one popcorn and one drink.
    // This can be achieved either by buying them individually (cost X + Y)
    // or by buying a combo offer (cost Z).
    // We choose the minimum of these two options.
    int effective_cost_for_one_popcorn_and_one_drink = min(X + Y, Z);

    // Now, calculate the total minimum cost.
    // We need two sets of (1 popcorn + 1 drink), so that's 2 times the effective cost.
    // We also need one additional drink, which costs Y.
    int minimum_total_cost = 2 * effective_cost_for_one_popcorn_and_one_drink + Y;

    // Print the calculated minimum total cost to standard output, followed by a newline.
    cout << minimum_total_cost << "\n";

    // Indicate successful program execution.
    return 0;
}