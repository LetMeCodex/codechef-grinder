#include <cstdio>   // For scanf, printf
#include <string>   // For std::string (though we'll use char array for S)

// Function to solve a single test case
void solve() {
    int N;
    scanf("%d", &N); // Read the length of the queue

    // Using a char array for S to potentially reduce overhead compared to std::string
    // N can be up to 10, so N+1 for the null terminator is sufficient.
    char S[11]; 
    scanf("%s", S); // Read the queue string

    int boys_count = 0;      // Counter for boys who have entered
    int girls_count = 0;     // Counter for girls who have entered
    int people_entered = 0;  // Total people who have entered

    // Iterate through the queue from the front (index 0) to the back
    for (int i = 0; i < N; ++i) {
        // A person enters the bar
        if (S[i] == 'B') {
            boys_count++;
        } else { // S[i] == 'G'
            girls_count++;
        }
        people_entered++; // Increment the total count of people who entered

        // Check the security condition immediately after this person enters
        // The condition is: number of boys > twice the number of girls
        if (boys_count > 2 * girls_count) {
            // If the condition is met, the security closes the entrance.
            // The current 'people_entered' count is the answer for this test case.
            printf("%d\n", people_entered);
            return; // Exit the function for this test case
        }
    }

    // If the loop completes, it means all N people in the queue were allowed to enter
    // without the security condition ever being met.
    // In this case, 'people_entered' would have naturally reached N.
    printf("%d\n", N);
}

int main() {
    // No need for ios_base::sync_with_stdio(false); cin.tie(NULL); with scanf/printf

    int T;
    scanf("%d", &T); // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}