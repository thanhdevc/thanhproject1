#include <iostream>
#include <string>
#include <sstream>
#include <queue> // Include stack for LIFO storage
using namespace std;

int findmaxsegment(int n, int a[], int i, int j) {
    int max = -300000;
    for (int x = i - 1; x <= j - 1; x++) { // Use zero-based indexing
        if (a[x] > max) max = a[x];
    }
    return max;
}

int sum(int n, int a[]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    return total;
}

int findmin(int n, int a[]) {
    int min = 100000;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int findmax(int n, int a[]) {
    int max = -200000;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin.ignore(); // Clear the newline character from the input buffer

    queue<int> results;
	
    string command;
    while (true) {
        getline(cin, command); 
		// Read a whole line for the command
    
        if (command == "***") {
            break; // Exit if the command is '***'
        }

        if (command == "find-max") {
            results.push(findmax(n, a)); // Store the result
        } else if (command == "find-min") {
            results.push(findmin(n, a)); // Store the result
        } else if (command == "sum") {
            results.push(sum(n, a)); // Store the result
        } else if (command[8] == 45) {
            istringstream t(command);
            string temp;
            int i,j;
            t>>temp>>i>>j;
            results.push(findmaxsegment(n, a, i, j)); // Store the result
        }
    }

    // Print all stored results (in LIFO order)
    while (!results.empty()) {
        cout<<results.front()<<endl;
        results.pop();
    }
    

    return 0;
}
