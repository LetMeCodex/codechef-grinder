#include <cstdio> // For standard input/output operations using printf and scanf

int main() {
    int T; // Declare variable for the number of test cases
    scanf("%d", &T); // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Declare variable for the amount owed to the driver
        scanf("%d", &X); // Read the amount owed

        // Calculate the total amount the driver owes back to you.
        // You paid 100 dollars, and you owe X dollars.
        int amount_driver_owes_back = 100 - X;

        // The driver can only give back change in 10 dollar bills.
        // To find the maximum amount the driver can give back without exceeding
        // 'amount_driver_owes_back', we find the largest multiple of 10
        // that is less than or equal to 'amount_driver_owes_back'.
        // This is done by integer division by 10 (to get the number of 10-dollar bills)
        // and then multiplying by 10 again (to get the total amount).
        int max_change = (amount_driver_owes_back / 10) * 10;

        // Output the calculated maximum change, followed by a newline character.
        printf("%d\n", max_change);
    }

    return 0; // Indicate successful program execution
}