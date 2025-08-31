#include <iostream>
#include <string>

using namespace std;

const string vowels = "aouieyAOIYUE";
const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int countVowels(const string &str) {
    int result = 0;
    for (const auto &c : str) {
        if (vowels.find(c) != string::npos)
            result++;
    }
    return result;
}

int main() {
    string text;
    int result = 0;

    cout << "Enter text: \n";
    getline(cin, text);
    text += ' ';
    string word;

    for (const auto &c : text) {
        if (alphabet.find(c) != string::npos)
            word += c;
        else {
            if (!word.empty() && countVowels(word) > 3)
                result++;
            word = "";
        }
    }

    cout << "Words with 3+ vowels: " << result << endl;
    return 0;
}
