#include <iostream> // Using iostream for basic input/output

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables 'A' and 'B' for silver and gold coins.
    int A, B;
    // Read the values of A and B from standard input.
    // Assuming a single test case as 't' is not explicitly mentioned in the problem statement.
    cin >> A >> B;

    // Calculate the total number of silver coins Chef can obtain.
    // Chef starts with 'A' silver coins.
    // Each 'B' gold coin can be traded for 2 silver coins,
    // so 'B' gold coins yield 'B * 2' silver coins.
    // Total silver coins = initial silver coins + silver coins from gold trades.
    int total_silver_coins = A + (B * 2);

    // Since each silver coin sells for Rs. 1, the total money earned
    // is simply the total number of silver coins.
    // Output the total money earned, followed by a newline.
    cout << total_silver_coins << "\n";

    return 0; // Indicate successful program execution.
}