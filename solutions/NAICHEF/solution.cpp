#include <iostream>
#include <vector>
#include <iomanip>

// Using namespace std; is common in competitive programming to avoid typing std:: repeatedly.
using namespace std;

void solve() {
    int N;
    long long A, B; // Using long long for A and B just in case, though constraints say N, A, B <= N
    cin >> N >> A >> B;

    int countA = 0; // Counter for occurrences of number A on die faces
    int countB = 0; // Counter for occurrences of number B on die faces

    // Loop N times to read each number written on the faces of the die.
    for (int i = 0; i < N; ++i) {
        int x; // x_i <= N, so int is fine.
        cin >> x; // Read the current face number
        
        // Check if the current face number matches A
        if (x == A) {
            countA++;
        }
        // Check if the current face number matches B
        // This is an independent check, as A and B can be the same number.
        if (x == B) {
            countB++;
        }
    }

    // Calculate the probability of getting A on the first toss.
    // static_cast<double> is used to ensure floating-point division.
    double probA = static_cast<double>(countA) / N;
    
    // Calculate the probability of getting B on the second toss.
    double probB = static_cast<double>(countB) / N;

    // Since the tosses are mutually independent, the total probability of winning
    // is the product of the individual probabilities.
    double total_probability = probA * probB;

    // Print the result.
    // std::fixed ensures that the number is printed in fixed-point notation (not scientific).
    // std::setprecision(10) sets the number of digits after the decimal point to 10,
    // which is sufficient for the required absolute error of 10^-6.
    cout << fixed << setprecision(10) << total_probability << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further optimizing I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}