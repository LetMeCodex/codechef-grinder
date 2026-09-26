#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std; // Use standard namespace

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read N (number of problems). N is not directly used in the calculation,
                  // but it's part of the input format.

        int NA, NB, NC, ND;
        cin >> NA >> NB >> NC >> ND; // Read the counts of problems for each option

        // The maximum marks Chef can guarantee is the maximum among NA, NB, NC, and ND.
        // This is because Chef's optimal strategy to guarantee marks is to mark all problems
        // with the single option that has the highest count.
        // For example, if NA is the highest count, Chef marks all N problems as 'A'.
        // Since there are exactly NA problems whose correct answer is 'A', Chef will correctly
        // answer all NA of them, thus guaranteeing NA marks. This score is guaranteed
        // irrespective of which specific problems have 'A' as the answer.
        // Any other strategy (e.g., marking different problems with different options)
        // would allow an adversary to arrange the correct answers in a way that minimizes
        // Chef's score, potentially leading to a lower guaranteed score.
        int max_guaranteed_score = max({NA, NB, NC, ND});

        cout << max_guaranteed_score << "\n"; // Output the result for the current test case
    }

    return 0;
}