#include <iostream> // Required for cin, cout
#include <set>      // For std::set to store unique sorted elements

// Using namespace std; is requested by the problem instructions.
using namespace std;

int main() {
    // Fast I/O is requested by the problem instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description and sample inputs indicate a single test case.
    // No 'T' for the number of test cases is provided in the problem statement or sample.

    int N;
    cin >> N; // Read the number of elements

    set<int> distinct_elements; // Use a set to automatically store unique elements in sorted order
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        distinct_elements.insert(A_i); // Insert into the set
    }

    // After inserting all elements, 'distinct_elements' will contain
    // all unique values from the input array A, sorted in ascending order.

    // Case 1: If there is only one distinct element in the array.
    // This implies all elements A_i are identical (e.g., {5, 5, 5}).
    // In this case, A_i % A_j will always be A_1 % A_1 = 0.
    // The problem states N >= 2, so distinct_elements.size() will be at least 1.
    if (distinct_elements.size() == 1) {
        cout << 0 << "\n";
    } else {
        // Case 2: If there are at least two distinct elements.
        // The maximum value of A_i % A_j is the second largest distinct element.
        // This is proven in the detailed explanation above.

        // To get the second largest distinct element from a sorted set:
        // std::set::rbegin() returns a reverse iterator pointing to the largest element.
        // Incrementing this reverse iterator (it++) moves it to the next element in reverse order,
        // which is the second largest element.
        auto it = distinct_elements.rbegin(); // 'it' points to the largest element (M1)
        ++it;                                 // 'it' now points to the second largest element (M2)
        cout << *it << "\n";                  // Dereference to get the value of M2
    }

    return 0; // Indicate successful execution
}