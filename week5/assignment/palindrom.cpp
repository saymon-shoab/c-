#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string word, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (word[start] != word[end]) {
        return false;
    }
    return is_palindrome(word, start + 1, end - 1);
}

int main() {
    string word ;
    cin>>word;
    if (is_palindrome(word, 0, word.length() - 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
