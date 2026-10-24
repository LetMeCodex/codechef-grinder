#include <cstdio> // Required for scanf and printf

int main() {
    // When using scanf/printf, the C++ stream optimizations are not applicable
    // and should be omitted to avoid potential conflicts or unnecessary overhead.
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int N; // Declare an integer variable N to store the number of elements
    // Read the value of N using scanf
    scanf("%d", &N);

    int max_length = 0; // Initialize max_length to 0. This will store the maximum length of a subarray with non-zero product.
    int current_length = 0; // Initialize current_length to 0. This will store the length of the current consecutive subarray of non-zero elements.

    // Loop through N elements of the array
    for (int i = 0; i < N; ++i) {
        int element; // Declare an integer variable to store the current element
        // Read the current element using scanf
        scanf("%d", &element);

        if (element != 0) {
            // If the current element is non-zero, it contributes to the current non-zero subarray.
            // Increment current_length.
            current_length++;
        } else {
            // If the current element is zero, it breaks any ongoing non-zero subarray.
            // First, update max_length with the length of the non-zero subarray that just ended.
            // Using an if statement for max is equivalent to std::max and avoids including <algorithm>.
            if (current_length > max_length) {
                max_length = current_length;
            }
            // Then, reset current_length to 0, as a new non-zero subarray must start after this zero.
            current_length = 0;
        }
    }

    // After the loop finishes, there might be a non-zero subarray ending at the very last element of the array.
    // This final check ensures that such a subarray's length is considered.
    if (current_length > max_length) {
        max_length = current_length;
    }

    // Print the final maximum length followed by a newline character using printf.
    printf("%d\n", max_length);

    return 0; // Indicate successful program execution
}