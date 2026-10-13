#include <iostream> // Required for standard input/output operations (cin, cout)
// #include <bits/stdc++.h> // A common header in competitive programming that includes most standard libraries.
// Using specific headers like <iostream> is generally better practice for clarity,
// but <bits/stdc++.h> is often allowed and used in contests.
// For this problem, <iostream> is sufficient.

// using namespace std; // This line is often used to avoid typing std:: repeatedly.
// Per problem instructions, it's allowed. I'll use std:: explicitly for clarity.

void solve() {
    int X, Y, Z;
    // Read the money Ashish has (X), cost of PIZZA (Y), and cost of BURGER (Z).
    std::cin >> X >> Y >> Z;

    // Ashish prefers PIZZA over BURGER.
    // First, check if he can afford a PIZZA.
    if (X >= Y) {
        // If he has enough money for PIZZA, he will eat PIZZA.
        std::cout << "PIZZA\n";
    } 
    // If he cannot afford PIZZA (i.e., X < Y), then check if he can afford a BURGER.
    else if (X >= Z) {
        // If he has enough money for BURGER (and couldn't afford PIZZA), he will eat BURGER.
        std::cout << "BURGER\n";
    } 
    // If he cannot afford PIZZA and also cannot afford BURGER, he eats nothing.
    else {
        std::cout << "NOTHING\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases.
    std::cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for the current test case.
    }

    return 0; // Indicate successful execution.
}