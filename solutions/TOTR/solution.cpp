#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string
#include <cctype>   // For std::islower, std::isupper, std::toupper

// As requested by the problem statement, use `using namespace std;`
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;          // Number of Bytelandian sentences to translate
    string M;       // The mapping string: English translation of "abcdefghijklmnopqrstuvwxyz"
    
    // Read T and the mapping string M from the first line of input.
    cin >> T >> M;

    // Create a character array to store the translation map.
    // translation_map[0] will store the English equivalent of Bytelandian 'a',
    // translation_map[1] for 'b', and so on, up to translation_map[25] for 'z'.
    char translation_map[26];
    for (int i = 0; i < 26; ++i) {
        translation_map[i] = M[i];
    }

    // Loop T times to process each Bytelandian sentence.
    for (int t_case = 0; t_case < T; ++t_case) {
        string S; // The current Bytelandian sentence
        
        // Read the Bytelandian sentence.
        // Since underscores replace spaces, sentences are single tokens.
        cin >> S;

        string translated_S = ""; // String to build the English translation
        // Pre-allocate memory for translated_S to potentially improve performance
        // by reducing reallocations, though for max length 100 it's not critical.
        translated_S.reserve(S.length()); 

        // Iterate through each character of the Bytelandian sentence.
        for (char ch : S) {
            if (islower(ch)) {
                // If the character is a lowercase letter, translate it using the map.
                // 'ch - 'a'' gives the 0-indexed position (0 for 'a', 1 for 'b', etc.).
                translated_S += translation_map[ch - 'a'];
            } else if (isupper(ch)) {
                // If the character is an uppercase letter,
                // first find its lowercase equivalent's translation,
                // then convert that translation to uppercase.
                // 'ch - 'A'' gives the 0-indexed position for uppercase letters.
                translated_S += toupper(translation_map[ch - 'A']);
            } else if (ch == '_') {
                // If the character is an underscore, replace it with a space.
                translated_S += ' ';
            } else {
                // If the character is any other symbol (punctuation: '.', ',', '!', '?'), keep it as is.
                translated_S += ch;
            }
        }
        
        // Output the translated English sentence, followed by a newline.
        cout << translated_S << "\n";
    }

    return 0; // Indicate successful execution.
}