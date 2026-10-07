#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement

// Use the standard namespace, as requested by the problem statement
using namespace std;

int main() {
    // Include fast I/O inside main(), as requested by the problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the dimensions of the cuboid (A, B, C)
    // and the edge length of the cube (X).
    // The constraints are 1 <= A,B,C,X <= 10.
    // The maximum possible volume for either object is 10*10*10 = 1000.
    // An 'int' type is sufficient to store these values without overflow.
    // However, to strictly adhere to the critical instruction "integer overflow (use long long in C++)",
    // we use 'long long' for variables that store dimensions and volumes.
    long long A, B, C, X;

    // Read the input values using cin, as requested
    cin >> A >> B >> C >> X;

    // Calculate the volume of the cuboid
    long long volume_cuboid = A * B * C;

    // Calculate the volume of the cube
    long long volume_cube = X * X * X;

    // Compare the volumes and print the result using cout << ... << "\n", as requested
    if (volume_cuboid > volume_cube) {
        cout << "Cuboid\n";
    } else if (volume_cube > volume_cuboid) {
        cout << "Cube\n";
    } else {
        cout << "Equal\n";
    }

    // The problem statement's input format description ("The first and only line of input will contain four space-separated integers A, B, C and X")
    // indicates a single test case. The general instruction "Handle multiple test cases (e.g. int t; cin >> t; while(t--)) properly as requested by the problem statement"
    // is likely boilerplate. Based on the specific input format, this solution processes a single set of inputs.

    return 0;
}