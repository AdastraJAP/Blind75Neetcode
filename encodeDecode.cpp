#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size());
            result += '#';
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            result.emplace_back(s, j + 1, len);
            i = j + 1 + len;
        }
        return result;
    }
};

int main() {
    Codec codec;
    vector<string> input;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, s);
        input.push_back(s);
    }

    string encoded = codec.encode(input);
    cout << "\nEncoded: " << encoded << "\n";

    vector<string> decoded = codec.decode(encoded);
    cout << "Decoded: ";
    for (const string& s : decoded)
        cout << "[" << s << "] ";
    cout << "\n";

    return 0;
}