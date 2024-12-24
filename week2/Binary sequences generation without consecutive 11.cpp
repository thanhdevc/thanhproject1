#include <iostream>
using namespace std;

void generateBinary(int n, string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    
    // Always add '0'
    generateBinary(n, s + "0");
    
    // Add '1' only if the last character is not '1'
    if (s.empty() || s.back() != '1') {
        generateBinary(n, s + "1");
    }
}

int main() {
    int n;
    cin >> n;
    generateBinary(n, "");
    return 0;
}
