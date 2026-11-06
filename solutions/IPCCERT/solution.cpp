#include <bits/stdc++.h> // Includes iostream and many other useful libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    // Read the number of students (N), the minimum required total lecture minutes (M),
    // and the number of lectures (K) from the first line of input.
    cin >> N >> M >> K;

    int eligible_students_count = 0; // Initialize a counter for students who meet the certificate criteria.

    // Loop through each of the N students.
    for (int i = 0; i < N; ++i) {
        long long total_lecture_minutes = 0; // Variable to store the total minutes watched by the current student.
                                            // Using 'long long' to be safe against potential overflow,
                                            // although 'int' would be sufficient given the problem constraints
                                            // (max sum: 1000 lectures * 1000 min/lecture = 10^6 minutes).
        
        // Loop through each of the K lectures for the current student.
        // Read the minutes watched for each lecture and add it to the total.
        for (int j = 0; j < K; ++j) {
            int T_ij; // Minutes watched for the j-th lecture by the i-th student.
            cin >> T_ij;
            total_lecture_minutes += T_ij; // Accumulate the minutes.
        }

        int Q_i; // Number of times the current student asked the question.
        cin >> Q_i;

        // Check if the current student meets both criteria for receiving a certificate:
        // 1. The total lecture minutes watched must be at least M.
        // 2. The number of questions asked must be no more than 10.
        if (total_lecture_minutes >= M && Q_i <= 10) {
            eligible_students_count++; // If both criteria are met, increment the counter.
        }
    }

    // Print the final count of eligible participants to standard output, followed by a newline.
    cout << eligible_students_count << "\n";

    return 0; // Indicate successful program execution.
}