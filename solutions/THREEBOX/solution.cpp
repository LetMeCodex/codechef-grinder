#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B, C, D; // Variables to store box sizes A, B, C and bag size D
        cin >> A >> B >> C >> D; // Read the four integers for the current test case

        // Logic to determine the minimum number of bags:

        // 1. Check if all three boxes can fit into a single bag.
        // This is possible if the sum of their sizes (A + B + C) does not exceed the bag size D.
        if (A + B + C <= D) {
            cout << 1 << "\n"; // If they fit, only 1 bag is needed.
        }
        // 2. If all three boxes cannot fit into one bag (i.e., A + B + C > D),
        // check if two boxes can fit into one bag, with the third box in another bag.
        // Since A <= B <= C, the smallest sum of two boxes is A + B.
        // If A + B fits into a bag, we can use 2 bags: one for (A+B) and one for (C).
        // (Box C will always fit alone because C <= D is given).
        else if (A + B <= D) {
            cout << 2 << "\n"; // If A and B fit together, 2 bags are needed.
        }
        // 3. If neither of the above conditions is met, it means:
        //    - A + B + C > D (cannot fit all three in one bag)
        //    - A + B > D (cannot fit even the two smallest boxes together in one bag)
        // In this scenario, no two boxes can be combined into a single bag.
        // Therefore, each box must go into its own separate bag.
        else {
            cout << 3 << "\n"; // Each box needs its own bag, so 3 bags are needed.
        }
    }

    return 0; // Indicate successful execution
}