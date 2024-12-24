#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string line;
    int wordCount = 0;
	while (getline(cin, line)) {
        istringstream iss(line);
        string word;
      while (iss >> word) {
         wordCount++;
        }
    }
    cout << wordCount; 
    return 0;
}
