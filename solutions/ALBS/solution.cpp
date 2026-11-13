#include <cstdio> // For scanf and printf
#include <vector>   // For std::vector<char>

// No 'using namespace std;' to be explicit and avoid potential conflicts.

void solve() {
    int n;
    // Read N using scanf
    scanf("%d", &n);

    // Use std::vector<char> to store the string.
    // It's dynamically sized and handles memory safely.
    // +1 for the null terminator that scanf expects.
    std::vector<char> s_vec(n + 1); 
    // Read the binary string into the vector's underlying C-style array.
    scanf("%s", s_vec.data());

    int operations = 0;

    // Iterate from the second character (index 1 in 0-indexed string)
    // up to the last character.
    // We compare s_vec[i] with s_vec[i-1].
    for (int i = 1; i < n; ++i) {
        // If the current character is the same as the previous one,
        // an operation is required.
        if (s_vec[i] == s_vec[i-1]) {
            operations++;
        }
    }
    
    // Output the minimum number of operations using printf.
    printf("%d\n", operations);
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false) and cin.tie(NULL)
    // are not strictly necessary as they primarily optimize C++ streams.
    // However, including them doesn't hurt and might be useful if other C++ streams are used.
    // For this specific problem, they are not needed.
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int t;
    // Read the number of test cases using scanf.
    scanf("%d", &t); 
    while (t--) { // Loop through each test case.
        solve();
    }

    return 0;
}