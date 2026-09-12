#include <bits/stdc++.h> // Includes all standard libraries for convenience

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int X; // Declare an integer variable X to store Chef's age.
        cin >> X; // Read Chef's age for the current test case.

        // Chef's current age is 20, and Chefina's current age is 10.
        // This means Chef is 20 - 10 = 10 years older than Chefina.
        // Since their age difference remains constant, when Chef is X years old,
        // Chefina will be X - 10 years old.
        int chefina_age = X - 10;

        // Output Chefina's calculated age, followed by a newline character.
        // The newline character ensures each output is on a separate line as required.
        cout << chefina_age << "\n";
    }

    return 0; // Indicate successful program execution.
}