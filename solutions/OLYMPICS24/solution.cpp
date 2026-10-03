#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and prevents flushing
    // operations that can slow down execution, especially for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the number of gold, silver,
    // and bronze medals won by Chefland, respectively.
    int G, S, B;

    // Read the three space-separated integers from the standard input.
    // These represent the current counts of gold, silver, and bronze medals.
    cin >> G >> S >> B;

    // Chef will be happy only if the team wins 5 medals of each type.
    // We need to calculate the additional medals required for each type.
    // Since the constraints state 1 <= G, S, B <= 5, the current medal counts
    // will never exceed the target of 5.
    // Therefore, the number of additional medals needed for a type is simply
    // 5 minus the current count for that type.

    // Calculate additional gold medals needed.
    // If G is 5, needed_gold will be 0. If G is less than 5, it will be 5 - G.
    int needed_gold = 5 - G;

    // Calculate additional silver medals needed.
    // If S is 5, needed_silver will be 0. If S is less than 5, it will be 5 - S.
    int needed_silver = 5 - S;

    // Calculate additional bronze medals needed.
    // If B is 5, needed_bronze will be 0. If B is less than 5, it will be 5 - B.
    int needed_bronze = 5 - B;

    // The total number of additional medals needed is the sum of additional
    // gold, silver, and bronze medals.
    int total_needed_medals = needed_gold + needed_silver + needed_bronze;

    // Output the calculated total number of additional medals to the standard output,
    // followed by a newline character as required.
    cout << total_needed_medals << "\n";

    // Indicate successful program execution.
    return 0;
}