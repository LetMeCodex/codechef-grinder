#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested.
    // This unties cin/cout from the C standard streams and disables synchronization,
    // which is crucial for competitive programming problems with large inputs/outputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the number of integers in the list.
    cin >> N;

    // The problem constraints state that elements of the list are between 0 and 10^6 (inclusive).
    // We will use Counting Sort, which is highly efficient when the range of input values (K)
    // is not significantly larger than the number of elements (N).
    // Here, N <= 10^6 and K <= 10^6, making Counting Sort an optimal choice.

    // Create a frequency array (vector in C++) to store the counts of each number.
    // The size needs to be `max_value + 1` to accommodate values from 0 up to `max_value`.
    // Since max_value is 10^6, the size is 1000001.
    // All elements are initialized to 0.
    // This vector will use approximately 4MB of memory (10^6 * 4 bytes), which is well within typical memory limits.
    vector<int> counts(1000001, 0); 

    // Read N numbers from the input and populate the frequency array.
    // For each number read, increment its corresponding count in the 'counts' vector.
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        counts[num]++; // Increment the count for the number 'num'.
    }

    // Iterate through the frequency array from the smallest possible value (0)
    // up to the largest possible value (10^6).
    // For each number 'i', print it 'counts[i]' times.
    // This naturally outputs the numbers in non-decreasing order.
    for (int i = 0; i <= 1000000; ++i) {
        // The inner loop runs 'counts[i]' times.
        // If counts[i] is 0, this loop doesn't run, and nothing is printed for 'i'.
        for (int j = 0; j < counts[i]; ++j) {
            cout << i << "\n"; // Print the number 'i' followed by a newline.
        }
    }

    return 0; // Indicate successful execution of the program.
}