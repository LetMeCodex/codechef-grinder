#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions.
using namespace std; // Uses the standard namespace, as per problem instructions.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to avoid TLE (Time Limit Exceeded)
    // on problems with large inputs, as requested by the problem instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int N, X, Y, A, B;
        // Read the five space-separated integers for the current test case.
        // N: distance to travel
        // X: petrol cost per litre
        // Y: diesel cost per litre
        // A: distance per litre for petrol
        // B: distance per litre for diesel
        cin >> N >> X >> Y >> A >> B;

        // To minimize the total cost, Chef needs to choose the car with the lower cost per kilometer.
        // Cost per kilometer for petrol car = (Cost per litre of petrol) / (Distance per litre of petrol) = X / A
        // Cost per kilometer for diesel car = (Cost per litre of diesel) / (Distance per litre of diesel) = Y / B

        // We need to compare X/A and Y/B.
        // To avoid floating-point arithmetic and potential precision issues,
        // we can cross-multiply and compare the integer products:
        // X/A vs Y/B
        // This is equivalent to comparing X * B vs Y * A (since A and B are positive).
        // The total distance N is a common factor for both total costs (N * (X/A) vs N * (Y/B)),
        // so it cancels out in the comparison and does not affect the decision.

        // Calculate the "cost factor" for petrol and diesel.
        // These values represent the relative cost per kilometer.
        // Using long long for intermediate products, though int would suffice given constraints (100*100 = 10000).
        long long petrol_cost_factor = (long long)X * B;
        long long diesel_cost_factor = (long long)Y * A;

        // Compare the cost factors to determine which car is cheaper.
        if (petrol_cost_factor < diesel_cost_factor) {
            cout << "PETROL\n"; // Petrol car is cheaper.
        } else if (diesel_cost_factor < petrol_cost_factor) {
            cout << "DIESEL\n"; // Diesel car is cheaper.
        } else {
            cout << "ANY\n"; // Both cars have the same cost.
        }
    }

    return 0; // Indicate successful execution.
}