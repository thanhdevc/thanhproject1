#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string line;
    while (getline(std::cin, line)) {
        for (int i=0;i<line.length();i++) {
            line[i] = toupper(line[i]);
        }
        cout << line << std::endl;
    }
    return 0;
}
