#include <iostream> // For cin, cout
#include <string>   // For string, getline
#include <sstream>  // For stringstream
#include <limits>   // For numeric_limits (used with cin.ignore)

// It's common in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::.
using namespace std;

// Function to solve a single test case
void solve() {
    string S;
    // Read the entire line for the quote, including spaces.
    // This is crucial because quotes can contain spaces.
    getline(cin, S);

    // Use stringstream to easily tokenize the string into words.
    // This is generally a safer and often cleaner approach for word-based problems
    // compared to manual character-by-character parsing, as it handles
    // multiple spaces, leading/trailing spaces, etc., automatically.
    stringstream ss(S);
    string word;
    bool found_not_word = false;

    // Extract words one by one from the stringstream
    while (ss >> word) {
        if (word == "not") {
            found_not_word = true;
            break; // Found the word "not", no need to check further.
        }
    }

    // Print the result based on whether "not" was found as a word.
    if (found_not_word) {
        cout << "Real Fancy\n";
    } else {
        cout << "regularly fancy\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // After reading an integer with cin >> T, a newline character remains in the input buffer.
    // The subsequent getline(cin, S) would read this empty line for the first test case.
    // cin.ignore() discards this leftover newline character.
    // Using the version with arguments is safer to clear the entire line,
    // ensuring no unexpected characters remain for subsequent getline calls.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Loop through each test case.
    while (T--) {
        solve();
    }

    return 0;
}