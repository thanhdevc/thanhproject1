#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

int n, a[100], ok;

void sinh() {
    int j = -1; // Initialize j to -1
    for (int i = n - 1; i > 0; i--) {
        if (a[i] < a[i + 1]) {
            j = i; // Found the first decreasing element
            break;
        }
    }

    if (j == -1) {
        ok = 0; // No more permutations
    } else {
        int min = 100000, t = -1; // Initialize t to -1
        for (int i = j + 1; i <= n; i++) {
            if (a[i] > a[j] && a[i] < min) {
                min = a[i];
                t = i;
            }
        }
        swap(a[j], a[t]); // Swap found elements
        
        // Reverse the elements from j + 1 to n
        reverse(a + j + 1, a + n + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i; // Initialize array
    }
    
    ok = 1; // Set ok to true
    while (ok) {
        for (int i = 1; i <= n; i++) {
            cout << a[i]<<" "; // Print current permutation
        }
        cout << endl;
        sinh(); // Generate the next permutation
    }

    return 0;
}
